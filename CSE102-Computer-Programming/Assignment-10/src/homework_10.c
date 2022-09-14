#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{  /* Here I created my struct. */
	double budget;
	int genre;
	char* name;
	double score;
	int year;
}Movie;


void part_7(int * arr, char ** type, int a){ /* This function sorted the genres and writing how many are there. */
	int x, i, temp;
	for(x=0; x<a; x++){
		if(arr[x] != 0)  /* Checking null or not. If null does not write. */
			printf("\n%-20s\t%10d", type[x], arr[x]); /*And print the result. */
	}
}


void part_6(Movie * movie, int i){   /* This function calculate the average imbd values and prints it. */
	int x;
	double avr, sum=0;
	for(x=0; x<i; x++)
		sum = sum + movie[x].score; /* calculate. */
	avr = sum / i;
	printf("\nAverage: %lf\n", avr);  /* And print */
}


void part_5(Movie * movie, int i, char ** type){   /* This function finds the movie and prints it */  
	int x=30, flag=0, temp;
	char *name = (char*)malloc(sizeof(char) * x);
	while(1){  /* If the user enters wrong name computer asked the again because of the infinite while loop. */
		printf("\nPlease enter the name of the movie: ");
		scanf("%s", name);
		for(x=0; x<i; x++){
			if(strcmp(name, movie[x].name) == 0){  /* If the movie name same as the exact movie if block is works. */
				temp = movie[x].genre - 1;
				if(movie[x].budget == 0)   /* If the budget is unknown, prints unknown. */
					printf("\nBudget: unknown\nGenre: %s\nName: %s\nScore: %lf\nYear: %d\n", type[temp],  movie[x].name, movie[x].score, movie[x].year);
				else    /* Else prints exact budget. */
					printf("\nBudget: %lf\nGenre: %s\nName: %s\nScore: %lf\nYear: %d\n", movie[x].budget, type[temp], movie[x].name, movie[x].score, movie[x].year);
				flag=1;
				break;
			}
		}
		if(flag == 1) break;  /* If the movie is founds flag turns 1 and breaking infinite while loop. */
		else printf("\nTRY AGAIN\n");  /* Else computers asks again the movie name. */
	}
	free(name);
}


void part_4(Movie * movie, int i){  /* This function takes the informations from the user and works accordingly the informations. */
	double score;
	int op, x, flag=0;
	while(1){   /* If the user enters wrong score computer asked the again because of the infinite while loop. */
		printf("\nEnter a score: ");
		scanf("%lf", &score);
		printf("\nLess (0) or Greater (1) %lf : ", score);
		scanf("%d", &op);
		if(op == 0){
			for(x=0; x<i; x++){
				if(movie[x].score < score){  /* If the score less than score if block works */
					printf("\n%s", movie[x].name);
					flag = 1;
				}
			}
			if(flag != 1) printf("\nTRY AGAIN\n");  /* If not found any score gives an error mesaage */
			else break;
		}
		else if(op == 1){
			for(x=0; x<i; x++){
				if(movie[x].score > score){  /* If the score grater than score if block works */
					printf("\n%s", movie[x].name);
					flag = 1;
				}
			}
			if(flag != 1) printf("\nTRY AGAIN\n");   /* If not found any score gives an error mesaage */
			else break;  /* If the movie is founds flag turns 1 and breaking infinite while loop. */
		}
		else printf("\nTRY AGAIN\n");  /* Else computers asks again the movie score. */
	}
}


void part_3(Movie * movie, int i){  /* This function takes the informations from the user and works accordingly the informations. */
	int year, x, op, flag=0;
	while(1){    /* If the user enters wrong year computer asked the again because of the infinite while loop. */
		printf("\nEnter a year: ");
		scanf("%d", &year);
		printf("\nUntil (0) or Since (1) %d : ", year);
		scanf("%d", &op);
		if(op == 0){
			for(x=0; x<i; x++){
				if(movie[x].year < year){   /* If the year less than year if block works */
					printf("\n%s", movie[x].name);
					flag = 1;
				}
			}
			if(flag != 1) printf("\nTRY AGAIN\n");   /* If not found any year gives an error mesaage */
			else break;
		}
		else if(op == 1){
			for(x=0; x<i; x++){
				if(movie[x].year > year){   /* If the year grater than year if block works */
					printf("\n%s", movie[x].name);
					flag = 1;
				}
			}
			if(flag != 1) printf("\nTRY AGAIN\n");    /* If not found any year gives an error mesaage */
			else break;    /* If the movie is founds flag turns 1 and breaking infinite while loop. */
		}
		else printf("\nTRY AGAIN\n");     /* Else computers asks again the movie year. */
	}
	
}


