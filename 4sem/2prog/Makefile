CC=g++

CFLAGS=-c -Wall

all: main

main: vector3.o main.o 
	$(CC) vector2.o main.o -o main

vector3.o: vector3.cpp
	$(CC) $(CFLAGS) vector2.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

