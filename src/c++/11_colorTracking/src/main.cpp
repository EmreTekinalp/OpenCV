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
    int iLowH = 170;
    int iLowS = 150;
    int iLowV = 60;

    int iHighH = 179;
    int iHighS = 255;
    int iHighV = 255;

    // create trackbars in control window
    cvCreateTrackbar("LowH", windowName, &iLowH, 180);
    cvCreateTrackbar("HighH", windowName, &iHighH, 180);

    cvCreateTrackbar("LowS", windowName, &iLowS, 255);
    cvCreateTrackbar("HighS", windowName, &iHighS, 255);

    cvCreateTrackbar("LowV", windowName, &iLowV, 255);
    cvCreateTrackbar("HighV", windowName, &iHighV, 255);

    int iLastX = -1;
    int iLastY = -1;

    //Capture a temporary image from the camera
    Mat imgTmp;
    capture.read(imgTmp);

    //Create a black image with the size as the camera output
    Mat imgLines = Mat::zeros(imgTmp.size(), CV_8UC3);;

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

        // flip image to act as a mirror, you can use in-place processing.
        flip(imgOriginal, imgOriginal, 1);

        // convert the captured images from bgr to hsv
        cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV);

        // Threshold the image
        inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThreshold);

        // morphological opening remove small objects from the foreground
        erode(imgThreshold, imgThreshold, getStructuringElement(MORPH_RECT, Size(5, 5)));
        dilate(imgThreshold, imgThreshold, getStructuringElement(MORPH_RECT, Size(5, 5)));

        // morphological closing fill small holes in the foreground
        dilate(imgThreshold, imgThreshold, getStructuringElement(MORPH_RECT, Size(5, 5)));
        erode(imgThreshold, imgThreshold, getStructuringElement(MORPH_RECT, Size(5, 5)));

        Moments oMoments = moments(imgThreshold);

        double dM01 = oMoments.m01;
        double dM10 = oMoments.m10;
        double dArea = oMoments.m00;

        if (dArea > 10000)
        {
            // calculate the position
            int posX = static_cast<int>(dM10 / dArea);
            int posY = static_cast<int>(dM01 / dArea);

            if (iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0)
            {
                // draw a line
                line(imgLines, Point(posX, posY), Point(iLastX, iLastY), Scalar(0, 0, 255), 3);
                cout << "(" << posX << ", " << posY << ")" << " Last(" << iLastX << ", " << iLastY << ")" << endl;
            }

            iLastX = posX;
            iLastY = posY;
        }

        // show the threshold and the original
        imshow("Threshold", imgThreshold);

        imgOriginal = imgOriginal + imgLines;
        imshow("Original", imgOriginal);

        if (waitKey(30) == 27)
        {
            break;
        }
    }

    return 0;
}