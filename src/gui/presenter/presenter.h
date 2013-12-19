#ifndef PRESENTER_H
#define PRESENTER_H

#include <QObject>

#include "src/gui/interfaces/IView.h"
#include "src/gui/interfaces/IDBView.h"

#include "src/model/model.h"

class Presenter : public QObject
{
    Q_OBJECT
public:
    Presenter(IView* view);


private:
    IView* view_main;
    IDView* view_db;

    Model model;
    // initialize signal/slots
    void initialize();

private slots:
    // for connection modal window exec
    void onDBConnection();

    // for xml-file generating
    void on_xmlPreviewAsked();

    // for latex-file checking
    void on_latexCheckAsked();

    // for latex-file opening
    void on_latexOpenAsked();

    // for xml-file saving
    void on_xmlSaveAsked();

};

#endif // PRESENTER_H
