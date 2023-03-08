CXX = g++
CPPFLAGS = -Wall

all: testWindGauge

testWindGauge: testWindGauge.o WindGauge.o
	g++ -o testWindGauge testWindGauge.o WindGauge.o

testWindGauge.o: testWindGauge.cpp WindGauge.h
	g++ -c testWindGauge.cpp 

WindGauge.o: WindGauge.cpp WindGauge.h
	g++ -c WindGauge.cpp

clean:
	rm -f testWindGauge *.o