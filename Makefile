main: main.cpp Critter.o
	g++ -o main main.cpp Critter.o

Critter.o : Critter.cpp Critter.h
	g++ -c Critter.cpp



clean :
	rm *.o main