CXX = gcc
CXXFLAGS = -Wall

main: adjGraph.cc adjGraph.h loadGraph.cc hb_io.cc hb_io.h
	$(CXX) $(CXXFLAGS) adjGraph.cc hb_io.cc loadGraph.cc -lstdc++

