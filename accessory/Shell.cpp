#include "Shell.h"
#include "../Critter.h"
#include "../parameters.h"
Shell::Shell() {
    cout << "Construct the Shell" << endl;
    coef = (rand()/double(RAND_MAX)) * (COEF_MAX_SHELL - 1) + 1;
    factor = (rand()/double(RAND_MAX)) * (FACTOR_MAX_SHELL - 1) + 1;
}
Shell::Shell(const Shell *s) {
	cout << "Construct the Shell" << endl;
    coef = s->coef;
    factor = s->factor;
}
Shell::~Shell() {
	cout << "Destruct the Shell" << endl;
}

double Shell::getCoef() {return coef;}
double Shell::getFactor() {return factor;}

string Shell::to_string(){
	return "{coef : "+ std::to_string(coef)+ ","+
			"factor :" + std::to_string(factor)+"}\n";
}


void Shell::draw( Critter* c,UImg & support){

	support.draw_circle( c->getX(), c->getY(), c->getSize(), c->getBehavior()->getColor() ,1-1/coef);
}


