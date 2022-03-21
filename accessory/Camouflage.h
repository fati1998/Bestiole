#ifndef SRC_CAMOUFLAGE_H
#define SRC_CAMOUFLAGE_H
 
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "../UImg.h"
using namespace std;

class Critter;

class Camouflage{
private:

    double capacity;

public:
    Camouflage();
    Camouflage (const Camouflage* c);
    ~Camouflage();
    double getCapacity();
    string to_string();
    void draw( Critter* c,UImg & support);
    
};

#endif
