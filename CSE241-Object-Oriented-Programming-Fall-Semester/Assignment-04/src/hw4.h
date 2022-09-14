#ifndef HW4_H
#define HW4_H

#include <iostream>
#include <vector>

using namespace std;

namespace DofSet{
    class DayofYearSet   /* create first class. */
    {
    public:
        class DayofYear   /* create inner class. */
        {
            public:
                DayofYear(int month_val, int day_val);  /* two parameter constructure. */
                DayofYear(int month_val);   /* one parameter constructure. */
                DayofYear();   /* no parameter constructure. */
                int get_month() const { return month; }   /* it returns month value. */
                int get_day() const { return day; }   /* it returns day value. */
            private:
                int month;
                int day;
        };
        void add(int a_month, int a_day);   /* adds new DayofYear parameter to DayofYearSet. */
        void remove(int index);   /* removes wanted index of the DayofYear object of the DayofYearSet. */
        void write_file();   /* it write to file to set. */
        int size() { return set_size; }   /* it returns size of the arr. */
        DayofYearSet & operator =(const DayofYearSet & other);   /* this one of the big three assigment operator. */
        DayofYearSet operator +(const DayofYearSet & other);   /* this function returns the union set of the two sets. */
        DayofYearSet operator -(const DayofYearSet & other);    /* this function returns the difference set of the two sets. */
        DayofYearSet operator ^(const DayofYearSet & other);    /* this function returns the intersection set of the two sets. */
        DayofYearSet operator !();   /* this function returns the complemented set of the set. */
        DayofYear & operator [](int index);   /* this function returns DayofYear object of the wanted index of the array. */
        friend ostream& operator <<(ostream &outs, const DayofYearSet & other);   /* this function writes the set to the file. */
        bool operator ==(const DayofYearSet & other) const;   /* this function checks the to sets are equal each other. */
        bool operator !=(const DayofYearSet & other) const;   /* this function checks the to sets are different eanch other. */
        DayofYearSet();   /* constructure of the first class. */
        DayofYearSet(vector<DayofYear> &vec);   /* this contructure works with vector. */
        DayofYearSet(const DayofYearSet & other);   /* this one of the big three copy constructure. */
        ~DayofYearSet();   /* destructure. */
        static int get_count() { return set_count; }   /* this function returns the all of the set elemens. */
        int set_size;
        static int set_count;
    private:
        DayofYear *day_of_year;
        vector<DayofYear> vec;
        void check_valid_date();   /* this function checks the dates are valid or not. */
        bool check_duplicate(int a_month, int a_day);   /* this function checks the elements used in the set before. */
    };
}

#endif