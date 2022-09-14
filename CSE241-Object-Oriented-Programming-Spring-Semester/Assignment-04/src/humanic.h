#ifndef HUMANIC_H
#define HUMANIC_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "Robot.h"

using namespace std;

class humanic : public Robot
{
public:
    virtual int getDamage() = 0;  /* for abstract class */
    virtual string getType() = 0;   /* for abstract class */
};

#endif