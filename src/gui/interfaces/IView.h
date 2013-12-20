#ifndef IVIEW_H
#define IVIEW_H

#include <QString>
#include <QImage>

class IView
{
public:
    /*
     *  SIGNALS
     */
    // menu -> tools -> Database connection
    virtual void on_menuTools_DBConnection() = 0;

    // menu -> tools -> Import image
    virtual void on_menuTools_ImportImage() = 0;

    // latex check clicked
    virtual void on_latexCheck_clicked() = 0;

    // latex open clicked
    virtual void on_latexOpen_clicked() = 0;

    // xml save clicked
    virtual void on_xmlSave_clicked() = 0;

    // xml tab selected
    virtual void on_xmlTabSelected() = 0;

    // image generate clicked
    virtual void on_imageGenerate_clicked() = 0;



    /*
     *  Getter functions
     *
     *
     */
    virtual QString getLatexText() = 0;

    /*
     *  Setter functions
     *
     */
    virtual void setXmlText(QString strxml) = 0;
    virtual void setStyleItems(QStringList items) = 0;
    virtual void setCurrentTab(int tab) = 0;
    virtual void setImage(QImage img) = 0;
};

#endif // IVIEW_H
