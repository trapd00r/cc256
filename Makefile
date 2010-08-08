CC = gcc
CCFLAGS = -Wall -pedantic -ansi

all: cc256

cc256:  src/cc256.c
	$(CC) -o bin/cc256 obj/cc256.o

install:
	cp bin/cc256 /usr/local/bin

uninstall:
	rm -fv /usr/local/bin/cc256

cc256.o: src/cc256.c
	$(CC) $(CCFLAGS) -c src/cc256.c -o obj/cc256.o

