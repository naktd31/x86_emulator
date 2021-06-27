#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "emulator.h"
#include "get_code.h"
#include "operations.h"

int main(int argc, char* argv[])
{
  FILE* binary;
  Emulator* emu;

  if(argc != 2){
    printf("usage: px86 filename\n");
    return 1;
  }

  emu = create_emu(MEMORY_SIZE, 0x0000,0x7c00);

  binary = fopen(argv[1],"rb");
  if(binary == NULL){
    printf("%s file is not opened.\n", argv[1]);
    return 1;
  }

  fread(emu->memory, 1, 0x200, binary);
  fclose(binary);

  init_instructions();
  while(emu->eip < MEMORY_SIZE){
    uint8_t code = get_code8(emu, 0);
    if(instructions[code] == NULL){
      printf("\n\nNot Implemented: %x\n", code);
      break;
    }

    instructions[code](emu);
    if(emu->eip == 0x00){
      printf("\n\nend of program. \n\n");
      break;
    }
  }

  dump_registers(emu);
  destroy_emu(emu);
  return 0;
}
