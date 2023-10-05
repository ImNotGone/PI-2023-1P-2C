CC=gcc
CCFLAGS=-Wall -Wextra -Werror -pedantic -std=c99 -g

all: ej1 ej2 ej3

ej1: ej1.o
	$(CC) $(CCFLAGS) -o $@ $@.o

ej2: ej2.o
	$(CC) $(CCFLAGS) -o $@ $@.o

ej3: ej3.o
	$(CC) $(CCFLAGS) -o $@ $@.o

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f *.o
	rm -f ej1 ej2 ej3

.PHONY: all clean
