CC = gcc

PROGRAMS = exam-03-01 exam-03-02

all: $(PROGRAMS)

exam-03-01: exam-03-01.c fat.c
	$(CC) -Wall -o $@ $^

exam-03-02: exam-03-02.c facttail.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
