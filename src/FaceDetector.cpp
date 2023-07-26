#include "FaceDetector.h"

FaceDetector::FaceDetector()
{
    std::cout << "FaceDetector constructor called." << std::endl;
}

FaceDetector::FaceDetector(std::string faceCascadeFilePath )
{
    // Load the face cascade classifier XML file
    if (!faceCascade.load(faceCascadeFilePath))
    {
        throw std::runtime_error("Failed to load face cascade classifier XML file.");
    }
}

std::vector<cv::Rect> FaceDetector::detectFaces(const cv::Mat &image)
{
    std::vector<cv::Rect> faces;
    faceCascade.detectMultiScale(image, faces, 1.1, 3, 0, cv::Size(30, 30));

    if ( faces.empty() )
    {
        std::cout << "No faces detected." << std::endl;
    }
    else
    {
        std::cout << faces.size() << " faces detected." << std::endl;
    }

    return faces;
}

// std::vector<cv::Rect> FaceDetector::detectMouths(const cv::Mat &image, double scaleFactor, int minNeighbors, int flags, cv::Size minSize)
// {
//     std::vector<cv::Rect> mouths;
//     mouthCascade.detectMultiScale(image, mouths, scaleFactor, minNeighbors, flags, minSize);

//     return mouths;
// }
