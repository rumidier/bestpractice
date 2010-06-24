CC = gcc

PROGRAMS = fib total totalb owe0

all: $(PROGRAMS)

fib: fib.c
	$(CC) -Wall -o $@ $^

total: total.c
	$(CC) -Wall -o $@ $^

totalb: totalb.c
	$(CC) -Wall -o $@ $^

owe0: owe0.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
