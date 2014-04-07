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

//Helper method for testing
void printMarked(vector<bool> marked, int n) {
   std::cout << "vector marked: ";

   for (int i = 0; i < n; i++) {
      std::cout << marked[i] << " ";
   }

   std::cout << std::endl;
}
