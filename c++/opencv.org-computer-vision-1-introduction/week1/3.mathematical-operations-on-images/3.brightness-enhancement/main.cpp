/**
 * Brightness is a measure of light falling on the scene. In RGB color space, it can be though of as the
 * arithmetic mean of the R, G and B color values. To make image brighter, the intensity values should be increased
 * by some offset (beta) and vice-versa
 */
#include <opencv2/highgui.hpp>

int main() {
    cv::Mat image = cv::imread("../boy.jpg");

    // Let's increase brightness by 50 intensity levels
    int brightnessOffset = 50;

    // Add the offset for increasing brightness
    cv::Mat brightHighImage = image.clone();
    cv::Mat brightHighChannels[3];
    cv::split(brightHighImage, brightHighChannels);

    for(int i=0; i<3; i++) {
        cv::add(brightHighChannels[i], brightnessOffset, brightHighChannels[i]);
    }

    cv::merge(brightHighChannels, 3, brightHighImage);

    cv::imshow("Original image", image);
    cv::imshow("Contrast brightness high image", brightHighImage);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
