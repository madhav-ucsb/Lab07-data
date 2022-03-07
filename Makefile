CXX = g++
# CXX = clang++

CXXFLAGS = -Wall -Wno-uninitialized

BINARIES=examheap


all: ${BINARIES}

tests: ${BINARIES}
	./examheap


examheap: examheap.o heap.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

heap.o: heap.cpp heap.h
	${CXX} heap.cpp -c
examheap.o: examheap.cpp heap.h 
	${CXX} examheap.cpp -c
clean:
	/bin/rm -f ${BINARIES} *.o