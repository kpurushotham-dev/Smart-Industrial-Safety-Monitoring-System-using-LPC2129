#include<lpc21xx.h>
#include "header.h"
#define GREEN (1<<17)
#define YELLOW (1<<18)
#define RED (1<<19)
#define PIR  (1<<6)
#define FLAME (1<<5)
int main()
{
int adc_val;
float voltage;
int temparature;

lcd_init();
UART0_init(9600);
adc_init();

IODIR0 |=GREEN|YELLOW|RED;
IODIR0 &=(PIR|FLAME);
IOSET0=GREEN|YELLOW|RED;

////////////////////////////////////////////////////////
	
while(1)
{
adc_val=adc_read(3);
voltage=(adc_val*3.3)/1023.0;
temparature=voltage *100;

/*LCD status*/
	
lcd_cmd(0X80);
lcd_string("TEMP: ");
lcd_integer(temparature);
lcd_string(" C");

	
lcd_cmd(0XC0);
lcd_string("STATUS: ");

if(temparature<30)

lcd_string("NORMAL");
	
else if(temparature<40)

lcd_string("SAFE ");


else

lcd_string("DANGER");

UART0_tx_string("\r\nTemparature    : ");
UART0_tx_integer(temparature);
UART0_tx_string("°C");

////////////////////////////////////////////////////////

/*PIR sensor*/

if(IOPIN0 & PIR)
{
  UART0_tx_string("\r\nPIR Sensor     :");
	UART0_tx_string(" Worker detected");
}
else
{
	UART0_tx_string("\r\nPIR Sensor     :");
	UART0_tx_string(" No Worker detected");
}

////////////////////////////////////////////////////////

if((IOPIN0&FLAME)==0)
{
	
 UART0_tx_string("\r\nFlame Sensor   : ");
 UART0_tx_string("Fire");
}
else
{
	UART0_tx_string("\r\nFlame Sensor   : ");
  UART0_tx_string("No Fire");
}

/////////////////////////////////////////////////////////

/*Machine status*/
if(temparature<30)
{
	UART0_tx_string("\r\nMachine Status : ");
	UART0_tx_string("NORMAL");
}	
else if(temparature<40)
{
	UART0_tx_string("\r\nMachine Status : ");
	UART0_tx_string("SAFE");
}
	else
{
	UART0_tx_string("\r\nMachine Status : ");
	UART0_tx_string("NOT SAFE");
}

/////////////////////////////////////////////////////////

/*LED status*/

if(temparature<30)
{
	IOCLR0=GREEN;
	IOSET0=YELLOW|RED;
  UART0_tx_string("\r\nLED Status     : ");
  UART0_tx_string("GREEN LED ON");
	UART0_tx_string("\r\n");
	
}	
else if(temparature<40)
{
	
	IOCLR0=YELLOW;
	IOSET0=GREEN|RED;
	UART0_tx_string("\r\nLED Status     : ");
	UART0_tx_string("YELLOW LED ON");
	UART0_tx_string("\r\n");
}
else
{
	IOCLR0=RED;
	IOSET0=YELLOW|GREEN;
	UART0_tx_string("\r\nLED Status     : ");
	UART0_tx_string("RED LED ON");
  UART0_tx_string("\r\n");
}

}

}
/////////////////////////////////////////////////////////
