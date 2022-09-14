#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <chrono>
#include <thread>

using namespace std::this_thread;
using namespace std::chrono;
using namespace std;

#include "hw5.h"

namespace Games{
    void BoardGame2D::playUser()   /* this function plays with the user until the game ends. */
    {
        int flag, score;
        string movement;
        while(1){
            cout << "\n";
            //sleep_until(system_clock::now() + milliseconds(250));   /* wait */
            print();
            cout << "\n";
            cout << "\nEnter the move: (for PegSolitaire and EightPuzzle (2B-U)(2 is row, B is column and U is direction)\n  ";
            cout << "for Klotski (2U)(2 is block and U is direction)  \n";  /* takes the parameter to user */
            cin >> movement;
            playUser(movement);   /* sends the parameter and plays one move */
            flag = endGame();   /* checks the game ends */
            if(flag == 0){
                cout << "\n";
                sleep_until(system_clock::now() + milliseconds(250));  /* wait */
                print();
                score = boardScore();   /* returns board score */
                cout << "\nCongratulations game over.\nThe score is: " << score << endl;
                break;
            }
        }
    }

    void BoardGame2D::playAutoAll()   /* this function plays with computer until the game ends */
    {
        int flag, score;
        while(1){
            //cout << "\n";
            //sleep_until(system_clock::now() + milliseconds(250));   /* wait */
            //print();
            playAuto();   /* plays one move automatically */
            flag = endGame();   /* checks the game ends */
            if(flag == 0){
                cout << "\n";
                //sleep_until(system_clock::now() + milliseconds(250));   /* wait */
                print();
                score = boardScore();   /* returns the board scre */
                cout << "\nCongratulations game over.\nThe score is: " << score << endl;
                break;
            }
        }
    }
    
    void BoardGame2D::playVector(const vector<BoardGame2D *> &vec)
    {
        for(int i=0; i<vec.size(); i++){
            vec[i]->playAutoAll();
            sleep_until(system_clock::now() + milliseconds(1000));
        }
    }

    PegSolitaire::PegSolitaire()
    {
        initialize();   /* sets the board */
    }

    void PegSolitaire::playUser(string input)    /* plays one move with taken parameter */
    {
        int flag;
        convert_row(input[0]);
        column = input[1];
        convert_int_column();
        direction = input[3];
        flag = check_input();   /* cheks the parameter */
        if(flag == 0)
            cout << "\nYou entered wrong input.";
        else{
            flag = is_legal();   /* cheks the move is legal */
            if(flag == 0)
                cout << "\nYou can not play like that.";
            else{
                make_move();   /* and if everything is okey thn makes move */
                //cout << "\nMove: " << row << column << "-" << direction << endl;   /* prints the move */
            }
        }
    }

    void PegSolitaire::playAuto()   /* this function plays one move */
    {
        int flag, end_flag;
        while(1){
            column = make_rand_column();   /* makes rand column */
            row = make_rand_row();   /* makes rand row */
            direction = make_random_direction();   /* makes rand direction */
            flag = check_input();   /* checks the input */
            if(flag == 1){
                convert_int_column();   /* converts column to integer*/
                flag = is_legal();   /* checks the move is legal */
                if(flag == 1){
                    make_move();  /* if everything is okey then makes move. */
                    //cout << "\nMove: " << row << column << "-" << direction << endl;   /* prints the move. */
                    break;
                }
            }
        }
    }

    void PegSolitaire::convert_row(char r)   /* this function converts the row char to integer. */
    {
        char a = '1';
        for(int i=1; i<=7; i++){
            if(r == a){
                row = i;
                break;
            }
            a++;
        }
    }

    void PegSolitaire::convert_int_column()   /* this function converts the column char to integer */
    {
        char a = 'A';
        for(int i=1; i<=26; i++){
            if(column == a){
                i_column = i;
                break;
            }
            a++;
        }
    }

    bool PegSolitaire::check_input()   /* this function checks the input is valid or not */
    {
        if((direction != 'U') && (direction != 'D') && (direction != 'L') && (direction != 'R'))
            return false;
        if((row < 1) || (row > 7) || (column < 'A') || (column > 'G'))
            return false;
        return true;
    }

