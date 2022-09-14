/*
** main.c:
**
** The test/driver program for the homework.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.04.02.23.55
** 
*/


#include <stdio.h>
#include "hw5_lib.h"


void test_operate_polynomials () 
{
/* Here I created temporary variables to assing values. */
	char op, temp;
	double c3, c2, c1, c0, d3, d2, d1, d0;
	double a3, a2, a1, a0, b3, b2, b1, b0;
	int k3, k2, k1, k0, l3, l2, l1, l0;
/*I took the values one by one and sent these values to the function for the realization of the operations. */
	printf("Enter '-' to substract, '+' to addition, '*' to multiply: ");
	scanf("%c", &op);
	temp = getchar();
	printf("Enter first polynomials coefficients: (like (n1,k1),(n2,k2),(n3,k3),(n4,k4)) \n");
	scanf("(%d,%lf),(%d,%lf),(%d,%lf),(%d,%lf)", &k3, &c3, &k2, &c2, &k1, &c1, &k0, &c0);
	temp = getchar();
/*I make these equalizations and if-else blocks considering the possibility of the user entering coefficients out of order. */
	if(k3 == 3)
		a3 = c3;
	else if(k3 == 2)
		a2 = c3;
	else if(k3 == 1)
		a1 = c3;
	else if(k3 == 0)
		a0 = c3;
	if(k2 == 3)
		a3 = c2;
	else if(k2 == 2)
		a2 = c2;
	else if(k2 == 1)
		a1 = c2;
	else if(k2 == 0)
		a0 = c2;
	if(k1 == 3)
		a3 = c1;
	else if(k1 == 2)
		a2 = c1;
	else if(k1 == 1)
		a1 = c1;
	else if(k1 == 0)
		a0 = c1;
	if(k0 == 3)
		a3 = c0;
	else if(k0 == 2)
		a2 = c0;
	else if(k0 == 1)
		a1 = c0;
	else if(k0 == 0)
		a0 = c0;
	printf("Enter second polynomials coefficients: (like (n1,k1),(n2,k2),(n3,k3),(n4,k4)) \n");
	scanf("(%d,%lf),(%d,%lf),(%d,%lf),(%d,%lf)", &l3, &d3, &l2, &d2, &l1, &d1, &l0, &d0);
	temp = getchar();
	if(l3 == 3)
		b3 = d3;
	else if(l3 == 2)
		b2 = d3;
	else if(l3 == 1)
		b1 = d3;
	else if(l3 == 0)
		b0 = d3;
	if(l2 == 3)
		b3 = d2;
	else if(l2 == 2)
		b2 = d2;
	else if(l2 == 1)
		b1 = d2;
	else if(l2 == 0)
		b0 = d2;
	if(l1 == 3)
		b3 = d1;
	else if(l1 == 2)
		b2 = d1;
	else if(l1 == 1)
		b1 = d1;
	else if(l1 == 0)
		b0 = d1;
	if(l0 == 3)
		b3 = d0;
	else if(l0 == 2)
		b2 = d0;
	else if(l0 == 1)
		b1 = d0;
	else if(l0 == 0)
		b0 = d0;
	operate_polynomials(&a3, &a2, &a1, &a0, &b3, &b2, &b1, &b0, op);	
/*I printed the coefficients calculated according to the way the operations were done in two different ways. */
	if((op == '+') || (op == '-'))
/*First coefficients => (3,k), Second coefficient => (2,k), Third coefficient => (1,k), Fourth coefficient => (0,k) */
		printf("First coefficient: %f\nSecond coefficient: %f\nThird coefficient: %f\nFourth coefficient: %f\n", a3, a2, a1, a0);
	else if(op == '*'){
		printf("First coefficient: %f\nSecond coefficient: %f\nThird coefficient: %f\nFourth coefficient: %f\nFifth coefficient: %f\nSixth coefficient: %f\nSeventh coefficient: %f\n", a3, a2, a1, a0, b3, b2, b1);
	}
}


void test_four_d_vectors ()
{
	double mean_a0=0.0, mean_a1=0.0, mean_a2=0.0, mean_a3=0.0, longest_distance=0.0;
	int N=5;
	four_d_vectors (&mean_a0, &mean_a1, &mean_a2, &mean_a3, &longest_distance, N);
	printf("Mean a0: %f\nMean a1: %f\nMean a2: %f\nMean a3: %f\nThe longest distance between two points: %f\n\n\n", mean_a0, mean_a1, mean_a2, mean_a3, longest_distance);
}


void test_dhondt_method ()
{
	int partyA=0, partyB=0, partyC=0, partyD=0, partyE=0, numberOfSeats=0;
	dhondt_method (&partyA, &partyB, &partyC, &partyD, &partyE, numberOfSeats);
	printf("Party A: %d seat(s).\nParty B: %d seat(s).\nParty C: %d seat(s).\nParty D: %d seat(s).\nParty E: %d seat(s).\n\n\n", partyA, partyB, partyC, partyD, partyE);
}


void test_order_2d_points_cc ()
{
	double x1=0.0, y1=0.0, x2=0.0, y2=0.0, x3=0.0, y3=0.0;
	order_2d_points_cc (&x1, &y1, &x2, &y2, &x3, &y3);
	printf("Counter-Clockwise Order: (%f,%f) - (%f,%f) - (%f,%f)\n\n\n", x1, y1, x2, y2, x3, y3);
}


void test_number_encrypt ()
{
	unsigned char number=0;
	number_encrypt (&number);
	printf("Encrypted number: %d\n\n\n", number);
}


/*
** main function for testing the functions...
**
*/
int main(void) {
	test_operate_polynomials ();
	test_four_d_vectors ();
	test_dhondt_method ();
	test_order_2d_points_cc ();
	test_number_encrypt ();
	return (0);
} /* end main */
