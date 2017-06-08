CFILES= hashtable.c
OBJ=$(CFILES:.c=.o)
HEADERS=
CC=gcc
CFLAGS=-Wall -Wextra -O2 -Wpedantic -g
LFLAGS=
EXE= ht

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $(LFLAGS) $^ -o $@ 

.SUFFIXES:
.SUFFIXES: .c .o
%.o: %.c $(HEADERS)
	gcc $(CFLAGS) -c -o $@ $< 

.PHONY: clean

clean:
	rm -vf *.o $(EXE)
