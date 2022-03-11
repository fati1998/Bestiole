#include "Careful.h"

const string Careful::COLOR = "blue";

Careful::Careful() : Behavior(){
	cout << "Construct Careful" << endl;
}

Careful::~Careful(){
	cout << "Destruct Careful" << endl;
}

string Careful::getColor()const{
	return  COLOR;
}

Behavior* Careful::clone() const{
	return new Careful(*this);
}

void Careful::specialBehavior(list<Critter> critterList)const{

}