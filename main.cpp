#include <QtGui/QApplication>
#include "mainwindow.h"

#include <stdio.h>
#include <sys/types.h>

#include <libusb-1.0/libusb.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
