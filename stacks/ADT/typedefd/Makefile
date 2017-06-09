CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Wpedantic -g

SRC = test_ADT.c stackADT.c
OBJ = ${SRC:.c=.o}
EXE = test_ADT

all: ${EXE}

# The first line clears out the suffix list, the second introduces all 
# suffixes which may be subject to implicit rules in this Makefile.
.SUFFIXES:
.SUFFIXES: .c .o

${OBJ}: stackADT.h

${EXE}: ${OBJ}
	${CC} -o $@ ${OBJ} ${CFLAGS}

.PHONY: clean

clean: 
	@echo cleaning up:
	@rm -rf ${EXE} ${OBJ}


