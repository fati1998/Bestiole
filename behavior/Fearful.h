#ifndef _FEARFUL_H_
#define _FEARFUL_H_
#include "Behavior.h"
#include <string>
#include <cmath>
#include <iostream>

using namespace std;
//class Critter;

class Fearful : public Behavior{
	protected:
		int COLOR[3] = {255,255,0}; // yellow
		
	public:
		Fearful();
		~Fearful();
		int* getColor()  override;
		void specialBehavior(Critter* c,std::vector<std::shared_ptr<Critter>> crittersList) override;
		Behavior* clone()const override;
	    string to_string()override;
};
#endif