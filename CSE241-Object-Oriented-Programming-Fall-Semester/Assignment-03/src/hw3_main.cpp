#include <iostream> 
#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime> 
#include <fstream>

using namespace std;

enum class pegs {empty, peg, blank};

class PegSolitaire
{
public:
    class Cell
    {
        public:
            Cell(pegs location) { set_location(location); }   /* Sets the state of the cells. */
            inline void set_location(pegs loc) { location = loc; }   /* Sets the state of the cells. */
            void set_row(int r) { row = r; }   /* Sets the row of the cells. */
            void set_column(int c);   /* Sets the column of the cells. */
            int get_row() const { return row; }    /* Gets the row of the cells. */
            char get_column() const { return column; }   /* Gets the column of the cells. */
            pegs get_cellType() const { return location; }    /* Gets the state of the cells. */

        private:
            int row;    /* Initialize of the row. */
            char column;   /* Initialize of the column. */
            pegs location;   /* Initialize of the state. */
    };

    PegSolitaire(int boardNumber);   /* If the user enters just the board number this object works. */
    PegSolitaire(int sizeRow, int sizeColumn);  /* If the user enters size of the board (for square boards) this object works. */
    PegSolitaire(string commend);   /* If the user wants to load of the any arbitrary or given board and enters load or save this object works. */
    PegSolitaire();   /* If the user enters nothing this object works and sets square board size of 5x5 */

    void playGame();  /* User just enters board number and then the game continius until the to stay any moves. (just like computer game). */
    void play();  /* User just enters board number and the automatically make a move just 1 step. */
    void play(string user_column, string user_row, string user_direction);  /* User enters board number and movement informations and then the game make a move just 1 step. */
    bool compare(PegSolitaire & other);  /* This function takes a another PegSolitaire object and compares the remain pegs of the board and returns true or false. */
        
private:
    vector<vector<Cell>> board;   /* Initialize of the 2D vector. */
    int remain_peg, remain_empty, taken_peg, board_type, u_row, i_column, table6_direction, g_row, g_column, r_size, c_size, f;  /* Initialize of the variables. */
    char u_column, direction;
    string board_number;
    void print_board_1_and_4() const;  /* Prints the board 1 and 4 */
    void print_board_2_and_5() const;  /* Prints the board 2 and 5 */
    void print_board_3() const;   /* Prints the board 3 */
    void print_board_6() const;   /* Prints the board 6 */
    void print_arbitrary_board() const;   /* Prints the arbitrary boards */
    void print_square_board() const;   /* Prints the square boards */
    void count_pegs();  /* Counts the how many remain pegs, empty cells and taken pegs. */
    void set_given_board();   /* Sets the given boards. */
    void set_special_board(int r_size, int c_size);   /* Sets the square boards. */
    void set_arbitrary_board(ifstream &f);  /* Sets the arbitrary boards. */
    void read_arbitrary_board(ifstream &f);  /* Reads the file. */
    void read_file();    /* Reads the file. */
    void write_file();   /* Write to file. */
    void get_commend();  /* Take the infi from the user (for load and save). */
    void make_move();  /* Makes the move. */
    void make_move_table6();   /* Makes the moves for board 6 */
    void covert_char(char column);   /* Convert to char column to integer column. */
    char make_random_direction();   /* Makes random direction. */
    char make_rand_column();  /* Makes the random column. */
    int make_rand_row();   /* Makes the random row. */
    int make_rand_direction2();   /* Makes the random direction (for nortwest, southwest, southeast and northeast). */
    bool check_input();   /* Checks of the inputs. */
    bool is_legal();   /* Checks of the inputs for movement. */
    bool is_legal_for_table6();   /* Cheks of the inputs for movements for board 6. */
    bool check_end();  /* Checks the game end. */
    bool check_end_table6();  /* Cheks the game end for board 6 */
};

int main(){
    /* In the main I tested my object and I try to show the all game modes as possible as I can. (Main function like a test function)*/
    srand(time(NULL));   /* Make random integers for rand functions. */
    PegSolitaire player1(1);  /* Create first player object. */
    PegSolitaire player2;  /* Create second player object. */
    PegSolitaire player3(7, 7);   /* Create third player object. */
    cout << "\n----------FIRST STEP----------\n";
    PegSolitaire player4("load");  /* Create fourth player object. */
    PegSolitaire player5(6);  /* Create fifth player object. */
    cout << "\n----------SECOND STEP----------\n";
    player1.play();  /* Plays just 1 step. */
    cout << "\n----------THIRD STEP----------\n";
    player3.playGame();  /* Plays until the game over. */
    cout << "\n----------FOURTH STEP----------\n";
    player2.play("c", "5", "n");   /* Plays just 1 step. */
    cout << "\n----------FIFTH STEP----------\n";
    int remain = player2.compare(player1);   /* Compare to two boards. */
    cout << "\nBoolean result: " << remain << endl;
    cout << "\n----------SIXTH STEP----------\n";
    player5.playGame();  /* Plays until the game over. */
}


PegSolitaire::PegSolitaire(int boardNumber)
                            :board_type(boardNumber)
{
    set_given_board();  /* Object initialization and sets the proper board. */
}

PegSolitaire::PegSolitaire(int sizeRow, int sizeColumn)
                            :r_size(sizeRow), c_size(sizeColumn)
{
    set_special_board(r_size, c_size);   /* Object initialization and sets the proper board. */
}

PegSolitaire::PegSolitaire() : r_size(5), c_size(5)
{
    set_special_board(r_size, c_size);    /* Object initialization and sets the proper board. */
}

