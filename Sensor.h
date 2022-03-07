#ifndef _SENSOR_H_
#define _SENSOR_H_

#include <iostream>
using namespace std;

class Sensor{
	protected:
		double field;
		double distance;
		double detectionCapacity;

	public:

		Sensor(double f, double d, double c);
		virtual ~Sensor();
		double getField();
		double getDistance();
		double getDetectionCapacity();
		virtual Sensor *clone()const=0;

};

#endif
