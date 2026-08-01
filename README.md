# BlackPill Firmware Project

This repository is the starting point for a BlackPill-based firmware project using FreeRTOS and C++ from first principles.

## Project direction
This project is intentionally scoped as a learning and baseline firmware project. The goal is to build a clean, modular embedded architecture using an STM32 BlackPill board and to establish repeatable engineering practices before adding more ambitious features.

## Core objectives
- understand the embedded system architecture from the ground up
- build a reliable MCU firmware baseline
- use FreeRTOS in a disciplined, practical way
- keep the design modular and debuggable
- establish the requirement-driven workflow before adding advanced features

## Repository structure
- App/ - application logic
- BSP/ - board support and hardware abstractions
- Drivers/ - peripheral drivers
- FreeRTOS/ - RTOS-specific code and configuration
- CMSIS/ - CMSIS dependencies and headers
- startup/ - startup and reset code
- linker/ - linker scripts
- Makefile/ - build scripts and tooling

## Current phase
We are in the architecture and project-definition phase.

The next work is to define:
1. the hardware and firmware baseline
2. the system architecture
3. the initial build flow
4. the validation and review process
5. the first safe milestone feature set

## Design and process documents
- [AGENTS.md](AGENTS.md)
- [REQUIREMENTS.md](REQUIREMENTS.md)
- [ARCHITECTURE.md](ARCHITECTURE.md)
- [CODING_STANDARDS.md](CODING_STANDARDS.md)
- [VALIDATION_CHECKLIST.md](VALIDATION_CHECKLIST.md)
- [DESIGN.md](DESIGN.md)
- [PROJECT_PLAN.md](PROJECT_PLAN.md)

## Working philosophy
We are not rushing into feature development.
The first goal is to create a trustworthy, minimal baseline that can later evolve into more advanced firmware work.
