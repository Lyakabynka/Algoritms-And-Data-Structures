all: main

main: array_search.o
	g++ -o array_search array_search.o

main1.o: array_search.cpp
	g++ -c array_search.cpp

clean:
	rm -f array_search *.o