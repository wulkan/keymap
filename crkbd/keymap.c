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
      KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET  ,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER,  KC_ENT,     KC_SPC,   RAISE, KC_RALT \
                                      //`--------------------------'  `--------------------------'
    ),

  [_RAISE] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR, KC_PIPE,  KC_GRV,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER,  KC_ENT,     KC_SPC,   RAISE, KC_RALT \
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, X(SE_AA_LOW), XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, X(SE_OE_LOW), X(SE_AE_LOW), XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      COLEMAK_DH, GAMEING, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER,  KC_ENT,     KC_SPC,   RAISE, KC_RALT \
                                      //`--------------------------'  `--------------------------'
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void eeconfig_init_user(void) {
  set_unicode_input_mode(UC_LNX);
}


void matrix_init_user(void) {
  //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
  #ifdef SSD1306OLED
    iota_gfx_init(!has_usb());   // turns on the display
  #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_logo(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write(matrix, read_logo());
    //matrix_write_ln(matrix, read_layer_state());
    //matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED
