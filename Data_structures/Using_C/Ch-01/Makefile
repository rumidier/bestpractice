CC = gcc

PROGRAMS = LinearSearch BinarySearch

all : $(PROGRAMS)

LinearSearch: LinearSearch.c
	$(CC) -Wall -o $@ $^

BinarySearch: BinarySearch.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
