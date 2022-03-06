#include "Critter.h"

#include <iostream>
#include <iostream>

using namespace std;

int main(){
	Critter b = Critter(100,102);
	Critter b1 = Critter(100,102);
	cout << b.distance(b1)<<endl;
	cout << b.collision(b1)<<endl;
	cout << b.detection(b1)<<endl;
	b.behaviorAfterCollision();
	cout <<b.to_string()<< endl;
	Critter* copy = b1.clone();
	cout <<b1.to_string()<< endl;
	cout <<copy->to_string()<< endl;
	return 0;
}