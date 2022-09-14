#include <iostream> 
#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime> 
#include <fstream>

using namespace std;

enum class pegs {empty, peg, blank};   /* Create strong enum. */

void print_board_1_and_4(const vector<vector<pegs>> &vec);  /* Prints board 1 and 4 */
void print_board_2_and_5(const vector<vector<pegs>> &vec);  /* Prints board 2 and 5 */
void print_board_3(const vector<vector<pegs>> &vec);   /* Prints board 3 */
void print_board_6(const vector<vector<pegs>> &vec);   /* Prints board 6 */
void print_arbitrary_boards(const vector<vector<pegs>> &vec, int g_column);
void b1(vector<vector<pegs>> &vec);     /* If the user select board 1 this function sets the main vector according to the 1st board. */
void b2(vector<vector<pegs>> &vec);     /* If the user select board 2 this function sets the main vector according to the 2nd board. */
void b3(vector<vector<pegs>> &vec);     /* If the user select board 3 this function sets the main vector according to the 3rd board. */
void b4(vector<vector<pegs>> &vec);     /* If the user select board 4 this function sets the main vector according to the 4th board. */
void b5(vector<vector<pegs>> &vec);     /* If the user select board 5 this function sets the main vector according to the 5th board. */
void b6(vector<vector<pegs>> &vec);     /* If the user select board 6 this function sets the main vector according to the 6th board. */
void make_move(vector<vector<pegs>> &vec, int row, int column, char direction);     /* Makes moves. */
void make_move_table6(vector<vector<pegs>> &vec, int row, int column, int table6_direction, char direction);    /* Makes moves for board 6 */
void fill_board(ifstream &f, vector<vector<pegs>> &vec);    /* Reads file and calculate the size of 2D vector. */
void create_board(ifstream &f, vector<vector<pegs>> &vec, int &g_row, int &g_column);    /* Again reads same file and fills the 2D vector. */
void write_board_to_file(ofstream &f, const vector<vector<pegs>> &vec);    /* After the user writes save. This function write the current shape of the board to file.*/
char make_rand_column(int b_type, int g_column, int g_row=0);      /* Makes random columns. */
char make_random_direction();       /* Makes random directions. */
int make_rand_direction2();     /* Makes random directions for board 6 */
int covert_char(char column);       /* Converts char colums to integer columns. */
int make_rand_row(int b_type, int g_row);      /* Makes random rows. */
int count_pegs(const vector<vector<pegs>> &vec);    /* Counts how many pegs remains in the board at the end of the game. */
bool check_input(int b_type, int row, char column, char direction, int g_row, int g_column);     /* Checks inputs are correct or not. */
bool is_legal(const vector<vector<pegs>> &vec, int row, int column, char direction);        /* Checks the inputs are legal or not. */
bool is_legal_for_table6(const vector<vector<pegs>> &vec, int row, int column, int table6_direction, char direction);   /* Checks the inputs are legal or not for board 6 */
bool check_end(const vector<vector<pegs>> &vec);    /* Checks the game over or not. */
bool check_end_table6(const vector<vector<pegs>> &vec);     /* Checks game over or not for board 6 */

