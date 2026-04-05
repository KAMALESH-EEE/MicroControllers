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

#define INTR2_REG     (* (volatile uint32_t *) (BASE_IO_BANK + 0x0f8)) // Raw interrupts for GPIO from 16 to 23

#define C0_INTE2_REG  (* (volatile uint32_t *) (BASE_IO_BANK + 0x108)) // Core0# interrupts enable for GPIO from 16 to 23



#define FUN_SIO 5


// IO CONFIGURATION REGISTERS (SIO) details

#define BASE_SIO 0xd0000000

#define IO_IN_REG     (* (volatile uint32_t *) (BASE_SIO + 0x004))

#define IO_OUT_REG    (* (volatile uint32_t *) (BASE_SIO + 0x010))

#define IO_DIR_REG    (* (volatile uint32_t *) (BASE_SIO + 0x020))

// PAD CONFIGURATION REGISTERS details

#define BASE_PAD 0x4001c000



// CLOCK and TIMER REGISTERS details

#define BASE_TIMER 0x40054000

#define TIM_RAW_H_REG (* (volatile uint32_t *) (BASE_TIMER + 0x24)) 
#define TIM_RAW_L_REG (* (volatile uint32_t *) (BASE_TIMER + 0x28)) 




// FUNCTION declearation

void GPIO__INIT(uint8_t pin, uint8_t fun);

void GPIO__DIR(uint8_t pin, bool dir);

void GPIO__OUT(uint8_t pin, bool sts);

uint64_t get_time_uS ();

void usleep (int64_t uS);

void HC_SR04_init ();
float get_distance ();