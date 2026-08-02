# BlackPill Coding Standards

## 1. Language and style
- Prefer clear, explicit C++ and C code over clever or overly condensed patterns
- use consistent naming and readable structure
- keep function sizes reasonable and responsibilities focused
- avoid hidden global state unless it is intentionally required

## 2. Embedded safety rules
- validate all pointer usage
- never trust raw hardware register state without checking assumptions
- avoid unsafe integer conversions without explicit justification
- prefer bounded loops and checked indexing
- do not use dynamic allocation in highly timing-sensitive or safety-sensitive paths unless the design explicitly requires it

## 3. RTOS and concurrency rules
- document shared state and synchronization strategy
- guard shared resources with explicit synchronization mechanisms
- avoid unnecessary blocking in interrupt or time-critical paths
- keep task interactions predictable and understandable

## 4. Determinism rules
- avoid unpredictable operations in time-sensitive code
- minimize reliance on undefined or implementation-dependent behavior
- prefer fixed-size structures and explicit types for hardware interfaces

## 5. Maintainability rules
- keep modules focused on one concern
- keep hardware-specific code near the boundary where it belongs
- document assumptions when interfacing with peripherals or low-level hardware
- write code that is easy to debug in the lab

## 6. Code review expectations
All changes should be reviewable for:
- correctness
- readability
- hardware correctness
- embedded safety
- project consistency
