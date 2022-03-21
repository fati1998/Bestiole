#ifndef _EAR_H_
#define _EAR_H_

#include "Sensor.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Critter;

class Ear: public Sensor{
	public:
		Ear();
		~Ear();
		string to_string();
		bool detects(Critter* c1, Critter* c2) override;
		Sensor *clone()const override;
		void draw( Critter* c,UImg & support) override;

};

#endif