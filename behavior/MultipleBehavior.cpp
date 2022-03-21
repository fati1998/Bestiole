#include "MultipleBehavior.h"


MultipleBehavior::MultipleBehavior() : Behavior(){
	cout << "Construct MultipleBehavior" << endl;
}

MultipleBehavior::~MultipleBehavior(){
	cout << "Destruct MultipleBehavior" << endl;
}

int* MultipleBehavior::getColor(){
	return  COLOR;
}

Behavior* MultipleBehavior::clone() const{
	return new MultipleBehavior(*this);
}

void MultipleBehavior::specialBehavior(Critter* c, std::vector<std::shared_ptr<Critter>> crittersList){
	/*
	The critter with this behavior adopts successively other behaviors chosen randomly over time.
	*/
	int index = rand()%4; // return randomly the index of the chosen behavior
	listBehaviors[index]->specialBehavior(c,crittersList);
}

string MultipleBehavior::to_string(){
	return "MultipleBehavior";
}