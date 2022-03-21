#ifndef _GREGARIOUS_H_
#define _GREGARIOUS_H_
#include "Behavior.h"
#include <string>
#include <iostream>

using namespace std;

class Gregarious : public Behavior{
	protected:
		int COLOR[3] = {0,255,0}; // green
	public:
		Gregarious();
		~Gregarious();
		int* getColor()  override;
		void specialBehavior(Critter* c, std::vector<std::shared_ptr<Critter>> crittersList) override;
		Behavior* clone()const override;
		string to_string()override;
};
#endif