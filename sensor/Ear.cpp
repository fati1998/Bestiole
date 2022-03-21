#include "Ear.h"
#include "../Critter.h"
#include "../parameters.h"

Ear::Ear(): Sensor(0.,0.,0.){
	cout<<"Construct Ear"<<endl;
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
	
	double dist = c1->distance(c2);
	if(dist<0){dist = 0;}
	if(dist<distance){cout<< "ear detection"<<endl;}
	return dist<distance and detectionCapacity>c2->getCapacityCamouflage();

}
Sensor* Ear::clone() const{
	return new Ear(*this);
}

void Ear::draw( Critter* c,UImg & support){
	int color[3] = {100,50,0};
	support.draw_circle( c->getX(), c->getY(),distance, color, 0.2);
}