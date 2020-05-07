CXX=g++

all: HuffTree.o HuffmanCoder testHuff1

HuffTree.o: PQueue.h PQueue.cpp HuffTree.cpp HuffTree.h
	$(CXX) -c -g HuffTree.cpp

HuffmanCoder: HuffmanCoder.cpp HuffTree.o
	$(CXX) -g HuffmanCoder.cpp HuffTree.o -o HuffmanCoder



clean:
	rm -f *.o HuffTree.o HuffmanCoder
