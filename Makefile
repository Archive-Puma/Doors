CC=gcc
CC_FLAGS=-m32 -c -Wall -Wextra -Werror -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs

all: kernel.bin

SOURCES=$(wildcard src/*.c) $(wildcard src/include/*.c)
OBJECTS =$(SOURCES:.c=.o)

%.o: %.c
	$(CC) $(CC_FLAGS) -o $@ $<

bootloader.o:
	nasm -f elf32 -o bootloader.o src/bootloader.asm

kernel.bin: $(OBJECTS) bootloader.o src/link.ld
	ld -m elf_i386 -T src/link.ld -o iso/boot/kernel.bin src/bootloader.o $(OBJECTS)

clean:
	rm -rf iso bootloader.o $(OBJECTS)
