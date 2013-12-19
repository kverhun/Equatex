#ifndef IMAGEIMPORTDIALOG_H
#define IMAGEIMPORTDIALOG_H

#include <QDialog>

namespace Ui {
class ImageImportDialog;
}

class ImageImportDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ImageImportDialog(QWidget *parent = 0);
    ~ImageImportDialog();

private:
    Ui::ImageImportDialog *ui;
    void initialize();
};

#endif // IMAGEIMPORTDIALOG_H
