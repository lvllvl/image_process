#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

struct ImageData {
    std::vector<int> pixels; 
    int width;
    int height;
    int channels;
    // TODO: get file format from file name
};

class Image {
public:
    
    // Constructors
    Image(); // Image(const std::string& filename);
    Image( const std::string& filename ); // Image(const std::string& filename);
    ~Image();// Destructor

    // Member functions
    bool loadFrameFile( const std::string filename );
    std::vector<cv::Vec3b> openImage( const std::string& filename );
    void resize( int newWidth, int newHeight);
    void convertToGrayscale();
    void displayImage( const std::string& filename );
    cv::VideoCapture initCamera(); 
    cv::Mat captureImage( cv::VideoCapture& camera );
    void displayCapturedImage( const std::string& windowName, cv::Mat& image );

    // bool saveToFile( std::string filename );
   //  Image crop( int x, int y, int width, int height ); 

   // TODO: rotate, but provide the ability to reverse roation. 
   // TODO: #4 add feature that lets you reverse any filter or changes to the image. 
   //  Image rotate( float angle );
   //  Image applyFilter( Filter filer ); // TODO: Implement Filter class

    // Add other private member variables and functions as needed
private:
    ImageData imageData; 
};

#endif // IMAGE_H
