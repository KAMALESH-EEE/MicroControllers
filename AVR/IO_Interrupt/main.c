
#include <avr/io.h>
#include "avr_delay.h"  //Include my header file for delay
#include <avr/interrupt.h>

ISR(INT0_vect)
{
    PORTB^=(1<<3);      //Toggling RB3 pin
}

int main()
{
    PORTB=0xff; 
    DDRB=0xff;          //Setting port B as OUTPUT
    SREG |=(1<<7);      //Enabling Global Interrupts
    DDRD=0;             //Setting port D as OUTPUT
    PORTD=0x04;
    MCUCR&=~(1<<4);     //Enabling PULL-UP
    EICRA = 0x02;       //The falling edge of INT0 generates an interrupt request
    EIMSK = 0x01;       //External Interrupt Request 0 Enable

    while (1)
    {
        PORTB|=(1<<2);
        delay(1);
        PORTB&=~(1<<2);
        delay(1);
    }
}

