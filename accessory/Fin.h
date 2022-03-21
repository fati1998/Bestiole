#ifndef SRC_FIN_H
#define SRC_FIN_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "../UImg.h"
using namespace std;
class Critter;

class Fin{
private:
    
    double coef;
 
public:
    Fin();
    Fin (const Fin* f);
    ~Fin();
    double getCoef();
    string to_string();
    void draw( Critter* c,UImg & support);
    
};

#endif 
