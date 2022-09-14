#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int check_polindrom(int array[], int i, int n){
/*This function check if the array polindrom or not.*/
	if(i >= n) /*If the array null return 0*/
		return 1;
	else if(array[i] == array[n])
		return check_polindrom(array, i+1, n-1); /*check to the last integer in the array*/
	else
		return 0; /*is not equal return 0*/
}


int search_element(int array2[], int input_number, int x){
/*This function checks whether the randomly received value is equal to any value in the array*/
	int deger;
	if(array2[x] == '\0') /*If the array null return 0*/
		 deger = 0;
	else if(array2[x] == input_number) /*If the number exists in the array return 1*/
		deger = 1;
	else{
		x++;
		deger = search_element(array2, input_number, x); /*check to the last integer in the array*/
	}
	return deger;
}


int main(){
/*I assigned the values required for the first function*/
	int n, deger, i;
	int array[50];
	printf("How many elements enter you will enter the array?\n");
	scanf("%d", &n); /*I received the n value from the user. */
	for(i=0; i<n; i++){   /*I crete n size array with for loop */
		printf("Enter %d. element: ", i+1);
		scanf("%d", &array[i]);
	}
	deger = check_polindrom(array, 0, n-1);  /* I send the values to function*/
	if(deger == 1) /*I cheched the polindrom or not and I printed*/
		printf("Your input is polindrom.\n"); 
	else
		printf("Your input is not polindrom.\n");
	printf("\n-------------------------------------------------\n\n");
/*I assigned the values required for the second function*/
	int array2[20];
	int input_number, x=0;
	srand(time(NULL)); /*I assigned random integer 0 to 100*/
	for(i=0; i<20; i++){ /*I crete n size array with for loop */
		array2[i]= rand()%100;
		printf("%d ", array2[i]);
	}
	input_number = rand()%100;
	printf("\nnumber is: %d\n", input_number); /* I send the values to function*/
	deger = search_element(array2, input_number, x);
	if(deger == 1)  /*I cheched the value in the array or not and I printed*/
		printf("The number is in the array.\n");
	else
		printf("The number is not in the array.\n");
}
