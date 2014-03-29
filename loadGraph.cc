#include <iostream>
#include <fstream>
#include <string>

#include "hb_io.h"
#include "adjGraph.h"

using std::string;

   adjGraph convertToGraph ( int nrow, int ncol, int * colptr, int * rowind ) {
      adjGraph g = adjGraph(ncol);

      if (nrow > ncol) {
         g = adjGraph(nrow);
      }

      for (int i = 0; i < ncol; i++) {
         std::cout << "colptr at " << i << " = " << colptr[i] << std::endl;
      }

      for (int i = 0; i < ncol; i++) {
         std::cout << "rowind at " << i << " = " << rowind[i] << std::endl;
      }

      int j = 0;
      for (int i = 0; i < ncol; i++) {
         for ( ; j < colptr[i]; j++) {
            g.insert(i, rowind[j] - 1);
            std::cout << "adding edge from " << i << " to " << rowind[j] << std::endl;
         }
      }

      return g;
   }

   adjGraph loadGraph (string file) {
      int indcrd;
      char * indfmt = NULL;
      std::ifstream input;
      char * key = NULL;
      char * mxtype = NULL;
      int ncol;
      int neltvl;
      int nnzero;
      int nrhs;
      int nrhsix;
      int nrow;
      int ptrcrd;
      char * ptrfmt = NULL;
      int rhscrd;
      char * rhsfmt = NULL;
      char * rhstyp = NULL;
      char * title = NULL;
      int totcrd;
      int valcrd;
      char * valfmt = NULL;

      input.open(file.c_str());

      if (input) 
         std::cout << "Loading file " << file << std::endl;

      hb_header_read(input, &title, &key, &totcrd, &ptrcrd, &indcrd,
         &valcrd, &rhscrd, &mxtype, &nrow, &ncol, &nnzero, &neltvl,
         &ptrfmt, &indfmt, &valfmt, &rhsfmt, &rhstyp, &nrhs, &nrhsix);

      std::cout << "rhscrd = " << rhscrd << std::endl;

      int * colptr = new int[ncol+1];

      int nRowInd;
      if (mxtype[2] == 'A' || mxtype[2] == 'a') {
         nRowInd = nnzero;
      } else if (mxtype[2] == 'E' || mxtype[2] == 'e') {
         nRowInd = neltvl;
      } else {
         std::cout << "Invalid mxtype." << mxtype[2] << std::endl;
      }

      int * rowind = new int[nRowInd];

      std::cout << "Reading the structure" << std::endl;

      hb_structure_read(input, ncol, mxtype, nnzero, neltvl, ptrcrd,
         ptrfmt, indcrd, indfmt, colptr, rowind);

      input.close();

      hb_structure_print(ncol, mxtype, nnzero, neltvl, colptr, rowind);

      adjGraph g = convertToGraph( nrow, ncol, colptr, rowind ); 

      delete [] colptr;
      delete [] rowind;

      return g;
   }

   int main() {
      adjGraph g = loadGraph("bcsstm01/bcsstm01.rb");

      g.print();
   }
