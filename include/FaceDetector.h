// FaceDetector.h
#ifndef FACE_DETECTOR_H
#define FACE_DETECTOR_H

#include <opencv2/opencv.hpp>

class FaceDetector {
public:
    FaceDetector();

    FaceDetector(std::string faceCascadeFilePath, std::string mouthCascadeFilePath); 
    std::vector<cv::Rect> detectFaces(const cv::Mat& image);
    // std::vector<cv::Rect> detectFaces(const cv::Mat& image, double scaleFactor = 1.1, int minNeighbors = 3, int flags = 0, cv::Size minSize = cv::Size(0,0));
    std::vector<cv::Rect> detectMouths(const cv::Mat& image, double scaleFactor = 1.1, int minNeighbors = 3, int flags = 0, cv::Size minSize = cv::Size(30,30));
private:
    cv::CascadeClassifier faceCascade;
    cv::CascadeClassifier mouthCascade;
};

#endif // FACE_DETECTOR_H

