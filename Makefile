# CXX Make variable for compiler
CXX=g++
# Make variable for compiler options
#	-std=c++11  C/C++ variant to use, e.g. C++ 2011
#	-g          include information for symbolic debugger e.g. gdb 
CXXFLAGS=-std=c++11


pagingwithtlb : main.cpp pageTable.o tracereader.o output_mode_helpers.o
	$(CXX) $(CXXFLAGS) -g -o pagingwithtlb $^

main.o : main.cpp
	$(CXX) $(CXXFLAGS) -g -c $<

pageTable.o : pageTable.cpp pageTable.h
	$(CXX) $(CXXFLAGS) -g -c $<

tracereader.o : tracereader.cpp tracereader.h
	$(CXX) $(CXXFLAGS) -g -c $<

output_mode_helpers.o : output_mode_helpers.cpp output_mode_helpers.h
	$(CXX) $(CXXFLAGS) -g -c $<

clean :
	rm -f *.o