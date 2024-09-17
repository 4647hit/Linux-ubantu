.PHONY:all
all: mykill  sigtest

sigtest:sigtest.cc
	g++ -o $@ $^ -std=c++11
# test:test.cpp
# 	g++ -o $@ $^ -std=c++11
mykill:mykill.cpp
	g++ -o $@ $^ -std=c++11
.PHONY:clean
clean:
	rm -f mykill