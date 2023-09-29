CXX = g++
CXXFLAGS = -W -g

mytest: mytest.cpp csr.cpp 
	$(CXX) $(CXXFLAGS) mytest.cpp csr.cpp -o mytest

run:
	./mytest