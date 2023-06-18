BOARD?=arduino:avr:uno
PORT?=/dev/ttyACM0

INCLUDE = ./include

CFLAGS = --build-property compiler.cpp.extra_flags="-I./include"

.PHONY: default all upload clean

default: all upload monitor

all:
	arduino-cli compile --fqbn $(BOARD) $(CFLAGS) ./

upload:
	arduino-cli upload --fqbn $(BOARD) --port $(PORT)

monitor:
	arduino-cli monitor -p $(PORT)

clean:
	rm -r build