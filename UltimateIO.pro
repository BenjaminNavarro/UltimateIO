#-------------------------------------------------
#
# Project created by QtCreator 2011-11-07T18:11:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UltimateIO
TEMPLATE = app


SOURCES += main.cpp\
	mainwindow.cpp \
    threadconnect.cpp \
    usbdevice.cpp \
    led.cpp

HEADERS  += mainwindow.h \
    threadconnect.h \
    usbdevice.h \
    led.h

FORMS    += mainwindow.ui

LIBS += -L/usr/local/lib -lusb-1.0

RESOURCES += \
    images.qrc












