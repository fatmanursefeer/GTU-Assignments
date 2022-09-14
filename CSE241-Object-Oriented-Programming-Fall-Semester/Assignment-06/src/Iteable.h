#ifndef ITERABLE_H
#define ITERABLE_H

#include "GTUIterator.h"
#include "GTUIteratorConst.h"

namespace GTUIterable
{
    template <class T>
    class Iterable   /* abstract Iterable class */
    {
    public:
        virtual bool empty() const = 0;
        virtual int size() const = 0;
        virtual void erase(GTUIterator<T> position) = 0;
        virtual void clear() = 0;
        virtual GTUIterator<T> begin() const = 0;
        virtual GTUIterator<T> end() const = 0;
        virtual GTUIteratorConst<T> cbegin() const = 0;
        virtual GTUIteratorConst<T> cend() const = 0;
    };
}   /* namespace GTUIterable */

#endif