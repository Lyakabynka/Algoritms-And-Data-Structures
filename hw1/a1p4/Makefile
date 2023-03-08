CXX = g++
CPPFLAGS = -g -Wall

all: main

main: vectors1.o 
	$(CXX) $(CPPFLAGS) -o vectors1 vectors1.o

vectors1.o: vectors1.cpp
	$(CXX) $(CPPFLAGS) -c vectors1.cpp

clean:
	rm -f *.o