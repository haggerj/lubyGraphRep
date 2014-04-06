CXX = gcc
CXXFLAGS = -Wall -g

main: adjGraph.cc adjGraph.h loadGraph.cc hb_io.cc hb_io.h
	$(CXX) $(CXXFLAGS) -o load adjGraph.cc hb_io.cc loadGraph.cc -lstdc++
test: adjGraph.cc adjGraph.h maxSpanSet.cc maxSpanSet.h test.cc
	$(CXX) $(CXXFLAGS) -o test adjGraph.cc maxSpanSet.cc test.cc -lstdc++
