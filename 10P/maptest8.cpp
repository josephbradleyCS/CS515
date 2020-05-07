// test must finish within 60 seconds on agate with our grading system.


#include <iostream>
#include <string>
#include <cassert>
#include <sstream>
#include "unorderedmap.h"
using namespace std;

int main(){
	UnorderedMap<string, string>m;
	int key;
	stringstream ss;
	srand(time(0));
	for (int i=1; i<1000000; i++){
		key = rand()%100000;
		m.insert(std::to_string(key), "hello");
	}

	m["Hi"] = "Me";
	cout << "Hi, " << m["Hi"] << endl;

	UnorderedMap<string, string>m1 = m;
}
