#ifndef _BEHAVIOR_H_
#define _BEHAVIOR_H_

#include <string>
#include <list>
#include <iostream> 

using namespace std;

class Critter;

class Behavior{
	public: 
		Behavior();
		virtual ~Behavior();
		virtual string getColor()const=0;
		virtual void specialBehavior(list<Critter> critterList)const=0;
		virtual Behavior* clone() const=0;

};
#endif