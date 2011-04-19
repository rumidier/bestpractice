CC = gcc

PROGRAMS = simple_list

all: $(PROGRAMS)

simple_list: simple_list.c simple_func.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
