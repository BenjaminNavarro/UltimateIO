#ifndef LED_H
#define LED_H

#include <QObject>

class LED : public QObject
{
    Q_OBJECT
public:
    explicit LED();
    void allumerLED();
    void eteindreLED();
    bool getEtatLED();

private :
    bool m_etatLED;

signals :
    void updateLEDStatus(bool state);

public slots:
    void LEDStatusChanged(bool state);

};

#endif // LED_H
