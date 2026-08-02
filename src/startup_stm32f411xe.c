#include <stdint.h>

extern uint32_t _estack;
extern void main(void);

void Reset_Handler(void);
void Default_Handler(void) { while(1); }

// Setup weak alias defaults for early hardware vector routing
void NMI_Handler(void)          __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler(void)    __attribute__ ((weak, alias("Default_Handler")));

// Construct the primary vector table structure array
__attribute__((section(".vector_table")))
void (* const vector_table[])(void) = {
    (void (*)(void))&_estack,
    Reset_Handler,
    NMI_Handler,
    HardFault_Handler
};

void Reset_Handler(void) {
    // Directly step into application execution loop
    main();
    while(1);
}
