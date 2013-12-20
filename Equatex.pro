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
    src/model/Database/dbconnection.cpp

HEADERS  += src/gui/view/mainwindow.h \
    src/gui/view/dbdialog.h \
    src/gui/view/imageimportdialog.h \
    src/gui/interfaces/IDBView.h \
    src/gui/presenter/presenter.h \
    src/gui/interfaces/IView.h \
    src/model/model.h \
    src/model/Database/dbconnection.h \
    src/model/Database/dbqueries.h \
    src/gui/interfaces/IImageImportView.h

FORMS    += src/gui/view/mainwindow.ui \
    src/gui/view/dbdialog.ui \
    src/gui/view/imageimportdialog.ui

QMAKE_CXXFLAGS += -std=c++11
