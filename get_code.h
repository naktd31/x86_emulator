#ifndef _GET_CODE_H_
#define _GET_CODE_H_

#include <stdint.h>
#include "emulator.h"

uint8_t get_code8(Emulator* emu, int index);
int8_t get_sign_code8(Emulator* emu, int index);
uint32_t get_code32(Emulator* emu, int index);

#endif
