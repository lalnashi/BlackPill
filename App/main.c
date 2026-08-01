#include "led.h"
#include "uart.h"

/// @file main.c
/// @brief Application entry point for the BlackPill baseline firmware.
/// @details Initializes the board LED and holds it on so the target has a
///          visible startup indicator during hardware validation.

/// @brief Runs the simplest possible startup sequence to force the LED on.
/// @return This function does not return under normal operation.
int main(void)
{
    /// Initialize the LED support layer.
    bsp_led_init();

    /// Force the LED to the on state immediately for a visible startup indicator.
    bsp_led_set(true);

    /// Keep the board in a steady on state to confirm the firmware is alive.
    for (;;)
    {
    }
}
