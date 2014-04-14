#include "adjGraph.h"
#include "maxSpanSet.h"
#include "loadGraph.h"
#include <set>
#include <iostream>
#include <stdlib.h>

using std::set;

void printIsSpanningSet(set<int> spanSet, adjGraph g);
void printSet(set<int> s);

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

   printIsSpanningSet(spanningSet, g);

   set<int> lubySpanningSet;
   lubySpanSet(lubySpanningSet, g);
   printSet(lubySpanningSet);
   printIsSpanningSet(lubySpanningSet, g);

   adjGraph g2 = loadGraph("bcsstm01/bcsstm01.rb");
   g2.print();
   set<int> lubySet2;
   lubySpanSet(lubySet2, g2);
   printSet(lubySet2);
   printIsSpanningSet(lubySet2, g2);

   adjGraph g3 = loadGraph("Stranke94/Stranke94.rb");
   g3.print();
   set<int> lubySet3;
   lubySpanSet(lubySet3, g3);
   printSet(lubySet3);
   printIsSpanningSet(lubySet3, g3);

   return 0;
}

void printSet(set<int> s) {
   for (set<int>::iterator itr = s.begin(); itr != s.end(); itr++) {
      std::cout << *itr << " ";
   }
   std::cout << "\n" << std::endl;
}

void printIsSpanningSet(set<int> set, adjGraph g) {
   if (isSpanningSet(set, g)) {
      std::cout << "Is spanning set" << std::endl;
   } else {
      std::cout << "Not a spanning set" << std::endl;
   }
}
