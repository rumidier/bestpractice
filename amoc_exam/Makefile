CC = gcc

PROGRAMS = list

all: $(PROGRAMS)

list: list_main.c list_add.c list_print.c list_spec_delet.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
