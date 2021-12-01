#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>

/**
 * Converting type of the image into a string
 * Mat image.type() CV function returns the integer which needs to be interpreted in order to get the image type
 * which will contain specific properties of image interested to us.
 *
 * Image type in openCV is of following format: 8UC1
 * 8 - how many bits are used to represent a single color channel
 * U - this tells us, is it an unsigned integer, a signed integer or floating point number
 * C1 - last two characters, C stands for channel ... C1 - means that its single channel image. C3 means that it have 3 channels etc ...
 */
std::string type2str(int type) {
    std::string r;

    // Decoding depth of the image
    // Depth of the image is the number of bits used to represent each pixel in an image.
    uchar depth = type & CV_MAT_DEPTH_MASK;

    // Get number of channels with expression bellow
    // Channel represents how many numbers we have per pixel is the number of channels that image has.
    // A monochrome image that has one number per pixel has one channel.
    // A more typical image that has three (R, G, B) numbers per pixel has three channels.
    // Such images are called RGB images.
    uchar chans = 1 + (type >> CV_CN_SHIFT);

    switch (depth) {
        case CV_8U:  r = "8U"; break;
        case CV_8S:  r = "8S"; break;
        case CV_16U: r = "16U"; break;
        case CV_16S: r = "16S"; break;
        case CV_32S: r = "32S"; break;

        case CV_32F: r = "32F"; break;
        case CV_64F: r = "64F"; break;
        default:     r = "User"; break;
    }

    r += "C";
    r += (chans+'0');

    return r;
}

int main( int argc, char** argv ) {
    // It will be loaded as matrix
    cv::Mat testImage = cv::imread("../number_zero.jpg", cv::IMREAD_GRAYSCALE);

    // Showing the matrix of the image
    std::cout << testImage << std::endl;

    std::cout << "Data type = " << type2str(testImage.type()) << std::endl;
    std::cout << "Image dimensions = " << testImage.size() << std::endl;
    /*
    cv::Mat image;
    image = cv::imread("../sample.jpeg" , cv::IMREAD_UNCHANGED);

    if(! image.data ) {
        std::cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );
    cv::imshow( "Display window", image );

    cv::waitKey(0);
    return 0;
    */
}