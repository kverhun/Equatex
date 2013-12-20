#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

#include <QImage>

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
    connect(this->ui->actionImport_image, SIGNAL(triggered()), this, SLOT(on_menuTools_ImportImage_clicked()));

    ui->imageHeigth_edit->setText("240");
    ui->imageWidth_edit->setText("320");

    QStringList colorList = QStringList();
    colorList.append("black");
    colorList.append("white");
    colorList.append("blue");
    colorList.append("red");
    colorList.append("green");

    ui->background_cbox->clear();
    ui->background_cbox->addItems(colorList);
    ui->background_cbox->setCurrentText("white");
    ui->fontColor_cBox->clear();
    ui->fontColor_cBox->addItems(colorList);
    ui->fontColor_cBox->setCurrentText("Black");
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

void MainWindow::on_menuTools_ImportImage_clicked()
{
    emit(on_menuTools_ImportImage());
}


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

void MainWindow::setCurrentTab(int tab)
{
    ui->editor_tab->setCurrentIndex(tab);
}

void MainWindow::on_regenImage_button_clicked()
{
    QImage img("D:\\projects\\C++\\QT\\images\\qtimage\\imgs\\dig_0.jpg");
    img = img.scaled(1300,1000);

    ui->image_label->setPixmap(QPixmap::fromImage(img));


    //ui->image_label->show();
}

void MainWindow::setImage(QImage img)
{
    this->ui->image_label->setFixedSize(img.width(), img.height());
    this->ui->image_label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_imageGen_button_clicked()
{
    emit(on_imageGenerate_clicked());
}

QString MainWindow::getSelectedType()
{
    return ui->imageStyle_cbox->currentText();
}


QString MainWindow::getImageWidth()
{
    return ui->imageWidth_edit->text();
}

QString MainWindow::getImageHeight()
{
    return ui->imageHeigth_edit->text();
}

void MainWindow::on_fontColor_checkBox_clicked()
{
    if (ui->fontColor_checkBox->isChecked())
    {
        ui->fontColor_cBox->setEnabled(true);
    }
    else
    {
        ui->fontColor_cBox->setEnabled(false);
    }
}


bool MainWindow::getFontColorUse()
{
    return this->ui->fontColor_checkBox->isChecked();
}

QString MainWindow::getFontColor()
{
    return this->ui->fontColor_cBox->currentText();
}

QString MainWindow::getBackground()
{
    return this->ui->background_cbox->currentText();
}


