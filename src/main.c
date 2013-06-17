/**
 ******************************************************************************
 * @file    main.c
 * @author  MCD Application Team
 * @version V3.4.0
 * @date    29-June-2012
 * @brief   Virtual Com Port Demo main file
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
 *
 * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *        http://www.st.com/software_license_agreement_liberty_v2
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************************
 */


/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "hw_config.h"
#include "usb_lib.h"
#include "usb_desc.h"
#include "usb_pwr.h"
#include "systick.h"


void send_usart(USART_TypeDef* USART, char* data) {
	while(*data != 0) {
		USART_SendData(USART1,*data);
		data++;
	}
}

int main(void) {

	Set_System();
	Set_USBClock();
	USB_Interrupts_Config();
	USB_Init();

	delay_init();

	GPIO_InitTypeDef led;

	led.GPIO_Mode = GPIO_Mode_Out_PP;
	led.GPIO_Speed = GPIO_Speed_50MHz;

	led.GPIO_Pin = GPIO_Pin_0;
	GPIO_Init(GPIOB, &led);

	GPIO_ResetBits(GPIOB, GPIO_Pin_0);


	while (1) {
		delay_ms(1000);
	}
}
#ifdef USE_FULL_ASSERT
/*******************************************************************************
 * Function Name  : assert_failed
 * Description    : Reports the name of the source file and the source line number
 *                  where the assert_param error has occurred.
 * Input          : - file: pointer to the source file name
 *                  - line: assert_param error line source number
 * Output         : None
 * Return         : None
 *******************************************************************************/
void assert_failed(uint8_t* file, uint32_t line)
{
	/* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while (1)
	{}
}
#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
