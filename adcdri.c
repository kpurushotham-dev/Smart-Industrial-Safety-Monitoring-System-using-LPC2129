#include<lpc21xx.h>
#define DONE ((ADDR>>31)&1)

void adc_init(void)
{
PINSEL1 = (PINSEL1 & ~(3<<24)) | (1<<24);
ADCR = (1 << 21) | (6 << 8);
}

unsigned int adc_read(unsigned int ch_num)
{
unsigned int result;
ADCR|=(1<<ch_num);
ADCR|=(1<<24);
while(DONE==0);
ADCR&= ~(1<<24);
ADCR&= ~(1<<ch_num);
result=(ADDR>>6)&0X3ff;
return result;
}

	 