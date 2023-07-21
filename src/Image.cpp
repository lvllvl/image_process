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

// FIXME: this is a duplicate function, remove it!
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

std::vector<cv::Vec3b> Image::openImage(const std::string &filename)
{

   cv::Mat image = cv::imread(filename); // Read the image file

   std::vector<cv::Vec3b> pixels; // create vector to store pixels

   if (image.empty())
   {
      std::cerr << "Failed to open or read the image: " << filename << std::endl;
   }

   // ImageData struct: add data to struct
   imageData.width = image.cols;
   imageData.height = image.rows;
   imageData.channels = image.channels();

   int totalPixels = image.rows * image.cols; // calculate total number of pixels
   pixels.reserve(totalPixels);               // reserve space in vector for pixels

   for (int row = 0; row < image.rows; ++row)
   {
      for (int col = 0; col < image.cols; ++col)
      {

         pixels.push_back(image.at<cv::Vec3b>(row, col)); // add pixels to vector
      }
   }
   return pixels;
}

void Image::resize(int newWidth, int newHeight)
{
   std::cout << "Resize called" << std::endl;
   std::vector<int> newPixels(newWidth * newHeight * imageData.channels); // create vector to store new pixels

   // Function to resize an image
   // void resizeImage(const unsigned char *imageData.pixels, int inputWidth, int inputHeight,
   //                  unsigned char *outputImage, int newWidth, int newHeight, int channels)
   // {
   for (int y = 0; y < newHeight; ++y)
   {
      for (int x = 0; x < newWidth; ++x)
      {
         for (int c = 0; c < imageData.channels; ++c)
         {
            // Calculate the corresponding pixel coordinates in the input image
            float srcX = (float)(x * imageData.width) / newWidth;
            float srcY = (float)(y * imageData.height) / newHeight;

            // Calculate the integer pixel coordinates and fractional parts
            int x0 = (int)srcX;
            int y0 = (int)srcY;
            int x1 = x0 + 1;
            int y1 = y0 + 1;
            float dx = srcX - x0;
            float dy = srcY - y0;

            // Perform bilinear interpolation
            float pixel = (1 - dx) * (1 - dy) * imageData.pixels[y0 * imageData.width * imageData.channels + x0 * imageData.channels + c] + dx * (1 - dy) * imageData.pixels[y0 * imageData.width * imageData.channels + x1 * imageData.channels + c] + (1 - dx) * dy * imageData.pixels[y1 * imageData.width * imageData.channels + x0 * imageData.channels + c] + dx * dy * imageData.pixels[y1 * imageData.width * imageData.channels + x1 * imageData.channels + c];

            // Set the pixel value in the output image
            newPixels[y * newWidth * imageData.channels + x * imageData.channels + c] = (int)pixel;
         }
      }
   }
   imageData.pixels = std::move(newPixels);
   imageData.width = newWidth;
   imageData.height = newHeight;
}

void Image::convertToGrayscale()
{
   std::cout << "Convert to grayscale called" << std::endl;

   for (int i = 0; i < imageData.pixels.size(); i += 3)
   {

      int red = imageData.pixels[i];
      int green = imageData.pixels[i + 1];
      int blue = imageData.pixels[i + 2];

      // Calculate grayscale value by taking the average
      int grayscale = (red + green + blue) / 3;

      // Assign the grayscale value to all three channels ( R, G, B )
      imageData.pixels[i] = grayscale;
      imageData.pixels[i + 1] = grayscale;
      imageData.pixels[i + 2] = grayscale;
   }
}

void Image::displayImage(const std::string &filename)
{
   std::cout << "displayImage function called" << std::endl;
   cv::Mat image = cv::imread(filename);

   if (image.empty())
   {
      std::cout << "Could not open or find the image" << std::endl;
      return;
   }
   cv::imshow("Display window", image);
   cv::waitKey(10000);
}

cv::VideoCapture Image::initCamera()
{
   std::cout << "initCamera function called" << std::endl;

   cv::VideoCapture camera(0); // open the default camera

   camera.set(cv::CAP_PROP_FRAME_WIDTH, 640);
   camera.set(cv::CAP_PROP_FRAME_HEIGHT, 480);

   if (!camera.isOpened())     // check if we succeeded
   {
      std::cout << "Unable to open camera" << std::endl;
      throw std::runtime_error( "Failed to access the camera." );
   }
   return camera;
}

cv::Mat Image::captureImage( cv::VideoCapture& camera ){

   cv::Mat frame; 
   if ( !camera.read( frame ) ){
      // Handle the iamge capture failure 
      throw std::runtime_error( "Failed to capture an image." );
   }
   return frame;
}

void Image::displayCapturedImage( const std::string& windowName, cv::Mat& image ){

   if (! image.empty()) {
      cv::imshow( windowName, image );
      cv::waitKey(0);

   } else{
      std::cout << "Image is empty" << std::endl;
   }
}