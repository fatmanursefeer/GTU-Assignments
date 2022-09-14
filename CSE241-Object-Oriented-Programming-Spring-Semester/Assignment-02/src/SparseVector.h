#ifndef SPARSEVECTOR_H
#define SPARSEVECTOR_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class SparseVector
{
public:
    SparseVector(); /* Default constructure */
    SparseVector(int size);  /* This constructure creats an object with this size. */
    SparseVector(string filename);  /* This constructure read file and creates object */
    SparseVector operator +(const SparseVector &other);  /* This function adds two vectors */
    SparseVector operator -(const SparseVector &other);  /* This function subtracts two vectors */
    SparseVector operator -();  /* This function negates elements of the vector */
    void operator =(const SparseVector &other);  /* This function equals two vectors */
    friend ostream& operator <<(ostream &outs, const SparseVector & other);  /* This function writes the vector */
    friend double dot(const SparseVector &first, const SparseVector &second); /* This function multiply elements of the vectors */
    vector<double> vec;  /* Stores the double values */
private:
    void read_file(string filename);  /* This function reads file and creates object */
    void parse_the_element(string item);  /* This function parses the strings */
};

#endif