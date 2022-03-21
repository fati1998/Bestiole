#include "Critter.h"

#include "behavior/Fearful.h"
#include "behavior/Careful.h"
#include "behavior/SuicideBomber.h"
#include "behavior/Gregarious.h"
#include "behavior/MultipleBehavior.h"
 
#include "accessory/Fin.h" 
#include "accessory/Camouflage.h" 
#include "accessory/Shell.h" 


#include "Environment.h"

#include <cmath>
#include <string>
using namespace std;


int Critter::counter = 0;
 

Critter::Critter(int xLim, int yLim){
	identity = ++counter;
	cout <<"Create the critter :"<< identity<< endl;

	x = static_cast<double>( rand() )/RAND_MAX*xLim;
	y = static_cast<double>( rand() )/RAND_MAX*yLim;
	orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
	pDead = PDEAD;
	ageLimit = static_cast<double>( rand() )/RAND_MAX*AGE_MAX;
	speed = static_cast<double>( rand() )/RAND_MAX*SPEED_MAX;
	size = 5+static_cast<double>( rand() )/RAND_MAX*(MAX_SIZE-5);
	isDead = false;

	// Sensors 
	
	for(int i=0; i<rand()/(RAND_MAX/2); i++){
		mySensors.push_back(new Eye());
	}
	for(int i=0; i<rand()/(RAND_MAX/2); i++){
		mySensors.push_back(new Ear());
	}

	// Accessories
	
	// add fins and update speed
	for(int i=0; i<rand()/(RAND_MAX/2); i++){
		Fin* fin = new Fin();
		cout << "speed: " << speed << "==>" ;
		myFins.push_back(fin);
		speed *=fin->getCoef();
		cout << speed << endl;

	}

	// add camouflage
	
	for(int i=0; i<rand()/(RAND_MAX/2); i++){
		Camouflage* cam = new Camouflage();
		myCamouflage.push_back(cam);
	}

	for(int i=0; i<rand()/(RAND_MAX/2); i++){
		Shell* shell = new Shell();
		cout << "speed: " << speed << "==>" ;
		myShells.push_back(shell);
		speed /= shell->getFactor();
		cout << speed << endl;
		cout << "pDead: " << pDead << "==>" ;
		pDead /= shell->getCoef();
		cout << pDead << endl;

	}



	cout << "capacity camouflage " << std::to_string(getCapacityCamouflage()) <<endl;

	

	
	int be = rand()%5;
	if(be==1){myBehavior = new Gregarious();}
	else if(be==2){myBehavior = new Fearful();}
	else if(be==3){myBehavior = new SuicideBomber();}
	else if(be==4){myBehavior = new Careful();}
	else{myBehavior = new MultipleBehavior();}

}


Critter::Critter(Critter* c){
	identity = ++counter;
	cout <<"cloning the critter :"<< identity<< endl;
	orientation = c->orientation;
	pDead = c-> pDead;
	ageLimit = c->ageLimit;
	speed = c->speed;
	size = c->size;
	isDead = c->isDead;
	myBehavior = c->myBehavior->clone();
	mySensors = {};
	for(Sensor* s: c->mySensors){
		mySensors.push_back(s->clone());
	}
	myFins = {};
	for(Fin* f: c->myFins){
		myFins.push_back(new Fin(f));
	}
	myCamouflage = {};
	for(Camouflage* cam: c->myCamouflage){
		myCamouflage.push_back(new Camouflage(cam));
	}

	myShells = {};
	for(Shell* shell: c->myShells){
		myShells.push_back(new Shell(shell));
	}




	x = c->x + 2*size*sin(orientation)/2;
	y = c->y + 2*size*cos(orientation)/2;
}

Critter::~Critter(){
   cout << "destruct the critter :" << to_string() <<endl;
   delete myBehavior;
   for (auto it = mySensors.begin(); it!= mySensors.end(); ++it){
   	delete *it;
   }
   for (auto it = myFins.begin(); it!= myFins.end(); ++it){
   	delete *it;
   }
   for (auto it = myCamouflage.begin(); it!= myCamouflage.end(); ++it){
   	delete *it;
   }
   for (auto it = myShells.begin(); it!= myShells.end(); ++it){
   	delete *it;
   }


}


void Critter::move(int xLim, int yLim){
   double x_ = x+size*cos(orientation);
   double y_ = y+size*sin(orientation);

   if((x_<0) || (x_>xLim)){
   		orientation += M_PI;
   		orientation = fmod(orientation, 2*M_PI);
   }
   if((y_<0) || (y_>yLim)){
   	 	orientation = 2*M_PI - orientation;
   }
   x += cos(orientation)*speed;
   y += sin(orientation)*speed;


}

double Critter::distance(Critter * c){
	return sqrt(pow(x-c->x,2)+pow(y-c->y,2));
}

bool Critter::collision(Critter * c){
	double distance = this->distance(c);
	if(distance<=(size+c->size)){
	cout << identity << "is colliding with" << c->getIdentity()<<endl;}
	return (distance<=(size+c->size));
}


