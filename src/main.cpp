#include "stm32f10x.h"
#include "hw_config.h"
#include "usb_lib.h"
#include "usb_desc.h"
#include "usb_pwr.h"
#include "systick.h"
#include "MyLib.h"

Pin LED(PB0);

extern void USB_SendData(uint8_t* buffer, uint8_t length);

void OUT_Callback(uint8_t* Rx, uint8_t length) {
	uint8_t ack = 0x55, nack = 0xAA;

	switch(Rx[0]) {

	case 1: // LED Command
		if(Rx[1] == LED_ON)
			LED.On();
		else if (Rx[1] == LED_OFF)
			LED.Off();

		USB_SendData(&ack, 1);
		break;

	default:
		USB_SendData(&nack, 1);
		break;
	}
}


int main(void) {

	Set_System();
	Set_USBClock();
	USB_Interrupts_Config();
	USB_Init();

	delay_init();

	while (1) {
		delay_ms(1000);
	}
}
