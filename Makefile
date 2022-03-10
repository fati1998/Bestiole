main: main.cpp Critter.o Sensor.o Eye.o Ear.o
	g++ -o main main.cpp Critter.o Sensor.o Eye.o Ear.o

Critter.o : Critter.cpp Critter.h
	g++ -c Critter.cpp

Sensor.o : Sensor.cpp Sensor.h 
	g++ -c Sensor.cpp 

Eye.o : Eye.cpp Eye.h 
	g++ -c Eye.cpp 

Ear.o : Ear.cpp Ear.h
	g++ -c Ear.cpp

clean :
	rm *.o main