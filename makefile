CC = gcc
CFLAGS = -I$(IDIR)
#CFLAGS had -lncurses, but was removed because of an error.

IDIR = ./include/
SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c

all: sudoku run clean


sudoku:
	$(CC) $(SOURCES) $(CFLAGS) -o $@

run:
	./sudoku

clean:
	rm sudoku
