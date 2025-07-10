#ifndef IMAGEACQUISITIONWORKER_H
#define IMAGEACQUISITIONWORKER_H
#include <QObject>
#include <QImage>
#include "MvCameraControl.h"
#include <opencv2/core.hpp>
#define RECT 80

class ImageAcquisitionWorker : public QObject
{
    Q_OBJECT
public:
    explicit ImageAcquisitionWorker(QObject *parent = nullptr);
    void setSThreshold(float value) { sThreshold = value; }
    void setVThreshold(float value) { vThreshold = value; }
public slots:
    void snapshot(void * handle); // 捕获图像的槽函数
signals:
    // 发送捕获到的图像数据
    void snapshotImage(QImage image);
    void snapshotColorChart(const double hue);
    void snapshotError(const QString &error);
    void snapshotFinished();
private:
    float sThreshold = 0.2f; // 色调阈值
    float vThreshold = 0.2f; // 饱和度阈值
};
#endif // IMAGEACQUISITIONWORKER_H