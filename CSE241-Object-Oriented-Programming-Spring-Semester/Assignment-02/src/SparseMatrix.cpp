#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "SparseVector.h"
#include "SparseMatrix.h"

using namespace std;

SparseMatrix::SparseMatrix()
{
    matrix.resize(1);   /* Resize the matrix with size 1 */
    for(int i=0; i<matrix.size(); i++)
        matrix[i].vec.resize(1);  /* And resize the all vectors inside the matrix (rows) with size 1 */
}

SparseMatrix::SparseMatrix(string filename)
{
    readFile(filename);   /* This constructure creates matrix with given size */
}

SparseMatrix::SparseMatrix(int rSize, int cSize)
{
    matrix.resize(rSize);  /* Resize the matrix with given size */
    for(int i=0; i<matrix.size(); i++)
        matrix[i].vec.resize(cSize);  /* And resize the all vectors inside the matrix (every row) with given size */
}

SparseMatrix SparseMatrix::operator +(const SparseMatrix &other)
{
    if((columnSize != other.columnSize) || (matrix.size() != other.matrix.size()))  /* If their row and column size are not equal exits the program */
        exit(1);
    int row = matrix.size();
    SparseMatrix sumMatrix(row, columnSize);  /* Creates new object with this sizes */
    for(int i=0; i<matrix.size(); i++)
        sumMatrix.matrix[i] = matrix[i] + other.matrix[i];  /* Adds all elements of the matrices one by one */
    return sumMatrix;  /* Returns the new object */
}

SparseMatrix SparseMatrix::operator -(const SparseMatrix &other)
{
    if((columnSize != other.columnSize) || (matrix.size() != other.matrix.size()))  /* If their row and column size are not equal exits the program */
        exit(1);
    int row = matrix.size();
    SparseMatrix substMatrix(row, columnSize);  /* Creates new object with this sizes */
    for(int i=0; i<matrix.size(); i++)
        substMatrix.matrix[i] = matrix[i] - other.matrix[i];  /* Subtract all elements of the matrices one by one */
    return substMatrix;  /* Returns the new object */
}

SparseMatrix SparseMatrix::operator -()
{
    int row = matrix.size();
    SparseMatrix negMatrix(row, columnSize);  /* Creates new object with this sizes */
    for(int i=0; i<matrix.size(); i++)
        negMatrix.matrix[i] = -matrix[i];  /* Negates all elements of the matrix one by one */
    return negMatrix;  /* Returns the new object */
}

SparseMatrix SparseMatrix::operator *(const SparseMatrix &other)
{
    if(columnSize != other.matrix.size())  /* If the column of the first matrix and row of the second matrix are not equal then exits the program */
        exit(1);
    int row = matrix.size();
    int column = other.columnSize;
    SparseMatrix multiMatrix(row, column);  /* Creates new object with this sizes */
    SparseVector temp1(columnSize), temp2(columnSize);
    double dotValue;
    for(int i=0; i<matrix.size(); i++){
        int t = 0;
        for(int j=0; j<columnSize; j++)
            temp1.vec[j] = matrix[i].vec[j];   /* Copies the row elements of the first matrix to temp vector */
        for(int k=0; k<column; k++){
            for(int l=0; l<columnSize; l++)
                temp2.vec[l] = other.matrix[l].vec[t];  /* Copies the column elements of the second matrix to another temp vector */
            dotValue = dot(temp1, temp2);  /* And multiply the these temp vectors and get the dot product value */
            multiMatrix.matrix[i].vec[t] = dotValue;  /* And equals the that value to new object to given index */
            t++;
        }
    }
    return multiMatrix;  /* Returns the new object */
}

SparseMatrix SparseMatrix::transpose()
{
    int row = matrix.size();
    SparseMatrix transposeMatrix(columnSize, row);  /* Creates new object with this sizes */
    for(int i=0; i<row; i++){
        for(int j=0; j<columnSize; j++)
            transposeMatrix.matrix[j].vec[i] = matrix[i].vec[j];  /* Equals the elements the new object properly */
    }
    return transposeMatrix;  /* Returns the new object */
}

void SparseMatrix::operator =(const SparseMatrix &other)
{
    int row = other.matrix.size();
    int column = other.columnSize;
    matrix.resize(row);  /* Resize the matrix with new row value */
    for(int i=0; i<row; i++)
        matrix[i] = other.matrix[i];  /* Equals the all elements one by one */
}

ostream& operator <<(ostream &outs, const SparseMatrix &other)
{
    int counter = 0;
    for(int i=0; i<other.matrix.size(); i++){
        for(int j=0; j<other.matrix[i].vec.size(); j++){
            if(other.matrix[i].vec[j] != 0){  /* If the value is not equal 0.0 then writes */
                if(counter != 0)
                    outs << "\n" << i << " ";  /* Prints '\n' every new line except first line */
                else
                    outs << i << " ";  /* Prints the row index */
                counter++;
                break;
            }
        }
        for(int j=0; j<other.matrix[i].vec.size(); j++){
            if(other.matrix[i].vec[j] != 0)  /* If the value is not equal 0.0 then writes */
                outs << j << ":" << other.matrix[i].vec[j] << " ";
        }
    }
    outs << "\n";
    return outs;
}

void SparseMatrix::readFile(string filename)
{
    int rowNumber, columnNumber = 0, tempSize, t;
    string item, item2;
    ifstream file;
    file.open(filename);  /* Opens the file */
    if(!file)
        exit(1);  /* If the file does not opens then exits the program */
    while(!file.eof()){  /* While end of the file */
        file >> item;  /* Takes the strings one by one */
        rowNumber = stoi(item);  /* Takes the row index firstly so converts the string to integer */
        matrix.resize(rowNumber + 1);  /* Resize the matrix with these row number */
        while(1){  /* While see to new line or end of the file keep going */
            file >> item2;   /* Takes the strings one by one */
            if((file.peek() == '\n') || (file.eof())){  /* If there is new line or end of the file this block works */
                tempSize = split_the_elements(item2, rowNumber);  /* Then split the this string properly and returns the column number */
                break;
            }
            else
                tempSize = split_the_elements(item2, rowNumber);  /* If there is not new line or end file then this block works */
        }
        if(tempSize > columnNumber)
            columnNumber = tempSize;  /* If the taken column number value bigger than old column value than is updates */
    }
    file.close();  /* Close the file */
    columnSize = columnNumber;  /* Equals the column sizes */
    for(int i=0; i<rowNumber+1; i++)
        matrix[i].vec.resize(columnNumber);   /* Resize the all rows inside the matrix with given column number */
}

int SparseMatrix::split_the_elements(string item, int rowNumber)
{
    string temp1, temp2;
    int i=0, var1;
    double var2;
    while(item[i] != ':'){   /* While see the char ':' copy to elements temp1 */
        temp1.push_back(item[i]);
        i++;
    }
    var1 = stoi(temp1);  /* Converts string to integer and get the index value */
    i++;
    while(i < item.size()){   /* And after char ':' copy the rest of the string to temp2 */
        temp2.push_back(item[i]);
        i++;
    }
    var2 = stod(temp2);  /* Converts string to double and get the data value */
    matrix[rowNumber].vec.resize(var1 + 1);  /* Resize the matrix's row with new read index value */
    matrix[rowNumber].vec[var1] = var2;    /* And equals the data with this index of the matrix */
    return (var1 + 1);  /* Returns the column number */
}