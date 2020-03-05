/*
Copyright 2019 kuchosauronad0

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0001
#define MANUFACTURER    kuchosauronad0
#define PRODUCT         Planckenstein
#define DESCRIPTION     A handwired planck keyboard

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

#define ENCODERS_PAD_A { F4 } //PIN A3
#define ENCODERS_PAD_B { F5 } //PIN A2

#define MATRIX_ROW_PINS { F6, F7, B1, B3 }
//                    PIN A1, A0, 15, 14
#define MATRIX_COL_PINS { B2, B6, B4, E6, D7, C6, D4, D0, D1, D2, D3, B5 }
//                    PIN 16, 10, 8,   7,  6,  5,  4,  3,  2,RXI,TXO, 9
#define UNUSED_PINS { B0, D5 }
//                PIN RX_LED,TX_LED
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE
