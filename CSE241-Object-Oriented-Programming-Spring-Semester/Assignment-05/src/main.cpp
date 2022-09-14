/* For execute the all program with makefile you have to follow these steps ==> 1)make pa5   2)./pa5   */
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Gate.h"

using namespace std;

/* this function reads the circuit.txt and sets the vector<Gate*> gates */
int readCircuitFile(vector<Gate*> &gates, string& d1, string& d2, string& d3, string& d4);

/* this function reads the input.txt and calculate the outputs */
void readInputFile(vector<Gate*> &gates, int counter, string& d1, string& d2, string& d3, string& d4);

/* main function */
int main()
{
    string d1, d2, d3, d4;  /* for output gate names */
    int counter;  /* for gate number */
    vector<Gate*> gates;  /* vector for gates* s */
    counter = readCircuitFile(gates, d1, d2, d3, d4);  /* reads the circuit.txt and returns the gates number */
    readInputFile(gates, counter, d1, d2, d3, d4);  /* reads the input.txt and calculates and writes the outputs */
}

int readCircuitFile(vector<Gate*> &gates, string& d1, string& d2, string& d3, string& d4)
{
    ifstream file;
    string temp;
    int counter = 0;
    file.open("circuit.txt");  /* opens the file */
    while(!file.eof()){  /* while end of the file */
        file >> temp;  /* takes the value */
        if(temp == "INPUT"){  /* if it is INPUT this block works */
            while(file.peek() != '\n'){  /* while end of the line */
                file >> temp;  /* takes the values */
                counter++;  /* increases the counter */
            }
        }
        else if(temp == "OUTPUT"){  /* if it is OUTPUT this block works */
            while(file.peek() != '\n'){  /* while end of the line */
                file >> temp;  /* takes the values */
                counter++;  /* increases the counter */
            }
        }
        else if(file.peek() == '\n')  /* if it is not INPUT or OUTPUT this block works */
            counter++;  /* increases the counter */
    }
    file.clear();
    file.seekg (0, ios::beg);  /* returns the begin of the file and reads second time */
    while(!file.eof()){  /* while end of the file */
        file >> temp;    /* takes value */
        if(temp == "INPUT"){  /* if it is INPUT this block works */
            while(file.peek() != '\n'){    /* while end of the line */
                file >> temp;  /* takes the gate name */
                InputGate* tempInGate = new InputGate(temp);   /*  creates InputGate* by the name of temp */
                gates.push_back(tempInGate);  /* adds the this object in the vector */
            }
        }
        else if(temp == "OUTPUT"){  /* if it is OUTPUT this block works */
            while(file.peek() != '\n'){   /* while end of the line */
                file >> temp;  /* takes the gate name */
                OutputGate* tempOutputGate = new OutputGate(temp);  /*  creates OutputGate* by the name of temp */
                gates.push_back(tempOutputGate); /* adds the this object in the vector */
            }
        }
        else if(temp == "AND"){  /* if it is AND this block works */
            file >> temp;  /* takes the gate name */
            AndGate* tempAndGate = new AndGate(temp);  /*  creates AndGate* by the name of temp */
            gates.push_back(tempAndGate); /* adds the this object in the vector */
            file >> temp;  /* takes first input name */
            for(int j=0; j<counter; j++){  /* searches the entire vector for the input name it receives */
                if(gates[j]->getGateName() == temp){  /* if it finds that name in the vector then it equalizes these two pointers */
                    tempAndGate->in1 = gates[j];   /* equalizes two pointers */
                    break;
                }
            }
            file >> temp;  /* takes second input name */
            for(int j=0; j<counter; j++){  /* searches the entire vector for the input name it receives */
                if(gates[j]->getGateName() == temp){  /* if it finds that name in the vector then it equalizes these two pointers */
                    tempAndGate->in2 = gates[j];   /* equalizes two pointers */
                    break;
                }
            }
        }
        else if(temp == "OR"){  /* if it is OR this block works */
            file >> temp;  /* takes the gate name */
            OrGate* tempOrGate = new OrGate(temp);  /*  creates OrGate* by the name of temp */
            gates.push_back(tempOrGate); /* adds the this object in the vector */
            file >> temp;  /* takes first input name */
            for(int j=0; j<counter; j++){  /* searches the entire vector for the input name it receives */
                if(gates[j]->getGateName() == temp){  /* if it finds that name in the vector then it equalizes these two pointers */
                    tempOrGate->in1 = gates[j];   /* equalizes two pointers */
                    break;
                }
            }
            file >> temp;  /* takes second input name */
            for(int j=0; j<counter; j++){  /* searches the entire vector for the input name it receives */
                if(gates[j]->getGateName() == temp){  /* if it finds that name in the vector then it equalizes these two pointers */
                    tempOrGate->in2 = gates[j];   /* equalizes two pointers */
                    break;
                }
            }
        }
        else if(temp == "NOT"){  /* if it is NOT this block works */
            file >> temp;  /* takes the gate name */
            NotGate* tempNotGate = new NotGate(temp);  /*  creates NotGate* by the name of temp */
            gates.push_back(tempNotGate); /* adds the this object in the vector */
            file >> temp;  /* takes input name */
            for(int j=0; j<counter; j++){  /* searches the entire vector for the input name it receives */
                if(gates[j]->getGateName() == temp){  /* if it finds that name in the vector then it equalizes these two pointers */
                    tempNotGate->in1 = gates[j];   /* equalizes two pointers */
                    break;
                }
            }
        }
        else if(temp == "FLIPFLOP"){  /* if it is FLIPFLOP this block works */
            file >> temp;  /* takes the gate name */
            FlipFlopGate* tempFlipFlopGate = new FlipFlopGate(temp);  /*  creates FlipFlopGate* by the name of temp */
            gates.push_back(tempFlipFlopGate); /* adds the this object in the vector */
            file >> temp;  /* takes input name */
            for(int j=0; j<counter; j++){  /* searches the entire vector for the input name it receives */
                if(gates[j]->getGateName() == temp){  /* if it finds that name in the vector then it equalizes these two pointers */
                    tempFlipFlopGate->in1 = gates[j];   /* equalizes two pointers */
                    break;
                }
            }
        }
        else if(temp == "DECODER"){  /* if it is DECODER this block works */
            int data, num;
            DecoderGate* tempDecoderGate = new DecoderGate();  /*  creates DecoderGate* with no parameter constructor */
            gates.push_back(tempDecoderGate); /* adds the this object in the vector */
            file >> d1;  /* takes first output name of the decoder */
            file >> d2;  /* takes second output name of the decoder */
            file >> d3;  /* takes third output name of the decoder */
            file >> d4;  /* takes fourth output name of the decoder */
            file >> temp;  /* takes first input name */
            for(int j=0; j<counter; j++){  /* searches the entire vector for the input name it receives */
                if(gates[j]->getGateName() == temp){  /* if it finds that name in the vector then it equalizes these two pointers */
                    tempDecoderGate->in1 = gates[j];   /* equalizes two pointers */
                    break;
                }
            }
            file >> temp;  /* takes second input name */
            for(int j=0; j<counter; j++){  /* searches the entire vector for the input name it receives */
                if(gates[j]->getGateName() == temp){  /* if it finds that name in the vector then it equalizes these two pointers */
                    tempDecoderGate->in2 = gates[j];   /* equalizes two pointers */
                    break;
                }
            }
        }
    }
    file.close();  /* close the file */
    return counter;  /* return the gate numbers */
}

