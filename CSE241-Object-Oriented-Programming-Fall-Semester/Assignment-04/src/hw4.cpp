#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

#include "hw4.h"

namespace DofSet{

    int DayofYearSet::set_count = 0;

    DayofYearSet::DayofYear::DayofYear(int month_val, int day_val) : month(month_val), day(day_val)
    { }

    DayofYearSet::DayofYear::DayofYear(int month_val) : month(month_val), day(1)   /* assignes to day=1 month=month value. */
    { }

    DayofYearSet::DayofYear::DayofYear() : month(1), day(1)   /* assignes to day=1 month=1. */
    { }

    DayofYearSet::DayofYearSet() : set_size(0)
    {
        day_of_year = new DayofYear[1];  /* creates new dynamic array with one size. */
    }

    DayofYearSet::DayofYearSet(vector<DayofYear> &vec)   /* this function takes vector object. */
    {
        int day, month;
        if(vec.size() > 0)   /* if the size bigger than 0 this works. */
        {
            day_of_year = new DayofYear[vec.size()];  /* creates new dynamic array with vector size. */
            for(int i = 0; i < vec.size(); i++)
            {
                day = vec[i].get_day();
                month = vec[i].get_month();
                day_of_year[i] = DayofYear(month, day);    /* fills the array with vector. */
            }
            set_size = vec.size();   /* set the size with vec size. */
        }
        set_count = vec.size() + set_count;  /* set the static size with vec size + before size. */
    }

    bool DayofYearSet::check_duplicate(int a_month, int a_day)
    {
        for(int i=0; i<set_size; i++){
            if((day_of_year[i].get_day() == a_day) && (day_of_year[i].get_month() == a_month))  /* if the element used before returns false.*/
                return false;
        }
        return true;
    }

    void DayofYearSet::add(int a_month, int a_day)
    {
        int flag = check_duplicate(a_month, a_day);   /* checks the element used before or not. */
        if(flag == 0)
            cout << "\nYou can not add same date.\n";
        else{
            if(set_size == 0){
                day_of_year[0] = DayofYear(a_month, a_day);  /* if size = 0 the it puts the values that place. */
            }
            else{
                DayofYear *temp = new DayofYear[set_size+1];   /* create another dynamic array pointer. */
                for(int i=0; i<set_size; i++)
                    temp[i] = day_of_year[i];   /* copys to main set to temp array. */
                delete [] day_of_year;  /* deletes main array because we do not need them anymore. */
                day_of_year = temp;  /* now it points same place as temp pointer. */
                day_of_year[set_size] = DayofYear(a_month, a_day);  /* it puts the values to end of the array. */
            } 
            set_size++;   /* increase set size. */
            set_count++;   /* increase static set size. */
            check_valid_date();   /* checks the values are valid or not. */
        }
    }

    void DayofYearSet::remove(int index)
    {
        if(index >= set_size)  /* if index bigger than size it gives an error message. */
            cout << "\nYou can not remove an element larger than the size of the array.\n";
        else if(index < 0)    /* if index less than 0 it gives an error mesaaje. */
            cout << "\nYou entered invalid index number.\n";
        else{
            DayofYear *temp = new DayofYear[set_size-1];  /* creates new array pointer with size-1. */
            for(int i=index; i<set_size; i++)
                day_of_year[i] = day_of_year[i+1];  /* it shifts the elements. */
            set_size--;  /* decreases set size. */
            set_count--;  /* decreases static set size. */
            for(int i=0; i<set_size; i++)
                temp[i] = day_of_year[i];  /* copys the elements. */
            delete [] day_of_year;
            day_of_year = temp;  /* now it points same place as temp pointer. */
        }
    }

    DayofYearSet::DayofYear& DayofYearSet::operator [](int index)
    {
        if(set_size == 0){  /* if the array is empty it gives an error message. */
            cout << "\nYour set is empty. Firstly please the set.\n";
            exit(1);
        }
        else if(index >= set_size){   /* if the index is bigger than size it gives an error message. */
            cout << "\nIllegal index for set. Please enter the correct index.\n";
            exit(1);
        }
        return day_of_year[index];   /* if everything is okey then it returns DayofYear object. */
    }

    bool DayofYearSet::operator ==(const DayofYearSet & other) const
    {
        /* if the sets are equal it returns true, else returns false. */
        for(int i=0; i<set_size; i++){
            if((day_of_year[i].get_month() != other.day_of_year[i].get_month()) ||  (day_of_year[i].get_day() != other.day_of_year[i].get_day()))
                return false;
        }
        return true;
    }

    bool DayofYearSet::operator !=(const DayofYearSet & other) const
    {
        /* if the sets are different from each other it returns true, else returns false. */
        for(int i=0; i<set_size; i++){
            if((day_of_year[i].get_month() != other.day_of_year[i].get_month()) ||  (day_of_year[i].get_day() != other.day_of_year[i].get_day()))
                return true;
        }
        return false;
    }

