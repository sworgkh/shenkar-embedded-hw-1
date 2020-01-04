#include "potentiometer.h"
#include "Compiler.h"

unsigned int get_potentiometer_value()
{
    unsigned int value;
    ADCON0 = 0x13;
    while (ADCON0 & 0x02)
        ;
    value = ADRESH;
    value = value << 8;
    value = value | ADRESL;
    return value;
}
