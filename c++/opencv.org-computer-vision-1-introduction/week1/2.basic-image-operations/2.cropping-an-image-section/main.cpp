#include <opencv2/highgui.hpp>

int main() {
    cv::Mat image = cv::imread("../boy.jpg");
    cv::namedWindow("Original image", cv::WINDOW_NORMAL);
    cv::imshow("Original image", image);

    // Crop the image / crop rectangle
    // x coordinates = 170 to 320
    // y coordinates - 40 to 200
    cv::Mat cropped = image(cv::Range(40, 200), cv::Range(170, 320));
    cv::namedWindow("Cropped image", cv::WINDOW_NORMAL);
    cv::imshow("Cropped image", cropped);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
