#include "dbdialog.h"
#include "ui_dbdialog.h"

DBDialog::DBDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DBDialog)
{
    ui->setupUi(this);
}

DBDialog::~DBDialog()
{
    delete ui;
}

QString DBDialog::getDBName()
{
    return this->ui->dbName_edit->text();
}

QString DBDialog::getDBUser()
{
    return this->ui->dbUser_edit->text();
}

QString DBDialog::getDBPassword()
{
    return this->ui->dbPassword_edit->text();
}

void DBDialog::outMessage(QString msg)
{
    this->ui->msg_label->setText(msg);
}

void DBDialog::initialize()
{
    this->setWindowTitle("Configure ODBC connection parameters");
}
