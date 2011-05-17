CC = gcc

PROGRAMS = dlist

DLIST = \
	D-list/dlist-main.c \
	D-list/dlist.c

all: $(PROGRAMS)

dlist: $(DLIST)
	$(CC) -Wall -g -o $@ $^

clean:
	rm -rf $(PROGRAMS)
