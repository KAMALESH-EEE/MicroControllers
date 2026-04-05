#ifndef REGISTERS_H
#define REGISTERS_H
#endif

// IO CONTROL REGISTERS Details

#define BASE_IO_BANK 0x40014000


#define IO0_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0x004))

#define IO1_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0x00c))

#define IO2_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0x014))

#define IO3_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0x01c))

#define IO4_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0x024))

#define IO5_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0x02c))

#define IO6_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0x034))

#define IO7_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0x03c))

#define IO8_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0x044))

#define IO9_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0x04c))

#define IO10_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0x054))

#define IO11_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0x05c))

#define IO12_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0x064))

#define IO13_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0x06c))

#define IO14_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0x074))

#define IO15_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0x07c))

#define IO16_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0x084))

#define IO17_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0x08c))

#define IO18_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0x094))

#define IO19_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0x09c))

#define IO20_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0x0a4))

#define IO21_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0x0ac))

#define IO22_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0x0b4))

#define IO23_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0x0bc))

#define IO24_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0xc4))

#define IO25_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0x0cc))

#define IO26_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0x0d4))

#define IO27_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0x0dc))

#define IO28_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0x0e4))

#define IO29_CTRL_REG (* (volatile uint32_t *) (BASE_IO_BANK +0x0ec))

#define FUN_SIO 5;


// IO CONFIGURATION REGISTERS (SIO) details

#define BASE_SIO 0xd0000000

#define IO_DIR_REG (* (volatile uint32_t *) (BASE_SIO + 0x020))

#define IO_OUT_REG (* (volatile uint32_t *) (BASE_SIO + 0x010))



// struct define


typedef struct

{
    uint_8t gpio;

}   PIN;

void GPIO_INIT(uint_8t pin);

void GPIO_DIR(uint_8t pin, bool dir);

void GPIO_OUT(uint_8t pin, bool sts);