    void DayofYearSet::check_valid_date()   /* this function checks the inputs are valid or not. */
    {
        auto flag = 0;
        if((day_of_year[set_size-1].get_month() < 1) || (day_of_year[set_size-1].get_month() > 12)){
            cout << "\nYou entered wrong month value. In " << set_size-1 << ". index.\n";
            exit(1);
        }
        else if((day_of_year[set_size-1].get_month() == 1) && ((day_of_year[set_size-1].get_day() < 1) || (day_of_year[set_size-1].get_day() > 31)))
            flag = 1;
        else if((day_of_year[set_size-1].get_month() == 2) && ((day_of_year[set_size-1].get_day() < 1) || (day_of_year[set_size-1].get_day() > 28)))
            flag = 1;
        else if((day_of_year[set_size-1].get_month() == 3) && ((day_of_year[set_size-1].get_day() < 1) || (day_of_year[set_size-1].get_day() > 31)))
            flag = 1;
        else if((day_of_year[set_size-1].get_month() == 4) && ((day_of_year[set_size-1].get_day() < 1) || (day_of_year[set_size-1].get_day() > 30)))
            flag = 1;
        else if((day_of_year[set_size-1].get_month() == 5) && ((day_of_year[set_size-1].get_day() < 1) || (day_of_year[set_size-1].get_day() > 31)))
            flag = 1;
        else if((day_of_year[set_size-1].get_month() == 6) && ((day_of_year[set_size-1].get_day() < 1) || (day_of_year[set_size-1].get_day() > 30)))
            flag = 1;
        else if((day_of_year[set_size-1].get_month() == 7) && ((day_of_year[set_size-1].get_day() < 1) || (day_of_year[set_size-1].get_day() > 31)))
            flag = 1;
        else if((day_of_year[set_size-1].get_month() == 8) && ((day_of_year[set_size-1].get_day() < 1) || (day_of_year[set_size-1].get_day() > 31)))
            flag = 1;
        else if((day_of_year[set_size-1].get_month() == 9) && ((day_of_year[set_size-1].get_day() < 1) || (day_of_year[set_size-1].get_day() > 30)))
            flag = 1;
        else if((day_of_year[set_size-1].get_month() == 10) && ((day_of_year[set_size-1].get_day() < 1) || (day_of_year[set_size-1].get_day() > 31)))
            flag = 1;
        else if((day_of_year[set_size-1].get_month() == 11) && ((day_of_year[set_size-1].get_day() < 1) || (day_of_year[set_size-1].get_day() > 30)))
            flag = 1;
        else if((day_of_year[set_size-1].get_month() == 12) && ((day_of_year[set_size-1].get_day() < 1) || (day_of_year[set_size-1].get_day() > 31)))
            flag = 1;
        if(flag == 1){
            cout << "\nYou entered wrong day value. In " << set_size-1 << ". index.\n";
            exit(1);
        }
    }

    DayofYearSet::DayofYearSet(const DayofYearSet & other) : set_size(other.set_size)  /* copy constructure. */
    {
        day_of_year = new DayofYear[set_size];
        for(int i=0; i<set_size; i++)
            day_of_year[i] = other.day_of_year[i];
    }

    DayofYearSet & DayofYearSet::operator =(const DayofYearSet & other)  /* assigment operator. */
    {
        if(this == &other)
            return *this;
        else{
            set_size = other.set_size;
            delete [] day_of_year;
            day_of_year = new DayofYear[set_size];
            for(int i=0; i<set_size; i++)
                day_of_year[i] = other.day_of_year[i];
            return *this;
        }
    }

    DayofYearSet DayofYearSet::operator +(const DayofYearSet & other)
    {
        DayofYearSet temp;  /* create new DayofYearSet object. */
        int size1 = set_size, size2 = other.set_size, temp_size = set_size;
        DayofYear *temp1 = new DayofYear[size1];  /* create new DayofYear pointer object. */
        for(int i=0; i< set_size; i++)
            temp1[i] = day_of_year[i];  /* copys the elements. */
        for(int i=0; i<size1; i++){
            for(int j=0; j<size2; j++){
                if((temp1[i].get_month() == other.day_of_year[j].get_month()) && (temp1[i].get_day() == other.day_of_year[j].get_day())){
                    /* if the values are same then its deletes from the temp array. */
                    for(int k=i; k<temp_size; k++)
                        temp1[k] = temp1[k+1];
                    temp_size--;  /* decreasing the size of temp array. */
                }
            }
        }
        for(int i=0; i<temp_size; i++)
            temp.add(temp1[i].get_month(), temp1[i].get_day());   /* adds the elements to new set. */
        for(int j=0; j<size2; j++)
            temp.add(other.day_of_year[j].get_month(), other.day_of_year[j].get_day());   /* adds the elements to new set. */
    return temp;  /* returns the set. */
    }


