#include <iostream>
#include <cstdlib>
#include <string>
#include "Robot.h"

using namespace std;

int Robot::get_type() const
{
    return type;  /* returns type */
}

int Robot::getStrength() const
{
    return strength;  /* returns strength */
}

int Robot::getHitpoint() const
{
    return hitpoint;  /* returns hitpoint */
}

void Robot::setType(int newType)
{
    type = newType;  /* sets type */
}

void Robot::setStrength(int newStrength)
{
    strength = newStrength;  /* sets strength */
}

void Robot::setHitpoint(int newHitpoint)
{
    hitpoint = newHitpoint;  /* sets hitpoint */
}

void match(Robot& first, Robot& second)  /* matches robots */
{
    int damage, hitP, temp;
    while(1){  /* continues the game until one of them beats */
        if(first.getType() == "roomba")   /* if the robot type is roomba it continues two round */
            temp = 0;
        else
            temp = 1;
        while(temp < 2){
            damage = first.getDamage();   /* takes damage */
            hitP = second.getHitpoint();
            hitP = hitP - damage;   /* substruct from the hitpoint */
            second.setHitpoint(hitP);  /* sets the hitpoint new value */
            temp++;
            if(second.getHitpoint() <= 0)  /* if hitpoint less or equal than 0 the match ends */
                break;
        }
        if(second.getHitpoint() <= 0)  /* if hitpoint less or equal than 0 the match ends */
            break;
        if(second.getType() == "roomba")   /* if the robot type is roomba it continues two round */
            temp = 0;
        else
            temp = 1;
        while(temp < 2){
            damage = second.getDamage();   /* takes damage */
            hitP = first.getHitpoint();
            hitP = hitP - damage;   /* substruct from the hitpoint */
            first.setHitpoint(hitP);  /* sets the hitpoint new value */
            temp++;
            if(first.getHitpoint() <= 0)  /* if hitpoint less or equal than 0 the match ends */
                break;
        }
        if(first.getHitpoint() <= 0)  /* if hitpoint less or equal than 0 the match ends */
            break;
    }
    if(first.getHitpoint() < 0)
        cout << second.getType() << " is winner." << endl;  /* if the second robot wins the game this block works */
    else if(second.getHitpoint() < 0)
        cout << first.getType() << " is winner." << endl;  /* if the first robot wins the game this block works */
}