void part_2(int * arr, char ** type, int a){  /* This function writes the type names. */
	int x;
	for(x=0; x<a; x++){   /* a is length of the arr */
		if(arr[x] != 0)  /* If the arr not null, prints the type name. */
			printf("\n%s", type[x]);
	}
}


void part_1(Movie * movie, int i, char ** type, int l){  /* This function sorts the values according to user wants. */
	int num, op, sval, eval, temp, x, ret;
	int k=30, temp_year, temp_genre;
	double temp_budget, temp_score;
	char *temp_name = (char*)malloc(sizeof(char) * k);  /* I create temp name dinamically */
	Movie *temp_movie;
	temp_movie = (Movie *)calloc(l, sizeof(Movie));   /* I create temp movie struct dinamically */
	while(1){
		printf("\n1. Budget\n2. Genre\n3. Name\n4. Score\n5. Year\n\nPlease select an operation: ");  /* I takes the necessary information from the user. */
		scanf("%d", &num);
		printf("\n\n1. Single Selection\n2. Multiple Selection\n\nPlease select an operation: ");
		scanf("%d", &op);
		for(k=0; k<l; k++)
			temp_movie[k] = movie[k];   /* I filled the temp structure same values exact structure. */
		switch(num){
			case 1:    /* If the user select 1, I sorted the values according to budget. */
				for(k=0; k<i; k++){
					for(l=k+1; l<i; l++){
						if(temp_movie[k].budget > temp_movie[l].budget){   /* If the budget grater than other budget switches the values. */
							temp_budget = temp_movie[k].budget;  
							temp_score = temp_movie[k].score;
							temp_year = temp_movie[k].year;
							temp_genre = temp_movie[k].genre;
							strcpy(temp_name, temp_movie[k].name);
							temp_movie[k].budget = temp_movie[l].budget;
							temp_movie[k].score = temp_movie[l].score;
							temp_movie[k].year = temp_movie[l].year;
							temp_movie[k].genre = temp_movie[l].genre;
							strcpy(temp_movie[k].name, temp_movie[l].name);
							temp_movie[l].budget = temp_budget;
							temp_movie[l].score = temp_score;
							temp_movie[l].year = temp_year;
							temp_movie[l].genre = temp_genre;
							strcpy(temp_movie[l].name, temp_name);
						}
					}
				}
				break;
			case 2:  /* If the user select 2, I sorted the values according to genres. */
				for(k=0; k<i; k++){
					for(l=k+1; l<i; l++){
						if(temp_movie[k].genre > temp_movie[l].genre){  /* If the genre grater than other genre switches the values. */
							temp_budget = temp_movie[k].budget;
							temp_score = temp_movie[k].score;
							temp_year = temp_movie[k].year;
							temp_genre = temp_movie[k].genre;
							strcpy(temp_name, temp_movie[k].name);
							temp_movie[k].budget = temp_movie[l].budget;
							temp_movie[k].score = temp_movie[l].score;
							temp_movie[k].year = temp_movie[l].year;
							temp_movie[k].genre = temp_movie[l].genre;
							strcpy(temp_movie[k].name, temp_movie[l].name);
							temp_movie[l].budget = temp_budget;
							temp_movie[l].score = temp_score;
							temp_movie[l].year = temp_year;
							temp_movie[l].genre = temp_genre;
							strcpy(temp_movie[l].name, temp_name);
						}
					}
				}
				break;
			case 3:    /* If the user select 3, I sorted the values according to names length. */
				for(k=0; k<i; k++){
					for(l=k+1; l<i; l++){
						if(strcmp(temp_movie[k].name, temp_movie[l].name) > 0){    /* If the name long than other name switches the values. */
							temp_budget = temp_movie[k].budget;
							temp_score = temp_movie[k].score;
							temp_year = temp_movie[k].year;
							temp_genre = temp_movie[k].genre;
							strcpy(temp_name, temp_movie[k].name);
							temp_movie[k].budget = temp_movie[l].budget;
							temp_movie[k].score = temp_movie[l].score;
							temp_movie[k].year = temp_movie[l].year;
							temp_movie[k].genre = temp_movie[l].genre;
							strcpy(temp_movie[k].name, temp_movie[l].name);
							temp_movie[l].budget = temp_budget;
							temp_movie[l].score = temp_score;
							temp_movie[l].year = temp_year;
							temp_movie[l].genre = temp_genre;
							strcpy(temp_movie[l].name, temp_name);
						}
					}
				}
				break;
			case 4:     /* If the user select 4, I sorted the values according to scores */
				for(k=0; k<i; k++){
					for(l=k+1; l<i; l++){
						if(temp_movie[k].score > temp_movie[l].score){   /* If the score grater than other score switches the values. */
							temp_budget = temp_movie[k].budget;
							temp_score = temp_movie[k].score;
							temp_year = temp_movie[k].year;
							temp_genre = temp_movie[k].genre;
							strcpy(temp_name, temp_movie[k].name);
							temp_movie[k].budget = temp_movie[l].budget;
							temp_movie[k].score = temp_movie[l].score;
							temp_movie[k].year = temp_movie[l].year;
							temp_movie[k].genre = temp_movie[l].genre;
							strcpy(temp_movie[k].name, temp_movie[l].name);
							temp_movie[l].budget = temp_budget;
							temp_movie[l].score = temp_score;
							temp_movie[l].year = temp_year;
							temp_movie[l].genre = temp_genre;
							strcpy(temp_movie[l].name, temp_name);
						}
					}
				}
				break;
			case 5:     /* If the user select 5, I sorted the values according to year. */
				for(k=0; k<i; k++){
					for(l=k+1; l<i; l++){
						if(temp_movie[k].year > temp_movie[l].year){    /* If the year grater than other year switches the values. */
							temp_budget = temp_movie[k].budget;
							temp_score = temp_movie[k].score;
							temp_year = temp_movie[k].year;
							temp_genre = temp_movie[k].genre;
							strcpy(temp_name, temp_movie[k].name);
							temp_movie[k].budget = temp_movie[l].budget;
							temp_movie[k].score = temp_movie[l].score;
							temp_movie[k].year = temp_movie[l].year;
							temp_movie[k].genre = temp_movie[l].genre;
							strcpy(temp_movie[k].name, temp_movie[l].name);
							temp_movie[l].budget = temp_budget;
							temp_movie[l].score = temp_score;
							temp_movie[l].year = temp_year;
							temp_movie[l].genre = temp_genre;
							strcpy(temp_movie[l].name, temp_name);
						}
					}
				}
				break;
		}
		if((op == 1) && (num>0) && (num<6)){   /* If the user wants to one value information this block works. */
			printf("\n\nEnter value: ");
			scanf("%d", &sval);
			temp = temp_movie[sval].genre;
			printf("\n%d. Movie\n\n", sval);   /* I printed the values I ordered before. */
			printf("%-10lf\t%10s  %30s\t%35lf\t%40d\n", temp_movie[sval-1].budget, type[temp-1], temp_movie[sval-1].name, temp_movie[sval-1].score, temp_movie[sval-1].year);
		}
		else if((op == 2) && (num>0) && (num<6)){   /* If the user wants to more than one value information this block works. */
			printf("\n\nEnter start value: ");
			scanf("%d", &sval);
			printf("\nEnter end value: ");
			scanf("%d", &eval);
			printf("\nMovies between %d and %d, sorted by budget.\n\n", sval, eval);
			for(x=sval; x<=eval; x++){
				temp = temp_movie[x].genre;     /* I printed the values I ordered before. */
				printf("%-10lf\t%10s  %30s\t%35lf\t%40d\n", temp_movie[x-1].budget, type[temp-1], temp_movie[x-1].name, temp_movie[x-1].score, temp_movie[x-1].year);
			}		
		}
		else printf("\nTRY AGAIN\n");
	}
	free(temp_movie);    /* free the temp structure. */
	free(temp_name);    /* free the temp char. */
}


