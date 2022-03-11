#include "MultipleBehavior.h"

const string MultipleBehavior::COLOR = "pink";

MultipleBehavior::MultipleBehavior() : Behavior(){
	cout << "Construct MultipleBehavior" << endl;
}

MultipleBehavior::~MultipleBehavior(){
	cout << "Destruct MultipleBehavior" << endl;
}

string MultipleBehavior::getColor()const{
	return  COLOR;
}

Behavior* MultipleBehavior::clone() const{
	return new MultipleBehavior(*this);
}

void MultipleBehavior::specialBehavior(list<Critter> critterList)const{

}