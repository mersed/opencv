/**
 * Many definitions of contrast exists in literature. Without going into the gory details, roughly speaking it is the
 * difference in intensity between the brightest and darkest regions of a given image. Higher the difference, higher the
 * contrast. The maximum contrast of an image is also known as Dynamic Range. In an image with good contrast, objects
 * are easily discernible.
 *
 * One of the easiest way to improve contrast of the image is intensity scaling.
 *
 * In this approach, a scale factor (alpha) is multiplied with intensity values of all the pixels. Given bellow is
 * the code snippet to do the same.
 */

#include <opencv2/highgui.hpp>

int main() {
    cv::Mat image = cv::imread("../boy.jpg");

    double contrastPercentage = 30.0;
    // Multiply with scaling factor to increase contrast
    cv::Mat contrastHigh = image;

    // Convert contrastHigh to float
    contrastHigh.convertTo(contrastHigh, CV_64F, 1/255.0);
    contrastHigh = contrastHigh * (1 + contrastPercentage/100.0);

    cv::imshow("Original image", image);
    cv::imshow("Contrast high image", contrastHigh);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
