#include "SuicideBomber.h"

const string SuicideBomber::COLOR = "red";

SuicideBomber::SuicideBomber() : Behavior(){
	cout << "Construct SuicideBomber" << endl;
}

SuicideBomber::~SuicideBomber(){
	cout << "Destruct SuicideBomber" << endl;
}

string SuicideBomber::getColor()const{
	return  COLOR;
}

Behavior* SuicideBomber::clone() const{
	return new SuicideBomber(*this);
}

void SuicideBomber::specialBehavior(list<Critter> critterList)const{

}