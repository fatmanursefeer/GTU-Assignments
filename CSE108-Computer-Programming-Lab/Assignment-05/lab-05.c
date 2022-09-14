#include <stdio.h>
#include <stdlib.h>

void expression0(int x, int *result){
/* I have described the operations for expression0 in here */
	*result = x*x +5;
}

void expression1(int x, int *result){
/* I have described the operations for expression1 in here */
	*result = 2*x + 1;
}

void expression2(int x, int *result){
/* I have described the operations for expression2 in here */
	*result = x*x;
}

void addition(void (*func)(int, int *), int *sum, int n){
/* Here I did the operations for each function with for loop. */
	for(x=0; x<=n; x++){
		*func(x, &result);
		*sum = *sum + *result;
	}
}

void calculation(int *sumArray, int n){
/* Here I called the addition function seperately for each three function and added the array. */
	addition((&expression0)(x, &result), &sum, n);
	*sumArray[0] = *sum;
	addition((&expression1)(x, &result), &sum, n);
	*sumArray[1] = *sum;
	addition((&expression2)(x, &result), &sum, n);
	*sumArray[2] = *sum;
}


void createArray(int *array2[10]){
/* Here I filled 2D array with two for loops. */
	int i,j;
	for(i=0; i<10; i++){
		for(j=0; j<10; j++)
			*array2[i][j] = rand()%90 + 10; /*I used the rand function to get random numbers.*/
	}
}

int main(){
/*Here I created the variables. */
	int sumArray[3];
	int array2[10][10];
	int n, result, sumArray=0, sum=0;
	int i, j;
/* Taking the n variable from the user. */
	printf("n: ");
	scanf("%d", &n);
/* And I called calculation function here.*/
	calculation(*sumArray, n);
/* I printed the results that came out one by one. */
	printf("Sum of expression0: %d\n", sumArray[0]);
	printf("Sum of expression1: %d\n", sumArray[1]);
	printf("Sum of expression2: %d\n", sumArray[2]);
/* Here we went to second part. */
	printf("-----------------------------------------------------\n");
	printf("Matrix: \n");
/* I called the function to fill the array. */
	createArray(&array2[10]);
	while(1){
	/* I kept the while loop until the user entered the wrong value. */
		printf("Which elements of the matrix do you want to reach?\ni: ");
		scanf("%d", &i);
		printf("j: ");
		scanf("%d", &j);
		if((j<0) || (j>10) || (i<0) || (i>10)){
			printf("Invalid input. Terminating...\n");
			break;
		}
		else
			printf("%d. row %d. column of the matrix is: %d\n", i, j, array2[i][j]);
	}
}
