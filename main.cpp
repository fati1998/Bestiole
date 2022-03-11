#include "Critter.h"
#include "sensor/Sensor.h"
#include "sensor/Eye.h"
#include "sensor/Ear.h"
#include <iostream>
#include <list>
#include "behavior/Behavior.h"
#include "behavior/Fearful.h"
#include "behavior/Careful.h"
#include "behavior/SuicideBomber.h"
#include "behavior/Gregarious.h"
#include "behavior/MultipleBehavior.h"
using namespace std;
int main(){
	// Test Critter
	
	Critter b = Critter(2,2);
	Critter b1 = Critter(2,2);
	cout << b.to_string() << endl;
	cout << b1.to_string() << endl;
	cout << b.detection(&b1);
	Fearful c1 =  Fearful();
	Careful c2 =  Careful();
	Gregarious c3 =  Gregarious();
	MultipleBehavior c4 =  MultipleBehavior();
	SuicideBomber c5 =  SuicideBomber();
	cout<< c1.getColor() <<endl;
	cout<< c2.getColor() <<endl;
	cout<< c3.getColor() <<endl;
	cout<< c4.getColor() <<endl;
	cout<< c5.getColor() <<endl;

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