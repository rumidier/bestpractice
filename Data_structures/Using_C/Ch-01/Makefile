CC = gcc

PROGRAMS = LinearSearch BinarySearch BSWorstOpCount

all : $(PROGRAMS)

LinearSearch: LinearSearch.c
	$(CC) -Wall -o $@ $^

BinarySearch: BinarySearch.c
	$(CC) -Wall -o $@ $^

BSWorstOpCount: BSWorstOpCount.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
