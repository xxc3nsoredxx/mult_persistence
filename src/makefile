OBJS = mp.o
CC = gcc
CFLAGS = -c -Wall -Wextra --pedantic-errors -std=c89
LFLAGS = -lgmp

all: mp

mp: $(OBJS)
	$(CC) $(OBJS) -o mp $(LFLAGS)

mp.o: mp.c
	$(CC) $(CFLAGS) mp.c
