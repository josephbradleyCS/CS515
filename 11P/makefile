CXX=g++ -g

all: maptest0  maptest1 maptest2 maptest3 maptest4 maptest5 maptest6 maptest7 maptest8

maptest0: map.h map.cpp maptest0.cpp
	$(CXX)  maptest0.cpp -o maptest0

#
# mapTest: mapTest.cpp map.h
# 	$(CXX) mapTest.cpp -lgtest -lpthread -o mapTest

maptest1: maptest1.cpp map.h
	$(CXX) maptest1.cpp -o maptest1

maptest2: maptest2.cpp map.h
	$(CXX) maptest2.cpp -o maptest2

maptest3: maptest3.cpp map.h
	$(CXX) maptest3.cpp -o maptest3

maptest4: maptest4.cpp map.h
	$(CXX) maptest4.cpp -o maptest4

maptest5: maptest5.cpp map.h
	$(CXX) maptest5.cpp -o maptest5

maptest6: maptest6.cpp map.h
	$(CXX) maptest6.cpp -o maptest6

maptest7: maptest7.cpp map.h
	$(CXX) maptest7.cpp -o maptest7

maptest8: maptest8.cpp map.h
	$(CXX) maptest8.cpp -o maptest8



clean:
	rm -f *.o  maptest0
