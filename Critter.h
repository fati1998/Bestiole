#ifndef _CRITTER_H_
#define _CRITTER_H_

#include "UImg.h"
 
#include <iostream>
#include "sensor/Eye.h"
#include "sensor/Ear.h"
#include "behavior/Behavior.h"
#include <cmath>
#include <string>
#include <list>
using namespace std;

class Behavior;
class Careful;
class Gregarious;
class Fearful;
class SuicideBomber;
class MultipleBehavior;
class Environment;
class Fin;
class Camouflage;
class Shell;

class Critter{
	protected:

		static int counter;

	private:
		int identity;
		int x, y;
		double pDead;
		int ageLimit;
		double speed;
		double size;
		double orientation;
		bool isDead;
		list<Sensor*> mySensors;
		list<Fin*> myFins;
		list<Camouflage*> myCamouflage;
		list<Shell*> myShells;
		Behavior* myBehavior;


	private:
		void move( int xLim, int yLim );

	public:
		Critter(int xLim, int yLim);
		Critter(Critter* c);
		~Critter();
		double distance(Critter *c);
		bool collision(Critter* c);
		void behaviorAfterCollision();
		bool detection(Critter* c);
		void specialBehavior(std::vector<std::shared_ptr<Critter>> crittersList);
		//bool myEyeDetects(Critter &c);
		string to_string();
		Critter *clone();
		bool cloning(double pro_clonage);
		// Getters

		double getX();
		double getY();
		int getIdentity();
		double getOrientation();
		double getSize();
		double getAgeLimit();
		bool getIsDead();
		double getCapacityCamouflage();
		Behavior* getBehavior();

		// setters 
		void setOrientation(double o);
		void setBehavior(Behavior* newBehavior);
		void decrementAge();
		void dead();

		void action( Environment & monEnvironment );
		void draw( UImg & support );
};

#endif