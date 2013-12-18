#-------------------------------------------------
#
# Project created by QtCreator 2013-12-18T19:28:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Equatex
TEMPLATE = app

SOURCES += main.cpp \
    src/gui/view/mainwindow.cpp \

HEADERS  += src/gui/view/mainwindow.h \

FORMS    += src/gui/view/mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11
