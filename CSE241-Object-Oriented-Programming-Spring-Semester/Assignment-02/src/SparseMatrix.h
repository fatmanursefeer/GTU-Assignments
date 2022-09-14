#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "SparseVector.h"

using namespace std;

class SparseMatrix
{
public:
    SparseMatrix();  /* Default constructure */
    SparseMatrix(int rSize, int cSize);  /* This constructure creats an object with this size. */
    SparseMatrix(string filename);  /* This constructure read file and creates object */
    SparseMatrix operator +(const SparseMatrix &other);  /* This function adds two matrices */
    SparseMatrix operator -(const SparseMatrix &other);  /* This function subtracts two matrices */
    SparseMatrix operator -();  /* This function negates elements of the matrix */
    SparseMatrix operator *(const SparseMatrix &other);  /* This function multiplies two matrices */
    SparseMatrix transpose();  /* This function get the traspose of the matrix */
    void operator =(const SparseMatrix &other);  /* This function equals two matrices */
    friend ostream& operator <<(ostream &outs, const SparseMatrix &other);  /* This function writes the vector */
private:
    vector<SparseVector> matrix;  /* Stores the double values */
    int columnSize;     /* Column size */
    void readFile(string filename);    /* This function reads file and creates object */
    int split_the_elements(string item, int rowNumber);  /* This function splits the strings */
};

#endif