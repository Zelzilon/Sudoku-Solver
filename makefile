CC = gcc
CFLAGS = -lncurses -I$(IDIR)

IDIR = ./include/
SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c

all: sudoku run clean

sudoku:
	$(CC) $(SOURCES) $(CFLAGS) -o $2

run:
	./sudoku

clean:
	rm sudoku