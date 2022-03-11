#ifndef _GREGARIOUS_H_
#define _GREGARIOUS_H_
#include "Behavior.h"
#include <string>
#include <iostream>

using namespace std;

class Gregarious : public Behavior{
	protected:
		static const string COLOR;
	public:
		Gregarious();
		~Gregarious();
		string getColor() const override;
		void specialBehavior(list<Critter> critterList)const override;
		Behavior* clone()const override;
};
#endif