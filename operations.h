#ifndef _OPERATIONS_H_
#define _OPERATIONS_H_

#include "emulator.h"
#include "get_code.h"

typedef void instruction_func_t(Emulator*);
extern instruction_func_t* instructions[256];

void mov_r32_imm32(Emulator* emu);
void short_jump(Emulator* emu);
void near_jump(Emulator* emu);
void init_instructions(void);

#endif
