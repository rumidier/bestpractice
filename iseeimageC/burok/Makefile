CC = gcc

PROGRAMS = union time kakdo 208 ran_num revtxt

all: $(PROGRAMS)

union: union.c
	$(CC) -Wall -o $@ $^

time: time-200.c
	$(CC) -Wall -o $@ $^

kakdo: kakdo.c
	$(CC) -Wall -o $@ -lm $^

208: 208.c
	$(CC) -Wall -o $@ $^

ran_num: ran_num.c
	$(CC) -Wall -o $@ $^

revtxt: revtxt.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
