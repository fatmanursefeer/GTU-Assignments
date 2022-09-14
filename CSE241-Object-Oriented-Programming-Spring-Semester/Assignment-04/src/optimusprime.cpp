#include <iostream>
#include <cstdlib>
#include <string>
#include "optimusprime.h"

using namespace std;

optimusprime::optimusprime()  /* no parameter constructor */
{
    setType(0);  /* sets type 0 */
    setStrength(50);  /* sets strength 50 */
    setHitpoint(100);  /* sets hitpoint 100 */
}

optimusprime::optimusprime(int newType, int newStrength, int newHit)  /* constructor which takes 3 parameter */
{
    setType(newType);  /* sets type */
    setStrength(newStrength);  /* sets strength */
    setHitpoint(newHit);  /* sets hitpoint */
}

string optimusprime::getType()  /* this function returns type */
{
    switch (get_type())  /* takes type type of integer */
    {
        case 0: return "optimusprime";
        case 1: return "robocop";
        case 2: return "roomba";
        case 3: return "bulldozer";
    }
    return "unknown";
}

int optimusprime::getDamage()  /* calculates the damage and returns it */
{
    int damage, possibility;
    damage = (rand() % getStrength()) + 1;  /* calculate damage range (0, strength] */
    possibility = rand() % 10;  /* for chance 10% */
    if(possibility == 2)
        damage = damage + 50;  /* if it is lucky it gain 50 extra damage point */
    possibility = rand() % 15;  /* for chance 15% */
    if(possibility == 2)
        damage = damage * 2;  /* if it is lucky it doubles the damage poits */
    cout << getType() << " attacks for " << damage << " points!" << endl;
    return damage;  /* returns the damage */
}