PegSolitaire::PegSolitaire(string commend)
{
    /* Object initialization. */
    int temp;
    for(int i=0; i<commend.size(); i++)
        commend[i] = toupper(commend[i]);
    if(commend == "LOAD"){   /* If the user wants to load any board this works. */
        read_file();   /* Read the file and sets the board. */
        cout << "\n\nMENU\n1) Press 1 if you want the computer to play.\n2) Press 2 if you want to play one step automatically.";
        cout << "\n3) Press 3 if you want to play one step own your own.\n";
        cin >> temp;   /* Is asked to user what do her want to board. */
        if(temp == 1)
            playGame();
        else if(temp == 2)
            play();
        else if(temp == 3){
            print_arbitrary_board();
            string r, c, d;
            cout << "\nColumn: ";
            cin >> c;
            cout << "\nRow: ";
            cin >> r;
            cout << "\nDirection: ";
            cin >> d;
            play(c, r, d);
        }
        else{
            cout << "\nYou entered wrong input.";  /* If the user enters wrong input the program will ends. */
            exit(1);
        }
    }
    else if(commend == "SAVE"){   /* If the user wants to save to board this will works. */
        write_file();   /* Writes the board to file. */
        cout << "The board saved successfuly.";
    }
    else{
        cerr << "\nYou entered wrong input.";     /* If the user enters wrong input the program will ends. */
        exit(1);
    }
}

bool PegSolitaire::check_input()   /* This function checks if the inputs are correct or not. */
{
    if((direction != 'N') && (direction != 'S') && (direction != 'W') && (direction != 'E'))
        return false;
    if(((board_type == 1) || (board_type == 4)) && ((u_row < 1) || (u_row > 7) || (u_column < 'A') || (u_column > 'G')))
        return false;
    else if(((board_type == 2) || (board_type == 5)) && ((u_row < 1) || (u_row > 9) || (u_column < 'A') || (u_column > 'I')))
        return false;
    else if((board_type == 3) && ((u_row < 1) || (u_row > 8) || (u_column < 'A') || (u_column > 'H')))
        return false;
    else if((board_type == 6) && ((u_row < 1) || (u_row > 5) || (u_column < 'A') || (u_column > 'I')))
        return false;
    else if(board_type == 0){   /* If the board type is not to given standart boards then this works. */
        if(f ==1){   /* If the board is square board this works. */
            char a = 'E';
            for(int i=5; i<=c_size; i++){
                if(i == c_size)
                    break;
                a++;
            }
            if((u_row < 1) || (u_row > r_size) || (u_column < 'A') || (u_column > a))
                return false;
        }
        else{   /* If the board is arbitrary board this works. */
            char temp = 'A';
            for(int i=1; i<= g_column; i++){
                if(i == g_column)
                    break;
                temp++;
            }
            if((u_row < 1) || (u_row > g_row) || (u_column < 'A') || (u_column > temp))
                return false;
        }
    }
    return true;
}

void PegSolitaire::covert_char(char column)  /* This function convert char column to integer column. */
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

bool PegSolitaire::compare(PegSolitaire & other)   /* This function compare to board and returns true or false. */
{
    count_pegs();   /* Calculate first board. */
    other.count_pegs();   /* Calculate second board. */
    cout << "\nFirst game has " << remain_peg << " peg. And second game has " << other.remain_peg << " peg.\n";
    if(remain_peg > other.remain_peg)   /* Compare its. */
        return true;
    return false;
}

void PegSolitaire::play(string user_column, string user_row, string user_direction)  /* This function takes movements informations and plays just 1 step. */
{
    int flag=0, end_flag=0;
    string user_direction2;
    if((user_row.size() > 2) || (user_column.size() > 1) || (user_direction.size() > 1)){
        cout << "\nYou entered wrong input.";   /* If the inputs are not correct the programs ends. */
        exit(1);
    }
    user_row[0] = toupper(user_row[0]);
    user_row[1] = toupper(user_row[1]);
    user_column[0] = toupper(user_column[0]);
    user_direction[0] = toupper(user_direction[0]);
    /* I handle the row works in here. Here string row turns the integer properly and then the integer row uses all the time. */
    if(user_row.size() < 2){
        char a = '1';
        for(int i=1; i<10; i++){
            if(user_row[0] == a){
                u_row = i;
                break;
            }
            a++;
        }
    }
    else if(user_row[0] == '1'){
        char a = '0';
        for(int i=10; i<20; i++){
            if(user_row[1] == a){
                u_row = i;
                break;
            }
            a++;
        }
    }
    else if(user_row[0] == '2'){
        char a = '0';
        for(int i=20; i<27; i++){
            if(user_row[1] == a){
                u_row = i;
                break;
            }
            a++;
        }
    }
    u_column = user_column[0];
    direction = user_direction[0];
    flag = check_input();   /* Checks the inputs. */
    if(flag == 0){
        cout << u_row << u_column << direction << endl;
        cout << "\nYou entered wrong input.";
        exit(1);
    }
    while(1){
        if((direction == 'N') && ((board_type == 6) || (board_number == "g6"))){
            cout << "\nWhich direction do you want? 1 for Nortwest(1) or 2 for Norteast(2) : "; /* If the user wants to go northwest or northeast this works.*/
            cin >> user_direction2;
        }
        else if((direction == 'S')  && ((board_type == 6) || (board_number == "g6"))){
            cout << "\nWhich direction do you want? 1 for Southwest(1) or 2 for Southeast(2) : ";   /* If the user wants to go southwest or southeast this works.*/
            cin >> user_direction2;
        }
        /* After I take input from the user I check input is correck or not. */
        if(((board_type == 6) || (board_number == "g6")) && ((user_direction2.size() > 1) || ((user_direction2[0] != 1) && (user_direction2[0] != 2))))
            cout << "\nYou entered wrong input please try again.";
        else{
            /* If the input is correct I convert him integer or char to string. */ 
            if(user_direction2[0] == '1')
                table6_direction = 1;
            else
                table6_direction = 2;
            break;
        }
    }
    covert_char(u_column);   /* Converts char column to integer column. */
    /* If the board type is 6 this if blok works. */
    if((board_type == 6) || (board_number == "g6")){
        flag = is_legal_for_table6();   /* Checks inputs are legal or not. */
        if(flag == 0){
            cout << "\nYou entered wrong input.";
            exit(1);
        }
        cout << "\n";
        print_board_6();
        make_move_table6(); /* Makes move. */
        cout << "\nMove: " << u_column << u_row << "-" << direction << endl;
        end_flag = check_end_table6();     /* Checks the game over or not. */
        cout << "\n";
        print_board_6();      /* Prints the latest version of the board. */
        if(end_flag == 0){      /* If game over this blok works and the program ends after same mesagges. */
            count_pegs();
            cout << "\nCongratulations game over.\n" << remain_peg << " pegs remain.\n" ;
            cout << remain_empty << " empty remain.\n" << taken_peg << " pegs taken from the board." << endl;
        }
    }
    else{
        flag = is_legal();       /* Checks inputs are legal or not. */
        if(flag == 0){
            cout << "\nYou entered wrong input.";
            exit(1);
        }
        cout << "\n";
        if((board_type == 1) || (board_type == 4) || (board_number == "g1") || (board_number == "g4"))
            print_board_1_and_4();
        else if((board_type == 2) || (board_type == 5) || (board_number == "g2") || (board_number == "g5"))
            print_board_2_and_5();
        else if((board_type == 3) || (board_number == "g3"))
            print_board_3();
        else{
            if(f == 1)
                print_square_board();
            else
                print_arbitrary_board();
        }
        make_move();    /* Makes move. */
        cout << "\nMove: " << u_column << u_row << "-" << direction << endl;
        end_flag = check_end();     /* Checks the game over or not. */
        cout << "\n";
        /* Prints the latest version of the board accorording to board type. */
        if((board_type == 1) || (board_type == 4) || (board_number == "g1") || (board_number == "g4"))
            print_board_1_and_4();
        else if((board_type == 2) || (board_type == 5) || (board_number == "g2") || (board_number == "g5"))
            print_board_2_and_5();
        else if((board_type == 3) || (board_number == "g3"))
            print_board_3();
        else{
            if(f == 1)
                print_square_board();
            else
                print_arbitrary_board();
        }
        if(end_flag == 0){
            count_pegs();
            cout << "\nCongratulations game over.\n" << remain_peg << " pegs remain.\n" ;
            cout << remain_empty << " empty remain.\n" << taken_peg << " pegs taken from the board." << endl;
        }
    }
}

