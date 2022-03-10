#include "Critter.h"
#include "Sensor.h"
#include "Eye.h"
#include "Ear.h"
#include <iostream>
#include <list>

using namespace std;

int main(){
	// Test Critter
	
	Critter b = Critter(2,2);
	Critter b1 = Critter(2,2);
	cout << b.to_string() << endl;
	cout << b1.to_string() << endl;
	cout << b.detection(&b1);
	/*
	cout << b.distance(b1)<<endl;
	cout << b.collision(b1)<<endl;
	cout << b.detection(b1)<<endl;
	b.behaviorAfterCollision();
	cout <<b.to_string()<< endl;
	Critter* copy = b1.clone();
	cout <<b1.to_string()<< endl;
	cout <<copy->to_string()<< endl;
	cout<< b.myEyeDetects(b);
	// Test Eye
	
	Eye s = Eye();
	cout << s.getDistance()<<endl;
	cout << s.getField()<<endl;
	cout << s.getDetectionCapacity()<<endl;
	Sensor*  c = s.clone();
	cout << s.to_string() << endl;
	// Test Ear

	Ear r = Ear();
	cout << s.getDistance()<<endl;
	*/

}