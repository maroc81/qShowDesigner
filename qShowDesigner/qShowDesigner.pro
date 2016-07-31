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
    ShowDesigner.cpp \
    SerialConfig.cpp \
    QLineEditLabel.cpp \
    QChannelSlider.cpp \
    Fixture.cpp \
    Fixtures.cpp \
    MainWindow.cpp

HEADERS  += \
    ShowDesigner.h \
    ShowDesignerTest.h \
    SerialConfig.h \
    QLineEditLabel.h \
    QChannelSlider.h \
    Fixture.h \
    Fixtures.h \
    MainWindow.h

FORMS    += \
    Fixtures.ui \
    MainWindow.ui \
    SerialConfig.ui

LIBS += -L/usr/lib/fglrx
