#ifndef _CAREFUL_H_
#define _CAREFUL_H_
#include "Behavior.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Careful : public Behavior{
	protected:
		int COLOR[3] = {0,0,255}; //blue
	public:
		Careful();
		~Careful();
		int* getColor() override;
		void specialBehavior(Critter* c, std::vector<std::shared_ptr<Critter>> crittersList) override;
		Behavior* clone()const override;
		string to_string()override;
};
#endif