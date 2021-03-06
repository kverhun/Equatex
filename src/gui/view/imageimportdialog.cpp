#include "imageimportdialog.h"
#include "ui_imageimportdialog.h"

#include <QMessageBox>

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

void ImageImportDialog::execute()
{
    this->exec();
}

void ImageImportDialog::shutdown()
{
    this->close();
}

/*
 *  Getter functions
 *
 *
 */

QString ImageImportDialog::getImageType()
{
    return this->ui->imageClass_cbox->currentText();
}

QString ImageImportDialog::getSymbolDesc()
{
    return this->ui->symbol_cbox->currentText();
}

QString ImageImportDialog::getImagePath()
{
    return this->ui->imagePath_edit->text();
}

QString ImageImportDialog::getNewTypeName()
{
    return this->ui->className_edit->text();
}

QString ImageImportDialog::getNewTypeDesc()
{
    return this->ui->classDesc_edit->text();
}


/*
 *  Setter functions
 *
 */
void ImageImportDialog::setImageTypes(QStringList types)
{
    this->ui->imageClass_cbox->clear();
    this->ui->imageClass_cbox->addItems(types);
}

void ImageImportDialog::setSymbols (QStringList symbols)
{
    this->ui->symbol_cbox->clear();
    this->ui->symbol_cbox->addItems(symbols);
}

void ImageImportDialog::setImagePath(QString path)
{
    this->ui->imagePath_edit->setText(path);
}

void ImageImportDialog::on_import_button_clicked()
{
    emit(on_import_clicked());
}

void ImageImportDialog::on_cancel_button_clicked()
{
    emit(on_cancel_clicked());
}

void ImageImportDialog::on_imageBrowse_button_clicked()
{
    emit(on_browse_clicked());
}

void ImageImportDialog::on_addClass_button_clicked()
{
    if (this->ui->className_edit->text().isEmpty())
    {
        QMessageBox mb;
        mb.setText("Type name can not be empty!");
        mb.exec();
    }
    else
        emit(on_add_clicked());
}
