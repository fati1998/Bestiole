#include "Ear.h"
#include "Critter.h"

const double Ear::DISTANCER_MIN=1.;
const double Ear::DISTANCER_MAX=3.;
const double Ear::CAPACITYR_MIN=0.1;
const double Ear::CAPACITYR_MAX=0.99;

Ear::Ear(): Sensor(0.,0.,0.){
	cout<<"Construct Ear"<<endl;
	this->field = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
	this->distance = DISTANCER_MIN + static_cast<double>( rand() )/RAND_MAX*(DISTANCER_MAX-DISTANCER_MIN);
	this->detectionCapacity = CAPACITYR_MIN + static_cast<double>( rand() )/RAND_MAX*(CAPACITYR_MAX-CAPACITYR_MIN);
}

Ear::~Ear(){
	cout<<"Destruct Ear"<<endl;
}

string Ear::to_string(){
	return "Ear {field : "+ std::to_string(field)+ ",\n"  + 
				"distance : " + std::to_string(distance) + ",\n"  + 
				"detectionCapacity : " + std::to_string(detectionCapacity) + "}\n";
}
bool Ear::detects(Critter* c1, Critter* c2){
	double angle1 = c1->getOrientation()-M_PI/2 - atan(c2->getY()/c2->getX());
	double angle2 = c1->getOrientation()+M_PI/2 - atan(c2->getY()/c2->getX());

	double dist = c1->distance(c2)-c1->getSize()/5-c2->getSize();
	if(dist<0){dist = 0;}
	return dist<distance and (abs(angle1) <= field or abs(angle2) <= field );

}
Sensor* Ear::clone() const{
	return new Ear(*this);
}