PROJECT := $(shell readlink $(dir $(lastword $(MAKEFILE_LIST))) -f)

cpp1= main.cpp 
inc= $(PROJECT)
cpp2 = stl_heap.cpp


all : stl.out \
	test.out


test.out : $(cpp1)
	g++ -std=c++11 -O3 $^ -I $(inc) -o $@

stl.out : $(cpp2)
	g++ -std=c++11 -O3 $^ -I $(inc) -o $@

make clean:
	rm -rf test.out stl.out

