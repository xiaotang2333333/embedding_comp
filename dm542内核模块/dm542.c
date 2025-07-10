// dm542 stepper motor driver controller
#include <linux/module.h>
#include <linux/notifier.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <linux/gpio/consumer.h>
#include <linux/pwm.h>
#include <linux/sysfs.h>
#include <linux/types.h>
#include <linux/interrupt.h>
extern int rockchip_pwm_register_oneshot_done_notifier(struct notifier_block *nb);
extern int rockchip_pwm_unregister_oneshot_done_notifier(struct notifier_block *nb);
enum TRIG_STAT
{
    NO_TRIG,
    SW1_TRIG,
    SW2_TRIG
};
struct dm542_data
{
    struct gpio_desc *ena_gpio;
    struct gpio_desc *dir_gpio;
    struct gpio_desc *sw1_gpio;
    struct gpio_desc *sw2_gpio;
    struct device *dev;
    struct pwm_device *pwm;
    long pulse_count;
    int sw1_irq;
    int sw2_irq;
    struct notifier_block pwm_notifier;
    enum TRIG_STAT trig; // 记录触发状态
};
static void config_pluse(long pulse_count, struct dm542_data *data)
{
    if (pulse_count <= 256)
    {
        data->pwm->state.oneshot_count = pulse_count;
        data->pwm->state.oneshot_repeat = 0; // 不重复
        data->pwm->last.oneshot_count = 0;   // 不重复时不多余
    }
    else
    {
        data->pwm->state.oneshot_count = 256;
        data->pwm->state.oneshot_repeat = (pulse_count >> 8) - 1; // 每256个脉冲重复一次,0时重复一次
        data->pwm->last.oneshot_count = pulse_count & 0xFF;
    }
}
static int dm542_pwm_oneshot_done_callback(struct notifier_block *nb,
                                           unsigned long action, void *data)
{
    struct pwm_device *done_pwm = data; // 从 data 参数获取到的 PWM 设备
    // 通过 container_of 宏，从 notifier_block 指针获取到包含它的 dm542_data 结构体指针
    struct dm542_data *dm542_priv_data =
        container_of(nb, struct dm542_data, pwm_notifier);
    // 确保是正确的 PWM 设备触发的事件
    if (dm542_priv_data->pwm == done_pwm)
    {
        dev_info(dm542_priv_data->dev, "PWM device oneshot finished! State: %d\n", done_pwm->state.enabled);
        sysfs_notify(&(dm542_priv_data->dev->kobj), NULL, "pwm_enable");
    }
    return NOTIFY_OK; // 表示成功处理通知
}
static ssize_t enable_show(struct device *dev, struct device_attribute *attr,
                           char *buf)
{
    struct dm542_data *data = dev_get_drvdata(dev);
    int value = gpiod_get_value(data->ena_gpio);

    return scnprintf(buf, PAGE_SIZE, "%d\n", !value); // 由于共阴接法，实际输出0才启动
}

static ssize_t enable_store(struct device *dev, struct device_attribute *attr,
                            const char *buf, size_t count)
{
    struct dm542_data *data = dev_get_drvdata(dev);
    int ret;
    long value;

    ret = kstrtol(buf, 10, &value);
    if (ret < 0)
        return ret;

    gpiod_set_value(data->ena_gpio, !value); // 使能引脚需要反转
    pwm_disable(data->pwm);
    config_pluse(0, data); // 使能时停止PWM
    return count;
}

static DEVICE_ATTR_RW(enable);

static ssize_t pwm_enable_show(struct device *dev, struct device_attribute *attr,
                               char *buf)
{
    struct dm542_data *data = dev_get_drvdata(dev);
    return scnprintf(buf, PAGE_SIZE, "%d\n", data->pwm->state.enabled ? 1 : 0);
}

