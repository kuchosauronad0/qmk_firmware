/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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


#define PRODUCT         Comfy Thumbs
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0001
#define MANUFACTURER    Galactic Wafer
#define DESCRIPTION     Handwired Keyboard

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 12
#define MATRIX_COLS 6

// wiring of each half
#define MATRIX_COL_PINS { D4, C6, D7, E6, B4, B5 }
// Pin label on ProMicro   4   5   6   7   8   9
#define MATRIX_ROW_PINS { F5, F6, F7, B1, B3, B2, B6 }
// Pin label on ProMicro  A2  A1  A0  15  14  16  10

// WS2812 RGB LED strip input and number of LEDs
// Probably doesn't have rgb at this point
//#define RGB_DI_PIN D3
//#define RGBLED_NUM 12

