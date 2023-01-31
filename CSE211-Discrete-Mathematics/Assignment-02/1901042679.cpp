#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void read_file(vector<vector<string>> &vars, string filename);  /* Reads files. */
bool check_function(vector<vector<string>> &vars, int temp);   /* Checks the sets function or not. */
bool check_inverse_function(vector<vector<string>> &vars, int temp);   /* Checks the sets of the inverse function or not. */
bool is_it_onto(vector<vector<string>> &vars, int temp);   /* Checks the functions onto or not. */
bool is_it_one_to_one(vector<vector<string>> &vars, int temp);   /* Checks the functions one to one or not. */
bool is_it_onetoone_for_inverse(vector<vector<string>> &vars, int temp);    /* Checks the inverse of the functions one to one or not. */

int main(int argc, char *argv[]){
    vector<vector<string>> variables;
    string filename = argv[1];
    int temp=0;

    read_file(variables, filename);

    if(variables.size() > 2)
        temp = 1;

    int func = check_function(variables, temp);
    int inverse_func = check_inverse_function(variables, temp);
    int onto = is_it_onto(variables, temp);
    int onetoone = is_it_one_to_one(variables, temp);
    int onetoone_for_inevrse = is_it_onetoone_for_inverse(variables, temp);

    /* If the sets more than 2 this works. */
    if(temp == 1){
        if(func == 0)
            cout << "Problem 3: not a function.\n";
        else if((onto == 1) && (onetoone == 0))
            cout << "Problem 3: onto but not one-to-one.\n";
        else if((onto == 0) && (onetoone == 1))
            cout << "Problem 3: one-to-one but not onto.\n";
        else if((onto == 1) && (onetoone == 1))
            cout << "Problem 3: bijective.\n";
        else if((onto == 0) && (onetoone == 0))
            cout << "Problem 3: neither onto nor one-to-one.\n";
    }
    /* If the sets less than or equal to 2 this works. */
    else{
        if(func == 0)
            cout << "Problem 1: not a function.\n";
        else if((onto == 1) && (onetoone == 0))
            cout << "Problem 1: onto but not one-to-one.\n";
        else if((onto == 0) && (onetoone == 1))
            cout << "Problem 1: one-to-one but not onto.\n";
        else if((onto == 1) && (onetoone == 1))
            cout << "Problem 1: bijective.\n";
        else if((onto == 0) && (onetoone == 0))
            cout << "Problem 1: neither onto nor one-to-one.\n";
        if(inverse_func == 0)
            cout << "Problem 2: not a function.\n";
        else if((onto == 1) && (onetoone_for_inevrse == 0))
            cout << "Problem 2: onto but not one-to-one.\n";
        else if((onto == 0) && (onetoone_for_inevrse == 1))
            cout << "Problem 2: one-to-one but not onto.\n";
        else if((onto == 1) && (onetoone_for_inevrse == 1))
            cout << "Problem 2: bijective.\n";
        else if((onto == 0) && (onetoone_for_inevrse == 0))
            cout << "Problem 2: neither onto nor one-to-one.\n";
    }
    
}

void read_file(vector<vector<string>> &vars, string filename)
{
    ifstream file;
    string line;
    vector<string> set;
    char letter;
    file.open(filename);
    if(!file)
        cerr << "\nERROR!!! The file does not open.";
    while(getline(file, line)){
        if(line.length() == 0)
            continue;
        if((line.size() == 1) && (line[0] >= 65) && (line[0] <= 90)){
            letter = line[0];
            if(letter == 'A'){
                letter++;
                set.clear();   /* Clears the set and increase the letter number. */
            }
            else{
                vars.push_back(set);
                letter++;
                set.clear();   /* Clears the set and increase the letter number. */
            }
        }
        else
            set.push_back(line);
    }
    vars.push_back(set);
    file.close();
}

bool check_function(vector<vector<string>> &vars, int temp)
{
    /* Checks the sets function or not. */
    if(temp == 0){
        if(vars[0].size() > vars[1].size())
            return false;
        for(int i=0; i<vars[0].size(); i++){
            for(int j=i+1; j<vars[0].size()-j; j++){
                if(vars[0][i] == vars[0][j])
                    return false;
            }
        }
    }
    else{
        for(int i=1; i<vars.size()-1; i++){
            if(vars[0].size() > vars[i].size())
                return false;
        }
        for(int k=0; k<vars.size(); k++){
            for(int i=0; i<vars[k].size(); i++){
                for(int j=i+1; j<vars[k].size()-j; j++){
                    if(vars[k][i] == vars[k][j])
                        return false;
                }
            }
        }
    }  
    return true;
}

bool check_inverse_function(vector<vector<string>> &vars, int temp)
{
    /* Checks the sets of the inverse function or not. */
    if(temp == 0){
        if(vars[1].size() > vars[0].size())
            return false;
        for(int i=0; i<vars[1].size(); i++){
            for(int j=i+1; j<vars[1].size()-j; j++){
                if(vars[1][i] == vars[1][j])
                    return false;
            }
        }
    }
    return true;
}

bool is_it_onto(vector<vector<string>> &vars, int temp)
{
    /* Checks the functions onto or not. */
    if(temp == 0){
        if(vars[0].size() == vars[1].size())
            return true;
    }
    else{
        for(int i=0; i<vars.size()-1; i++){
            if(vars[i].size() != vars[i+1].size())
                return false;
        }
        return true;
    }
    return false;
}

bool is_it_one_to_one(vector<vector<string>> &vars, int temp)
{
    /* Checks the functions one to one or not. */
    if(temp == 0){
        for(int i=0; i<vars[1].size(); i++){
            for(int j=i+1; j<vars[1].size()-j; j++){
                if(vars[1][i] == vars[1][j])
                    return false;
            }
        }
    }
    else{
        for(int k=1; k<vars.size(); k++){
            for(int i=0; i<vars[k].size(); i++){
                for(int j=i+1; j<vars[k].size()-j; j++){
                    if(vars[k][i] == vars[k][j])
                        return false;
                }
            }
        }
    }
    return true;
}

bool is_it_onetoone_for_inverse(vector<vector<string>> &vars, int temp)
{
    /* Checks the inverse of the functions one to one or not. */
    for(int i=0; i<vars[0].size(); i++){
        for(int j=i+1; j<vars[0].size()-j; j++){
            if(vars[0][i] == vars[0][j])
                return false;
        }
    }
    return true;
}