#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    std::cout << "Hello, World!" << std::endl;
    cv::Mat img_L=cv::imread("./data/tsukuba_l.png", cv::IMREAD_GRAYSCALE);
    cv::Mat img_R=cv::imread("./data/tsukuba_r.png", cv::IMREAD_GRAYSCALE);



    cv::Mat disparity_data;
    cv::Mat disparity_map;
    double min,max;
    cv::Ptr<cv::StereoBM> sbm = cv::StereoBM::create();
    sbm->compute(img_L, img_R, disparity_data);
    cv::minMaxLoc(disparity_data, &min, &max);
    disparity_data.convertTo(disparity_map, CV_8UC1, 255/(max-min), -255*min/(max-min));


    cv::imshow("SBM ", disparity_map);
    cv::waitKey(0);

    return 0;
}