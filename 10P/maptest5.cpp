// more tests cases for map::erase() method

#include <cassert>
#include <iostream>
#include "unorderedmap.h"

using namespace std;


int main(){
	UnorderedMap<string, string> m1;
	m1.insert("45", "a");
	m1.insert("21", "a");
	m1.insert("4","a");
	m1.insert("61","a");
	m1.insert("2","a");
	m1.insert("35","a");
	m1.insert("3","a");
	m1.insert("8","a");
	m1.insert("31","a");
	m1.insert("12","a");
	m1.insert("33","a");
	m1.insert("49","a");
	m1.insert("17","a");
	m1.insert("9","a");
	m1.insert("27","a");

	assert(m1.size()==15);

	// test output
	m1.dump(); // cout << m1;


	UnorderedMap<string, string>::Iterator it;

	// erase elements not in the set

	m1.erase("62");
	assert(m1.size()==15);

	m1.erase("13");
	assert(m1.size()==15);

	m1.erase("100");
	assert(m1.size()==15);

	m1.erase("1");
	assert(m1.size()==15);

	// erase elements in the set
	m1.erase("9");
	assert(m1.size()==14);
	m1.dump(); // cout << m1 << endl;
	cout << "+++++++++++++++++++++++++++++"<< endl;

	m1.erase("27");
	assert(m1.size()==13);
	m1.dump(); // cout << m1 << endl;
	cout << "+++++++++++++++++++++++++++++"<< endl;

	m1.erase("21");
	assert(m1.size()==12);
	m1.dump(); // cout << m1 << endl;
	cout << "+++++++++++++++++++++++++++++"<< endl;


	m1.erase("4");
	assert(m1.size()==11);
	m1.dump(); // cout << m1 << endl;
	cout << "+++++++++++++++++++++++++++++"<< endl;

	m1.erase("61");
	assert(m1.size()==10);
	m1.dump(); // cout << m1 << endl;
	cout << "+++++++++++++++++++++++++++++"<< endl;

	m1.erase("33");
	assert(m1.size()==9);
	m1.dump(); // cout << m1 << endl;
	cout << "+++++++++++++++++++++++++++++"<< endl;

	m1.erase("12");
	assert(m1.size()==8);
	m1.dump(); // cout << m1 << endl;
	cout << "+++++++++++++++++++++++++++++"<< endl;

	m1.erase("3");
	assert(m1.size()==7);
	m1.dump(); // cout << m1 << endl;
	cout << "+++++++++++++++++++++++++++++"<< endl;

	m1.erase("2");
	assert(m1.size()==6);
	m1.dump(); // cout << m1 << endl;
	cout << "+++++++++++++++++++++++++++++"<< endl;

	m1.erase("17");
	assert(m1.size()==5);
	m1.dump(); // cout << m1 << endl;
	cout << "+++++++++++++++++++++++++++++"<< endl;

	m1.erase("45");
	assert(m1.size()==4);
	m1.dump(); // cout << m1 << endl;
	cout << "+++++++++++++++++++++++++++++"<< endl;

	m1.erase("31");
	assert(m1.size()==3);
	m1.dump(); // cout << m1 << endl;
	cout << "+++++++++++++++++++++++++++++"<< endl;

	m1.erase("49");
	assert(m1.size() == 2);
	m1.dump(); // cout << m1 << endl;
	cout << "+++++++++++++++++++++++++++++"<< endl;

	m1.erase("35");
	assert(m1.size() == 1);
	m1.dump(); // cout << m1 << endl;
	cout << "+++++++++++++++++++++++++++++"<< endl;

	m1.erase("8");
	assert(m1.size() == 0 );
	m1.dump(); // cout << m1 << endl;
}
