CC = gcc
CFLAGS = -Wall -Wextra -O2

all: test_vector test_list

test_vector: vector.o test_vector.o
	$(CC) $(CFLAGS) $^ -o $@

test_list: list.o test_list.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm *.o

depend:
	gcc *.c -MM > .depend

-include .depend
