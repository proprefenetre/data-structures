CC=gcc
CFLAGS=-Wall -Wextra -O2 -Wpedantic -g
LFLAGS= -lm

CFILES= calc.c stack.c
OBJ=$(CFILES:.c=.o)
HEADERS= stack.h
EXE= calc-test

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(LFLAGS) $^ -o $@ 

.SUFFIXES:
.SUFFIXES: .c .o
%.o: %.c $(HEADERS)
	gcc $(CFLAGS) -c -o $@ $< 

.PHONY: clean

clean:
	rm -vf *.o $(EXE)
