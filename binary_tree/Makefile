# $@ (full target name of the current target)
# $? (returns the dependencies that are newer than the current target)
# $* (returns the text that corresponds to % in the target)
# $< (name of the first dependency)
# $^ (name of all the dependencies with space as the delimiter)

CFILES=
CC=gcc
CFLAGS=-Wall -Wextra -O2 -Wpedantic -g
EXE=

O=$(CFILES:.c=.o)

${EXE}: clean ${O}
	${CC} ${CFLAGS} -o $@ ${O} 

.SUFFIXES: .c .o

%.o: %.c
	gcc ${CFLAGS} -c -o $@ $< 

clean:
	rm -vf *.o ${EXE}


