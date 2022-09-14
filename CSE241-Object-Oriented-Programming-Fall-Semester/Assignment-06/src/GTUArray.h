#include <iostream>
#include <memory>
#include <algorithm>

#include "Iteable.h"

using namespace std;
using namespace GTUIterable;

/* I did not wrote any destructure because we use shared_ptr all the time so that it is not necessery to wrote any destructure */

namespace GTUIterable
{
    template <class T, int capacity>
    class GTUArray : public Iterable<T>   /* GTUArray class */
    {
    public:
        GTUArray();  /* no parameter constructure */
        GTUArray(const GTUArray & other); //copy constructure
        GTUArray(GTUArray && other); //move copy constructure
        GTUArray & operator =(const GTUArray & other); //copy = operator
        GTUArray & operator =(GTUArray && other); //move = operator
        bool empty() const;  /* checks the array is empty or not */
        int size() const;   /* returns the size of the array */
        void erase(GTUIterator<T> element);  /* erase the iter of the array */
        void clear();   /* clears the array */
        GTUIterator<T> begin() const;    /* returns the begin iterator of the array */
        GTUIterator<T> end() const;    /* returns the end iterator of the array */
        GTUIteratorConst<T> cbegin() const;    /* returns the begin constant iterator of the array */
        GTUIteratorConst<T> cend() const;    /* returns the end constant iterator of the array */
        T &operator[](int index);  /* index operator */
    private:
        shared_ptr<T> arr;
        int cap;
    };
}

template <class T, int capacity>
GTUArray<T, capacity>::GTUArray()   /* no parameter constructure */
{
    cap = capacity;
    shared_ptr<T> temp(new T[cap], default_delete<T[]>());  /* using shared_ptr */
    arr = temp;
}

template <class T, int capacity>
GTUArray<T, capacity>::GTUArray(const GTUArray & other) : cap(other.cap)   /* copy constructure */
{
    shared_ptr<T> array(new T[other.cap], default_delete<T[]>());
    int i=0;
    for(auto iter = other.begin(); iter != other.end(); iter++){
        array.get()[i] = *iter;
        i++;
    }
    arr = array;
}

template <class T, int capacity>
GTUArray<T, capacity>::GTUArray(GTUArray && other) : cap(other.cap), arr(other.arr)  /* move constructure */
{
    other.arr = nullptr;
    other.cap = 0;
}

template <class T, int capacity>
GTUArray<T, capacity> & GTUArray<T, capacity>::operator =(const GTUArray & other)  /* copy assigment constructure */
{
    if(this == &other)
        return *this;
    else{
        cap = other.cap;
        delete [] arr;
        shared_ptr<T> temp(new T[cap], default_delete<T[]>());
        int i=0;
        for(auto iter = other.begin(); iter != other.end(); iter++){
            temp.get()[i] = *iter;
            i++;
        }
        arr = temp;
        return *this;
    }
}

template <class T, int capacity>
GTUArray<T, capacity> &GTUArray<T, capacity>::operator =(GTUArray && other)   /* move assigment constructure */
{
    cap = other.cap;
    arr = other.arr;
    other.cap = 0;
    other.arr = nullptr;
    return *this;
}

template <class T, int capacity>
bool GTUArray<T, capacity>::empty() const
{
    return (size() == 0);  /* checks the array is empty or not */
}

template <class T, int capacity>
int GTUArray<T, capacity>::size() const
{
    return cap;  /* returns the size of the array */
}

template <class T, int capacity>
void GTUArray<T, capacity>::erase(GTUIterator<T> element)   /* erase the iter of the array */
{
    shared_ptr<T> temp(new T[this->cap - 1], default_delete<T[]>());
    for(auto iter = begin(), index = 0; iter != end(); iter++, index++)
    {
        if (iter == element)  /* finds the iter */
            index--;
        else
            temp.get()[index] = *iter;
    }
    arr = nullptr;
    arr = temp;
}

template <class T, int capacity>
void GTUArray<T, capacity>::clear()   /* clears the array */
{
    arr = nullptr;
    shared_ptr<T> temp(new T[this->cap], default_delete<T[]>());
    arr = temp;
}

template <class T, int capacity>
GTUIterator<T> GTUArray<T, capacity>::begin() const
{
    return GTUIterator<T>(arr.get());    /* returns the begin iterator of the array */
}

template <class T, int capacity>
GTUIterator<T> GTUArray<T, capacity>::end() const
{
    return GTUIterator<T>(arr.get() + cap);    /* returns the end iterator of the array */
}

template <class T, int capacity>
GTUIteratorConst<T> GTUArray<T, capacity>::cbegin() const
{
    return GTUIteratorConst<T>(arr.get());    /* returns the begin const iterator of the array */
}

template <class T, int capacity>
GTUIteratorConst<T> GTUArray<T, capacity>::cend() const
{
    return GTUIteratorConst<T>(arr.get() + cap);    /* returns the end const iterator of the array */
}

template <class T, int capacity>
T &GTUArray<T, capacity>::operator[](int index)
{
    return arr.get()[index];
}