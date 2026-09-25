#include <iostream>

#include <opencv2/core.hpp>

using namespace cv;
using namespace std;

int main() {

    Mat R = Mat(3, 2, CV_8UC3);
    randu(R, Scalar::all(0), Scalar::all(255));
     cout << "R (python)  = " << endl << format(R, Formatter::FMT_PYTHON) << endl << endl;

    return 0;
}
