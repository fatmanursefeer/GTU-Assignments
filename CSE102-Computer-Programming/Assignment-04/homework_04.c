#include <stdio.h>
#include <math.h>

void write(float a_n, int n){
/* I created this function because if I wrote down the values in this function every time, my code would be redundant. */
	if(n == 1){ 
	/* I created this part to print a_n*x instead of printing a_n*x^1 */
		if(a_n > 0){
	    		printf("+");
	    		if(a_n == 1)
	    			printf("x");
	    		else
	    			printf("%.1fx", fabs(a_n));
	    	}
	    	else if(a_n < 0){
			printf("-");
	    		if(a_n == 1)
	    			printf("x");
	    		else
	    			printf("%.1fx", fabs(a_n));
	    	}
	}
	else if(n == 0){
	/* I created this part to print a_n instead of printing a_n*x^0 */
		if(a_n > 0)
			printf("+%.1f", fabs(a_n));
		else if(a_n < 0)
			printf("-%.1f", fabs(a_n));
	
	}
	else{
		if(a_n > 0){
			printf("+");
			if(a_n == 1)
				printf("x^%d", n);
			else
				printf("%.1fx^%d", a_n, n);
		}
		else if(a_n < 0){
			printf("-");
			if(a_n == 1)
			    	printf("x^%d", n);
			else
			    	printf("%.1fx^%d", fabs(a_n), n);
		}
	}
}

void write_polynomial(){
/* In this function, I wrote the polynomial according to the request of the user by taking the coefficient values and how many degree polynomials the user wants to write.
** Ihave assigned variables n for degree and a_n for coefficient. */
	int n;
	float a_n;
	printf("Enter your polynomial: (like n a_n a_n-1 ... a_0): ");
	scanf("%d", &n);  /* I got the value of n here. */
	printf("p(x) = "); 
	while(n+1 > 0){
		scanf(" %f", &a_n); /* I got the value of a_n here. */
		write(a_n, n); /* Here I sent the values to the function that I created seperately. */
		n--;
	}
	printf("\n");
}


void armstrong_and_palindrom_numbers(){
/* In this function, I determine whether the number entered by the user is a Palindrom or Armstrong number.
** Here I assigned the variables that I used to find the Palindrome number. */
	int num, temp1, sum1=0;
/* Here I assigned the variables that I used to find the Armstrong number. */
	int temp2, temp3, sum2=0, count=0, pwr, i;
	while(1){
		printf("Please enter an integer number: ");
		scanf("%d", &num);
		/* Here I checkec to see if the user entered negative number, if they did, I wrote an error message. */
		if(num < 0)
			printf("Please enter positive integer number.\n");
		else{
		/* Here I have done the necessesary operations for Palindrome number. */
			temp1 = num;
			while(temp1 != 0){
				sum1 = sum1 * 10;
				sum1 = sum1 + temp1%10;
				temp1 = temp1/10;
			}
			/* Here I have done the necessesary operations for Armstrong number. */
			temp2 = num;
			while(temp2 != 0){
				count++; /* Here I calculated have many digits the number is. */
				temp2 = temp2/10;
			}
			temp2 = num;
			while(temp2 != 0){
				pwr = 1;
				temp3 = temp2%10;
				for(i=0; i<count; i++)
					pwr = pwr * temp3;
				sum2 = sum2 + pwr;
				temp2 = temp2/10;
			}
			if((sum1 == num) && (sum2 == num))
				printf("This number is both Palindrome and Armstrong number.\n");
			else if((sum1 == num) && (sum2 != num))
				printf("This number is only Palindrome number.\n");
			else if((sum1 != num) && (sum2 == num))
				printf("This number is only Armstrong number.\n");
			else
				printf("This number does not satisfy any special cases.\n");
			break;
		}
	}
}

void prime_numbers_between_two_integer(){
/* In this function, our aim is to get two integer numbers from the user and to print the sum of the prime numbers between these two numbers on the screen.
** Here I have assigned the i and k values that I use in for loops and the variables necessary to achive the result with them. */
	int num1, num2, i, k, sum=0, count;
	while(1){
		printf("Please enter first integer number: ");
		scanf("%d", &num1);
		printf("Please enter second integer number: ");
		scanf("%d", &num2);
		/*  Here I printed an error message if the first number the user entered is grater than or equal to the number the second entered. */
		if(num1 >= num2)
			printf("You entered wrong numbers. Please try again.\n");
		/* Here I checkec to see if the user entered negative numbers, if they did, I wrote an error message. */
		else if((num1 < 0) || (num2 < 0))
			printf("Please enter positive integer numbers.\n");
		else{
			for(i=num1+1; i<num2; i++){
				count = 0;
				for(k=2; k<i; k++){
					if(i%k == 0)
						count++;
				}
				if(count == 0)
					sum = sum + i;
			}
			/* I put this condition here because in the code I wrote at the top, it was also getting the number 1 when the first number smaller than 2 
			** So I had it subtract the value of 1 here. */
			if(num1 < 1)
				printf("Sum of prime numbers between %d and %d: %d\n", num1, num2, sum-1);
			else
				printf("Sum of prime numbers between %d and %d: %d\n", num1, num2, sum);
			break;
		}
	}
}

int main(){
/* Here I wrote to indicate that this function started when we entered each function so that the output of my code would look good.
** And I called each function one by one.  */
	printf("\n-----WRITTING POLYNOMIAL-----\n");
	write_polynomial();
	printf("\n-----CALCULATING ARMSTRONG & PALINDROM NUMBERS-----\n");
	armstrong_and_palindrom_numbers();
	printf("\n-----CALCULATING PRIME NUMBERS BETWEEN TWO INTEGER NUMBERS-----\n");
	prime_numbers_between_two_integer();
}
