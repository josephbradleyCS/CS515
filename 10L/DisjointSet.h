/* Sets are disjoint if the sets are all pairwise disjoint.                  *
 * For example, the sets {1,2}, {3,6}, {10,41} are  disjoint,                *
 * whereas the sets {3,2}, {2,8} are not, due to the common element 2.       *
 * A disjoint set is a set containing disjoint sets. Another name   		 *
 * for this data structure is the union-find.                                *
 *
 * This particular implementation uses an uptree that is built with an       *
 * underlying std::map. All elements are int type                            *
 *                                                                           *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */



#include <map>
using namespace std;

template<typename T>

class DisjointSet{
public:
    std::map<T, T> parents; // access to set representitives
    std::map<T, int> depths; // used for path compression

    DisjointSet(){};

    /**
	 * Creates a singleton set from the parameter.
	 */
    void createSet(T x) {
      parents[x] = x;
      //T a;
      depths[x] = 0;
    }

    /**
	 * Finds and returns the representative of the set which contains the
	 * parameter. Implements path compression.
	 */
    T findSet(T x) {
      if (x != parents[x]) {
        parents[x] = findSet(parents[x]);
      }
      return parents[x];
    }

    /**
	 * Combines the sets which contain the parameters. Return false if two
     * parameters are already in the same set; otherwise, union the two sets
     * by rank and return true
	 */
    bool unionSets(T p, T q) {
      T xid = findSet(p);
      T yid = findSet(q);
      if (xid == yid) {
        return false;
      }

      if (depths[xid] > depths[yid]) {
        parents[yid] = xid;
      } else {
        parents[xid] = yid;
        if (depths[xid] == depths[yid]) {
          depths[yid]++;
        }
      }
      return true;
    }

};

//
