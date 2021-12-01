#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

/**
 * There are multiple ways to resize image using cv.
 * Bellow we are going to go through them
 */
int main() {
    cv::Mat image = cv::imread("../boy.jpg");
    cv::namedWindow("Original image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Original image", image);

    // *** Method 1 - Specify width and height
    int resizeDownWidth = 300;
    int resizeDownHeight = 200;
    cv::Mat resizeDown;
    cv::resize(image, resizeDown, cv::Size(resizeDownWidth, resizeDownHeight), cv::INTER_LINEAR);

    // Mess up with the aspect ratio
    int resizeUpWith = 600;
    int resizeUpHeight = 900;
    cv::Mat resizeUp;
    cv::resize(image, resizeUp, cv::Size(resizeUpWith, resizeUpHeight), cv::INTER_LINEAR);

    cv::namedWindow("Resize down image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Resize down image", resizeDown);
    cv::namedWindow("Resize up image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Resize up image", resizeUp);


    // *** Method 1 - Specify scaling factor
    // Scaling up the image 1.5 times by specifying both scaling factors
    double scaleUpX = 1.5;
    double scaleUpY = 1.5;

    // Scaling Down the image 0.6 times specifying a single scale factor
    double scaleDown = 0.6;

    cv::Mat scaledUp, scaledDown;

    cv::resize(image, scaledDown, cv::Size(), scaleDown, scaleDown, cv::INTER_LINEAR);
    cv::resize(image, scaledUp, cv::Size(), scaleUpX, scaleUpY, cv::INTER_LINEAR);

    cv::namedWindow("Scaled up image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Scaled up image", scaledUp);
    cv::namedWindow("Scaled down image", cv::WINDOW_AUTOSIZE);
    cv::imshow("Scaled down image", scaledDown);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
