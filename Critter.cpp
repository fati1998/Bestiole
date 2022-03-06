#include "Critter.h"
#include <cmath>

const double Critter::PDEAD=0.6;
const double Critter::MAX_SIZE=20.;
const int Critter::AGE_MAX = 80;
const double Critter::SPEED_MAX= 10.;
int Critter::counter = 0;
 

Critter::Critter(int xLim, int yLim){
	identity = ++counter;
	cout <<"Create the critter :"<< identity<< endl;

	x = static_cast<double>( rand() )/RAND_MAX*xLim;
	y = static_cast<double>( rand() )/RAND_MAX*yLim;
	cumulX = cumulY = 0.;
	orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
	pDead = PDEAD;
	ageLimit = static_cast<double>( rand() )/RAND_MAX*AGE_MAX;
	speed = static_cast<double>( rand() )/RAND_MAX*SPEED_MAX;
	size = static_cast<double>( rand() )/RAND_MAX*MAX_SIZE;

	isDead = false;

}

Critter::~Critter(){
   cout << "destruct the critter :" << identity <<endl;
}

/*
void Bestiole::bouge(Mileu ){

   double         nx, ny;
   double         dx = cos( orientation )*vitesse;
   double         dy = -sin( orientation )*vitesse;
   int            cx, cy;


   cx = static_cast<int>( cumulX ); cumulX -= cx;
   cy = static_cast<int>( cumulY ); cumulY -= cy;

   nx = x + dx + cx;
   ny = y + dy + cy;

   if ( (nx < 0) || (nx > xLim - 1) ) {
      orientation = M_PI - orientation;
      cumulX = 0.;
   }
   else {
      x = static_cast<int>( nx );
      cumulX += nx - x;
   }

   if ( (ny < 0) || (ny > yLim - 1) ) {
      orientation = -orientation;
      cumulY = 0.;
   }
   else {
      y = static_cast<int>( ny );
      cumulY += ny - y;
   }

}
*/
double Critter::distance(Critter &c){
	return sqrt(pow(x-c.x,2)+pow(y-c.y,2));
}

bool Critter::collision(Critter &c){
	double distance = this->distance(c);
	return (distance<=(size+c.size));
}


void Critter::behaviorAfterCollision(){
	double p = static_cast<double>( rand() )/RAND_MAX;
	if(p>pDead){
		cout<<"DEAD"<<endl;
		isDead = true;
	}
	else{
		orientation += M_PI;
		orientation = fmod(orientation, 2*M_PI);

	}


}

bool Critter::detection(Critter &b){
	return false;
}

Critter* Critter::clone(){
	Critter* copy = new Critter(*this);
	copy->identity = ++counter;
	copy->x += 2*size*sin( orientation )/5;
	copy->y -= 2*size*cos( orientation )/5;

	return copy;
}


string Critter::to_string(){
	return "Bestiole {Identity : "+std::to_string(identity) + 
	"\nPosition:(" + std::to_string(x) +"," + std::to_string(y)+"),\n"
	"age limit : " + std::to_string(ageLimit) + ","
	"\nspeed : " + std::to_string(speed) + ","
	"\nsize : " + std::to_string(size) + ","
	"\norientation : " + std::to_string(orientation) +"}";
}
 