    bool PegSolitaire::is_legal()   /* this function checks the input is valid or not to make move */
    {
        if(board[row][i_column] != pegs::peg)
            return false;
        else if(direction == 'D'){
            if(board[row+1][i_column] == pegs::blank)
                return false;
            else if((board[row+2][i_column] != pegs::empty) || (board[row+1][i_column] != pegs::peg))
                return false;
        }
        else if(direction == 'R'){
            if(board[row][i_column+1] == pegs::blank)
                return false;
            else if((board[row][i_column+2] != pegs::empty) || (board[row][i_column+1] != pegs::peg))
                return false;
        }
        else if(direction == 'L'){
            if(board[row][i_column-1] == pegs::blank)
                return false;
            else if((board[row][i_column-2] != pegs::empty) || (board[row][i_column-1] != pegs::peg))
                return false;
        }
        else if(direction == 'U'){
            if(board[row-1][i_column] == pegs::blank)
                return false;
            else if((board[row-2][i_column] != pegs::empty) || (board[row-1][i_column] != pegs::peg))
                return false;
        }
        return true;
    }

    void PegSolitaire::make_move()   /* this function makes move if everything okey. */
    {
        if(direction == 'D'){
            board[row][i_column] = pegs::empty;
            board[row+1][i_column] = pegs::empty;
            board[row+2][i_column] = pegs::peg;
        }
        else if(direction == 'R'){
            board[row][i_column] = pegs::empty;
            board[row][i_column+1] = pegs::empty;
            board[row][i_column+2] = pegs::peg;
        }
        else if(direction == 'L'){
            board[row][i_column] = pegs::empty;
            board[row][i_column-1] = pegs::empty;
            board[row][i_column-2] = pegs::peg;
        }
        else if(direction == 'U'){
            board[row][i_column] = pegs::empty;
            board[row-1][i_column] = pegs::empty;
            board[row-2][i_column] = pegs::peg;
        }
    }

