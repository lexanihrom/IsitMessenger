#-------------------------------------------------
#
# Project created by QtCreator 2016-04-04T12:44:06
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IsitMessenger
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    ServerDiscovery.cpp

HEADERS  += MainWindow.hpp \
    ServerDiscovery.hpp

FORMS    += MainWindow.ui
