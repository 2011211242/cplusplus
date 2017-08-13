PROJECT := $(shell readlink $(dir $(lastword $(MAKEFILE_LIST))) -f)

cpp= main.cpp 
inc= $(PROJECT)

test.out : $(cpp)
	g++ -std=c++11 -O3 $^ -I $(inc) -o $@

all :
	test.out

make clean:
	rm -rf test.out