int main()
{
    srand(time(NULL));  /* Use for produce random numbers. */
    int b_type=0, u_row, flag, i_column, end_flag, peg, table6_direction, g_row=0, g_column=0;  /* I assign variables. */
    char u_type, u_column, direction;
    string board_type, user_type, user_direction, user_column, user_row, user_table6_direction, board_number;
    
    vector<vector<pegs>> board;     /* Create 2D vector. */
    
    start:
    while(1){
        /* In my program the user firstly write load or save and then write the other things in properly. I explain that condition to user. */
        /* Here I take board type, and player type. */
        cout << "\nTo play on arbitrary boards, firstly you need to write load. And then you need to write which board you want to play with.";  /* Here i explained how the user should act*/
        cout << "\nTo save this boards, firstly you need to write save. And then you need to write the number of whatever arbitrary board you played on it.\n";
        cout << "\n1- Human player game\n2- Computer player game\nSelect the game type (h or c) : "; 
        cin >> user_type;
        for(int i=0; i<user_type.size(); i++)
            user_type[i] = toupper(user_type[i]);
        if(user_type == "LOAD"){   /* If the user wants to load any arbitrary board this blok works. */
            cout << "\nWhich board do you want to load? (For arbitrary boards enter 1, 2 or 3) (For given boards enter g1, g2, g3, g4, g5 or g6) : ";
            cin >> board_number;
            if(((board_number.size() != 1) && (board_number.size() != 2)) || ((board_number[0] != '1') && (board_number[0] != '2') && (board_number[0] != 3) 
                && (board_number != "g1") && (board_number != "g2") && (board_number != "g3") && (board_number != "g4") && (board_number != "g5") && (board_number != "g6"))){
                    cerr << "\nYou entered wrong board number. Please try again." << endl;
                }
            else{
                start_2:
                b_type = 0;
                cout << "\n1- Human player game\n2- Computer player game\nSelect the game type (h or c) : "; 
                cin >> user_type;
                user_type[0] = toupper(user_type[0]);
                u_type = user_type[0];
                break;
            }
        }
        else if(user_type == "SAVE")   /* If the user wants to save board the program gives an error message because the user did not play with any board. */
            cerr << "\nYou did not play with any board so that you can not save any board. To save board firstly you have to play any type board and then you can save.";
        cout << "\nWhich board would you like to play? (You can choose 1 to 6) : "; 
        cin >> board_type;
        cout << "\n\n";
        for(int i=0; i<board_type.size(); i++)
            board_type[i] = toupper(board_type[i]);
        if(board_type == "LOAD"){
            cout << "\nWhich board do you want to load? (For arbitrary boards enter 1, 2 or 3) (For given boards enter g1, g2, g3, g4, g5 or g6) : ";
            cin >> board_number;
            if(((board_number.size() != 1) && (board_number.size() != 2)) || ((board_number[0] != '1') && (board_number[0] != '2') && (board_number[0] != 3) 
                && (board_number != "g1") && (board_number != "g2") && (board_number != "g3") && (board_number != "g4") && (board_number != "g5") && (board_number != "g6"))){
                    cerr << "\nYou entered wrong board number. Please try again." << endl;
                }
            else{
                b_type = 0;
                u_type = user_type[0];
                break;
            }
        }
        else if(board_type == "SAVE")
            cerr << "\nYou did not play with any board so that you can not save any board. To save board firstly you have to play any type board and then you can save.";
        else if((board_type.size() != 1) || ((board_type[0] != '1') && (board_type[0] != '2') && (board_type[0] != '3') && (board_type[0] != '4') && (board_type[0] != '5') && (board_type[0] != '6')))
            cerr << "\nYou entered wrong board number. Please try again." << endl;
        if((user_type.size() != 1) || (((user_type[0]) != 'H') && (user_type[0]) != 'C'))
            cerr << "\nYou entered wrong letter. Please try again." << endl;
        else{
            /* If the inputs are correct I convert them integer or char to string. */ 
            if(board_type[0] == '1')
                b_type = 1;
            else if(board_type[0] == '2')
                b_type = 2;
            else if(board_type[0] == '3')
                b_type = 3;
            else if(board_type[0] == '4')
                b_type = 4;
            else if(board_type[0] == '5')
                b_type = 5;
            else if(board_type[0] == '6')
                b_type = 6;
            u_type = user_type[0];
            break;
        }
    }
    /* Here I resize the 2D vector according to board type. */
    board.clear();
    if(b_type == 1){
        board.resize(9, vector<pegs>(9, pegs::peg));
        b1(board);
    }
    else if(b_type == 2){
        board.resize(11, vector<pegs>(11, pegs::peg));
        b2(board);
    }
    else if(b_type == 3){
        board.resize(10, vector<pegs>(10, pegs::peg));
        b3(board);
    }
    else if(b_type == 4){
        board.resize(9, vector<pegs>(9, pegs::peg));
        b4(board);
    }
    else if(b_type == 5){
        board.resize(11, vector<pegs>(11, pegs::peg));
        b5(board);
    }
    else if(b_type == 6){
        board.resize(7, vector<pegs>(11, pegs::peg));
        b6(board);
    }
    else{
        ifstream file;   /* If the user wants to load any board this block works and opens the file properly. */
        if(board_number[0] == '1')
            file.open("file_1.txt");
        else if(board_number[0] == '2')
            file.open("file_2.txt");
        else if(board_number[0] == '3')
            file.open("file_3.txt");
        else if(board_number == "g1"){
            file.open("g_file_1.txt");
            if(!file){        /* If the user did not play with the first board given, the program gives an error message. */
                cerr << "\nThe file does not exist. Please firsly play the game then save. And then load.";
                goto start;
            }
        }
        else if(board_number == "g2"){
            file.open("g_file_2.txt");
            if(!file){        /* If the user did not play with the second board given, the program gives an error message. */
                cerr << "\nThe file does not exist. Please firsly play the game then save. And then load.";
                goto start;
            }
        }
        else if(board_number == "g3"){
            file.open("g_file_3.txt");
            if(!file){        /* If the user did not play with the third board given, the program gives an error message. */
                cerr << "\nThe file does not exist. Please firsly play the game then save. And then load.";
                goto start;
            }
        }
        else if(board_number == "g4"){
            file.open("g_file_4.txt");
            if(!file){        /* If the user did not play with the forth board given, the program gives an error message. */
                cerr << "\nThe file does not exist. Please firsly play the game then save. And then load.";
                goto start;
            }
        }
        else if(board_number == "g5"){
            file.open("g_file_5.txt");
            if(!file){        /* If the user did not play with the fifth board given, the program gives an error message. */
                cerr << "\nThe file does not exist. Please firsly play the game then save. And then load.";
                goto start;
            }
        }
        else if(board_number == "g6"){
            file.open("g_file_6.txt");
            if(!file){        /* If the user did not play with the sixth board given, the program gives an error message. */
                cerr << "\nThe file does not exist. Please firsly play the game then save. And then load.";
                goto start;
            }
        }
        else
            cerr << "\nYou did not play given boards yet. Please first you play and then save the board after that you can load that boad.\n";
        create_board(file, board, g_row, g_column);
        file.clear();
        file.seekg(0, ios::beg);
        fill_board(file, board);
        file.close();
    }
    
    /* Here I printed the board according to type. */
    if((b_type == 1) || (b_type == 4) || (board_number == "g1") || (board_number == "g4"))
        print_board_1_and_4(board);
    else if((b_type == 2) || (b_type == 5) || (board_number == "g2") || (board_number == "g5"))
        print_board_2_and_5(board);
    else if((b_type == 3) || (board_number == "g3"))
        print_board_3(board);
    else
        print_arbitrary_boards(board, g_column);

    /* If the player type is h this bloks works. */
    if(u_type == 'H'){
        while(1){
            cout << "\n\nEnter the column letter: ";
            cin >> user_column;
            for(int i=0; i<user_column.size(); i++)
                user_column[i] = toupper(user_column[i]);
            if((user_column == "LOAD") || (user_column == "SAVE")){
                if(user_column == "LOAD"){     /* If the user wants to load any arbitrary board this blok works. */
                    cout << "\nWhich board do you want to load? (For arbitrary boards enter 1, 2 or 3) (For given boards enter g1, g2, g3, g4, g5 or g6) : ";
                    cin >> board_number;
                    if(((board_number.size() != 1) && (board_number.size() != 2)) || ((board_number[0] != '1') && (board_number[0] != '2') && (board_number[0] != 3) 
                        && (board_number != "g1") && (board_number != "g2") && (board_number != "g3") && (board_number != "g4") && (board_number != "g5") && (board_number != "g6"))){
                            cerr << "\nYou entered wrong board number. Please try again." << endl;
                    }
                    else
                        goto start_2;
                }
                else{
                    cout << "\nWhich board do you want to save? (For arbitrary boards enter 1, 2 or 3) (For given boards enter g1, g2, g3, g4, g5 or g6) : ";
                    cin >> board_number;
                    if(((board_number.size() != 1) && (board_number.size() != 2)) || ((board_number[0] != '1') && (board_number[0] != '2') && (board_number[0] != 3) 
                    && (board_number != "g1") && (board_number != "g2") && (board_number != "g3") && (board_number != "g4") && (board_number != "g5") && (board_number != "g6"))){
                            cerr << "\nYou entered wrong board number. Please try again." << endl;
                    }
                    ofstream file_o;    /* If the user wants to save the board firstl open the file and then writes that board and then it turns to the top of the loop. */
                    if(board_number[0] == '1')
                        file_o.open("file_1.txt");   /* For arbitrary board 1. */
                    else if(board_number[0] == '2')
                        file_o.open("file_2.txt");      /* For arbitrary board 2. */
                    else if(board_number[0] == '3')
                        file_o.open("file_3.txt");      /* For arbitrary board 3. */
                    else if(board_number == "g1")
                        file_o.open("g_file_1.txt");   /* For given board 1. */
                    else if(board_number == "g2")
                        file_o.open("g_file_2.txt");   /* For given board 2. */
                    else if(board_number == "g3")
                        file_o.open("g_file_3.txt");   /* For given board 3. */
                    else if(board_number == "g4")
                        file_o.open("g_file_4.txt");   /* For given board 4. */
                    else if(board_number == "g5")
                        file_o.open("g_file_5.txt");   /* For given board 5. */
                    else if(board_number == "g6")
                        file_o.open("g_file_6.txt");   /* For given board 6. */
                    write_board_to_file(file_o, board);
                    file_o.close();
                    goto start;
                }
            }
            else{
                cout << "\nEnter the row number: ";
                cin >> user_row;
                for(int i=0; i<user_row.size(); i++)
                    user_row[i] = toupper(user_row[i]);
                if((user_row == "LOAD") || (user_row == "SAVE")){
                    if(user_row == "LOAD"){
                        cout << "\nWhich board do you want to load? (For arbitrary boards enter 1, 2 or 3) (For given boards enter g1, g2, g3, g4, g5 or g6) : ";
                        cin >> board_number;
                        if(((board_number.size() != 1) && (board_number.size() != 2)) || ((board_number[0] != '1') && (board_number[0] != '2') && (board_number[0] != 3) 
                            && (board_number != "g1") && (board_number != "g2") && (board_number != "g3") && (board_number != "g4") && (board_number != "g5") && (board_number != "g6"))){
                                cerr << "\nYou entered wrong board number. Please try again." << endl;
                        }
                        else
                            goto start_2;
                    }
                    else{
                        cout << "\nWhich board do you want to save? (For arbitrary boards enter 1, 2 or 3) (For given boards enter g1, g2, g3, g4, g5 or g6) : ";
                        cin >> board_number;
                        if(((board_number.size() != 1) && (board_number.size() != 2)) || ((board_number[0] != '1') && (board_number[0] != '2') && (board_number[0] != 3) 
                        && (board_number != "g1") && (board_number != "g2") && (board_number != "g3") && (board_number != "g4") && (board_number != "g5") && (board_number != "g6"))){
                                cerr << "\nYou entered wrong board number. Please try again." << endl;
                        }
                        ofstream file_o;    /* If the user wants to save the board firstl open the file and then writes that board and then it turns to the top of the loop. */
                        if(board_number[0] == '1')
                            file_o.open("file_1.txt");
                        else if(board_number[0] == '2')
                            file_o.open("file_2.txt");
                        else if(board_number[0] == '3')
                            file_o.open("file_3.txt");
                        else if(board_number == "g1")
                            file_o.open("g_file_1.txt");
                        else if(board_number == "g2")
                            file_o.open("g_file_2.txt");
                        else if(board_number == "g3")
                            file_o.open("g_file_3.txt");
                        else if(board_number == "g4")
                            file_o.open("g_file_4.txt");
                        else if(board_number == "g5")
                            file_o.open("g_file_5.txt");
                        else if(board_number == "g6")
                            file_o.open("g_file_6.txt");
                        write_board_to_file(file_o, board);
                        file_o.close();
                        goto start;
                    }
                }
                else{
                    cout << "\n\nEast: E  ,  West: W\nSouth: S  ,  North: N\n(For northwest and northeast: N,    For southwest and southeast: S)\n\nEnter the direction letter: ";
                    cin >> user_direction;
                    for(int i=0; i<user_direction.size(); i++)
                        user_direction[i] = toupper(user_direction[i]);
                    if((user_row == "LOAD") || (user_row == "SAVE")){
                        if(user_row == "LOAD"){
                            cout << "\nWhich board do you want to load? (For arbitrary boards enter 1, 2 or 3) (For given boards enter g1, g2, g3, g4, g5 or g6) : ";
                            cin >> board_number;
                            if(((board_number.size() != 1) && (board_number.size() != 2)) || ((board_number[0] != '1') && (board_number[0] != '2') && (board_number[0] != 3) 
                                && (board_number != "g1") && (board_number != "g2") && (board_number != "g3") && (board_number != "g4") && (board_number != "g5") && (board_number != "g6"))){
                                    cerr << "\nYou entered wrong board number. Please try again." << endl;
                            }
                            else
                                goto start_2;
                        }
                        else{
                            cout << "\nWhich board do you want to save? (For arbitrary boards enter 1, 2 or 3) (For given boards enter g1, g2, g3, g4, g5 or g6) : ";
                            cin >> board_number;
                            if(((board_number.size() != 1) && (board_number.size() != 2)) || ((board_number[0] != '1') && (board_number[0] != '2') && (board_number[0] != 3) 
                            && (board_number != "g1") && (board_number != "g2") && (board_number != "g3") && (board_number != "g4") && (board_number != "g5") && (board_number != "g6"))){
                                    cerr << "\nYou entered wrong board number. Please try again." << endl;
                            }
                            ofstream file_o;    /* If the user wants to save the board firstl open the file and then writes that board and then it turns to the top of the loop. */
                            if(board_number[0] == '1')
                                file_o.open("file_1.txt");
                            else if(board_number[0] == '2')
                                file_o.open("file_2.txt");
                            else if(board_number[0] == '3')
                                file_o.open("file_3.txt");
                            else if(board_number == "g1")
                                file_o.open("g_file_1.txt");
                            else if(board_number == "g2")
                                file_o.open("g_file_2.txt");
                            else if(board_number == "g3")
                                file_o.open("g_file_3.txt");
                            else if(board_number == "g4")
                                file_o.open("g_file_4.txt");
                            else if(board_number == "g5")
                                file_o.open("g_file_5.txt");
                            else if(board_number == "g6")
                                file_o.open("g_file_6.txt");
                            write_board_to_file(file_o, board);
                            file_o.close();
                            goto start;
                        }
                    }
                }
            }
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
            /* If the board type is 6 this if blok works. */
            if((b_type == 6) || (board_number == "g6")){
                flag = check_input(b_type, u_row, u_column, direction, g_row, g_column);     /* Checks the inputs. */
                if(flag == 0)
                    cerr << "\nYou entered wrong input. Please try again.";
                else{
                    if(direction == 'N'){
                        cout << "\nWhich direction do you want? 1 for Nortwest(1) or 2 for Norteast(2) : "; /* If the user wants to go northwest or northeast this works.*/
                        cin >> user_table6_direction;
                    }
                    else if(direction == 'S'){
                        cout << "\nWhich direction do you want? 1 for Southwest(1) or 2 for Southeast(2) : ";  /* If the user wants to go southwest or southeast this works.*/
                        cin >> user_table6_direction;
                    }
                    /* After I take input from the user I check input is correck or not. */
                    if((user_table6_direction.size() != 1) || ((user_table6_direction[0] != '1') && (user_table6_direction[0] != '2')))
                        cerr << "You entered wrong number. Please try again." << endl;
                    else{
                        /* If the input is correct I convert him integer or char to string. */ 
                        if(user_table6_direction[0] == '1')
                            table6_direction = 1;
                        else
                            table6_direction = 2;
                    }
                    i_column = covert_char(u_column);   /* Converts char column to integer column. */
                    flag = is_legal_for_table6(board, u_row, i_column, table6_direction, direction);    /* Checks inputs are legal or not. */
                    if(flag == 0)
                        cerr << "\nYou can not play like that. Please try again.";
                    else{
                        make_move_table6(board, u_row, i_column, table6_direction, direction);  /* Makes move. */
                        end_flag = check_end_table6(board);     /* Checks the game over or not. */
                        if(end_flag == 0){      /* If game over this blok works and the program ends after same mesagges. */
                            cout << "\n";
                            print_board_6(board);       /* Prints the latest version of the board. */
                            peg = count_pegs(board);    /* Counts how many pegs remain. */
                            cout << "\nCongratulations game over. You have " << peg << " pegs.\n" << endl;
                            break;
                        }
                        cout << "\n";
                        print_board_6(board);   /* If tha game not end prints the new board and continue. */
                    }
                }
            }
            else{
                flag = check_input(b_type, u_row, u_column, direction, g_row, g_column);       /* Checks inputs are correct or not. */
                if(flag == 0)
                    cerr << "\nYou entered wrong input. Please try again.";
                else{
                    i_column = covert_char(u_column);    /* Converts char column to integer column. */
                    flag = is_legal(board, u_row, i_column, direction);        /* Checks inputs are legal or not. */
                    if(flag == 0)
                        cerr << "\nYou can not play like that. Please try again.";
                    else{
                        make_move(board, u_row, i_column, direction);    /* Makes move. */     
                        end_flag = check_end(board);     /* Checks the game over or not. */
                        if(end_flag == 0){
                            cout << "\n";
                            /* Prints the latest version of the board accorording to board type. */
                            if((b_type == 1) || (b_type == 4) || (board_number == "g1") || (board_number == "g4"))
                                print_board_1_and_4(board);
                            else if((b_type == 2) || (b_type == 5) || (board_number == "g2") || (board_number == "g5"))
                                print_board_2_and_5(board);
                            else if((b_type == 3) || (board_number == "g3"))
                                print_board_3(board);
                            else
                                print_arbitrary_boards(board, g_column);
                            peg = count_pegs(board);    /* Counts how many pegs remain. */
                            cout << "\nCongratulations game over. You have " << peg << " pegs.\n" << endl;
                            break;
                        }
                        cout << "\n";
                        /* If the game not end prints the new board and continue. */
                        if((b_type == 1) || (b_type == 4) || (board_number == "g1") || (board_number == "g4"))
                            print_board_1_and_4(board);
                        else if((b_type == 2) || (b_type == 5) || (board_number == "g2") || (board_number == "g5"))
                            print_board_2_and_5(board);
                        else if((b_type == 3) || (board_number == "g3"))
                            print_board_3(board);
                        else
                            print_arbitrary_boards(board, g_column);
                    }
                }
            }  
        }
    }
    /* If the player type is c this bloks works. */
    else if(u_type == 'C'){
        while(1){
            u_column = make_rand_column(b_type, g_column);    /* Makes random columns. */
            u_row = make_rand_row(b_type, g_row);      /* Makes random rows. */
            direction = make_random_direction();    /* Makes random directions. */
            /* If the board type is 6 this if blok works. */
            if((b_type == 6) || (board_number == "g6")){
                flag = check_input(b_type, u_row, u_column, direction, g_row, g_column);     /* Checks inputs are correct or not. */
                if(flag == 1){
                    if((direction == 'N') || (direction == 'S'))
                        table6_direction = make_rand_direction2();    /* If the user wants to move northwes, northeast, southwest or southeast this works. */
                    i_column = covert_char(u_column);    /* Converts char column to integer column. */
                    flag = is_legal_for_table6(board, u_row, i_column, table6_direction, direction);        /* Checks inputs are legal or not. */
                    if(flag == 1){
                        make_move_table6(board, u_row, i_column, table6_direction, direction);    /* Makes move. */     
                        end_flag = check_end_table6(board);     /* Checks the game over or not. */
                        /* Prints the latest version of the board accorording to board type. */
                        if(end_flag == 0){
                            cout << "\n";
                            print_board_6(board);
                            peg = count_pegs(board);    /* Counts how many pegs remain. */
                            cout << "\nCongratulations game over. You have " << peg << " pegs.\n" << endl;
                            break;
                        }
                        cout << "\n";
                        print_board_6(board);   /* If the game not end prints the new board and continue. */
                    }
                }
            }
            else{
                flag = check_input(b_type, u_row, u_column, direction, g_row, g_column);    /* Checks inputs are correct or not. */
                if(flag == 1){
                    decltype(covert_char(u_column)) i_column = covert_char(u_column); // a has type int
                    flag = is_legal(board, u_row, i_column, direction);        /* Checks inputs are legal or not. */
                    if(flag == 1){
                        make_move(board, u_row, i_column, direction);    /* Makes move. */     
                        end_flag = check_end(board);     /* Checks the game over or not. */
                        if(end_flag == 0){
                            cout << "\n";
                            /* Prints the latest version of the board accorording to board type. */
                            if((b_type == 1) || (b_type == 4) || (board_number == "g1") || (board_number == "g4"))
                                print_board_1_and_4(board);
                            else if((b_type == 2) || (b_type == 5) || (board_number == "g2") || (board_number == "g5"))
                                print_board_2_and_5(board);
                            else if((b_type == 3) || (board_number == "g3"))
                                print_board_3(board);
                            else
                                print_arbitrary_boards(board, g_column);
                            peg = count_pegs(board);   /* Counts how many pegs remain. */
                            cout << "\nCongratulations game over. You have " << peg << " pegs.\n" << endl;
                            break;
                        }
                        cout << "\n";
                           /* If the game not end prints the new board and continue. */
                        if((b_type == 1) || (b_type == 4) || (board_number == "g1") || (board_number == "g4"))
                            print_board_1_and_4(board);
                        else if((b_type == 2) || (b_type == 5) || (board_number == "g2") || (board_number == "g5"))
                            print_board_2_and_5(board);
                        else if((b_type == 3) || (board_number == "g3"))
                            print_board_3(board);
                        else
                            print_arbitrary_boards(board, g_column);
                    }
                }
            }
        }
    }
}

