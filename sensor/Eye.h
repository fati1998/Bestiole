#ifndef _EYE_H_
#define _EYE_H_

#include "Sensor.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Critter;

class Eye: public Sensor{

	public:
		Eye();
		~Eye();
		string to_string() override;
		bool detects(Critter* c1, Critter* c2) override;
		Sensor *clone()const override;
		void draw( Critter* c,UImg & support)override;

};

#endif