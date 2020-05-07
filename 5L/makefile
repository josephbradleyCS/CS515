CXX=g++

all: charlist.o set.o setTest jumble

charlist.o: charlist.cpp charlist.h
	$(CXX) -g -c charlist.cpp

jumble: jumble.cpp charlist.o
	$(CXX) -g jumble.cpp charlist.o -o jumble

set.o: set.cpp set.h
	$(CXX) -g -c set.cpp

setTest: setTest.cpp set.o set.h
	$(CXX) setTest.cpp set.o -lgtest -lpthread -o setTest

clean:
	rm -f *.o settest jumble
	rm -f *.o charlist
