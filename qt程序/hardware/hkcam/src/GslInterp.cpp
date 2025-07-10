#include "GslInterp.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
GslInterp::GslInterp(const QString &filePath, QObject *parent)
{
    readDataFromFile(filePath);
    acc = gsl_interp_accel_alloc();
    spline = gsl_spline_alloc(gsl_interp_steffen, readyHue.size());
    gsl_spline_init(spline, readyHue.data(), movement.data(), readyHue.size());
}
GslInterp::~GslInterp()
{
    gsl_spline_free(spline);
    gsl_interp_accel_free(acc);
    readyHue.clear();
    movement.clear();
}
void GslInterp::readDataFromFile(const QString &filePath)
{
    readyHue.reserve(800); // 预留足够的空间
    movement.reserve(800);
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file:" << filePath;
        return;
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList parts = line.split(',');
        if (parts.size() == 2)
        {
            bool ok1, ok2;
            double m = parts[0].toDouble(&ok1);
            double hue = parts[1].toDouble(&ok2);
            if (ok1 && ok2)
            {
                movement.append(m);
                readyHue.append(hue);
            }
        }
    }
    file.close();
}
double GslInterp::interpolate(double x) const
{
    static double y; // 用于存储结果
    return gsl_spline_eval_e(spline, x, acc, &y) == GSL_SUCCESS ? y : 0.0f;
}