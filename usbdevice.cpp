#include "usbdevice.h"

USBDevice::USBDevice() {
    dev = 0;
    name = "";
    connected = false;
}

bool USBDevice::getStatus() {
    return connected;
}

libusb_device_handle* USBDevice::getHandle() {
    return dev;
}

void USBDevice::deviceChanged(libusb_device_handle *device) {
    dev = device;
    if(dev != NULL) {
        connected = true;
        qDebug() << "\nDevice connected \n";
    }
    else {
        connected = false;
        qDebug() << "\nDevice disconnected \n";
    }
}