void PegSolitaire::play() /* This function automatically plays just 1 step. */
{
    int flag=0, end_flag=0;
    cout << "\n";
    /* Prints the boaard */
    if((board_type == 6) || (board_number == "g6"))
        print_board_6();
    else{
        if((board_type == 1) || (board_type == 4) || (board_number == "g1") || (board_number == "g4"))
            print_board_1_and_4();
        else if((board_type == 2) || (board_type == 5) || (board_number == "g2") || (board_number == "g5"))
            print_board_2_and_5();
        else if((board_type == 3) || (board_number == "g3"))
            print_board_3();
        else{
            if(f == 1)
                print_square_board();
            else
                print_arbitrary_board();
        }
    }
    while(1){
        u_column = make_rand_column();    /* Makes random columns. */
        u_row = make_rand_row();     /* Makes random rows. */
        direction = make_random_direction();    /* Makes random directions. */
        if((board_type == 6) || (board_number == "g6")){    /* If the board type is 6 this if blok works. */
            flag = check_input();      /* Checks inputs are correct or not. */
            if(flag == 1){
                if((direction == 'N') || (direction == 'S'))
                    table6_direction = make_rand_direction2();   /* If the user wants to move northwes, northeast, southwest or southeast this works. */
                covert_char(u_column);   /* Converts char column to integer column. */
                flag = is_legal_for_table6();     /* Checks inputs are legal or not. */
                if(flag == 1){
                    make_move_table6();    /* Makes move. */     
                    cout << "\nMove: " << u_column << u_row << "-" << direction << endl;
                    end_flag = check_end_table6();      /* Checks the game over or not. */
                    cout << "\n";
                    print_board_6();   /* Prints the latest version of the board accorording to board type. */
                    if(end_flag == 0){
                        count_pegs();
                        cout << "\nCongratulations game over.\n" << remain_peg << " pegs remain.\n" ;
                        cout << remain_empty << " empty remain.\n" << taken_peg << " pegs taken from the board." << endl;
                    }
                    break;
                }
            }
        }
        else{
            flag = check_input();   /* Checks inputs are correct or not. */
            if(flag == 1){
                covert_char(u_column);
                flag = is_legal();       /* Checks inputs are legal or not. */
                if(flag == 1){
                    make_move();   /* Makes move. */     
                    cout << "\nMove: " << u_column << u_row << "-" << direction << endl;
                    end_flag = check_end();    /* Checks the game over or not. */
                    cout << "\n";
                    /* Prints the latest version of the board accorording to board type. */
                    if((board_type == 1) || (board_type == 4) || (board_number == "g1") || (board_number == "g4"))
                        print_board_1_and_4();
                    else if((board_type == 2) || (board_type == 5) || (board_number == "g2") || (board_number == "g5"))
                        print_board_2_and_5();
                    else if((board_type == 3) || (board_number == "g3"))
                        print_board_3();
                    else{
                        if(f == 1)
                            print_square_board();
                        else
                            print_arbitrary_board();
                    }
                    if(end_flag == 0){
                        count_pegs();
                        cout << "\nCongratulations game over.\n" << remain_peg << " pegs remain.\n" ;
                        cout << remain_empty << " empty remain.\n" << taken_peg << " pegs taken from the board." << endl;
                    }
                    break;
                }
            }
        }
    }
}

