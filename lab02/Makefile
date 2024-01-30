CC=gcc
CFLAGS=-Wall -g -std=c99

all: vector

vector: vector.o test_vector.o
	$(CC) -o vector vector.o test_vector.o

bit_ops.o: vector.c vector.h
	$(CC) $(CFLAGS) -c vector.c

test_bit_ops.o: test_vector.c vector.h
	$(CC) $(CFLAGS) -c test_vector.c

clean:
	rm vector vector.o test_vector.o
	
	
