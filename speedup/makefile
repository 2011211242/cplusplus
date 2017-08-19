all: plusplusi.s \
	iplusplus.s

iplusplus.s:iplusplus.cpp
	g++ -O0 -S $^ -o $@

plusplusi.s:plusplusi.cpp
	g++ -O0 -S $^ -o $@


clean:
	rm -rf iplusplus.s plusplusi.s
