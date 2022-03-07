#include "Eye.h"

const double Eye::DISTANCE_MIN=1.;
const double Eye::DISTANCE_MAX=3.;
const double Eye::CAPACITY_MIN=0.1;
const double Eye::CAPACITY_MAX=0.99;

Eye::Eye(): Sensor(0., 41.,0.){
	cout<<"Construct Eye"<<endl;
	this->field = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
	this->distance = DISTANCE_MIN + static_cast<double>( rand() )/RAND_MAX*(DISTANCE_MAX-DISTANCE_MIN);
	this->detectionCapacity = CAPACITY_MIN + static_cast<double>( rand() )/RAND_MAX*(CAPACITY_MAX-CAPACITY_MIN);
}

Eye::~Eye(){
	cout<<"Destruct Eye"<<endl;
}
Sensor* Eye::clone() const{
	return new Eye(*this);
}