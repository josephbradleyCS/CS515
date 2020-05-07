#include <string>
#include "unorderedmap.h"

using namespace std;


int main(){
   UnorderedMap <double, string> m;
   m.insert(10, "hello");
   m.insert(15, "World");
   cout << "here\n";
   UnorderedMap<double, string>::Iterator it = m.find(10);
   cout << "found 10\n";
   UnorderedMap<double, string>::Iterator it2 = m.find(15);

   it++;

   //assert(it == it2);


   cout << "found 15\n";
   m.dump();
   cout << it->data << " " << it2->data << endl;
   cout << endl << endl << endl;
}
