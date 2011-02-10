CC = gcc

PROGRAMS = bubble bubble_count double_arr string_sort string_search

all: $(PROGRAMS)

bubble: bubble.c
	$(CC) -Wall -o $@ $^

bubble_count: bubble_count.c
	$(CC) -Wall -o $@ $^

bubble_arr: bubble_arr.c
	$(CC) -Wall -o $@ $^

string_sort: string_sort.c
	$(CC) -Wall -o $@ $^

string_search: string_search.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
