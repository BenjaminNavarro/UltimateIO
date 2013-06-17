#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "usbdevice.h"
#include "threadconnect.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    USBDevice device;
    threadConnect connectTh;

private slots:
    void LEDStatusChanged(bool status);

};

#endif // MAINWINDOW_H
