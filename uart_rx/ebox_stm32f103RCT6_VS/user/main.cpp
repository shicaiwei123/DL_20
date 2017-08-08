/**
******************************************************************************
* @file   : *.cpp
* @author : shentq
* @version: V1.2
* @date   : 2016/08/14

* @brief   ebox application example .
*
* Copyright 2016 shentq. All Rights Reserved.
******************************************************************************
*/

#include "ebox.h"
#include "uart_num.h"
#include "led.h"

UartNum<float> uartNum(&uart1);
Led led(&PC13, 1);

void setup()
{
	ebox_init();
	uartNum.begin(115200);
	led.begin();
}

int main(void)
{
	setup();
	float f[] = { 0.1,10.1 };
	float* rx;
	int size;

	while (1)
	{
		led.toggle();
		delay_ms(100);
		
		for (int i=0;i<2;i++)
		{
			f[i] += 0.1;
		}
		uartNum.sendNum(f, 2);

		uartNum.printf("\r\n");
		uartNum.waitBusy();
		rx = uartNum.getNum();
		size = uartNum.getLength();
		for (int i = 0; i < size; i++)
		{
			uartNum.printf("%f ",rx[i]);
		}
		uartNum.printf("\r\n");
	}
}


