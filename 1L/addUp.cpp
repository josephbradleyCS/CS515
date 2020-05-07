#include <iostream>
using namespace std;

int main(){
	int sum = 0;
	int value;
	for (int i=0; i<100; i++){ // iterate from values 0 to 100
		cin >> value;   // read from stdin, "value" now contains the int value that was read in from cin
		sum += value;  // interger addition, aquivielnt to sum = sum + value
	}
  cout << "Total is " << sum << endl;  // output to stdout, << sends string/int values to the terminal
}
