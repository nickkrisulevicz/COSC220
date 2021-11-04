output: prog.o bar-1.o foo.o
	g++ -std=c++11 prog.o bar-1.o foo.o -o prog

prog.o: prog.cpp
	g++ -c -std=c++11 prog.cpp

bar-1.o: bar-1.cpp
	g++ -c -std=c++11 bar-1.cpp

foo.o: foo.cpp
	g++ -c -std=c++11 foo.cpp

clean:
	rm *.o
