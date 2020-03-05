/* Copyright 2019 kuchosauronad0
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
enum planck_layers {
  _LAYOUT
};

//float my_song[][2] = SONG(NOCTURNE_OP_9_NO_1);

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
 QMKBEST = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_LAYOUT] = LAYOUT( /* Base */
   KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_A,   KC_B, 
   KC_0,    KC_0,   KC_0,   KC_0,   KC_0,   KC_0,   KC_0,   KC_0,   KC_0,   KC_0,   KC_0,   KC_0,
   KC_0,    KC_0,   KC_0,   KC_0,   KC_0,   KC_0,   KC_0,   KC_0,   KC_0,   KC_0,   KC_0,   KC_0,
   KC_0,    KC_0,   KC_0,   KC_0,   KC_0,   KC_0,   KC_0,   KC_0,   KC_0,   KC_0,   KC_0,   KC_0
   ),
};
#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
  if (clockwise) {
   tap_code(KC_1);
  } else {
   tap_code(KC_0);
  }
 }
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
 switch (keycode) {
  case QMKBEST:
   if (record->event.pressed) {
    // when keycode QMKBEST is pressed
    SEND_STRING("QMK is the best thing ever!");
   } else {
   }
   break;
 }
 return true;
}

//void matrix_init_user(void) {
//
//}
//
//void matrix_scan_user(void) {
//
//}
//
//void led_set_user(uint8_t usb_led) {
//
//}
