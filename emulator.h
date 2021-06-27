#ifndef _EMULATOR_H_
#define _EMULATOR_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define MEMORY_SIZE (1024 * 1024)
enum Register { EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI, REGISTERS_COUNT };

typedef struct {
  uint32_t registers[REGISTERS_COUNT];
  uint32_t eflags;

  uint8_t* memory;
  uint32_t eip;
} Emulator;


Emulator* create_emu(size_t size, uint32_t eip, uint32_t esp);
uint8_t get_code8(Emulator* emu, int index);
int8_t get_sign_code8(Emulator* emu, int index);
uint32_t get_code32(Emulator* emu, int index);
int32_t get_sign_code32(Emulator* emu, int index);
void set_memory8(Emulator* emu, uint32_t address, uint8_t value);
void set_memory32(Emulator* emu, uint32_t address, uint32_t value);
uint32_t set_registers32(Emulator* emu, uint8_t index, uint32_t value);
uint8_t get_memory8(Emulator* emu, uint32_t address);
uint32_t get_memory32(Emulator* emu, uint32_t address);
uint32_t get_registers32(Emulator* emu, uint8_t index);
void destroy_emu(Emulator* emu);
void dump_registers(Emulator* emu);

#include "modrm.h"

#endif
