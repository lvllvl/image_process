#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <vector>
#include <opencv2/opencv.hpp>


struct ImageData {
    std::vector<int> pixels; 
    int width;
    int height;
    // int* pixels;
};

class Image {
public:
    // Constructors
    Image(); // Image(const std::string& filename);
    Image( const std::string& filename ); // Image(const std::string& filename);
    ~Image();// Destructor

    // Member functions
    bool loadFrameFile( const std::string filename );
    // int loadImageWidthFromFile( const std::string filename );
    // int loadImageHeightFromFile( const std::string filename );
    std::vector<cv::Vec3b> openImage( const std::string& filename );
    // int getWidth();
    // int getHeight();
    // bool saveToFile( std::string filename );
    // void resize( int newWidth, int newHeight);
   //  Image crop( int x, int y, int width, int height ); 
   //  Image rotate( float angle );
   //  Image applyFilter( Filter filer ); // TODO: Implement Filter class
   //  Image convertToGrayscale(); 

    // Add other private member variables and functions as needed
private:
    ImageData imageData; 
};

#endif // IMAGE_H
