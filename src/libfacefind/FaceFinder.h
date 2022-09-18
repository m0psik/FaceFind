#ifndef FACEFIND_FACEFINDER_H
#define FACEFIND_FACEFINDER_H

#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

class FaceFinder {
public:
    FaceFinder();
    void setObjectNumber(const short& _objectNumber);
    void setCameraNumber(const short& _cameraNumber);
    void start();
private:
    int current_id = 0;
    void increase_id();
    std::vector<cv::Mat> faces;
    short cameraNumber{};
    short objectNumber{};
    bool isFaceDetected(); // функция определяющая наличие лица в кадре
    static void motionAnalyze() ;
};


#endif //FACEFIND_FACEFINDER_H
