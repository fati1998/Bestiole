#include "Environment.h"
#include "behavior/Careful.h"
#include "behavior/Fearful.h"
#include "behavior/SuicideBomber.h"
#include "behavior/Gregarious.h"
#include "behavior/MultipleBehavior.h"
#include <cstdlib>
#include <ctime>

const T    Environment::white[] = { (T)255, (T)255, (T)255 };

Environment::Environment(int w, int l): UImg( w, l, 1, 3 ),width(w),length(l){
	std::srand( time(NULL) );
	cout << "Construct the Environment" << endl;
	for(int i=0; i<INITIAL_NUMBER; i++){
		this->addCritter();
	}
	int n_careful = int(INITIAL_NUMBER*PERCENTAGE_CAREFUL/100);
	int n_fearful = int(INITIAL_NUMBER*PERCENTAGE_FEARFUL/100);
	int n_gregarious = int(INITIAL_NUMBER*PERCENTAGE_GREGARIOUS/100);
	int n_kamikaze = int(INITIAL_NUMBER*PERCENTAGE_SUICIDE/100);
	for(int i=0; i<n_careful ; i++){
		listCritters[i]->setBehavior(new Careful());
	}
	for(int i=n_careful; i<n_careful+n_fearful; i++){
		listCritters[i]->setBehavior(new Fearful());
	}
	for(int i=n_careful+n_fearful; i<n_careful+n_fearful+n_gregarious; i++){
		listCritters[i]->setBehavior(new Gregarious());
	}
	for(int i=n_careful+n_fearful+n_gregarious; i<n_careful+n_fearful+n_gregarious+n_kamikaze; i++){
		listCritters[i]->setBehavior(new SuicideBomber());
	}
	for(int i = n_careful+n_fearful+n_gregarious+n_kamikaze; i<INITIAL_NUMBER; i++){
		listCritters[i]->setBehavior(new MultipleBehavior());
	}



}
Environment::~Environment(){
	cout << "Destruct the Environment" << endl;
}
void Environment::step(){
	std::vector<std::shared_ptr<Critter>> clonedCritters;
	for ( std::vector<std::shared_ptr<Critter>>::iterator it = listCritters.begin() ; it != listCritters.end() ; ++it ){
		bool col = false;
		
		if ((*it)->getAgeLimit()==0){
			(*it)->dead();
		}
		else{
			(*it)->decrementAge();}
		
		for( std::vector<std::shared_ptr<Critter>>::iterator neighbor= listCritters.begin() ; neighbor !=  listCritters.end() ; ++neighbor ){
			if(it==neighbor){
				continue;
			}

			if((*it)->collision((*neighbor).get())){
				(*it)->behaviorAfterCollision();
				col = true;
			}

		
		}

		
		std::vector<std::shared_ptr<Critter>> listNeighbors = getNeighbors((*it).get());
		if(!col && !(*it)->getIsDead()){
			(*it)->specialBehavior(listNeighbors);
		}
		//
		
	}	



	removeDeadCritters();
	cloning();
	int n = std::rand()%NMAX;
	double pro = static_cast<double>( std::rand() )/RAND_MAX;
	if(pro<P_BIRTH){
		for(int i=0; i<n; i++){
			addCritter();
		}
	}

   	cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
    for ( std::vector<std::shared_ptr<Critter>>::iterator it = listCritters.begin() ; it != listCritters.end() ; ++it ){
   	  (*it)->draw( *this );
      (*it)->action( *this );
    }
}

void Environment::cloning(){
	if(listCritters.size()<30){
		int size = listCritters.size();
		for(int i=0; i<size; i++){
			if(listCritters[i]->cloning(P_CLONAGE)){
					addCritter(listCritters[i]->clone());
				}
		
		}
	}
}

void Environment::addCritter(){
	Critter* c = new Critter(width, length);
	addCritter(c);

}


void Environment::addCritter(Critter* crit){
	std::shared_ptr<Critter> critter;
   	critter.reset(crit);
	listCritters.push_back(critter);
}



std::vector<std::shared_ptr<Critter>> Environment::getNeighbors(Critter* c){

	std::vector<std::shared_ptr<Critter>> list;
	for ( std::vector<std::shared_ptr<Critter>>::iterator it = listCritters.begin() ; it != listCritters.end() ; ++it ){
		if(c->getIdentity() != (*it)->getIdentity() && c->detection((*it).get())){
			list.push_back((*it));
		}
	}
	return list;
}


int Environment::getWidth(){
	return width;
}
int Environment::getLength(){
	return length;
}

void Environment::removeDeadCritters(){
	std::vector<std::shared_ptr<Critter>>::iterator it = listCritters.begin();
	while(it != listCritters.end()){
		if((*it)->getIsDead()){
			listCritters.erase(it);
		}else{
			it++;
		}
	}	 
}

Critter* Environment::getCritterById(int id){
	std::vector<std::shared_ptr<Critter>>::iterator it = listCritters.begin();
    while(it != listCritters.end()){
		if((*it)->getIdentity() == id){
		    return (*it).get();

		}
		 it++;
   } 
   return nullptr;
}