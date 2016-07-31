CC := arm-linux-gcc
LD := arm-linux-ld
OBJCOPY := arm-linux-objcopy
OBJDUMP := arm-linux-objdump

key_led.bin: crt0.S key_led.c
	$(CC) -g -c -o crt0.o crt0.S
	$(CC) -g -c -o key_led.o key_led.c
	$(LD) -Ttext 0x0000000 -g crt0.o key_led.o -o key_led_elf
	$(OBJCOPY) -O binary -S key_led_elf key_led.bin
	$(OBJDUMP) -D -m arm key_led_elf > key_led.dis
clean:
	rm -rf *.dis *.bin *_elf *.o
