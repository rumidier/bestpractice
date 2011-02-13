CC = gcc

PROGRAMS = square three_mv type_arr mall_free three_string_print

all: $(PROGRAMS)

square: square.c
	$(CC) -Wall -o $@ $^

three_mv: three_mv.c
	$(CC) -Wall -o $@ $^

type_arr: type_arr.c
	$(CC) -Wall -o $@ $^

mall_free: mall_free.c
	$(CC) -Wall -o $@ $^

three_string_print: three_string_print.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
