#-------------------------------------------------
#
# Project created by QtCreator 2013-12-18T19:28:14
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += xml


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Equatex
TEMPLATE = app

SOURCES += main.cpp \
    src/gui/view/mainwindow.cpp \
    src/gui/view/dbdialog.cpp \
    src/gui/view/imageimportdialog.cpp \
    src/gui/presenter/presenter.cpp \
    src/model/model.cpp \
    src/model/Database/dbconnection.cpp \
    src/lib/files/file_utils.cpp \
    src/lib/image/image_utils.cpp \
    src/lib/image/qt_image_utils.cpp \
    src/lib/parse/pars_utils.cpp \
    src/lib/expression/Symbol.cpp \
    src/lib/expression/Fraction.cpp \
    src/lib/expression/Expression.cpp

HEADERS  += src/gui/view/mainwindow.h \
    src/gui/view/dbdialog.h \
    src/gui/view/imageimportdialog.h \
    src/gui/interfaces/IDBView.h \
    src/gui/presenter/presenter.h \
    src/gui/interfaces/IView.h \
    src/model/model.h \
    src/model/Database/dbconnection.h \
    src/model/Database/dbqueries.h \
    src/gui/interfaces/IImageImportView.h \
    src/lib/files/file_utils.h \
    src/lib/image/image_utils.h \
    src/lib/image/qt_image_utils.h \
    src/lib/parse/parse_utils.h \
    src/lib/expression/Symbol.h \
    src/lib/expression/Item.h \
    src/lib/expression/Fraction.h \
    src/lib/expression/Expression.h

FORMS    += src/gui/view/mainwindow.ui \
    src/gui/view/dbdialog.ui \
    src/gui/view/imageimportdialog.ui

QMAKE_CXXFLAGS += -std=c++11
