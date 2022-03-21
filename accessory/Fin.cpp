#include "Fin.h"
#include "../Critter.h"
#include "../parameters.h"

Fin::Fin() {
    cout << "Construct the Fin" << endl;
    coef = (rand()/double(RAND_MAX)) * (COEF_MAX_FIN - 1) + 1;
}

Fin::Fin(const Fin *f) {
	cout << "Construct the Fin" << endl;
    coef = f->coef;
} 

Fin::~Fin() {

	cout << "Destruct the Fin" << endl;

}

double Fin::getCoef() {return coef;}

string Fin::to_string(){
	return "{coef : "+ std::to_string(coef)+ "}\n";
}

void Fin::draw( Critter* c,UImg & support){
	double size = c->getSize()/4;
	int color[3] = {  23, 32, 42 };
	support.draw_circle(c->getX(),c->getY(), size, color, 0.8);
}

