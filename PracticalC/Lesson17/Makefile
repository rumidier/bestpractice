CC = gcc

PROGRAMS = word find

all: $(PROGRAMS)

word: word.c
	$(CC) -Wall -o $@ $^

find: find.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
