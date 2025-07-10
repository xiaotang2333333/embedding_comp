#include "ImageAcquisitionWorker.h"
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#define COUNT 3
ImageAcquisitionWorker::ImageAcquisitionWorker(QObject *parent)
    : QObject(parent)
{
}

void ImageAcquisitionWorker::snapshot(void *handle)
{
    if (handle == nullptr)
    {
        emit snapshotError("Camera handle is null");
        return;
    }
    if (MV_CC_StartGrabbing(handle) != MV_OK)
    {
        emit snapshotError("Failed to start grabbing images");
        return;
    }

    double totalHueSum = 0.0;
    int totalValidPixels = 0;
    QVector<float> nowHue((RECT + 1) * (RECT + 1), 0.0f);
    QImage lastImage;
    int stableCount = 0;  // 连续稳定的拍照次数
    float lastAvg = 0.0f; // 上一帧的平均色调
    // 循环直到完成8次连续稳定的拍照
    while (stableCount < COUNT)
    {
        nowHue.clear();
        float currentAvg = 0.0f;
        MV_FRAME_OUT stImageBuffer;
        if (MV_CC_GetImageBuffer(handle, &stImageBuffer, 0xFFFF) != MV_OK)
        {
            emit snapshotError("Failed to get image buffer");
            break;
        }
        // 处理当前帧
        cv::Mat rawImage(stImageBuffer.stFrameInfo.nHeight, stImageBuffer.stFrameInfo.nWidth, CV_16UC1, stImageBuffer.pBufAddr);
        cv::Mat rgb16;
        cv::Mat rgb32f;
        cv::cvtColor(rawImage, rgb16, cv::COLOR_BayerRGGB2RGB_EA);
        cv::Mat rgb8_display;
        rgb16.convertTo(rgb8_display, CV_8UC3, 255.0 / 4095.0);
        rgb16.convertTo(rgb32f, CV_32FC3, 1.0f / 4095.0f);

        // 光斑圆心检测
        cv::Mat gray;
        cv::cvtColor(rgb8_display, gray, cv::COLOR_RGB2GRAY);
        cv::GaussianBlur(gray, gray, cv::Size(9, 9), 2, 2);
        cv::Mat binary;
        cv::threshold(gray, binary, 0, 255, cv::THRESH_BINARY + cv::THRESH_OTSU);
        cv::Mat kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5));
        cv::morphologyEx(binary, binary, cv::MORPH_CLOSE, kernel);
        cv::morphologyEx(binary, binary, cv::MORPH_OPEN, kernel);
        std::vector<std::vector<cv::Point>> contours;
        cv::findContours(binary, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
        cv::Point2f center;
        float radius = 0;
        bool foundCircle = false;
        if (!contours.empty())
        {
            double maxArea = 0;
            int maxAreaIdx = 0;
            for (size_t i = 0; i < contours.size(); i++)
            {
                double area = cv::contourArea(contours[i]);
                if (area > maxArea)
                {
                    maxArea = area;
                    maxAreaIdx = i;
                }
            }
            if (maxArea > 100)
            {
                cv::minEnclosingCircle(contours[maxAreaIdx], center, radius);
                foundCircle = true;
            }
        }

        if (foundCircle)
        {
            int x1 = std::max(0, static_cast<int>(center.x - RECT / 2));
            int y1 = std::max(0, static_cast<int>(center.y - RECT / 2));
            int x2 = std::min(rgb8_display.cols - 1, static_cast<int>(center.x + RECT / 2));
            int y2 = std::min(rgb8_display.rows - 1, static_cast<int>(center.y + RECT / 2));

            // 提取ROI区域hue值
            cv::Mat roi = rgb32f(cv::Rect(x1, y1, x2 - x1, y2 - y1));
            cv::Mat hsvRoi;
            cv::cvtColor(roi, hsvRoi, cv::COLOR_RGB2HSV_FULL);
            std::vector<cv::Mat> ch(3);
            cv::split(hsvRoi, ch);

            for (int i = 0; i < hsvRoi.rows; ++i)
            {
                const float *hue_row = ch[0].ptr<float>(i);
                const float *s_row = ch[1].ptr<float>(i);
                const float *v_row = ch[2].ptr<float>(i);
                for (int j = 0; j < hsvRoi.cols; ++j)
                {
                    if (s_row[j] > sThreshold && v_row[j] > vThreshold)
                    {
                        nowHue.append(hue_row[j]);
                    }
                }
            }
            if (!nowHue.empty())
            {
                currentAvg = std::accumulate(nowHue.begin(), nowHue.end(), 0.0f) / nowHue.size();

                // 检查与上一帧的差异,首次拍照正常赋值
                if (std::abs(currentAvg - lastAvg) > lastAvg * 0.05f && lastAvg > 0)
                {
                    stableCount = 0;      // 重置稳定计数
                    totalHueSum = 0.0;    // 重置总色调和
                    totalValidPixels = 0; // 重置有效像素计数
                    lastAvg = currentAvg;
                    qDebug() << "NO GOOD.";
                }
                else
                {
                    totalHueSum += currentAvg * nowHue.size();
                    totalValidPixels += nowHue.size();
                    stableCount++; // 增加稳定计数
                }
            }
            // 只在最后一次捕获时绘制标注
            if (stableCount == (COUNT - 1))
            {
                cv::rectangle(rgb8_display, cv::Rect(x1, y1, x2 - x1, y2 - y1),
                              cv::Scalar(0, 255, 0), 2);
                cv::circle(rgb8_display, cv::Point(static_cast<int>(center.x), static_cast<int>(center.y)),
                           static_cast<int>(radius), cv::Scalar(0, 0, 255), 2);
                cv::circle(rgb8_display, cv::Point(static_cast<int>(center.x), static_cast<int>(center.y)),
                           3, cv::Scalar(255, 0, 0), -1);
                lastImage = QImage(rgb8_display.data, rgb8_display.cols, rgb8_display.rows,
                                   rgb8_display.step, QImage::Format_RGB888)
                                .copy();
            }
        }
        // 释放当前帧缓冲区
        if (stImageBuffer.pBufAddr)
        {
            MV_CC_FreeImageBuffer(handle, &stImageBuffer);
        }
    }
    // 停止抓图
    if (MV_CC_StopGrabbing(handle) != MV_OK)
    {
        emit snapshotError("Failed to stop grabbing images");
    }

    // 发射最后一次捕获的图像
    if (!lastImage.isNull())
    {
        emit snapshotImage(lastImage);
    }

    // 计算并发射平均hue值
    if (totalValidPixels > 0)
    {
        double averageHue = static_cast<double>(totalHueSum / totalValidPixels);
        emit snapshotColorChart(averageHue);
        qDebug() << "Average hue value over 5 captures:" << averageHue;
    }
    else
    {
        emit snapshotColorChart(-1.0f);
        qDebug() << "No valid pixels found in ROI over 5 captures";
    }

    emit snapshotFinished();
}