int covert_char(char column)
{
    /* This function takes char column and it converts to integer column for example it takes A and convert to 1 and returns it.*/
    int temp;
    auto a = 'A';
    for(int i=1; i<=26; i++){
        if(column == a){
            temp = i;
            break;
        }
        a++;
    }
    return temp;
}

bool check_input(int b_type, int row, char column, char direction, int g_row, int g_column)
{
    /* This function checks inputs are valid or not. If it is valid returns true if not returns false. */
    if((direction != 'N') && (direction != 'S') && (direction != 'W') && (direction != 'E'))    /* Checks direction. */
        return false;
    if(((b_type == 1) || (b_type == 4)) && ((row < 1) || (row > 7) || (column < 'A') || (column > 'G')))    /* Checks columns and rows board 1 and 4 */
        return false;
    else if(((b_type == 2) || (b_type == 5)) && ((row < 1) || (row > 9) || (column < 'A') || (column > 'I')))    /* Checks columns and rows board 2 and 5 */
        return false;
    else if((b_type == 3) && ((row < 1) || (row > 8) || (column < 'A') || (column > 'H')))    /* Checks columns and rows board 3 */
        return false;
    else if((b_type == 6) && ((row < 1) || (row > 5) || (column < 'A') || (column > 'I')))    /* Checks columns and rows board 6 */
        return false;
    else if(b_type == 0){
        char temp = 'A';
        for(int i=1; i<= g_column; i++){
            if(i == g_column)
                break;
            temp++;
        }
        if((row < 1) || (row > g_row) || (column < 'A') || (column > temp))
            return false;
    }
    return true;
}

