/*
** hw4_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.03.03.20.16
** 
*/

#include <stdio.h>
#include <math.h>
#include "hw1_lib.h"

double func3(double a0, double a1, double a2, double a3, double x)
{
/* Here we calculated the fuction values of third-degree polynomials. */
    int i;
    double arr[4], sum;
    arr[0] = a0;
    arr[1] = a1;
    arr[2] = a2;
    arr[3] = a3;
    sum = arr[0];
    for(i=1; i<=3; i++)
        sum = (sum * x) + arr[i];
    return sum;
}

double func4(double a0, double a1, double a2, double a3, double a4, double x)
{
/* Here we calculated the fuction values of fourth-degree polynomials. */
    int i;
    double arr[5], sum;
    arr[0] = a0;
    arr[1] = a1;
    arr[2] = a2;
    arr[3] = a3;
    arr[4] = a4;
    sum = arr[0];
    for(i=1; i<=4; i++)
        sum = (sum * x) + arr[i];
    return sum;
}

double integral3(double a0, double a1, double a2, double a3, double xs, double xe, double delta)
{
/* Here I have calculated the approximate value of the integral using the trapezoidal rule. */
    int i, n;
    double val, temp, sum=0;
    n = fabs(xe-xs)/delta;
    for(i=1; i<n; i++)
    {
    	temp = xs+i*delta;
    	sum = sum + func3(a0, a1, a2, a3, temp);
    }
    val = (delta/2)*(func3(a0, a1, a2, a3, xs) + func3(a0, a1, a2, a3, xe) + 2 * sum);
    return val;
}


double integral4(double a0, double a1, double a2, double a3, double a4, double xs, double xe, double delta)
{
/* Here I have calculated the approximate value of the integral using the trapezoidal rule. */
    int i, n;
    double val, temp, sum=0;
    n = fabs(xe-xs)/delta;
    for(i=1; i<n; i++)
    {
    	temp = xs+i*delta;
    	sum = sum + func4(a0, a1, a2, a3, a4, temp);
    }
    val = (delta/2)*(func4(a0, a1, a2, a3, a4, xs) + func4(a0, a1, a2, a3, a4, xe) + 2 * sum);
    return val;
}


double root3(double a0, double a1, double a2, double a3, double xs, double xe)
{
/* I gave the margin of error 0.0001 */
    double val, err=0.0001;
    val = xs;
    while((xe-xs) >= err)
    {
    	val = (xs+xe)/2;
    	if(func3(a0, a1, a2, a3, val) == 0.0)
    		return val;
    	else if(func3(a0, a1, a2, a3, val) * func3(a0, a1, a2, a3, xs) < 0)
    		xe = val;
    	else
    		xs = val;
    }
}


double root4(double a0, double a1, double a2, double a3, double a4, double xs, double xe)
{
/* I gave the margin of error 0.0001 */
    double val, err=0.0001;
    val = xs;
    while((xe-xs) >= err)
    {
    	val = (xs+xe)/2;
    	if(func4(a0, a1, a2, a3, a4, val) == 0.0)
    		return val;
    	else if(func4(a0, a1, a2, a3, a4, val) * func4(a0, a1, a2, a3, a4, xs) < 0)
    		xe = val;
    	else
    		xs = val;
    }
}
