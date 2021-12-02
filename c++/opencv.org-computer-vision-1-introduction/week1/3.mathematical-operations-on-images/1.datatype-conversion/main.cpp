/**
 * Before we get into any mathematical operations, it is very important to understand the data types used and how to
 * convert from one to another.
 *
 * As we saw in previous modules, an image represented as a Mat once it's read using imread function. The default
 * datatype of this object is unsigned integer (8 bits). For most Arithmetic operations like multiplication or division,
 * we need to convert the array type to floating point with each pixel having 16, 32 or 64 bits of data. This helps
 * prevent overflow while working with the images.
 */
#include <opencv2/highgui.hpp>
#include <iostream>

int main() {
    cv::Mat image = cv::imread("../boy.jpg");

    // In this example we are going to convert image to 32 bit floating point format
    // When the image is in that format, the expected range is from 0 to 1, hence we need to normalize it,
    // so we don't have values outside this range. This is the reason why we are defining scaling factor.
    double scalingFactor = 1/255.0;
    double shift = 0;

    // Converting image from unsigned char to float (32 bit)
    image.convertTo(image, CV_32FC3, scalingFactor, shift);
    std::cout << image << std::endl;

    // We can convert it back using reciprocal of the scaling factor to move values back to range 0 to 255.
    image.convertTo(image, CV_8UC3, 1.0/scalingFactor, shift);
    cv::imshow("Converted back image", image);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
