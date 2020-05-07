#include "HuffTree.h"
#include <iostream>
#include "string"
using namespace std;


int main() {
  //cout << "HuffmanCoder\n";

  // char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  //
  // string str = "supercalifragilisticexpialidocious";
  //
  // int a[] = {3, 3, 1, 2, 1, 1, 7, 3, 2, 2, 2, 3, 1, 2, 1};
  // char b[] = {'a', 'c','d','e','f','g','i','l','o','p','r','s','t','u','x'};
  // HuffTree h;
  // h.buildTree(b, a, 15);
  // //cout << "The Tree has been Built\n";
  // for (int i = 0; i < 15; i++) {
  //   cout << h.getCode(b[i]) << endl;
  // }




  HuffTree h;
  char c[7] = {'e', 'f', 'd', 'a', 'g'};
  int f[7] = {12, 4, 2, 3, 1};
  h.buildTree(c,f,5);

  cout << h.getCode('e') << endl;
  cout << h.getCode('f') << endl;
  cout << h.getCode('a') << endl;
  cout << h.getCode('g') << endl;
  cout << h.getCode('d') << endl;
}
