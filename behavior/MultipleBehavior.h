#ifndef _MULTIPLEBEHAVIOR_H_
#define _MULTIPLEBEHAVIOR_H_
#include "Behavior.h"
#include "Careful.h"
#include "SuicideBomber.h"
#include "Fearful.h"
#include "Gregarious.h"
#include <string>
#include <iostream>

using namespace std;

class MultipleBehavior : public Behavior{
	protected:
		int COLOR[3] = {255,0,255}; // pink
	public:
		MultipleBehavior();
		~MultipleBehavior();
		int* getColor() override;
		void specialBehavior(Critter* c, std::vector<std::shared_ptr<Critter>> crittersList) override;
		Behavior* clone()const override;
		string to_string()override;

	private:
		Behavior* listBehaviors[4] = {new Careful(), new SuicideBomber(),new Gregarious(), new Fearful()};
};
#endif