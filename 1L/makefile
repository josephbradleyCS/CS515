CXX=g++
VAR1=foobar

all: hello addUp results


hello: hello.cpp
	$(CXX)  hello.cpp -o hello

addUp: addUp.cpp
	$(CXX) addUp.cpp -o addUp >> results.txt

results:
	$ ./addUp < myNumbers > results.txt

clean:
	rm -f *.o hello
	rm -f *.o addUp
	rm -f results.txt
