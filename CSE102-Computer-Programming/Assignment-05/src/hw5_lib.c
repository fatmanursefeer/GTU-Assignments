/*
** hw5_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.04.02.23.55
** 
*/

#include <stdio.h>
#include <math.h>
#include "hw5_lib.h"


void operate_polynomials  (double* a3, double* a2, double* a1, double* a0, double* b3, double* b2, double* b1, double* b0, char op)
{
/* Here I created temporary variables to assing values. */
	double c6, c5, c4, c3, c2, c1, c0;
/*I created if-else if- else blocks to perform operations according to the transection operator entered. */
	if(op == '+'){
		c3 = (*a3)+(*b3);
		c2 = (*a2)+(*b2);
		c1 = (*a1)+(*b1);
		c0 = (*a0)+(*b0);
	/* I assinged the values in c's to pointer so that the values could go to the main function. */
		*a3 = c3; 
		*a2 = c2;
		*a1 = c1;
		*a0 = c0;
	}
	else if(op == '-'){
		c3 = (*a3)-(*b3);
		c2 = (*a2)-(*b2);
		c1 = (*a1)-(*b1);
		c0 = (*a0)-(*b0);
		*a3 = c3;
		*a2 = c2;
		*a1 = c1;
		*a0 = c0;
	}
	else if(op == '*'){
		c6 = (*a3)*(*b3);
		c5 = (((*a3)*(*b2))+((*b3)*(*a2)));
		c4 = (((*a3)*(*b1))+((*b3)*(*a1))+((*a2)*(*b2)));
		c3 = (((*a3)*(*b0))+((*b3)*(*a0))+((*a2)*(*b1))+((*b2)*(*a1)));
		c2 = (((*a2)*(*b0))+((*b2)*(*a0))+((*a1)*(*b1)));
		c1 = (((*a1)*(*b0))+((*b1)*(*a0)));
		c0 = (*a0)*(*b0);
		*a3 = c6;
		*a2 = c5;
		*a1 = c4;
		*a0 = c3;
		*b3 = c2;
		*b2 = c1;
		*b1 = c0;
	}
/*If something different enters the operator than excepted, it will print an error message. */
	else
		printf("You entered wrong operator sing.\n"); 
}


void four_d_vectors (double* mean_a0, double* mean_a1, double* mean_a2, double* mean_a3, double* longest_distance, int N)
{
/* Here I created temporary variables to assing values. */
	double d0, d1, d2, d3, a0, a1, a2, a3, euclidian_distance=0.0;
	double sum0, sum1, sum2, sum3;
	int temp, i=1;
/* I received the first values seperately. */
	printf("Enter 4D vektor: ");
	scanf("%lf %lf %lf %lf", &d0, &d1, &d2, &d3);
/*Since I will use the sum values in the loop, I made the initial sum values equal to the first values I got. */
	sum0 = d0;
	sum1 = d1;
	sum2 = d2;
	sum3 = d3;
	temp = N-1;
	while(1){
	/*I have created an infinite loop and keep it running until it reaches the desired amount. */
		printf("Enter 4D vektor: ");
		scanf("%lf %lf %lf %lf", &a0, &a1, &a2, &a3);
		temp--;
	/*After the last vector, I made the loop end when user input these values to finish. */
		if((a0 == -1.0) && (a1 == -1.0) && (a2 == -1.0) && (a3 == -1.0))
			break;
	/*I summed each entered value with its total amount to calculate the mean. */
		sum0 = sum0 + a0;
		sum1 = sum1 + a1;
		sum2 = sum2 + a2;
		sum3 = sum3 + a3;
	/*I calculate the difference of the values to send it to the function.*/
		d0 = d0-a0;
		d1 = d1-a1;
		d2 = d2-a2;
		d3 = d3-a3;
	/*I send the numbers that I calculate the differences of to the function as parameters. */
		distance_between_4d_points (d0, d1, d2, d3, &euclidian_distance);
		if(temp < 1)
			break;
	/*Since we calculate between consecutive numbers, I equated the first entered values to d's, and thus I can calculate between the newly entered numbers and the previous numbers. */
		d0 = a0;
		d1 = a1;
		d2 = a2;
		d3 = a3;
		i++;
	}
/*Here if the user writes -1 -1 -1 -1 without coming to the N number, then I have done the average and max length numbers operations seperately. */
	if((a0 == -1.0) && (a1 == -1.0) && (a2 == -1.0) && (a3 == -1.0)){
		*longest_distance = euclidian_distance;
		*mean_a0 = sum0/(double)i;
		*mean_a1 = sum1/(double)i;
		*mean_a2 = sum2/(double)i;
		*mean_a3 = sum3/(double)i;
	}
/*Finally, I calculated the average values and the maximum distance and sent these values to the main function via a pointer. */
	else{
		*longest_distance = euclidian_distance;
		*mean_a0 = sum0/(double)N;
		*mean_a1 = sum1/(double)N;
		*mean_a2 = sum2/(double)N;
		*mean_a3 = sum3/(double)N;
	}
}


