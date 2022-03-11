#include "Gregarious.h"

const string Gregarious::COLOR = "green";

Gregarious::Gregarious() : Behavior(){
	cout << "Construct Gregarious" << endl;
}

Gregarious::~Gregarious(){
	cout << "Destruct Gregarious" << endl;
}

string Gregarious::getColor()const{
	return  COLOR;
}

Behavior* Gregarious::clone() const{
	return new Gregarious(*this);
}

void Gregarious::specialBehavior(list<Critter> critterList)const{

}