    DayofYearSet DayofYearSet::operator -(const DayofYearSet & other)
    {
        DayofYearSet temp;  /* create new DayofYearSet object. */
        int size1 = set_size, size2 = other.set_size, temp_size = set_size;
        DayofYear *temp1 = new DayofYear[size1];  /* create new DayofYear pointer object. */
        for(int i=0; i< set_size; i++)
            temp1[i] = day_of_year[i];  /* copys the elements. */
        for(int i=0; i<size1; i++){
            for(int j=0; j<size2; j++){
                if((temp1[i].get_month() == other.day_of_year[j].get_month()) && (temp1[i].get_day() == other.day_of_year[j].get_day())){
                    /* if the values are same then its deletes from the temp array. */
                    for(int k=i; k<temp_size; k++)
                        temp1[k] = temp1[k+1];
                    temp_size--;  /* decreasing the size of temp array. */
                }
            }
        }
        for(int i=0; i<temp_size; i++)
            temp.add(temp1[i].get_month(), temp1[i].get_day());   /* adds the elements to new set. */
        return temp;
    }

    DayofYearSet DayofYearSet::operator ^(const DayofYearSet & other)
    {
        DayofYearSet temp;  /* create new DayofYearSet object. */
        int size1 = set_size, size2 = other.set_size, t=0;
        DayofYear *temp1 = new DayofYear[size1+size2];  /* create new DayofYear pointer object. */
        for(auto i=0; i<size1; i++){
            for(decltype(i) j=0; j<size2; j++){
                if((day_of_year[i].get_month() == other.day_of_year[j].get_month()) && (day_of_year[i].get_day() == other.day_of_year[j].get_day())){
                    temp1[t] = day_of_year[i];  /* copys the elements. */
                    t++;
                }
            }
        }
        for(int i=0; i<t; i++)
            temp.add(temp1[i].get_month(), temp1[i].get_day());  /* adds the elements to new set. */
        return temp;
    }
    
    ostream& operator <<(ostream& outs, const DayofYearSet & other)    /* this function writes the set to the file. */
    {
        for(int i=0; i<other.set_size; i++)
            outs << "\nDay: " << other.day_of_year[i].get_day() << "\tMonth: " << other.day_of_year[i].get_month() << "\n";
        return outs;
    }

    void DayofYearSet::write_file()   /* this function writes to file to set. */
    {
        ofstream file;
        file.open("text.txt");
        cout << "\n\n";
        for(int i=0; i<set_size; i++)
            file << "Day: " << day_of_year[i].get_day() << "\tMonth: " << day_of_year[i].get_month() << "\n";
        file.close();
    }

    DayofYearSet DayofYearSet::operator!()
    {
        DayofYearSet dofs;  /* create new DayofYearSet object. */
        DayofYear *temp = new DayofYear[365];  /* create new DayofYear pointer object. */
        int k=0, flag=0;
        /* fills the array with 365 days information. */
        for(int i=1; i<=12; i++){
            for(int j=1; j<=31; j++){
                if((i == 1) && (j <= 31))
                    flag = 1;
                else if((i == 2) && (j <= 28))
                    flag = 1;
                else if((i == 3) && (j <= 31))
                    flag = 1;
                else if((i == 4) && (j <= 30))
                    flag = 1;
                else if((i == 5) && (j <= 31))
                    flag = 1;
                else if((i == 6) && (j <= 30))
                    flag = 1;
                else if((i == 7) && (j <= 31))
                    flag = 1;
                else if((i == 8) && (j <= 31))
                    flag = 1;
                else if((i == 9) && (j <= 30))
                    flag = 1;
                else if((i == 10) && (j <= 31))
                    flag = 1;
                else if((i == 11) && (j <= 30))
                    flag = 1;
                else if((i == 12) && (j <= 31))
                    flag = 1;
                if(flag == 1){
                    temp[k] = DayofYear(i, j);  /* fills the array. */
                    k++;
                    flag = 0;
                }
            }
        }
        int size1 = 365, size2 = set_size, temp_size = 365;
        for(int i=0; i<size1; i++){
            for(int j=0; j<size2; j++){
                if((temp[i].get_month() == day_of_year[j].get_month()) && (temp[i].get_day() == day_of_year[j].get_day())){
                    /* if the values are same then its deletes from the temp array. */
                    for(int l=i; l<temp_size; l++)
                        temp[l] = temp[l+1];
                    temp_size--;  /* decreasing the size of temp array. */
                }
            }
        }
        for(int i=0; i<temp_size; i++)
            dofs.add(temp[i].get_month(), temp[i].get_day());  /* adds the elements to new set. */
        return dofs;
    }

    DayofYearSet::~DayofYearSet()  /* destructure */
    {
        delete [] day_of_year;
    }
}