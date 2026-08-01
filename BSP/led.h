#ifndef BSP_LED_H
#define BSP_LED_H

#include <stdbool.h>

/// @file led.h
/// @brief LED board support interface for the BlackPill baseline firmware.

/// @brief Initializes the LED state for the target board.
void bsp_led_init(void);

/// @brief Sets the LED output state.
/// @param state true to turn the LED on, false to turn it off.
void bsp_led_set(bool state);

/// @brief Toggles the current LED state.
void bsp_led_toggle(void);

#endif
