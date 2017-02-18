#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::vector;

using namespace cv;


int main(int argc, const char** argv)
{
    // get video capture
    VideoCapture capture(0);
    char windowName[] = "Control";

    // check whether the image is loaded or not
    if (!capture.isOpened())
    {
        cout << "Error : No video capture found!!" << endl;
        return -1;
    }

    namedWindow(windowName, CV_WINDOW_AUTOSIZE);

    // define HSV low and high variables
    int iLowH = 0;
    int iLowS = 0;
    int iLowV = 0;

    int iHighH = 180;
    int iHighS = 255;
    int iHighV = 255;

    // create trackbars in control window
    cvCreateTrackbar("LowH", windowName, &iLowH, 180);
    cvCreateTrackbar("HighH", windowName, &iHighH, 180);

    cvCreateTrackbar("LowS", windowName, &iLowS, 255);
    cvCreateTrackbar("HighS", windowName, &iHighS, 255);

    cvCreateTrackbar("LowV", windowName, &iLowV, 255);
    cvCreateTrackbar("HighV", windowName, &iHighV, 255);

    for (;;)
    {
        Mat imgOriginal;

        bool bSuccess = capture.read(imgOriginal);
        if (!bSuccess)
        {
            cout << "Error: Could not capture image!" << endl;
            break;
        }

        Mat imgHSV;
        Mat imgThreshold;

        // convert the captured images from bgr to hsv
        cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV);

        // Threshold the image
        inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThreshold);

        // morphological opening remove small objects from the foreground
        erode(imgThreshold, imgThreshold, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
        dilate(imgThreshold, imgThreshold, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

        // morphological closing fill small holes in the foreground
        dilate(imgThreshold, imgThreshold, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
        erode(imgThreshold, imgThreshold, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

        // show the threshold and the original
        imshow("Threshold", imgThreshold);
        imshow("Original", imgOriginal);

        if (waitKey(30) == 27)
        {
            break;
        }
    }

    return 0;
}