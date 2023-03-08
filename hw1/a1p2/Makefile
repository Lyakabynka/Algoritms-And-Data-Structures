CXX = g++
CPPFLAGS = -g -Wall

all: main

main: testStack.o
	$(CXX) $(CPPFLAGS) -o testStack testStack.o

testStack.o: testStack.cpp Stack.h
	$(CXX) $(CPPFLAGS) -c testStack.cpp

clean:
	rm -f *.o