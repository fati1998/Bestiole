#include "Bestiole.h"

#include <iostream>
#include <iostream>

using namespace std;

int main(){
	Bestiole b = Bestiole(100,102);
	Bestiole b1 = Bestiole(100,102);
	cout << b.distance(b1)<<endl;
	cout << b.collision(b1)<<endl;
	cout << b.detection(b1)<<endl;
	b.comportementApresCollision();

	return 0;
}