void distance_between_4d_points (double d0, double d1, double d2, double d3, double* euclidian_distance)
{
	double temp_distance;
/*Here I calculated the length using the values I found the differences. */
	temp_distance = sqrt((d0*d0)+(d1*d1)+(d2*d2)+(d3*d3));
/*I created an if block to find the maximum distance. */
	if(temp_distance > *euclidian_distance)
		*euclidian_distance = temp_distance;
/*I sent these max distance to the upper function via a pointer. */
}


void dhondt_method (int* partyA, int* partyB, int* partyC, int* partyD, int* partyE, int numberOfSeats)
{
/* I did not get a value from the user because it was defined in the main function and equalized to the value. */
/* Here I created temporary variables to assing values. */
	int a=1, b=1, c=1, d=1, e=1;
	int prtyA, prtyB, prtyC, prtyD, prtyE;
	int aV=0, bV=0, cV=0, dV=0, eV=0;
/*I have assigned them to temporary values to use the values in the pointers. */
	prtyA = *partyA;
	prtyB = *partyB;
	prtyC = *partyC;
	prtyD = *partyD;
	prtyE = *partyE;
/*I created a loop that will keep spinning until the seat runs out.*/
	while(numberOfSeats > 0){
	/*If the number of votes is equal, my priority will be A=-B-C-D-E */
		if((prtyA >= prtyB) && (prtyA >= prtyC) && (prtyA >= prtyD) && (prtyA >= prtyE)){
			a++;
			aV++;
			prtyA = (*partyA)/a;
		}
		else if((prtyB > prtyA) && (prtyB >= prtyC) && (prtyB >= prtyD) && (prtyB >= prtyE)){
			b++;
			bV++;
			prtyB = (*partyB)/b;
		}
		else if((prtyC > prtyA) && (prtyC > prtyB) && (prtyC >= prtyD) && (prtyC >= prtyE)){
			c++;
			cV++;
			prtyC = (*partyC)/c;
		}
		else if((prtyD > prtyA) && (prtyD > prtyB) && (prtyD > prtyC) && (prtyD >= prtyE)){
			d++;
			dV++;
			prtyD = (*partyD)/d;
		}
		else if((prtyE > prtyA) && (prtyE > prtyB) && (prtyE > prtyC) && (prtyE > prtyD)){
			e++;
			eV++;
			prtyE = (*partyE)/e;
		}
		numberOfSeats--;
	}
/*I have synchronized the amounts of seats gained as a result of the operations done to the pointers and thus sent them to the main funcion. */
	*partyA = aV;
	*partyB = bV;
	*partyC = cV;
	*partyD = dV;
	*partyE = eV;
}


void order_2d_points_cc (double* x1, double* y1, double* x2, double* y2, double* x3, double* y3)
{
	/* I could not do this part. */
}


