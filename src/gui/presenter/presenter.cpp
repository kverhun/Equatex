#include "presenter.h"

#include "src/gui/interfaces/IView.h"
#include "src/gui/view/dbdialog.h"

#include <QMessageBox>

Presenter::Presenter(IView *view)
{
    this->view_main = view;
    this->view_db = new DBDialog();

    //this->model = Model();

    this->initialize();
}

void Presenter::initialize()
{
    QObject* qview = dynamic_cast<QObject*>(this->view_main);
    connect(qview, SIGNAL(on_menuTools_DBConnection()), this, SLOT(onDBConnection()));

    connect(qview, SIGNAL(on_latexCheck_clicked()), this, SLOT(on_latexCheckAsked()));
    connect(qview, SIGNAL(on_xmlTabSelected()), this, SLOT(on_xmlPreviewAsked()));
    connect(qview, SIGNAL(on_xmlSave_clicked()), this, SLOT(on_xmlSaveAsked()));
    connect(qview, SIGNAL(on_latexOpen_clicked()), this, SLOT(on_latexOpenAsked()));
}

void Presenter::onDBConnection()
{
    QMessageBox mb;
    mb.exec();
}

void Presenter::on_xmlPreviewAsked()
{
    QMessageBox mb;
    mb.setText("XML preview asked");
    mb.exec();
}

void Presenter::on_latexCheckAsked()
{
    QMessageBox mb;
    mb.setText("Latex checking asked");
    mb.exec();
}

void Presenter::on_latexOpenAsked()
{
    QMessageBox mb;
    mb.setText("Latex open asked");
    mb.exec();
}

void Presenter::on_xmlSaveAsked()
{
    QMessageBox mb;
    mb.setText("XML save asked");
    mb.exec();
}
