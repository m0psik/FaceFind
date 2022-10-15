#ifndef FACEFIND_FACEFINDER_H
#define FACEFIND_FACEFINDER_H

#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

class FaceFinder {
public:
    FaceFinder();
    std::vector< uchar* > start();
private:
    std::vector<cv::Mat> faces;
    bool isFaceDetected(); // функция определяющая наличие лица в кадре
    static void motionAnalyze() ;
};


#endif //FACEFIND_FACEFINDER_H
