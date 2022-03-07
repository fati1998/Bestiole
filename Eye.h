#ifndef _EYE_H_
#define _EYE_H_

#include "Sensor.h"
#include <iostream>
#include <cmath>
using namespace std;

class Eye: public Sensor{
	protected:
		static const double FIELDE_MIN;
		static const double FIELDE_MAX;
		static const double DISTANCEE_MIN;
		static const double DISTANCEE_MAX;
		static const double CAPACITYE_MIN;
		static const double CAPACITYE_MAX;

	public:
		Eye();
		~Eye();
		Sensor *clone()const override;

};

#endif