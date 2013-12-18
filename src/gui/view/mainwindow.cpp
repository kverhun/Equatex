#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->gridLayout->setColumnStretch(0,1);
    ui->gridLayout->setColumnStretch(1,0);

    ui->gridLayout->setColumnMinimumWidth(1,150);

}

MainWindow::~MainWindow()
{
    delete ui;
}
