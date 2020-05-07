CXX=g++

all: set.o

set.o: set.cpp  set.h
	$(CXX) -c -g set.cpp

setTest: setTest.cpp  set.o set.h
	$(CXX) setTest.cpp set.o -lgtest -lpthread -o setTest
	./setTest

setTest1: setTest1.cpp set.o set.h
	$(CXX) setTest.cpp set.o -lgtest -lpthread -o setTest1
	./setTest1

clean:
	rm -f *.o  setTest
