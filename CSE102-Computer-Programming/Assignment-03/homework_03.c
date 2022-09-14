#include <stdio.h>

void write_fibonacci_sequence(int num){
/* Here I did the process of printing fibonacci numbers as much as desired terms number in this function. */
	int x=1, y=1, z, i;
	printf("\nFibonacci Sequence:\n");
	for(i=1; i<=num; i++){
		printf("%d\n", x);
		z = x + y;
		x = y;
		y = z;
	}
}

void calculate_fibonacci_sequence(){
	int num;
	char ch;
/* Here Here I got the infine while loop to get a number until the user enters the '*' sing. */ 
	while(1){
		printf("\nPlease enter term(s) number: ");
		scanf("%d", &num);
		ch = getchar();
/* And I have printed possible results for all possible situations. */ 
		if(ch == 42)
			break;
		else if(num<0){
			printf("\nPlease enter 'positive' term(s) number: ");
			scanf("%d", &num);
			ch = getchar();
			if(ch == 42)
				break;
			else if((ch>64) && (ch<123)){
				printf("\nPlease enter 'numeric' term(s) number: ");
				scanf("%d", &num);
				ch = getchar();
				if(ch == 42)
					break;
				else
					write_fibonacci_sequence(num);
			}
			else
				write_fibonacci_sequence(num);	
		}
		else if((ch>64) && (ch<123)){
			printf("\nPlease enter 'numeric' term(s) number: ");
			scanf("%d", &num);
			ch = getchar();
			if(ch == 42)
				break;
			else if(num<0){
				printf("\nPlease enter 'positive' term(s) number: ");
				scanf("%d", &num);
				ch = getchar();
				if(ch == 42)
					break;
				else
					write_fibonacci_sequence(num);
			}
			else
				write_fibonacci_sequence(num);
		}
		else
			write_fibonacci_sequence(num);
	}
}

void calculate_perfect_number(int num){
/* Here I calculated the number perfect number or not. */
	int sum=0, i;
	for(i=1; i<num; i++){
		if(num%i == 0)
			sum = sum + i;
	}
/* Here I printed the natural number divisors with a for loop. */
	printf("\nNaturel Number Divisors:");
	for(i=1; i<=num; i++){
		if(num%i == 0){
			if(i == num)
				printf(" %d", i);
			else
				printf(" %d,", i);
		}
	}
	if((num == sum) || (num ==1))
		printf("\nIs Perfect Number? : Yes");
	else	
		printf("\nIs Perfect Number? : No");
}

int calculate_harmonic_divisor_number(int num){
/* Here I calculated the number harmonic divisor or not. */
	int i, count=0;
	float sum=0.0, result;
	for(i=1; i<=num; i++){
		if(num%i == 0){
			sum = sum + (1.0/(float)i);
			count++;
		}
	}
/* Here I use typecasting. */
	result = (float)count/sum;
	if((result - (int)result) < 0.000001)
		printf("\nIs Harmonic Divisor Number? : Yes");
	else
		printf("\nIs Harmonic Divisor Number? : No");		
}


void decide_perfect_harmonic_number(){
	int num;
	char ch;
/* Here I got the infine while loop to get a number until the user enters the '*' sing. */ 
	while(1){
		printf("\n\nPlease enter input number: ");
		scanf("%d", &num);
		ch = getchar();
		if(ch == 42)
			break;
		else if(num < 0)
			printf("\nPlease try again.");
/* Here I wrote different functions and called them so that the code would not grow unnecesserily. */
		else{
			calculate_perfect_number(num);
			calculate_harmonic_divisor_number(num);
		}
	}
}

void difference_max_min(){
	int i;
	double num, min, max, diff;
/* Here I got five numbers from the user and found the largest and smallest of these numbers. */
	printf("\nPlease enter 5 numbers: ");
	scanf("%lf", &num);
	max = num;
	min = num;
	for(i=0; i<4; i++){
		scanf(" %lf", &num);
		if(num > max)
			max = num;
		if(num < min)
			min = num;
	}
/* Then I pulled these two numbers out of each other and I printed the result. */
	diff = max - min;
	printf("\nMaximum number is: %lf", max);
	printf("\nMinimum number is: %lf", min);
	printf("\nDifference between maximum and minimum is: %.3lf\n", diff);
}

void bmi_calculation(){
/* Here I took the height and weight from the user in order to be able to calculate bmi and processed them. */
	double height, weight, bmi;
	printf("\nPlease enter weight(kg): ");
	scanf("%lf", &weight);
	printf("\nPlease enter height(m): ");
	scanf("%lf", &height);
	bmi = weight / (height * height);
/* Here I made sure that the appropriate answer was found with if- else if- else block. */ 
	if(bmi < 16.0)
		printf("Your category: Severely Underweight\n");
	else if((bmi >=16.0) && (bmi < 18.5))
		printf("Your category: Underweight\n");
	else if((bmi >= 18.5) && (bmi < 25.0))
		printf("Your category: Normal\n");
	else if((bmi >= 25.0) && (bmi < 30.0))
		printf("Your category: Overweight\n");
	else
		printf("Your category: Obese\n");
}

int main(){
/*Here I printed out what we were doing to indicate that the code was logged in before starting each function in order to look correct. */
	printf("\nCALCULATING FIBONACCI SEQUENCE");
	calculate_fibonacci_sequence();
	printf("\nDECIDING PERFECT NUMBER & HARMONIC DIVISOR NUMBER");
	decide_perfect_harmonic_number();
	printf("\nCALCULATING DIFFERENCE BETWEEN MAX AND MIN NUMBERS"); 
	difference_max_min();
	printf("\nCALCULATING BMI");
	bmi_calculation();	
}

