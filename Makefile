CC=g++
CFLAGS=-std=c++11

all: test
	./test

test: test.cpp
	$(CC) $(CFLAGS) -o test test.cpp

