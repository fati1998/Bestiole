main: main.cpp Critter.o Sensor.o Eye.o Ear.o Behavior.o Fearful.o Careful.o SuicideBomber.o Gregarious.o MultipleBehavior.o Environment.o Aquarium.o Shell.o Fin.o Camouflage.o
	g++ -o main main.cpp Critter.o Sensor.o Eye.o Ear.o Behavior.o Fearful.o Careful.o SuicideBomber.o Gregarious.o MultipleBehavior.o Environment.o Aquarium.o Shell.o Fin.o Camouflage.o -I . -lX11 -lpthread

Critter.o : Critter.cpp Critter.h
	g++ -c Critter.cpp

Environment.o : Environment.cpp Environment.h
	g++ -c Environment.cpp -I .

Aquarium.o : Aquarium.cpp Aquarium.h
	g++ -c Aquarium.cpp -I .


#  ********** Sensors **********
Sensor.o : sensor/Sensor.cpp sensor/Sensor.h 
	g++ -c sensor/Sensor.cpp 

Eye.o : sensor/Eye.cpp sensor/Eye.h 
	g++ -c sensor/Eye.cpp 

Ear.o : sensor/Ear.cpp sensor/Ear.h
	g++ -c sensor/Ear.cpp


#  ********** Accessories **********
Fin.o : accessory/Fin.h  accessory/Fin.cpp
	g++ -c  accessory/Fin.cpp

Shell.o : accessory/Shell.h  accessory/Shell.cpp
	g++ -c  accessory/Shell.cpp

Camouflage.o : accessory/Camouflage.h  accessory/Camouflage.cpp
	g++ -c  accessory/Camouflage.cpp

#  ********** Behaviors **********
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