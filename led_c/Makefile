CC := arm-linux-gcc
LD := arm-linux-ld
OBJCOPY := arm-linux-objcopy
OBJDUMP := arm-linux-objdump

led_on_c.bin: crt0.S led_on_c.c
	$(CC) -g -c -o crt0.o crt0.S
	$(CC) -g -c -o led_on_c.o led_on_c.c
	$(LD) -Ttext 0x0000000 -g crt0.o led_on_c.o -o led_on_c_elf
	$(OBJCOPY) -O binary -S led_on_c_elf led_on_c.bin
	$(OBJDUMP) -D -m arm led_on_c_elf > led_on_c.dis
clean:
	rm -rf led_on_c.dis led_on_c.bin led_on_c_elf *.o
