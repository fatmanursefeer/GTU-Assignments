#ifndef HW5_H
#define HW5_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class pegs {empty, peg, blank};

namespace Games{

    class BoardGame2D    /* create base class */
    {
    public:
        virtual void playUser() final;   /* this function plays with user until the game ends. */
        virtual void playUser(string input) = 0;    /* this function plays one move */
        virtual void playAuto() = 0;   /* this function plays one move */
        virtual void playAutoAll() final;    /* this function plays with computer until game ends */
        virtual void print() = 0;    /* this function prints the current game board. */
        /*friend ostream& operator <<(ostream &outs, const BoardGame2D & other);   I can not do this function */
        virtual bool endGame() = 0;   /* this function checks the game end or not */
        virtual int boardScore() = 0;  /* this function returns the board score */
        virtual void initialize() = 0;  /* this function sets the board */
        static void playVector(const vector<BoardGame2D *> &vec);   /* this function keeps all the objects. */
    };

    class PegSolitaire : public BoardGame2D    /* create derived class*/
    {
    public:
        PegSolitaire();   /* no parameter constructor */
        void playUser(string input);    /* this function plays one move */
        void playAuto();   /* this function plays one move */
        void print();   /* this function prints the current game board. */
        bool endGame();   /* this function checks the game end or not */
        int boardScore();  /* this function returns the board score */
        void initialize();   /* this function sets the board */
    private:
        vector<vector<pegs>> board;   /* I assigned the variables and some private nessesery functions in here */
        int row, i_column;
        char column, direction;
        void convert_row(char r);
        void convert_int_column();
        void make_move();
        bool check_input();
        bool is_legal();
        char make_random_direction();
        char make_rand_column();
        int make_rand_row();
    };

    class EightPuzzle : public BoardGame2D
    {
    public:
        EightPuzzle();   /* no parameter constructor */
        void playUser(string input);     /* this function plays one move */
        void playAuto();   /* this function plays one move */
        void print();  /* this function prints the current game board. */
        bool endGame();   /* this function checks the game end or not */
        int boardScore();  /* this function returns the board score */
        void initialize();   /* this function sets the board */
        
    private:
        vector<vector<int>> board;   /* I assigned the variables and some private nessesery functions in here */
        int row, i_column, r0, c0, r1, c1;
        char direction, column;
        void convert_row(char r);
        void convert_int_column();
        void make_move();
        bool check_input();
        bool is_legal();
        bool is_solvable();
        char make_random_direction();
        char make_rand_column();
        int make_rand_row();
    };

    class Klotski : public BoardGame2D
    {
    public:
        Klotski();   /* no parameter constructor */
        void playUser(string input);    /* this function plays one move */
        void playAuto();   /* this function plays one move */
        void print();  /* this function prints the current game board. */
        bool endGame();   /* this function checks the game end or not */
        int boardScore();   /* this function returns the board score */
        void initialize();   /* this function sets the board */
    private:
        vector<vector<int>> board;   /* I assigned the variables and some private nessesery functions in here */
        int input, r0, c0;
        char direction;
        void make_move();
        void convert_input(char temp);
        bool check_input();
        bool is_legal();
        char make_random_direction();
        int make_rand_move();
    };
    
}

#endif