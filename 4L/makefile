CXX=g++

all: queue.o queueTest

queue.o: queue.cpp queue.h
	$(CXX) -c -g queue.cpp

queueTest: queueTest_golden.cpp queue.cpp queue.h
	$(CXX) -g queueTest_golden.cpp queue.cpp -lgtest -lpthread -o queueTest

clean:
	rm -f queueTest queue.o
