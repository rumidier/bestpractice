CC = gcc

PROGRAMS = thing call array-p ptr2 ptr3 init-a  tmp-name tmp2

all: $(PROGRAMS)

thing: thing.c
	$(CC) -Wall -o $@ $^

call: call.c
	$(CC) -Wall -o $@ $^

array-p: array-p.c
	$(CC) -Wall -o $@ $^

ptr2: ptr2.c
	$(CC) -Wall -o $@ $^

ptr3: ptr3.c
	$(CC) -Wall -o $@ $^

init-a: init-a.c
	$(CC) -Wall -o $@ $^

split: split.c
	$(CC) -Wall -o $@ $^

tmp-name: tmp-name.c
	$(CC) -Wall -o $@ $^

tmp2: tmp2.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)

