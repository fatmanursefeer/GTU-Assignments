#include <iostream>
#include <vector>

using namespace std;

#include "hw4.h"

int main(){
    using DofSet::DayofYearSet;
    DayofYearSet s1, s2, s3, s4;   /* create new DayofYearSet objects. */
    int i;
    s1.add(2,3);   /* use add function more than 2 . */
    s1.add(2,4);
    s1.add(5,7);
    s1.add(11,9);

    cout << "\ns1: \n";
    cout << s1;    /* writes the s1*/
    
    int size_stc = DayofYearSet::get_count();    /* returns the size of the all sets. */
    i = s1.size();   /* returns the size of the set. */
    cout << "\nSize of s1: " << i;
    cout << "\nSize of all sets: " << size_stc << endl;

    s2.add(12,3);   /* fill the s2 with add function. */
    s2.add(4,7);
    s2.add(8,9);
    s2.add(1,7);
    s2.add(10,9);

    cout << "\ns2: \n";
    cout << s2;    /* writes the s1*/
    
    size_stc = DayofYearSet::get_count();   /* returns the size of the all sets. */
    i = s2.size();  /* returns the size of the set. */
    cout << "\nSize of s2: " << i;
    cout << "\nSize of all sets: " << size_stc << endl;

    i = (s1 == s2);   /* I use overloaded operator == */
    cout << "\nAre two sets equal them each other? : (yes: 1, no:0)  " << i << endl;


    s3 = !(s1+s2);   /* I shows the De Morgan rule works. */
    s4 = !s1 ^ !s2;
    i = (s3 == s4);   /* I use overloaded operator == for checks the De Morgan is works or not. */
    cout << "\n\nThe result of De Morgan: " << i << endl;

    DayofYearSet s5, s6, s7, s8, s9;   /* create new DayofYearSet objects. */
    s5.add(12,3);   /* fill the s5 with add function. */
    s5.add(4,4);
    s5.add(6,7);
    s5.add(11,28);
    s5.add(6,17);
    s5.add(2,3);
    s5.add(11,8);
    i = s5.size();  /* returns the size of the set. */
    cout << "\ns5: \n";
    cout << s5;    /* writes the s5*/
    cout << "\nSize of s5: " << i << endl;
    s5.remove(2);   /* It removes index 2 int the s5 . */
    s5.remove(0);   /* It removes index 0 int the s5 . */
    i = s5.size();  /* returns the size of the set. */
    cout << "\ns5: \n";
    cout << s5;    /* writes the s5*/
    cout << "\nSize of s5: " << i << endl;

    s6 = (s1+s2);  /* I use overloaded operator + function. */
    i = s6.size();  /* returns the size of the set. */
    cout << "\ns6: \n";
    cout << s6;    /* writes the s6 */
    cout << "\nSize of s6: " << i << endl;
    
    i = (s5 != s6);   /* I use overloaded operator != for show s5 and s6 are different from each other. */
    cout << "\nAre two sets different them each other? : (yes: 0, no:1)  " << i << endl;

    cout << "\ns6: \n";
    cout << s6;    /* writes the s6 */
    cout << "\n\ns1: \n";
    cout << s1;    /* writes the s1 */
    i = (s1 != s6);   /* I use overloaded operator != for show s1 and s6 are different from each other. */
    cout << "\ns1 and s6 different them each other? : (yes: 0, no:1)  " << i << endl;

    s7 = (s6 - s1);   /* I use overloaded operator - function. */
    
    i = s7.size();  /* returns the size of the set. */
    cout << "\ns7: \n";
    cout << s7;    /* writes the s7 */
    cout << "\nSize of s7: " << i << endl;

    cout << "\ns5: \n";
    cout << s5;    /* writes the s5 */
    cout << "\n\ns6: \n";
    cout << s6;    /* writes the s6 */
    
    s8 = (s5 - s6);   /* I use overloaded operator - function. */

    i = s8.size();
    cout << "\n\ns8: \n";
    cout << s8;    /* writes the s8 */
    cout << "\nSize of s8: " << i << endl;

    s8.write_file();    /* writes the s8 int the file text.txt */

    s9 = (s5 ^ s6);   /* I use overloaded operator ^ function. */

    i = s9.size();  /* returns the size of the set. */
    cout << "\n\ns9: \n";
    cout << s9;   /* writes the s9 */
    cout << "\nSize of s9: " << i << endl;

    DayofYearSet::DayofYear d1, d2;      /* create new DayofYear object. */
    d1 = s8[1];      /* I use overloaded operator [] function.  */
    cout << "\nThe first index of the s8 is:";
    cout << "\nDay: " << d1.get_day() << "\tMonth: " << d1.get_month() << endl;

    d2 = s6[5];     /* I use overloaded operator [] function.  */
    cout << "\nThe fifth index of the s6 is:";
    cout << "\nDay: " << d2.get_day() << "\tMonth: " << d2.get_month() << endl;

    DayofYearSet::DayofYear d3, d4(9), d5(10,11);     /* create new DayofYear object. */

    cout << "\nNo paremeter constructure:\nDay: " << d3.get_day() << "\tMonth: " << d3.get_month() << endl;
    cout << "\nOne paremeter constructure:\nDay: " << d4.get_day() << "\tMonth: " << d4.get_month() << endl;
    cout << "\nTwo paremeter constructure:\nDay: " << d5.get_day() << "\tMonth: " << d5.get_month() << endl;

    DayofYearSet s10, s11;   /* create new DayofYearSet objects. */

    /* I shows what happen if the user input invalid values int the set. */
    cout << "\n\nDo you want to see the what happen if the inputs are invalid?: (yes:1, no:0)  ";
    cin >> i;
    if(i == 1){
        s10.add(12,3);
        s10.add(4,44);
        s10.add(6,7);
    }
}