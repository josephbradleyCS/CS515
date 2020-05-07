
#include <iostream>
#include <list>
#include <iterator>
#include <map>
#include <string>
#include <fstream>
#include <queue>
#include <stack>
#include <utility>
#include <tuple>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
#include "DisjointSet.h"

using namespace std;


int main(int argc, char* argv[]) {

    //cout << "argv[0]: " << argv[0] << endl;
    //cout << "argc: " << argc << endl;

    string begin = "";

    if (argc != 2) {
      cout << "wrong number of args";
      exit(0);
    }

    map <string, list<pair<int, string>>> adjList;
    ifstream myfile;
    string pNode;
    string cNode;
    int weight;
    //cout << "initilaized map allWords, ifstream myFile, temps for line input\n";

    vector <string> vertex;
    list <tuple<int, string, string>> qt;


    myfile.open(argv[1]);

    //cout << "opened file: " << argv[1];

    if (myfile) {
      while (!myfile.eof()) {
        myfile >> pNode;
        myfile >> cNode;
        myfile >> weight;

        if (begin.length() == 0) {
          begin = pNode;
          //cout << "Begin: " << begin << endl;
        }

        if (find(vertex.begin(), vertex.end(), pNode) == vertex.end()) {
          vertex.push_back(pNode);
        }
        if (find(vertex.begin(), vertex.end(), cNode) == vertex.end()) {
          vertex.push_back(cNode);
        }


        //word = word.tolower()
        pair<int, string> pary;
        //cout << "pNode: " << pNode << " (" << cNode << ", " << weight << ")\n";
        pary.first = weight;
        pary.second = cNode;
        adjList[pNode].push_front(pary);

        tuple<int, string, string> tupy;
        tupy = make_tuple(weight, pNode, cNode);
        qt.push_back(tupy);

      }
    myfile.close();
  } else {
    cout << "Unable to open file";
  }

  // gernerate minumum spanning tree

  // map iterator I
//exit(0);
// for (  map<string, list<pair<int, string>>>::iterator i = adjList.begin(); i != adjList.end(); i++) {
//   cout << i->first << ": ";
//
//   for (list<pair<int, string>>::iterator j = i->second.begin(); j != i->second.end(); j++) {
//     cout << "(" << j->first << j->second << ") ";
//   }
//   cout << endl;
// }
//

sort(qt.begin(), gt.end());
while (!qt.empty()) {
  cout << get<0>(qt.top()) << " " << get<1>(qt.top()) << " " << get<2>(qt.top()) << endl;
  qt.pop();
}
//
// for (int i = 0; i < vertex.size(); i++) {
//   cout << vertex.at(i) << endl;
// }


// qt is a prioriy queue of connections from most expensize to least
// adjList is an adjaceny list of all connections mapped to the pNode value
// vertex is a vector of all the nodes

//exit(0);

DisjointSet<string> mst;
for (int i = 0; i < vertex.size(); i++) {
  //cout << vertex.at(i) << endl;
  mst.createSet(vertex[i]);
}
while (mst.parents.size() > 1) {

}





  //
  //
  // IO and exit
  stack<string> path;
  path.push(begin);
  while (!cin.eof() && !path.empty()) {
    // queue the wights of the list
    cout << "<" << path.top() << "># ";
    string command = " ";
    cin >> command;
    if (cin.eof()) {
      break;
    }

    string next;

    if (command == "exit") {
      //cout << "leaving: " << path.top();
      path.pop();
    } else if (command == "ssh") {
      cin >> next;
      if (find(vertex.begin(), vertex.end(), next) == vertex.end()) {
        cout << "Cannot find node.  Available nodes are:\n";
        for (int i = 0; i < vertex.size(); i++) {
          cout << "  " << vertex.at(i) << endl;
        }

      } else {
        // go to node, add path to path
        cout << "FIXME ssh Node exits\n";
      }
    } else if (command == "ping") {
      cin >> next;
      if (find(vertex.begin(), vertex.end(), next) == vertex.end()) {
        cout << "Cannot find node.  Available nodes are:\n";
        for (int i = 0; i < vertex.size(); i++) {
          cout << "  " << vertex.at(i) << endl;
        }
      } else {
        cout << "FIXME ping command Node exits" << endl;
      }
    }
  }
  cout << endl;
    return 0;
}
