# BlackPill Project AI Operating Instructions

## 1. Mission
This repository is a BlackPill / FreeRTOS / C++ embedded firmware project. The primary goal is to build trustworthy, testable, maintainable embedded software for the STM32 BlackPill platform.

The agent must follow the repository design and requirement documents before implementing changes.

## 2. Source of truth
Read these files first and treat them as the authoritative project contract:
- README.md
- REQUIREMENTS.md
- ARCHITECTURE.md
- CODING_STANDARDS.md
- VALIDATION_CHECKLIST.md

If a requirement is unclear, missing, or contradictory:
- stop and ask for clarification
- do not guess
- do not invent features outside the documented scope

## 3. Mandatory workflow
Before claiming a task is complete, complete the following in order:

### 3.1 Requirements review
- confirm the requirement being implemented
- map the change to the project requirements and design intent
- verify that the implementation is aligned with the firmware architecture

### 3.2 Build verification
- ensure the project builds successfully using the repo’s required build steps
- fix compile errors before moving to the next stage
- do not ignore warnings if the project treats warnings as failures

### 3.3 Code quality and static review
- validate against the repository coding standards
- check for dead code, unsafe patterns, unused variables, and unclear ownership
- prefer clarity, determinism, and embedded-safe patterns over cleverness

### 3.4 Memory and safety validation
For this embedded C/C++ project, memory safety and robustness checks are mandatory where applicable:
- compiler warnings must be reviewed
- bounds checking must be explicit where memory access is involved
- no unsafe casts or unchecked pointer assumptions without justification
- if the project targets a host test environment, run sanitizer-based validation when possible
- for bare-metal or MCU work, apply reasoning-based validation and runtime checks where supported

### 3.5 Test and validation
- run the applicable project tests, host tests, or smoke validation
- validate against real behavior rather than assumed behavior
- when hardware-in-the-loop validation is required, verify against the device constraints and expected outputs

### 3.6 Final requirement traceability check
- confirm the implementation satisfies the relevant requirement
- confirm there are no hidden shortcuts or undocumented assumptions
- confirm the final behavior matches the design intent

## 4. Definition of done
A task is complete only when all of the following are true:
- requirements are satisfied
- the project builds successfully
- code quality checks are passed
- memory and safety checks are handled appropriately
- applicable tests or validation checks pass
- the final response includes fresh evidence of verification

## 5. Non-negotiable rules
- do not claim completion without fresh evidence
- do not hide failing checks
- do not invent requirements not present in the project docs
- do not implement speculative features without explicit approval
- do not assume hardware behavior without checking the datasheet or design constraints
- do not use unsafe embedded patterns without justification
- do not skip validation because the code “looks correct”

## 6. Reporting format
When reporting completion, the agent must include:
- what requirement was addressed
- what was changed
- what build/validation commands were run
- what result each check produced
- any remaining risks, assumptions, or follow-up actions

## 7. Final instruction
Follow the design, respect the hardware constraints, validate the result, and only then report success.
