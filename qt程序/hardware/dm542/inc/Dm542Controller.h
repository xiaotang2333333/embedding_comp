#ifndef DM542_CONTROLLER_H
#define DM542_CONTROLLER_H

#include <QObject>
#include <QFileSystemWatcher>
#include <QFile>
#include <fstream>
enum AXIS{
    X_AXIS = 0,
    Y_AXIS = 1,
    Z_AXIS = 2
};
class Dm542Controller : public QObject
{
    Q_OBJECT

signals:
    void pwmComplete(const AXIS whatAmI);
    void pwmStart();
    void swTrig(int trigStat,const AXIS whatAmI);

public:
    explicit Dm542Controller(QObject *parent = nullptr,
                             const QString &devicePath = "/sys/class/dm542/dm542-x",
                             const AXIS &whatAmI = X_AXIS);
    ~Dm542Controller() override;

    bool setEnable(bool enable);
    bool setPwmEnable(bool enable);
    bool setPeriod(unsigned long long period);
    bool setPulseCount(long long count);
    unsigned long long getPeriod();
    long long getPulseCount();
    bool getEnable();
    bool getPwmEnable();
private slots:
    void onFileChanged(const QString &path);

private:
    QString devicePath;
    AXIS whatAmI;
    QFileSystemWatcher watcher;

    bool writeAttribute(const QString &attr, const QString &value);
    bool readAttribute(const QString &attr, QString &value);
};

#endif // DM542_CONTROLLER_H