#include "Camouflage.h"
#include "../Critter.h"
#include "../parameters.h"
 

Camouflage::Camouflage(){
    cout << "Construct the Camouflage" << endl;
    capacity = (rand()/double(RAND_MAX)) * (CAPACITY_MAX_CAMOUFLAGE - CAPACITY_MIN_CAMOUFLAGE) + CAPACITY_MIN_CAMOUFLAGE;
}

Camouflage::Camouflage (const Camouflage* c){
	cout << "Construct the Camouflage" << endl;
    capacity = c->capacity;
}

Camouflage::~Camouflage(){
	cout << "Destruct the Camouflage" << endl;
}

double Camouflage::getCapacity(){return capacity;}

string Camouflage::to_string(){
	return "{capacity : "+ std::to_string(capacity)+ "}\n";
}

void Camouflage::draw( Critter* c,UImg & support){
	int color[3] =  {213, 216, 220 };
	support.draw_ellipse( c->getX(), c->getY(), c->getSize(), c->getSize()/2., c->getOrientation()/M_PI*180.,  color ,capacity);
}
