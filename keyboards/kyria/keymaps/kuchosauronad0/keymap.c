/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

#ifdef RGBLIGHT_ENABLE
  extern rgblight_config_t rgblight_config;
#endif

#ifdef INDICATOR_LIGHTS
  extern userspace_config_t userspace_config;
  uint8_t last_mod;
  uint8_t last_led;
  uint8_t last_osm;
#endif

#define LAYOUT_wrapper(...)            LAYOUT(__VA_ARGS__)
#define LAYOUT_kyria_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
    KC_1, K01, K02, K03, K04, K05,                         K06, K07, K08, K09, K0A, KC_1, \
    KC_1, K11, K12, K13, K14, K15,                         K16, K17, K18, K19, K1A, KC_1, \
    KC_1, K21, K22, K23, K24, K25, KC_1, KC_2, KC_3, KC_4, K26, K27, K28, K29, K2A, KC_1, \
                    KC_1, KC_2, KC_3,KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0 \
    )

#define LAYOUT_kyria_base_wrapper(...)       LAYOUT_kyria_base(__VA_ARGS__)

uint16_t copy_paste_timer;

/*enum layers {
    QWERTY = 0,
    LOWER,
    RAISE,
    NAV,
    ADJUST
};*/

//enum custom_keycodes {
//    KC_CCCV = SAFE_RANGE
//};


////////////////////////////////////////////////////////////////////////////////
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kyria_base_wrapper(
    _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
    _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
    _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
  ),
  [_COLEMAK] = LAYOUT_kyria_base_wrapper(
    _________________COLEMAK_L1________________, _________________COLEMAK_R1________________,
    _________________COLEMAK_L2________________, _________________COLEMAK_R2________________,
    _________________COLEMAK_L3________________, _________________COLEMAK_R3________________
  ),

  [_DVORAK] = LAYOUT_kyria_base_wrapper(
    _________________DVORAK_L1_________________, _________________DVORAK_R1_________________,
    _________________DVORAK_L2_________________, _________________DVORAK_R2_________________,
    _________________DVORAK_L3_________________, _________________DVORAK_R3_________________
  ),
#ifdef UNICODEMAP_ENABLE
  [_UNICODE] = LAYOUT_kyria_base_wrapper(
    _______________UNICODE_L1__________________, _______________UNICODE_R1__________________,
    _______________UNICODE_L2__________________, _______________UNICODE_R2__________________,
    _______________UNICODE_L3__________________, _______________UNICODE_R3__________________
  ),
#endif
  [_PLOVER] = LAYOUT_wrapper(\
    KC_1,  _________________PLOVER_L1_________________,                                     _________________PLOVER_R1_________________, KC_1,
    KC_NO, _________________PLOVER_L2_________________,                                     _________________PLOVER_R2_________________, KC_NO,
    KC_NO, _________________PLOVER_L3_________________, _______, _______, _______, _______, _________________PLOVER_R3_________________, _______,
                             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_MODS] = LAYOUT_wrapper(\
    KC_LALT, _______, _______, _______, _______, _______,                                      _______, _______, _______, _______, _______, KC_RALT,
    KC_LCTL, _______, _______, _______, _______, _______,                                      _______, _______, _______, _______, _______, KC_RCTL,
    KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
                               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_LOWER] = LAYOUT_wrapper(\
    KC_TILD, _________________LOWER_L1__________________,                                     _________________LOWER_R1__________________, KC_BSPC,
    KC_F11,  _________________LOWER_L2__________________,                                     _________________LOWER_R2__________________, KC_PIPE,
    KC_F12,  _________________LOWER_L3__________________, _______, _______, _______, _______, _________________LOWER_R3__________________, _______,
                               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_RAISE] = LAYOUT_wrapper(\
    KC_GRV,  _________________RAISE_L1__________________,                                     _________________RAISE_R1__________________, KC_BSPC,
    _______, _________________RAISE_L2__________________,                                     _________________RAISE_R2__________________, KC_BSLS,
    _______, _________________RAISE_L3__________________, _______, _______, _______, _______, _________________RAISE_R3__________________, _______,
                               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_ADJUST] = LAYOUT_wrapper(\
    KC_MAKE, _________________ADJUST_L1_________________,                                     _________________ADJUST_R1_________________, KC_RESET,
    VRSN,    _________________ADJUST_L2_________________,                                     _________________ADJUST_R2_________________, EEP_RST,
    DEBUG,   _________________ADJUST_L3_________________, _______, _______, _______, _______, _________________ADJUST_R3_________________, _______,
                               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )

};

