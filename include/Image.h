#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Image {
    // Member variables

    // Member function prototypes
    public:
        int getWidth();
        int getHeight();
        bool loadFrameFile( std::string filename );
        bool saveToFile( std::string filename );
        void resize( int newWidth, int newHeight);
        Image crop( int x, int y, int width, int height ); 
        Image rotate( float angle );
        // Image applyFilter( Filter filer ); // TODO: Implement Filter class
        Image convertToGrayscale(); 
};