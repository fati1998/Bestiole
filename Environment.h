#ifndef _ENVIRONMENT_H
#define _ENVIRONMENT_H
#include "Critter.h"
#include "parameters.h"
#include "UImg.h"
#include <vector>
#include <memory>
#include <cmath>

using namespace std;

class Environment:public UImg{
	private:
		static const T          white[];
		int width, length;
		std::vector<std::shared_ptr<Critter>>   listCritters;
	public:
		Environment(int w, int l);
		~Environment();
		void step();
		void cloning();
		void removeDeadCritters();
		void addCritter();
		void addCritter(Critter* crit);
		void addCritter(std::vector<std::shared_ptr<Critter>>  clonedCritters);
		std::vector<std::shared_ptr<Critter>> getNeighbors(Critter* c);
		Critter* getCritterById(int id);

		// getters 
		int getWidth();
		int getLength();

};

#endif