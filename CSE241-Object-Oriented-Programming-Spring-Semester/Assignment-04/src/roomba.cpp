#include <iostream>
#include <cstdlib>
#include <string>
#include "roomba.h"

using namespace std;

roomba::roomba()  /* no parameter constructor */
{
    setType(2);  /* sets type 2 */
    setStrength(50);  /* sets strength 50 */
    setHitpoint(100);  /* sets hitpoint 100 */
}

roomba::roomba(int newType, int newStrength, int newHit)  /* constructor which takes 3 parameter */
{
    setType(newType);  /* sets type */
    setStrength(newStrength);  /* sets strength */
    setHitpoint(newHit);  /* sets hitpoint */
}

string roomba::getType()  /* returns the type */
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

int roomba::getDamage()  /* calculates the damage and returns it */
{
    int damage;
    damage = (rand() % getStrength()) + 1;  /* calculate damage range (0, strength] */
    cout << getType() << " attacks for " << damage << " points!" << endl;
    return damage;  /* returns damage */
}