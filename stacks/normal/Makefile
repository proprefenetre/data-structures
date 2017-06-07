CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Wpedantic -g

SRC = calc.c stack.c
HEADER = stack.h
OBJ = ${SRC:.c=.o}
EXE = calc

all: ${EXE}

# The first line clears out the suffix list, the second introduces all 
# suffixes which may be subject to implicit rules in this Makefile.
.SUFFIXES:
.SUFFIXES: .c .o

${OBJ}: ${HEADER}

${EXE}: ${OBJ}
	${CC} -o $@ ${OBJ} ${CFLAGS}

.PHONY: clean

clean: 
	@echo cleaning up:
	@rm -rf ${EXE} ${OBJ}


