CC = gcc

PROGRAMS = joshep linked2 namecard

all: $(PROGRAMS)

joshep: joshep.c
	$(CC) -Wall -o $@ $^

linked2: linked2.c
	$(CC) -Wall -o $@ $^

namecard: namecard.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
