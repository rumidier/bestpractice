CC = gcc

PROGRAMS = list

all: $(PROGRAMS)

list: list_main.c list_func.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
