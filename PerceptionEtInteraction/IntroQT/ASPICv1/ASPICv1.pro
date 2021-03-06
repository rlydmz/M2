#-------------------------------------------------
#
# Project created by QtCreator 2018-09-11T15:17:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ASPICv1
TEMPLATE = app

INCLUDEPATH += local/include/opencv
LIBS += -L/net/cremi/ranqueti/local/lib/ -lopencv_core -lopencv_imgcodecs -lopencv_highgui

SOURCES += main.cpp\
        mainwindow.cpp \
    aboutwindow.cpp

HEADERS  += mainwindow.h \
    aboutwindow.h

FORMS    += mainwindow.ui \
    aboutwindow.ui

RESOURCES += \
    mainressource.qrc
