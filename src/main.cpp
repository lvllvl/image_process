#include "../include/Image.h"
#include <iostream>

int main() {
    
    Image image;

    try {
        // Init the camera
        cv::VideoCapture camera = image.initCamera();
        bool convertToGrayscale = false;

        while (true) {
            // Capture an image
            cv::Mat frame; 
            camera.read( frame );

            // Display the captured frame 
            cv::imshow( "Captured Frame", frame );

            // Wait for a short duration ( e.g., 30 ms ) to control framerate
            int key = cv::waitKey( 30 );
            if (key == 'g' ){
                convertToGrayscale = !convertToGrayscale;
            }

            cv::Mat displayFrame = frame.clone(); 
            if ( convertToGrayscale ){
                cv::cvtColor( frame, displayFrame, cv::COLOR_BGR2GRAY );
            }

            // Display the frame ( color or grayscale )
            cv::imshow( "Display Frame", displayFrame );

            // check if the user pressed a key ( key != -1 ) or if 'q' was pressed ( ASCII value of 'q' is 113 )
            if ( key != -1 ||   key == 113 ) {
                break; // exit the loop if a key is pressed or 'q' is detected 
            }
        }
        // After exiting loop, capture the image 
        cv::Mat captureImage = image.captureImage( camera );

        // convert the captured image to grayscale if needed
        if ( convertToGrayscale ){
            cv::cvtColor( captureImage, captureImage, cv::COLOR_BGR2GRAY );
        }

        // Display the captured image
        image.displayCapturedImage( "Captured Image", captureImage );

    } catch ( const std::exception& ex ){
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    }
    
    // image.openImage("test_images/testImage_01.png");
    // image.displayImage("test_images/testImage_01.png");

    // image.initCamera();

    return 0;
}