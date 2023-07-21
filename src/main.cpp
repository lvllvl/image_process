#include "../include/Image.h"
#include <iostream>

int main() {

    Image image;
    // image.loadFrameFile("test_images/testImage_01.png");
    image.openImage("test_images/testImage_01.png");
    image.displayImage("test_images/testImage_01.png");

    return 0;
}