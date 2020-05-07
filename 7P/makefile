CXX=g++ -g

all: map.o mapTest maptest1 maptest2 maptest3 maptest4 maptest5 maptest6 maptest7 maptest8

map.o: map.cpp map.h
	$(CXX) -c map.cpp

mapTest: mapTest.cpp map.o map.h
	$(CXX) mapTest.cpp map.o -lgtest -lpthread -o mapTest

maptest1: maptest1.cpp map.o
	$(CXX) maptest1.cpp map.o -o maptest1

maptest2: maptest2.cpp map.o
	$(CXX) maptest2.cpp map.o -o maptest2

maptest3: maptest3.cpp map.o
	$(CXX) maptest3.cpp map.o -o maptest3

maptest4: maptest4.cpp map.o
	$(CXX) maptest4.cpp map.o -o maptest4

maptest5: maptest5.cpp map.o
	$(CXX) maptest5.cpp map.o -o maptest5

maptest6: maptest6.cpp map.o
	$(CXX) maptest6.cpp map.o -o maptest6

maptest7: maptest7.cpp map.o
	$(CXX) maptest7.cpp map.o -o maptest7

maptest8: maptest8.cpp map.o
	$(CXX) maptest8.cpp map.o -o maptest8



clean:
	rm -f *.o mapTest
	rm -f *.o maptest1
	rm -f *.o maptest2
	rm -f *.o maptest3
	rm -f *.o maptest4
	rm -f *.o maptest5
	rm -f *.o maptest6
	rm -f *.o maptest7
	rm -f *.o maptest8
