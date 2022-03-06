main: main.cpp Bestiole.o
	g++ -o main main.cpp Bestiole.o

Bestiole.o : Bestiole.cpp Bestiole.h
	g++ -c Bestiole.cpp



clean :
	rm *.o main