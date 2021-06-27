FILES_TO_CLEAN = *.o *.exe binary\*
RM = cmd.exe /C del

.PHONY: clean

all: main helloworld

main: main.c emulator.o get_code.o operations.o
	gcc -Wall -o main main.c emulator.o get_code.o operations.o

emulator.o: emulator.c
	gcc -c emulator.c

get_code.o: get_code.c
	gcc -c get_code.c

operations.o: operations.c
	gcc -c operations.c

helloworld: helloworld.asm
	nasm helloworld.asm -o binary\helloworld

clean:
	-$(RM) $(FILES_TO_CLEAN)
