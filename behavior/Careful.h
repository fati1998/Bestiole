#ifndef _CAREFUL_H_
#define _CAREFUL_H_
#include "Behavior.h"
#include <string>
#include <iostream>

using namespace std;

class Careful : public Behavior{
	protected:
		static const string COLOR;
	public:
		Careful();
		~Careful();
		string getColor() const override;
		void specialBehavior(list<Critter> critterList)const override;
		Behavior* clone()const override;
};
#endif