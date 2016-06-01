#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::string;

using namespace cv;

int main(int argc, const char** argv)
{
    //capture the camera by using the index
    VideoCapture capture(0);

    //check whether the image is loaded or not
    if (!capture.isOpened())
    {
        cout << "Error : Video cannot be loaded..!!" << endl;
        //system("pause"); //wait for a key press
        return -1;
    }

    // get the frames per second of the video (5 == CV_CAP_PROP_FPS)
    double fps = capture.get(CV_CAP_PROP_FPS);
    double dWidth = capture.get(CV_CAP_PROP_FRAME_WIDTH);
    double dHeight = capture.get(CV_CAP_PROP_FRAME_HEIGHT);

    cout << fps << ", " << dWidth << ", " << dHeight << endl;

    //create a window with the name "MyWindow"
    namedWindow("MyWindow", CV_WINDOW_AUTOSIZE);

    while (true)
    {
        // create Mat object to store every single frame from capture
        Mat frame;

        // read a new frame of the video and check status
        bool onSuccess = capture.read(frame);

        if (!onSuccess)
        {
            cout << "Cannot read frame from video file.!" << endl;
            break;
        }

        // show the frame in the window
        imshow("MyWindow", frame);

        // give the user ability to escape (27 == esc)
        if (waitKey(32) == 27)
        {
            cout << "esc key pressed, exiting video." << endl;
            break;
        }
    }

    if (waitKey(0))
    {
        destroyWindow;
    }
    return 0;
}