static ssize_t pwm_enable_store(struct device *dev, struct device_attribute *attr,
                                const char *buf, size_t count)
{
    struct dm542_data *data = dev_get_drvdata(dev);
    int ret;
    long value;

    ret = kstrtol(buf, 10, &value);
    if (ret < 0)
        return ret;
    // sw1触发时需要滑台远离电机端，因此下次输入需要pluse_count为负,对应dir为0
    //int check_dir = gpiod_get_value(data->dir_gpio);v
    //int check_trig1 = gpiod_get_value(data->sw1_gpio);
    //int check_trig2 = gpiod_get_value(data->sw2_gpio);
    //if (((check_dir>0) && check_trig1)||((check_dir<0) && check_trig2) || (!data->pulse_count))
    //{
    //    return -EINVAL; // 方向和触发状态不匹配
    //}
    if (!data->pulse_count)
    {
        return -EINVAL;
    }
    if (value && !data->pwm->state.enabled)
    {
        ret = pwm_enable(data->pwm);
        if (ret)
            return ret;
        data->pulse_count = 0;
        return count;
    }
    else if (!value && data->pwm->state.enabled)
    {
        pwm_disable(data->pwm);
        return count;
    }
    else
    {
        return -EINVAL; // 无效的操作
    }
}
static DEVICE_ATTR_RW(pwm_enable);

static ssize_t period_show(struct device *dev, struct device_attribute *attr,
                           char *buf)
{
    struct dm542_data *data = dev_get_drvdata(dev);
    return scnprintf(buf, PAGE_SIZE, "%llu\n", data->pwm->state.period);
}
static ssize_t period_store(struct device *dev, struct device_attribute *attr,
                            const char *buf, size_t count)
{
    struct dm542_data *data = dev_get_drvdata(dev);
    int ret;
    unsigned long long value;

    ret = kstrtoull(buf, 10, &value);
    if (ret < 0)
        return ret;
    data->pwm->state.period = value;
    return count;
}

static DEVICE_ATTR_RW(period);

static ssize_t pulse_count_show(struct device *dev,
                                struct device_attribute *attr, char *buf)
{
    struct dm542_data *data = dev_get_drvdata(dev);
    return scnprintf(buf, PAGE_SIZE, "%lld\n", data->pwm->state.oneshot_count + (data->pwm->state.oneshot_repeat << 8) + data->pwm->last.oneshot_count);
}
static ssize_t pulse_count_store(struct device *dev,
                                 struct device_attribute *attr,
                                 const char *buf, size_t count)
{
    struct dm542_data *data = dev_get_drvdata(dev);
    int ret;
    long long value;

    ret = kstrtoll(buf, 10, &value);
    if (ret < 0)
        return ret;
    if (value < 0) // 反转
    {
        data->pulse_count = -value;
        gpiod_set_value(data->dir_gpio, 0);
        config_pluse(-value, data);
    }
    else if (value > 0) // 正转
    {
        data->pulse_count = value;
        gpiod_set_value(data->dir_gpio, 1);
        config_pluse(value, data);
    }
    return count;
}

static DEVICE_ATTR_RW(pulse_count);

static ssize_t trig_stat_show(struct device *dev, struct device_attribute *attr,
                              char *buf)
{
    struct dm542_data *data = dev_get_drvdata(dev);
    const char *stat_str;

    switch (data->trig)
    {
    case NO_TRIG:
        stat_str = "NO_TRIG";
        break;
    case SW1_TRIG:
        stat_str = "SW1_TRIG";
        break;
    case SW2_TRIG:
        stat_str = "SW2_TRIG";
        break;
    default:
        stat_str = "UNKNOWN";
    }

    return scnprintf(buf, PAGE_SIZE, "%s\n", stat_str);
}

static DEVICE_ATTR_RO(trig_stat);

static struct attribute *dm542_attrs[] = {
    &dev_attr_enable.attr,
    &dev_attr_pwm_enable.attr,
    &dev_attr_period.attr,
    &dev_attr_pulse_count.attr,
    &dev_attr_trig_stat.attr,
    NULL,
};

static const struct attribute_group dm542_attr_group = {
    .attrs = dm542_attrs,
};

