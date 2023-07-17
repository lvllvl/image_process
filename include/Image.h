#include <string>
class Image {
    // Member variables

    // Member function prototypes
    int getWidth();
    int getHeight();
    bool loadFrameFile( const std::string filename );
    bool saveToFile( std::string filename );
    void resize( int newWidth, int newHeight);
    Image crop( int x, int y, int width, int height ); 
    Image rotate( float angle );
    // Image applyFilter( Filter filer ); // TODO: Implement Filter class
    Image convertToGrayscale(); 
    
     
};