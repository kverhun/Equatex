#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "src/gui/interfaces/IView.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public IView
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    /*
     *  Getter functions
     */
    QString getLatexText();
    QString getSelectedType();
    QString getImageWidth();
    QString getImageHeight();


    /*
     *  Setter functions
     */
    void setXmlText(QString strxml);
    void setStyleItems(QStringList items);


    void setCurrentTab(int tab);
    void setImage(QImage img);
private slots:
    void on_openLatex_button_clicked();
    void on_menuTools_DBConnection_clicked();
    void on_menuTools_ImportImage_clicked();

    void on_checkLatex_button_clicked();
    void on_saveXml_button_clicked();

    void on_editor_tab_currentChanged(int index);

    void on_regenImage_button_clicked();

    void on_imageGen_button_clicked();

private:
    Ui::MainWindow *ui;

    // sets initial layout parameters
    void initialize();

signals:
    void on_menuTools_DBConnection();
    void on_menuTools_ImportImage();
    void on_latexCheck_clicked();
    void on_xmlSave_clicked();
    void on_xmlTabSelected();
    void on_latexOpen_clicked();
    void on_imageGenerate_clicked();

};

#endif // MAINWINDOW_H
