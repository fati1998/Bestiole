main: main.cpp Critter.o Sensor.o Eye.o Ear.o Behavior.o Fearful.o Careful.o SuicideBomber.o Gregarious.o MultipleBehavior.o
	g++ -o main main.cpp Critter.o Sensor.o Eye.o Ear.o Behavior.o Fearful.o Careful.o SuicideBomber.o Gregarious.o MultipleBehavior.o

Critter.o : Critter.cpp Critter.h
	g++ -c Critter.cpp

Sensor.o : sensor/Sensor.cpp sensor/Sensor.h 
	g++ -c sensor/Sensor.cpp 

Eye.o : sensor/Eye.cpp sensor/Eye.h 
	g++ -c sensor/Eye.cpp 

Ear.o : sensor/Ear.cpp sensor/Ear.h
	g++ -c sensor/Ear.cpp

Behavior.o: behavior/Behavior.cpp behavior/Behavior.h
	g++ -c behavior/Behavior.cpp

Fearful.o: behavior/Fearful.cpp behavior/Fearful.h
	g++ -c behavior/Fearful.cpp

Careful.o: behavior/Careful.cpp behavior/Careful.h
	g++ -c behavior/Careful.cpp


SuicideBomber.o: behavior/SuicideBomber.cpp behavior/SuicideBomber.h
	g++ -c behavior/SuicideBomber.cpp

Gregarious.o: behavior/Gregarious.cpp behavior/Gregarious.h
	g++ -c behavior/Gregarious.cpp

MultipleBehavior.o: behavior/MultipleBehavior.cpp behavior/MultipleBehavior.h
	g++ -c behavior/MultipleBehavior.cpp
	
clean :
	rm *.o main 