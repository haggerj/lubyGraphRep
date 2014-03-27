#ifndef ADJGRAPH_H
#define ADJGRAPH_H

class adjGraph {
   public:
      adjGraph(int v);
      int V() const;
      int E() const;

      void insert(int e1, int e2);
      bool edge(int e1, int e2);

      void print();
};

#endif
