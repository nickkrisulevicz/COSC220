output: main.o node.o
	g++ -std=c++11 main.o node.o -o main

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

node.o: node.cpp node.h
	g++ -c -std=c++11 node.cpp

clean:
	rm *.o main
