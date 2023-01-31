package scr;

import java.util.ArrayList;  //For ArrayList
import java.io.PrintWriter;
import java.io.FileOutputStream;
import java.io.FileNotFoundException;

public class DayofYearSet
{
    private DayofYear[] day_of_year;
    public int set_size;
    public static int set_count;

    public static class DayofYear  /* Static inner class */
    {
        private int month;
        private int day;

        public DayofYear()  /* No parameter constructure */
        {
            month = 1;
            day = 1;
        }

        public DayofYear(int month_val)  /* constructure */
        {
            month = month_val;
            day = 1;
        }

        public DayofYear(int month_val, int day_val)  /* constructure */
        {
            month = month_val;
            day = day_val;
        }

        public int get_month()   /* returns the month value */
        {
            return month;
        }

        public int get_day()   /* returns the day value */
        {
            return day; 
        }
    }

    private void check_valid_date()   /* checks the days are valid or invalid */
    {
        int flag = 0;
        int temp = set_size - 1;
        if((day_of_year[set_size-1].get_month() < 1) || (day_of_year[set_size-1].get_month() > 12)){
            System.out.print("\nYou entered wrong month value. In " + temp + ". index.\n");
            System.exit(1);
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
            System.out.print("\nYou entered wrong month value. In " + temp + ". index.\n");
            System.exit(1);
        }
    }

    private boolean check_duplicate(int a_month, int a_day)   /* checks the values are already inside the array or not */
    {
        for(var i=0; i<set_size; i++){
            if((day_of_year[i].get_day() == a_day) && (day_of_year[i].get_month() == a_month))
                return false;
        }
        return true;
    }

    public DayofYearSet()  /* constructure */
    {
        set_size = 0;
        day_of_year = new DayofYear[1];
    }
    
    public DayofYearSet(ArrayList<DayofYear> myArrList)   /* this constructure takes ArrayList parameter */
    {
        int my_day, my_month;
        if(myArrList.size() > 0)   /* if the size bigger than 0 this works. */
        {
            day_of_year = new DayofYear[myArrList.size()];  /* creates new dynamic array with myArrListtor size. */
            for(int i=0; i<myArrList.size(); i++)
            {
                my_day = myArrList.get(i).get_day();
                my_month = myArrList.get(i).get_month();
                day_of_year[i] = new DayofYearSet.DayofYear(my_month, my_day);    /* fills the array with myArrListtor. */
            }
            set_size = myArrList.size();   /* set the size with myArrList size. */
            set_count = myArrList.size() + set_count;  /* set the static size with myArrList size + before size. */
        }
        else
            System.out.print("\nError!! Your vector is empty.\n");
    }

    /**
	 * Return size of the all sets.
	 * 
	 * @param nothing
	 * @return int value all sets
	 */

    public static int get_count()   /* returns the size of the all sets */
    {
        return set_count;
    }

    /**
	 * adds the new values at the set.
	 * 
	 * @param month new month value
     * @param day new day value
	 * @return nothing
	 */

    public void add(int a_month, int a_day)   /* adds the new values of the array */
    {
        boolean flag = check_duplicate(a_month, a_day);   /* checks the element used before or not. */
        if(flag == false)
            System.out.print("\nYou can not add same date.\n");
        else{
            if(set_size == 0)
                day_of_year[0] = new DayofYearSet.DayofYear(a_month, a_day);  /* if size = 0 the it puts the values that place. */
            else{
                DayofYear[] temp = new DayofYear[set_size+1];   /* create another dynamic array pointer. */
                for(int i=0; i<set_size; i++)
                    temp[i] = day_of_year[i];   /* copys to main set to temp array. */
                day_of_year = temp;  /* now it points same place as temp pointer. */
                day_of_year[set_size] = new DayofYearSet.DayofYear(a_month, a_day);  /* it puts the values to end of the array. */
            } 
            set_size++;   /* increase set size. */
            set_count++;   /* increase static set size. */
            check_valid_date();   /* checks the values are valid or not. */
        }
    }

    /**
	 * removes the elements of the sets.
	 * 
	 * @param index
	 * @return nothing
	 */

    public void remove(int index)   /* removes the element of the array */
    {
        if(index >= set_size)  /* if index bigger than size it gives an error message. */
            System.out.print("\nYou can not remove an element larger than the size of the array.\n");
        else if(index < 0)    /* if index less than 0 it gives an error mesaaje. */
            System.out.print("\nYou entered invalid index number.\n");
        else{
            DayofYear[] temp = new DayofYear[set_size-1];  /* creates new array pointer with size-1. */
            for(int i=index; i<set_size-1; i++)
                day_of_year[i] = day_of_year[i+1];  /* it shifts the elements. */
            set_size--;  /* decreases set size. */
            set_count--;  /* decreases static set size. */
            for(int i=0; i<set_size; i++)
                temp[i] = day_of_year[i];  /* copys the elements. */
            day_of_year = temp;  /* now it points same place as temp pointer. */
        }
    }

    /**
	 * returns size of the set.
	 * 
	 * @param nothing
	 * @return int value set size
	 */

    public int size()   /* returns the size of the set */
    { 
        return set_size;
    }

    /**
	 * returns union of the two new DayofYearSet object.
	 * 
	 * @param DayofYearSet new DayofYearSet object
	 * @return DayofYearSet object
	 */

