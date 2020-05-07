#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

void printGraph(map<char, list<char> > &graph)
{
    map<char, list<char> >::iterator graph_it;
    list<char>::iterator it;

    for (graph_it = graph.begin();
         graph_it != graph.end(); graph_it++)
    {
        cout << (*graph_it).first << ": ";
        for (it = (*graph_it).second.begin();
             it != (*graph_it).second.end(); it++)
            cout << *it << " ";
        cout << endl;
    }
}



int main() {

    // build the graph
    map<char, list<char> > graph;
    char v1, v2, start, end;

    //Process graph input
    while((cin >> v1) && v1 != '?') {
        if (!(cin >> v2)) {
            break;
        } else {
          graph[v1];
        }
        graph[v1].push_back(v2);
    }

    // display stored graph if compiled with -DDEBUG_PRINT
#ifdef DEBUG_PRINT
    printGraph(graph);
#endif

    //Process queries
    while (cin >> start >> end) {
        //REPLACE WITH CODE TO STORE OR PROCESS QUERIES
      cin >> v1; //grab the next '?'
      if (v1 != '?')
          break;


      // start is starting char
      // end is ending char
      map<char, bool> visited;
      map<char, char> parent;

      map<char, list<char>>::iterator graph_it;
      list<char>::iterator currGraphList;

      string str = "";


      //why,,,just why
      for (graph_it = graph.begin(); graph_it != graph.end(); graph_it++ ) {
        visited[graph_it->first] = false;
      }

      queue<char> charQueue;
      charQueue.push(start);
      visited[start] = true;

      char graphIndex = start;
      while (!charQueue.empty()) { // do queues have ends()??
        graphIndex = charQueue.front(); charQueue.pop();
        currGraphList = graph[graphIndex].begin();
        while (currGraphList != graph[graphIndex].end()) { // iterate throught the map. currGraphList is the iterator
          if (!visited[(*currGraphList)]) {  // if the char val hasnt been visited,
            parent[(*currGraphList)] = graphIndex; // set the parents at the graph index to the char value associated with it
            visited[(*currGraphList)]  = true;  // set the visited at the graph iterator to true
            charQueue.push(*currGraphList);
          }
          currGraphList++;
        }
      }


      // printing it out;


      // if (charQueue.front() != end) {
      //   while (!charQueue.empty()) {
      //     cout << charQueue.front(); charQueue.pop();
      //   }
      // } else {
      //   cout << "from " << start << " to " << end << " : path not found.\n";
      //
      // }



      string a;
      if (charQueue.front() != end) {
        a = "from ";
        a += start;
        a += " to ";
        a +=  end;
        a += " : path found.\n";

        char temp = end;

        end = parent[end];
        stack<char> traceChar;
        traceChar.push(end);
        int i = 0;
        while(end != start) {
           if (i < 30) {i++;}
           else {
             cout << "from " << start << " to " << temp << " : path not found.\n";
             break;
           }
           end = parent[end];
           traceChar.push(end);
        }


        while (!traceChar.empty()) {
          if (i > 19) {break;}
          a += traceChar.top();
          traceChar.pop();
          a += " ";
        }

        if (i < 19) {
          a += temp;
          a += "\n";
          cout << a;
        }

      } else {
        cout << "from " << start << " to " << end << " : path not found.\n";

      }

  }

}
