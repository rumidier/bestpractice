CC = gcc

PROGRAMS = ex17-1 ex17-2 ex17-3 A-score jango

all: $(PROGRAMS)

ex17-1: ex17-1.c
	$(CC) -Wall -o $@ $^

ex17-2: ex17-2.c
	$(CC) -Wall -o $@ $^

ex17-3: ex17-3.c
	$(CC) -Wall -o $@ $^

A-score: A-score.c
	$(CC) -Wall -o $@ $^

jango: jango.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
