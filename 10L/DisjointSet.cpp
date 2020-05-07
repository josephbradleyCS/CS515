
#include <map>
using namespace std;




/**
* Creates a singleton set from the parameter.
*/
template<KEY_TYPE KEY, VALUE_TYPE T>
void DisjointSet<KEY, T>::DisjointSet0::createSet(int a) {
  parents[x] = x;
  depth[x] = 0;
}

/**
* Finds and returns the representative of the set which contains the
* parameter. Implements path compression.
*/
template<KEY_TYPE KEY, VALUE_TYPE T>
int DisjointSet<KEY, T>::findSet(int p) {
  if (x != parents[x]) {
    parents[x] = find(parents[x]);
  }
  return parents[x];
}

/**
* Combines the sets which contain the parameters. Return false if two
 * parameters are already in the same set; otherwise, union the two sets
 * by rank and return true
*/
template<KEY_TYPE KEY, VALUE_TYPE T>
bool DisjointSet<KEY, T>::unionSets(int p, int q) {
  xid = findSet(x);
  yid = findSet(y);
  if (xid == yid) {
    return false;
  }

  if (depth[xid] > depth[yid]) {
    parents[yid] = xid;
  } else {
    parents[xid] = yid;
    if (depth[xid] == depth[yid]) {
      depth[yid]++;
    }
  }
  return true;
}
