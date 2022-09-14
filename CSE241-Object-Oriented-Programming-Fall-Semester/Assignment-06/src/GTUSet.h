#include <iostream>
#include <memory>

#include "Iteable.h"

using namespace std;
using namespace GTUIterable;

/* I did not wrote any destructure because we use shared_ptr all the time so that it is not necessery to wrote any destructure */

namespace GTUIterable
{
    template <class T>
    class GTUSet : public Iterable<T>   /* GTUSet class */
    {
    public:
        GTUSet();  /* no parameter constructure*/
        GTUSet(int size);
        GTUSet(const GTUSet & other); //copy constructure
        GTUSet(GTUSet && other); //move copy constructure
        GTUSet & operator =(const GTUSet & other); //copy = operator
        GTUSet & operator =(GTUSet && other); //move = operator
        bool empty() const;    /* checks the set is empty or not */
        int size() const;   /* returns the size of the set */
        void erase(GTUIterator<T> element);   /* erase the iter of the set */
        void clear();   /* clears the set */
        bool search(const T &element);   /* search the element in the set */
        void add(const T &element);   /* adds the element of the set */
        void delete_(const T &element);   /* deletes element of the set */
        GTUSet<T> intersection(const GTUSet<T> &other);   /* returs the intersection of the two sets */
        GTUSet<T> union_(const GTUSet<T> &other);   /* returns the union of the two sets */
        GTUIterator<T> begin() const;  /* returns the begin iterator of the set */
        GTUIterator<T> end() const;   /* returns the end iterator of the set */
        GTUIteratorConst<T> cbegin() const;   /* returns the begin constant iterator of the set */
        GTUIteratorConst<T> cend() const;   /* returns the end constant iterator of the set */
        T &operator[](int index);
    private:
        shared_ptr<T> data;
        int capacity = 0;
        int size_ = 0;
    };
}

template <class T>
GTUSet<T>::GTUSet()   /* no parameter constructure */
{
    capacity = 0;
    size_ = 0;
    shared_ptr<T> temp(new T[capacity], default_delete<T[]>());  /* using shared_ptr */
    data = temp;
}

template <class T>
GTUSet<T>::GTUSet(int size)
{
    while(size > capacity)
        capacity += 10;
    shared_ptr<T> temp(new T[capacity], default_delete<T[]>());
    data = temp;
}

template <class T>
GTUSet<T>::GTUSet(const GTUSet & other) : size_(other.size_), capacity(other.capacity)  /* copy constructure */
{
    shared_ptr<T> set(new T[other.capacity], default_delete<T[]>());
    int i=0;
    for(auto iter = other.begin(); iter != other.end(); iter++){
        set.get()[i] = *iter;
        i++;
    }
    data = set;
}

template <class T>
GTUSet<T>::GTUSet(GTUSet && other) : size_(other.size_), capacity(other.capacity), data(other.data)   /* move constructure */
{
    other.data = nullptr;
    other.size_ = 0;
    other.capacity = 0;
}

template <class T>
GTUSet<T> & GTUSet<T>::operator =(const GTUSet & other)   /* copy assigment constructure */
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
GTUSet<T> &GTUSet<T>::operator =(GTUSet && other)  /* move assigment constructure */
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
bool GTUSet<T>::empty() const
{
    return (size_ == 0);   /* checks the set is empty or not */
}

template <class T>
int GTUSet<T>::size() const
{
    return size_;    /* returns the size of the set */
}

template <class T>
void GTUSet<T>::erase(GTUIterator<T> element)   /* erase the iter of the set */
{
    shared_ptr<T> temp(new T[this->capacity - 1], default_delete<T[]>());
    for(auto iter = begin(), index = 0; iter != end(); iter++, index++)
    {
        if (iter == element)   /* finds the iter */
            index--;
        else
            temp.get()[index] = *iter;
    }
    size_--;
    data = nullptr;
    data = temp;  /* assign the pointers */
}

