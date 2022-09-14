#include <stdio.h>

int find_max_distance(int num){
/* Here I calculate max distance between entered values. */
	int max, min, i, max_distance;
	max = num;
	min = num;
/* I have mached the first entered value to max and min so that I can compare. */
	for(i= 2; i<6; i++){
		printf("\n%d: ", i);
		scanf("%d", &num);
		if(num>max)
			max = num;
		if(num < min)
			min = num;
	}
/* I got the values one by one with for loop and compared each other. And than I found max and min values and calculate max distance. And return it. */
	max_distance = max - min;
	return max_distance;	
}


void find_odd_average(){
/* Here I calculated the average of odd numbers until enter -1. */
	int i=1, num=0, sum=0, count=0;
	double average;
	printf("Please enter positive numbers(end -1 to stop entering):\n");
/* Here I use infine loop because I always need to be valued. */ 
	while(1){
		printf("%d: ",i);
		scanf("%d", &num);
		if(num == -1)
			break;
		else if(num%2 != 0){
			sum = sum + num;
			count++;
		}
		i++;
	}
/* Finally I division the sum to count and I found average. And I printed it. */
	average = (sum/count);
	printf("Average of odd numbers: %.2lf\n", average);
}


int main(){
/* Here firstly I made first fonksion and I gave a value from the user. */
	int num, max;
	printf("Please enter 5 number: \n");
	printf("1: ");
	scanf("%d", &num);
	max = find_max_distance(num);
	printf("Max distance between two consecutive nums: %d\n", max);
/* Here I began to second fonksion */
	find_odd_average();
}

