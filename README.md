
Install qmk, for arch do:
```
sudo pacman --needed --noconfirm -S git python-pip libffi
sudo pacman -S qmk
qmk setup -H ~/git/qmk_firmware
sudo cp ~/git/qmk_firmware/util/udev/50-qmk.rules /etc/udev/rules.d/.
sudo udevadm control --reload-rules
sudo udevadm trigger
```

Link keymap into the qmk project:
```
ln -s ~/git/keymap/crkbd ~/git/qmk_firmware/keyboards/crkbd/keymaps/wulkan
```

Setup qmk to default to this keyboard and keymap
```
qmk config user.keyboard=crkbd
qmk config user.keymap=wulkan
```

Build
```
qmk compile
```

Flash left side
```
qmk flash -bl dfu-split-left
```

Flash right side
```
qmk flash -bl dfu-split-right
```
