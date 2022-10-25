#pragma once
#include "quantum.h"
#ifdef ENCODER_ENABLE
//const uint16_t PROGMEM encoder_actions[2][9];
const uint16_t encoder_actions[2][9];
void encoder_update_user(uint8_t index, bool clockwise);
#endif
