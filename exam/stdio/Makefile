CC = gcc

PROGRAMS = line-counter

all: $(PROGRAMS)

line-counter: line-counter.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
