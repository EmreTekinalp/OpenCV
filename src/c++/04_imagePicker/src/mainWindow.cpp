#include "mainWindow.h"
#include "ui_imagePicker.h"
using namespace cv;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create the image widget
    ImagePicker* imageWidget = new ImagePicker();
    ImagePicker* imageWidget2 = new ImagePicker();
    ui->imageLayout->addWidget(imageWidget);
    ui->imageLayout->addWidget(imageWidget2);

    // Load an image
    //allocate the projectPath and resourcePath
    string projectPath = "E:/GitHub/OpenCV/src/c++/03_helloQtOpenCV/";
    string resourcesPath = projectPath + "/resources";
    string highFiveImage = resourcesPath + "/jpg/highFive.jpg";

    // Take the original picture twice and convert one to a gray scale version
    cv::Mat image = cv::imread(highFiveImage, true);
    cv::Mat gray_image;
    cvtColor(image, gray_image, COLOR_BGR2GRAY);
    imwrite(resourcesPath + "/jpg/grayHighFive.jpg", gray_image);

    imageWidget->showImage(image);
    imageWidget2->showImage(gray_image);
}

MainWindow::~MainWindow()
{
    delete ui;
}
