// test for copy constructor and assignment operator

#include <iostream>
#include <string>
#include <cassert>
#include "unorderedmap.h"
using namespace std;

int main(){
	UnorderedMap<string, string>m1;
	assert( m1.insert("a", "boy") == true);
	assert( m1.insert("k", "kite") == true);
	assert( m1.insert("z", "zoo") == true);
	assert( m1.insert("b", "breeze") == true);
	assert( m1.insert("r", "fire") == true);
	assert( m1.insert("d", "rose") == true);
	assert( m1.insert("c", "ice") == true);
	assert( m1.insert("c", "car") == false);

	UnorderedMap<string, string>m2(m1);
	cout << "++++++++new tree++++++++++++" << endl;
	 m1.dump(); // cout << m2 << endl;
	cout << "++++++++new tree again++++++++++++" << endl;
	//m2(m1);
	m2.dump(); // cout << m2 << endl;
	exit(0);

	assert(m1.size()==7);
	assert(m2.size()==7);

	m1.erase("c");
	m2["c"] = "cute";

	assert(m1.size()==6);
	assert(m2.size()==7);
	cout << "++++++++tree 1++++++++++++" << endl;
	 m1.dump(); // cout << m1 << endl;
	cout << "++++++++tree 2++++++++++++" << endl;
	 m1.dump(); // cout << m2 << endl;

	m2.insert("haha", "me here");
	cout << "++++++++new tree again++++++++++++" << endl;
	m2 = m1;
	 m1.dump(); // cout << m2 << endl;

}
