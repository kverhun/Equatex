#ifndef IMAGEIMPORTDIALOG_H
#define IMAGEIMPORTDIALOG_H

#include "src/gui/interfaces/IImageImportView.h"

#include <QDialog>

namespace Ui {
class ImageImportDialog;
}

class ImageImportDialog : public QDialog, public IImageImportView
{
    Q_OBJECT

public:
    explicit ImageImportDialog(QWidget *parent = 0);
    ~ImageImportDialog();
    void execute();
    void shutdown();
    /*
     *  Getter functions
     *
     *
     */
    QString getImageType();
    QString getSymbolDesc();
    QString getImagePath();

    /*
     *  Setter functions
     *
     */
    void setImageTypes(QStringList types);
    void setSymbols (QStringList symbols);
    void setImagePath(QString path);

signals:
    void on_browse_clicked();
    void on_cancel_clicked();
    void on_import_clicked();

private slots:
    void on_import_button_clicked();

    void on_cancel_button_clicked();

    void on_imageBrowse_button_clicked();

private:
    Ui::ImageImportDialog *ui;
    void initialize();
};

#endif // IMAGEIMPORTDIALOG_H