int control(Movie * movie, int i){  /* This function checks if the name existed before if it returs 1. */
	int x, temp;
	for(x=0; x<i; x++){
		if(strcmp(movie[i].name, movie[x].name) == 0){  /* If the same names exist this block works. */
			movie[x].budget = movie[i].budget;
			movie[x].genre = movie[i].genre;
			movie[x].score = movie[i].score;
			movie[x].year = movie[i].year;
			return 1;  /* and return 1. */
		}
	}
	return 0;  /* else returns 0 */
}


int genre_reading(char *temp, Movie * movie, int i, int a, int * arr, char ** type){  /* This function works to determine types and array size. */
	int x, flag=0;
	if(a == 0){  /* If the first element this block works. */
		strcpy(type[0], temp);
		arr[0]++;
		movie[i].genre = a+1;
		return 1;
	}
	else{
		for(x=0; x<a; x++){
			if(strcmp(type[x], temp) == 0){  /* If the type exist before this block works and just array size increases. */
				arr[x]++;
				movie[i].genre = x+1;
				flag=1;
				break;
			}
		}
		if(flag != 1){   /* else the new type adds the type array and the other arrays size increases. */
			strcpy(type[x], temp);
			arr[x]++;
			return 1;
		}
	}
	return 0;
}


void read_file(char filename[], int l, Movie * movie){  /* This function reads the file and takes the informations inside the file. */
	int len = 300, i, op, ret, tempi=150, row=50, a=0, b, c;
	double n;
	int *arr = (int*)malloc(tempi * sizeof(int));  /* I create necessary arrays dinamically. */
	char *line = (char*)malloc(sizeof(char) * len);
	char *temp = (char*)malloc(sizeof(char) * tempi);
	char *temp2 = (char*)malloc(sizeof(char) * tempi);
	char *temp3 = (char*)malloc(sizeof(char) * tempi);
	char **type = malloc(row * sizeof(char *));
	for(i=0; i<row; i++)  /* I create 2d char type array dinamically. */
		type[i] = malloc(row * sizeof(char));
	FILE *fpt;
	if((fpt = fopen(filename, "r")) == NULL){  /* If the file is not opened gives an error message. */
		printf("\nERROR THE FILE IS NOT OPENED!!!\n");
		exit(1);
	}
	for(i=0; i<tempi; i++)  /* I equaled the all of the arr element to 0 because of the garbage values. */
		arr[i] = 0;
	i=0;
	fgets(line, len, fpt); /* I read first line seperately becase the firs line just contains string values. */ 
	while(fgets(line, len, fpt) != NULL){  /* And then I read end of the file and takes the informations. */
		temp = strtok(line, ",");  /* I use strtok seperate the strings. */
		movie[i].budget = strtod(temp, &temp2);  /*And I use strtod parse string to double. */
		temp3 = strtok(NULL, ",");
		temp = strtok(NULL, ",");
		movie[i].name = malloc(tempi * sizeof(char));  /* I create struct name dinamically. */
		strcpy(movie[i].name, temp);
		temp = strtok(NULL, ",");
		movie[i].score = strtod(temp, &temp2);
		temp = strtok(NULL, ",");
		n = strtod(temp, &temp2);
		movie[i].year = (int)n;  /* I do typecasting double to integer. */
		b = control(movie, i);
		if(b == 1) i--;  /* If the name exist before i decreasing and the struct filled again. */
		else{
			c = genre_reading(temp3, movie, i, a, arr, type);  /* If not exist before genre is determins. */
			if(c == 1) a++;  /* If the new type is adding the array size increases. */
		}
		i++;
	}
	fclose(fpt); /* Iclose the file. */
	while(1){   /* I create infinete loop and asked the user what action he wants. */ 
		printf("\n**********************MENU*********************\n");
		printf("1. List of the Sorted Data\n2. List of the Genres\n3. List of the Movie Through the Years\n");
		printf("4. List of the Movie Through the Scores\n5. All Information of a Single Movie\n6. Average of the IMBD Scores\n");
		printf("7. Frequence of the Genres\n8. Exit\n\nPlease select an operation: ");
		scanf("%d", &op);
		if(op == 1) part_1(movie, i, type, l);  /* part 1 */
		else if(op == 2) part_2(arr, type, a);  /* part 2 */
		else if(op == 3) part_3(movie, i);  /* part 3 */
		else if(op == 4) part_4(movie, i);  /* part 4 */
		else if(op == 5) part_5(movie, i, type);  /* part 5 */
		else if(op == 6) part_6(movie, i);  /* part 6 */
		else if(op == 7) part_7(arr, type, a);  /* part 7 */
		else if(op == 8) break;  /* If the user wants the exit breaking the while loop */
		else printf("\nTRY AGAIN\n");  /* If the user enters other than upper values gives an error message. */
	}
	for(i=0; i<row; i++)  /* I freeing one by one of the 2d char array. */
		free(type[i]);
	free(line);  /* And I free other variables. */
	free(temp);
	free(temp2);
	free(temp3);
	free(arr);
}

int main(){
	FILE *fp;
	Movie *movie;
	char temp;
	int satir_sayisi=0, tempi=100;
	char *filename = malloc(sizeof(char) * tempi);  /* I create char array dinamically for the takes file name. */
	printf("Enter your file name: ");
	scanf("%s", filename);
	if((fp = fopen(filename, "r")) == NULL){   /* If the file is not opened gives an error message. */
		printf("\nERROR THE FILE IS NOT OPENED!!!\n");
		exit(1);
	}
	for(temp = getc(fp); temp != EOF; temp = getc(fp)){   /* I calculated the number of lines and I created the structure according to this value. */
		if(temp == '\n')
			satir_sayisi++;
	}
	fclose(fp);  /* I close the file. */
	movie = (Movie *)calloc(satir_sayisi, sizeof(Movie)); /* I create the structure dinamically. */
	read_file(filename, satir_sayisi, movie);
	free(filename);  /* Finally I free the filename. */
	free(movie);
}
