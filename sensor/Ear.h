#ifndef _EAR_H_
#define _EAR_H_

#include "Sensor.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Critter;

class Ear: public Sensor{
	protected:
		static const double DISTANCER_MIN;
		static const double DISTANCER_MAX;
		static const double CAPACITYR_MIN;
		static const double CAPACITYR_MAX;

	public:
		Ear();
		~Ear();
		string to_string();
		bool detects(Critter* c1, Critter* c2) override;
		Sensor *clone()const override;

};

#endif