#ifndef BSP_UART_H
#define BSP_UART_H

/// @file uart.h
/// @brief UART board support interface for the BlackPill baseline firmware.

/// @brief Initializes the UART peripheral used by the baseline firmware.
/// @return 0 on successful initialization, otherwise a non-zero error code.
int bsp_uart_init(void);

/// @brief Writes a null-terminated message to the UART output stream.
/// @param message Pointer to the message to transmit.
void bsp_uart_write(const char *message);

#endif
