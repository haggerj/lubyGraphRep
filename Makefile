CXX = gcc
CXXFLAGS = -Wall -g

main: adjGraph.cc adjGraph.h maxSpanSet.cc maxSpanSet.h loadGraph.cc loadGraph.h hb_io.cc hb_io.h test.cc
	$(CXX) $(CXXFLAGS) -o test adjGraph.cc maxSpanSet.cc test.cc loadGraph.cc hb_io.cc -lstdc++
