#pragma once

#include <QtWidgets\qmainwindow.h>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};