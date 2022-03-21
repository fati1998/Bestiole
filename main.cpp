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
#include "Environment.h"
#include "Aquarium.h"

#include <vector> 
#include <algorithm>
using namespace std;
int main(){

   Aquarium  ecosysteme( 960, 700);

   ecosysteme.run();

   return 0;

}