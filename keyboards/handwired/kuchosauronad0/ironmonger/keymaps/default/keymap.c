
#include QMK_KEYBOARD_H

#define _QW 0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .-----------------------------------------------------------------------------------------------------------.
 * | ESC    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | BACKSPC|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | TAB    | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SHIFT  | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | ENT/SFT|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | LCTRL  | LGUI   | ALT    | ALT    | NUM    | SHIFT  | SPACE  | DIR    | RGUI   | RALT   | DEL    | CTRL   |
 * '-----------------------------------------------------------------------------------------------------------'
 */

  [_QW] = LAYOUT(
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_T(KC_ENT),
  KC_LCTL, KC_LGUI, KC_LALT, KC_LALT, KC_1, KC_LSFT,  KC_SPC,     KC_1, KC_RGUI, KC_RALT, KC_DEL,  KC_RCTL
  ),


};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
