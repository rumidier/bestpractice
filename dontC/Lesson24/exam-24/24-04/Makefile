CC = gcc

PROGRAMS = compile str_len_compare ex_len_compare

all: $(PROGRAMS)

compile: compile.c
	$(CC) -Wall -o $@ $^

str_len_compare: str_len_compare.c
	$(CC) -Wall -o $@ $^

ex_len_compare: ex_len_compare.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
