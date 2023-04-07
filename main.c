#include <REGX52.H>
#include "esp8266.h"
#include "oled.h"
#include "DS1302.h"
#include "uart.h"
#include "delay.h"

void main()
{
	unsigned int flag=1;//用作防一秒内多次进入的判断位
	Uart_Init();
	Esp8266_Init();
	DS1302_Init();
	DS1302_SetTime();
	OLED_init();
	OLED_clear();
	while(1)
	{
//如果需要用oled显示的话请将scl连在P0_7,sda连在P0_6
		EA=0;
		DS1302_ReadTime();//读取时间
		OLED_ShowNum(2,1,DS1302_Time[3]);//显示时
		OLED_print_char(2,3,':',0);
		OLED_ShowNum(2,4,DS1302_Time[4]);//显示分
		OLED_print_char(2,6,':',0);
		OLED_ShowNum(2,7,DS1302_Time[5]);//显示秒
//		flag=1;
		if((DS1302_Time[5]==0||DS1302_Time[4]==0||DS1302_Time[3]==0)&&DS1302_Time[5]==0)//此处&&避免因为小时的归零导致一个小时的屏幕清理
		{
			OLED_clear();
			delay(1000);
		}
		if((DS1302_Time[3]%12==0) && (DS1302_Time[5]==0)&&(DS1302_Time[4]==0))
		{
			IAP_CONTR=0x20;//软件复位寄存器
		}
		if((DS1302_Time[3]==6) &&(DS1302_Time[4]==6)&& (DS1302_Time[5]==6))
		{
			P2_0=0;
			delay(500);
			P2_0=1;
			delay(500);
		}else{flag=1;}//确保flag处于触发状态
		OLED_print_char(0,1,Recive_table[4],0);
		OLED_print_char(0,2,Recive_table[5],0);
		OLED_print_char(0,3,Recive_table[6],0);
		OLED_print_char(0,4,Recive_table[7],0);
		OLED_print_char(0,5,Recive_table[8],0);
		OLED_print_char(1,1,Recive_table[9],0);
		OLED_print_char(1,2,Recive_table[10],0);
		OLED_print_char(1,3,Recive_table[11],0);
		OLED_print_char(1,4,Recive_table[12],0);
		OLED_print_char(1,5,Recive_table[13],0);


//		OLED_clear();
		
	}
}

void UART_Routine(void) interrupt 4
{
static	unsigned char i=0;
static	unsigned char flag=0;
	P2=0xff;
	if(RI==1)
	{
		RI = 0;
		if(i<21)
		{
			if(SBUF=='O'){flag=1;}
			else if(SBUF=='T'){flag=0;}
			if(flag==1){Recive_table[i++] = SBUF;}
		}
		
	}
} 