//static irqreturn_t dm542_sw_irq_handler(int irq, void *dev_id)
//{
//    struct dm542_data *data = dev_id;
//    struct device *dev = data->dev;
//    int gpio_state;
//    // 输入的pulse_count为负时，滑台远离电机，定义离电机近的是sw1
//    if (irq == data->sw1_irq)
//    {
//        gpio_state = gpiod_get_value(data->sw1_gpio);
//        // sw1触发时需要滑台远离电机，因此下次输入需要pluse_count为负
//        if (gpio_state) // 正常高电平
//        {
//            data->trig = NO_TRIG;
//        }
//        else
//        {
//            data->trig = SW1_TRIG;
//            config_pluse(0, data); // 触发时停止
//            if (data->pwm->state.enabled)
//                pwm_disable(data->pwm); // 停止PWM
//        }
//        dev_info(dev, "SW1 triggered, state: %d\n",
//                 gpio_state);
//    }
//    else if (irq == data->sw2_irq)
//    {
//        gpio_state = gpiod_get_value(data->sw2_gpio);
//        if (gpio_state) // 正常高电平
//        {
//            data->trig = NO_TRIG;
//        }
//        else
//        {
//            data->trig = SW2_TRIG;
//            config_pluse(0, data);
//            if (data->pwm->state.enabled)
//                pwm_disable(data->pwm); // 停止PWM
//        }
//        dev_info(dev, "SW2 triggered, state: %d\n",
//                 gpio_state);
//    }
//    sysfs_notify(&(data->dev->kobj), NULL, "trig_stat");
//    return IRQ_HANDLED;
//}