void PegSolitaire::playGame()
{
    int flag=0, end_flag=0;
    cout << "\n";
    /* Prints the latest version of the board accorording to board type. */
    if((board_type == 6) || (board_number == "g6"))
        print_board_6();
    else{
        if((board_type == 1) || (board_type == 4) || (board_number == "g1") || (board_number == "g4"))
            print_board_1_and_4();
        else if((board_type == 2) || (board_type == 5) || (board_number == "g2") || (board_number == "g5"))
            print_board_2_and_5();
        else if((board_type == 3) || (board_number == "g3"))
            print_board_3();
        else{
            if(f == 1)
                print_square_board();
            else
                print_arbitrary_board();
        }
    }
    while(1){
        u_column = make_rand_column();    /* Makes random columns. */
        u_row = make_rand_row();     /* Makes random rows. */
        direction = make_random_direction();   /* Makes random directions. */
        if((board_type == 6) || (board_number == "g6")){
            flag = check_input();   /* Checks inputs are correct or not. */
            if(flag == 1){
                if((direction == 'N') || (direction == 'S'))
                    table6_direction = make_rand_direction2();   /* If the user wants to move northwes, northeast, southwest or southeast this works. */
                covert_char(u_column);   /* Converts char column to integer column. */
                flag = is_legal_for_table6();      /* Checks inputs are legal or not. */
                if(flag == 1){
                    make_move_table6();    /* Makes move. */     
                    cout << "\nMove: " << u_column << u_row << "-" << direction << endl;
                    end_flag = check_end_table6();    /* Checks the game over or not. */
                    if(end_flag == 0){
                        cout << "\n";
                        print_board_6();
                        count_pegs();
                        cout << "\nCongratulations game over.\n" << remain_peg << " pegs remain.\n" ;
                        cout << remain_empty << " empty remain.\n" << taken_peg << " pegs taken from the board." << endl;
                        break;
                    }
                    cout << "\n";
                    print_board_6();
                }
            }
        }
        else{
            flag = check_input();    /* Checks inputs are correct or not. */
            if(flag == 1){
                covert_char(u_column);
                flag = is_legal();       /* Checks inputs are legal or not. */
                if(flag == 1){
                    make_move();    /* Makes move. */   
                    cout << "\nMove: " << u_column << u_row << "-" << direction << endl;
                    end_flag = check_end();   /* Checks the game over or not. */
                    if(end_flag == 0){
                        cout << "\n";
                        /* Prints the latest version of the board accorording to board type. */
                        if((board_type == 1) || (board_type == 4) || (board_number == "g1") || (board_number == "g4"))
                            print_board_1_and_4();
                        else if((board_type == 2) || (board_type == 5) || (board_number == "g2") || (board_number == "g5"))
                            print_board_2_and_5();
                        else if((board_type == 3) || (board_number == "g3"))
                            print_board_3();
                        else{
                            if(f == 1)
                                print_square_board();
                            else
                                print_arbitrary_board();
                        }
                        count_pegs();
                        cout << "\nCongratulations game over.\n" << remain_peg << " pegs remain.\n" ;
                        cout << remain_empty << " empty remain.\n" << taken_peg << " pegs taken from the board." << endl;
                        break;
                    }
                    cout << "\n";
                    /* If the game not end prints the new board and continue. */
                    if((board_type == 1) || (board_type == 4) || (board_number == "g1") || (board_number == "g4"))
                        print_board_1_and_4();
                    else if((board_type == 2) || (board_type == 5) || (board_number == "g2") || (board_number == "g5"))
                        print_board_2_and_5();
                    else if((board_type == 3) || (board_number == "g3"))
                        print_board_3();  
                    else{
                        if(f == 1)
                            print_square_board();
                        else
                            print_arbitrary_board();
                    }
                }
            }
        }
    }
}

void PegSolitaire::make_move()   /* This function makes move and change the some locations on the board */
{
    if(direction == 'S'){    /* If the user wants to go south this block works. */
        board[u_row][i_column].set_location(pegs::empty);     /* After the move initial location will be empty.*/
        board[u_row+1][i_column].set_location(pegs::empty);   /* After the move side of the location will be empty. */
        board[u_row+2][i_column].set_location(pegs::peg);     /* After the move second side of the location will be peg. */
    }
    else if(direction == 'E'){    /* If the user wants to go east this block works. */
        board[u_row][i_column].set_location(pegs::empty);    /* After the move initial location will be empty.*/
        board[u_row][i_column+1].set_location(pegs::empty);  /* After the move side of the location will be empty. */
        board[u_row][i_column+2].set_location(pegs::peg);    /* After the move second side of the location will be peg. */
    }
    else if(direction == 'W'){    /* If the user wants to go west this block works. */
        board[u_row][i_column].set_location(pegs::empty);    /* After the move initial location will be empty.*/
        board[u_row][i_column-1].set_location(pegs::empty);  /* After the move side of the location will be empty. */
        board[u_row][i_column-2].set_location(pegs::peg);    /* After the move second side of the location will be peg. */
    }
    else if(direction == 'N'){    /* If the user wants to go north this block works. */
        board[u_row][i_column].set_location(pegs::empty);    /* After the move initial location will be empty.*/
        board[u_row-1][i_column].set_location(pegs::empty);  /* After the move side of the location will be empty. */
        board[u_row-2][i_column].set_location(pegs::peg);    /* After the move second side of the location will be peg. */
    }
}

void PegSolitaire::make_move_table6()   /* This function makes same things with upper function but for board 6 */
{
    if(direction == 'E'){      /* If the user wants to go east this block works. */
        board[u_row][i_column].set_location(pegs::empty);
        board[u_row][i_column+2].set_location(pegs::empty);
        board[u_row][i_column+4].set_location(pegs::peg);
    }
    else if(direction == 'W'){      /* If the user wants to go west this block works. */
        board[u_row][i_column].set_location(pegs::empty);
        board[u_row][i_column-2].set_location(pegs::empty);
        board[u_row][i_column-4].set_location(pegs::peg);
    }
    else if((direction == 'N') && (table6_direction == 1)){     /* If the user wants to go northwest this block works. */
        board[u_row][i_column].set_location(pegs::empty);
        board[u_row-1][i_column-1].set_location(pegs::empty);
        board[u_row-2][i_column-2].set_location(pegs::peg);
    }
    else if((direction == 'N') && (table6_direction == 2)){          /* If the user wants to go northeast this block works. */
        board[u_row][i_column].set_location(pegs::empty);
        board[u_row-1][i_column+1].set_location(pegs::empty);
        board[u_row-2][i_column+2].set_location(pegs::peg);
    }
    else if((direction == 'S') && (table6_direction == 1)){      /* If the user wants to go southwest this block works. */
        board[u_row][i_column].set_location(pegs::empty);
        board[u_row+1][i_column-1].set_location(pegs::empty);
        board[u_row+2][i_column-2].set_location(pegs::peg);
    }
    else if((direction == 'S') && (table6_direction == 2)){           /* If the user wants to go southeast this block works. */
        board[u_row][i_column].set_location(pegs::empty);
        board[u_row+1][i_column+1].set_location(pegs::empty);
        board[u_row+2][i_column+2].set_location(pegs::peg);
    }
}

