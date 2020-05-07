#include "PQueue0.h"
#include <cstdlib>
#include <cassert>
#include <vector>
#include <queue>
using namespace std;

int main(){
    // 8 2 2 1 3 9 10
    std::priority_queue<int, std::vector<int>, std::greater<int>> ref;
    // create something as PQueue
    auto pqueue;
    for( int i = 0; i < 10000000; i++ ) {
      srand(i);
      int rand = rand() % 617;
      bool ins = rand() % 2;

      if( ins ) {
        pqueue.insert(rand);
        ref.push(rand);

        assert(pqueue.top() == pqueue.getMin());
      } else {
        if( !ref.empty() ) {
          ref.pop();
          pqueue.removeMin();
          assert(pqueue.top() == ref.top());
        }
      }
    }
}
