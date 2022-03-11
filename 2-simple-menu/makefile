# Created: Petri Pihla
# Date : 03.03.2022

CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: final

final: main.o
	$(CC) $(CFLAGS) main.o -o program.exe -lncurses

main.o: main.c
	$(CC) $(CFLAGS) -c main.c 

clean:
	rm -f program.exe *.o
