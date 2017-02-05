CFILES= linkedlist.c test_linkedlist.c
CC=gcc
CFLAGS=-Wall -Wextra -O2 -Wpedantic -g
EXE=tests

O=$(CFILES:.c=.o)

${EXE}: clean ${O}
	${CC} ${CFLAGS} -o $@ ${O} 

.SUFFIXES: .c .o

%.o: %.c
	gcc ${CFLAGS} -c -o $@ $< 

clean:
	rm -vf *.o ${EXE}


