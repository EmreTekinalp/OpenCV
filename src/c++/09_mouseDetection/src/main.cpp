#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::vector;

using namespace cv;


void Callback(int event, int x, int y, int flags, void* userdata)
{
    if (event == EVENT_LBUTTONDOWN)
    {
        cout << "left mouse button down! (" << x << ", " << y << ")" << endl;
    }
    else if (event == EVENT_RBUTTONDOWN)
    {
        cout << "right mouse button down! (" << x << ", " << y << ")" << endl;
    }
    else if (event == EVENT_MBUTTONDOWN)
    {
        cout << "middle mouse button down! (" << x << ", " << y << ")" << endl;
    }
    else if (event == EVENT_MOUSEMOVE && flags == EVENT_FLAG_ALTKEY)
    {
        cout << "mouse movement and alt key pressed! (" << x << ", " << y << ")" << endl;
    }
    else if (flags == EVENT_FLAG_CTRLKEY + EVENT_FLAG_LBUTTON)
    {
        cout << "ctrl key pressed and left mouse button down! (" << x << ", " << y << ")" << endl;
    }
    else if (flags == EVENT_FLAG_SHIFTKEY + EVENT_FLAG_RBUTTON)
    {
        cout << "shift key pressed and right mouse button down! (" << x << ", " << y << ")" << endl;
    }
}


int main(int argc, const char** argv)
{
    //allocate the projectPath and dataPath to store the image
    string projectPath = string(argv[0]).substr(0, string(argv[0]).find("build"));
    string resourcePath = projectPath + "resources/jpg";

    // get picture
    Mat img = imread(resourcePath + "/highFive.jpg");

    cout << resourcePath + "/highFive.jpg" << endl;
    // check whether the image is loaded or not
    if (img.empty())
    {
        cout << "Error : No image found!!" << endl;
        return -1;
    }

    namedWindow("MyWindow", CV_WINDOW_AUTOSIZE);

    setMouseCallback("MyWindow", Callback, NULL);
    imshow("MyWindow", img);

    waitKey(0);

    return 0;
}