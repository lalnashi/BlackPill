#include "main.h"

// Safe preprocessor macro constant for calculation tracking
#define NOT_OPEN_DRAIN 0

/// @brief Delays by an approximate number of milliseconds using CPU loop cycles
/// @param ms delay value in milliseconds
void delay_ms(uint32_t ms) {
    // 16MHz internal clock gives roughly 5333 loop cycles per millisecond
    volatile uint32_t count = ms * 5333;
    __asm__ volatile (
        "1: subs %0, #1 \n"
        "   bne 1b      \n"
        : "+r" (count)
    );
}

/// @brief This flashes the value of count on LED GPIOC 13
/// @param uCount The number of active blinks to perform
void flash_count(uint32_t uCount) {
    for (uint32_t cnt = 0; cnt < uCount; cnt++) {
        // Pin is active-low: writing 0 turns the LED ON
        gpio_set_pin_state(GPIOC, 13, GPIO_PIN_RESET);
        delay_ms(100);
        
        // Writing 1 turns the LED OFF
        gpio_set_pin_state(GPIOC, 13, GPIO_PIN_SET);
        delay_ms(100);
    }
}

int main(void) {
    // Force the CPU vector layout mapping to stable flash region offset
    SCB->VTOR = 0x08000000;

    // 1. Enable Port C Clock Using our functional abstraction layout
    gpio_enable_clock(GPIOC);

    // 2. Set Pin C13 to General Purpose Output Mode
    gpio_set_mode(GPIOC, 13, GPIO_MODE_OUTPUT);
    
    // 3. Force Push-Pull Operation topology configuration
    gpio_set_output_type(GPIOC, 13, NOT_OPEN_DRAIN);
    
    // Force the onboard LED into the OFF state by default
    gpio_set_pin_state(GPIOC, 13, GPIO_PIN_SET);

    // Track state locally within the main stack configuration loop space
    uint32_t count_number = 1;

    while (1) {
        // Execute active flashes
        flash_count(count_number);

        // Cycle through states 1 to 5 safely
        count_number++;
        if (count_number > 5) { 
            count_number = 1;
        }

        // Wait 1 second before executing the next value grouping loop
        delay_ms(1000);
    }
}
