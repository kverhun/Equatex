#ifndef DBDIALOG_H
#define DBDIALOG_H

#include <QDialog>

#include "src/gui/interfaces/IDBView.h"

namespace Ui {
class DBDialog;
}

class DBDialog : public QDialog, public IDView
{
    Q_OBJECT

public:
    explicit DBDialog(QWidget *parent = 0);
    ~DBDialog();

    QString getDBName();
    QString getDBUser();
    QString getDBPassword();

    void outMessage(QString msg);

signals:
    void onConnectClick();
    void onTestClick();
    void onCancelClick();

private:
    Ui::DBDialog *ui;
    void initialize();
};

#endif // DBDIALOG_H
