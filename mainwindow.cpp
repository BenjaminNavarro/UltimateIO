#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int r;

    r = libusb_init(NULL);

    if (r >= 0) {
        connect(&connectTh,SIGNAL(updateDevice(libusb_device_handle*)),&device,SLOT(deviceChanged(libusb_device_handle*)));
        connect(&connectTh,SIGNAL(updateLEDStatus(bool)),this,SLOT(LEDStatusChanged(bool)));

        connectTh.start();
    }
    ui->img_led->setPixmap(QPixmap(":/led_circle_red.png"));
}

MainWindow::~MainWindow()
{
    connectTh.stop();

    libusb_close(device.getHandle());

    libusb_exit(NULL);

    delete ui;
}

void MainWindow::LEDStatusChanged(bool status) {
    if(status) {
       ui->img_led->setPixmap(QPixmap(":/led_circle_green.png"));
    }
    else {
       ui->img_led->setPixmap(QPixmap(":/led_circle_red.png"));
    }
}
