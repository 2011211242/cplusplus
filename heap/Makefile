PROJECT := $(shell readlink $(dir $(lastword $(MAKEFILE_LIST))) -f)

cpp= main.cpp \

test.out : $(cpp)
	g++ -std=c++11 -O3 $^ -o $@

all :
	test.out

make clean:
	rm -rf test.out

