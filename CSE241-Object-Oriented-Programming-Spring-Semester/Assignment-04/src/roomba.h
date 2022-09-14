#ifndef ROOMBA_H
#define ROOMBA_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "Robot.h"

using namespace std;

class roomba : public Robot
{
public:
    roomba();  /* no parameter constructor */
    roomba(int newType, int newStrength, int newHit);  /* constructor which takes 3 parameter */
    int getDamage();  /* this function calculates the damage */
    string getType();  /* this function returns type */
};

#endif