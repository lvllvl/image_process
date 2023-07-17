#include "Image.h"
class Image {
    // Member variables

    // // Member function prototypes
    // int getWidth();
    // int getHeight();
    // bool loadFrameFile( std::string filename );
    // bool saveToFile( std::string filename );
    // void resize( int newWidth, int newHeight);
    // Image crop( int x, int y, int width, int height ); 
    // Image rotate( float angle );
    // Image applyFilter( Filter filer ); // TODO: Implement Filter class
    // Image convertToGrayscale(); 

     bool Image::loadFrameFile( std::string filename ) {
        ofstream file; // Create file object
        file.open(filename); // Open file
        file << "Writing this to a file.\n";
        file.close(); // Close file

        return true;
     }
};