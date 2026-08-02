# BlackPill Project Requirements

## 1. Project purpose
This project is an educational and practical firmware repository focused on:
- STM32 BlackPill development
- FreeRTOS-based embedded software
- C++ and C firmware patterns
- low-level embedded understanding from first principles

## 2. Target platform
- STM32 BlackPill board family
- embedded firmware running on MCU hardware
- FreeRTOS used where appropriate for task scheduling and coordination

## 3. Functional goals
The project should demonstrate:
- clean firmware structure
- modular code organization
- deterministic embedded behavior
- correct hardware abstraction boundaries
- use of FreeRTOS primitives in appropriate contexts
- clear startup, task, and driver separation

## 4. Non-functional goals
- keep the design simple and readable
- prefer correctness over cleverness
- minimize hidden side effects
- prefer robust edge-case handling over fragile assumptions
- keep code maintainable and easy to debug

## 5. Constraints
- embedded code must remain hardware-aware and platform-conscious
- memory usage and timing must be considered explicitly
- code should avoid unnecessary dynamic allocation in firmware paths
- assumptions must be validated against the hardware or system constraints
- safety-critical or timing-critical behavior must be implemented defensively

## 6. Acceptance expectations
A feature or fix is accepted only when it can be shown to:
- satisfy the project requirement
- build successfully
- remain consistent with the project architecture
- pass the validation routine defined in VALIDATION_CHECKLIST.md
