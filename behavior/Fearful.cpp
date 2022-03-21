#include "Fearful.h"
#include "../parameters.h"
Fearful::Fearful() : Behavior(){
	cout << "Construct Fearful" << endl;
}

Fearful::~Fearful(){
	cout << "Destruct Fearful" << endl;
}

int* Fearful::getColor(){
	return  COLOR;
}

Behavior* Fearful::clone() const{
	return new Fearful(*this);
}

void Fearful::specialBehavior(Critter* c,std::vector<std::shared_ptr<Critter>> crittersList){
	/*
		if the number of neighbors exceeds a threshold, the creature goes in the 
	    opposite direction
	*/
	double orientation = c->getOrientation();
	int counter = crittersList.size();
	if(counter>=maxNeighbors){
		orientation += M_PI;
		c->setOrientation(orientation);
	}

	
}

string Fearful::to_string(){
	return "Fearful";
}