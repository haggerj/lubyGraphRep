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

//spanSet should be an empty set
void lubySpanSet(set<int>& spanSet, adjGraph graph) {
   for (int i = 0; i < graph.V(); i++) {
      if(graph.numEdges(i) == 0 || (rand() % (2 * graph.numEdges(i))) == 1) {
         spanSet.insert(i);
      }
   }

   bool cont = true;

   for (int j = 0; j < graph.V(); j++) {
      if(spanSet.find(j) != spanSet.end()) {
         list<int> edges = graph.edges(j);
         int numEdges = edges.size();

         for (list<int>::iterator itr = edges.begin(); 
            itr != edges.end() && cont; itr++) {

            if (*itr != j && spanSet.find(*itr) != spanSet.end()) {
               if (numEdges < graph.numEdges(*itr)) {
                  spanSet.erase(j);
                  cont = false;
               } else {
                  spanSet.erase(*itr);
               }
            }
         }
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
