#include "DisjointSet.h"
#include <iostream>
#include <cassert>
using namespace std;

int main(){
    //DisjointSet s;

    /*
     *   you fill in here to set up the disjoint set
     */

    DisjointSet<int> s;
    s.createSet(1);
    s.createSet(2);
    s.createSet(4);
    s.createSet(5);
    s.createSet(6);
    s.createSet(7);

    s.unionSets(3, 5);
    s.unionSets(1, 6);

    s.createSet(8);
    s.createSet(9);


    assert(s.findSet(1) == s.findSet(6)); // 1 and 6 are connected.
    assert(s.findSet(3) != s.findSet(6)); // 3 and 6 are not connected.
    assert(s.findSet(1) == s.findSet(1)); // 1 and 1 are connected.
    assert(s.findSet(3) == s.findSet(5)); // 3 and 5 are connected.
    assert(s.findSet(3) != s.findSet(9)); // 3 and 9 are not connected.

}
