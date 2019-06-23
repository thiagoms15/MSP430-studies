APP=hello_world

OBJECTS=$(APP).o
OUTPUT=$(APP).elf
MAP_FILE=$(APP).map
HEX_FILE=$(APP).hex
LSS_FILE=$(APP).lss

CROSS_COMPILE_PATH=/opt/ti/msp430-gcc
GCC_DIR =  $(CROSS_COMPILE_PATH)/bin
SUPPORT_FILE_DIRECTORY = $(CROSS_COMPILE_PATH)/include

DEVICE  = msp430g2553
CC      = $(GCC_DIR)/msp430-elf-gcc
GDB     = $(GCC_DIR)/msp430-elf-gdb

CFLAGS = -I $(SUPPORT_FILE_DIRECTORY) -mmcu=$(DEVICE) -O2 -g
LFLAGS = -L $(SUPPORT_FILE_DIRECTORY) -Wl,-Map,$(MAP_FILE) -T $(DEVICE).ld #-nostdlib -nostartfiles

all: ${OBJECTS}
	@echo -e "Building..."
	@$(CC) $(CFLAGS) $(LFLAGS) $? -o $(OUTPUT)
	@ cp $(OUTPUT) $(DEVICE).out
	@echo -e "Done."

install: all
	mspdebug --force-reset rf2500 "prog $(OUTPUT)"
	mspdebug --force-reset rf2500 "run"

debug: all
	clear
	@echo -e "--------------------------------------------------------------------------------"
	@echo -e "--                           Debugging $(APP)                            --"
	@echo -e "--------------------------------------------------------------------------------"
	$(GDB) $(OUTPUT)

info: all
	clear
	@echo -e "--------------------------------------------------------------------------------"
	@echo -e "--                     Info about the $(APP)                             --"
	@echo -e "--------------------------------------------------------------------------------"
	@file $(OUTPUT)
	@$(GCC_DIR)/msp430-elf-size $(OUTPUT)
	@$(GCC_DIR)/msp430-elf-objdump -Sd -W $(OUTPUT) > $(LSS_FILE)
	@echo -e "Created $(LSS_FILE)"
	@$(GCC_DIR)/msp430-elf-objcopy -O ihex $(OUTPUT) $(HEX_FILE)
	@echo -e "Created $(HEX_FILE)"

.PHONY : clean
clean :
	@echo "Clean up."
	@rm $(OBJECTS) $(OUTPUT) $(DEVICE).out $(MAP_FILE) $(LSS_FILE) $(HEX_FILE)
