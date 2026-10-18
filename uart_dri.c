#include<lpc21xx.h>
void UART0_init(unsigned int baud)
{
unsigned int pclk,result;

if(VPBDIV==0x0)
pclk=15000000;

else if(VPBDIV==0x1)
pclk=60,000,000;

else if(VPBDIV==0x2)
pclk=30,000,000;

result=pclk/(16*baud);

PINSEL0|=0X05;         //TxD and RxD;
U0LCR=0X83;          //unlock baudrate setting
U0DLL=97 ;          //store data
U0DLM=0;            //result
U0LCR=0X03;         //lock baudrate setting
}

#define THRE ((U0LSR>>5) & 1)
void UART0_tx(unsigned char data)
{
	//while((U0LSR&(1<<5))==0);
U0THR=data;
while(THRE==0);
}
	#define RBR (U0LSR&1)
	unsigned char UART0_rx(void) 
	{
		while(RBR==0);
		return U0RBR;
}
	
void UART0_tx_string(char *ptr)
{
	while(*ptr!=0)
	{
		UART0_tx(*ptr);
		ptr++;
	}
}

void UART0_tx_integer(adc_val) 
{
	char a[10];
int i; 
if(adc_val<0)
	{
UART0_tx('-'); 
adc_val=-adc_val; 
} 
if(adc_val==0) 
{ 
	UART0_tx('0');
return;
}
for(i=0;adc_val;adc_val=adc_val/10,i++) 
a[i]=adc_val%10+48;
for(i=i-1;i>=0;i--) 
UART0_tx(a[i]);
} 




















