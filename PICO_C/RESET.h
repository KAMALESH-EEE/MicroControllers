
#ifndef PSM_RESET_H
#define PSM_RESET_H


#define BASE_PSM                0x40010000

#define PSM_FRCE_ON_REG         *((volatile uint32_t *) (BASE_PSM  +   0x0))
#define PSM_FRCE_OFF_REG        *((volatile uint32_t *) (BASE_PSM  +   0x0))
#define PSM_WDSEL_REG           *((volatile uint32_t *) (BASE_PSM  +   0x0))
#define PSM_DONE_REG            *((volatile uint32_t *) (BASE_PSM  +   0x0))



#endif
