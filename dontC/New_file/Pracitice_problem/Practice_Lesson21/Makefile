CC = gcc

PROGRAMS = word_len average_score copy_word palin sachik jumin cat_str

all: $(PROGRAMS)

word_len: word_len.c
	$(CC) -Wall -o $@ $^

average_score: average_score.c
	$(CC) -Wall -o $@ $^

copy_word: copy_word.c
	$(CC) -Wall -o $@ $^

palin: palin.c
	$(CC) -Wall -o $@ $^

sachik: sachik.c
	$(CC) -Wall -o $@ $^

jumin: jumin.c
	$(CC) -Wall -o $@ $^

cat_str: cat_str.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
