CC=gcc
CC_FLAGS=-m32 -c -Wall -Wextra -Werror -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs

AS=nasm
AS_FLAGS=-f elf

SRC=src
INC=$(SRC)/include


all: kernel.bin

SRCS.C=$(wildcard $(SRC)/*.c) $(wildcard $(INC)/*.c)
SRCS.S=$(wildcard $(SRC)/*.s) $(wildcard $(INC)/*.s)
OBJS =$(SRCS.C:.c=.o) $(SRCS.S:.s=.o)

%.o: %.c
	$(CC) $(CC_FLAGS) -o $@ $<

%.o: %.s
	$(AS) $(AS_FLAGS) -o $@ $<

kernel.bin: $(OBJS) src/link.ld
	ld -m elf_i386 -T src/link.ld -o iso/boot/kernel.bin $(OBJS)

clean:
	rm -rf iso $(OBJS)
