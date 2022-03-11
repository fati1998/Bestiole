#include "Fearful.h"

const string Fearful::COLOR = "yellow";

Fearful::Fearful() : Behavior(){
	cout << "Construct Fearful" << endl;
}

Fearful::~Fearful(){
	cout << "Destruct Fearful" << endl;
}

string Fearful::getColor()const{
	return  COLOR;
}

Behavior* Fearful::clone() const{
	return new Fearful(*this);
}

void Fearful::specialBehavior(list<Critter> critterList)const{

}