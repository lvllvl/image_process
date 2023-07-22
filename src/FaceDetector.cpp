#include "FaceDetector.h"

FaceDetector::FaceDetector() {
    // Load the face cascade classifier XML file
    std::string cascadeFilePath = "/opt/homebrew/opt/opencv/share/opencv4/haarcascades/haarcascade_frontalface_default.xml";
    if (!faceCascade.load(cascadeFilePath)) {
        throw std::runtime_error("Failed to load face cascade classifier XML file.");
    }
}

std::vector<cv::Rect> FaceDetector::detectFaces(const cv::Mat& image) {
    std::vector<cv::Rect> faces;
    faceCascade.detectMultiScale(image, faces, 1.1, 3, 0, cv::Size(30, 30));
    return faces;
}