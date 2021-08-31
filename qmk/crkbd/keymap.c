#include QMK_KEYBOARD_H

extern uint8_t is_master;

#define _COLEMAK_DH 0
#define _GAMEING 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 4

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)

#define COLEMAK_DH DF(_COLEMAK_DH)
#define GAMEING DF(_GAMEING)

enum unicode_names {
  SE_AA_HIGH,
  SE_AE_HIGH,
  SE_OE_HIGH,
  SE_AA_LOW,
  SE_AE_LOW,
  SE_OE_LOW,
};

const uint32_t PROGMEM unicode_map[] = {
  [SE_AA_HIGH] = 0x00C5,
  [SE_AE_HIGH] = 0x00C4,
  [SE_OE_HIGH] = 0x00D6,
  [SE_AA_LOW]  = 0x00E5,
  [SE_AE_LOW]  = 0x00E4,
  [SE_OE_LOW]  = 0x00F6,
};

#define SE_AA XP(SE_AA_LOW, SE_AA_HIGH)
#define SE_AE XP(SE_AE_LOW, SE_AE_HIGH)
#define SE_OE XP(SE_OE_LOW, SE_OE_HIGH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /* Colemak-DH
  ,-----------------------------------------.             ,-----------------------------------------.
  | Tab  |   Q  |   W  |   F  |   P  |   B  |             |   J  |   L  |   U  |   Y  |   ;  | Bksp |
  |------+------+------+------+------+------|             |------+------+------+------+------+------|
  | Shift|   A  |   R  |   S  |   T  |   G  |             |   M  |   N  |   E  |   I  |   O  | Shift|
  |------+------+------+------+------+------|             |------+------+------+------+------+------|
  | Ctrl |   Z  |   X  |   C  |   D  |   V  |             |   K  |   H  |   ,  |   .  |   /  | "    |
  `------+------+------+------+------+------+------+------+------+------+------+------+------+------'
                              | GUI  |Lower |Enter |Space |Raise | Esc  |
                              `-----------------------------------------'
*/
  [_COLEMAK_DH] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_LSFT, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                        KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_RSFT,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                        KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
  //,--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------.
                                          KC_LGUI, LOWER,   KC_ENT,     KC_SPC, RAISE,   KC_ESC
                                      //`--------------------------'  `--------------------------'
  ),

  [_GAMEING] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_RSFT,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
  //,--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------.
                                          KC_LGUI, LOWER,   KC_SPC,     KC_ENT, RAISE,   KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.  
      KC_TAB,  KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER,  KC_ENT,     KC_SPC,   RAISE, KC_RALT \
                                      //`--------------------------'  `--------------------------'
    ),

  [_RAISE] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR, KC_PIPE, KC_GRV,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER,  KC_ENT,     KC_SPC,   RAISE, KC_RALT \
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT( \
  //,-------------------------------------------------------.                    ,-----------------------------------------------------.
        RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   XXXXXXX, XXXXXXX, XXXXXXX, SE_AA,   XXXXXXX,\
  //|----------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                       KC_F12,  XXXXXXX, XXXXXXX, SE_OE,   SE_AE,   XXXXXXX,\
  //|----------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     COLEMAK_DH, GAMEING, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|----------+--------+--------+--------+--------+--------+----------|  |------+--------+--------+--------+--------+--------+--------|
                                            KC_LGUI,   LOWER,  KC_ENT,     KC_SPC,  RAISE, KC_RALT \
                                        //`----------------------------' `--------------------------'
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void eeconfig_init_user(void) {
  set_unicode_input_mode(UC_LNX); // UC_LNX for linux, UC_MAC for macOS, UC_WINC for windows
}


#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
  oled_render_logo();
}

#endif // OLED_DRIVER_ENABLE