    bool PegSolitaire::endGame()    /* this function checks the game ends or not */
    {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if((board[i][j] == pegs::peg) && (board[i-1][j] == pegs::peg)){
                    if((board[i-2][j] == pegs::empty) || (board[i+1][j] == pegs::empty))
                        return true;
                }
                else if((board[i][j] == pegs::peg) && (board[i+1][j] == pegs::peg)){
                    if((board[i+2][j] == pegs::empty) || (board[i-1][j] == pegs::empty))
                        return true;
                }
                else if((board[i][j] == pegs::peg) && (board[i][j-1] == pegs::peg)){
                    if((board[i][j-2] == pegs::empty) || (board[i][j+1] == pegs::empty))
                        return true;
                }
                else if((board[i][j] == pegs::peg) && (board[i][j+1] == pegs::peg)){
                    if((board[i][j+2] == pegs::empty) || (board[i][j-1] == pegs::empty))
                        return true;
                }
            }
        }
        return false;
    }

    void PegSolitaire::print()  /* this function prints the current game board */
    {
        cout << "\x1b[2J";   /* this codes for ansi */
        cout << "\033[0;0H";
        cout << endl << endl;
        int k = 1;
        cout << "    A B C D E F G\n";
        for(int i=0; i<board.size(); i++){
            if((i >= 1) && (i < 8)){
                cout << k << " ";
                k++;
            }
            for(int j=0; j<board[i].size(); j++){
                if((board[i][j]) == pegs::blank)
                    cout << " ";
                else if((board[i][j]) == pegs::peg)
                    cout << "P";
                else
                    cout << ".";
                cout << " ";
            }
            cout << endl;
        }
    }

    int PegSolitaire::boardScore()  /* this function returns currents score of the board */
    {
        int peg = 0;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j] == pegs::peg)
                    peg++;
            }
        }
        return peg;
    }

    char PegSolitaire::make_rand_column()   /* this function makes rand column */
    {
        int x;
        char column = 'A';
        x = rand()%7;
        for(int i=0; i<x; i++){
            if(i == x)
                return column;
            column++;
        }
        return column;
    }

    int PegSolitaire::make_rand_row()   /* this function makes rand row */
    {
        int x;
        x = rand()%7 + 1;
        return x;
    }

    char PegSolitaire::make_random_direction()   /* this function makes rand direction */
    {
        int x;
        char dir;
        x = rand()%4;
        if(x == 0)
            dir = 'U';
        else if(x == 1)
            dir = 'L';
        else if(x == 2)
            dir = 'R';
        else if(x == 3)
            dir = 'D';
        return dir;
    }

    void PegSolitaire::initialize()   /* this function sets the initial board */
    {
        board =
        {
            {pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank},
            {pegs::blank, pegs::blank, pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::blank, pegs::blank, pegs::blank},
            {pegs::blank, pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::blank, pegs::blank},
            {pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::blank},
            {pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::empty, pegs::peg, pegs::peg, pegs::peg, pegs::blank},
            {pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::blank},
            {pegs::blank, pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::blank, pegs::blank},
            {pegs::blank, pegs::blank, pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::blank, pegs::blank, pegs::blank},
            {pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank}
        };    
    }

    EightPuzzle::EightPuzzle()
    {
        initialize();   /* sets the board */
    }

    void EightPuzzle::playUser(string input)   /* this function play one move */
    {
        int flag;
        convert_row(input[0]);   /* seperates the string properly */
        column = input[1];
        convert_int_column();
        direction = input[3];
        flag = check_input();   /* checks the input */
        if(flag == 0)
            cout << "\nYou entered wrong input.";
        else{
            flag = is_legal();  /* checks the input is legal for move */
            if(flag == 0)
                cout << "\nYou can not play like that.";
            else{
                make_move();  /* if everything is okey then makes move */
                cout << "\nMove: " << row << column << "-" << direction << endl;   /* prints the move */
            }
        }
    }

    void EightPuzzle::playAuto()   /* this function play one move */
    {
        int flag, end_flag;
        while(1){
            column = make_rand_column();  /* makes rand column */
            row = make_rand_row();   /* makes rand row */
            direction = make_random_direction();   /* makes rand direction */
            flag = check_input();   /* checks the input */
            if(flag == 1){
                convert_int_column();   /* converts the column */
                flag = is_legal();  /* checks the input is legal for move */
                if(flag == 1){
                    make_move();   /* if everything is okey then makes move */
                    //cout << "\nMove: " << row << column << "-" << direction << endl;   /* prints the move */
                    break;
                }
            }
        }
    }

    void EightPuzzle::make_move()   /* this function makes move */
    {
        int temp, temp2;
        if(direction == 'L'){   /* if direction is left then this block is works */
            temp = board[r1][c1];
            board[r1][c1] = board[r0][c0];
            c1--;
            while(c1 >= c0){
                temp2 = board[r1][c1];
                board[r1][c1] = temp;
                temp = temp2;
                c1--;
            }
        }
        else if(direction == 'R'){   /* if direction is right then this block is works */
            temp = board[r1][c1];
            board[r1][c1] = board[r0][c0];
            c1++;
            while(c1 <= c0){
                temp2 = board[r1][c1];
                board[r1][c1] = temp;
                temp = temp2;
                c1++;
            }
        }
        else if(direction == 'U'){   /* if direction is up then this block is works */
            temp = board[r1][c1];
            board[r1][c1] = board[r0][c0];
            r1--;
            while(r1 >= r0){
                temp2 = board[r1][c1];
                board[r1][c1] = temp;
                temp = temp2;
                r1--;
            }
        }
        else if(direction == 'D'){   /* if direction is down then this block is works */
            temp = board[r1][c1];
            board[r1][c1] = board[r0][c0];
            r1++;
            while(r1 <= r0){
                temp2 = board[r1][c1];
                board[r1][c1] = temp;
                temp = temp2;
                r1++;
            }
        }
    }

    bool EightPuzzle::is_legal()   /* this function checks the input is legal for move */
    {
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[i][j] == 0){
                    r0 = i;   /* finds the space coordinates */
                    c0 = j;
                }
            }
        }
        r1 = row-1;
        c1 = i_column-1;
        if(board[r1][c1] == 0)
            return false;
        else if((direction == 'L') && ((r1 != r0) || (c1 <= c0)))
            return false;
        else if((direction == 'R') && ((r1 != r0) || (c1 >= c0)))
            return false;
        else if((direction == 'U') && ((r1 <= r0) || (c1 != c0)))
            return false;
        else if((direction == 'D') && ((r1 >= r0) || (c1 != c0)))
            return false;
        return true;
    }

    bool EightPuzzle::check_input()   /* this function checks the input */
    {
        if((direction != 'U') && (direction != 'D') && (direction != 'L') && (direction != 'R'))
            return false;
        if((row < 1) || (row > 3) || (column < 'A') || (column > 'C'))
            return false;
        return true;
    }

    bool EightPuzzle::endGame()   /* this function checks if the game ends or not */
    {
        vector<vector<int>> temp_board   /* create temperary board */
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 0}
        };
        if(board == temp_board)   /* if the boards are same the game is over */
            return false;
        return true;
    }

    void EightPuzzle::print()   /* this function prints current board */
    {
        cout << "\x1b[2J";    /* these are for ansi */
        cout << "\033[0;0H";
        cout << endl << endl;
        int k=1;
        cout << "     A   B   C\n   ";
        for(int i=0; i<13; i++)
            cout << "-";
        cout << "\n";
        for(int i=0; i<3; i++){
            cout << k << ") ";
            for(int j=0; j<3; j++)
                cout << "|  " << board[i][j];
            cout << "|\n";
            k++;
        }
        cout << "   ";
        for(int i=0; i<13; i++)
            cout << "-";
    }

    int EightPuzzle::boardScore()   /* this function returns current board score */
    {
        int score=0;
        vector<vector<int>> tempBoard   /* create new board (end board) */
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 0}
        };
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(tempBoard[i][j] != board[i][j])
                    score++;   /* counts how many differ integer there are */
            }
        }
        return score;  /* returns the score */
    }

    char EightPuzzle::make_rand_column()   /* makes rand column */
    {
        int x;
        char column = 'A';
        x = rand()%3;
        for(int i=0; i<x; i++){
            if(i == x)
                return column;
            column++;
        }
        return column;
    }

    int EightPuzzle::make_rand_row()   /* makes rand row */
    {
        int x;
        x = rand()%3 + 1;
        return x;
    }

    char EightPuzzle::make_random_direction()    /* makes rand direction */
    {
        int x;
        char dir;
        x = rand()%4;
        if(x == 0)
            dir = 'U';
        else if(x == 1)
            dir = 'L';
        else if(x == 2)
            dir = 'R';
        else if(x == 3)
            dir = 'D';
        return dir;
    }

    void EightPuzzle::convert_int_column()   /* converts column char to integer */
    {
        char a = 'A';
        for(int i=1; i<=26; i++){
            if(column == a){
                i_column = i;
                break;
            }
            a++;
        }
    }

    void EightPuzzle::convert_row(char r)    /* converts row char to integer */
    {
        char a = '1';
        for(int i=1; i<=3; i++){
            if(r == a){
                row = i;
                break;
            }
            a++;
        }
    }

    bool EightPuzzle::is_solvable()   /* checks if the random board is solvable or not if not then creates another rand board */
    {
        int count = 0, result;
        vector<int> temp;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++)
                temp.push_back(board[i][j]);
        }
        for(int i=0; i<8; i++){
            for(int j=i+1; j<9; j++){
                if((temp[i]) && (temp[j]) && (temp[i] > temp[j]))
                    count++;
            }
        }
        result = count % 2;
        if(result == 0)
            return true;
        return false;
    }

    void EightPuzzle::initialize()  /* sets the board */
    {
        int k, l, temp;
        board =
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 0}
        };    
        while(1){   /* rands the board until its solvable */
            for(int i=2; i>0; i--){
                for(int j=2; j>0; j--){
                    k = rand() % (i+1);
                    l = rand() % (j+1);
                    temp = board[i][j];
                    board[i][j] = board[k][l];
                    board[k][l] = temp;
                }
            }
            if(is_solvable())  /* if the board solvable then breaks the loop */
                break;
        }
    }

    Klotski::Klotski()
    {
        initialize();   /* sets the board */
    }

    void Klotski::playUser(string index)   /* this function plays with user until the game ends */
    {
        int flag;
        convert_input(index[0]);
        direction = index[1];
        flag = check_input();   /* checks the input */
        if(flag == 0)
            cout << "\nYou entered wrong input.";
        else{
            flag = is_legal();   /* checks the input for move */
            if(flag == 0)
                cout << "\nYou can not play like that.";
            else{
                make_move();   /* if everything is okey then makes move */
                cout << "\nMove: " << input << direction << endl;  /* prints the move */
            }
        }
    }

    void Klotski::playAuto()    /* this function play one move */
    {
        int flag, end_flag;
        while(1){
            input = make_rand_move();  /* makes rand move */
            direction = make_random_direction();   /* makes rand direction */
            flag = check_input();   /* checks the input */
            if(flag == 1){
                flag = is_legal();   /* checks the input for move is legal */
                if(flag == 1){
                    make_move();   /* if everything is okey then makes move */
                    //cout << "\nMove: " << input << direction << endl;   /* prints the move */
                    break;
                }
            }
        }
    }

    void Klotski::make_move()   /* this function makes move */
    {
        if(direction == 'L'){   /* if direction is left this block works */
            if((input == 0) || (input == 1) || (input == 2) || (input == 3)){   /* if the blocks are 1x1 then moves */
                board[r0][c0-1] = input;
                board[r0][c0] = 10;
            }
            else if((input == 4) || (input == 5) || (input == 7) || (input == 8)){   /* if the blocks are 1x2 then moves */
                board[r0][c0-1] = input;
                board[r0+1][c0-1] = input;
                board[r0][c0] = 10;
                board[r0+1][c0] = 10;
            }
            else if(input == 6){  /* if the blocks are 2x1 then moves */
                board[r0][c0-1] = input;
                board[r0][c0+1] = 10;
            }
            else if(input == 9){     /* if the blocks are 2x2 then moves */
                board[r0][c0-1] = input;
                board[r0+1][c0-1] = input;
                board[r0][c0+1] = 10;
                board[r0+1][c0+1] = 10;
            }
        }
        else if(direction == 'R'){   /* if direction is right this block works */
            if((input == 0) || (input == 1) || (input == 2) || (input == 3)){   /* if the blocks are 1x1 then moves */
                board[r0][c0+1] = input;
                board[r0][c0] = 10;
            }
            else if((input == 4) || (input == 5) || (input == 7) || (input == 8)){   /* if the blocks are 1x2 then moves */
                board[r0][c0+1] = input;
                board[r0+1][c0+1] = input;
                board[r0][c0] = 10;
                board[r0+1][c0] = 10;
            }
            else if(input == 6){   /* if the blocks are 2x1 then moves */
                board[r0][c0+2] = input;
                board[r0][c0] = 10;
            }
            else if(input == 9){   /* if the blocks are 2x2 then moves */
                board[r0][c0+2] = input;
                board[r0+1][c0+2] = input;
                board[r0][c0] = 10;
                board[r0+1][c0] = 10;
            }
        }
        else if(direction == 'U'){   /* if direction is up this block works */
            if((input == 0) || (input == 1) || (input == 2) || (input == 3)){   /* if the blocks are 1x1 then moves */
                board[r0-1][c0] = input;
                board[r0][c0] = 10;
            }
            else if((input == 4) || (input == 5) || (input == 7) || (input == 8)){   /* if the blocks are 1x2 then moves */
                board[r0-1][c0] = input;
                board[r0+1][c0] = 10;
            }
            else if(input == 6){   /* if the blocks are 2x1 then moves */
                board[r0-1][c0] = input;
                board[r0-1][c0+1] = input;
                board[r0][c0] = 10;
                board[r0][c0+1] = 10;
            }
            else if(input == 9){   /* if the blocks are 2x2 then moves */
                board[r0-1][c0] = input;
                board[r0-1][c0+1] = input;
                board[r0+1][c0] = 10;
                board[r0+1][c0+1] = 10;
            }
        }
        else if(direction == 'D'){   /* if direction is down this block works */
            if((input == 0) || (input == 1) || (input == 2) || (input == 3)){    /* if the blocks are 1x1 then moves */
                board[r0+1][c0] = input;
                board[r0][c0] = 10;
            }
            else if((input == 4) || (input == 5) || (input == 7) || (input == 8)){  /* if the blocks are 1x2 then moves */
                board[r0+2][c0] = input;
                board[r0][c0] = 10;
            }
            else if(input == 6){  /* if the blocks are 2x1 then moves */
                board[r0+1][c0] = input;
                board[r0+1][c0+1] = input;
                board[r0][c0] = 10;
                board[r0][c0+1] = 10;
            }
            else if(input == 9){  /* if the blocks are 2x2 then moves */
                board[r0+2][c0] = input;
                board[r0+2][c0+1] = input;
                board[r0][c0] = 10;
                board[r0][c0+1] = 10;
            }
        }
    }

    bool Klotski::is_legal()   /* this function checks the input is legal for move */
    {
        int flag = 0;
        for(int i=0; i<5; i++){
            for(int j=0; j<4; j++){
                if(board[i][j] == input){
                    r0 = i;     /* finds the blocks coordinates */
                    c0 = j;
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                break;
        }
        /* this if else blocks checks the boundary of the board */
        if(direction == 'L'){    /* if direction is left this block works */
            if((input == 0) || (input == 1) || (input == 2) || (input == 3)){    /* if the blocks are 1x1 then moves */
                if(c0 <= 0)
                    return false;
                if(board[r0][c0-1] != 10)
                    return false;
            }
            else if((input == 4) || (input == 5) || (input == 7) || (input == 8)){    /* if the blocks are 1x2 then moves */
                if(c0 <= 0)
                    return false;
                if((board[r0][c0-1] != 10) || (board[r0+1][c0-1] != 10))
                    return false;
            }
            else if(input == 6){    /* if the blocks are 2x1 then moves */
                if(c0 <= 0)
                    return false;
                if(board[r0][c0-1] != 10)
                    return false;
            }
            else if(input == 9){    /* if the blocks are 2x2 then moves */
                if(c0 <= 0)
                    return false;
                if((board[r0][c0-1] != 10) || (board[r0+1][c0-1] != 10))
                    return false;
            }
        }
        else if(direction == 'R'){    /* if direction is right this block works */
            if((input == 0) || (input == 1) || (input == 2) || (input == 3)){    /* if the blocks are 1x1 then moves */
                if(c0 >= 3)
                    return false;
                if(board[r0][c0+1] != 10)
                    return false;
            }
            else if((input == 4) || (input == 5) || (input == 7) || (input == 8)){    /* if the blocks are 1x2 then moves */
                if(c0 >= 3)
                    return false;
                if((board[r0][c0+1] != 10) || (board[r0+1][c0+1] != 10))
                    return false;
            }
            else if(input == 6){    /* if the blocks are 2x1 then moves */
                if(c0 >= 3)
                    return false;
                if(board[r0][c0+2] != 10)
                    return false;
            }
            else if(input == 9){    /* if the blocks are 2x2 then moves */
                if(c0 >= 3)
                    return false;
                if((board[r0][c0+2] != 10) || (board[r0+1][c0+2] != 10))
                    return false;
            }
        }
        else if(direction == 'U'){    /* if direction is up this block works */
            if((input == 0) || (input == 1) || (input == 2) || (input == 3)){    /* if the blocks are 1x1 then moves */
                if(r0 <= 0)
                    return false;
                if(board[r0-1][c0] != 10)
                    return false;
            }
            else if((input == 4) || (input == 5) || (input == 7) || (input == 8)){    /* if the blocks are 1x2 then moves */
                if(r0 <= 0)
                    return false;
                if(board[r0-1][c0] != 10)
                    return false;
            }
            else if(input == 6){    /* if the blocks are 2x1 then moves */
                if(r0 <= 0)
                    return false;
                if((board[r0-1][c0] != 10) || (board[r0-1][c0+1] != 10))
                    return false;
            }
            else if(input == 9){    /* if the blocks are 2x2 then moves */
                if(r0 <= 0)
                    return false;
                if((board[r0-1][c0] != 10) || (board[r0-1][c0+1] != 10))
                    return false;
            }
        }
        else if(direction == 'D'){    /* if direction is down this block works */
            if((input == 0) || (input == 1) || (input == 2) || (input == 3)){    /* if the blocks are 1x1 then moves */
                if(r0 > 3)
                    return false;
                if(board[r0+1][c0] != 10)
                    return false;
            }
            else if((input == 4) || (input == 5) || (input == 7) || (input == 8)){    /* if the blocks are 1x2 then moves */
                if(r0 >= 3)
                    return false;
                if(board[r0+2][c0] != 10)
                    return false;
            }
            else if(input == 6){    /* if the blocks are 2x1 then moves */
                if(r0 > 3)
                    return false;
                if((board[r0+1][c0] != 10) || (board[r0+1][c0+1] != 10))
                    return false;
            }
            else if(input == 9){    /* if the blocks are 2x2 then moves */
                if(r0 >= 3)
                    return false;
                if((board[r0+2][c0] != 10) || (board[r0+2][c0+1] != 10))
                    return false;
            }
        }
        return true;
    }

    bool Klotski::check_input()  /* this function checks the input */
    {
        if((direction != 'U') && (direction != 'D') && (direction != 'L') && (direction != 'R'))
            return false;
        if((input < 0) || (input > 9))
            return false;
        return true;
    }

    bool Klotski::endGame()    /* this function checks the game ends or not */
    {
        if((board[4][1] == 9) && (board[4][2] == 9))    /* ends condition is 2x2 blocks must to been end of the board */
            return false;
        return true;
    }

    void Klotski::print()   /* this function prints the current board */
    {
        cout << "\x1b[2J";   /* this for ansi */
        cout << "\033[0;0H";
        cout << endl << endl;
        cout << "\n";
        for(int i=0; i<5; i++){
            for(int j=0; j<4; j++){
                if(board[i][j] < 10)
                    cout << board[i][j] << " ";
                else
                    cout << "  ";
            }
            cout << "\n";
        }
    }

    int Klotski::boardScore()   /* this function returns current board score */
    {
        int score=0;
        vector<vector<int>> temp_board   /* create temperary ends board */
        {
            {4, 5, 7, 8},
            {4, 5, 7, 8},
            {0, 1, 6, 6},
            {10, 9, 9, 2},
            {10, 9, 9, 3}
        };
        if((board[4][1] == 9) && (board[4][2] == 9))  /* if the game ends returns 0 mean best score */
            return score;
        if(temp_board == board)   /* if these are equal returns 0 (the best score) */
            return score;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(temp_board[i][j] != board[i][j])
                    score++;  /* if the game is not ends then its count how many differ blocks and returns that score */
            }
        }
        return score;
    }

    char Klotski::make_random_direction()  /* this function makes rand direction */
    {
        int x;
        char dir;
        x = rand()%4;
        if(x == 0)
            dir = 'U';
        else if(x == 1)
            dir = 'L';
        else if(x == 2)
            dir = 'R';
        else if(x == 3)
            dir = 'D';
        return dir;
    }

    int Klotski::make_rand_move()   /* this function makes rand moves */
    {
        int x;
        x = rand()%10;
        return x;
    }

    void Klotski::convert_input(char temp)   /* this function converts the move char to integer */
    {
        char a = '0';
        for(int i=0; i<10; i++){
            if(temp == a){
                input = i;
                break;
            }
            a++;
        }
    }

    void Klotski::initialize()   /* this function sets the initial board */
    {
        board =
        {
            {7, 9, 9, 8},
            {7, 9, 9, 8},
            {4, 6, 6, 5},
            {4, 2, 3, 5},
            {0, 10, 10, 1}
        };
    }
}