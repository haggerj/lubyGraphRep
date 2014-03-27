#include "adjGraph.h"

int main() {
   adjGraph g = adjGraph(10);
   g.insert(2, 5);
   g.insert(0, 8);
   g.insert(3, 6);
   g.insert(3, 3);

   g.print();

   return 0;
}
