CC=gcc
CFLAGS=-Wall -Wextra -O2 -Wpedantic -g
LFLAGS=

CFILES= stack.c stack_test.c
OBJ=$(CFILES:.c=.o)
HEADERS= stack.h
EXE= stack-test

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(LFLAGS) $^ -o $@ 

.SUFFIXES:
.SUFFIXES: .c .o
%.o: %.c $(HEADERS)
	gcc $(CFLAGS) -c -o $@ $< 

.PHONY: clean

clean:
	rm -vf *.o $(EXE)
