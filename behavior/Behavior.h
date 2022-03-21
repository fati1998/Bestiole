#ifndef _BEHAVIOR_H_
#define _BEHAVIOR_H_

#include <string>
#include <memory>
#include <list>
#include <iostream> 
#include <vector>
#include "../Critter.h"
using namespace std;

class Critter;

class Behavior{
	public: 
		Behavior();
		virtual ~Behavior();
		virtual int* getColor()=0;
		virtual void specialBehavior(Critter* c, std::vector<std::shared_ptr<Critter>> crittersList){};
		virtual Behavior* clone() const=0;
		virtual string to_string(){return " ";};

};
#endif