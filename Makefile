CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
# Includes both -Iinclude and -ICMSIS directories
CFLAGS = -mcpu=cortex-m4 -mthumb -O1 -g -Wall -Iinclude -ICMSIS -DSTM32F411xE

# Workspace Directory File Definitions
SRCS = src/main.c src/startup_stm32f411xe.c
OBJS = $(SRCS:.c=.o)

all: blink.bin

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

blink.elf: $(OBJS) linker_script.ld
	$(CC) $(CFLAGS) -T linker_script.ld $(OBJS) -o blink.elf -nostartfiles -nodefaultlibs

blink.bin: blink.elf
	$(OBJCOPY) -O binary blink.elf blink.bin

flash: blink.bin
	st-flash write blink.bin 0x08000000

clean:
	rm -f src/*.o *.elf *.bin