bool is_legal(const vector<vector<pegs>> &vec, int row, int column, char direction)
{
    /* This funtion checks the location and direction appropriate to the board. If appropriate returns true, if not returns false. */
    if(vec[row][column] != pegs::peg)   /* If the location is not peg it returns false. */
        return false;
    else if(direction == 'S'){
        if(vec[row+1][column] == pegs::blank)    /* If the user wants to go south checks it is near the border or not. */
            return false;
        else if((vec[row+2][column] != pegs::empty) || (vec[row+1][column] != pegs::peg))    /* Checks the beside location is peg and the other location is blank. */
            return false;
    }
    else if(direction == 'E'){
        if(vec[row][column+1] == pegs::blank)    /* If the user wants to go east checks it is near the border or not. */
            return false;
        else if((vec[row][column+2] != pegs::empty) || (vec[row][column+1] != pegs::peg))    /* Checks the beside location is peg and the other location is blank. */
            return false;
    }
    else if(direction == 'W'){
        if(vec[row][column-1] == pegs::blank)    /* If the user wants to go west checks it is near the border or not. */
            return false;
        else if((vec[row][column-2] != pegs::empty) || (vec[row][column-1] != pegs::peg))    /* Checks the beside location is peg and the other location is blank. */
            return false;
    }
    else if(direction == 'N'){
        if(vec[row-1][column] == pegs::blank)    /* If the user wants to go north checks it is near the border or not. */
            return false;
        else if((vec[row-2][column] != pegs::empty) || (vec[row-1][column] != pegs::peg))    /* Checks the beside location is peg and the other location is blank. */
            return false;
    }
    return true;
}

