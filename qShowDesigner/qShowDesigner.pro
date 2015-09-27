#-------------------------------------------------
#
# Project created by QtCreator 2015-08-16T19:16:29
#
#-------------------------------------------------

QT  += core gui
QT  += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qShowDesigner
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    serialconfig.cpp \
    showdesigner.cpp \
    qlineeditlabel.cpp \
    fixture.cpp

HEADERS  += mainwindow.h \
    serialconfig.h \
    showdesigner.h \
    qlineeditlabel.h \
    fixture.h

FORMS    += mainwindow.ui \
    serialconfig.ui

LIBS += -L/usr/lib/fglrx
