#include "Sensor.h"
#include <iostream>
#include <cmath>
using namespace std;

class Eye: public Sensor{
	protected:
		static const double DISTANCE_MIN;
		static const double DISTANCE_MAX;
		static const double CAPACITY_MIN;
		static const double CAPACITY_MAX;

	public:
		Eye();
		~Eye();
		Sensor *clone()const override;

};

//#endif