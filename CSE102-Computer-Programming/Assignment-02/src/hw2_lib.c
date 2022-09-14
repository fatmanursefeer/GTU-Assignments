/*
** hw2_lib.c:
**
** The source file implementing library functions.
**
*/

#include <stdio.h>
#include <math.h>
#include "hw2_lib.h"


int find_weekday_of_data(int day, int month, int year)
{
/* We found that the date entered in this function corresponds to the number of days of the week. */
    
    int val1, val2, val3;
/* I printed an error message against the incorrect values entered here. */
    if((day<1) || (day>31))
    	printf("You entered wrong number.");
    if((month<1) || (month>12))
    	printf("You entered wrong number.");
    if(year<1)
    	printf("You entered wrong number");
/* --------------------------------------------------- */
    if(month == 1){
    	month = 13;
    	year--;
    }
    if(month == 2){
    	month = 14;
    	year--;
    }

/* I synchronized the val1 variable to the value in the last two digits of the year entered. */
    
    val1 = year % 100;

/* I synchronized the val2 variable to the value in the first two digits of the year entered. */
    
    val2 = year / 100;

/* I applied the algorithm and synchronized the resulting value to val3 and found out what day of the week the date entered corresponds to the result. */
    
    val3 = day + 13 * (month+1) / 5 + val1 + val1 / 4 + val2 / 4 + 5 * val2;
    val3 = val3 % 7;
    if(val3 == 0)
    	val3 = 6;
    else
    	val3--;
    return val3;
}


int count_day_between_dates(int start_day, int start_month, int start_year, int end_day, int end_month, int end_year)
{
/* Here I calculated the difference in days between the two dates entered. */
    
    int val1, val2, val3;
/* I printed an error message against the incorrect values entered here. */
    if((start_day<1) || (start_day>31))
    	printf("You entered wrong number.");
    if((end_day<1) || (end_day>31))
    	printf("You entered wrong number.");
    if((start_month<1) || (start_month>12))
    	printf("You entered wrong number.");
    if((end_month<1) || (end_month>12))
    	printf("You entered wrong number.");
    if((start_year<1) || (end_year<1))
    	printf("You entered wrong number");
/* --------------------------------------------------- */
    if(start_month <= 2){
    	start_year--;
    	start_month = start_month + 13;
    }
    else
    	start_month++;

/* I applied the algorithm to the start date. */
    
    val1 = 1461 * start_year / 4 + 153 * start_month / 5 + start_day;
    
    if(end_month <= 2){
    	end_year--;
    	end_month = end_month + 13;
    }
    else
    	end_month++;
    
/* I applied the algorithm to the end date. */
    
    val2 = 1461 * end_year / 4 + 153 * end_month / 5 + end_day;
    
    val3 = val2 - val1;
    return val3;
}


double find_angle(double a, double b, double c)
{
/* I applied the edge theorem and cosinus theorem to find the agle. */

    double vb, vc, val, radyan, derece;
/* I printed an error message against the incorrect values entered here. */    
    if((a<=0) || (b<=0) || (c<=0))
    	printf("You entered wrong number.");
/* --------------------------------------------------- */    
/* I only used the math.h library to calculate the square root of the result and calculate the cos result. */

    vb = sqrt(((a*a)/2) + ((c*c)/2) - ((b*b)/4));
    vb = (vb/3)*2;
    vc = sqrt(((b*b)/2) + ((a*a)/2) - ((c*c)/4));
    vc = (vc/3)*2;
    val = ((vb*vb) + (vc*vc) - (a*a)) / (2*vb*vc);
    radyan = acos(val);
    return radyan;
}


