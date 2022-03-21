#include "Gregarious.h"


Gregarious::Gregarious() : Behavior(){
	cout << "Construct Gregarious" << endl;
}

Gregarious::~Gregarious(){
	cout << "Destruct Gregarious" << endl;
}

int* Gregarious::getColor(){
	return  COLOR;
}

Behavior* Gregarious::clone() const{
	return new Gregarious(*this);
}

void Gregarious::specialBehavior(Critter* c, std::vector<std::shared_ptr<Critter>> crittersList){
	/*
	The critter changes its orientation to the average value of the orientations 
	of its neighbors
	*/
	double orientation = 0;
	if(crittersList.size()>0){
		for( std::vector<std::shared_ptr<Critter>>::iterator it = crittersList.begin() ; it != crittersList.end() ; ++it ){
			orientation += (*it)->getOrientation();
			cout << (*it)->getOrientation()<< endl;
		}
		cout << c->getOrientation() << "==>" << orientation <<endl;
		c->setOrientation(orientation/crittersList.size());
	}
}

string Gregarious::to_string(){
	return "Gregarious";
}