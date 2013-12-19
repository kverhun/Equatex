#include "src/gui/view/mainwindow.h"
#include <QApplication>

#include "src/gui/presenter/presenter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Presenter presenter(&w);
    Q_UNUSED(presenter);

    w.show();

    return a.exec();
}
