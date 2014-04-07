#include <set>
#include <vector>
#include "maxSpanSet.h"
#include <iostream>

using std::set;
using std::vector;
using std::list;

void printMarked(vector<bool> marked, int n);

bool isSpanningSet(set<int> spanningSet, adjGraph graph) {
   vector<bool> marked(graph.V(), false);
   bool spanning = true;

   for (set<int>::iterator itr = spanningSet.begin(); 
        itr != spanningSet.end() && spanning; itr++) {
      std::cout << "checking for node " << *itr << std::endl;

      printMarked(marked, graph.V());

      if (marked[*itr]) {
         spanning = false;
      } else {
         marked[*itr] = true;
         list<int> edges = graph.edges(*itr);

         for (list<int>::iterator litr = edges.begin();
              litr != edges.end() && spanning; litr++) {
 
            printMarked(marked, graph.V());

            if(*itr != *litr && marked[*litr]) {
               spanning = false;
            } else {
               marked[*litr] = true;
            }
         }
      }
   }

   return spanning;
}

void printMarked(vector<bool> marked, int n) {
   std::cout << "vector marked: ";

   for (int i = 0; i < n; i++) {
      std::cout << marked[i] << " ";
   }

   std::cout << std::endl;
}