bool PegSolitaire::is_legal()   /* This funtion checks the location and direction appropriate to the board. If appropriate returns true, if not returns false. */
{
    if((board[u_row][i_column]).get_cellType() != pegs::peg)    /* If the location is not peg it returns false. */
        return false;
    else if(direction == 'S'){
        if((board[u_row+1][i_column]).get_cellType() == pegs::blank)    /* If the user wants to go south checks it is near the border or not. */
            return false;
        else if(((board[u_row+2][i_column]).get_cellType() != pegs::empty) || ((board[u_row+1][i_column]).get_cellType() != pegs::peg))
            /* Checks the beside location is peg and the other location is blank. */
            return false;
    }
    else if(direction == 'E'){   /* If the user wants to go east checks it is near the border or not. */
        if((board[u_row][i_column+1]).get_cellType() == pegs::blank)
            return false;
        else if(((board[u_row][i_column+2]).get_cellType() != pegs::empty) || ((board[u_row][i_column+1]).get_cellType() != pegs::peg))
            /* Checks the beside location is peg and the other location is blank. */
            return false;
    }
    else if(direction == 'W'){    /* If the user wants to go west checks it is near the border or not. */
        if((board[u_row][i_column-1]).get_cellType() == pegs::blank)
            return false;
        else if(((board[u_row][i_column-2]).get_cellType() != pegs::empty) || ((board[u_row][i_column-1]).get_cellType() != pegs::peg))
            /* Checks the beside location is peg and the other location is blank. */
            return false;
    }
    else if(direction == 'N'){   /* If the user wants to go north checks it is near the border or not. */
        if((board[u_row-1][i_column]).get_cellType() == pegs::blank)
            return false;
        else if(((board[u_row-2][i_column]).get_cellType() != pegs::empty) || ((board[u_row-1][i_column]).get_cellType() != pegs::peg))
            /* Checks the beside location is peg and the other location is blank. */
            return false;
    }
    return true;
}

bool PegSolitaire::is_legal_for_table6()
{
    /* This function checks same things with upper function but the 6 board is different from the other boards so that this function checks is legal for board 6 */
    /* It checks all possibilities to go and returns value accordingly. */
    if(board[u_row][i_column].get_cellType() != pegs::peg)
        return false;
    else if(direction == 'E'){
        if((board[u_row][i_column+3].get_cellType() == pegs::blank) && (board[u_row-1][i_column+3].get_cellType() == pegs::blank))
            return false;
        else if((board[u_row][i_column+4].get_cellType() != pegs::empty) || (board[u_row][i_column+2].get_cellType() != pegs::peg))
            return false;
    }
    else if(direction == 'W'){
        if((board[u_row][i_column-3].get_cellType() == pegs::blank) && (board[u_row-1][i_column-3].get_cellType() == pegs::blank))
            return false;
        else if((board[u_row][i_column-4].get_cellType() != pegs::empty) || (board[u_row][i_column-2].get_cellType() != pegs::peg))
            return false;
    }
    else if((direction == 'N') && (table6_direction == 1)){
        if((i_column < 5) || (u_row < 3))
            return false;
        else if((board[u_row-1][i_column-1].get_cellType() != pegs::peg) || (board[u_row-2][i_column-2].get_cellType() != pegs::empty))
            return false;
    }
    else if((direction == 'N') && (table6_direction == 2)){
        if((i_column > 5) || (u_row < 3))
            return false;
        else if((board[u_row-1][i_column+1].get_cellType() != pegs::peg) || (board[u_row-2][i_column+2].get_cellType() != pegs::empty))
            return false;
    }
    else if((direction == 'S') && (table6_direction == 1)){
        if((i_column > 7) || (u_row > 3) || (i_column < 3))
            return false;
        else if((board[u_row+1][i_column-1].get_cellType() != pegs::peg) || (board[u_row+2][i_column-2].get_cellType() != pegs::empty))
            return false;
    }
    else if((direction == 'S') && (table6_direction == 2)){
        if((i_column > 7) || (u_row > 3) || (i_column < 3))
            return false;
        else if((board[u_row+1][i_column+1].get_cellType() != pegs::peg) || (board[u_row+2][i_column+2].get_cellType() != pegs::empty))
            return false;
    }
    return true;
}

void PegSolitaire::write_file()
{
    /* If the user wants to save the board firstl open the file and then writes that board and then it turns to the top of the loop. */
    ofstream f;
    while(1){
        cout << "\nWhich board do you want to save? (For arbitrary boards enter 1, 2 or 3) (For given boards enter g1, g2, g3, g4, g5 or g6) : ";
        cin >> board_number;
        if(((board_number.size() != 1) && (board_number.size() != 2)) || ((board_number[0] != '1') && (board_number[0] != '2') && (board_number[0] != 3) 
        && (board_number != "g1") && (board_number != "g2") && (board_number != "g3") && (board_number != "g4") && (board_number != "g5") && (board_number != "g6"))){
                cerr << "\nYou entered wrong board number. Please try again." << endl;
        }
        else
            break;
    }  
    if(board_number[0] == '1')   /* For arbitrary board 1. */
        f.open("file_1.txt");
    else if(board_number[0] == '2')     /* For arbitrary board 2. */
        f.open("file_2.txt");
    else if(board_number[0] == '3')     /* For arbitrary board 3. */
        f.open("file_3.txt");
    else if(board_number == "g1")  /* For given board 1. */
        f.open("g_file_1.txt");
    else if(board_number == "g2")  /* For given board 2. */
        f.open("g_file_2.txt");
    else if(board_number == "g3")  /* For given board 3. */
        f.open("g_file_3.txt");
    else if(board_number == "g4")  /* For given board 4. */
        f.open("g_file_4.txt");
    else if(board_number == "g5")  /* For given board 5. */
        f.open("g_file_5.txt");
    else if(board_number == "g6")  /* For given board 6. */
        f.open("g_file_6.txt");
    /* Writes to file. */
    for(int i=1; i<board.size()-1; i++){
		for(int j=1; j<board[i].size()-1; j++){
            if(board[i][j].get_cellType() == pegs::blank)
                f << " ";
            else if(board[i][j].get_cellType() == pegs::peg)
                f << "P";
            else
                f << ".";
        }
        if(i != board.size()-2)
            f << endl;
    }
}

