#include "emulator.h"

char* registers_name[] = {
    "EAX", "ECX", "EDX", "EBX", "ESP", "EBP", "ESI", "EDI"};

Emulator* create_emu(size_t size, uint32_t eip, uint32_t esp)
{
  Emulator* emu = malloc(sizeof(Emulator));
  emu->memory = malloc(size);

  memset(emu->registers, 0, sizeof(emu->registers));
  emu->eip = eip;
  emu->registers[ESP] = esp;

  return emu;
}

uint8_t get_code8(Emulator* emu, int index)
{
  return emu->memory[emu->eip + index];
}

int8_t get_sign_code8(Emulator* emu, int index)
{
  return (int8_t)emu->memory[emu->eip + index];
}

uint32_t get_code32(Emulator* emu, int index)
{
  int i;
  uint32_t ret = 0;
  for(i=0; i<4; i++){
    ret |= get_code8(emu, index+i) << (i * 8);
  }
  return ret;
}

int32_t get_sign_code32(Emulator* emu, int index)
{
  return (int32_t)get_code32(emu, index);
}

void set_memory8(Emulator* emu, uint32_t address, uint8_t value)
{
  emu->memory[address] = value;
}

void set_memory32(Emulator* emu, uint32_t address, uint32_t value)
{
  int i;
  for(i=0; i<4; i++){
    set_memory8(emu, address+i, value>>(i*8));
  }
}

uint32_t set_registers32(Emulator* emu, uint8_t index, uint32_t value)
{
  emu->registers[index] = value;
}

uint8_t get_memory8(Emulator* emu, uint32_t address)
{
  return emu->memory[address];
}

uint32_t get_memory32(Emulator* emu, uint32_t address)
{
  int i;
  uint32_t ret = 0;
  for(i=0; i<4; i++){
    ret |= get_memory8(emu, address+i) << (8*i);
  }
  return ret;
}

uint32_t get_registers32(Emulator* emu, uint8_t index)
{
  return emu->registers[index];
}

void destroy_emu(Emulator* emu)
{
  free(emu->memory);
  free(emu);
}

void dump_registers(Emulator* emu)
{
    int i;

    for (i = 0; i < REGISTERS_COUNT; i++) {
        printf("%s = %08x\n", registers_name[i], emu->registers[i]);
    }

    printf("EIP = %08x\n", emu->eip);
}
