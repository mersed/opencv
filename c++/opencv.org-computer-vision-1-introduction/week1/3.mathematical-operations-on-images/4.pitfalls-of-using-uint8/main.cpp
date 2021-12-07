/**
 * NOTE: Material bellow is used from opencv course and some recommendations and practices within
 * these examples does not make sense at all.
 * Eg. Converting to float to avoid overflow while doing arithmetic operations, then converting back to uint8 where
 * clipping is going to happen during conversion again does not make sense, because you end up with the same issue
 * as you initially had with uint8 and arithmetic operations.
 *
 * I think that after conversion to specific type to avoid overflow, you should stick to it withot returning back
 * to uint8 which will have same issue as we described bellow.
 */
#include <iostream>
#include <opencv2/highgui.hpp>

int main() {
    uint8_t data[] = {100, 110, 120, 130};
    cv::Mat a(2, 2, CV_8UC1, data);

    std::cout << a << std::endl;

    // We can see here, that element a[1,1] should have been 260, but instead its clipped. THere will be a similar
    // problem if we subtract.
    std::cout << a + 130 << std::endl;
    std::cout << "--------------------" << std::endl;

    // Lets us see another interesting nuisance
    // In this case, both operands (a and 130) are uint8 and thus the output is uint8 and hence the clipping.
    // This shows a major pitfall of using uint8 while dealing with arithmetic operations on images.
    // Thus, it is important to convert the images to int or float (recommended) data types while doing arithmetic
    // operations (like addition, subtraction, multiplication etc.) on images to avoid undesirable results.
    uint8_t scalar = 130;
    std::cout << a - scalar << std::endl;
    std::cout << "--------------------" << std::endl;

    // ----------- Solution 1: Use opencv functions
    // For some kind of stupid reason this is marked as a solution 1 for the problem outlined bellow,
    // but this addition will have exactly the same issue with uint8 truncation as before... I would not
    // consider this as a solution at all
    cv::Mat addition;
    cv:add(a, cv::Scalar(130), addition);
    std::cout << addition << std::endl;
    std::cout << "--------------------" << std::endl;

    // ----------- Solution 2: Convert to int
    // You should convert to higher integer types to avoid underflow situations. Perform clipping if necessary
    // and bring it back to uint8 in the final stage as that is what the display functions expect.
    int dataInt[] = {100, 110, 120, 130};
    cv::Mat b(2, 2, CV_32SC1, dataInt);
    b = b + 130;
    std::cout << b << std::endl;
    std::cout << "--------------------" << std::endl;

    // If we try to convert it back to uint8, again it will be clipped
    b.convertTo(b, CV_8UC1);
    std::cout << b << std::endl;
    std::cout << "--------------------" << std::endl;

    // ----------- Solution 3: Convert to normalized float32/float64
    // It is a good practice to convert the uint8 and normalize the range to [0,1] and change it back to [0, 255]
    // after doing all arithmetic operations
    cv::Mat a_float32;
    a.convertTo(a_float32, CV_32F, 1.0/255.0, 0);
    a_float32 = a_float32 + 130.0/255.0;
    std::cout << a_float32 << std::endl;
    std::cout << "--------------------" << std::endl;

    cv::Mat c;
    a_float32.convertTo(c, CV_32F, 255.0, 0.0);
    std::cout << c << std::endl;
    std::cout << "--------------------" << std::endl;

    // Clipped output
    cv::Mat b_uint8;
    c.convertTo(b_uint8, CV_8UC1);
    std::cout << b_uint8;
    return 0;
}
