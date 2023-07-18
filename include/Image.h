#ifndef IMAGE_H
#define IMAGE_H

#include <string>

class Image {
public:
    // Constructors
    Image(); // Image(const std::string& filename);
    ~Image();// Destructor

    // Member functions
    bool loadFrameFile( const std::string filename );
    int getWidth();
    // int getHeight();
    // bool saveToFile( std::string filename );
    // void resize( int newWidth, int newHeight);
   //  Image crop( int x, int y, int width, int height ); 
   //  Image rotate( float angle );
   //  Image applyFilter( Filter filer ); // TODO: Implement Filter class
   //  Image convertToGrayscale(); 

    // Add other private member variables and functions as needed
};

#endif // IMAGE_H
