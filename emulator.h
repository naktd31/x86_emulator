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
void destroy_emu(Emulator* emu);
void dump_registers(Emulator* emu);

#endif