template <class T>
void GTUSet<T>::clear()   /* clears the set */
{
    capacity = 0;
    size_ = 0;
    data = nullptr;
}

template <class T>
bool GTUSet<T>::search(const T &element)   /* search the element in the set */
{
    for(auto iter = begin(); iter != end(); iter++){
        if(*iter == element)
            return true;
    }
    return false;
}

template <class T>
void GTUSet<T>::add(const T &element)   /* adds the element in the set */
{
    try{   /* if the element already exist in the set gives an error messaje */
        for(auto iter = begin(); iter != end(); iter++)
        {
            if(*iter == element)
                throw " already added!!!\n";
        }
        if(size_ < capacity)
        {
            *(end()) = element;
            size_++;
        }
        else
        {
            capacity += 10;
            shared_ptr<T> temp(new T[this->capacity], default_delete<T[]>());
            
            for(auto iter = begin(), index = 0; iter != end(); iter++, index++)
                temp.get()[index] = *iter;

            data = nullptr;
            data = temp;
            *(end()) = element;
            size_++;
        }
    }
    catch(const char *errorMessage){
        cerr << element << errorMessage;
    }    
}

template <class T>
void GTUSet<T>::delete_(const T &element)   /* deletes the elements of the set */
{
    shared_ptr<T> temp(new T[this->capacity - 1], default_delete<T[]>());
    for(auto iter = begin(), index = 0; iter != end(); iter++, index++)
    {
        if (*iter == element)
            index--;
        else
            temp.get()[index] = *iter;
    }
    size_--;
    data = nullptr;
    data = temp;
}

template <class T>
GTUSet<T> GTUSet<T>::intersection(const GTUSet<T> &other)   /* returns the intersection of the two sets */
{
    GTUSet<T> temp;
    int i=0, setSize;
    if(this->size_ > other.size_)
        setSize = this->size_;
    else
        setSize = other.size_;
    shared_ptr<T> intersectionSet(new T[setSize], default_delete<T[]>());   /* create new set */
    for(auto iter = begin(); iter != end(); iter++){
        for(auto iter2 = other.begin(); iter2 != other.end(); iter2++){
            if(*iter == *iter2){
                intersectionSet.get()[i] = *iter;  /* assigns the iters */
                i++;
            }
        }
    }
    for(int j=0; j<i; j++)
        temp.add(intersectionSet.get()[j]);  /* adds the elements of the new set */
    return temp;
}

template <class T>
GTUSet<T> GTUSet<T>::union_(const GTUSet<T> &other)   /* returns the union set of the two sets */
{
    GTUSet<T> temp;
    int i=0;
    int setSize = this->size_ + other.size_;
    shared_ptr<T> unionSet(new T[setSize], default_delete<T[]>());  /* creates new set */
    for(auto iter = begin(); iter != end(); iter++){
        unionSet.get()[i] = *iter;   /* adds the iters */
        i++;
    }
    for(auto iter2 = other.begin(); iter2 != other.end(); iter2++){
        unionSet.get()[i] = *iter2;  /* adds the iters */
        i++;
    }
    for(int j=0; j<i; j++)
        temp.add(unionSet.get()[j]);  /* add the elements of the new set */
    return temp;
}

template <class T>
GTUIterator<T> GTUSet<T>::begin() const
{
    return GTUIterator<T>(data.get());    /* returns the begin iterator of the set */
}

template <class T>
GTUIterator<T> GTUSet<T>::end() const
{
    return GTUIterator<T>(data.get() + size_);    /* returns the end iterator of the set */
}

template <class T>
GTUIteratorConst<T> GTUSet<T>::cbegin() const
{
    return GTUIteratorConst<T>(data.get());    /* returns the begin constant iterator of the set */
}

template <class T>
GTUIteratorConst<T> GTUSet<T>::cend() const
{
    return GTUIteratorConst<T>(data.get() + size_);    /* returns the end constant iterator of the set */
}

template <class T>
T &GTUSet<T>::operator[](int index)  /* index operator */
{
    return data.get()[index];
}