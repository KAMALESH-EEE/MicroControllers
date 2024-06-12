#include <avr/io.h>
#include <avr/interrupt.h>
int i=0;
ISR(TIMER0_COMPA_vect)
{
    if(i==10)
    {
    PORTB^=0xff;  
    i=0;
    }
    else i++;
}

int main()
{
     TCCR0A =0xC2;
     TCCR0B=0x04;
     DDRD |=(1<<6);
     OCR0A = 0xff;
     TIMSK0=0x02;
     SREG|=(1<<7);
     DDRB=0xff;
     PORTB=0;
    while(1)
    {
        
    }
}
