// tests for find() and erase()

#include "map.h"
#include <cassert>
#include <iostream>
using namespace std;


int main(){
	Map<string, string>m1;
	Map<string, string>::Iterator it;

	m1.insert("21","1");
	m1.insert("4","1");
	m1.insert("1","1");
	m1.insert("2","1");
	m1.insert("35","1");
	m1.insert("3","1");
	m1.insert("28","1");
	m1.insert("31","1");
	m1.insert("12","1");
	m1.insert("33","1");
	m1.insert("45","1");
	m1.insert("49","1");
	m1.insert("17","1");
	m1.insert("39","1");
	m1.insert("44","1");
	m1.insert("4","1");
	m1.insert("28","1");

	cout << m1 << endl;

	cout << m1.size() << endl;

	assert(m1.size()==15);

	// elements in the set
	it = m1.find("17");

	m1.dump(cout);

	assert( it->key == "17");
	assert( it != m1.end());

	it = m1.find("12");
	assert( it->key == "12");
	assert( it != m1.end());

	it = m1.find("4");
	assert( it->key == "4");
	assert( it != m1.end());

	it = m1.find("1");
	assert( it->key == "1");
	assert( it != m1.end());

	it = m1.find("49");
	assert( it->key == "49");
	assert( it != m1.end());

	it = m1.find("21");
	assert( it->key == "21");
	assert( it != m1.end());


	it = m1.find("28");
	assert( it->key == "28");
	assert( it != m1.end());

	// elements not in the set
	it = m1.find("13");
	assert( it == m1.end());

	it = m1.find("18");
	assert( it == m1.end());

	it = m1.find("0");
	assert( it == m1.end());

	it = m1.find("42");
	assert( it == m1.end());

	it = m1.find("15");
	assert( it == m1.end());

	it = m1.find(" ");
	assert( it == m1.end());

}
