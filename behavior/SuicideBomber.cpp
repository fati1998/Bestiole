#include "SuicideBomber.h"


SuicideBomber::SuicideBomber() : Behavior(){
	cout << "Construct SuicideBomber" << endl;
}

SuicideBomber::~SuicideBomber(){
	cout << "Destruct SuicideBomber" << endl;
}

int* SuicideBomber::getColor(){
	return  COLOR;
}

Behavior* SuicideBomber::clone() const{
	return new SuicideBomber(*this);
}

void SuicideBomber::specialBehavior(Critter* c, std::vector<std::shared_ptr<Critter>> crittersList){
	/*
	the critter seeks to attack the nearest critter
	*/
	double x = 0.;
	double y = 0.;
	double distance = 1000.;
	if (crittersList.size()>0){

		for( std::vector<std::shared_ptr<Critter>>::iterator it = crittersList.begin() ; it != crittersList.end() ; ++it ){
			if(distance > c->distance((*it).get())){
				distance = c->distance((*it).get());
				x = (*it)->getX();
				y = (*it)->getY();
				if((x-c->getX())>0){
					c->setOrientation(atan((y-c->getY())/(x-c->getX())));
				}
				else if((x-c->getX())==0){c->setOrientation(M_PI/2);}
				else{
					c->setOrientation(M_PI+atan((y-c->getY())/(x-c->getX())));
				}
			}
		}
		
	}
}


string SuicideBomber::to_string(){
	return "SuicideBomber";
}