### Makefile  -*- Makefile -*-

MCU     = atmega328p
F_CPU   = 16000000

CC      = avr-gcc
CFLAGS  = -O2 -Wall -std=gnu11 -mmcu=$(MCU)
CPPFLAGS  = -DF_CPU=$(F_CPU)L

OBJCOPY = avr-objcopy

.PHONY: default
default: fade.hex fade

fade:  fade.c

%.hex: %
	$(OBJCOPY) -O ihex $< $@

### Makefile ends here