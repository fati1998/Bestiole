#include "Ear.h"

const double Ear::DISTANCER_MIN=1.;
const double Ear::DISTANCER_MAX=3.;
const double Ear::CAPACITYR_MIN=0.1;
const double Ear::CAPACITYR_MAX=0.99;

Ear::Ear(): Sensor(0., 41.,0.){
	cout<<"Construct Ear"<<endl;
	this->field = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
	this->distance = DISTANCER_MIN + static_cast<double>( rand() )/RAND_MAX*(DISTANCER_MAX-DISTANCER_MIN);
	this->detectionCapacity = CAPACITYR_MIN + static_cast<double>( rand() )/RAND_MAX*(CAPACITYR_MAX-CAPACITYR_MIN);
}

Ear::~Ear(){
	cout<<"Destruct Ear"<<endl;
}
Sensor* Ear::clone() const{
	return new Ear(*this);
}