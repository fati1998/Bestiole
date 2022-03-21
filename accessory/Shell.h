#ifndef SRC_SHELL_H
#define SRC_SHELL_H

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "../UImg.h"

using namespace std;

class Critter;

class Shell{
private:
    static const double COEF_MAX;
    static const double FACTOR_MAX;
    double coef;
    double factor;

public:
    Shell();
    Shell (const Shell* s);
    ~Shell();
    double getCoef();
    double getFactor();
    string to_string();
    void draw( Critter* c,UImg & support);
};

#endif 
