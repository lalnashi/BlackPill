#ifndef GPIO_H
#define GPIO_H

#include "stm32f4xx.h"

// Define readable enumeration constants for pin modes
typedef enum {
    GPIO_MODE_INPUT  = 0x00,
    GPIO_MODE_OUTPUT = 0x01,
    GPIO_MODE_ALT    = 0x02,
    GPIO_MODE_ANALOG = 0x03
} GPIOMode_t;

// Define pin states
typedef enum {
    GPIO_PIN_RESET = 0,
    GPIO_PIN_SET   = 1
} GPIOState_t;

// Define open Drain values
typedef enum {
    NOT_OPEN_DRAIN = 0,
    OPEN_DRAIN =1
}OpenDrainMode;

// Set the operational mode of a specific pin
inline static void gpio_set_mode(GPIO_TypeDef *GPIOx, uint8_t pin, GPIOMode_t mode) {
    GPIOx->MODER &= ~(3UL << (pin * 2));         // Clear current mode bits
    GPIOx->MODER |=  ((uint32_t)mode << (pin * 2)); // Write new mode configuration
}

// Set the output driving type to Push-Pull (0) or Open-Drain (1)
inline static void gpio_set_output_type(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t is_open_drain) {
    if (is_open_drain) {
        GPIOx->OTYPER |= (1UL << pin);
    } else {
        GPIOx->OTYPER &= ~(1UL << pin);
    }
}

// Set a specific pin HIGH or LOW
inline static void gpio_set_pin_state(GPIO_TypeDef *GPIOx, uint8_t pin, GPIOState_t state) {
    if (state == GPIO_PIN_SET) {
        GPIOx->ODR |= (1UL << pin);
    } else {
        GPIOx->ODR &= ~(1UL << pin);
    }
}

// Read the current state of a pin (Get function)
inline static GPIOState_t gpio_get_pin_state(GPIO_TypeDef *GPIOx, uint8_t pin) {
    if (GPIOx->IDR & (1UL << pin)) {
        return GPIO_PIN_SET;
    }
    return GPIO_PIN_RESET;
}

// Toggle a specific pin output state
inline static void gpio_toggle_pin(GPIO_TypeDef *GPIOx, uint8_t pin) {
    GPIOx->ODR ^= (1UL << pin);
}
// Abstract Clock Management using an optimized switch-case block
inline static void gpio_enable_clock(GPIO_TypeDef *GPIOx) {
    switch ((uint32_t)GPIOx) {
        case GPIOA_BASE:
            RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
            break;
        case GPIOB_BASE:
            RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
            break;
        case GPIOC_BASE:
            RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
            break;
#if defined(GPIOD_BASE)
        case GPIOD_BASE:
            RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
            break;
#endif
#if defined(GPIOE_BASE)
        case GPIOE_BASE:
            RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
            break;
#endif
#if defined(GPIOH_BASE)
        case GPIOH_BASE:
            RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
            break;
#endif
        default:
            // Optional: Handle error or unsupported port pass-through
            break;
    }
    
    /* 
     * Optimization Note: A short delay after enabling a peripheral clock 
     * is good practice on STM32 to ensure the clock stabilizes before 
     * you read or write to its registers.
     */
    __asm__ volatile("nop");
}


#endif // GPIO_H
