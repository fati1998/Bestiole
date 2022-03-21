#include "Eye.h"
#include "../Critter.h"
#include "../parameters.h"

Eye::Eye(): Sensor(0., 0.,0.){
	cout<<"Construct Eye"<<endl;
	this->field = FIELDE_MIN + static_cast<double>( rand() )/RAND_MAX*(FIELDE_MAX-FIELDE_MIN);
	this->distance = DISTANCEE_MIN + static_cast<double>( rand() )/RAND_MAX*(DISTANCEE_MAX-DISTANCEE_MIN);
	this->detectionCapacity = CAPACITYE_MIN + static_cast<double>( rand() )/RAND_MAX*(CAPACITYE_MAX-CAPACITYE_MIN);
}

Eye::~Eye(){
	cout<<"Destruct Eye"<<endl;
}

string Eye::to_string(){
	return "Eye {field : "+ std::to_string(field)+ ",\n"  + 
				"distance : " + std::to_string(distance) + ",\n"  + 
				"detectionCapacity : " + std::to_string(detectionCapacity) + "}\n";

}


bool Eye::detects(Critter* c1, Critter* c2){
	double angle = c1->getOrientation() - atan(c2->getY()/c2->getX());
	double x = c1->getX()+c1->getSize()*cos(c1->getOrientation());
	double y = c1->getY()+c1->getSize()*sin(c1->getOrientation());
	
	double x_ = c2->getX()+c2->getSize()*cos(c2->getOrientation());
	double y_ = c2->getY()+c2->getSize()*sin(c2->getOrientation());

	double dist = sqrt(pow(x-x_,2)+pow(y-y_,2));
	if(dist<0){dist = 0;}
	return dist<distance and abs(angle) <= field and detectionCapacity>c2->getCapacityCamouflage();

}
Sensor* Eye::clone() const{
	return new Eye(*this);
}

void Eye::draw( Critter* c,UImg & support){
	double x1 =  c->getX();
	double y1 =  c->getY();

	double x2 = x1 + distance* cos(c->getOrientation() - field);
	double y2 = y1 + distance* sin(c->getOrientation() - field);

	double x3 = x1 + distance* cos(c->getOrientation() + field);
	double y3 = y1 + distance* sin(c->getOrientation() + field);

	int color[3] = {60,100,10};

	support.draw_triangle(x1, y1, x2, y2, x3, y3, color, 0.5);
}