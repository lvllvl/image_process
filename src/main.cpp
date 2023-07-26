#include "../include/Image.h"
#include "../include/FaceDetector.h"
#include <iostream>

int main()
{

    Image image;               // Create an Image object
    FaceDetector faceDetector; // Create a FaceDetector object

    try
    {
        cv::VideoCapture camera = image.initCamera(); // Init the camera
        bool convertToGrayscale = false;              // Flag to convert to grayscale

        while (true)
        {
            cv::CascadeClassifier faceCascade;

            cv::Mat frame; // Capture an image
            camera.read(frame);
            // Check if the frame is empty (e.g., camera read error)
            if (frame.empty())
            {
                std::cerr << "Error: Failed to capture frame from the camera." << std::endl;
                break; // Exit the loop if frame is empty
            }
            cv::imshow("Captured Frame", frame); // Display the captured frame

            std::vector<cv::Rect> faces = faceDetector.detectFaces(frame); // Detect faces in the captured frame
            if (faces.empty())
            {
                std::cout << "No faces detected." << std::endl;

                // print faces
                for (const cv::Rect &faceRect : faces){
                    std::cout << faceRect << std::endl;
                }
            }
            else
            {
                std::cout << faces.size() << " faces detected." << std::endl;
            }

            // Wait for a short duration ( e.g., 30 ms ) to control framerate
            int key = cv::waitKey(30);

            if (key == 'g')
            { // If 'g' is pressed, toggle the grayscale flag
                convertToGrayscale = !convertToGrayscale;
            }

            cv::Mat displayFrame = frame.clone(); // Create a copy of the frame to display
            if (convertToGrayscale)
            { // Convert the frame to grayscale if needed
                cv::cvtColor(frame, displayFrame, cv::COLOR_BGR2GRAY);
            }

            for (const cv::Rect &faceRect : faces)
            {
                cv::rectangle(displayFrame, faceRect, cv::Scalar(0, 255, 0), 2); // Draw a green rectangle around the face
            }

            cv::imshow("Display Frame", displayFrame); // Display the captured frame ( color or grayscale )

            // check if the user pressed a key ( key != -1 ) or
            // if 'q' was pressed ( ASCII value of 'q' is 113 )
            if (key != -1 || key == 113)
            {
                break; // exit the loop if a key is pressed or 'q' is detected
            }
        }
        cv::Mat captureImage = image.captureImage(camera); // After exiting loop, capture the image

        // convert the captured image to grayscale if needed
        if (convertToGrayscale)
        {
            cv::cvtColor(captureImage, captureImage, cv::COLOR_BGR2GRAY);
        }

        image.displayCapturedImage("Captured Image", captureImage); // Display the captured image
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}