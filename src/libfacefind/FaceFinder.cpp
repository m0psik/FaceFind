#include "FaceFinder.h"

#include <iostream>

FaceFinder::FaceFinder() = default;

void FaceFinder::setCameraNumber(const short &_cameraNumber) {
    cameraNumber = _cameraNumber;
}

void FaceFinder::increase_id() {
    if (current_id == 60000) {
        current_id = 0;
    }
    current_id++;
}

void FaceFinder::setObjectNumber(const short &_objectNumber) {
    objectNumber = _objectNumber;
}

void FaceFinder::start() {
    while (true) {
        motionAnalyze();
        if (!isFaceDetected()) {
            std::cout << "No face detected\n";
            continue;
        }
        std::cout << "FACE DETECTED\n";
        increase_id();
        for (auto &face: faces) {
            cv::imwrite("test.jpg", face);
        }
        return;
    }
}

void FaceFinder::motionAnalyze() {
    cv::VideoCapture capture(0);
    capture.set(3, 512);
    capture.set(4, 288);
    cv::Mat frame, gray, frameDelta, thresh, firstFrame;
    std::vector<std::vector<cv::Point> > cnts;
    capture.read(frame);
    cvtColor(frame, firstFrame, cv::COLOR_BGR2GRAY);
    GaussianBlur(firstFrame, firstFrame, cv::Size(21, 21), 0);

    while (capture.read(frame)) {
        cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
        GaussianBlur(gray, gray, cv::Size(21, 21), 0);

        absdiff(firstFrame, gray, frameDelta);
        threshold(frameDelta, thresh, 25, 255, cv::THRESH_BINARY);

        dilate(thresh, thresh, cv::Mat(), cv::Point(-1, -1), 2);
        findContours(thresh, cnts, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

        for (auto &cnt: cnts) {
            if (cv::contourArea(cnt) < 5000) {
                continue;
            }
            std::cout << "Motion detected\n";
            return;
        }
    }
}

bool FaceFinder::isFaceDetected() {
    cv::VideoCapture capture(0);
    cv::CascadeClassifier faceDetector("cascades/haarcascade_frontalface_alt.xml");
    cv::Mat image, frame, gray;
    int iterationCounter = 0;
    faces.clear();
    while (capture.read(frame)) {
        iterationCounter += 1;
        std::vector<cv::Rect> face;
        cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
        faceDetector.detectMultiScale(gray, face);
        if (!face.empty()) {
            faces.push_back(frame(face[0]));
        }
        if (iterationCounter == 5) {
            if (iterationCounter - faces.size() == 0) {
                return true;
            } else {
                return false;
            }
        }
    }
    return false;
}
