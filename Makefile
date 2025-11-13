CC = gcc
CFLAGS = -Wall -Wextra -std=c99

arena: main.c arena.c arena.h
	$(CC) $(CFLAGS) -o arena main.c arena.c

clean:
	rm -f arena

test: arena
	./arena
