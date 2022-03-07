main: main.cpp Critter.o Sensor.o Eye.o
	g++ -o main main.cpp Critter.o Sensor.o Eye.o

Critter.o : Critter.cpp Critter.h
	g++ -c Critter.cpp

Sensor.o : Sensor.cpp Sensor.h
	g++ -c Sensor.cpp

Eye.o : Eye.cpp Eye.h
	g++ -c Eye.cpp

clean :
	rm *.o main