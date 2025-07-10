#ifndef GSLINTERP_H
#define GSLINTERP_H
#include <gsl/gsl_interp.h>
#include <gsl/gsl_spline.h>
#include <gsl/gsl_errno.h>
#include <QString>
#include <QObject>
class GslInterp : public QObject
{
    Q_OBJECT
private:
    void readDataFromFile(const QString &filePath);
    gsl_interp_accel *acc;
    gsl_spline *spline;
    QVector<double> readyHue; // 存储色调数据
    QVector<double> movement;

public:
    GslInterp(const QString &filePath, QObject *parent);
    ~GslInterp();
    double interpolate(double x) const;
};

#endif