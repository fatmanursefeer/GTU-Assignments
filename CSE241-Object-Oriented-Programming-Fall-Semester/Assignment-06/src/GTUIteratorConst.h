#ifndef GTUITERATORCONST_H
#define GTUITERATORCONST_H

#include <string>

using namespace std;

namespace GTUIterable
{
    template <class T>
    class GTUIteratorConst   /* GTUIteratorConst class */
    {
    public:
        GTUIteratorConst(T *ptr) : _ptr(ptr) {}
        const T &operator*() { return *_ptr; }
        const T *operator->() { return _ptr; }
        GTUIteratorConst operator++()   /* ++ operator */
        {
            _ptr++;
            return *this;
        }
        GTUIteratorConst operator++(int t)   /* ++ operator */
        {
            GTUIteratorConst temp = *this;
            _ptr++;
            return temp;
        }
        GTUIteratorConst operator--()    /* -- operator */
        {
            _ptr--;
            return *this;
        }
        GTUIteratorConst operator--(int t)    /* -- operator */
        {
            GTUIteratorConst tmp = *this;
            _ptr--;
            return tmp;
        }
        GTUIteratorConst &operator=(const GTUIteratorConst &right){   /* = operator */
	        _ptr = right._ptr;
            return *this;
	    }
        bool operator==(const GTUIteratorConst &other) const { return _ptr == other._ptr; }
        bool operator!=(const GTUIteratorConst &other) const { return _ptr != other._ptr; }
    private:
        T const *_ptr;
    };
}

#endif