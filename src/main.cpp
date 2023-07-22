#include "../include/Image.h"
#include <iostream>

int main() {
    
    Image image; // Create an Image object
    try {
        cv::VideoCapture camera = image.initCamera();// Init the camera
        bool convertToGrayscale = false; // Flag to convert to grayscale

        while (true) {
            cv::Mat frame; // Capture an image
            camera.read( frame );

            cv::imshow( "Captured Frame", frame );// Display the captured frame 

            // Wait for a short duration ( e.g., 30 ms ) to control framerate
            int key = cv::waitKey( 30 );

            if (key == 'g' ){ // If 'g' is pressed, toggle the grayscale flag
                convertToGrayscale = !convertToGrayscale;
            }

            cv::Mat displayFrame = frame.clone();  // Create a copy of the frame to display
            if ( convertToGrayscale ){// Convert the frame to grayscale if needed
                cv::cvtColor( frame, displayFrame, cv::COLOR_BGR2GRAY ); 
            }

            cv::imshow( "Display Frame", displayFrame ); // Display the captured frame ( color or grayscale )

            // check if the user pressed a key ( key != -1 ) or 
            // if 'q' was pressed ( ASCII value of 'q' is 113 )
            if ( key != -1 ||   key == 113 ) {
                break; // exit the loop if a key is pressed or 'q' is detected 
            }
        }
        cv::Mat captureImage = image.captureImage( camera );// After exiting loop, capture the image

        // convert the captured image to grayscale if needed
        if ( convertToGrayscale ){
            cv::cvtColor( captureImage, captureImage, cv::COLOR_BGR2GRAY );
        }

        image.displayCapturedImage( "Captured Image", captureImage );// Display the captured image

    } catch ( const std::exception& ex ){
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    }
    
    return 0;
}