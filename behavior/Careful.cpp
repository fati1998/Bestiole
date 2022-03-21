#include "Careful.h"
 

Careful::Careful() : Behavior(){
	cout << "Construct Careful" << endl;
}

Careful::~Careful(){
	cout << "Destruct Careful" << endl;
}

int* Careful::getColor(){
	return  COLOR;
}

Behavior* Careful::clone() const{
	return new Careful(*this);
}

void Careful::specialBehavior(Critter* c, std::vector<std::shared_ptr<Critter>> crittersList){
	/* 
	    The critter adjusts its trajectory to avoid possible collisions.
		for this we divide the neighborhood into 4 parts according to the 
		orientation of the critter. 
		We assign a score to each part. The score is related to the distance
		between the critter and its neares neighbor and the number of critters in the part.

		The critter moves towards the area with maximum score
	*/
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	double dist1 = 10000;
	double dist2 = 10000;
	double dist3 = 10000;
	double dist4 = 10000;

	if(crittersList.size()>0){
	    for( std::vector<std::shared_ptr<Critter>>::iterator it = crittersList.begin() ; it != crittersList.end() ; ++it ){

			if(((*it)->getX() - c->getX())>=0 and ((*it)->getY() - c->getY())>=0 ){
				count1 += 1;
				if(dist1>c->distance((*it).get())){
					dist1 = c->distance((*it).get());
				}
			}
			else if(((*it)->getX() - c->getX())<0 and ((*it)->getY() - c->getY())>=0 ){
				count2 += 1;
				if(dist2>c->distance((*it).get())){
					dist2 = c->distance((*it).get());
				}
			}
			else if(((*it)->getX() - c->getX())<0 and ((*it)->getY() - c->getY())<0){
				count3 += 1;
				if(dist3>c->distance((*it).get())){
					dist3 = c->distance((*it).get());
				}
			}
			else{
				count4 += 1;
				if(dist4>c->distance((*it).get())){
					dist4 = c->distance((*it).get());
				}
			}
		}

		double score1 = 0.25/count1 + 0.75*dist1;
		double score2 = 0.25/count2 + 0.75*dist2;
		double score3 = 0.25/count3 + 0.75*dist3;
		double score4 = 0.25/count4 + 0.75*dist4;

		double maximum = max({score1, score2, score3, score4});
		double orientation = c->getOrientation();
		if (maximum==score1){
			c->setOrientation(orientation- M_PI/4);
		}
		else if(maximum==score2){
			c->setOrientation(orientation+ M_PI/4);
		}
		else if(maximum==score3){
			c->setOrientation(orientation+ 3*M_PI/4);
		}
		else{
			c->setOrientation(orientation+ 5*M_PI/4);
		}
	}
}

string Careful::to_string(){
	return "Careful";
}