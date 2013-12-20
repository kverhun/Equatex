#ifndef IIMAGEIMPORTVIEW_H
#define IIMAGEIMPORTVIEW_H

#include <QString>

class IImageImportView
{
public:
    virtual void execute() = 0;
    virtual void shutdown() = 0;
    /*
     *  SIGNALS
     */
    virtual void on_import_clicked() = 0;
    virtual void on_cancel_clicked() = 0;
    virtual void on_browse_clicked() = 0;



    /*
     *  Getter functions
     *
     *
     */
    virtual QString getImageType() = 0;
    virtual QString getSymbolDesc() = 0;
    virtual QString getImagePath() = 0;

    /*
     *  Setter functions
     *
     */
    virtual void setImageTypes(QStringList types) = 0;
    virtual void setSymbols (QStringList symbols) = 0;
    virtual void setImagePath(QString path) = 0;
};

#endif // IIMAGEIMPORTVIEW_H
