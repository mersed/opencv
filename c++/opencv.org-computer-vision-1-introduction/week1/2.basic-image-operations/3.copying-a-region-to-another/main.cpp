#include <opencv2/highgui.hpp>

/**
 * Bellow code demonstrates how to copy one region to another.
 * Only requirement is to make sure that roi matrix dimension match, and we can copy
 * thing sto specific roi of the image how ever we want.
 */
int main() {
    cv::Mat image = cv::imread("../boy.jpg");
    cv::namedWindow("Original image", cv::WINDOW_NORMAL);
    cv::imshow("Original image", image);

    // First lets create a copy of the original image
    cv::Mat copiedImage = image.clone();

    cv::Mat copyRoi = image(cv::Range(40, 200), cv::Range(180, 320));

    // Find height and width of the roi
    int roiHeight = copyRoi.size().height;
    int roiWidth = copyRoi.size().width;

    // Copy to the left of the face
    copyRoi.copyTo(copiedImage(cv::Range(40, 40 + roiHeight), cv::Range(10, 10 + roiWidth)));

    // Copy to the right of the face
    copyRoi.copyTo(copiedImage(cv::Range(40, 40 + roiHeight), cv::Range(330, 330 + roiWidth)));

    cv::namedWindow("Image with copied rois", cv::WINDOW_NORMAL);
    cv::imshow("Image with copied rois", copiedImage);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
