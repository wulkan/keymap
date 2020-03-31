current_dir = $(shell pwd)
keyboard = crkbd
revision = rev1
keymap = $(shell whoami)
flash_method = dfu-split-left

ifdef revision
rev = /$(revision)
rev_out = _$(revision)
else
rev =
rev_out =
endif

.PHONY: help
help:
	@echo --+== Keymaps ==+--
	@echo
	@echo Each keymap is in a folder that is named the same as the keyboard
	@echo
	@echo -- Get dependencies
	@echo make git-submodule
	@echo
	@echo -- Build the keymap
	@echo make build
	@echo - Optional variables with defaults
	@echo keyboard=crkbd
	@echo revision=rev1
	@echo
	@echo -- Build and flash the keymap
	@echo make flash
	@echo - Optional variables with defaults
	@echo keyboard=crkbd
	@echo revision=rev1
	@echo flash_method=dfu-split-left
	@echo
	@echo -- Dislay this help message
	@echo make help

.PHONY: build
build:
	@if [ ! -d "$(current_dir)/$(keyboard)" ]; then exit 1 ; fi
	@ln -s $(current_dir)/$(keyboard) qmk_firmware/keyboards/$(keyboard)/keymaps/$(keymap)
	@cd qmk_firmware; make $(keyboard)$(rev):$(keymap); cp $(keyboard)$(rev_out)_$(keymap).hex ../$(keyboard)$(rev_out)_$(keymap).hex; make clean; rm *.hex
	@rm qmk_firmware/keyboards/$(keyboard)/keymaps/$(keymap)

.PHONY: flash
flash:
	@if [ ! -d "$(current_dir)/$(keyboard)" ]; then exit 1 ; fi
	@ln -s $(current_dir)/$(keyboard) qmk_firmware/keyboards/$(keyboard)/keymaps/$(keymap)
	@cd qmk_firmware; sudo make $(keyboard)$(rev):$(keymap):$(flash_method); sudo make clean; sudo rm *.hex
	@rm qmk_firmware/keyboards/$(keyboard)/keymaps/$(keymap)

.PHONY: git-submodule
git-submodule:
	@git submodule sync --recursive
	@git submodule update --init --recursive --progress
