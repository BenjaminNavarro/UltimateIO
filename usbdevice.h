#ifndef USBDEVICE_H
#define USBDEVICE_H

#include <QObject>
#include <QDebug>
#include <iostream>
#include <QString>
#include <libusb-1.0/libusb.h>

using namespace std;

class USBDevice : public QObject
{
    Q_OBJECT
public:
    explicit USBDevice();
    bool getStatus();
    libusb_device_handle* getHandle();

private:
    libusb_device_handle *dev;
    QString name;
    bool connected;

signals:

public slots:
    void deviceChanged(libusb_device_handle *device);

};

#endif // USBDEVICE_H
