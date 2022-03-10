#ifndef _CRITTER_H_
#define _CRITTER_H_

#include <iostream>
#include "Eye.h"
#include "Ear.h"
#include <cmath>
#include <string>
#include <list>
using namespace std;

class Critter{
	protected:

		static const double PDEAD;
		static const double MAX_SIZE;
		static const int AGE_MAX;
		static const double SPEED_MAX;
		static int counter;

	private:
		int identity;
		Eye myEye = Eye();
		int x, y;
		double            cumulX, cumulY;
		double pDead;
		int ageLimit;
		double speed;
		double size;
		double orientation;
		bool isDead;
		list<Sensor*> mySensors;


	private:
		//void bouge( int xLim, int yLim );

	public:
		Critter(int xLim, int yLim);
		~Critter();
		double distance(Critter *c);
		bool collision(Critter* c);
		void behaviorAfterCollision();
		bool detection(Critter* c);
		//bool myEyeDetects(Critter &c);
		string to_string();
		Critter *clone();
		// Getters
		double getX();
		double getY();
		double getOrientation();
		double getSize();
};

#endif