void PegSolitaire::read_file()
{
    /* If the user wants to load any board this block works and opens the file properly. */
    ifstream file;
    while(1){
        cout << "\n(If you did not play any standart board and did not save it you can not load that board.)";
        cout << "\nWhich board do you want to load? (For arbitrary boards enter 1, 2 or 3) (For given boards enter g1, g2, g3, g4, g5 or g6) : ";
        cin >> board_number;
        if(((board_number.size() != 1) && (board_number.size() != 2)) || ((board_number[0] != '1') && (board_number[0] != '2') && (board_number[0] != '3') 
            && (board_number != "g1") && (board_number != "g2") && (board_number != "g3") && (board_number != "g4") && (board_number != "g5") && (board_number != "g6"))){
                cerr << "\nYou entered wrong board number. Please try again." << endl;
        }
        else{
            if(board_number[0] == '1'){       /* If the user did not play with the first arbitrary board given, the program gives an error message. */
                file.open("file_1.txt");
                break;
            }
            else if(board_number[0] == '2'){       /* If the user did not play with the second arbitrary board given, the program gives an error message. */
                file.open("file_2.txt");
                break;
            }
            else if(board_number[0] == '3'){       /* If the user did not play with the third arbitrary board given, the program gives an error message. */
                file.open("file_3.txt");
                break;
            }
            else if(board_number == "g1"){       /* If the user did not play with the first board given, the program gives an error message. */
                file.open("g_file_1.txt");
                if(!file)
                    cerr << "\nThe file does not exist. Please firsly play the game then save. And then load.";
                else
                    break;
            }
            else if(board_number == "g2"){       /* If the user did not play with the second board given, the program gives an error message. */
                file.open("g_file_2.txt");
                if(!file)
                    cerr << "\nThe file does not exist. Please firsly play the game then save. And then load.";
                else
                    break;
            }
            else if(board_number == "g3"){       /* If the user did not play with the third board given, the program gives an error message. */
                file.open("g_file_3.txt");
                if(!file)
                    cerr << "\nThe file does not exist. Please firsly play the game then save. And then load.";
                else
                    break;
            }
            else if(board_number == "g4"){       /* If the user did not play with the fourth board given, the program gives an error message. */
                file.open("g_file_4.txt");
                if(!file)
                    cerr << "\nThe file does not exist. Please firsly play the game then save. And then load.";
                else
                    break;
            }
            else if(board_number == "g5"){       /* If the user did not play with the fifth board given, the program gives an error message. */
                file.open("g_file_5.txt");
                if(!file)
                    cerr << "\nThe file does not exist. Please firsly play the game then save. And then load.";
                else
                    break;
            }
            else if(board_number == "g6"){       /* If the user did not play with the sixth board given, the program gives an error message. */
                file.open("g_file_6.txt");
                if(!file)
                    cerr << "\nThe file does not exist. Please firsly play the game then save. And then load.";
                else
                    break;
            }
            else
                cerr << "\nYou did not play given boards yet. Please first you play and then save the board after that you can load that boad.\n";
        }
    }   
    read_arbitrary_board(file);   /* Reads file. */
    file.clear();
    file.seekg(0, ios::beg);  /* Goes to begin of the file.  */
    set_arbitrary_board(file);  /* Fills the 2D vector.  */
    file.close();  /* Close to file. */
}


char PegSolitaire::make_rand_column()
{
    /* This function makes random integer columns and it convert to char column. */
    int x;
    char column = 'A';
    /* It changes to the borders. */
    if((board_type == 1) || (board_type == 4))
        x = rand()%7;
    else if((board_type == 2) || (board_type == 5) || (board_type == 6))
        x = rand()%9;
    else if(board_type == 3)
        x = rand()%8;
    else{
        if(f == 1)
            x = rand()%r_size;
        else
            x = rand()%g_column;
    }
    /* Coverts. */
    for(int i=0; i<x; i++){
        if(i == x)
            return column;
        column++;
    }
    return column;
}


int PegSolitaire::make_rand_row()
{
    /* This function makes random rows and returns it. */
    int x;
    /* It changes to the borders. */
    if((board_type == 1) || (board_type == 4))
        x = rand()%7 + 1;
    else if((board_type == 2) || (board_type == 5))
        x = rand()%9 + 1;
    else if(board_type == 3)
        x = rand()%8 + 1;
    else if(board_type == 6)
        x = rand()%5 + 1;
    else{
        if(f == 1)
            x = rand()%r_size +1;
        else
            x = rand()%g_row + 1;
    }
    return x;
}


char PegSolitaire::make_random_direction()
{
     /* This function makes random directions with using rand function. */
    int x;
    char dir;
    x = rand()%4;
    if(x == 0)
        dir = 'N';
    else if(x == 1)
        dir = 'W';
    else if(x == 2)
        dir = 'E';
    else if(x == 3)
        dir = 'S';
    return dir;
}

int PegSolitaire::make_rand_direction2()
{
    /* This function makes random direction for board 6. For northwest, northeast, southwest and southeast. */
    int x;
    x = rand()%2+1;
    return x;
}


void PegSolitaire::count_pegs()
{
    /* This function count how many pegs, empty cells remain and how many pegs are taken from the board */
    int peg = 0, cell=0;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if((board[i][j]).get_cellType() == pegs::peg)
                peg++;
            if((board[i][j]).get_cellType() != pegs::blank)
                cell++;
        }
    }
    remain_peg = peg;
    remain_empty = cell-peg;
    taken_peg = remain_empty - 1;
}

bool PegSolitaire::check_end()
{
    /* This function checks the game end or not. */
    /* I use 2 for loops and I reach every value inside the 2D vector. */
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            /* If there are two consecutive pegs and the other location is empty the game is not end. */
            if(((board[i][j]).get_cellType() == pegs::peg) && ((board[i-1][j]).get_cellType() == pegs::peg)){
                if(((board[i-2][j]).get_cellType() == pegs::empty) || ((board[i+1][j]).get_cellType() == pegs::empty))
                    return true;
            }
            else if(((board[i][j]).get_cellType() == pegs::peg) && ((board[i+1][j]).get_cellType() == pegs::peg)){
                /* If there are two consecutive pegs and the other location is empty the game is not end. */
                if(((board[i+2][j]).get_cellType() == pegs::empty) || ((board[i-1][j]).get_cellType() == pegs::empty))
                    return true;
            }
            else if(((board[i][j]).get_cellType() == pegs::peg) && ((board[i][j-1]).get_cellType() == pegs::peg)){
                /* If there are two consecutive pegs and the other location is empty the game is not end. */
                if(((board[i][j-2]).get_cellType() == pegs::empty) || ((board[i][j+1]).get_cellType() == pegs::empty))
                    return true;
            }
            else if(((board[i][j]).get_cellType() == pegs::peg) && ((board[i][j+1]).get_cellType() == pegs::peg)){
                /* If there are two consecutive pegs and the other location is empty the game is not end. */
                if(((board[i][j+2]).get_cellType() == pegs::empty) || ((board[i][j-1]).get_cellType() == pegs::empty))
                    return true;
            }
        }
    }
    /* If all the contition is not works the game over. */
    return false;
}

