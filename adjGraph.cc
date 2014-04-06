#include <vector>
using std::vector;

#include <list>
using std::list;

#include <iostream>

#include "adjGraph.h"

   int Vcnt;
   int Ecnt;

   vector<list<int> > adj;

   adjGraph::adjGraph(int V) {
         Vcnt = V;
         Ecnt = 0;
         adj = vector<list<int> >(V);
   }

   int adjGraph::V() const {
         return Vcnt;
   }

   int adjGraph::E() const {
         return Ecnt;
   }

   void adjGraph::insert(int e1, int e2) {
         if (e1 < Vcnt && e2 < Vcnt) {
            adj[e1].push_back(e2);
            adj[e2].push_back(e1);
            Ecnt++;
         }
   }

   bool adjGraph::edge(int e1, int e2) {
         if (e1 > Vcnt || e2 > Vcnt) {
            return false;
         }

         list<int>::iterator itr = adj[e1].begin();

         while(itr != adj[e1].end()) {
            if(*itr == e2) {
               return true;
            }
         }

         return false;
    }

   void adjGraph::print() {
      for (vector<list<int> >::iterator vitr = adj.begin();
           vitr != adj.end(); vitr++) {
         for(list<int>::iterator litr = vitr->begin(); litr != vitr->end(); 
             litr++) {
            std::cout << *litr << " ";
         }

         std::cout << "\n" << std::endl;
      }
   }

   list<int> adjGraph::edges(int v1) {
      return adj[v1];
   }
