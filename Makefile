CC := arm-none-eabi-gcc
OBJCOPY := arm-none-eabi-objcopy
SIZE := arm-none-eabi-size
CFLAGS := -mcpu=cortex-m4 -mthumb -O0 -g -ffreestanding -fdata-sections -ffunction-sections -Wall -Wextra -pedantic -I$(CURDIR)/BSP -I$(CURDIR)/App
LDFLAGS := -nostdlib -T $(CURDIR)/linker/stm32f411xe.ld -Wl,--gc-sections -Wl,-Map,$(CURDIR)/Build/blackpill_baseline.map
BUILD_DIR := $(CURDIR)/Build
TARGET_ELF := $(BUILD_DIR)/blackpill_baseline.elf
TARGET_BIN := $(BUILD_DIR)/blackpill_baseline.bin

SRCS := $(CURDIR)/App/main.c $(CURDIR)/BSP/led.c $(CURDIR)/BSP/uart.c
OBJS := $(patsubst $(CURDIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
STARTUP := $(CURDIR)/startup/startup_stm32f411xe.S
STARTUP_OBJ := $(BUILD_DIR)/startup/startup_stm32f411xe.o

.PHONY: all clean build prog reset info help USB usb

all: build

help:
	@echo "BlackPill firmware workflow"
	@echo ""
	@echo "  make clean     - remove generated build artifacts"
	@echo "  make build     - compile the firmware only"
	@echo "  make prog      - build then flash using st-flash"
	@echo "  make reset     - reset the target using st-flash reset"
	@echo "  make info      - probe the ST-LINK and target with st-info --probe"
	@echo "  make help      - show this help text"
	@echo ""
	@echo "ST-LINK workflow:"
	@echo "  1. make clean"
	@echo "  2. make build"
	@echo "  3. make prog"
	@echo "  4. make info    (optional: check target visibility)"
	@echo "  5. make reset   (optional: reset after flashing)"
	@echo ""
	@echo "Notes:"
	@echo "  - build and prog are separated so code can be compiled without flashing"
	@echo "  - prog uses st-flash --reset write <bin> 0x08000000"
	@echo "  - reset uses st-flash reset"
	@echo "  - info uses st-info --probe"

build: $(TARGET_BIN)

USB: $(TARGET_BIN)
	@if command -v dfu-util >/dev/null 2>&1; then \
		echo "Attempting DFU bootloader flash over USB-C..."; \
		dfu-util -d 0483:572a -a 0 -s 0x08000000:leave -D $(TARGET_BIN); \
	elif command -v stm32flash >/dev/null 2>&1; then \
		echo "Attempting serial bootloader flash over USB-C..."; \
		stm32flash -w $(TARGET_BIN) /dev/ttyACM0; \
	elif command -v hid-flash >/dev/null 2>&1; then \
		echo "Attempting HID bootloader flash over USB-C..."; \
		hid-flash --device 0483:572a $(TARGET_BIN); \
	else \
		echo "No USB bootloader tool is installed for this BlackPill variant."; \
		echo "Install dfu-util, stm32flash, or the vendor HID bootloader utility, then plug the board into USB-C and retry."; \
		echo "The board is currently enumerating as WeAct Studio HID bootloader (0483:572a)."; \
		exit 1; \
	fi

usb: USB

$(TARGET_BIN): $(TARGET_ELF)
	$(OBJCOPY) -O binary $(TARGET_ELF) $(TARGET_BIN)
	$(SIZE) $(TARGET_ELF)

$(TARGET_ELF): $(OBJS) $(STARTUP_OBJ)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(OBJS) $(STARTUP_OBJ) $(LDFLAGS) -o $@

$(BUILD_DIR)/%.o: $(CURDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(STARTUP_OBJ): $(STARTUP)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

prog: build
	@if command -v st-flash >/dev/null 2>&1; then \
		st-flash --reset write $(TARGET_BIN) 0x08000000; \
	elif command -v openocd >/dev/null 2>&1; then \
		openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c "init; reset halt; program $(TARGET_ELF) verify reset exit"; \
	else \
		echo "No supported STM32 programmer found. Install stlink-tools or OpenOCD."; \
		exit 1; \
	fi

reset:
	@if command -v st-flash >/dev/null 2>&1; then \
		st-flash reset; \
	else \
		echo "st-flash is not installed. Install stlink-tools first."; \
		exit 1; \
	fi

info:
	@if command -v st-info >/dev/null 2>&1; then \
		st-info --probe; \
	else \
		echo "st-info is not installed. Install stlink-tools first."; \
		exit 1; \
	fi

clean:
	rm -rf $(BUILD_DIR)
