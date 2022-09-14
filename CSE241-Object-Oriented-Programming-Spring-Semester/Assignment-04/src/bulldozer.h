#ifndef BULLDOZER_H
#define BULLDOZER_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "Robot.h"

using namespace std;

class bulldozer : public Robot
{
public:
    bulldozer();  /* no parameter constructor */
    bulldozer(int newType, int newStrength, int newHit);  /* constructor which takes 3 parameter */
    int getDamage();  /* this function calculates the damage */
    string getType();  /* this function returns type */
};

#endif