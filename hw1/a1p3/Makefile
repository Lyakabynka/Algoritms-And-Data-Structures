CXX = g++
CPPFLAGS = -g -Wall

all: main

main: testLinkedList.o LinkedList.o
	gcc -o testLinkedList testLinkedList.o LinkedList.o

testLinkedList.o: testLinkedList.cpp LinkedList.h LinkedList.cpp
	gcc -c testLinkedList.cpp

LinkedList.o: LinkedList.cpp LinkedList.h
	gcc -c LinkedList.cpp

clean:
	rm -f *.o