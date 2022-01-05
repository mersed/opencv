#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

int main() {
    // Load the face image
    cv::Mat faceImage = cv::imread("../musk.jpg");
    faceImage.convertTo(faceImage, CV_32FC3);
    faceImage = faceImage/255.0;
    cv::imshow("Original image", faceImage);

    // Load the Sunglasses image with Alpha channel
    cv::Mat glassPNG = cv::imread("../sunglass.png", cv::IMREAD_UNCHANGED);
    glassPNG.convertTo(glassPNG, CV_32F);
    glassPNG = glassPNG/255.0;

    // Resize the image to fit over the eye region
    cv::resize(glassPNG, glassPNG, cv::Size(), 0.5, 0.5);

    std::cout << "Image dimensions" << glassPNG.size() << std::endl;
    std::cout << "Number of channels = " << glassPNG.channels() << std::endl;

    int glassHeight = glassPNG.size().height;
    int glassWidth = glassPNG.size().width;

    // Separate the Color and alpha channels
    cv::Mat glassRGBAChannels[4];
    cv::Mat glassRGBChannels[3];
    cv::split(glassPNG, glassRGBAChannels);

    for(int i=0; i<3; i++) {
        // Copy, R,G,B channel from RGBA ro RGB
        glassRGBChannels[i] = glassRGBAChannels[i];
    }

    cv::Mat glassRGB, glassMask1;
    // Prepare RGB image
    cv::merge(glassRGBChannels, 3, glassRGB);
    // Alpha channel is the 4th channel in RGBA Image
    glassMask1 = glassRGBAChannels[3];

    cv::imshow("Original glass image", glassPNG);
    cv::imshow("Glass RGB Image", glassRGB);
    cv::imshow("Glass alpha channel", glassMask1);

    // -------- Using naive replace
    // Top left corner of the glases
    int topLeftRow = 130;
    int topLeftCol = 130;
    int bottomRightRow = topLeftRow + glassHeight;
    int bottomRightCol = topLeftCol + glassWidth;

    // Make a copy
    cv::Mat faceWithGlassesNaive = faceImage.clone();
    cv::Mat roiFace = faceWithGlassesNaive(cv::Range(topLeftRow, bottomRightRow), cv::Range(topLeftCol, bottomRightCol));
    // Replace the eye region with the sunglass image
    glassRGB.copyTo(roiFace);
    cv::imshow("Face with glasses naive", faceWithGlassesNaive);

    /**
     * You can see that output is not even close. This is because the BGR image is opaque and will either have a black
     * or white rectangle around the sunglass. We need to use a mask along with the sunglass image in order to get
     * the desired output. Let us see how it can be done with very simple steps using the tools we learned till now.
     */


    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
