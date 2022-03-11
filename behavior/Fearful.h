#ifndef _FEARFUL_H_
#define _FEARFUL_H_
#include "Behavior.h"
#include <string>
#include <iostream>

using namespace std;

class Fearful : public Behavior{
	protected:
		static const string COLOR;
	public:
		Fearful();
		~Fearful();
		string getColor() const override;
		void specialBehavior(list<Critter> critterList)const override;
		Behavior* clone()const override;
};
#endif