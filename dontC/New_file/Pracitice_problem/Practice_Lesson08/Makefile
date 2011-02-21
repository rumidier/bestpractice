CC = gcc

PROGRAMS = convert_data convert_byte char_check fah_to_cen sec_print yun_year 

all: $(PROGRAMS)

convert_data: convert_data.c
	$(CC) -Wall -o $@ $^

convert_byte: convert_byte.c
	$(CC) -Wall -o $@ $^

char_check: char_check.c
	$(CC) -Wall -o $@ $^

fah_to_cen: fah_to_cen.c
	$(CC) -Wall -o $@ $^

sec_print: sec_print.c
	$(CC) -Wall -o $@ $^

yun_year: yun_year.c
	$(CC) -Wall -o $@ $^

clean:
	rm -rf $(PROGRAMS)
