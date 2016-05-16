#include "mainWindow.h"
#include "ui_helloQtOpenCV.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create the image widget
    HelloQtOpenCV* imageWidget = new HelloQtOpenCV();
    ui->imageLayout->addWidget(imageWidget);

    // Load an image
    //allocate the projectPath and resourcePath
    string projectPath = "E:/GitHub/OpenCV/src/c++/03_helloQtOpenCV/";
    string resourcesPath = projectPath + "/resources";
    string highFiveImage = resourcesPath + "/jpg/highFive.jpg";

    cv::Mat image = cv::imread(highFiveImage, true);
    imageWidget->showImage(image);
}

MainWindow::~MainWindow()
{
    delete ui;
}
