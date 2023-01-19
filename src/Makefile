CC = gcc
FLAGS = -Wall -Werror -Wextra -lncurses -std=c11
FILES = main.c langton.c visualiser.c
BINNAME = ant
LIBNAME = libant

all: clean library
	$(CC) $(FLAGS) $(FILES) -o $(BINNAME)
	./ant

library:
	$(CC) $(FLAGS) -shared -o $(LIBNAME).so -fPIC $(FILES)
clean:
	rm -rf $(BINNAME) $(LIBNAME).so