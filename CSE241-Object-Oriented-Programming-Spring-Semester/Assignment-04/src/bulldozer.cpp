#include <iostream>
#include <cstdlib>
#include <string>
#include "bulldozer.h"

using namespace std;

bulldozer::bulldozer()  /* no parameter constructor */
{
    setType(3);  /* sets type 3 */
    setStrength(10);  /* sets strength 10 */
    setHitpoint(10);  /* sets hitpoint 10 */
}

bulldozer::bulldozer(int newType, int newStrength, int newHit)  /* constructor which takes 3 parameter */
{
    setType(newType);  /* sets type */
    setStrength(newStrength);  /* sets strength */
    setHitpoint(newHit);  /* sets hitpoint */
}

string bulldozer::getType()  /* returns type */
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

int bulldozer::getDamage()  /* calculates the damage and returns it */
{
    int damage;
    damage = (rand() % getStrength()) + 1;  /* calculate damage range (0,strength] */
    cout << getType() << " attacks for " << damage << " points!" << endl;
    return damage;  /* returns damage */
}