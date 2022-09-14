#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "SparseVector.h"

using namespace std;

SparseVector::SparseVector()
{
    vec.resize(1); /* This constructure creates one size vector */
}

SparseVector::SparseVector(int size)
{
    vec.resize(size);  /* This constructure creates vector with given size */
}

SparseVector::SparseVector(string filename)
{
    read_file(filename);  /* This constructure reads file and creates vector */
}

SparseVector SparseVector::operator +(const SparseVector &other)
{
    if(vec.size() != other.vec.size())  /* If their size is not equal then the program exits */
        exit(1);
    int size = other.vec.size();
    SparseVector sumVector(size);  /* Creates new object with size */
    for(int i=0; i<size; i++)
        sumVector.vec[i] = vec[i] + other.vec[i];  /* Adds elements of the vectors one by one */
    return sumVector;  /* Returns new object */
}

SparseVector SparseVector::operator -(const SparseVector &other)
{
    if(vec.size() != other.vec.size())  /* If their size is not equal then the program exits */
        exit(1);
    int size = other.vec.size();
    SparseVector substVector(size);  /* Creates new object with size */
    for(int i=0; i<size; i++)
        substVector.vec[i] = vec[i] - other.vec[i];  /* Subtract elements of the vectors one by one */
    return substVector;
}

SparseVector SparseVector::operator -()
{
    int size = vec.size();
    SparseVector negVector(size);  /* Creates new object with size */
    for(int i=0; i<size; i++)
        negVector.vec[i] = vec[i] * (-1);  /* Negates all elements of the vector one by one */
    return negVector;
}

void SparseVector::operator =(const SparseVector &other)
{
    int size = other.vec.size();
    vec.resize(size);   /* Resize the vector with other vector size */
    for(int i=0; i<size; i++)
        vec[i] = other.vec[i];  /* Equals all the elements one by one */
}

ostream& operator <<(ostream &outs, const SparseVector & other)
{
    for(int i=0; i<other.vec.size(); i++){
        if(other.vec[i] != 0)  /* If the values are not equal 0.0 then writes the values */
            outs << i << ":" << other.vec[i] << " ";
    }
    return outs;
}

double dot(const SparseVector &first, const SparseVector &second)
{
    if(first.vec.size() != second.vec.size())  /* If their size is not equal then the program exits */
        exit(1);
    double dot_product = 0;
    int size = first.vec.size();
    for(int i=0; i<size; i++)
        dot_product = dot_product + (first.vec[i] * second.vec[i]);  /* Multiply the elements of the vectors one by one and sums them */
    return dot_product;    /* Returns the dot value */
}

void SparseVector::read_file(string filename)
{
    string item;
    ifstream file;
    file.open(filename);  /* Opens the file */
    if(!file)
        exit(1);   /*  If file does not opens then exit the program */
    while(!file.eof()){   /* While end of the file */
        file >> item;   /*  Takes the strings one by one */
        parse_the_element(item);  /*  For the split the elements sends the string */
    }
    file.close();  /* Close the file */
}

void SparseVector::parse_the_element(string item)
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
    vec.resize(var1 + 1);  /* Resize the vector with new read index value */
    vec[var1] = var2;  /* And equals the data with this index of the vector */
}