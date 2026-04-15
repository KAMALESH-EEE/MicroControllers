#include <stdio.h>
#include <stdbool.h>
#include "pico/stdlib.h"

#include "registers.h"

void main()
{
stdio_init_all();

PSM_FRCE_OFF_REG = (1 << 14);

printf("%d",PSM_DONE_REG);

}