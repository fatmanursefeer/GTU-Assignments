#include <stdio.h>

int deger_hesapla(int n){
/*Here I have calculated the elements of the array one by one. */
	int sum;
	sum = ((2*n*n)-3);
	n++;
	return sum;
}

float average_finder(int *array3, int x){
/*Here I got the average of the array elements satisfying the condition. */
	float sum=0, avrg;
	int i;
	for(i=0; i<x; i++)
		sum = sum + array3[i];
	avrg = sum/x;
	return avrg;
}

int main(){
/*I created three array */
	int i, j, n=1, x=0;
	int array[3][5], array2[4][9], array3[100];
	float sum1, sum2;
/* I filled the arrays by calling the function. */
	for(i=0; i<3; i++){
		for(j=0;j<5;j++){
			array[i][j] = deger_hesapla(n);
			n++;
		}
	}
	n = 1;
/* I filled the arrays by calling the function. */
	for(i=0; i<4; i++){
		for(j=0;j<9;j++){
			array2[i][j] = deger_hesapla(n);
			n++;
		}
	}
/* I detected the arrays and send them to the funtion to calculate the average of the arrays that meet the condition. */
	for(i=0;i<3;i++){
		for(j=0; j<5; j++){
			while(((i+j)%2) == 0){
				array3[x] = array[i][j];
				x++;
			}
		}
	}
	sum1 = average_finder(array3, x);
	x=0;
/* I detected the arrays and send them to the funtion to calculate the average of the arrays that meet the condition. */
	for(i=0;i<4;i++){
		for(j=0; j<9; j++){
			while(((i+j)%2) == 0){
				array3[x] = array2[i][j];
				x++;
			}
		}
	}
	sum2 = average_finder(array3, x);
	/*Finally I printed the arrays one by one. */
	printf("Average Finder\n\nMatrix:\n");
	for(i=0; i<3; i++){
		for(j=0; j<5; j++)
			printf("%d\t", array[i][j]);
		printf("\n");
	}	
	printf("Result: %.1f\n", sum1);
	for(i=0; i<4; i++){
		for(j=0; j<9; j++)
			printf("%d\t", array2[i][j]);
		printf("\n");
	}	
	printf("Result: %.1f\n", sum2);
	/*part2*/
	
	
	
}
