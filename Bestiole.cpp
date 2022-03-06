#include "Bestiole.h"
#include <cmath>

const double Bestiole::PMORT=0.6;
const double Bestiole::TAILLE_MAX=20.;
const int Bestiole::AGE_MAX = 80;
const double Bestiole::VITESSE_MAX= 10.;
int Bestiole::compteur = 0;

Bestiole::Bestiole(int xLim, int yLim){
	identite = ++compteur;

	cout <<"Creation de la bestiole"<< identite<< endl;
	x = static_cast<double>( rand() )/RAND_MAX*xLim;
	y = static_cast<double>( rand() )/RAND_MAX*yLim;

	cout <<"position : ("<<x<<","<<y<<")"<<endl;

	cumulX = cumulY = 0.;
	orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;

	cout <<"Orientation:"<< orientation<< endl;

	pMort = PMORT;
	ageLimite = static_cast<double>( rand() )/RAND_MAX*AGE_MAX;
	cout <<"ageLimite"<< ageLimite<< endl;

	vitesse = static_cast<double>( rand() )/RAND_MAX*VITESSE_MAX;
	cout <<"vitesse"<< vitesse<< endl;

	taille = static_cast<double>( rand() )/RAND_MAX*TAILLE_MAX;
	cout <<"taille"<< taille<< endl;

	isDead = false;

}

Bestiole::~Bestiole(){
   cout << "destruction de la Bestiole" << identite <<endl;
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
double Bestiole::distance(Bestiole &b){
	return sqrt(pow(x-b.x,2)+pow(y-b.y,2));
}

bool Bestiole::collision(Bestiole &b){
	double distance = this->distance(b);
	return static_cast<bool> (distance<=(taille+b.taille));
}


void Bestiole::comportementApresCollision(){
	double p = static_cast<double>( rand() )/RAND_MAX;
	cout << "proba" << p << endl;
	if(p>pMort){
		cout<<"mort"<<endl;
		isDead = true;
	}
	else{
		cout<<"vivant"<<endl;
		orientation += M_PI;
		orientation = fmod(orientation, 2*M_PI);
		cout <<"Orientation:"<< orientation<< endl;

	}


}

bool Bestiole::detection(Bestiole &b){
	return false;
}

Bestiole* Bestiole::clone(){
	return new Bestiole(*this);
}



