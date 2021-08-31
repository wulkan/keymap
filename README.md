# Repo for my different keyboard layouts

## [Crkbd](https://github.com/foostan/crkbd) with [ZMK](https://zmk.dev/) and [nice!nano](https://nicekeyboards.com/nice-nano)

Follow the instructions for setting up zmk: 

[ZMK Setup](https://zmk.dev/docs/development/setup)

Since I'm from Sweden I sometimes have to write things in swedish with **`åäö`**. At the same time I want an American layout to my keyboard. In QMK that was easy sorted with the help of sending unicode charactars in a form of macro. Neither is supported in ZMK and the PR that would enable this kind of macro seems to be stall so you need to apply a patch to your local ZMK clone in order to compile my crkbd layout.
The patch is based on the work in this PR [zmkfirmware/zmk#685](https://github.com/zmkfirmware/zmk/pull/685)
```sh
cd ~/git/zmk
git apply ../keymap/zmk/zmk_behavior_macro.patch
```

Then you are ready to compile both the left and right side of the keyboard, replace `username` with your username
```sh
cd ~/git/zmk/app
west build -d build/left -b nice_nano -- -DSHIELD=corne_left -DZMK_CONFIG=/home/username/git/keymap/zmk/crkbd
cp build/left/zephyr/zmk.uf2 corne_left.uf2
west build -d build/right -b nice_nano -- -DSHIELD=corne_right -DZMK_CONFIG=/home/username/git/keymap/zmk/crkbd
cp build/right/zephyr/zmk.uf2 corne_right.uf2
```

Now just connect the nice!nano via USB and double press the reset butten and copy the file over for that half and your done.

## [Crkbd](https://github.com/foostan/crkbd) with [QMK](https://qmk.fm/) and [Elite-C](https://splitkb.com/products/elite-c-low-profile-rev4-microcontroller)

Install QMK, for arch do:
```sh
sudo pacman --needed --noconfirm -S git python-pip libffi
sudo pacman -S qmk
qmk setup -H ~/git/qmk_firmware
sudo cp ~/git/qmk_firmware/util/udev/50-qmk.rules /etc/udev/rules.d/.
sudo udevadm control --reload-rules
sudo udevadm trigger
```

Link keymap into the qmk project:
```sh
ln -s ~/git/keymap/qmk/crkbd ~/git/qmk_firmware/keyboards/crkbd/keymaps/wulkan
```

Setup qmk to default to this keyboard and keymap
```sh
qmk config user.keyboard=crkbd
qmk config user.keymap=wulkan
```

Build
```sh
qmk compile
```

Flash left side
```sh
qmk flash -bl dfu-split-left
```

Flash right side
```sh
qmk flash -bl dfu-split-right
```
