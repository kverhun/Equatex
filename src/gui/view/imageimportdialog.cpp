#include "imageimportdialog.h"
#include "ui_imageimportdialog.h"

ImageImportDialog::ImageImportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImageImportDialog)
{
    ui->setupUi(this);
}

ImageImportDialog::~ImageImportDialog()
{
    delete ui;
}

void ImageImportDialog::initialize()
{
    this->setWindowTitle("Import image to database");
}