bool is_legal_for_table6(const vector<vector<pegs>> &vec, int row, int column, int table6_direction, char direction)
{
    /* This function checks same things with upper function but the 6 board is different from the other boards so that this function checks is legal for board 6 */
    /* It checks all possibilities to go and returns value accordingly. */
    if(vec[row][column] != pegs::peg)
        return false;
    else if(direction == 'E'){
        if((vec[row][column+3] == pegs::blank) && (vec[row-1][column+3] == pegs::blank))
            return false;
        else if((vec[row][column+4] != pegs::empty) || (vec[row][column+2] != pegs::peg))
            return false;
    }
    else if(direction == 'W'){
        if((vec[row][column-3] == pegs::blank) && (vec[row-1][column-3] == pegs::blank))
            return false;
        else if((vec[row][column-4] != pegs::empty) || (vec[row][column-2] != pegs::peg))
            return false;
    }
    else if((direction == 'N') && (table6_direction == 1)){
        if((column < 5) || (row < 3))
            return false;
        else if((vec[row-1][column-1] != pegs::peg) || (vec[row-2][column-2] != pegs::empty))
            return false;
    }
    else if((direction == 'N') && (table6_direction == 2)){
        if((column > 5) || (row < 3))
            return false;
        else if((vec[row-1][column+1] != pegs::peg) || (vec[row-2][column+2] != pegs::empty))
            return false;
    }
    else if((direction == 'S') && (table6_direction == 1)){
        if((column > 7) || (row > 3) || (column < 3))
            return false;
        else if((vec[row+1][column-1] != pegs::peg) || (vec[row+2][column-2] != pegs::empty))
            return false;
    }
    else if((direction == 'S') && (table6_direction == 2)){
        if((column > 7) || (row > 3) || (column < 3))
            return false;
        else if((vec[row+1][column+1] != pegs::peg) || (vec[row+2][column+2] != pegs::empty))
            return false;
    }
    return true;
}

