/**
 * Masking is a very important step in many image processing and computer vision algorithms. The goal is to
 * segment out the area of interest and apply your algorithm to specific part of the image. You can perform all
 * operations on this segmented part of the image and put it back on the original image.
 *
 * Image mask is the same size as the original image. Usually we are using binary mask, where white pixels represent
 * the pixels we are interested in processing and black pixels represent the pixels we are not interested in
 * processing.
 */

#include <opencv2/highgui.hpp>

int main() {
    cv::Mat image = cv::imread("../boy.jpg");
    cv::namedWindow("Original image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Original image", image);

    // ***** 1st way of creating a binary mask
    // Create an empty image of the same size as the original
    cv::Mat mask1 = cv::Mat::zeros(image.size(), image.type());
    cv::namedWindow("Black mask", cv::WINDOW_AUTOSIZE);
    cv::imshow("Black mask", mask1);

    // If we are interested in processing eg. a face region we can update a mask by setting a proper pixel values
    // to 255.
    mask1(cv::Range(50, 200), cv::Range(170, 320)).setTo(255);
    cv::namedWindow("Updated mask with white section", cv::WINDOW_AUTOSIZE);
    cv::imshow("Updated mask with white section", mask1);


    // ***** 2nd way of creating a binary mask
    // The second way of creating a mask is not creating a rectangular mask, instead we will look at pixel intensity.
    // In our example, we want to focus on red pixels and create red color detector.
    // We would like to extract all the pixels that are kind of red.
    // Our logic/condition is: we will say that red pixel is a pixel where red channel is above 150 and 2 other channels
    // have low intensity, bellow 100
    cv::Mat mask2;

    // How the function bellow works, is that with scalar we are defining that we want a ranges of:
    // Blue channel between 0 - 100
    // Green channel between 0 - 100
    // Red channel between 150 - 255
    cv::inRange(image, cv::Scalar(0, 0, 150), cv::Scalar(100,100,255), mask2);
    cv::namedWindow("Binary mask for red color", cv::WINDOW_AUTOSIZE);
    cv::imshow("Binary mask for red color", mask2);



    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
