#include "sys.h"
#include "usart.h"		
#include "delay.h"	 
int main(void)
{				 
	u16 t; u16 len; u16 times=0;
	Stm32_Clock_Init(9);	//ϵͳʱ������
	delay_init(72);	  		//��ʱ��ʼ��
	uart_init(72,115200); 	//���ڳ�ʼ��Ϊ115200
  	while(1)
	{
		if(USART_RX_STA&0x8000)
		{ 
			len=USART_RX_STA&0x3FFF;//�õ��˴ν��յ������ݳ���
			printf("\r\n Hello Windows! \r\n\r\n");
			for(t=0;t<len;t++)
			{
				USART1->DR=USART_RX_BUF[t];
				while((USART1->SR&0X40)==0);//�ȴ����ͽ���
			}
			printf("\r\n\r\n");//���뻻��
			USART_RX_STA=0;
		}else
		{
			times++;
			if(times%200==0)printf("Hello Windows!\r\n"); 
			//delay_ms(1); 
		}
	}	 
} 

