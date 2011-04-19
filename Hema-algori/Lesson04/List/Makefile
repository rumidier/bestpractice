CC = gcc

PROGRAMS = list_main

all: $(PROGRAMS)

list_main: list_main.c list.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
