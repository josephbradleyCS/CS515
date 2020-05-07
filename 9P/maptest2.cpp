// testing erase
#include <iostream>
#include <string>
#include <cassert>
#include "map.h"
using namespace std;

int main(){
	Map<int, int>m1;
	assert( m1.insert(12, 1) == true);
	assert( m1.insert(9, 1) == true);
	assert( m1.insert(6, 2) == true);
	assert( m1.insert(11, 2) == true);
	assert( m1.insert(15, 2) == true);
	assert( m1.insert(10, 2) == true);
	assert( m1.insert(8, 2) == true);
	assert( m1.insert(13, 1) == true);
	assert( m1.insert(7, 1) == true);
	assert( m1.insert(14, 1) == true);


	Map<int, int>::Iterator itt;
	itt = m1.begin();
	int i = 0;
	while (itt != m1.end()) {
		i++;
		if (i > 20) {break;}
		cout << itt->key << endl;
		itt++;
	}

	m1.erase(0);
	m1.erase(20);
	cout << m1 << endl;
	cout << "+++++++++++++++++++++++++++++"<< endl;

	m1.erase(10);
	cout << m1 << endl;
	cout << "+++++++++++++++++++++++++++++"<< endl;

	m1.erase(10);
	cout << m1 << endl;
	cout << "+++++++++++++++++++++++++++++"<< endl;


	m1.erase(6);
	cout << m1 << endl;
	cout << "+++++++++++++++++++++++++++++"<< endl;

	m1.erase(15);
	cout << m1 << endl;
	cout << "+++++++++++++++++++++++++++++"<< endl;

	m1.erase(12);
	cout << m1 << endl;
	cout << "+++++++++++++++++++++++++++++"<< endl;

	Map<int, int>::Iterator it;
	it = m1.begin();
	i = 0;
	while (it != m1.end()) {
		i++;
		if (i > 20) {break;}
		cout << it->key << endl;
		it++;
	}



}
