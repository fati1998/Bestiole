#ifndef _SUICIDEBOMBER_H_
#define _SUICIDEBOMBER_H_
#include "Behavior.h"
#include <string>
#include <iostream>

using namespace std;

class SuicideBomber : public Behavior{
	protected:
		int COLOR[3] = {255,0,0}; //red
	public:
		SuicideBomber();
		~SuicideBomber();
		int* getColor() override;
		void specialBehavior(Critter* c, std::vector<std::shared_ptr<Critter>> crittersList) override;
		Behavior* clone()const override;
		string to_string()override;
};
#endif

