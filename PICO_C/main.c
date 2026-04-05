#include <stdio.h>
#include "pico/stdlib.h"

#include "registers.h"


int main ()
{

  GPIO_INIT (8)
  GPIO_DIR (8,true);

  IO_OUT_REG = (1 << 22);

}