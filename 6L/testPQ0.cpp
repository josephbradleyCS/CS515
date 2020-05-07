#include "PQueue0.h"
#include <cstdlib>
#include <cassert>
using namespace std;

int main(){

    // 8 2 2 1 3 9 10
    int i, x;

    // cout << "Test 0: Enqueuing..." << endl;
    int a0[4] = {24, 55, 22, 31};
    PQueue q0(a0, 4);
    //exit(-1);
    assert(q0.size()==4);
    // cout << "Test 0: Dequeuing..." << endl;
    for( i = 1; i <= 4; i++ ) {
        x = q0.findMin();
        q0.deleteMin();
        cout << x << " ";

        //exit(-1);
        ///// cout << x << " ";
    }
     cout << endl;

     cout << "Test 1: Enqueuing..." << endl;
    int a1[20] = {24, 55, 22, 31, 4, 50, 10, 13, 42, 53, 67, 89, 76, 30, 51, 17, 98, 2, 31, 29};
    PQueue q1(a1, 20);
    assert(q1.size()==20);
     cout << "Test 1: Dequeuing..." << endl;
    for( i = 1; i < 20; i++ ) {
        x = q1.findMin();
        q1.deleteMin();
        cout << x << " ";
    }
     cout << endl;

    PQueue q2;
    cout << "Test 2: Enqueuing..." << endl;

    int a3[50]={91, 3, 14, 9, 52, 52, 82, 22, 93, 66,
                92, 99, 35, 57, 98, 22, 1, 23, 88, 53,
                25, 10, 57, 55, 45, 13, 14, 34, 38, 26,
                82, 9, 21, 20, 31, 54, 56, 99, 77, 71,
                67, 2, 50, 36, 59, 67, 41, 6, 79, 43};

    for( i = 0; i < 50; i++) {
        q2.insert(a3[i]);
    }
    assert(q2.size() == 50);
    cout << "Test 2: Dequeuing..." << endl;
    for( i = 0; i < 50; i++ ) {
        x = q2.findMin();
        q2.deleteMin();
        cout << x << " ";
    }
    cout << endl;

    cout << "Test 3:" << endl;

    assert(q2.size() == 0);
    cout << "1" << endl;
    q2.insert(3); // cout << "inserting 3\n";
    q2.insert(10); // cout << "inserting 10\n";
    q2.insert(9); // cout << "inserting 9\n";

    assert(q2.findMin()==3);
    cout << "2" << endl;

    q2.deleteMin(); // cout << "delete min (3)\n";
    assert(q2.findMin()==9);
    q2.deleteMin(); // cout << "delete min (9)\n";
    // cout << "size = " << q2.size() << endl;
    q2.insert(8); // cout << "inserting 8\n";
    q2.insert(2); // cout << "inserting 2\n"; 2 2 9 2 10 9
    // cout << "size = " << q2.size() << endl;
    assert(q2.findMin()==2);
    q2.deleteMin(); // cout << "delete min (2)\n";
    // cout << "size = " << q2.size() << endl;
    assert(q2.findMin()==8);
    q2.deleteMin();
    // cout << "size = " << q2.size() << endl;
    assert(q2.findMin()==10);
    q2.deleteMin();
    // cout << "size = " << q2.size() << endl;
    assert(q2.isEmpty() == true);
}

// void dump (PQueue a) {
//   for (int i = 1; i < a.size(); i++) {
//     // cout << a._array[i];
//   }
// }
