#include <stdio.h>

void russian_multiplication(unsigned int *multiplicant, unsigned int *multiplier){
/*Here I multiplied two numbers using the russian method. */
	unsigned int sum=0;
	while(*multiplier > 0){ /*Here I wanted the loop contuinue until the multiplier less than 0 */
		if(*multiplier%2 != 0) /* I wanted the it collect as long as no pairs left. */
			sum = sum + *multiplicant;
		*multiplicant *= 2; /*I multiply 2 to multiplicant. */
		*multiplier /= 2; /*I divide 2 to multiplier. */
	}
	*multiplicant = sum;
}


void multiply_polynomials(double *a3, double *a2, double *a1, double *a0, double *b3, double *b2, double *b1, double b0){
	double c6, c5, c4, c3, c2, c1, c0;
	c6 = ((*a3) * (*b3));
	c5 = (((*a3)*(*b2)) + ((*b3)*(*a2)));
	c4 = (((*a3)*(*b1)) + ((*b3)*(*a1)) + ((*a2)*(*b2)));
	c3 = (((*a3)*(b0)) + ((*b3)*(*a0)) + ((*a2)*(*b1)) + ((*b2)*(*a1)));
	c2 = (((*a2)*(b0)) + ((*b2)*(*a0)) + ((*a1)*(*b1)));
	c1 = (((*a1)*(b0)) + ((*b1)*(*a0)));
	c0 = ((*a0)*(b0));
	c6 = *a3;
	c5 = *a2;
	c4 = *a1;
	c3 = *a0;
	c2 = *b3;
	c1 = *b2;
	c0 = *b1;
}



int main(){
/*I did the operations of getting values from the user and printing the values in the main function. */
	unsigned int multiplicant, multiplier;
	double a3, a2, a1, a0, b3, b2, b1, b0;
	printf("Enter first number: ");
	scanf("%u", &multiplicant);
	printf("Enter second number: ");
	scanf("%u", &multiplier);
	russian_multiplication(&multiplicant, &multiplier);
	printf("%u\n%u\n", multiplicant, multiplier+1);
	printf("Enter (a3, a2, a1, a0); ");
	scanf("%lf %lf %lf %lf", &a3, &a2, &a1, &a0);
	printf("Enter (b3, b2, b1, b0); ");
	scanf("%lf %lf %lf %lf", &b3, &b2, &b1, &b0);
	multiply_polynomials(&a3, &a2, &a1, &a0, &b3, &b2, &b1, b0);
	if(a3 > 0)
		printf("%.1lfx^6", a3);
	else
		printf("-%.1lfx^6", a3);
	if(a2 > 0)
		printf("+%.1lfx^5", a2);
	else
		printf("-%.1lfx^5", a2);
	if(a1 > 0)
		printf("+%.1lfx^4", a1);
	else
		printf("-%.1lfx^4", a1);
	if(a0 > 0)
		printf("+%.1lfx^3", a0);
	else
		printf("-%.1lfx^3", a0);
	if(b3 > 0)
		printf("+%.1lfx^2", b3);
	else
		printf("-%.1lfx^2", b3);
	if(b2 > 0)
		printf("+%.1lfx", b2);
	else
		printf("-%.1lfx", b2);
	if(b1 > 0)
		printf("+%.1lf", b1);
	else
		printf("-%.1lf", b1);

}
