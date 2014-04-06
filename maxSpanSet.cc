#include <set>
#include <vector>
#include "maxSpanSet.h"

using std::set;
using std::vector;
using std::list;

bool isSpanningSet(set<int> spanningSet, adjGraph graph) {
   vector<bool> marked(graph.V(), false);
   bool spanning = true;

   for (set<int>::iterator itr = spanningSet.begin(); 
        itr != spanningSet.end() && spanning; itr++) {
      if (marked[*itr]) {
         spanning = false;
      } else {
         marked[*itr] = true;
         list<int> edges = graph.edges(*itr);

         for (list<int>::iterator litr = edges.begin();
              litr != edges.end() && spanning; litr++) {
            if(marked[*litr]) {
               spanning = false;
            } else {
               marked[*litr] = true;
            }
         }
      }
   }

   return spanning;
}
