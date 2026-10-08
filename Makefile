CC = gcc
CFLAGS = -Wall -Wextra -std=c99
PREFIX = $(HOME)/.local

conway: main.o life.o
	$(CC) $(CLAGS) -o conway main.o life.o 

main.o: main.c life.h
	$(CC) $(CLAGS) -c main.c

life.o: life.c life.h 
	$(CC) $(CLAGS) -c life.c

install: conway
	mkdir -p  $(PREFIX)/bin
	cp conway $(PREFIX)/bin/conway

clean:
	rm -f conway *.o

.PHONY: install clean

