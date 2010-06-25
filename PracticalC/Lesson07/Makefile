CC = gcc

PROGRAMS = calc1 calc2 good

all: $(PROGRAMS)

cal1: cal1.c
	$(CC) -Wall -o $@ $^

calc2: calc2.c
	$(CC) -Wall -o $@ $^

good: good.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
