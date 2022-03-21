#ifndef _AQUARIUM_H_
#define _AQUARIUM_H_
#include "Environment.h"
#include <CImg.h>
#include <string>
using namespace std;
using namespace cimg_library;
class Aquarium: public CImgDisplay{

	private:
		Environment* env;
	public:
		Aquarium(int width, int length);
		~Aquarium();
		void birth();
		void kill(int id);
		void clone(int id);
		void setBehavior(int id, string const &  behavior);
		void run();
};

#endif