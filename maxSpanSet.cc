#include <set>
#include <vector>
#include "maxSpanSet.h"
#include <iostream>
#include <stdlib.h>

using std::set;
using std::vector;
using std::list;

void printMarked(vector<bool> marked, int n);

bool isSpanningSet(set<int> spanningSet, adjGraph graph) {
   vector<bool> marked(graph.V(), false);

   for (set<int>::iterator itr = spanningSet.begin(); 
        itr != spanningSet.end(); itr++) {

      if (marked[*itr]) {
         return false;
      } else {
         marked[*itr] = true;
         list<int> edges = graph.edges(*itr);

         for (list<int>::iterator litr = edges.begin();
              litr != edges.end(); litr++) {

            if(*itr != *litr && marked[*litr]) {
               return false;
            } else {
               marked[*litr] = true;
            }
         }
      }
   }


   for (int i = 0; i < graph.V(); i++) {
      if (!marked[i]) {
         return false;
      }
   }

   return true;
}

// spanSet should be an empty set
void lubySpanSet(set<int>& spanSet, adjGraph graph) {
  set<int> discarded;

  while(!isSpanningSet(spanSet, graph)) {
    set<int> candidates;
    for(int i = 0; i < graph.V(); i++) {
      if(spanSet.find(i) == spanSet.end() 
        && discarded.find(i) == discarded.end() && (graph.numEdges(i) == 0 ||
        rand() % (2 * graph.numEdges(i)))) {
        candidates.insert(i);
      }
    }

    for(set<int>::iterator itr = candidates.begin();
      itr != candidates.end(); itr++) {
      int numEdges = graph.numEdges(*itr);
      list<int> edges = graph.edges(*itr);

      for(list<int>::iterator editr = edges.begin(); editr != edges.end(); editr++) {
        if(*itr != *editr && candidates.find(*editr) != candidates.end()) {
          if(numEdges < graph.numEdges(*editr) ||
            (*itr < *editr && numEdges == graph.numEdges(*editr))) {
            candidates.erase(*itr);
            break;
          } else {
            candidates.erase(*editr);
          }
        }
      }
    }

    for(set<int>::iterator itr = candidates.begin(); itr != candidates.end(); itr++) {
      spanSet.insert(*itr);
    }
  }
}

//Helper method for testing
void printMarked(vector<bool> marked, int n) {
   std::cout << "vector marked: ";

   for (int i = 0; i < n; i++) {
      std::cout << marked[i] << " ";
   }

   std::cout << std::endl;
}
