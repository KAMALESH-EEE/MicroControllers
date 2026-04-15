#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "registers.h"

void GPIO__INIT(uint8_t pin, uint8_t fun)
{

    volatile uint32_t * REG_ptr;

    REG_ptr = (volatile uint32_t*) (BASE_IO_BANK + (pin * 8) + 4); // pointing GPIO_CTRL reg of <pin> pin

    *REG_ptr = fun; // setting to SIO function

}

void GPIO__DIR(uint8_t pin, bool dir)
{

    volatile uint32_t * REG_ptr;
    
    IO_DIR_REG &= ~(1 << pin); // clear the direction

    IO_DIR_REG |= ((dir & 0x1) << pin); // setting new direction   

    if (! dir){

      REG_ptr = (volatile uint32_t*) (BASE_PAD + (pin * 4) + 4); // pointing GPIO_CTRL reg of <pin> pin

      *REG_ptr |= (1 << 6); // Input Enable

    }

}

void GPIO__OUT(uint8_t pin, bool sts)
{

    IO_OUT_REG &= ~(1 << pin); // clear the state

    IO_OUT_REG |= ((sts & 0x1) << pin); // setting new state   

}


uint64_t get_time_uS ()
{
    return ((TIM_RAW_H_REG << 32) |TIM_RAW_L_REG);
}

void usleep (int64_t uS)
{

  uint64_t tt;

  tt = get_time_uS () + uS;

  while (true)    if (tt <= get_time_uS())  break;
  
}


void HC_SR04_init ()
{ 
  
  GPIO__INIT (21, FUN_SIO);
  GPIO__INIT (20, FUN_SIO);

  GPIO__DIR (21, true);
  GPIO__DIR (20, false);

  C0_INTE2_REG |= (0x3 << 18);

}

float get_distance ()
{

  uint64_t st = 0, time_out = 5000000;

  /* Pulse for 10 uSec*/
  GPIO__OUT (21, true);

  INTR2_REG = (0xc0000);   // Clearing the Interrupt
  
  usleep(10);
  GPIO__OUT (21, false);

  /*wait for Echo pin High and latch the time*/

  while (time_out > 0)
  {
    if (((INTR2_REG >> 19) & 0x1) == 0x1)
    {
      st = get_time_uS ();
      time_out = 5000000;
      break;
    }
    time_out -= 1;
  }
  

  /*wait for Echo pin LOW and Calculate the time*/
 while (time_out > 0)
  {
    if (((INTR2_REG >> 18) & 0x1) == 0x1)
    {
      st = (get_time_uS() - st);
      return (float) st/5.8 ;
    }

    time_out -= 1;

  }

  return 100000.0;

}


void i2c_write(I2C1 *self, uint8_t Addr, uint8_t Data)
{

  I2C1_TAR_REG = self -> SlaveID;


  while (true)    if ((I2C1_TX_FL_REG & 0xff) < 0xff) break;
  I2C1_CMD_REG = (I2C_RESTART | I2C_WRITE) | (Addr & 0xff);
  
  
  while (true)    if ((I2C1_TX_FL_REG & 0xff) < 0xff) break;
  I2C1_CMD_REG = (I2C_STOP | I2C_WRITE) | (Data & 0xff);
  usleep(1000);

}

uint8_t i2c_read(I2C1 *self, uint8_t Addr)
{

  I2C1_TAR_REG = self -> SlaveID;

  while (true)    if ((I2C1_TX_FL_REG &0xff) < 0xff)    break;
  I2C1_CMD_REG = (I2C_RESTART | I2C_WRITE) | ((Addr) & 0xff);
  

  while (true)    if ((I2C1_TX_FL_REG &0xff) < 0xff)    break;
  I2C1_CMD_REG = (I2C_RESTART | I2C_STOP | I2C_READ);

  
  while (true)    if ((I2C1_RX_FL_REG &0xff))     break;
  usleep(1000);

  return (uint8_t)(I2C1_CMD_REG & 0xff);
  
}


void I2C_DEVICE (I2C1 *S_dev, uint8_t S_ID)

{

  GPIO__INIT (27, FUN_I2C);
  GPIO__INIT (26, FUN_I2C);

  

  S_dev->SlaveID = S_ID;

  S_dev->Read  = i2c_read ;
  S_dev->Write = i2c_write;

  I2C1_EN_REG = 0;

  I2C1_SCK_HCNT_REG = 600;
  I2C1_SCK_LCNT_REG = 600;

  I2C1_CTRL_REG     = (I2C_S_DIS | I2C_M_RESTART | I2C_SPEED_STD | I2C_M_EN);

  I2C1_EN_REG = 1;

}