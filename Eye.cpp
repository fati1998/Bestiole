#include "Eye.h"

const double Eye::DISTANCEE_MIN=1.;
const double Eye::DISTANCEE_MAX=3.;
const double Eye::CAPACITYE_MIN=0.1;
const double Eye::CAPACITYE_MAX=0.99;

Eye::Eye(): Sensor(0., 41.,0.){
	cout<<"Construct Eye"<<endl;
	this->field = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
	this->distance = DISTANCEE_MIN + static_cast<double>( rand() )/RAND_MAX*(DISTANCEE_MAX-DISTANCEE_MIN);
	this->detectionCapacity = CAPACITYE_MIN + static_cast<double>( rand() )/RAND_MAX*(CAPACITYE_MAX-CAPACITYE_MIN);
}

Eye::~Eye(){
	cout<<"Destruct Eye"<<endl;
}
Sensor* Eye::clone() const{
	return new Eye(*this);
}