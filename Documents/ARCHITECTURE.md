# BlackPill Firmware Architecture

## 1. High-level architecture
The project follows a simple embedded architecture pattern with clear separation between:
- startup and platform setup
- board support / peripheral configuration
- application logic
- FreeRTOS task execution where used
- debugging and validation paths

## 2. Layer responsibilities

### 2.1 Board support layer
Responsible for:
- clock configuration
- GPIO configuration
- UART configuration
- timer setup
- board-specific startup routines

### 2.2 Peripheral and driver layer
Responsible for:
- hardware abstraction for the board peripherals
- encapsulation of register-level or HAL-level behavior
- clean access boundaries for application code

### 2.3 Application layer
Responsible for:
- firmware behavior
- business logic or feature logic
- task coordination and system-level decisions

### 2.4 FreeRTOS layer
Responsible for:
- task scheduling
- prioritization and timing
- inter-task communication
- synchronization primitives where needed

## 3. Design principles
- keep peripheral access explicit and controlled
- isolate hardware dependencies from higher-level logic
- prefer small, understandable modules
- avoid mixing unrelated responsibilities in a single file
- favor deterministic code paths over runtime complexity

## 4. Embedded design rules
- check stack and memory usage when introducing local buffers or task stacks
- do not assume infinite timing margins
- validate all hardware assumptions against datasheet and board configuration
- treat interrupts and RTOS scheduling as part of the design, not afterthoughts

## 5. Standard project structure
The repository should keep code organized into logical areas such as:
- App/
- Drivers/
- BSP/
- FreeRTOS/
- startup/
- linker/
- CMSIS/

New code should be placed into the correct layer rather than inserted into unrelated areas.
