#include <iostream>

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/objdetect.hpp"

using namespace cv;
using namespace std;

int main() {

    VideoCapture cap(0);
    if(!cap.isOpened()) return -1;

    Mat frame;
    namedWindow("edges", WINDOW_AUTOSIZE);

    CascadeClassifier faceCascade;
    faceCascade.load("haarcascade_frontalface_default.xml");

    if(faceCascade.empty()) {
        cout << "Error loading cascade classifier" << endl;
        return -1;
    }

    vector<Rect> faces;

    for(;;)
    {
        cap >> frame;
        faceCascade.detectMultiScale(frame, faces, 1.1, 3, 0, Size(30, 30));
        for(size_t i = 0; i < faces.size(); i++) {
            rectangle(frame, faces[i], Scalar(255, 0, 0), 2);
        }
        imshow("edges", frame);
        if(waitKey(30) >= 0) break;
    }
    return 0;
}
