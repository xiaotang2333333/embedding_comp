#include "Dm542Controller.h"
#include <stdexcept>
#include <filesystem>
#include <fstream>
#include <QDebug>
#include <QFileInfo>
#include <QDir>
Dm542Controller::Dm542Controller(QObject *parent, const QString &devicePath, const AXIS &whatAmI)
    : QObject(parent), devicePath(devicePath), whatAmI(whatAmI)
{
    // 监控enable文件变化
    QString File = devicePath + "/pwm_enable";
    if (QFile::exists(File))
    {
        watcher.addPath(File);
    }
    if (!QDir(devicePath).exists())
    {
        throw std::runtime_error(("DM542 device path not found: " + devicePath).toStdString());
    }
    File = devicePath + "/trig_stat";
    if(QFile::exists(File))
    {
        watcher.addPath(File);
    }
    else
    {
        qWarning() << "trig_stat file does not exist at" << File;
    }
    connect(&watcher, &QFileSystemWatcher::fileChanged, this, &Dm542Controller::onFileChanged);
}

Dm542Controller::~Dm542Controller()
{
    setEnable(false);
    watcher.removePath(devicePath + "/pwm_enable");
    watcher.removePath(devicePath + "/trig_stat");
}

void Dm542Controller::onFileChanged(const QString &path)
{
    if (path.endsWith("pwm_enable"))
    {
        QString value;
        if (readAttribute("pwm_enable", value))
        {
            if (value == "1")
            {
                emit pwmStart();
            }
            else if (value == "0")
            {
                emit pwmComplete(whatAmI);
            }
        }
        else
        {
            qWarning() << "Failed to read pwm_enable attribute from" << path;
        }
    }
    else if (path.endsWith("trig_stat"))
    {
        QString value;
        if (readAttribute("trig_stat", value))
        {
            if (value == "SW1_TRIG")
            {
                emit swTrig(1,whatAmI); // 触发SW1
            }
            else if (value == "SW2_TRIG")
            {
                emit swTrig(2,whatAmI);
            }
        }
        else
        {
            qWarning() << "Failed to read trig_stat attribute from" << path;
        }
    }
}

bool Dm542Controller::setEnable(bool enable)
{
    return writeAttribute("enable", enable ? "1" : "0");
}

bool Dm542Controller::setPwmEnable(bool enable)
{
    return writeAttribute("pwm_enable", enable ? "1" : "0");
}

bool Dm542Controller::setPeriod(unsigned long long period)
{
    return writeAttribute("period", QString::number(period));
}

bool Dm542Controller::setPulseCount(long long count)
{
    return writeAttribute("pulse_count", QString::number(count));
}

bool Dm542Controller::writeAttribute(const QString &attr, const QString &value)
{
    QFile file(devicePath + "/" + attr);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return false;
    }
    QTextStream out(&file);
    out << value;
    file.close();
    return true;
}

bool Dm542Controller::readAttribute(const QString &attr, QString &value)
{
    QFile file(devicePath + "/" + attr);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return false;
    }
    QTextStream in(&file);
    value = in.readAll().trimmed();
    file.close();
    return true;
}
unsigned long long Dm542Controller::getPeriod()
{
    QString value;
    if (readAttribute("period", value))
    {
        return value.toULongLong();
    }
    throw std::runtime_error("Failed to read period attribute");
}
long long Dm542Controller::getPulseCount()
{
    QString value;
    if (readAttribute("pulse_count", value))
    {
        return value.toLongLong();
    }
    throw std::runtime_error("Failed to read pulse_count attribute");
}
bool Dm542Controller::getEnable()
{
    QString value;
    if (readAttribute("enable", value))
    {
        return value == "1";
    }
    throw std::runtime_error("Failed to read enable attribute");
}
bool Dm542Controller::getPwmEnable()
{
    QString value;
    if (readAttribute("pwm_enable", value))
    {
        return value == "1";
    }
    throw std::runtime_error("Failed to read pwm_enable attribute");
}