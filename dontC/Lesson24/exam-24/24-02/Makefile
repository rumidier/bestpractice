CC = gcc

PROGRAMS = char_point int_point string_point

all: $(PROGRAMS)

char_point: char_point.c
	$(CC) -Wall -o $@ $^

int_point: int_point.c
	$(CC) -Wall -o $@ $^

string_point: string_point.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
