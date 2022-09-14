#ifndef ROBOCOP_H
#define ROBOCOP_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "Robot.h"
#include "humanic.h"

using namespace std;

class robocop : public humanic
{
public:
    robocop();  /* no parameter constructor */
    robocop(int newType, int newStrength, int newHit);  /* constructor which takes 3 parameter */
    int getDamage();  /* this function calculates the damage */
    string getType();  /* this function returns type */
};

#endif