bool PegSolitaire::check_end_table6()
{
    /* This function makes same things with upper function but for 6 board. */
    /* I use 2 for loops and I reach every value inside the 2D vector. */
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if(((board[i][j]).get_cellType() == pegs::peg) && ((board[i][j+2]).get_cellType() == pegs::peg)){
                if((j < 6) && ((board[i][j+4]).get_cellType() == pegs::empty) || ((board[i][j-2]).get_cellType() == pegs::empty))
                    return true;
            }
            else if(((board[i][j]).get_cellType() == pegs::peg) && ((board[i][j-2]).get_cellType() == pegs::peg)){
                if((j > 3) && (((board[i][j-4]).get_cellType() == pegs::empty) || ((board[i][j+2]).get_cellType() == pegs::empty)))
                    return true;
            }
            else if(((board[i][j]).get_cellType() == pegs::peg) && ((board[i-1][j+1]).get_cellType() == pegs::peg) && ((board[i-2][j+2]).get_cellType() == pegs::empty))
                return true;
            else if(((board[i][j]).get_cellType() == pegs::peg) && ((board[i-1][j-1]).get_cellType() == pegs::peg) && ((board[i-2][j-2]).get_cellType() == pegs::empty))
                return true;
            else if(((board[i][j]).get_cellType() == pegs::peg) && ((board[i+1][j+1]).get_cellType() == pegs::peg) && ((board[i+2][j+2]).get_cellType() == pegs::empty))
                return true;
            else if(((board[i][j]).get_cellType() == pegs::peg) && ((board[i+1][j-1]).get_cellType() == pegs::peg) && ((board[i+2][j-2]).get_cellType() == pegs::empty))
                return true;
        }
    }
    return false;
}

void PegSolitaire::Cell::set_column(int c)  /* This function sets the column. */
{
    char a = 'A';
    for(int i=0; i<26; i++){
        if(c == i)
            break;
        a++;
    }
    column = a;
}

void PegSolitaire::print_board_1_and_4() const
{
    /* This function prints board 1 and 4 */
    int k = 1;
    cout << "    A B C D E F G\n";
    for(int i=0; i<board.size(); i++){
        if((i >= 1) && (i < 8)){
            cout << k << " ";
            k++;
        }
		for(int j=0; j<board[i].size(); j++){
            if((board[i][j]).get_cellType() == pegs::blank)
                cout << " ";
            else if((board[i][j]).get_cellType() == pegs::peg)
                cout << "P";
            else
                cout << ".";
            cout << " ";
        }
        cout << endl;
    }
}

void PegSolitaire::print_board_2_and_5() const
{
    /* This function prints board 2 and 5 */
    int k = 1;
    cout << "\n    A B C D E F G H I\n";
    for(int i=0; i<board.size(); i++){
        if((i >= 1) && (i < 10)){
            cout << k << " ";
            k++;
        }
		for(int j=0; j<board[i].size(); j++){
            if((board[i][j]).get_cellType() == pegs::blank)
                cout << " ";
            else if((board[i][j]).get_cellType() == pegs::peg)
                cout << "P";
            else
                cout << ".";
            cout << " ";
        }
        cout << endl;
    }
}

void PegSolitaire::print_board_3() const
{
    /* This function prints board 3 */
    int k = 1;
    cout << "    A B C D E F G H\n";
    for(int i=0; i<board.size(); i++){
        if((i >= 1) && (i < 9)){
            cout << k << " ";
            k++;
        }
		for(int j=0; j<board[i].size(); j++){
            if((board[i][j]).get_cellType() == pegs::blank)
                cout << " ";
            else if((board[i][j]).get_cellType() == pegs::peg)
                cout << "P";
            else
                cout << ".";
            cout << " ";
        }
        cout << endl;
    }
}

void PegSolitaire::print_board_6() const
{   
    /* This function prints board 6 */
    int k = 1;
    cout << "    A B C D E F G H I\n";
    for(int i=0; i<board.size(); i++){
        if((i >= 1) && (i < 6)){
            cout << k << " ";
            k++;
        }
		for(int j=0; j<board[i].size(); j++){
            if((board[i][j]).get_cellType() == pegs::blank)
                cout << " ";
            else if((board[i][j]).get_cellType() == pegs::peg)
                cout << "P";
            else
                cout << ".";
            cout << " ";
        }
        cout << endl;
    }
}

void PegSolitaire::print_square_board() const
{
    /* This function prints square board. */
    int k = 1;
    char temp = 'A';
    cout << "   ";
    for(int i=0; i<c_size; i++){
        cout << " " << temp;
        temp++;
    }
    for(int i=0; i<board.size(); i++){
        if((i >= 1) && (i < board.size()-1)){
            cout << k << " ";
            k++;
        }
		for(int j=0; j<board[i].size(); j++){
            if(board[i][j].get_cellType() == pegs::blank)
                cout << " ";
            else if(board[i][j].get_cellType() == pegs::peg)
                cout << "P";
            else
                cout << ".";
            cout << " ";
        }
        cout << endl;
    }
}

void PegSolitaire::print_arbitrary_board() const
{
    /* This function works for the prints arbitrary boards. */
    int k = 1;
    char temp = 'A';
    cout << "   ";
    for(int i=0; i<g_column; i++){
        cout << " " << temp;
        temp++;
    }
    for(int i=0; i<board.size(); i++){
        if((i >= 1) && (i < board.size()-1)){
            cout << k << " ";
            k++;
        }
		for(int j=0; j<board[i].size(); j++){
            if(board[i][j].get_cellType() == pegs::blank)
                cout << " ";
            else if(board[i][j].get_cellType() == pegs::peg)
                cout << "P";
            else
                cout << ".";
            cout << " ";
        }
        cout << endl;
    }
}

