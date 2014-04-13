#include "adjGraph.h"
#include "maxSpanSet.h"
#include <set>
#include <iostream>
#include <stdlib.h>

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
   spanningSet.insert(8);
   spanningSet.insert(2);
   spanningSet.insert(4);
   spanningSet.insert(7);
   spanningSet.insert(9);

   if (isSpanningSet(spanningSet, g)) {
      std::cout << "Is spanning set" << std::endl;
   } else {
      std::cout << "Not a spanning set" << std::endl;
   }

   set<int> lubySpanningSet;
   lubySpanSet(lubySpanningSet, g);

   for (set<int>::iterator itr = lubySpanningSet.begin();
        itr != lubySpanningSet.end(); itr++) {
      std::cout << *itr << " ";
   }
   std::cout << std::endl;

   if (isSpanningSet(lubySpanningSet, g)) {
      std::cout << "Is spanning set" << std::endl;
   } else {
      std::cout << "Not a spanning set" << std::endl;
   }

   return 0;
}
