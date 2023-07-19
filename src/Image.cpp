#include "Image.h"
#include <iostream>
#include <fstream>
#include <string>

Image::Image()
{
   std::cout << "Image constructor called" << std::endl;
}

Image::Image(const std::string &filename)
{
   std::cout << "Image constructor called" << std::endl;
   Image::loadFrameFile(filename);
   // imageData.width = loadImageWidthFromFile(filename);
   // imageData.height = loadImageHeightFromFile(filename);

   // TODO: #1 make sure you're only opening the file ONE TIME, then gather data, be efficient!
   // TODO: #2 store the file name 
   // TODO: #3 store the number of channels in the image
}

Image::~Image()
{
   std::cout << "Image destructor called" << std::endl;
}

bool Image::loadFrameFile(const std::string filename)
{
   std::ifstream inputFile(filename); // Create file object
   if (inputFile.is_open())
   {
      // Check if file is open
      std::cout << "File is open" << std::endl;
      inputFile.close(); // Close file
   }
   else
   {
      std::cout << "Unable to open file" << std::endl;
      return false;
   }
   return true;
}

std::vector<cv::Vec3b> Image::openImage( const std::string& filename ){
   cv::Mat image = cv::imread( filename ); // Read the file

   std::vector<cv::Vec3b> pixels;
   if ( image.empty() ) {
      std::cerr << "Failed to open or read the image: " << filename << std::endl;
   }
   // Add the width and height to the ImageData struct
   imageData.width = image.cols;
   imageData.height = image.rows;
   
   int totalPixels = image.rows * image.cols;
   pixels.reserve( totalPixels );

   for ( int row = 0; row < image.rows; ++row ) {
      for ( int col = 0; col < image.cols; ++col ){
         pixels.push_back( image.at<cv::Vec3b>( row, col ) );
      }
   }
   return pixels;
}

// int Image::loadImageWidthFromFile(const std::string filename)
// {
//    std::ifstream inputFile(filename, std::ios::binary); // Create file object

//    if (inputFile.is_open())
//    {
//       // Check if file is open
//       std::cout << "File is open" << std::endl;
//       inputFile.seekg(18, std::ios::beg);

//       // Read the width from the file
//       unsigned int width = 0;
//       inputFile.read(reinterpret_cast<char *>(&width), sizeof(width));

//       inputFile.close(); // Close file
//       return static_cast<int>(width);
//    }
//    else
//    {
//       std::cout << "Unable to open file" << std::endl;
//       return -1;
//    }
// }

// int Image::loadImageHeightFromFile(const std::string filename)
// {
//    std::ifstream inputFile(filename, std::ios::binary); // Create file object

//    if (inputFile.is_open())
//    {
//       // Check if file is open
//       std::cout << "File is open" << std::endl;
//       inputFile.seekg(18, std::ios::beg);

//       // Read the height from the file
//       unsigned int height = 0;
//       inputFile.read(reinterpret_cast<char *>(&height), sizeof(height));

//       inputFile.close(); // Close file
//       return static_cast<int>(height);
//    }
//    else
//    {
//       std::cout << "Unable to open file" << std::endl;
//       return -1;
//    }
// }

// void Image::resize(int newWidth, int newHeight)
// {
//    std::cout << "Resize called" << std::endl;

//    // Function to resize an image
//    // void resizeImage(const unsigned char *inputImage, int inputWidth, int inputHeight,
//    //                  unsigned char *outputImage, int newWidth, int newHeight, int channels)
//    // {
//       for (int y = 0; y < newHeight; ++y)
//       {
//          for (int x = 0; x < newWidth; ++x)
//          {
//             for (int c = 0; c < channels; ++c)
//             {
//                // Calculate the corresponding pixel coordinates in the input image
//                float srcX = (float)(x * imageData.width) / newWidth;
//                float srcY = (float)(y * imageData.height) / newHeight;

//                // Calculate the integer pixel coordinates and fractional parts
//                int x0 = (int)srcX;
//                int y0 = (int)srcY;
//                int x1 = x0 + 1;
//                int y1 = y0 + 1;
//                float dx = srcX - x0;
//                float dy = srcY - y0;

//                // Perform bilinear interpolation
//                float pixel = (1 - dx) * (1 - dy) * inputImage[y0 * imageData.width * channels + x0 * channels + c] + dx * (1 - dy) * inputImage[y0 * imageData.width * channels + x1 * channels + c] + (1 - dx) * dy * inputImage[y1 * imageData.width * channels + x0 * channels + c] + dx * dy * inputImage[y1 * imageData.width * channels + x1 * channels + c];

//                // Set the pixel value in the output image
//                outputImage[y * newWidth * channels + x * channels + c] = (unsigned char)pixel;
//             }
//          }
//       }
//    // }
// }