/*
** hw1_io.c:
**
** The source file implementing output functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.03.03.20.16
** 
*/


#include <stdio.h>
#include <math.h>
#include "hw1_io.h"


void write_polynomial3(double a0, double a1, double a2, double a3)
{
/* Here I did the operations for the first coefficient. */
    if(a0 > 0)
    {
    	if(a0 == 1)
    		printf("x^3");
    	else
    		printf("%.1fx^3", fabs(a0));
    }
    else if(a0 < 0)
    {
        printf("-");
    	if(a0 == 1)
    		printf("x^3");
    	else
    		printf("%.1fx^3", fabs(a0));
    }
/* Here I did the operations for the second coefficient. */ 
    if(a1 > 0)
    {
    	printf("+");
    	if(a1 == 1)
    		printf("x^2");
    	else
    		printf("%.1fx^2", fabs(a1));
    }
    else if(a1 < 0)
    {
        printf("-");
    	if(a1 == 1)
    		printf("x^2");
    	else
    		printf("%.1fx^2", fabs(a1));
    }
/* Here I did the operations for the third coefficient. */
    if(a2 > 0)
    {
    	printf("+");
    	if(a2 == 1)
    		printf("x");
    	else
    		printf("%.1fx", fabs(a2));
    }
    else if(a2 < 0)
    {
        printf("-");
    	if(a2 == 1)
    		printf("x");
    	else
    		printf("%.1fx", fabs(a2));
    }
/* Here I did the operations for the fourth coefficient. */
    if(a3 > 0)
    {
    	printf("+");
    	if(a3 == 1)
    		printf("1");
    	else
    		printf("%.1f", fabs(a3));
    }
    else if(a3 < 0)
    {
        printf("-");
    	if(a3 == 1)
    		printf("1");
    	else
    		printf("%.1f", fabs(a3));
    }
}

void write_polynomial4(double a0, double a1, double a2, double a3, double a4)
{
/* Here I did the operations for the first coefficient. */
    if(a0 > 0)
    {
    	if(a0 == 1)
    		printf("x^4");
    	else
    		printf("%.1fx^4", fabs(a0));
    }
    else if(a0 < 0)
    {
        printf("-");
    	if(a0 == 1)
    		printf("x^4");
    	else
    		printf("%.1fx^4", fabs(a0));
    }
/* Here I did the operations for the second coefficient. */
    if(a1 > 0)
    {
    	printf("+");
    	if(a1 == 1)
    		printf("x^3");
    	else
    		printf("%.1fx^3", fabs(a1));
    }
    else if(a1 < 0)
    {
        printf("-");
    	if(a1 == 1)
    		printf("x^3");
    	else
    		printf("%.1fx^3", fabs(a1));
    }
/* Here I did the operations for the third coefficient. */
    if(a2 > 0)
    {
    	printf("+");
    	if(a2 == 1)
    		printf("x^2");
    	else
    		printf("%.1fx^2", fabs(a2));
    }
    else if(a2 < 0)
    {
        printf("-");
    	if(a2 == 1)
    		printf("x^2");
    	else
    		printf("%.1fx^2", fabs(a2));
    }
/* Here I did the operations for the fourth coefficient. */
    if(a3 > 0)
    {
    	printf("+");
    	if(a3 == 1)
    		printf("x");
    	else
    		printf("%.1fx", fabs(a3));
    }
    else if(a3 < 0)
    {
        printf("-");
    	if(a3 == 1)
    		printf("x");
    	else
    		printf("%.1fx", fabs(a3));
    }
/* Here I did the operations for the fifth coefficient. */
    if(a4 > 0)
    {
    	printf("+");
    	if(a4 == 1)
    		printf("1");
    	else
    		printf("%.1f", fabs(a4));
    }
    else if(a4 < 0)
    {
        printf("-");
    	if(a4 == 1)
    		printf("1");
    	else
    		printf("%.1f", fabs(a4));
    }
}
