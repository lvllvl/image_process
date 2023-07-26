#include "FaceDetector.h"

FaceDetector::FaceDetector()
{
    std::cout << "FaceDetector constructor called." << std::endl;
}

FaceDetector::FaceDetector(std::string faceCascadeFilePath, std::string mouthCascadeFilePath)
{
    if (!faceCascade.load(faceCascadeFilePath))
    {
        throw std::runtime_error("Failed to load face cascade classifier XML file.");
    }
    if (!mouthCascade.load(mouthCascadeFilePath))
    {
        throw std::runtime_error("Failed to load mouth cascade classifier XML file.");
    }
}

std::vector<cv::Rect> FaceDetector::detectFaces(const cv::Mat &image)
{
    std::vector<cv::Rect> faces;
    try
    {
        // faceCascade.detectMultiScale(image, faces, scaleFactor, minNeighbors, flags, minSize);
        faceCascade.detectMultiScale(image, faces, 1.05, 2, 0, cv::Size(20, 20));

        if ( faces.empty() )
        {
            std::cout << "No faces detected." << std::endl;
        }
        else
        {
            std::cout << faces.size() << " faces detected." << std::endl;
        }
    }
    catch (cv::Exception &e)
    {
        // Handle exception
        // throw std::runtime_error("Failed to detect faces.");
    }
    return faces;
}

std::vector<cv::Rect> FaceDetector::detectMouths(const cv::Mat &image, double scaleFactor, int minNeighbors, int flags, cv::Size minSize)
{
    std::vector<cv::Rect> mouths;
    try
    {
        mouthCascade.detectMultiScale(image, mouths, scaleFactor, minNeighbors, flags, minSize);
    }
    catch (cv::Exception &e)
    {
        // Handle exception
        throw std::runtime_error("Failed to detect mouths.");
    }
    return mouths;
}
