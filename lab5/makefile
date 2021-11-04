output: vectorDriver.o vectorAux.o
	g++ -std=c++11 vectorDriver.o vectorAux.o -o labmain

vectorDriver.o: vectorDriver.cpp
	g++ -c -std=c++11 vectorDriver.cpp

vectorAux.o: vectorAux.cpp vectorAux.h
	g++ -c -std=c++11 vectorAux.cpp

clean:
	rm *.o labmain
