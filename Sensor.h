#ifndef _SENSOR_H_
#define _SENSOR_H_

#include <iostream>
#include <string>
using namespace std;

class Critter;

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
		virtual bool detects(Critter* c1, Critter* c2){return false;};
		virtual string to_string(){return " ";};

};

#endif
