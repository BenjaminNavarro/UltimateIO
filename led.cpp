#include "led.h"

LED::LED() {
    m_etatLED = false;
}

void LED::allumerLED() {
    m_etatLED = true;
    emit updateLEDStatus(m_etatLED);
}

void LED::eteindreLED() {
   m_etatLED = false;
   emit updateLEDStatus(m_etatLED);
}

bool LED::getEtatLED() {
    return m_etatLED;
}

void LED::LEDStatusChanged(bool state) {
    m_etatLED = state;
    emit updateLEDStatus(m_etatLED);
}
