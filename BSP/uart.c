#include "uart.h"

/// @file uart.c
/// @brief UART driver placeholder for the BlackPill baseline implementation.

/// @brief Initializes the UART abstraction used by the baseline firmware.
/// @return 0 to indicate the placeholder initialization succeeded.
int bsp_uart_init(void)
{
    return 0;
}

/// @brief Writes a message to the UART output stream.
/// @param message Pointer to the message to transmit.
void bsp_uart_write(const char *message)
{
    (void)message;
}
