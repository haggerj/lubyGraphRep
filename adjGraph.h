#ifndef ADJGRAPH_H
#define ADJGRAPH_H

#include <list>

class adjGraph {
   public:
      adjGraph(int v);
      int V() const;
      int E() const;

      void insert(int e1, int e2);
      bool edge(int e1, int e2);
      std::list<int> edges(int e);

      void print();
};

#endif
