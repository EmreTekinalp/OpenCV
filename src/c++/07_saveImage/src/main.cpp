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

    // create image
    Mat img(650, 600, CV_16UC3, Scalar(0, 5000, 5000));

    // check whether the image is loaded or not
    if (img.empty())
    {
        cout << "Error : Image cannot be loaded..!!" << endl;
        // system("pause"); //wait for a key press
        return -1;
    }

    // create vector to store compression parameters (COMPRESS TECHNIQUE, LEVEL OF QUALITY)
    vector<int> compression_parameters;
    compression_parameters.push_back(CV_IMWRITE_JPEG_QUALITY);
    compression_parameters.push_back(98);

    bool bSuccess = imwrite(dataPath + "/myImage.jpg", img, compression_parameters);
    if (!bSuccess)
    {
        cout << "Error: Failed to save image.!" << endl;
        return -1;
    }

    //create a window with the name "MyWindow"
    namedWindow("MyWindow", CV_WINDOW_AUTOSIZE);
    imshow("MyWindow", img);

    waitKey(0);
    destroyWindow("MyWindow");

    return 0;
}