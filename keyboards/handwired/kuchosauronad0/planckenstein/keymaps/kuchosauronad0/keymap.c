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
#include "kuchosauronad0.h"

/* Planckenstein base layout
 * ,-----------------------------------------------------------------------------------.
 * |TabAlt|  L1  |  L1  |  L1  |  L1  |  L1  |  R1  |  R1  |  R1  |  R1  |  R1  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |GuiEsc|  L2  |  L2  |  L2  |  L2  |  L2  |  R2  |  R2  |  R2  |  R2  |  R2  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+--- --+------|
 * |SftEsc|  L3  |  L3  |  L3  |  L3  |  L3  |  R3  |  R3  |  R3  |  R3  |  R3  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | Hyper|Leader|Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
#define LAYOUT_planckenstein_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K00, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K10, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K20 \
  ) \
  LAYOUT_wrapper( \
    R1L,     K01,     K02,  K03,    K04, K05,    K06,    K07, K08,     K09,     K00,   R1R, \
    R2L,     K11,     K12,  K13,    K14, K15,    K16,    K17, K18,     K19,     K10,   R2R, \
    R3L,     K21,     K22,  K23,    K24, K25,    K26,    K27, K28,     K29,     K20,   R3R,  \
    KC_LCTL, KC_LALT, HYP, KC_MEH, LWR, KC_SPC, KC_SPC, RSE, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT \
  )
#define LAYOUT_planckenstein_base_wrapper(...)       LAYOUT_planckenstein_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
            
  [_QWERTY] = LAYOUT_planckenstein_base_wrapper(
    _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
    _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
    _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
  ),

  [_COLEMAK] = LAYOUT_planckenstein_base_wrapper(
    _________________COLEMAK_L1________________, _________________COLEMAK_R1________________,
    _________________COLEMAK_L2________________, _________________COLEMAK_R2________________,
    _________________COLEMAK_L3________________, _________________COLEMAK_R3________________
  ),

  [_DVORAK] = LAYOUT_planckenstein_base_wrapper(
    _________________DVORAK_L1_________________, _________________DVORAK_R1_________________,
    _________________DVORAK_L2_________________, _________________DVORAK_R2_________________,
    _________________DVORAK_L3_________________, _________________DVORAK_R3_________________
  ),
  [_WORKMAN] = LAYOUT_planckenstein_base_wrapper(
    _________________WORKMAN_L1________________, _________________WORKMAN_R1________________,
    _________________WORKMAN_L2________________, _________________WORKMAN_R2________________,
    _________________WORKMAN_L3________________, _________________WORKMAN_R3________________
  ),

#ifdef UNICODEMAP_ENABLE
  [_UNICODE] = LAYOUT_planckenstein_base_wrapper(
    _______________UNICODE_L1__________________, _______________UNICODE_R1__________________,
    _______________UNICODE_L2__________________, _______________UNICODE_R2__________________,
    _______________UNICODE_L3__________________, _______________UNICODE_R3__________________
  ),
#endif

  [_MODS] = LAYOUT_wrapper(\
    _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______
  ),

  [_LOWER] = LAYOUT_wrapper(\
    KC_TILD, _________________LOWER_L1__________________, _________________LOWER_R1__________________, KC_BSPC,
    KC_F11,  _________________LOWER_L2__________________, _________________LOWER_R2__________________, KC_PIPE,
    KC_F12,  _________________LOWER_L3__________________, _________________LOWER_R3__________________, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_RAISE] = LAYOUT_wrapper(\
    KC_GRV,  _________________RAISE_L1__________________, _________________RAISE_R1__________________, KC_BSPC,
    _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________, KC_BSLS,
    _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_ADJUST] = LAYOUT_wrapper(\
    KC_MAKE, _________________ADJUST_L1_________________, _________________ADJUST_R1_________________, KC_RESET,
    VRSN,    _________________ADJUST_L2_________________, _________________ADJUST_R2_________________, EEP_RST,
    TG_MODS, _________________ADJUST_L3_________________, _________________ADJUST_R3_________________, KC_MPLY,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )

};

void matrix_init_keymap(void) {
  #ifndef CONVERT_TO_PROTON_C
    setPinOutput(D5);
    writePinHigh(D5);
    setPinOutput(B0);
    writePinHigh(B0);
  #endif
}
