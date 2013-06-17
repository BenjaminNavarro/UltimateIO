#ifndef THREADCONNECT_H
#define THREADCONNECT_H

#include <QThread>
#include <QDebug>
#include <libusb-1.0/libusb.h>

#define IN_ENDPOINT     0x81
#define OUT_ENDPOINT    0x03

class threadConnect : public QThread
{
    Q_OBJECT
public:
    explicit threadConnect();
    void stop();
    void run();
    bool getRunningStatus(void);

private:
    void checkCommunication();
    void disconnection(QString error);

    bool isRunning,isConnected;
    libusb_device_handle *dev;

signals:
    void updateDevice(libusb_device_handle *device);
    void updateLEDStatus(bool status);


};

#endif // THREADCONNECT_H
