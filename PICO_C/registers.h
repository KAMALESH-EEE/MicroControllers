#ifndef REGISTERS_H
#define REGISTERS_H


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



// I2C register details


#define BASE_I2C1 0x40048000

#define I2C1_CTRL_REG     (* (volatile uint32_t *) (BASE_I2C1 + 0x00))

#define I2C1_TAR_REG      (* (volatile uint32_t *) (BASE_I2C1 + 0x04))

#define I2C1_CMD_REG      (* (volatile uint32_t *) (BASE_I2C1 + 0x10))

#define I2C1_STS_REG      (* (volatile uint32_t *) (BASE_I2C1 + 0x70))

#define I2C1_SCK_HCNT_REG (* (volatile uint32_t *) (BASE_I2C1 + 0x14))

#define I2C1_SCK_LCNT_REG (* (volatile uint32_t *) (BASE_I2C1 + 0x18))

#define I2C1_EN_REG       (* (volatile uint32_t *) (BASE_I2C1 + 0x6c))

#define I2C1_TX_FL_REG    (* (volatile uint32_t *) (BASE_I2C1 + 0x74))

#define I2C1_RX_FL_REG    (* (volatile uint32_t *) (BASE_I2C1 + 0x78))

#define I2C_RESTART 0x400

#define I2C_STOP    0x200

#define I2C_READ    0x100

#define I2C_WRITE   0x000


#define I2C_S_EN 0x00
#define I2C_S_DIS 0x40

#define I2C_M_RESTART 0x20

#define I2C_10BIT_M_ADDR_EN 0x10

#define I2C_10BIT_S_ADDR_EN 0x8

#define I2C_SPEED_STD 0x2

#define I2C_M_EN 0x1
#define I2C_M_DIS 0x0



#define FUN_I2C 3

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

// Structure declearation

typedef struct I2C1 I2C1;

struct I2C1
{
  uint32_t SCK_PIN ,SDA_PIN;

  uint8_t SlaveID;

  uint8_t (*Read )  (I2C1 *self, uint8_t Addr);
  void    (*Write)  (I2C1 *self, uint8_t Addr, uint8_t Data);
};

void I2C_DEVICE (I2C1 *S_dev, uint8_t S_ID);


// FUNCTION declearation

void GPIO__INIT(uint8_t pin, uint8_t fun);

void GPIO__DIR(uint8_t pin, bool dir);

void GPIO__OUT(uint8_t pin, bool sts);

uint64_t get_time_uS ();

void usleep (int64_t uS);

void HC_SR04_init ();
float get_distance ();

void I2C0_init();
void DS1307_write(uint16_t data);
uint8_t DS1307_read(uint8_t data);

#endif