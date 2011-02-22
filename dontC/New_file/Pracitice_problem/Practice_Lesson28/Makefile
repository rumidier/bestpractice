CC = gcc

PROGRAMS = ex01 ex02 src_dest_copy copy_array str_plus search_word swap_p

all: $(PROGRAMS)

ex01: ex01.c
	$(CC) -Wall -o $@ $^

ex02: ex02.c
	$(CC) -Wall -o $@ $^

src_dest_copy: src_dest_copy.c
	$(CC) -Wall -o $@ $^

copy_array: copy_array.c
	$(CC) -Wall -o $@ $^

str_plus: str_plus.c
	$(CC) -Wall -o $@ $^

search_word: search_word.c
	$(CC) -Wall -o $@ $^

swap_p: swap_p.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
