all: main

main: main.o
	clang++ main.o -o matrix

main.o: source/main.cpp
	clang++ source/main.cpp -c --std=c++11

install: all
	cp matrix /usr/local/bin/matrix
