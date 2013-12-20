#ifndef PRESENTER_H
#define PRESENTER_H

#include <QObject>

#include "src/gui/interfaces/IView.h"
#include "src/gui/interfaces/IDBView.h"
#include "src/gui/interfaces/IImageImportView.h"

#include "src/model/model.h"

class Presenter : public QObject
{
    Q_OBJECT
public:
    Presenter(IView* view);


private:
    IView* view_main;
    IDView* view_db;
    IImageImportView* view_import;

    Model model;

    // initialize signal/slots
    void initialize();

    // set view data
    void initialize_view();



private slots:
    // for connection modal window exec
    void onDBConnection();

    // for image import
    void onImageImport();

    // for xml-file generating
    void on_xmlPreviewAsked();

    // for latex-file checking
    void on_latexCheckAsked();

    // for latex-file opening
    void on_latexOpenAsked();

    // for xml-file saving
    void on_xmlSaveAsked();

    // for image generation
    void on_imageGenerateAsked();

    /*
     *  Image import dialog
     */
    // for browse
    void on_import_browse();

    // for import
    void on_import_import();

    // for cancel
    void on_import_cancel();
    /*
     *  END Image import dialog
     */
};

#endif // PRESENTER_H
