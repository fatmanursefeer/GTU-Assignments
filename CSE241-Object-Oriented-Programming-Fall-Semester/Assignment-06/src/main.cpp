#include "GTUSet.h"
#include "GTUVector.h"
#include "GTUArray.h"

#include <iostream>

using namespace std;
using namespace GTUIterable;

template<class T>
void printSet(GTUSet<T> setForDouble);

template<class T>
void printVector(const GTUVector<T> vectorForInt);

template<class T, int capacity>
void printArray(GTUArray<T, capacity> arrayForChar);


int main()
{
    GTUSet<double> set;
    cout << "\n\nSTART OF SET TEST!\n\n";
    cout << "Size of set is : " << set.size() << "\n";
    cout << "Is the set empty? (yes:1, no:0) : " << set.empty() << "\n\n";
    set.add(5.6);
    set.add(6.8);
    set.add(7.1);
    set.add(98.1);
    set.add(9.3);
    set.add(66.3);
    cout << "Insertion is done! \n";
    cout << "---Printing SET---\n";
    printSet(set);
    cout << "Printing is done! \n\n";
    cout << "Erasing values at begin\n";
    set.erase(set.begin());
    cout << "Erase is done! \n";
    cout << "\n---Printing SET---\n";
    printSet(set);
    cout << "\n2. index of the set is : " << set[2] << endl;

    GTUSet<double> set2;
    set2.add(9.6);
    set2.add(6.8);
    set2.add(8.1);
    set2.add(7.9);
    cout << "\nPrinting the second set\n";
    printSet(set2);
    bool res = set2.search(6.8);
    cout << "\nThe elemement(6.8) is inside the set? (yes:1, no:0) : " << res << endl;
    cout << "\nDelete value 7.9\n";
    set2.delete_(7.9);
    cout << "Delete is done! \n\n";
    cout << "Printing the second set\n";
    printSet(set2);

    GTUSet<double> set3;
    set3 = set.intersection(set2);
    cout << "\nPrinting the intersection of the two sets\n";
    printSet(set3);

    cout << "\n";
    GTUSet<double> set4;
    set4 = set.union_(set2);
    cout << "\nPrinting the union of the two sets\n";
    printSet(set4);
    cout << "\n\nClearing the first set\n";
    set.clear();
    cout << "Clearing is done! \n";
    printSet(set);
    cout << "\nEnd of the set test!\n\n";


    GTUVector<int> vec;
    cout << "\n\nSTART OF VECTOR TEST!\n\n";
    cout << "Size of vector is : " << vec.size() << "\n";
    cout << "Is the vector empty? (yes:1, no:0) : " << vec.empty() << "\n\n";
    vec.add(52);
    vec.add(68);
    vec.add(71);
    vec.add(981);
    vec.add(93);
    vec.add(663);
    cout << "Insertion is done! \n";
    cout << "---Printing VECTOR---\n";
    printVector(vec);
    cout << "Printing is done! \n\n";
    cout << "Erasing values at begin\n";
    vec.erase(vec.begin());
    cout << "Erase is done! \n";
    cout << "\n---Printing VECTOR---\n";
    printVector(vec);
    cout << "\n2. index of the vector is : " << vec[2] << endl;
    cout << "\nClearing the vector\n";
    vec.clear();
    cout << "Clearing is done! \n";
    printVector(vec);
    cout << "\nEnd of the vector test!\n";


    GTUArray<char, 5> arr;
    cout << "\n\nSTART OF ARRAY TEST!\n\n";
    cout << "Size of array is : " << arr.size() << "\n";
    cout << "Is the arrar empty? (yes:1, no:0) : " << arr.empty() << "\n\n";
    arr[0] = 'f';
    arr[1] = 'a';
    arr[2] = 't';
    arr[3] = 'm';
    arr[4] = 'a';
    cout << "Insertion is done! \n";
    cout << "---Printing ARRAY---\n";
    printArray(arr);
    cout << "Printing is done! \n\n";
    cout << "Erasing values at begin\n";
    arr.erase(arr.begin());
    cout << "Erase is done! \n";
    cout << "\n---Printing ARRAY--\n";
    printArray(arr);
    cout << "\n2. index of the array is : " << arr[2] << endl;
    cout << "\nClearing the array\n";
    arr.clear();
    cout << "Clearing is done! \n";
    cout << "\nEnd of the array test!\n\n";
}

template <class T>
void printSet(GTUSet<T> setForDouble)
{
    cout << "Size of set is " << setForDouble.size() << endl;
    cout << "Is the set empty? (yes:1, no:0) :  " << setForDouble.empty() << endl;
    for(GTUIterator<T> i = setForDouble.begin(); i != setForDouble.end(); i++)
        cout << *i << " ";
    cout << endl;
}

template <class T>
void printVector(const GTUVector<T> vectorForInt)
{
    cout << "Size of vector is " << vectorForInt.size() << endl;
    cout << "Is the vector empty? (yes:1, no:0) :  " << vectorForInt.empty() << endl;
    for(GTUIterator<T> iter = vectorForInt.begin(); iter != vectorForInt.end(); iter++)
        cout << *iter << " ";
    cout << endl;
}

template <class T, int capacity>
void printArray(GTUArray<T, capacity> arrayForChar)
{
    cout << "Size of array is : " << arrayForChar.size() << endl;
    cout << "Is the array empty? (yes:1, no:0) :  " << arrayForChar.empty() << endl;
    for(GTUIterator<T> iter = arrayForChar.begin(); iter != arrayForChar.end(); iter++)
        cout << *iter << " ";
    cout << endl;
}