void Critter::behaviorAfterCollision(){
	double p = static_cast<double>( rand() )/RAND_MAX;
	if(p<=pDead){
		cout<<"DEAD"<<endl;
		isDead = true;
	}
	else{
		//cout << "********************* CHANGEMENT D'orientation *******************************" <<endl;
		orientation += M_PI;
		orientation = fmod(orientation, 2*M_PI);

	}

}

void Critter::specialBehavior(std::vector<std::shared_ptr<Critter>> crittersList){
	myBehavior->specialBehavior(this,crittersList);
}

bool Critter::detection(Critter* c){

	for(Sensor* s : mySensors){
		if (s->detects(this, c)){
			cout<< identity<<"detects"<<c->getIdentity()<< endl;
			return true;
		}
	}

	return false;
}
bool Critter::cloning(double pro_clonage){
	double p = static_cast<double>( rand() )/RAND_MAX;
	return (p<=pro_clonage);
}


Critter* Critter::clone(){
	
	Critter* copy = new Critter(*this);
	copy->myBehavior = this->myBehavior->clone();
	copy->mySensors = {};
	for (Sensor* s : mySensors){
   		copy->mySensors.push_back(s->clone());
   	}
   	copy->myFins = {};
	for(Fin* f: myFins){
		copy->myFins.push_back(new Fin(f));
	}
	copy->myCamouflage = {};
	for(Camouflage* cam: myCamouflage){
		copy->myCamouflage.push_back(new Camouflage(cam));
	}

	copy->myShells = {};
	for(Shell* shell: myShells){
		copy->myShells.push_back(new Shell(shell));
	}


	copy->identity = ++counter;
	copy->x += 5*size*sin( orientation );
	copy->y -= 5*size*cos( orientation );
	cout << "cloning critter ..." << copy->identity <<endl;
	return copy;
}

double Critter::getX(){return x;}
double Critter::getY(){return y;}
double Critter::getOrientation(){return orientation;}
double Critter::getSize(){return size;}
double Critter::getAgeLimit(){return ageLimit;}
bool Critter::getIsDead(){return isDead;}
double Critter::getCapacityCamouflage(){
	double capacity =0;
	for(Camouflage* cam:myCamouflage){
		if (capacity< cam->getCapacity()){
			capacity = cam->getCapacity();
		}
	}
	return capacity;

}

int Critter::getIdentity(){return identity;}

Behavior* Critter::getBehavior(){return myBehavior;}

void Critter::dead(){
	isDead=true;
}
void Critter::setOrientation(double o){
	orientation = fmod(o, 2*M_PI);
}

void Critter::setBehavior(Behavior* newBehavior){
	delete myBehavior;
	myBehavior = newBehavior;
}


void Critter::decrementAge(){
	ageLimit--;
}
string Critter::to_string(){
	string st = " ";
	for(Sensor* s : mySensors){
		st = st + s->to_string();
	}
	string f =" ";
	for(Fin* fin: myFins){
		f = f + fin->to_string();
	}
	
	string c = " ";
	for(Camouflage* cam:myCamouflage){
		c = c + cam->to_string();
	}

	string s = " ";
	for(Shell* shell:myShells){
		s = s + shell->to_string();
	}


	return "Bestiole {Identity : "+std::to_string(identity) + 
	"\nPosition:(" + std::to_string(x) +"," + std::to_string(y)+"),\n"
	"age limit : " + std::to_string(ageLimit) + ","
	"\nspeed : " + std::to_string(speed) + ","
	"\nsize : " + std::to_string(size) + ","
	"\norientation : " + std::to_string(orientation) +
	"\nbehavior: " + myBehavior->to_string()+ ","+
	"\nSensors: " + st+","+
	"\nFins: " + f+","+
	"\nCamouflage: " + c+","+
	"\nShells: " + s+","+
	"\nisDead: " + std::to_string(isDead)+"}";
}
 


void Critter::action( Environment & monEnvironment )
{

   move(monEnvironment.getWidth(), monEnvironment.getLength() );

}

void Critter::draw( UImg & support )
{


   //int color[3] = {0,0,255};
   support.draw_ellipse( x, y, size, size/2., orientation/M_PI*180.,  myBehavior->getColor(),5);
   int black[3] = {0, 0, 0};
   //support.draw_circle( xt, yt, AFF_SIZE/2., couleur );

   for (Sensor* s : mySensors){
   		s->draw(this, support);
   	}

   	for(Fin* f: myFins){
   		f->draw(this,support);
   	}
   	for(Camouflage* c: myCamouflage){
   		c->draw(this,support);
   	}

   	for(Shell* s: myShells){
   		s->draw(this,support);
   	}
   	support.draw_text(x-size/5,y-size/5, (std::to_string(identity)+":"+std::to_string(ageLimit)).c_str(), black, 4);


}
