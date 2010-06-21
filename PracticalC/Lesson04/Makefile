CC = gcc

PROGRAMS = simple term twice q_zero

all: $(PROGRAMS)

simple: simple.c
	$(CC) -Wall -o $@ $^

term: term.c
	$(CC) -Wall -o $@ $^

twice: twice.c
	$(CC) -Wall -o $@ $^

q_zero: q_zero.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
