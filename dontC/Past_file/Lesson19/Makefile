CC = gcc

PROGRAMS = que-19-1-1 th-mat que-19-1-2 que-19-2-1 que-19-2-2 que-19-4-1 que-19-4-2

all: $(PROGRAMS)

th-mat: th-mat.c
	$(CC) -Wall -o $@ $^

que-19-1-1: que-19-1-1.c
	$(CC) -Wall -o $@ $^

que-19-1-2: que-19-1-2.c
	$(CC) -Wall -o $@ $^

que-19-2-1: que-19-2-1.c
	$(CC) -Wall -o $@ $^

que-19-2-2: que-19-2-2.c
	$(CC) -Wall -o $@ $^

que-19-4-1: que-19-4-1.c
	$(CC) -Wall -o $@ $^

que-19-4-2: que19-4-2.c
	$(CC) -Wall -o $@ $^

celean:
	rm -rf $(PROGRAMS)
