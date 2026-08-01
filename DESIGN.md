# BlackPill Design Document

## 1. Purpose
This repository is the foundation for a BlackPill firmware project built around embedded C/C++ and FreeRTOS.

The design goal is to create a clean and testable baseline that demonstrates:
- startup and system initialization
- hardware abstraction boundaries
- simple task scheduling under FreeRTOS
- basic peripheral use and debugability
- development practices that can scale to more advanced firmware features

## 2. Design principles
- keep the system simple and deterministic
- separate hardware-specific code from application logic
- prefer explicit, readable firmware patterns
- avoid unnecessary abstraction layers early in the project
- keep the build reproducible and easy to debug

## 3. Hardware assumptions
The project targets the STM32 BlackPill board family and assumes a standard embedded toolchain environment for ARM Cortex-M devices.

## 4. Baseline firmware architecture
The baseline design includes:
- startup code and reset vector handling
- system clock initialization
- GPIO configuration
- optional UART console for debugging
- FreeRTOS task skeletons
- application task layer
- board support and driver layer separation

## 5. Initial milestone scope
The first milestone should be intentionally small and robust:
- successful build of the firmware project
- minimal startup and task execution
- basic LED or GPIO activity
- serial debug output if supported
- clean project layout and validation process

## 6. Future expansion
After the baseline is stable, the project may expand to include:
- additional drivers
- sensor interfaces
- communication stacks
- more complex task orchestration
- more advanced real-time behaviors

However, expansion should only occur after the baseline is validated.

## 7. Success criteria for the baseline
The project is successful at baseline when:
- the board builds cleanly
- firmware initializes predictably
- the system can be debugged effectively
- the project structure is modular and maintainable
- the engineering workflow is repeatable and explicit
