
#include <iostream>
#include <string>
#include <cassert>
#include "unorderedmap.h"
using namespace std;

int main(){

	UnorderedMap<string, string>m1;

	//cout << m1;
	assert( m1.insert("12", "1") == true);
	assert( m1.insert("9", "1") == true);
	assert( m1.insert("6", "2") == true);
	assert( m1.insert("11", "2") == true);
	assert( m1.insert("15", "2") == true);
	assert( m1.insert("10", "2") == true);
	assert( m1.insert("8", "2") == true);
	assert( m1.insert("13", "1") == true);
	assert( m1.insert("7", "1") == true);
	assert( m1.insert("14", "1") == true);
  //cout << m1;

	m1.dump();


	m1["I'm"] = "here";
	m1["You're"] = "there";

	cout << "I'm " << m1["I'm"] << endl;
	cout << "You're " << m1["You're"] << endl;


	// UnorderedMap<string, string>::Iterator it = m1.find("7");
	//
	// int i = 0;
	// while (it != m1.end()) {
	// 	if (i > 30) {break;} else {i++;}
	// 	cout << "Key: "<< it->key << "   Data: " << it->data << endl;
	//
	// 	it++;
	// }


	m1.dump();




}
