#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::string;

using namespace cv;

int main(int argc, const char** argv)
{
    //allocate the projectPath and resourcePath
    string projectPath = string(argv[0]).substr(0, string(argv[0]).find("build"));
    string resourcesPath = projectPath + "/resources";
    string videoPath = resourcesPath + "/mp4/rollercoaster.mp4";

    //read the image data in the file "highFive.jpg" and store it in 'img'
    VideoCapture capture(videoPath);

    //check whether the image is loaded or not
    if (!capture.isOpened())
    {
        cout << "Error : Video cannot be loaded..!!" << endl;
        //system("pause"); //wait for a key press
        return -1;
    }

    // get the frames per second of the video (5 == CV_CAP_PROP_FPS)
    double fps = capture.get(CV_CAP_PROP_FPS);

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

    return 0;
}