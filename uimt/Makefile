# --- Configuration
SKETCH_DIR ?= .
FQBN      ?= esp32:esp32:esp32
PORT      ?= /dev/ttyUSB0
CLI       := arduino-cli

ifeq (,$(shell echo $xterm-256color))
T_RED = [0;31m
T_GRN = [0;32m
T_YLW = [0;33m
T_RST = [0m
else
T_RED =
T_GRN =
T_YLW =
T_RST =
endif

.PHONY: all compile upload flash clean help

all: compile upload

compile:
	@echo "$(T_YLW)==> Compiling for $(FQBN)...$(T_RST)"
	@$(CLI) compile --fqbn $(FQBN) $(SKETCH_DIR)

upload:
	@echo "$(T_YLW)==> Uploading to $(PORT)...$(T_RST)"
	@$(CLI) upload -p $(PORT) --fqbn $(FQBN) $(SKETCH_DIR)

flash: compile upload

clean:
	@echo "$(T_RED)==> No build directory found to clean.$(T_RST)"

help:
	@echo "$(T_GRN)Usage: make [target] [variable=value]$(T_RST)"
	@echo ""
	@echo "Targets:"
	@echo "  compile   Build the sketch"
	@echo "  upload    Upload to board"
	@echo "  flash     Compile and upload (default)"
	@echo "  clean     Clean build artifacts"
	@echo ""
	@echo "Variables:"
	@echo "  FQBN      Set specific board ID"
	@echo "  PORT      Set serial port"
