#include "Image.h"
#include <iostream>
#include <fstream>
#include <string>


Image::Image(){
   std::cout << "Image constructor called" << std::endl;
}

Image::Image( const std::string& filename ){
   std::cout << "Image constructor called" << std::endl;
   Image::loadFrameFile(filename);
   // imageData.width = loadImageWidthFromFile(filename);
   // imageData.height = loadImageHeightFromFile(filename);
}

Image::~Image(){
   std::cout << "Image destructor called" << std::endl;
}

bool Image::loadFrameFile( const std::string filename ) {
   std::ifstream inputFile( filename ); // Create file object
   if (inputFile.is_open()) { 
      // Check if file is open
      std::cout << "File is open" << std::endl;
      inputFile.close(); // Close file
      } else {
         std::cout << "Unable to open file" << std::endl;
         return false;
         }
   return true;
   }

int Image::loadImageWidthFromFile( const std::string filename ) {
   std::ifstream inputFile( filename, std::ios::binary ); // Create file object

   if (inputFile.is_open()) { 
      // Check if file is open
      std::cout << "File is open" << std::endl;
      inputFile.seekg( 18, std::ios::beg );

      // Read the width from the file
      unsigned int width = 0;
      inputFile.read( reinterpret_cast<char*>( &width ), sizeof( width ) );

      inputFile.close(); // Close file
      return static_cast<int>( width );
      } else {
         std::cout << "Unable to open file" << std::endl;
         return -1;
         }
   }


int Image::loadImageHeightFromFile( const std::string filename ) {
   std::ifstream inputFile( filename, std::ios::binary ); // Create file object

   if (inputFile.is_open()) { 
      // Check if file is open
      std::cout << "File is open" << std::endl;
      inputFile.seekg( 18, std::ios::beg );

      // Read the height from the file
      unsigned int height = 0;
      inputFile.read( reinterpret_cast<char*>( &height ), sizeof( height ) );

      inputFile.close(); // Close file
      return static_cast<int>( height );

      } else {
         std::cout << "Unable to open file" << std::endl;
         return -1;
         }
   }


// int Image::getWidth(){

//    Image::loadFrameFile("test_images/you_tube.png");



// }