void make_move(vector<vector<pegs>> &vec, int row, int column, char direction)
{
    /* This function makes move and change the some locations on the board */
    if(direction == 'S'){   /* If the user wants to go south this block works. */
        vec[row][column] = pegs::empty;     /* After the move initial location will be empty.*/
        vec[row+1][column] = pegs::empty;   /* After the move side of the location will be empty. */
        vec[row+2][column] = pegs::peg;     /* After the move second side of the location will be peg. */
    }
    else if(direction == 'E'){     /* If the user wants to go east this block works. */
        vec[row][column] = pegs::empty;    /* After the move initial location will be empty.*/
        vec[row][column+1] = pegs::empty;  /* After the move side of the location will be empty. */
        vec[row][column+2] = pegs::peg;     /* After the move second side of the location will be peg. */
    }
    else if(direction == 'W'){     /* If the user wants to go west this block works. */
        vec[row][column] = pegs::empty;    /* After the move initial location will be empty.*/
        vec[row][column-1] = pegs::empty;  /* After the move side of the location will be empty. */
        vec[row][column-2] = pegs::peg;     /* After the move second side of the location will be peg. */
    }
    else if(direction == 'N'){      /* If the user wants to go north this block works. */
        vec[row][column] = pegs::empty;    /* After the move initial location will be empty.*/
        vec[row-1][column] = pegs::empty;  /* After the move side of the location will be empty. */
        vec[row-2][column] = pegs::peg;     /* After the move second side of the location will be peg. */
    }
}

void make_move_table6(vector<vector<pegs>> &vec, int row, int column, int table6_direction, char direction)
{
    /* This function makes same things with upper function but for board 6 */
    if(direction == 'E'){      /* If the user wants to go east this block works. */
        vec[row][column] = pegs::empty;
        vec[row][column+2] = pegs::empty;
        vec[row][column+4] = pegs::peg;
    }
    else if(direction == 'W'){      /* If the user wants to go west this block works. */
        vec[row][column] = pegs::empty;
        vec[row][column-2] = pegs::empty;
        vec[row][column-4] = pegs::peg;
    }
    else if((direction == 'N') && (table6_direction == 1)){      /* If the user wants to go northwest this block works. */
        vec[row][column] = pegs::empty;
        vec[row-1][column-1] = pegs::empty;
        vec[row-2][column-2] = pegs::peg;
    }
    else if((direction == 'N') && (table6_direction == 2)){           /* If the user wants to go northeast this block works. */
        vec[row][column] = pegs::empty;
        vec[row-1][column+1] = pegs::empty;
        vec[row-2][column+2] = pegs::peg;
    }
    else if((direction == 'S') && (table6_direction == 1)){      /* If the user wants to go southwest this block works. */
        vec[row][column] = pegs::empty;
        vec[row+1][column-1] = pegs::empty;
        vec[row+2][column-2] = pegs::peg;
    }
    else if((direction == 'S') && (table6_direction == 2)){           /* If the user wants to go southeast this block works. */
        vec[row][column] = pegs::empty;
        vec[row+1][column+1] = pegs::empty;
        vec[row+2][column+2] = pegs::peg;
    }
}

char make_rand_column(int b_type, int g_column, int g_row)
{
    /* This function makes random integer columns and it convert to char column. */
    int x;
    char column = 'A';
    /* It changes to the borders. */
    if((b_type == 1) || (b_type == 4))
        x = rand()%7;
    else if((b_type == 2) || (b_type == 5) || (b_type == 6))
        x = rand()%9;
    else if(b_type == 3)
        x = rand()%8;
    else
        x = rand()%g_column;
    /* Coverts. */
    for(int i=0; i<x; i++){
        if(i == x)
            return column;
        column++;
    }
    return column;
}

