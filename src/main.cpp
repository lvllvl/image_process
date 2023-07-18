#include "../include/Image.h"
#include <iostream>

int main() {

    Image image;
    image.loadFrameFile("test_images/test.txt");
    std::cout << "Hello, World!" << std::endl;

    return 0;
}