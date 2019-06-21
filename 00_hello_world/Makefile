OBJECTS=hello_world.o

CROSS_COMPILE_PATH=/opt/ti/msp430-gcc
GCC_DIR =  $(CROSS_COMPILE_PATH)/bin
SUPPORT_FILE_DIRECTORY = $(CROSS_COMPILE_PATH)/include

DEVICE  = msp430g2553
CC      = $(GCC_DIR)/msp430-elf-gcc
GDB     = $(GCC_DIR)/msp430-elf-gdb

CFLAGS = -I $(SUPPORT_FILE_DIRECTORY) -mmcu=$(DEVICE) -O2 -g
LFLAGS = -L $(SUPPORT_FILE_DIRECTORY)

all: ${OBJECTS}
	$(CC) $(CFLAGS) $(LFLAGS) $? -o $(DEVICE).out

debug: all
	$(GDB) $(DEVICE).out

.PHONY : clean
clean :
	-rm $(OBJECTS) $(DEVICE).out  	
