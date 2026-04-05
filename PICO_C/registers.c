#include "registers.h"

void GPIO_INIT(uint_8t pin){

    volatile uint_32t* REG_ptr;

    REG_ptr = (volatile uint_32t*) (BASE_IO_BANK + (pin * 8) + 4); // pointing GPIO_CTRL reg of <pin> pin

    *REG_ptr = FUN_SIO; // setting to SIO function

}

void GPIO_DIR(uint_8t pin, bool dir){

    IO_DIR_REG &= ~(1 << pin); // clear the direction

    IO_DIR_REG |= ((dir & 0x1) << pin); // setting new direction   

}

void GPIO_OUT(uint_8t pin, bool sts){

    IO_OUT_REG &= ~(1 << pin); // clear the state

    IO_OUT_REG |= ((sts & 0x1) << pin); // setting new state   

}