////////////////////////////////////////////////////////////////////////////////////
//layer_state_t layer_state_set_user(layer_state_t state) {
//    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
//}
//
//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//    switch (keycode) {
//        case KC_CCCV:  // One key copy/paste
//            if (record->event.pressed) {
//                copy_paste_timer = timer_read();
//            } else {
//                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {  // Hold, copy
//                    tap_code16(LCTL(KC_C));
//                } else { // Tap, paste
//                    tap_code16(LCTL(KC_V));
//                }
//            }
//            break;
//    }
//    return true;
//}
//
//
//bool is_alt_tab_active = false;
//uint16_t alt_tab_timer = 0;
//
//LEADER_EXTERNS();
//
//void matrix_scan_user(void) {
//    if (is_alt_tab_active) {
//        if (timer_elapsed(alt_tab_timer) > 1000) {
//            unregister_code(KC_LALT);
//            is_alt_tab_active = false;
//        }
//    }
//
//    LEADER_DICTIONARY() {
//        leading = false;
//        leader_end();
//
//        SEQ_ONE_KEY(KC_C) { // Inline Code
//            SEND_STRING("`` " SS_TAP(X_LEFT) SS_TAP(X_LEFT));
//        }
//        SEQ_ONE_KEY(KC_P) { // Invoke Password Manager
//            SEND_STRING(SS_LCTRL(SS_LALT("\\")));
//        }
//        SEQ_ONE_KEY(KC_S) { // Windows screenshot
//            SEND_STRING(SS_LGUI("\nS"));
//        }
//        SEQ_TWO_KEYS(KC_F, KC_P) { // Fusion Projection prefix
//            SEND_STRING("[Projection] ");
//        }
//        SEQ_TWO_KEYS(KC_B, KC_B) { // Basecone invoice description
//            SEND_STRING("[Leveranciersnaam] [Factuurnummer]");
//        }
//        SEQ_TWO_KEYS(KC_E, KC_S) { // Support email splitkb
//            SEND_STRING("support@splitkb.com");
//        }
//        SEQ_TWO_KEYS(KC_E, KC_T) { // Email splitkb
//            SEND_STRING("thomas@splitkb.com");
//        }
//        SEQ_TWO_KEYS(KC_E, KC_P) { // Email personal
//            SEND_STRING("mail@thomasbaart.nl");
//        }
//        SEQ_TWO_KEYS(KC_S, KC_D) { // Splitkb documentation
//            SEND_STRING("https://docs.splitkb.com/");
//        }
//        SEQ_TWO_KEYS(KC_S, KC_V) { // Splitkb VAT number
//            SEND_STRING("NL210593349B01");
//        }
//        SEQ_TWO_KEYS(KC_B, KC_C) { // Discord bongocat
//            SEND_STRING(":bongocat:\n");
//        }
//        SEQ_TWO_KEYS(KC_C, KC_B) { // Discord code block
//            SEND_STRING("```c" SS_LSFT("\n\n") "``` " SS_TAP(X_UP));
//        }
//        SEQ_TWO_KEYS(KC_Y, KC_S) { // Greeting
//            SEND_STRING("Yours sincerely,\n\nThomas Baart");
//        }
//        SEQ_THREE_KEYS(KC_M, KC_V, KC_G) { // Greeting
//            SEND_STRING("Met vriendelijke groet,\n\nThomas Baart");
//        }
//    }
//}
//
//#ifdef OLED_DRIVER_ENABLE
//oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//	return OLED_ROTATION_180;
//}
//
//static void render_kyria_logo(void) {
//    static const char PROGMEM kyria_logo[] = {
//        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
//        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
//        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
//    };
//    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
//}
//
//static void render_qmk_logo(void) {
//  static const char PROGMEM qmk_logo[] = {
//    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
//    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
//    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
//
//  oled_write_P(qmk_logo, false);
//}
//
//static void render_status(void) {
//    // QMK Logo and version information
//    render_qmk_logo();
//    oled_write_P(PSTR("       Kyria rev1.0\n\n"), false);
//
//    // Host Keyboard Layer Status
//    oled_write_P(PSTR("Layer: "), false);
//    switch (get_highest_layer(layer_state)) {
//        case _QWERTY:
//            oled_write_P(PSTR("Default\n"), false);
//            break;
//        case _LOWER:
//            oled_write_P(PSTR("Lower\n"), false);
//            break;
//        case _RAISE:
//            oled_write_P(PSTR("Raise\n"), false);
//            break;
////        case NAV:
////            oled_write_P(PSTR("Navigation\n"), false);
////            break;
//        case _ADJUST:
//            oled_write_P(PSTR("Adjust\n"), false);
//            break;
//        default:
//            oled_write_P(PSTR("Undefined\n"), false);
//    }
//
//    // Host Keyboard LED Status
//    uint8_t led_usb_state = host_keyboard_leds();
//    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK)    ? PSTR("NUMLCK ") : PSTR("       "), false);
//    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK)   ? PSTR("CAPLCK ") : PSTR("       "), false);
//    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
//}
//
//void oled_task_user(void) {
//    if (is_keyboard_master()) {
//        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
//    } else {
//        render_kyria_logo();
//    }
//}
//#endif
//
////#ifdef ENCODER_ENABLE
////void encoder_update_user(uint8_t index, bool clockwise) {
////    if (index == 0) {
////        switch (biton32(layer_state)) {
////            case QWERTY:
////                // History scrubbing. For Adobe products, hold shift while moving
////                // backward to go forward instead.
////                if (clockwise) {
////                    tap_code16(C(KC_Z));
////                } else {
////                    tap_code16(C(KC_Y));
////                }
////                break;
////            default:
////                // Switch between windows on Windows with alt tab.
////                if (clockwise) {
////                    if (!is_alt_tab_active) {
////                        is_alt_tab_active = true;
////                        register_code(KC_LALT);
////                    }
////                    alt_tab_timer = timer_read();
////                    tap_code16(KC_TAB);
////                } else {
////                    tap_code16(S(KC_TAB));
////                }
////                break;
////        }
////    } else if (index == 1) {
////        switch (biton32(layer_state)) {
////            case QWERTY:
////                // Scrolling with PageUp and PgDn.
////                if (clockwise) {
////                    tap_code(KC_PGDN);
////                } else {
////                    tap_code(KC_PGUP);
////                }
////                break;
////            default:
////                // Volume control.
////                if (clockwise) {
////                    tap_code(KC_VOLU);
////                } else {
////                    tap_code(KC_VOLD);
////                }
////                break;
////        }
////    }
////}
////#endif
