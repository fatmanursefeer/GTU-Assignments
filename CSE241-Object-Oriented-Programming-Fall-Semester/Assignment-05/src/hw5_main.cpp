#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <thread>

#include "hw5.h"

using namespace Games;
using namespace std::this_thread;
using namespace std::chrono;

int main(){
    srand(time(NULL));
    PegSolitaire p1, p2;   /* creates the variables. */
    EightPuzzle e1, e2;
    Klotski k1, k2;
    vector<BoardGame2D *> vec;

    vec.push_back(&p1);  /* fill the vector with push_back function. */
    vec.push_back(&e1);
    vec.push_back(&k1);
    vec.push_back(&p2);
    vec.push_back(&e2);
    vec.push_back(&k2);
    BoardGame2D::playVector(vec);   /* plays all the objects until the all ends. */

    PegSolitaire p3;
    EightPuzzle e3;
    Klotski k3;

    cout << "\n\nThe p3 object is play one step. ";
    p3.playAuto();   /* plays one move automatically. */
    cout << "\nAfter one step play p3 is like that.\n ";
    p3.print();   /* prints after the one move */
    cout << "\nThe score of the p3 board is: " << p3.boardScore();     /* writes the board score */

    e3.print();   /* prints the board */
    string ent = "3C-U";
    e3.playUser(ent);   /* plays one move with user. */
    cout << "\nAfter one step play e3 is like that.\n ";
    e3.print();   /* prints the current board */
    cout << "\n\nThe e3 board is ends? (if ends it writes 0 if not it writes 1) :  " << e3.endGame();   /* checks the game ends or not */
    cout << "\nThe score of the e3 board is: " << e3.boardScore();  /* prints the current board. */
    cout << "\n\n";

    Klotski k4;
    k4.BoardGame2D::playAutoAll();   /* plays until the game ends */
    sleep_until(system_clock::now() + milliseconds(1000));   /* wait */

    PegSolitaire p4;
    p4.BoardGame2D::playUser();   /* plays with user until the game ends. */


}