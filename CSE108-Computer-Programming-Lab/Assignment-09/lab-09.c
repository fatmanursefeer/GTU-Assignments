#include <stdio.h>
#include <string.h>

struct grades{
	/*Here I create grades struct. */
	float midterm;
	float final;
	float homework;
};

struct students{
	/*Here I create students struct. */
	char name_surname[40];
	int id;
	struct grades ort; /*I call grades struct*/
};

struct games{
	/*Here I create games struct. */
	char name[30];
	char platform[10][20];
	float score;
};

struct line{
	/*Here I create line struct. */
	float x1, y1, x2, y2, x3, y3, slope;
};

int main(){
	/*PART1*/
	struct line myline; /* I create myline */
	printf("\nEnter x1: "); /*I wanted the enter of the variables from the user. */
	scanf("%f", &myline.x1);
	printf("\nEnter y1: ");
	scanf("%f", &myline.y1);
	printf("\nEnter x2: ");
	scanf("%f", &myline.x2);
	printf("\nEnter y2: ");
	scanf("%f", &myline.y2);
	printf("\nEnter x3: ");
	scanf("%f", &myline.x3);
	myline.slope = (myline.y2 - myline.y1) / (myline.x2 - myline.x1);   /* m = (y2-y1)/ (x2-x1) */
	myline.y3 = (myline.slope * (myline.x3 - myline.x2)) + myline.y2;   /* We know the m so I use the other variables and I found the y3 */
	printf("\nThe slope of the line: %f", myline.slope);  /* Finaally I print them */
	printf("\ny3: %f", myline.y3);
	
	/*PART2*/
	int n, i, id, flag=0;
	printf("How many students are there?: ");  /* The user enter the how man students are there. */
	scanf("%d", &n);
	float avr_mid, avr_fin, avr_hmw;
	float ort_arr[n], sum_mid=0, sum_fin=0, sum_hmw=0;
	struct students students_arr[n];   /* I create student_arr */
	for(i=0; i<n; i++){    /* I use for loop and I filled the arr */
		printf("\nEnter the %d. student name and surname: ", i+1);
		scanf(" %[^\n]%*c", students_arr[i].name_surname);
		printf("\nEnter the %d. student id number: ", i+1);
		scanf("%d", &students_arr[i].id);
		printf("\nEnter the %d. student midterm grade: ", i+1);
		scanf("%f", &students_arr[i].ort.midterm);
		printf("\nEnter the %d. student final grade: ", i+1);
		scanf("%f", &students_arr[i].ort.final);
		printf("\nEnter the %d. student homework grade: ", i+1);
		scanf("%f", &students_arr[i].ort.homework);
		sum_mid = sum_mid + students_arr[i].ort.midterm;
		sum_fin = sum_fin + students_arr[i].ort.final;
		sum_hmw = sum_hmw + students_arr[i].ort.homework;
	}
	fflush(stdin);
	avr_mid = sum_mid/n;  /* And I calculate the average of the grades and then I printed the all of them */
	avr_fin = sum_fin/n;
	avr_hmw = sum_hmw/n;
	printf("\nAverage of the midterms: %f\nAverage of the finals: %f\nAverage of the homeworks: %f\n", avr_mid, avr_fin, avr_hmw);
	printf("\nEnter a students id number: ");    /* User enter the id number */
	scanf("%d", &id);
	for(i=0; i<n; i++){
		if(id == students_arr[i].id){
			printf("\nStudent name-surname: %s", students_arr[i].name_surname);
			printf("\nStudent id: %d", students_arr[i].id);
			printf("\nStudent midterm grade: %f", students_arr[i].ort.midterm);
			printf("\nStudent final grade: %f", students_arr[i].ort.final);
			printf("\nStudent homework grade: %f\n", students_arr[i].ort.homework);
			flag = 1;  /* If there exist the flag becomes 1 */
		}
	}
	if(flag == 0)   /* If not exits the error message */
		printf("\nERROR THE STUDENT DOES NOT EXIST!!\n");
	
	/*PART3*/
	int num, j, temp;
	float sum_score=0, avr_score;
	printf("How many games are there?: ");
	scanf("%d", &num);
	struct games game_arr[num]; /* I create game_arr */
	for(j=0; j<num; j++){   /* I use for loop and I filled the arr */
		printf("\nEnter the %d. game name: ", i+1);
		scanf("%s", game_arr[i].name);
		printf("\nEnter the %d. game score: ", i+1);
		scanf("%f", &game_arr[i].score);
		sum_score = sum_score + game_arr[i].score;
	}
	avr_score = sum_score / num; /* And I calculate the average of the scores and then I printed the all of them */
	printf("\nAverage score of the games: %f \n", avr_score);
	 
}
