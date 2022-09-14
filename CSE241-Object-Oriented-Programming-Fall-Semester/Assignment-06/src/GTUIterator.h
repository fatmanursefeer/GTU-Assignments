#ifndef GTUITERATOR_H
#define GTUITERATOR_H

#include <string>

using namespace std;

namespace GTUIterable
{
    template <class T>
    class GTUIterator   /* GTUIterator class */
    {
    public:
        GTUIterator(T *ptr) : _ptr(ptr) {}
        T &operator*() const { return *_ptr; }
        T *operator->() const { return _ptr; }
        GTUIterator &operator++()   /* ++ operator */
        {
            _ptr++;
            return *this;
        }
        GTUIterator operator++(int t)  /* ++ operator */
        {
            GTUIterator temp = *this;
            _ptr++;
            return temp;
        }
        GTUIterator &operator--()  /* -- operator */
        {
            _ptr--;
            return *this;
        }
        GTUIterator operator--(int t)   /* -- operator */
        {
            GTUIterator temp = *this;
            _ptr--;
            return temp;
        }
        GTUIterator &operator=(const GTUIterator &right){   /* = operator */
	        _ptr=right._ptr;
	        return *this;
	    }
        bool operator==(const GTUIterator &other) const { return _ptr == other._ptr; }
        bool operator!=(const GTUIterator &other) const { return _ptr != other._ptr; }
    private:
        T *_ptr;
    };
}

#endif