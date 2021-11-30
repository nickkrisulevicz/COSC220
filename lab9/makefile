main: main.o dynClass.o
	g++ -o main main.o dynClass.o

main.o: main.cpp
	g++ -c main.cpp

dynClass.o: dynClass.cpp dynClass.h
	g++ -c dynClass.cpp

clean:
	rm *.o main
