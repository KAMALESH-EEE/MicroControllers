#include <stdio.h>
#include <stdbool.h>
#include "pico/stdlib.h"

#include "registers.h"


int main ()
{
  uint32_t ht,lt;
  stdio_init_all();

  GPIO__INIT (22, FUN_SIO);
  GPIO__DIR (22, true);

  GPIO__OUT (22, true);

  HC_SR04_init ();

  while (true)
  {
    usleep(1 * 1000);
    printf("%.2f mm\n",get_distance ());
  }

}