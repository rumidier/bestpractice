CC = gcc

PROGRAMS = wordlen score str palin sacik jumin jumin2

all: $(PROGRAMS)

wordlen: wordlen.c
	$(CC) -Wall -o $@ $^

score: score.c
	$(CC) -Wall -o $@ $^

str: str.c
	$(CC) -Wall -o $@ $^

palin: palin.c
	$(CC) -Wall -o $@ $^

sacik: sacik.c
	$(CC) -Wall -o $@ $^

jumin: jumin.c
	$(CC) -Wall -o $@ $^

jumin2: jumin2.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
