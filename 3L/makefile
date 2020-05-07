CXX=g++

all: queue.o stack.o

queue.o: queue.cpp queue.h
	$(CXX) -c queue.cpp

stack.o: stack.cpp stack.h
	$(CXX) -c stack.cpp

tests: queuetest stacktest

queuetest: queuetest.cpp queuetest1.cpp queuetest2.cpp queuetest3.cpp queuetest4.cpp queue.cpp queue.h
	$(CXX) queuetest.cpp queue.cpp -o queuetest
	$(CXX) queuetest1.cpp queue.cpp -o queuetest1
	$(CXX) queuetest2.cpp queue.cpp -o queuetest2
	$(CXX) queuetest3.cpp queue.cpp -o queuetest3
	$(CXX) queuetest4.cpp queue.cpp -o queuetest4








stacktest: stacktest.cpp stack.cpp stack.h
	$(CXX) stacktest.cpp stack.cpp -o stacktest
	$(CXX) stacktest1.cpp stack.cpp -o stacktest1
	$(CXX) stacktest2.cpp stack.cpp -o stacktest2
	$(CXX) stacktest3.cpp stack.cpp -o stacktest3
	$(CXX) stacktest4.cpp stack.cpp -o stacktest4
	$(CXX) stacktest5.cpp stack.cpp -o stacktest5



clean:
	rm -f queuetest stacktest queue.o stack.o