void PegSolitaire::read_arbitrary_board(ifstream &f)
{
    /* This function reads the file and resize to 2D vector. */
    board.clear();
    string line;
    int x=0, temp, i=0;
    while(getline(f, line)){
        temp = line.size();
        if(temp > x)
            x = temp;
        i++;
    }
    g_row = i;
    g_column = x;
    board.resize(i+2, vector<Cell>(x+2, pegs::blank));
}

void PegSolitaire::set_arbitrary_board(ifstream &f)
{
    /* This function reads the file again and fills the 2D vector. */
    string line;
    int temp, i=1;
    while(getline(f, line)){
        temp = line.size();
        for(int j=0; j<temp; j++){
            if(line[j] == ' ')
                board[i][j+1].set_location(pegs::blank);
            else if(line[j] == 'P')
                board[i][j+1].set_location(pegs::peg);
            else if(line[j] == '.')
                board[i][j+1].set_location(pegs::empty);
            board[i][j].set_row(i-1);
            board[i][j].set_column(j);
        }
        i++;
    }
    board_type = 0;
}

void PegSolitaire::set_special_board(int r_size, int c_size)
{
    /* This function sets the square board. */
    Cell P = Cell(pegs::peg);
    Cell E = Cell(pegs::empty);
    Cell B = Cell(pegs::blank);
    if(r_size != c_size){
        cout << "You can not creat square board.\n";
        exit(1);
    }
    int size = r_size;
    int temp = (size+2) / 2;

    board.resize(size+2, vector<Cell>(size+2, pegs::peg));   /* Resize the vector. */

    /* Fills the vector. */
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if((j==0) || (i==0) || (j==size+1) || (i==size+1))
                board[i][j].set_location(pegs::blank);
            if((j == temp) && (i == temp))
                board[i][j].set_location(pegs::empty);
            board[i][j].set_row(i);
            board[i][j].set_column(j);
        }
    }
    board_type = 0;
    f=1;
}


void PegSolitaire::set_given_board()
{
    /* This function sets the standart board. */
    Cell P = Cell(pegs::peg);
    Cell E = Cell(pegs::empty);
    Cell B = Cell(pegs::blank);

    /* Fills the boards. */
    if(board_type == 1){
        board = 
        {
            {B, B, B, B, B, B, B, B, B},
            {B, B, B, P, P, P, B, B, B},
            {B, B, P, P, P, P, P, B, B},
            {B, P, P, P, E, P, P, P, B},
            {B, P, P, P, P, P, P, P, B},
            {B, P, P, P, P, P, P, P, B},
            {B, B, P, P, P, P, P, B, B},
            {B, B, B, P, P, P, B, B, B},
            {B, B, B, B, B, B, B, B, B}
        };
    }
    else if(board_type == 2){
        board = 
        {
            {B, B, B, B, B, B, B, B, B, B, B},
            {B, B, B, B, P, P, P, B, B, B, B},
            {B, B, B, B, P, P, P, B, B, B, B},
            {B, B, B, B, P, P, P, B, B, B, B},
            {B, P, P, P, P, P, P, P, P, P, B},
            {B, P, P, P, P, E, P, P, P, P, B},
            {B, P, P, P, P, P, P, P, P, P, B},
            {B, B, B, B, P, P, P, B, B, B, B},
            {B, B, B, B, P, P, P, B, B, B, B},
            {B, B, B, B, P, P, P, B, B, B, B},
            {B, B, B, B, B, B, B, B, B, B, B}
        };
    }
    else if(board_type == 3){
        board = 
        {
            {B, B, B, B, B, B, B, B, B, B},
            {B, B, B, P, P, P, B, B, B, B},
            {B, B, B, P, P, P, B, B, B, B},
            {B, B, B, P, P, P, B, B, B, B},
            {B, P, P, P, P, P, P, P, P, B},
            {B, P, P, P, E, P, P, P, P, B},
            {B, P, P, P, P, P, P, P, P, B},
            {B, B, B, P, P, P, B, B, B, B},
            {B, B, B, P, P, P, B, B, B, B},
            {B, B, B, B, B, B, B, B, B, B}
        };
    }
    else if(board_type == 4){
        board = 
        {
            {B, B, B, B, B, B, B, B, B},
            {B, B, B, P, P, P, B, B, B},
            {B, B, B, P, P, P, B, B, B},
            {B, P, P, P, P, P, P, P, B},
            {B, P, P, P, E, P, P, P, B},
            {B, P, P, P, P, P, P, P, B},
            {B, B, B, P, P, P, B, B, B},
            {B, B, B, P, P, P, B, B, B},
            {B, B, B, B, B, B, B, B, B}
        };
    }
    else if(board_type == 5){
        board = 
        {
            {B, B, B, B, B, B, B, B, B, B, B},
            {B, B, B, B, B, P, B, B, B, B, B},
            {B, B, B, B, P, P, P, B, B, B, B},
            {B, B, B, P, P, P, P, P, B, B, B},
            {B, B, P, P, P, P, P, P, P, B, B},
            {B, P, P, P, P, E, P, P, P, P, B},
            {B, B, P, P, P, P, P, P, P, B, B},
            {B, B, B, P, P, P, P, P, B, B, B},
            {B, B, B, B, P, P, P, B, B, B, B},
            {B, B, B, B, B, P, B, B, B, B, B},
            {B, B, B, B, B, B, B, B, B, B, B}
        };
    }
    else if(board_type == 6){
        board = 
        {
            {B, B, B, B, B, B, B, B, B, B, B},
            {B, B, B, B, B, E, B, B, B, B, B},
            {B, B, B, B, P, B, P, B, B, B, B},
            {B, B, B, P, B, P, B, P, B, B, B},
            {B, B, P, B, P, B, P, B, P, B, B},
            {B, P, B, P, B, P, B, P, B, P, B},
            {B, B, B, B, B, B, B, B, B, B, B}
        };
    }
    for(int i=0; i< board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            board[i][j].set_row(i);
            board[i][j].set_column(j);
        }
    }
}