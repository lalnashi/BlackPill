#include "led.h"

#include <stdbool.h>
#include <stdint.h>

/// @file led.c
/// @brief BlackPill LED driver that drives the on-board LED on GPIO C pin 13.

/// GPIO port C base address for the STM32F411RE.
#define GPIOC_BASE_ADDRESS 0x40020800UL

/// Reset and clock control base address for the STM32F411RE.
#define RCC_BASE_ADDRESS 0x40023800UL

/// Bit mask used to enable clock gating for GPIO port C.
#define RCC_AHB1ENR_GPIOCEN (1UL << 2)

/// Bit mask used to select output mode for GPIO C pin 13.
#define GPIOC_PIN13_OUTPUT_MODE (1UL << 26)

/// Bit mask used to select the pin 13 output bit in GPIO C output data register.
#define GPIOC_PIN13_BIT (1UL << 13)

/// Internal software state used by the LED abstraction.
static bool led_state = false;

/// @brief Initializes the onboard BlackPill LED output.
/// @details Enables GPIOC clock, configures PC13 as push-pull output, and sets
///          the LED to the off state.
void bsp_led_init(void)
{
    volatile uint32_t *rcc_ahb1enr = (volatile uint32_t *)(RCC_BASE_ADDRESS + 0x30U);
    volatile uint32_t *gpioc_moder = (volatile uint32_t *)(GPIOC_BASE_ADDRESS + 0x00U);
    volatile uint32_t *gpioc_odr = (volatile uint32_t *)(GPIOC_BASE_ADDRESS + 0x14U);

    /// Enable the GPIOC peripheral clock.
    *rcc_ahb1enr |= RCC_AHB1ENR_GPIOCEN;

    /// Configure PC13 as a general purpose output pin.
    *gpioc_moder = (*gpioc_moder & ~(3UL << 26)) | GPIOC_PIN13_OUTPUT_MODE;

    /// Start with the LED off.
    *gpioc_odr |= GPIOC_PIN13_BIT;
    led_state = false;
}

/// @brief Sets the current LED output state.
/// @param state true to turn the LED on, false to turn it off.
void bsp_led_set(bool state)
{
    volatile uint32_t *gpioc_odr = (volatile uint32_t *)(GPIOC_BASE_ADDRESS + 0x14U);

    /// The on-board LED on WeAct BlackPill is active-low on PC13.
    if (state)
    {
        *gpioc_odr &= ~GPIOC_PIN13_BIT;
    }
    else
    {
        *gpioc_odr |= GPIOC_PIN13_BIT;
    }

    led_state = state;
}

/// @brief Toggles the current LED output state.
void bsp_led_toggle(void)
{
    bsp_led_set(!led_state);
}
