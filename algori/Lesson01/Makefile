CC = gcc

PROGRMAS = prime1 prime2 prime3

all: $(PROGRMAS)

prime1: prime1.c
	$(CC) -Wall -o $@ $^

prime2: prime2.c
	$(CC) -Wall -lm -o $@ $^

prime3: prime3.c
	$(CC) -Wall -lm -o $@ $^

clean:
	rm -rf $(PROGRMAS)
