CC = gcc

PROGRAMS = simple term twice q_zero two div

all: $(PROGRAMS)

simple: simple.c
	$(CC) -Wall -o $@ $^

term: term.c
	$(CC) -Wall -o $@ $^

twice: twice.c
	$(CC) -Wall -o $@ $^

q_zero: q_zero.c
	$(CC) -Wall -o $@ $^

two: two.c
	$(CC) -Wall -o $@ $^

div: div.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
