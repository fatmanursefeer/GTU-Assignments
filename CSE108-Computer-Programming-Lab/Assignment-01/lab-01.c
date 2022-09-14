/* 
First lab homework
*/

#include <stdio.h>

double trigonometry_calculation(int a, int b, int c)
{
    double sinx, cosx, tanx;
    sinx = a/c;
    cosx = b/c;
    tanx = a/b;
    printf("sinx: %.1lf/ncosx: %.1lf/ntanx: %.2lf);
    return sinx, cosx, tanx;
}

void age(int x)
{
    printf("Your age: %d", x);
}


double age_calculation(int x)
{
    int day;
    double hour, minute, second;
    day = x * 365;
    hour = day * 24;
    minute = hour * 60;
    second = minute * 60
    return second;
}


int main()
{
    int a, b, c, yas, x;
    x = double trigonometry_calculation;
    double second;
    scanf("%d", &yas);
    age(yas);
    second = age_calculation(yas);
    printf("Your are %lf second", second);
    
    return 0;
}
