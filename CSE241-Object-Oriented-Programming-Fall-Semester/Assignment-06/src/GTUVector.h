#include <iostream>
#include <memory>

#include "Iteable.h"

using namespace std;
using namespace GTUIterable;

/* I did not wrote any destructure because we use shared_ptr all the time so that it is not necessery to wrote any destructure */

namespace GTUIterable
{
    template <class T>
    class GTUVector : public Iterable<T>   /* GTUVector class*/
    {
    public:
        GTUVector();   /* no parameter constructure */
        GTUVector(int size);
        GTUVector(const GTUVector & other); //copy constructure
        GTUVector(GTUVector && other); //move copy constructure
        GTUVector & operator =(const GTUVector & other); //copy = operator
        GTUVector & operator =(GTUVector && other); //move = operator
        bool empty() const;   /* checks the vector is empty or not */
        int size() const;   /* returns the vector size */
        void erase(GTUIterator<T> element);   /* erase the iter at the vector */
        void clear();   /* clears the vector */
        void add(const T &element);   /* adds the element of the vector */
        GTUIterator<T> begin() const;   /* returns begin of the iter of the vector */
        GTUIterator<T> end() const;    /* returns end of the iter of the vector */
        GTUIteratorConst<T> cbegin() const;   /* returns begin of the constant iter of the vector */
        GTUIteratorConst<T> cend() const;   /* returns end of the constant iter of the vector */
        T &operator[](int index);
    private:
        shared_ptr<T> data;
        int capacity = 0;
        int size_ = 0;
    };
}

template <class T>
GTUVector<T>::GTUVector()   /* create a vector */
{
    capacity = 0;
    size_ = 0;
    shared_ptr<T> temp(new T[capacity], default_delete<T[]>());  /* using the shared_ptr */
    data = temp;
}

template <class T>
GTUVector<T>::GTUVector(int size)   /* create vector */
{
    while(size > capacity)
        capacity += 10;
    shared_ptr<T> temp(new T[capacity], default_delete<T[]>());
    data = temp;
}

template <class T>
GTUVector<T>::GTUVector(const GTUVector & other) : size_(other.size_), capacity(other.capacity)  /* copt constructure */
{
    shared_ptr<T> vec(new T[other.capacity], default_delete<T[]>());
    int i=0;
    for(auto iter = other.begin(); iter != other.end(); iter++){
        vec.get()[i] = *iter;
        i++;
    }
    data = vec;
}

template <class T>
GTUVector<T>::GTUVector(GTUVector && other) : size_(other.size_), capacity(other.capacity), data(other.data)   /* move constructure */
{
    other.data = nullptr;
    other.size_ = 0;
    other.capacity = 0;
}

template <class T>
GTUVector<T> & GTUVector<T>::operator =(const GTUVector & other)   /* copy assigment constructure */
{
    if(this == &other)
        return *this;
    else{
        size_ = other.size_;
        capacity = other.capacity;
        delete [] data;
        shared_ptr<T> temp(new T[capacity], default_delete<T[]>());
        int i=0;
        for(auto iter = other.begin(); iter != other.end(); iter++){
            temp.get()[i] = *iter;
            i++;
        }
        data = temp;
        return *this;
    }
}

template <class T>
GTUVector<T> &GTUVector<T>::operator =(GTUVector && other)   /* move assigment constructure */
{
    size_ = other.size_;
    capacity = other.capacity;
    data = other.data;
    other.size_ = 0;
    other.capacity = 0;
    other.data = nullptr;
    return *this;
}

template <class T>
T &GTUVector<T>::operator[](int index)  /* index operator */
{
    return data.get()[index];
}

template <class T>
bool GTUVector<T>::empty() const
{
    return (size_ == 0);  /* checks the vector is empty or not */
}

template <class T>
int GTUVector<T>::size() const
{
    return size_;   /* returns the size */
}

template <class T>
void GTUVector<T>::erase(GTUIterator<T> element)
{
    shared_ptr<T> temp(new T[this->capacity - 1], default_delete<T[]>());  /* update the capacity of vector */
    for(auto iter = begin(), index = 0; iter != end(); iter++, index++)
    {
        if(iter == element)  /* finds the element in the vector */
            index--;
        else
            temp.get()[index] = *iter;
    }
    size_--;
    data = nullptr;
    data = temp;   /* equals the pointers */
}

template <class T>
void GTUVector<T>::clear()   /* clears the vector */
{
    capacity = 0;
    size_ = 0;
    data = nullptr;
}

template <class T>
void GTUVector<T>::add(const T &element)   /* adds the element of the vector */
{
    if(size_ < capacity)   /* if the size less than the capacity adds the element directly */
    {
        *(end()) = element;
        size_++;
    }
    else
    {
        capacity += 10;  /* else increase the size of the vector and then adds the element */
        shared_ptr<T> temp(new T[capacity], default_delete<T[]>());

        for(auto iter = begin(), index = 0; iter != end(); iter++, index++)
            temp.get()[index] = *iter;

        data = nullptr;
        data = temp;
        *(end()) = element;
        size_++;   /* increase the size */
    }
}

template <class T>
GTUIterator<T> GTUVector<T>::begin() const
{
    return GTUIterator<T>(data.get());   /* returns the begin iterator of the vector */
}

template <class T>
GTUIterator<T> GTUVector<T>::end() const
{
    return GTUIterator<T>(data.get() + size_);  /* returns the end iterator of the vector */
}

template <class T>
GTUIteratorConst<T> GTUVector<T>::cbegin() const
{
    return GTUIteratorConst<T>(data.get());  /* returns the begin constant iterator of the vector */
}

template <class T>
GTUIteratorConst<T> GTUVector<T>::cend() const
{
    return GTUIteratorConst<T>(data.get() + size_);   /* returns the end constant iterator of the vector */
}