#ifndef AVR_DELAY_H
#define AVR_DELAY_H

long int MCU_freq = 8000000;

void delay(double s)
{
    int i,j,k;
    for(k=0;k<s*2;k++)
    for(i=0xff;i;i--) for(j=0xff;j;j--);
}

#endif

