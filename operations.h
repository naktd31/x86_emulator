#ifndef _OPERATIONS_H_
#define _OPERATIONS_H_

#include "emulator.h"
//#include "get_code.h"
#include "modrm.h"

typedef void instruction_func_t(Emulator*);
extern instruction_func_t* instructions[256];

void mov_r32_imm32(Emulator* emu);
void mov_rm32_imm32(Emulator* emu);
void mov_rm32_r32(Emulator* emu);
void mov_r32_rm32(Emulator* emu);
void add_rm32_r32(Emulator* emu);
void sub_rm32_imm8(Emulator* emu, ModRM* modrm);
void code_83(Emulator* emu);
void inc_rm32(Emulator* emu, ModRM* modrm);
void code_ff(Emulator* emu);
void short_jump(Emulator* emu);
void near_jump(Emulator* emu);
void init_instructions(void);

#endif
