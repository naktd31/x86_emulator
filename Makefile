FILES_TO_CLEAN = *.o *.exe binary\*
RM = cmd.exe /C del

all: main helloworld modrm-test

main: main.c emulator.o operations.o modrm.o
	gcc -Wall -o main main.c emulator.o operations.o modrm.o

emulator.o: emulator.c
	gcc -c emulator.c

#get_code.o: get_code.c
#	gcc -c get_code.c

operations.o: operations.c
	gcc -c operations.c

modrm.o: modrm.c
	gcc -c modrm.c

helloworld: helloworld.asm
	nasm helloworld.asm -o binary\helloworld

modrm-test: modrm-test.asm
	nasm modrm-test.asm -o binary\modrm-test

clean:
	-$(RM) $(FILES_TO_CLEAN)
