CC = gcc

PROGRAMS = simple term

all: $(PROGRAMS)

simple: simple.c
	$(CC) -Wall -o $@ $^

term: term.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
