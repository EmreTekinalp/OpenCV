#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::vector;

using namespace cv;

int main(int argc, const char** argv)
{
    //allocate the projectPath and dataPath to store the image
    string projectPath = string(argv[0]).substr(0, string(argv[0]).find("build"));
    string dataPath = projectPath + "/data";

    // capture webcam
    VideoCapture capture(0);

    // check whether the image is loaded or not
    if (!capture.isOpened())
    {
        cout << "Error : Could not capture video!!" << endl;
        return -1;
    }

    namedWindow("MyVideoWindow", CV_WINDOW_AUTOSIZE);

    double dWidth = capture.get(CV_CAP_PROP_FRAME_WIDTH);
    double dHeight = capture.get(CV_CAP_PROP_FRAME_HEIGHT);

    Size frameSize(static_cast<int>(dWidth), static_cast<int>(dHeight));

    VideoWriter oVideoWriter(dataPath + "/MyVideo.mp4", CV_FOURCC('M', 'P', '4', 'V'), 24, frameSize, true);
    if (!oVideoWriter.isOpened())
    {
        cout << "Could not initialize video writer!" << endl;
        return -1;
    }

    while (true)
    {
        Mat frame;
        bool bSuccess = capture.read(frame);
        if (!bSuccess)
        {
            cout << "Could not read captured video frame!" << endl;
            break;
        }

        imshow("MyVideoWindow", frame);
        oVideoWriter.write(frame);

        if (waitKey(10) == 27)
        {
            break;
        }
    }

    return 0;
}