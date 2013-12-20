#include "presenter.h"

#include "src/gui/interfaces/IView.h"
#include "src/gui/view/dbdialog.h"
#include "src/gui/interfaces/IImageImportView.h"
#include "src/gui/view/imageimportdialog.h"

#include <QMessageBox>
#include <QFileDialog>

Presenter::Presenter(IView *view)
{
    this->view_main = view;
    this->view_db = new DBDialog();
    this->view_import = new ImageImportDialog();
    //this->model = Model();

    this->initialize();
    this->initialize_view();
}

void Presenter::initialize()
{

    /*
     *  MainWindow connecting
     */
    QObject* qview = dynamic_cast<QObject*>(this->view_main);

    connect(qview, SIGNAL(on_menuTools_DBConnection()), this, SLOT(onDBConnection()));
    connect(qview, SIGNAL(on_menuTools_ImportImage()), this, SLOT(onImageImport()));

    connect(qview, SIGNAL(on_latexCheck_clicked()), this, SLOT(on_latexCheckAsked()));
    connect(qview, SIGNAL(on_xmlTabSelected()), this, SLOT(on_xmlPreviewAsked()));
    connect(qview, SIGNAL(on_xmlSave_clicked()), this, SLOT(on_xmlSaveAsked()));
    connect(qview, SIGNAL(on_latexOpen_clicked()), this, SLOT(on_latexOpenAsked()));

    /*
     *  END MainWindow connectiong
     */

    /*
     *  Import connecting
     */
    QObject* qimport = dynamic_cast<QObject*>(this->view_import);
    connect(qimport, SIGNAL(on_import_clicked()), this, SLOT(on_import_import()));
    connect(qimport, SIGNAL(on_cancel_clicked()), this, SLOT(on_import_cancel()));
    connect(qimport, SIGNAL(on_browse_clicked()), this, SLOT(on_import_browse()));
    /*
     *  END Import connecting
     */
}

void Presenter::initialize_view()
{
    view_main->setStyleItems(model.GetStyles());

}

void Presenter::onDBConnection()
{
    QMessageBox mb;
    mb.exec();
}

void Presenter::onImageImport()
{
    view_import->execute();
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

void Presenter::on_import_browse()
{
    QString fname = QFileDialog::getOpenFileName();
    view_import->setImagePath(fname);
}

void Presenter::on_import_cancel()
{
    view_import->shutdown();
}

void Presenter::on_import_import()
{
    view_import->shutdown();
}