    public DayofYearSet unionSet(final DayofYearSet other)   /* returns the set which is union of the two sets */
    {
        DayofYearSet temp = new DayofYearSet();  /* create new DayofYearSet object. */
        int size1 = set_size, size2 = other.set_size;
        for(int i=0; i<size1; i++)
            temp.add(day_of_year[i].get_month(), day_of_year[i].get_day());   /* adds the elements to new set. */
        for(int j=0; j<size2; j++)
            temp.add(other.day_of_year[j].get_month(), other.day_of_year[j].get_day());   /* adds the elements to new set. */
        return temp;
    }

    /**
	 * returns difference of the two new DayofYearSet object.
	 * 
	 * @param DayofYearSet new DayofYearSet object
	 * @return DayofYearSet object
	 */

    public DayofYearSet differenceSet(final DayofYearSet other)  /* returns the set which is difference of the two sets */
    {
        DayofYearSet temp = new DayofYearSet();  /* create new DayofYearSet object. */
        int size1 = set_size, size2 = other.set_size, temp_size = set_size;
        DayofYear[] temp1 = new DayofYear[size1];  /* create new DayofYear pointer object. */
        for(int i=0; i< set_size; i++)
            temp1[i] = day_of_year[i];  /* copys the elements. */
        for(int i=0; i<size1; i++){
            for(int j=0; j<size2; j++){
                if((temp1[i].get_month() == other.day_of_year[j].get_month()) && (temp1[i].get_day() == other.day_of_year[j].get_day())){
                    /* if the values are same then its deletes from the temp array. */
                    for(int k=i; k<temp_size-1; k++)
                        temp1[k] = temp1[k+1];
                    temp_size--;  /* decreasing the size of temp array. */
                }
            }
        }
        for(int i=0; i<temp_size; i++)
            temp.add(temp1[i].get_month(), temp1[i].get_day());   /* adds the elements to new set. */
        return temp;
    }

    /**
	 * returns intersection of the two new DayofYearSet object.
	 * 
	 * @param DayofYearSet new DayofYearSet object
	 * @return DayofYearSet object
	 */

    public DayofYearSet intersectionSet(final DayofYearSet other)   /* returns the set which is the intersection of the two sets */
    {
        DayofYearSet temp = new DayofYearSet();  /* create new DayofYearSet object. */
        int size1 = set_size, size2 = other.set_size, t=0;
        DayofYear[] temp1 = new DayofYear[size1+size2];  /* create new DayofYear pointer object. */
        for(int i=0; i<size1; i++){
            for(int j=0; j<size2; j++){
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

    /**
	 * returns complement of the set new DayofYearSet object.
	 * 
	 * @param nothing
	 * @return DayofYearSet object
	 */

    public DayofYearSet complementSet()   /* returns the set which is the complement of the set */
    {
        DayofYearSet dofs = new DayofYearSet();  /* create new DayofYearSet object. */
        DayofYear[] temp = new DayofYear[365];  /* create new DayofYear pointer object. */
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
                    temp[k] = new DayofYearSet.DayofYear(i, j);  /* fills the array. */
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
                    for(int l=i; l<temp_size-1; l++)
                        temp[l] = temp[l+1];
                    temp_size--;  /* decreasing the size of temp array. */
                }
            }
        }
        for(int i=0; i<temp_size; i++)
            dofs.add(temp[i].get_month(), temp[i].get_day());  /* adds the elements to new set. */
        return dofs;
    }

    /**
	 * writes to the txt file.
	 * 
	 * @param nothing
	 * @return nothing
	 */

    public void write_file()  /* writes the file the set */
    {
        PrintWriter outputStream = null;
        try{
            outputStream = new PrintWriter(new FileOutputStream("text.txt"));
        }
        catch(FileNotFoundException e){
            System.out.println("Error opening the file text.txt.");   /* if the file is not open then gives an error message */
            System.exit(0);
        }
        outputStream.print("Size of the set is: " + set_size + "\n\n");
        for(int i=0; i<set_size; i++)
            outputStream.print("Day: " + day_of_year[i].get_day() + "\tMonth: " + day_of_year[i].get_month() + "\n");  /* writes the set to file */
        
        outputStream.close();
    }

    /**
	 * writes to DayofYearSet details.
	 * 
	 * @param nothing
	 * @return string value
	 */
        
    public String toString()
    {
        int t = set_size-1;
        for(var i=0; i<t; i++)
            System.out.print("\nDay: " + day_of_year[i].get_day() + "\tMonth: " + day_of_year[i].get_month() + "\n");  /* writes the set */
        return("\nDay: " + day_of_year[t].get_day() + "\tMonth: " + day_of_year[t].get_month() + "\n");
    }

    /**
	 * checks the two sets are equal or not each other
	 * 
	 * @param DayofYearSet new DayofYearSet object
	 * @return boolean value
	 */
    
    public boolean equals(final DayofYearSet other)    /* if the sets are equal it returns true, else returns false. */
    {
        int flag=0;
        if(set_size != other.set_size)
            return false;
        for(int i=0; i<set_size; i++){
            for(int j=0; j<other.set_size; j++){
                if((day_of_year[i].get_day() == other.day_of_year[j].get_day()) && (day_of_year[i].get_month() == other.day_of_year[j].get_month()))
                    flag = 1;
            }
            if(flag == 0)
                return false;
            flag = 0;
        }
        return true;
    }
}
