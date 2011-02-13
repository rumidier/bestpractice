CC = gcc

PROGRAMS = pointer_one pointer_two string_copy copy_arry2 addstring \
	   stringcmp swapptr

all: $(PROGRAMS)

pointer_one: pointer_one.c
	$(CC) -Wall -o $@ $^

pointer_two: pointer_two.c
	$(CC) -Wall -o $@ $^

string_copy: string_copy.c
	$(CC) -Wall -o $@ $^

copy_arry2: copy_arry2.c
	$(CC) -Wall -o $@ $^

addstring: addstring.c
	$(CC) -Wall -o $@ $^

stringcmp: stringcmp.c
	$(CC) -Wall -o $@ $^

swapptr: swapptr.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
