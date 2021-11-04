#make all
#./main
main: Labmain.o LinkedList.o Node.o
		g++ -o main Labmain.o LinkedList.o Node.o

Labmain.o: Labmain.cpp
		g++ -c Labmain.cpp
LinkedList.o: LinkedList.cpp LinkedList.h
		g++ -c LinkedList.cpp
Node.o: Node.cpp Node.h
		g++ -c Node.cpp
clean:
	rm *.o main
	
