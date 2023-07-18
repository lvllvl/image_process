#include "Image.h"
#include <iostream>
#include <fstream>
#include <string>


Image::Image(){
   std::cout << "Image constructor called" << std::endl;
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
