CC = gcc
FLAGS = -Wall -Werror -Wextra -lncurses -std=c11
FILES = main.c
LIBFILES = langton.c visualiser.c
LIBNAME = libant
BINNAME = ant

all: game library
	./ant LLRR

game: clean
	$(CC) $(FILES) $(LIBFILES) -o $(BINNAME) $(FLAGS)
library:
	$(CC) $(FLAGS) -shared -o $(LIBNAME).so -fPIC $(FILES) $(LIBFILES)
clean:
	rm -rf $(BINNAME) $(LIBNAME).so *.o