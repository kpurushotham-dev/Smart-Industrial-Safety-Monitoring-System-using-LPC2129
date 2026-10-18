#include<lpc21xx.h>
void delay_ms(unsigned int ms)
{
T0PR=15000-1;
T0PC=0;
T0TC=0;
//T0TCR=0X02;        //RESET
T0TCR=0X01;          // START TIMER
while(T0TC<ms);
T0TCR=0X0;           //STOP TIMER
}

void delay_sec(unsigned int sec)
{
T0PR=15000000-1;
T0PC=0;
T0TC=0;
//T0TCR=0X02;
T0TCR=0X01;
while(T0TC<sec);
T0TCR=0X0;
}


