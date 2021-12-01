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
    if(!testImage.data ) {
        std::cout << "Could not open or find the image" << std::endl ;
        return -1;
    }

    // Showing the matrix of the image
    std::cout << testImage << std::endl;

    std::cout << "Data type = " << type2str(testImage.type()) << std::endl;
    std::cout << "Image dimensions = " << testImage.size() << std::endl;

    // --- Manipulating pixels ---
    // Getting a pixel at specific location (row, column)
    std::cout << (int)testImage.at<uchar>(0, 0) << std::endl;

    // Changing pixel at specific location
    testImage.at<uchar>(0, 0) = 200;
    std::cout << testImage << std::endl;

    // --- Manipulating group of pixels ---
    // Define our roi (region of interest)
    cv::Mat testRoi = testImage(cv::Range(0,2), cv::Range(0,4));
    std::cout << "Original Matrix\n" << testImage << std::endl << std::endl;
    std::cout << "Selected Region\n" << testRoi << std::endl;

    // Modify region
    testImage(cv::Range(0,2), cv::Range(0,4)).setTo(111);
    std::cout << "Modified Matrix\n" << testImage << std::endl;

    // --- Saving an an image ---
    cv::imwrite("../number_zero_changed.jpg", testImage);

    // --- Displaying an image ---
    cv::namedWindow( "Display window", cv::WINDOW_NORMAL );
    cv::imshow( "Display window", testImage );

    // --- Loading color image ---
    cv::Mat colorImage = cv::imread("../musk.jpg", cv::IMREAD_UNCHANGED); // IMREAD_COLOR is default
    if(!colorImage.data ) {
        std::cout << "Could not open or find the color image" << std::endl ;
        return -1;
    }

    // If we take a look we will see that we have 3 dimensions here ... Number or rows and columns + number of channels
    std::cout << std::endl << std::endl;
    std::cout << "Color image: " << std::endl;
    std::cout << "image size = " << colorImage.size() << std::endl;
    // It will have 3 channels here because its RGB image
    // Each channel itself is a grayscale image.
    // The combination of intensity values of the three channels gives the color that is displayed on the screen.
    // In openCV, the order of channels, R, G and B is reverse. i.e. In the image matrix, the Blue channel is indexed first
    // followed by the Green Channel and finally the Red Channel
    std::cout << "image channels = " << colorImage.channels() << std::endl;


    // --- Splitting and Merging channels ---
    cv::Mat imgChannels[3];
    cv::split(colorImage, imgChannels);
    cv::namedWindow( "Original color image", cv::WINDOW_NORMAL );
    cv::imshow( "Original color image", colorImage );
    cv::namedWindow( "Blue channel", cv::WINDOW_NORMAL );
    cv::imshow( "Blue channel", imgChannels[0] );
    cv::namedWindow( "Green channel", cv::WINDOW_NORMAL );
    cv::imshow( "Green channel", imgChannels[1] );
    cv::namedWindow( "Red channel", cv::WINDOW_NORMAL );
    cv::imshow( "Red channel", imgChannels[2] );

    // --- Manipulating color pixels
    // Lets load image as a color image. Even if original image is grayscale, when we pass 1 as a flag (which is equal to
    // IMREAD_COLOR, it replicates grayscale channel of the original image and produces 3 channel color image where
    // all 3 channels under those conditions are equal.
    cv::Mat grayscaleToColorImage = cv::imread("../number_zero.jpg", cv::IMREAD_COLOR); // IMREAD_COLOR is default
    if(!grayscaleToColorImage.data ) {
        std::cout << "Could not open or find the grayscaleToColorImage image" << std::endl ;
        return -1;
    }

    // If we print image it will look grayscale because all 3 channels are the same
    cv::namedWindow( "grayscaleToColorImage image", cv::WINDOW_NORMAL );
    cv::imshow( "grayscaleToColorImage image", grayscaleToColorImage );

    std::cout << std::endl << std::endl;
    std::cout << "Grayscale to color image and channel representation " << std::endl;
    // Get pixel intensity at 0,0 -- it will be [1, 0, 3]
    std::cout << grayscaleToColorImage.at<cv::Vec3b>(0,0) << std::endl;

    // Lets modify pixels at specific locations
    grayscaleToColorImage.at<cv::Vec3b>(0, 0) = cv::Vec3b(0, 255, 255);
    cv::namedWindow( "grayscaleToColorImage image - yellow pixel", cv::WINDOW_NORMAL );
    cv::imshow( "grayscaleToColorImage image - yellow pixel", grayscaleToColorImage );

    grayscaleToColorImage.at<cv::Vec3b>(1, 1) = cv::Vec3b(255, 255, 0);
    cv::namedWindow( "grayscaleToColorImage image - cyan pixel", cv::WINDOW_NORMAL );
    cv::imshow( "grayscaleToColorImage image - cyan pixel", grayscaleToColorImage );

    grayscaleToColorImage.at<cv::Vec3b>(2, 2) = cv::Vec3b(255, 0, 255);
    cv::namedWindow( "grayscaleToColorImage image - magenta pixel", cv::WINDOW_NORMAL );
    cv::imshow( "grayscaleToColorImage image - magenta pixel", grayscaleToColorImage );

    // Modify region of interest (roi)
    cv::Size size = grayscaleToColorImage.size();
    grayscaleToColorImage(
        cv::Range(0, 3),
        cv::Range(size.width-2, size.width)
    ).setTo(cv::Scalar(255, 0, 0));
    grayscaleToColorImage(
            cv::Range(3, 6),
            cv::Range(size.width-2, size.width)
    ).setTo(cv::Scalar(0, 255, 0));
    grayscaleToColorImage(
            cv::Range(6, 9),
            cv::Range(size.width-2, size.width)
    ).setTo(cv::Scalar(0, 0, 255));

    cv::namedWindow( "grayscaleToColorImage image - range of pixels", cv::WINDOW_NORMAL );
    cv::imshow( "grayscaleToColorImage image - range of pixels", grayscaleToColorImage );



    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}