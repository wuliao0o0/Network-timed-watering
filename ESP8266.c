#include <REGX51.H>
#include <string.h>
#include "uart.h"
#include "string.h"
#include "delay.h"
unsigned char Recive_table[21];
void Esp8266_Init(void)
{
	
	delay(1000);
//	Uart_SendCmd("\r\n");
//	Uart_SendCmd("AT+UART=9600,8,1,0,0");
//	delay(1000);
//	Uart_SendCmd("AT+CWMODE=3");
//	delay(1000);
//	P2_0=0;
////	Uart_SendCmd("AT+CWSAP=\"ESP8266\",\"12345678\",11,3");
////	Uart_SendCmd("AT+CIPMUX=1");
//	Uart_SendCmd("AT+CWJAP=\"HFUU\",\"\"");
//	delay(3000);
//	P2_1=0;
//	Uart_SendCmd("AT+CIPSTART=\"TCP\",\"192.168.0.103\",8080");
	Uart_SendCmd("AT+CIPSTART=\"TCP\",\"192.168.100.36\",80");
//	delay(3000);
	P2_2=0;
	Uart_SendCmd("AT+CIPMODE=1");
//	delay(3000);
	P2_3=0;
	Uart_SendCmd("AT+CIPSEND");
//	delay(3000);
	P2_4=0;
	Uart_SendCmd("GET");
	delay(1000);
	P2_5=0;
	
//	Uart_SendStr("+++");
//	delay(3000);
//	P2_6=0;
	////	delay(3000);
//	Uart_SendCmd("AT+CIPSERVER=1,8080");
////	Uart_SendStr("AT+CWQAP\r\n");
////	delay(1000);


}
