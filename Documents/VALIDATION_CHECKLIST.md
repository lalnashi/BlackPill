# BlackPill Validation Checklist

## 1. Pre-implementation validation
Before starting implementation, confirm:
- the requirement is clear
- the target hardware constraints are known
- the change fits the project architecture
- the intended behavior is testable

## 2. Build validation
The following must be checked before completion:
- project compiles successfully
- required build commands are executed and documented
- no unresolved compile or link errors remain

## 3. Static and quality validation
Check for:
- warnings that indicate real issues
- dead code
- unused variables or parameters
- poor naming or unclear state transitions
- unsafe pointer or casting behavior
- code that violates project coding standards

## 4. Memory and robustness validation
For C/C++ or native validation paths, check for:
- bounds issues
- null-pointer assumptions
- unsafe arithmetic or conversions
- stack-related risks where relevant
- failure paths that are not handled properly

## 5. Runtime validation
- test the firmware behavior against the intended task or feature
- confirm expected outputs are produced
- check for timing problems or incorrect state transitions
- validate task behavior where FreeRTOS is involved

## 6. Final sign-off
A task is only complete when:
- the requirement is met
- the code builds
- the design remains consistent
- validation checks pass
- final reporting includes evidence
