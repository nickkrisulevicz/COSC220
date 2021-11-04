output: main.o booknode.o student.o
	g++ -std=c++11 main.o booknode.o student.o -o StudentDlist

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

booknode.o: booknode.cpp booknode.h
	g++ -c -std=c++11 booknode.cpp

student.o: student.cpp student.h
	g++ -c -std=c++11 student.cpp

