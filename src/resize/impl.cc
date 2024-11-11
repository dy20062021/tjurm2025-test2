#include "impls.h"


cv::Mat my_resize(const cv::Mat& input, float scale) {
    /**
     * 要求：
     *      实现resize算法，只能使用基础的语法，比如说for循环，Mat的基本操作。不能
     * 用cv::resize。resize算法的内容自行查找学习，不是很难。
     * 
     * 提示：
     * 无。
     * 
     * 通过条件：
     * 运行测试点，你的结果跟答案长的差不多就行。
     */
    int new_rows = static_cast<int>(input.rows * scale);
    int new_cols = static_cast<int>(input.cols * scale);
    cv::Mat output(new_rows, new_cols, input.type());

    for (int i = 0; i < new_rows; ++i) {
        for (int j = 0; j < new_cols; ++j) {
            int src_x = static_cast<int>(j / scale);
            int src_y = static_cast<int>(i / scale);

            
            src_x = std::min(src_x, input.cols - 1);
            src_y = std::min(src_y, input.rows - 1);

            output.at<uchar>(i, j) = input.at<uchar>(src_y, src_x);
        }
    }

    return output;
}