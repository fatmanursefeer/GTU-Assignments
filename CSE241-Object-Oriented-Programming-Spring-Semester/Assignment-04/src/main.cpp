#include <iostream>
#include <cstdlib>
#include <string>
#include "Robot.h"
#include "bulldozer.h"
#include "roomba.h"
#include "humanic.h"
#include "optimusprime.h"
#include "robocop.h"

using namespace std;

/* the program works steps 1) make pa4  2) ./pa4  */

int main()
{
    srand(time(0));  /* for range() */
    bulldozer bull_1, bull_2, bull_3(3, 50, 100);  /* all bulldozer objects */
    roomba room_1, room_2, room_3(2, 50, 100);  /* all roomba objects */
    optimusprime op_1, op_2, op_3(0, 50, 100);  /* all optimusprime objets */
    robocop robo_1, robo_2, robo_3(1, 50, 100);  /* all robocop objects */
    cout << "--Match 1--\n--bulldozer vs roomba--\n";
    match(bull_1, room_1);  /* matches bulldozer and roomba */
    cout << "-----------------------------------\n";
    cout << "--Match 2--\n--optimusprime vs robocop--\n";
    match(op_1, robo_1);  /* matches optimusprime and robocop */
    cout << "-----------------------------------\n";
    cout << "--Match 3--\n--bulldozer vs optimusprime--\n";
    match(bull_2, op_2);  /* matches bulldozer and optimusprime */
    cout << "-----------------------------------\n";
    cout << "--Match 4--\n--roomba vs robocop--\n";
    match(room_2, robo_2);  /* matches roomba and robocop */
    cout << "-----------------------------------\n";
    cout << "--Match 5--\n--bulldozer vs robocop--\n";
    match(bull_3, robo_3);  /* matches bulldozer and robocop */
    cout << "-----------------------------------\n";
    cout << "--Match 6--\n--roomba vs optimusprime--\n";
    match(room_3, op_3);  /* matches roomba and optimusprime */
    cout << "-----------------------------------\n";
}
