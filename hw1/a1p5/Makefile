CXX = g++
CPPFLAGS = -g -Wall

all: main

main: vectors2.o 
	$(CXX) $(CPPFLAGS) -o vectors2 vectors2.o

vectors2.o: vectors2.cpp
	$(CXX) $(CPPFLAGS) -c vectors2.cpp

clean:
	rm -f *.o