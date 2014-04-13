#ifndef MAX_SPAN_SET_H
#define MAX_SPAN_SET_H

#include "adjGraph.h"
#include <set>

bool isSpanningSet(std::set<int> spanningSet, adjGraph graph);
void lubySpanSet(std::set<int>& spanSet, adjGraph graph);

#endif
