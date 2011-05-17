CC = gcc

PROGRAMS = textview

all: $(PROGRAMS)

textview: list.c textview-main.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
