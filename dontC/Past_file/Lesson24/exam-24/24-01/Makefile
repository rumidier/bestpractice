CC = gcc

PROGRAMS = str_count  int_count double_count exam_str_count

all: $(PROGRAMS)

str_count: str_count.c
	$(CC) -Wall -o $@ $^

int_count: int_count.c
	$(CC) -Wall -o $@ $^

double_count: double_count.c
	$(CC) -Wall -o $@ $^

exam_str_count: exam_str_count.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