void readInputFile(vector<Gate*> &gates, int counter, string& d1, string& d2, string& d3, string& d4)
{
    ifstream file;
    int temp, i, data, num;
    string t;
    char ch;
    file.open("input.txt");  /* open input.txt */
    while(!file.eof()){    /* while end of the file */
        i = 0;
        while(file.peek() != '\n'){   /* while end of the line */
            if(file.eof() == 1)  /* if end of the file breaks the loop I check here again because if i do not check it enters the infinite loop */
                break;
            file >> temp;  /* takes input */
            gates[i]->setGateData(temp);  /* equalizes the input data */
            i++;  /* increases i */
        }
        if(file.eof() == 1)  /* if end of the file breaks the loop I check here again because if i do not check it enters the infinite loop */
             break;
        ch = file.get();  /* for '\n' */
        data = gates[counter-1]->evaluate();  
        num = data % 10;  
        for(int j=0; j<counter; j++){
            if(gates[j]->getGateName() == d1){  
              gates[j]->setGateData(num);  
             cout << gates[j]->getGateData() << " ";  
              break;
            }
        }
        data = data / 10;  
        num = data % 10;  
        for(int j=0; j<counter; j++){
            if(gates[j]->getGateName() == d2){  
                gates[j]->setGateData(num);  
                cout << gates[j]->getGateData() << " ";  
                break;
            }
        }
        data = data / 10;  
        num = data % 10;  
        for(int j=0; j<counter; j++){
            if(gates[j]->getGateName() == d3){  
                gates[j]->setGateData(num);  
                cout << gates[j]->getGateData() << " ";  
                break;
            }
        }
        data = data / 10;  
        num = data % 10;  
        for(int j=0; j<counter; j++){
            if(gates[j]->getGateName() == d4){  
                gates[j]->setGateData(num);  
                cout << gates[j]->getGateData() << " ";  
                break;
            }
        }
        for(int j=0; j<counter; j++)
            gates[j]->setFlag(0);  
        cout << endl;
    }
    file.close();  /* close the file */
}
