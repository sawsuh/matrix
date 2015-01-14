all: main

main: main.o
	g++ main.o -o matrix

main.o: source/main.cpp
	g++ source/main.cpp -c --std=c++11

install: all
	cp matrix /usr/local/bin/matrix