static int dm542_probe(struct platform_device *pdev)
{
    struct dm542_data *data;
    struct device *dev = &pdev->dev;
    struct device_node *ena_node, *dir_node, *sw1_node, *sw2_node;
    int ret;

    data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
    if (!data)
        return -ENOMEM;

    data->dev = dev;

    // 初始化使能引脚
    ena_node = of_get_child_by_name(dev->of_node, "ena");
    if (ena_node)
    {
        data->ena_gpio = devm_gpiod_get_from_of_node(dev, ena_node,
                                                     "gpios", 0,
                                                     GPIOD_OUT_LOW, "ena");
        of_node_put(ena_node);
    }
    else
    {
        data->ena_gpio = devm_gpiod_get(dev, "ena", GPIOD_OUT_LOW);
    }

    if (IS_ERR(data->ena_gpio))
    {
        dev_err(dev, "Failed to get ena GPIO\n");
        return PTR_ERR(data->ena_gpio);
    }

    // 初始化方向引脚
    dir_node = of_get_child_by_name(dev->of_node, "dir");
    if (dir_node)
    {
        data->dir_gpio = devm_gpiod_get_from_of_node(dev, dir_node,
                                                     "gpios", 0,
                                                     GPIOD_OUT_LOW, "dir");
        of_node_put(dir_node);
    }
    else
    {
        data->dir_gpio = devm_gpiod_get(dev, "dir", GPIOD_OUT_LOW);
    }

    if (IS_ERR(data->dir_gpio))
    {
        dev_err(dev, "Failed to get dir GPIO\n");
        return PTR_ERR(data->dir_gpio);
    }

    // 初始化PWM
    data->pwm_notifier.notifier_call = dm542_pwm_oneshot_done_callback;
    ret = rockchip_pwm_register_oneshot_done_notifier(&data->pwm_notifier);
    if (ret)
    {
        dev_err(data->dev, "Failed to register PWM oneshot notifier: %d\n", ret);
        // 这里可能需要清理之前分配的资源
        return ret;
    }
    struct device_node *pul_node = of_get_child_by_name(dev->of_node, "pul");
    if (pul_node)
    {
        data->pwm = devm_fwnode_pwm_get(dev, &(pul_node->fwnode), NULL);
        of_node_put(pul_node);
    }
    else
    {
        data->pwm = devm_pwm_get(dev, "pul");
    }

    if (IS_ERR(data->pwm))
    {
        dev_err(dev, "Failed to get PWM device\n");
        return PTR_ERR(data->pwm);
    }
    // 设定PWM和GPIO初始状态
    pwm_config(data->pwm, 10000, 80000);
    gpiod_set_value(data->ena_gpio, 1);

    // 初始化SW1 GPIO和中断
    sw1_node = of_get_child_by_name(dev->of_node, "sw1");
    if (sw1_node)
    {
        data->sw1_gpio = devm_gpiod_get_from_of_node(dev, sw1_node,
                                                     "gpios", 0,
                                                     GPIOD_IN, "sw1");
        of_node_put(sw1_node);
    }
    else
    {
        data->sw1_gpio = devm_gpiod_get(dev, "sw1", GPIOD_IN);
    }

    //if (!IS_ERR(data->sw1_gpio))
    //{
    //    data->sw1_irq = gpiod_to_irq(data->sw1_gpio);
    //    ret = devm_request_irq(dev, data->sw1_irq, dm542_sw_irq_handler,
    //                           IRQF_TRIGGER_LOW,
    //                           "dm542_sw1", data);
    //    if (ret)
    //    {
    //        dev_warn(dev, "Failed to request SW1 interrupt\n");
    //    }
    //}

    // 初始化SW2 GPIO和中断
    sw2_node = of_get_child_by_name(dev->of_node, "sw2");
    if (sw2_node)
    {
        data->sw2_gpio = devm_gpiod_get_from_of_node(dev, sw2_node,
                                                     "gpios", 0,
                                                     GPIOD_IN, "sw2");
        of_node_put(sw2_node);
    }
    else
    {
        data->sw2_gpio = devm_gpiod_get(dev, "sw2", GPIOD_IN);
    }

    //if (!IS_ERR(data->sw2_gpio))
    //{
    //    data->sw2_irq = gpiod_to_irq(data->sw2_gpio);
    //    ret = devm_request_irq(dev, data->sw2_irq, dm542_sw_irq_handler,
    //                           IRQF_TRIGGER_LOW,
    //                           "dm542_sw2", data);
    //    if (ret)
    //    {
    //        dev_warn(dev, "Failed to request SW2 interrupt\n");
    //    }
    //}

    data->trig = NO_TRIG; // 初始化触发状态
    // 创建sysfs接口
    ret = sysfs_create_group(&dev->kobj, &dm542_attr_group);
    if (ret)
    {
        dev_err(dev, "Failed to create sysfs group\n");
        return ret;
    }

    platform_set_drvdata(pdev, data);
    dev_info(dev, "dm542 driver initialized\n");
    return 0;
}

static int dm542_remove(struct platform_device *pdev)
{
    struct dm542_data *data = platform_get_drvdata(pdev);

    sysfs_remove_group(&data->dev->kobj, &dm542_attr_group);

    rockchip_pwm_unregister_oneshot_done_notifier(&data->pwm_notifier);

    if (data->pwm && data->pwm->state.enabled) {
        pwm_disable(data->pwm);
    }

    if (data->dir_gpio) { // 添加对 gpios 的空检查
        gpiod_set_value(data->dir_gpio, 0); // 复位方向引脚
    }
    if (data->ena_gpio) { // 添加对 gpios 的空检查
        gpiod_set_value(data->ena_gpio, 1); // 禁用使能引脚（共阴接法，高电平禁用）
    }
    dev_info(&pdev->dev, "dm542 driver unloaded and resources released successfully.\n");
    return 0;
}

static const struct of_device_id dm542_of_match[] = {
    {.compatible = "dm542"},
    {.compatible = "tb6600"},
    {}};
MODULE_DEVICE_TABLE(of, dm542_of_match);

static struct platform_driver dm542_driver = {
    .probe = dm542_probe,
    .remove = dm542_remove,
    .driver = {
        .name = "dm542",
        .of_match_table = dm542_of_match,
    },
};

module_platform_driver(dm542_driver);

MODULE_AUTHOR("Driver Author");
MODULE_DESCRIPTION("dm542 Stepper Motor Driver");
MODULE_LICENSE("GPL v2");