CFLAGS = -Wall -Wextra -O2

all: test

test: vector.o test_sort.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm *.o

depend:
	gcc *.c -MM > .depend

-include .depend