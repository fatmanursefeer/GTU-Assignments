#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Robot
{
public:
    virtual int getDamage() = 0;  /* for abstract class */
    virtual string getType() = 0;  /* for abstract class */
    friend void match(Robot& first, Robot& second);  /* this function takes two robots object and continues the game until one of them beats */
    int get_type() const;  /* this function returns the type types integer */
    int getStrength() const;  /* this function returns the strength */
    int getHitpoint() const;  /* this function returns the hitpoint */
    void setType(int newType);  /* this function sets the type */
    void setStrength(int newStrength);  /* this function sets the strength */
    void setHitpoint(int newHitpoint);  /* this function sets the hitpoint */
private:
    int type;  /* these are data members */
    int strength;
    int hitpoint;
};

#endif