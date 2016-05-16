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
    string highFiveImage = resourcesPath + "/jpg/highFive.jpg";

    //read the image data in the file "highFive.jpg" and store it in 'img'
    Mat img = imread(highFiveImage, CV_LOAD_IMAGE_UNCHANGED);

    //check whether the image is loaded or not
    if (img.empty())
    {
        cout << "Error : Image cannot be loaded..!!" << endl;
        //system("pause"); //wait for a key press
        return -1;
    }

    //create a window with the name "MyWindow"
    namedWindow("MyWindow", CV_WINDOW_AUTOSIZE);
    //display the image which is stored in the 'img' in the "MyWindow" window
    imshow("MyWindow", img);

    //wait infinite time for a keypress
    waitKey(0);
    //destroy the window with the name, "MyWindow"
    destroyWindow("MyWindow");

    return 0;
}