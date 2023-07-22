// FaceDetector.h
#ifndef FACE_DETECTOR_H
#define FACE_DETECTOR_H

#include <opencv2/opencv.hpp>

class FaceDetector {
public:
    FaceDetector();

    std::vector<cv::Rect> detectFaces(const cv::Mat& image);

private:
    cv::CascadeClassifier faceCascade;
};

#endif // FACE_DETECTOR_H

