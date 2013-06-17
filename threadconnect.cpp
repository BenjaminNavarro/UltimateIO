#include "threadconnect.h"

threadConnect::threadConnect() {
    isRunning = false;
    isConnected = false;
}

void threadConnect::run() {
    isRunning = true;

    uchar led_on[2]={1,0xF0};
    uchar led_off[2]={1,0xFF};
    uchar ack;
    uchar* buffer;
    int res;
    int actual_length;
    bool state = false;


    while(isRunning) {
        while(!isConnected) {
            dev = libusb_open_device_with_vid_pid(NULL,0xFFEE,0xAABB);

            if(dev!=NULL) {
                isConnected = true;
                updateDevice(dev);
                updateLEDStatus(isConnected);

                if (libusb_kernel_driver_active(dev, 0)) {
                    disconnection("The kernel driver is active");
                    res = libusb_detach_kernel_driver(dev, 0);
                    if ( res != 0 ) {
                        disconnection(QString("failed to detach from kernel driver. Error Number : %1").arg(res));
                        continue;
                    }
                }

                int interface = 1;

                res = libusb_claim_interface(dev, interface);

                if (res < 0) {
                    disconnection(QString("can't claim interface %1, error %2 (%3)").arg(interface).arg(libusb_error_name(res)).arg(res));
                    continue;
                }
                else
                    isConnected = true;
            }
            msleep(500);
        }
        if(isConnected) {
            if(state)
                buffer = led_on;
            else
                buffer = led_off;

            state ^= 1;

            res = libusb_interrupt_transfer(dev, OUT_ENDPOINT, buffer, 2, &actual_length, 1000);

            if (res < 0) {
                disconnection(QString("interrupt transfer (out) error %1 (%2)").arg(libusb_error_name(res)).arg(res));
                continue;
            }

            res = libusb_interrupt_transfer(dev, IN_ENDPOINT, &ack, 1, &actual_length, 1000);

            if (res < 0) {
                disconnection(QString("interrupt transfer (in) error %1 (%2)").arg(libusb_error_name(res)).arg(res));
                continue;
            }

            if(ack != 0x55)
                qDebug() << "ACK NOT OK";

        }

        msleep(100);
    }
}

void threadConnect::stop() {
    isRunning = false;
    terminate();
    wait();
}

bool threadConnect::getRunningStatus(void) {
    return isRunning;
}

void threadConnect::checkCommunication() {

}

void threadConnect::disconnection(QString error) {
    qDebug() << error;

    if(dev != NULL) {
        libusb_release_interface(dev, 0x01);
        libusb_close(dev);
        dev = NULL;
        updateDevice(NULL);
    }

    updateLEDStatus(false);
    isConnected = false;
}