void print_tabulated(unsigned int r11, double r12, int r13, 
                     unsigned int r21, double r22, int r23, 
                     unsigned int r31, double r32, int r33, char border)
{
	int i;

/* Here I made the if - else if - else condition to make a table that changes depending on the user's choice. */
	if(border == '*'){
		printf("┌");
/* Here I looped and printed so as not to write '*' one by one. */		
		for(i=0; i<111; i++)
			printf("*");
		printf("┐\n|\t\t");
/* Here I printed the names of the rows. */
		printf("Row 101\t\t");
		printf("|\t\tRow ABCDEFG\t\t");
		printf("|\t\tRow XYZ123\t\t|\n");
		for(i=0; i<113; i++)
			printf("*");
/* Here I printed the values that correspond to the rows and columns one by one. */
		if(r11 < 10)
			printf("\n|\t\t%u\t\t", r11);
		else if(r11 < 100)
			printf("\n|   \t\t%u\t\t", r11);
		else if(r11 < 1000)
			printf("\n|  \t\t%u\t\t", r11);
		else if(r11 < 10000)
			printf("\n| \t\t%u\t\t", r11);
		else if(r11 < 100000)
			printf("\n|\t\t%u\t\t", r11);
		else
			printf("You entered invalid number.");
/* --------------------------------------------------------------------------------------------------------	
** I could not do the part where I did not print the next 0s after the comma in the Row ABCDEFG column
** but if the part after the comma is grater than 2 digits , it can successfully round.
** --------------------------------------------------------------------------------------------------------*/	
		printf("|%.2f\t\t\t\t\t", r12);
/* I have stipulated that the number entered here, along with the sing, should not exceed 6 digit. */
		if((r13 > -100000) || ((r13 < 100000)&&(r13 > -100000))){
/* Here I put it under the condition if - else print the sings in case the number is positive or negative. */
			if(r13 > 0)
				printf("|+%d\t\t\t\t\t|\n", r13);
			else
				printf("|%d\t\t\t\t\t|\n", r13);
		}
		else
			printf("You entered invalid number.");
		for(i=0; i<113; i++)
			printf("*");
		if(r21 < 10)
			printf("\n|\t\t%u\t\t", r21);
		else if(r21 < 100)
			printf("\n|   \t\t%u\t\t", r21);
		else if(r21 < 1000)
			printf("\n|  \t\t%u\t\t", r21);
		else if(r21 < 10000)
			printf("\n| \t\t%u\t\t", r21);
		else if(r21 < 100000)
			printf("\n|\t\t%u\t\t", r21);
		else
			printf("You entered invalid number.");
		printf("|%.2f\t\t\t\t\t", r22);
		if((r23 > -100000) || ((r23 < 100000)&&(r23 > -100000))){
			if(r23 > 0)
				printf("|+%d\t\t\t\t\t|\n", r23);
			else
				printf("|%d\t\t\t\t\t|\n", r23);
		}
		else
			printf("You entered invalid number.");
		for(i=0; i<113; i++)
			printf("*");
		if(r31 < 10)
			printf("\n|\t\t%u\t\t", r31);
		else if(r31 < 100)
			printf("\n|   \t\t%u\t\t", r31);
		else if(r31 < 1000)
			printf("\n|  \t\t%u\t\t", r31);
		else if(r31 < 10000)
			printf("\n| \t\t%u\t\t", r31);
		else if(r31 < 100000)
			printf("\n|\t\t%u\t\t", r31);
		else
			printf("You entered invalid number.");
		printf("|%.2f\t\t\t\t\t", r32);
		if((r33 > -100000) || ((r33 < 100000)&&(r33 > -100000))){
			if(r33 > 0)
				printf("|+%d\t\t\t\t\t|\n", r33);
			else
				printf("|%d\t\t\t\t\t|\n", r33);
		}
		else
			printf("You entered invalid number.");
		printf("└");
		for(i=0; i<111; i++)
			printf("*");
		printf("┘\n");
	}
/* Here I looped and printed so as not to write '-' one by one. */
	else if(border == '-'){
		printf("┌");
		for(i=0; i<111; i++)
			printf("-");
		printf("┐\n|\t\t");
/* Here I printed the names of the rows. */
		printf("Row 101\t\t");
		printf("|\t\tRow ABCDEFG\t\t");
		printf("|\t\tRow XYZ123\t\t|\n");
		for(i=0; i<113; i++)
			printf("-");
/* Here I printed the values that correspond to the rows and columns one by one. */
		if(r11 < 10)
			printf("\n|\t\t%u\t\t", r11);
		else if(r11 < 100)
			printf("\n|   \t\t%u\t\t", r11);
		else if(r11 < 1000)
			printf("\n|  \t\t%u\t\t", r11);
		else if(r11 < 10000)
			printf("\n| \t\t%u\t\t", r11);
		else if(r11 < 100000)
			printf("\n|\t\t%u\t\t", r11);
		else
			printf("You entered invalid number.");
		printf("|%.2f\t\t\t\t\t", r12);
/* I have stipulated that the number entered here, along with the sing, should not exceed 6 digit. */
		if((r13 > -100000) || ((r13 < 100000)&&(r13 > -100000))){
/* Here I put it under the condition if - else print the sings in case the number is positive or negative. */
			if(r13 > 0)
				printf("|+%d\t\t\t\t\t|\n", r13);
			else
				printf("|%d\t\t\t\t\t|\n", r13);
		}
		else
			printf("You entered invalid number.");
		for(i=0; i<113; i++)
			printf("-");
		if(r21 < 10)
			printf("\n|\t\t%u\t\t", r21);
		else if(r21 < 100)
			printf("\n|   \t\t%u\t\t", r21);
		else if(r21 < 1000)
			printf("\n|  \t\t%u\t\t", r21);
		else if(r21 < 10000)
			printf("\n| \t\t%u\t\t", r21);
		else if(r21 < 100000)
			printf("\n|\t\t%u\t\t", r21);
		else
			printf("You entered invalid number.");
		printf("|%.2f\t\t\t\t\t", r22);
		if((r23 > -100000) || ((r23 < 100000)&&(r23 > -100000))){
			if(r23 > 0)
				printf("|+%d\t\t\t\t\t|\n", r23);
			else
				printf("|%d\t\t\t\t\t|\n", r23);
		}
		else
			printf("You entered invalid number.");
		for(i=0; i<113; i++)
			printf("-");
		if(r31 < 10)
			printf("\n|\t\t%u\t\t", r31);
		else if(r31 < 100)
			printf("\n|   \t\t%u\t\t", r31);
		else if(r31 < 1000)
			printf("\n|  \t\t%u\t\t", r31);
		else if(r31 < 10000)
			printf("\n| \t\t%u\t\t", r31);
		else if(r31 < 100000)
			printf("\n|\t\t%u\t\t", r31);
		else
			printf("You entered invalid number.");
		printf("|%.2f\t\t\t\t\t", r32);
		if((r33 > -100000) || ((r33 < 100000)&&(r33 > -100000))){
			if(r33 > 0)
				printf("|+%d\t\t\t\t\t|\n", r33);
			else
				printf("|%d\t\t\t\t\t|\n", r33);
		}
		else
			printf("You entered invalid number.");
		printf("└");
		for(i=0; i<111; i++)
			printf("-");
		printf("┘\n");
	}
}
