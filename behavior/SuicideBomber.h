#ifndef _SUICIDEBOMBER_H_
#define _SUICIDEBOMBER_H_
#include "Behavior.h"
#include <string>
#include <iostream>

using namespace std;

class SuicideBomber : public Behavior{
	protected:
		static const string COLOR;
	public:
		SuicideBomber();
		~SuicideBomber();
		string getColor() const override;
		void specialBehavior(list<Critter> critterList)const override;
		Behavior* clone()const override;
};
#endif

