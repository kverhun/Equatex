#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->initialize();
}

void MainWindow::initialize()
{
    // resizing parameters
    ui->gridLayout->setColumnStretch(0,1);
    ui->gridLayout->setColumnStretch(1,0);
    ui->gridLayout->setColumnMinimumWidth(1,150);

    this->setWindowTitle("Equatex project");
    connect(this->ui->actionDatabase_connection, SIGNAL(triggered()), this, SLOT(on_menuTools_DBConnection_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openLatex_button_clicked()
{
    emit(on_latexOpen_clicked());
}

void MainWindow::on_menuTools_DBConnection_clicked()
{
    emit(on_menuTools_DBConnection());
}

/*
 QString getLatexText();

    void setXmlText(QString strxml);
*/

QString MainWindow::getLatexText()
{
    return ui->latex_edit->toPlainText();
}

void MainWindow::setXmlText(QString strxml)
{
    ui->xml_edit->setText(strxml);
}


void MainWindow::on_checkLatex_button_clicked()
{
    emit(on_latexCheck_clicked());
}

void MainWindow::on_saveXml_button_clicked()
{
    emit(on_xmlSave_clicked());
}

void MainWindow::on_editor_tab_currentChanged(int index)
{
    if (index == 1) emit(on_xmlTabSelected());
}

void MainWindow::setStyleItems(QStringList items)
{
    ui->imageStyle_cbox->clear();
    ui->imageStyle_cbox->addItems(items);
}
