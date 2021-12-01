#include <iostream>
#include <opencv2/highgui.hpp>

/**
 * We heard about red blue and green channels of the image. Some images have a forth channel called "the alpha
 * channel", which stores transparency information. These kind of transparent images are used when we want the image
 * to look not rectangular. Alpha channel allows us to control which parts of the image are visible, and which parts
 * are transparent, so you can see through them.
 */

int main() {
    // Read the image. Note that we are passing flag = IMREAD_UNCHANGED which is equivalent to -1
    cv::Mat image = cv::imread("../panther.png", cv::IMREAD_UNCHANGED);
    if(!image.data ) {
        std::cout << "Could not open or find the image" << std::endl ;
        return -1;
    }

    std::cout << "image size = " << image.size() << std::endl;
    std::cout << "number of channels = " << image.channels() << std::endl;

    // Let's split image to two groups. Let's get BGR image out, which is the first 3 channels, and get
    // alpha mask as the last channel.
    cv::Mat imgBGR;
    cv::Mat imgPNGChannels[4];
    cv::split(image, imgPNGChannels);
    cv::merge(imgPNGChannels, 3, imgBGR);

    cv::Mat imgMask = imgPNGChannels[3];

    // Let's show RGB image and alpha mask as a separate images
    cv::namedWindow("RGB image", cv::WINDOW_NORMAL);
    cv::imshow( "RGB image", imgBGR );
    cv::namedWindow("Alpha mask image", cv::WINDOW_NORMAL);
    cv::imshow("Alpha mask image", imgMask);

    /**
     * There are few things to notice when we separate this to 2 images (rgb and alpha channel mask).
     * Place where image was transparent, is black. And place where we wanted to display an image is white.
     * But ff we look at alpha mask image, at the boundaries between black/white, the transparency value is between
     * 0 - 255, which means that this mask is not necessary binary. The value which we observe on these boundaries, semi
     * transparent pixels, is combination of foreground and the background.
     */

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
