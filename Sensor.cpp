 #include "Sensor.h"

Sensor::Sensor(double f, double d, double c){
	cout<< "Create Sensor" << endl;
	field = f;
	distance = d;
	detectionCapacity = c;
}

Sensor::~Sensor(){
	cout<< "destruct Sensor" << endl;
}

double Sensor::getDistance(){
	return distance;
}

double Sensor::getField(){
	return field;
}

double Sensor::getDetectionCapacity(){
	return detectionCapacity;
}

