
#include <iostream>
#include <string>
#include <cassert>
#include "map.h"
using namespace std;

int main(){
	cout << "hi\n";
	Map<string, string>m1;

	cout << m1;

	assert( m1.insert("12", "1") == true);

	cout << m1 << endl;

	assert( m1.insert("9", "1") == true);

	cout << m1 << endl;

	assert( m1.insert("6", "2") == true);

	cout << m1 << endl;

	assert( m1.insert("11", "2") == true);

	cout << m1 << endl;

	assert( m1.insert("15", "2") == true);

	cout << m1 << endl;

	assert( m1.insert("10", "2") == true);

	cout << m1 << endl;

	assert( m1.insert("8", "2") == true);

	cout << m1 << endl;

	assert( m1.insert("13", "1") == true);

	cout << m1 << endl;

	assert( m1.insert("7", "1") == true);
	cout << "now\n";

	cout << m1 << endl;

	assert( m1.insert("14", "1") == true);

	cout << "FRICK\n";
  cout << m1;





}