void number_encrypt (unsigned char* number)
{
/* I did not get a value from the user because it was defined in the main function and equalized to the value. */
/*Here I called the functions in order as excepted from us. */
	char b7='0', b6='0', b5='0', b4='0', b3='0', b2='0', b1='0', b0='0';
	get_number_components (*number, &b7, &b6, &b5, &b4, &b3, &b2, &b1, &b0);
	reconstruct_components (number, b7, b6, b5, b4, b3, b2, b1, b0);
}


void get_number_components (unsigned char number, char* b7, char* b6, char* b5, char* b4, char* b3, char* b2, char* b1, char* b0)
{
/*I made individual value assignments until the number equals 0 */
	if(number != 0){
		if(number%2 == 1)
			*b0 = '1';
		else
			*b0 = '0';
		number = number/2;  /*And after each assignment I divided the number in half. */
	}
	if(number != 0){
		if(number%2 == 1)
			*b1 = '1';
		else
			*b1 = '0';
		number = number/2;
	}
	if(number != 0){
		if(number%2 == 1)
			*b2 = '1';
		else
			*b2 = '0';
		number = number/2;
	}
	if(number != 0){
		if(number%2 == 1)
			*b3 = '1';
		else
			*b3 = '0';
		number = number/2;
	}
	if(number != 0){
		if(number%2 == 1)
			*b4 = '1';
		else
			*b4 = '0';
		number = number/2;
	}
	if(number != 0){
		if(number%2 == 1)
			*b5 = '1';
		else
			*b5 = '0';
		number = number/2;
	}
	if(number != 0){
		if(number%2 == 1)
			*b6 = '1';
		else
			*b6 = '0';
		number = number/2;
	}
	if(number != 0){
		if(number%2 == 1)
			*b7 = '1';
		else
			*b7 = '0';
	}
}


void reconstruct_components (unsigned char* number, char b7, char b6, char b5, char b4, char b3, char b2, char b1, char b0)
{
/*I created the necessary variables to use in this function. */
	char a0, a1, a2, a3, a4, a5, a6, a7;
	int sum = 0;
/*I changed a value using variables a's as shown in PDF. */
	a0 = b2;
	b2 = b7;
	b7 = a0;
	a1 = b3;
	b3 = b6;
	b6 = a1;
	a2 = b0;
	b0 = b5;
	b5 = a2;
	a3 = b1;
	b1 = b4;
	b4 = a3;
/*I used all variables a's to shift left the values after making the replacements and assign them one by one. */
	a0 = b6;
	a1 = b7;
	a2 = b0;
	a3 = b1;
	a4 = b2;
	a5 = b3;
	a6 = b4;
	a7 = b5;
/*And I found the value of the number formed by doing mathematical operations according to their place in binary. */
	if(a0 == '0')
		sum = sum + 0; /* (0*2^0) */
	else
		sum = sum + 1; /* (1*2^0) */
	if(a1 == '0')
		sum = sum + 0; /* (0*2^1) */
	else
		sum = sum + 2; /* (1*2^1) */
	if(a2 == '0')
		sum = sum + 0; /* (0*2^2) */
	else
		sum = sum + 4; /* (1*2^2) */
	if(a3 == '0')
		sum = sum + 0; /* (0*2^3) */
	else
		sum = sum + 8; /* (1*2^3) */
	if(a4 == '0')
		sum = sum + 0; /* (0*2^4) */
	else
		sum = sum + 16; /* (1*2^4) */
	if(a5 == '0')
		sum = sum + 0; /* (0*2^5) */
	else
		sum = sum + 32; /* (1*2^5) */
	if(a6 == '0')
		sum = sum + 0; /* (0*2^6) */
	else
		sum = sum + 64; /* (1*2^6) */
	if(a7 == '0')
		sum = sum + 0; /* (0*2^7) */
	else
		sum = sum + 128; /* (1*2^7) */
	*number = sum;
}
