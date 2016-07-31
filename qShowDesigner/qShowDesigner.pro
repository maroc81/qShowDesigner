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
    MainWindow.cpp \
    FixturesModel.cpp \
    FixturesWindow.cpp

HEADERS  += \
    ShowDesigner.h \
    ShowDesignerTest.h \
    SerialConfig.h \
    QLineEditLabel.h \
    QChannelSlider.h \
    Fixture.h \
    MainWindow.h \
    FixturesModel.h \
    FixturesWindow.h

FORMS    += \
    MainWindow.ui \
    SerialConfig.ui \
    FixturesWindow.ui

LIBS += -L/usr/lib/fglrx
LIBS += -L/usr/lib/nvidia-352/
