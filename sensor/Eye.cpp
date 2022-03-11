#include "Eye.h"
#include "../Critter.h"

const double Eye::FIELDE_MIN=0.;
const double Eye::FIELDE_MAX=3.;
const double Eye::DISTANCEE_MIN=1.;
const double Eye::DISTANCEE_MAX=3.;
const double Eye::CAPACITYE_MIN=0.1;
const double Eye::CAPACITYE_MAX=0.99;

Eye::Eye(): Sensor(0., 41.,0.){
	cout<<"Construct Eye"<<endl;
	this->field = FIELDE_MIN + static_cast<double>( rand() )/RAND_MAX*(FIELDE_MAX-FIELDE_MIN);
	this->distance = DISTANCEE_MIN + static_cast<double>( rand() )/RAND_MAX*(DISTANCEE_MAX-DISTANCEE_MIN);
	this->detectionCapacity = CAPACITYE_MIN + static_cast<double>( rand() )/RAND_MAX*(CAPACITYE_MAX-CAPACITYE_MIN);
}

Eye::~Eye(){
	cout<<"Destruct Eye"<<endl;
}

string Eye::to_string(){
	return "Eye {field : "+ std::to_string(field)+ ",\n"  + 
				"distance : " + std::to_string(distance) + ",\n"  + 
				"detectionCapacity : " + std::to_string(detectionCapacity) + "}\n";

}


bool Eye::detects(Critter* c1, Critter* c2){
	double angle = c1->getOrientation() - atan(c2->getY()/c2->getX());
	double dist = c1->distance(c2)-c1->getSize()-c2->getSize();
	if(dist<0){dist = 0;}
	return dist<distance and abs(angle) <= field;

}
Sensor* Eye::clone() const{
	return new Eye(*this);
}