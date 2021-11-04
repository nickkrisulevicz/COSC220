
output: labmain.o node.o linkedlist.o
	g++ -c -std=c++11 labmain.o node.o linkedlist.o -o labmain

labmain.o: labmain.cpp
	g++ -c -std=c++11 labmain.cpp

linkedlist.o: linkedlist.cpp
	g++ -c -std=c++11 linkedlist.cpp linkedlist.h

node.o: node.cpp node.h
	g++ -c -std=c++11 node.cpp node.h

clean:
	rm *.o