int make_rand_row(int b_type, int g_row)
{
    /* This function makes random rows and returns it. */
    int x;
    /* It changes to the borders. */
    if((b_type == 1) || (b_type == 4))
        x = rand()%7 + 1;
    else if((b_type == 2) || (b_type == 5))
        x = rand()%9 + 1;
    else if(b_type == 3)
        x = rand()%8 + 1;
    else if(b_type == 6)
        x = rand()%5 + 1;
    else
        x = rand()%g_row + 1;
    return x;
}

char make_random_direction()
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

int make_rand_direction2()
{
    /* This function makes random direction for board 6. For northwest, northeast, southwest and southeast. */
    int x;
    x = rand()%2+1;
    return x;
}

bool check_end(const vector<vector<pegs>> &vec)
{
    /* This function checks the game end or not. */
    int flag = 0;
    /* I use 2 for loops and I reach every value inside the 2D vector. */
    for(int i=0; i<vec.size(); i++){
        for(int j=0; j<vec[i].size(); j++){
            if((vec[i][j] == pegs::peg) && (vec[i-1][j] == pegs::peg)){     /* If there are two consecutive pegs and the other location is empty the game is not end. */
                if((vec[i-2][j] == pegs::empty) || (vec[i+1][j] == pegs::empty))
                    return true;
            }
            else if((vec[i][j] == pegs::peg) && (vec[i+1][j] == pegs::peg)){  /* If there are two consecutive pegs and the other location is empty the game is not end. */
                if((vec[i+2][j] == pegs::empty) || (vec[i-1][j] == pegs::empty))
                    return true;
            }
            else if((vec[i][j] == pegs::peg) && (vec[i][j-1] == pegs::peg)){   /* If there are two consecutive pegs and the other location is empty the game is not end. */
                if((vec[i][j-2] == pegs::empty) || (vec[i][j+1] == pegs::empty))
                    return true;
            }
            else if((vec[i][j] == pegs::peg) && (vec[i][j+1] == pegs::peg)){   /* If there are two consecutive pegs and the other location is empty the game is not end. */
                if((vec[i][j+2] == pegs::empty) || (vec[i][j-1] == pegs::empty))
                    return true;
            }
        }
    }
    /* If all the contition is not works the game over. */
    return false;
}

bool check_end_table6(const vector<vector<pegs>> &vec)
{
    /* This function makes same things with upper function but for 6 board. */
    int flag = 0;
    /* I use 2 for loops and I reach every value inside the 2D vector. */
    for(int i=0; i<vec.size(); i++){
        for(int j=0; j<vec[i].size(); j++){
            if((vec[i][j] == pegs::peg) && (vec[i][j+2] == pegs::peg)){
                if((j < 6) && ((vec[i][j+4] == pegs::empty) || (vec[i][j-2] == pegs::empty)))
                    return true;
            }
            else if((vec[i][j] == pegs::peg) && (vec[i][j-2] == pegs::peg)){
                if((j > 3) && ((vec[i][j-4] == pegs::empty) || (vec[i][j+2] == pegs::empty)))
                    return true;
            }
            else if((vec[i][j] == pegs::peg) && (vec[i-1][j+1] == pegs::peg) && (vec[i-2][j+2] == pegs::empty))
                return true;
            else if((vec[i][j] == pegs::peg) && (vec[i-1][j-1] == pegs::peg) && (vec[i-2][j-2] == pegs::empty))
                return true;
            else if((vec[i][j] == pegs::peg) && (vec[i+1][j+1] == pegs::peg) && (vec[i+2][j+2] == pegs::empty))
                return true;
            else if((vec[i][j] == pegs::peg) && (vec[i+1][j-1] == pegs::peg) && (vec[i+2][j-2] == pegs::empty))
                return true;
        }
    }
    return false;
}

int count_pegs(const vector<vector<pegs>> &vec)
{
    /* This function count how many pegs are there in the board and it returns that number. */
    int peg = 0;
    /* I use 2 for loops and I reach every value inside the 2D vector. */
    for(int i=0; i<vec.size(); i++){
        for(int j=0; j<vec[i].size(); j++){
            if(vec[i][j] == pegs::peg)
                peg++;
        }
    }
    return peg;
}

void print_arbitrary_boards(const vector<vector<pegs>> &vec, int g_column){
    /* This function works for the prints arbitrary boards. */
    int k = 1;
    char temp = 'A';
    cout << "   ";
    for(int i=0; i<g_column; i++){
        cout << " " << temp;
        temp++;
    }
    for(int i=0; i<vec.size(); i++){
        if((i >= 1) && (i < vec.size()-1)){
            cout << k << " ";
            k++;
        }
		for(int j=0; j<vec[i].size(); j++){
            if(vec[i][j] == pegs::blank)
                cout << " ";
            else if(vec[i][j] == pegs::peg)
                cout << "P";
            else
                cout << ".";
            cout << " ";
        }
        cout << endl;
    }
}

void print_board_1_and_4(const vector<vector<pegs>> &vec)
{
    /* This function prints board 1 and 4 */
    int k = 1;
    cout << "    A B C D E F G\n";
    for(int i=0; i<vec.size(); i++){
        if((i >= 1) && (i < 8)){
            cout << k << " ";
            k++;
        }
		for(int j=0; j<vec[i].size(); j++){
            if(vec[i][j] == pegs::blank)
                cout << " ";
            else if(vec[i][j] == pegs::peg)
                cout << "P";
            else
                cout << ".";
            cout << " ";
        }
        cout << endl;
    }
}

void print_board_2_and_5(const vector<vector<pegs>> &vec)
{
    /* This function prints board 2 and 5 */
    int k = 1;
    cout << "\n    A B C D E F G H I\n";
    for(int i=0; i<vec.size(); i++){
        if((i >= 1) && (i < 10)){
            cout << k << " ";
            k++;
        }
		for(int j=0; j<vec[i].size(); j++){
            if(vec[i][j] == pegs::blank)
                cout << " ";
            else if(vec[i][j] == pegs::peg)
                cout << "P";
            else
                cout << ".";
            cout << " ";
        }
        cout << endl;
    }
}

