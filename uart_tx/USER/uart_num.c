#include "uart_num.h"

union num{
	float f;
	u8 c[4];
}float2char;


void sendFloat(float *f,int num)
{
	int i=0,j=0,k=0;
	for(i=0;i<num;i++)
	{
		float2char.f=f[i];
		for(j=0;j<4;j++)
		{
			if(float2char.c[j]=='\n'||float2char.c[j]=='\\')
			{
				while((USART1->SR&0x40)==0);
				USART_SendData(USART1,'\\');
				k++;
			}
			while((USART1->SR&0x40)==0);
			USART_SendData(USART1,float2char.c[j]);
			k++;
		}
	}
	while((USART1->SR&0x40)==0);
	USART_SendData(USART1,'\n');
}
