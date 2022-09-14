#ifndef OPTIMUSPRIME_H
#define OPTIMUSPRIME_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "Robot.h"
#include "humanic.h"

using namespace std;

class optimusprime : public humanic
{
public:
    optimusprime();  /* no parameter constructor */
    optimusprime(int newType, int newStrength, int newHit);  /* constructor which takes 3 parameter */
    int getDamage();  /* this function calculates the damage */
    string getType();  /* this function returns type */
};

#endif