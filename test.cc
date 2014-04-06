#include "adjGraph.h"
#include "maxSpanSet.h"
#include <set>
#include <iostream>

using std::set;

int main() {
   adjGraph g = adjGraph(10);
   g.insert(2, 5);
   g.insert(0, 8);
   g.insert(3, 6);
   g.insert(3, 3);

   g.print();

   set<int> spanningSet;
   spanningSet.insert(1);
   spanningSet.insert(3);
   spanningSet.insert(7);

   if (isSpanningSet(spanningSet, g)) {
      std::cout << "Is spanning set" << std::endl;
   } else {
      std::cout << "Not a spanning set" << std::endl;
   }

   return 0;
}
