#include <opencv2/highgui.hpp>

// Creating an image from scratch
int main() {
    // Let's begin by creating an empty matrix filled with zeros (will create a black image)
    cv::Mat emptyMatrix = cv::Mat(100, 200, CV_8UC3, cv::Scalar(0, 0, 0));
    cv::namedWindow( "Black image", cv::WINDOW_NORMAL );
    cv::imshow( "Black image", emptyMatrix );

    // We can change all the pixels from image from above, to white pixels.
    emptyMatrix.setTo(cv::Scalar(255, 255, 255));
    cv::namedWindow( "White image", cv::WINDOW_NORMAL );
    cv::imshow( "White image", emptyMatrix );

    // How to create an empty matrix, which is the same size as some other image
    cv::Mat emptyOriginal = cv::Mat(emptyMatrix.size(), emptyMatrix.type(), cv::Scalar(100, 100, 100));
    cv::namedWindow( "Same size image as previous", cv::WINDOW_NORMAL );
    cv::imshow( "Same size image as previous", emptyOriginal );

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
