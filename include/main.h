#ifndef MAIN_H
#define MAIN_H

#include "stm32f4xx.h"
#include "gpio.h"

// Hardware Application Functions

void delay_ms( uint32_t u32TimeMs );
void flash_count( uint32_t u32Count );

#endif // MAIN_H
