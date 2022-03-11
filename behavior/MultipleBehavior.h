#ifndef _MULTIPLEBEHAVIOR_H_
#define _MULTIPLEBEHAVIOR_H_
#include "Behavior.h"
#include <string>
#include <iostream>

using namespace std;

class MultipleBehavior : public Behavior{
	protected:
		static const string COLOR;
	public:
		MultipleBehavior();
		~MultipleBehavior();
		string getColor() const override;
		void specialBehavior(list<Critter> critterList)const override;
		Behavior* clone()const override;
};
#endif