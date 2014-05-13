# Project: Minesweeper

CC = gcc
CFLAGS = -O3 -W -Wall

build : Compiling Linking Clean

Linking :
	$(CC) $(CFLAGS) -o minesweeper main.o answers.o initializing.o minefinder.o printing.o

Compiling :
	$(CC) $(CFLAGS) -c main.c answers.c initializing.c minefinder.c printing.c

Clean :
	rm -f main.o answers.o initializing.o minefinder.o printing.o