void print_board_3(const vector<vector<pegs>> &vec)
{
    /* This function prints board 3 */
    int k = 1;
    cout << "    A B C D E F G H\n";
    for(int i=0; i<vec.size(); i++){
        if((i >= 1) && (i < 9)){
            cout << k << " ";
            k++;
        }
		for(int j=0; j<vec[i].size(); j++){
            if(vec[i][j] == pegs::blank)
                cout << " ";
            else if(vec[i][j] == pegs::peg)
                cout << "P";
            else
                cout << ".";
            cout << " ";
        }
        cout << endl;
    }
}

void print_board_6(const vector<vector<pegs>> &vec)
{   
    /* This function prints board 6 */
    int k = 1;
    cout << "    A B C D E F G H I\n";
    for(int i=0; i<vec.size(); i++){
        if((i >= 1) && (i < 6)){
            cout << k << " ";
            k++;
        }
		for(int j=0; j<vec[i].size(); j++){
            if(vec[i][j] == pegs::blank)
                cout << " ";
            else if(vec[i][j] == pegs::peg)
                cout << "P";
            else
                cout << ".";
            cout << " ";
        }
        cout << endl;
    }
}

void write_board_to_file(ofstream &f, const vector<vector<pegs>> &vec){
    /* This function write the current board to the file if the user wants to save the board. */
    for(int i=1; i<vec.size()-1; i++){
		for(int j=1; j<vec[i].size()-1; j++){
            if(vec[i][j] == pegs::blank)
                f << " ";
            else if(vec[i][j] == pegs::peg)
                f << "P";
            else
                f << ".";
        }
        if(i != vec.size()-2)
            f << endl;
    }
}

void create_board(ifstream &f, vector<vector<pegs>> &vec, int &g_row, int &g_column){
    /* This function reads the file and count column and rows then create 2D vector with the use this sizes. */
    vec.clear();
    string line;
    int x=0, temp, i=0;
    while(getline(f, line)){
        temp = line.size();
        if(temp > x)
            x = temp;
        i++;
    }
    g_row = i;  /* Calculate row. */
    g_column = x;  /* Calculate column. */
    vec.resize(i+2, vector<pegs>(x+2, pegs::blank));  /* And then resize the vector. */
}

void fill_board(ifstream &f, vector<vector<pegs>> &vec){
    /* This function reads the file again and fill the vector with correct sembols(enum types). */
    string line;
    int temp, i=1;
    while(getline(f, line)){
        temp = line.size();
        for(int j=0; j<temp; j++){
            if(line[j] == ' ')
                vec[i][j+1] = pegs::blank;
            else if(line[j] == 'P')
                vec[i][j+1] = pegs::peg;
            else if(line[j] == '.')
                vec[i][j+1] = pegs::empty;
        }
        i++;
    }
}

void b1(vector<vector<pegs>> &vec)
{
    /* This function create board 1 and writes " " for blank, P for peg and "." for empty. Returns that vector.*/
    vector<vector<pegs>> board_1
    {
        {pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::blank, pegs::blank},
        {pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::empty, pegs::peg, pegs::peg, pegs::peg, pegs::blank},
        {pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::blank},
        {pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::blank},
        {pegs::blank, pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank}
    };
    vec = board_1;
}

void b2(vector<vector<pegs>> &vec)
{
    /* This function create board 2 and writes " " for blank, P for peg and "." for empty. Returns that vector.*/
    vector<vector<pegs>> board_2
    {
        {pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::blank, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::blank, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::blank, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::blank},
        {pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::empty, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::blank},
        {pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::blank, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::blank, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::blank, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank}
    };
    vec = board_2;
}

void b3(vector<vector<pegs>> &vec)
{
    /* This function create board 3 and writes " " for blank, P for peg and "." for empty. Returns that vector.*/
    vector<vector<pegs>> board_3
    {
        {pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::blank, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::blank, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::blank, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::blank},
        {pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::empty, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::blank},
        {pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::blank, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::blank, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank}
    };
    vec = board_3;
}

void b4(vector<vector<pegs>> &vec)
{
    /* This function create board 4 and writes " " for blank, P for peg and "." for empty. Returns that vector.*/
    vector<vector<pegs>> board_4
    {
        {pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::blank},
        {pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::empty, pegs::peg, pegs::peg, pegs::peg, pegs::blank},
        {pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank}
    };
    vec = board_4;
}

void b5(vector<vector<pegs>> &vec)
{
    /* This function create board 5 and writes " " for blank, P for peg and "." for empty. Returns that vector.*/
    vector<vector<pegs>> board_5
    {
        {pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::peg, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::blank, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::blank, pegs::blank},
        {pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::empty, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::blank},
        {pegs::blank, pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::peg, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::peg, pegs::peg, pegs::peg, pegs::blank, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::peg, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank}
    };
    vec = board_5;
}

void b6(vector<vector<pegs>> &vec)
{
    /* This function create board 6 and writes " " for blank, P for peg and "." for empty. Returns that vector.*/
    vector<vector<pegs>> board_6
    {
        {pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::empty, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::peg, pegs::blank, pegs::peg, pegs::blank, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::peg, pegs::blank, pegs::peg, pegs::blank, pegs::peg, pegs::blank, pegs::blank, pegs::blank},
        {pegs::blank, pegs::blank, pegs::peg, pegs::blank, pegs::peg, pegs::blank, pegs::peg, pegs::blank, pegs::peg, pegs::blank, pegs::blank},
        {pegs::blank, pegs::peg, pegs::blank, pegs::peg, pegs::blank, pegs::peg, pegs::blank, pegs::peg, pegs::blank, pegs::peg, pegs::blank},
        {pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank, pegs::blank}
    };
    vec = board_6;
}