current_dir = $(shell pwd)
keymap = crkbd:wulkan
flash_method = dfu-split-left

.PHONY: build
build:
	@ln -s $(current_dir)/crkbd qmk_firmware/keyboards/crkbd/keymaps/wulkan
	@cd qmk_firmware; make $(keymap); cp crkbd_rev1_wulkan.hex ../crkbd_rev1_wulkan.hex; make clean; rm *.hex
	@rm qmk_firmware/keyboards/crkbd/keymaps/wulkan

.PHONY: flash
flash:
	@ln -s $(current_dir)/crkbd qmk_firmware/keyboards/crkbd/keymaps/wulkan
	@cd qmk_firmware; sudo make $(keymap):$(flash_method); sudo make clean; sudo rm *.hex
	@rm qmk_firmware/keyboards/crkbd/keymaps/wulkan

.PHONY: git-submodule
git-submodule:
	@git submodule sync --recursive
	@git submodule update --init --recursive --progress
