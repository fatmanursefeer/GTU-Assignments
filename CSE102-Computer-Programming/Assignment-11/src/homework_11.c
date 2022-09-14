#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node_one{   /* Here I created first structure. */
	int budget;
	int year;
	char* name;
	struct node_one *next;
};


struct node_two{   /* Here I created second structure. */
	char* genre;
	char* name;
	double score;
	struct node_two *next;
};

void free_list_1(struct node_one* h){     /* This function is used to free first type linked list. */
	struct node_one* t;
	while(h != NULL){
		t = h;
		h = h->next;
		free(t);     /* Free one by one. */
	}
}

void free_list_2(struct node_two* h){    /* This function is used to free second type linked list. */
	struct node_two* t;
	while(h != NULL){
		t = h;
		h = h->next;
		free(t);      /* Free one by one. */
	}
}

void insert(struct node_one **Movie_Budget, struct node_two **Movie_Name, struct node_one * temp1, struct node_two * temp2){
   	/* This function inserted the new node to the linked list. */
	struct node_one *curr;     /* Create new head pointer in two type. */
	struct node_two *curr2;
	if(*Movie_Budget == NULL || (*Movie_Budget)->year < temp1->year){     /* If node comes to the top of the list, the contents of this condition apply. */
		temp1->next = *Movie_Budget;     /* New pointer equaled to before with two pointer. */
		temp2->next = *Movie_Name;
		*Movie_Budget = temp1;
		*Movie_Name = temp2;
	}
	else if((*Movie_Budget)->year == temp1->year){  /* If the years equl each other this condition works. And looks the budged. */
		if((*Movie_Budget)->budget <= temp1->budget){
			temp1->next = *Movie_Budget;
			temp2->next = *Movie_Name;
			*Movie_Budget = temp1;
			*Movie_Name = temp2;
		}
		else{
			curr = *Movie_Budget;
			curr2 = *Movie_Name;
			while(curr->next != NULL && curr->next->budget > temp1->budget){
				curr = curr->next;
				curr2 = curr2->next;
			}
			temp1->next = curr->next;
			curr->next = temp1;
			temp2->next = curr2->next;
			curr2->next = temp2;
		}
	}
	else{   /* If none of the conditions appropriate then this condition works. */
		curr = *Movie_Budget;
		curr2 = *Movie_Name;
		while(curr->next != NULL && curr->next->year > temp1->year){
			curr = curr->next;
			curr2 = curr2->next;
		}
		temp1->next = curr->next;
		curr->next = temp1;
		temp2->next = curr2->next;
		curr2->next = temp2;
	}
}

int control(struct node_one *Movie_Budget, struct node_two *Movie_Name, struct node_one *temp1, struct node_two *temp2){
	/* This function checks if a node with the same name exist. If exist then update the node. */
	int flag=0;
	struct node_one *current = NULL;   /* Creates new pointers with two tyoe. */
	struct node_two *current2 = NULL;
	if(Movie_Budget != NULL){
		current = Movie_Budget;
		current2 = Movie_Name;
		while(current->next != NULL){
			if(strcmp(current->name, temp1->name) == 0){   /* If the name exists before then update it. */
				current->budget = temp1->budget;
				current->year = temp1->year;
				current2->score = temp2->score;
				strcpy(current2->genre, temp2->genre);
				flag=1;
				break;
			}
			current = current->next;
			current2 = current2->next;
		}
	}
	return flag;  /* And returns a signal. */
}

struct node_one* swap1(struct node_one *a1, struct node_one *a2){  /* This function swapping to first type two nodes. */
	struct node_one *t = a2->next;
	a2->next = a1;
	a1->next = t;
	return a2;  /* And return it. */
}

struct node_two* swap2(struct node_two *a1, struct node_two *a2){  /* This function swapping to second type two nodes. */
	struct node_two *t = a2->next;
	a2->next = a1;
	a1->next = t;
	return a2;  /* And return it. */
}

void sort(struct node_one **Movie_Budget, struct node_two **Movie_Name, int s){   /* This function sorts the nodes according to years if years are equals then looks budgets. */
	struct node_one **h1;
	struct node_two **h2;
	int i, j , flag;
	for(i=0; i<=s; i++){
		h1 = Movie_Budget;
		h2 = Movie_Name;
		flag = 0;
		for(j=0; j<(s-1-i); j++){
			struct node_one *p1 = *h1;
			struct node_one *p2 = p1->next;
			struct node_two *d1 = *h2;
			struct node_two *d2 = d1->next;
			if(p1->year < p2->year){
				*h1 = swap1(p1, p2);
				*h2 = swap2(d1, d2);
				flag = 1;
			}
			else if(p1->year == p2->year){   /* If years are equal then looks budgets. */
				if(p1->budget <= p2->budget){
					*h1 = swap1(p1, p2);
					*h2 = swap2(d1, d2);
					flag = 1;
				}
			}
			h1 = &(*h1)->next;
			h2 = &(*h2)->next;
		}
		if(flag == 0)
			break;
	}
}


void sort_by_budget(struct node_one **tempnode1, struct node_two **tempnode2, int s){  /* This function sorts the nodes according to their budgets. */
	struct node_one **h1;    /* Create two type node */
	struct node_two **h2;
	int i, j , flag;
	for(i=0; i<=s; i++){
		h1 = tempnode1;
		h2 = tempnode2;
		flag = 0;
		for(j=0; j<(s-1-i); j++){
			struct node_one *p1 = *h1;
			struct node_one *p2 = p1->next;
			struct node_two *d1 = *h2;
			struct node_two *d2 = d1->next;
			if(p1->budget > p2->budget){   /* If budget greater than the other then swap their. */
				*h1 = swap1(p1, p2);
				*h2 = swap2(d1, d2);
				flag = 1;
			}
			h1 = &(*h1)->next;
			h2 = &(*h2)->next;
		}
		if(flag == 0)
			break;
	}
}

void sort_by_year(struct node_one **tempnode1, struct node_two **tempnode2, int s){   /* This function sorts the nodes according to their years. */
	struct node_one **h1;   /* Create two type node */
	struct node_two **h2;
	int i, j , flag;
	for(i=0; i<=s; i++){
		h1 = tempnode1;
		h2 = tempnode2;
		flag = 0;
		for(j=0; j<(s-1-i); j++){
			struct node_one *p1 = *h1;
			struct node_one *p2 = p1->next;
			struct node_two *d1 = *h2;
			struct node_two *d2 = d1->next;
			if(p1->year > p2->year){     /* If year greater than the other then swap their. */
				*h1 = swap1(p1, p2);
				*h2 = swap2(d1, d2);
				flag = 1;
			}
			h1 = &(*h1)->next;
			h2 = &(*h2)->next;
		}
		if(flag == 0)
			break;
	}
}

void sort_by_score(struct node_one **tempnode1, struct node_two **tempnode2, int s){   /* This function sorts the nodes according to their scores. */
	struct node_one **h1;   /* Create two type node */
	struct node_two **h2;
	int i, j , flag;
	for(i=0; i<=s; i++){
		h1 = tempnode1;
		h2 = tempnode2;
		flag = 0;
		for(j=0; j<(s-1-i); j++){
			struct node_one *p1 = *h1;
			struct node_one *p2 = p1->next;
			struct node_two *d1 = *h2;
			struct node_two *d2 = d1->next;
			if(d1->score > d2->score){     /* If score greater than the other then swap their. */
				*h1 = swap1(p1, p2);
				*h2 = swap2(d1, d2);
				flag = 1;
			}
			h1 = &(*h1)->next;
			h2 = &(*h2)->next;
		}
		if(flag == 0)
			break;
	}
}

void sort_by_name(struct node_one **tempnode1, struct node_two **tempnode2, int s){   /* This function sorts the nodes according to their names. */
	struct node_one **h1;   /* Create two type node */
	struct node_two **h2;
	int i, j , flag;
	for(i=0; i<=s; i++){
		h1 = tempnode1;
		h2 = tempnode2;
		flag = 0;
		for(j=0; j<(s-1-i); j++){
			struct node_one *p1 = *h1;
			struct node_one *p2 = p1->next;
			struct node_two *d1 = *h2;
			struct node_two *d2 = d1->next;
			if(strcmp(p1->name, p2->name) > 0){     /* If name greater than the other then swap their. */
				*h1 = swap1(p1, p2);
				*h2 = swap2(d1, d2);
				flag = 1;
			}
			h1 = &(*h1)->next;
			h2 = &(*h2)->next;
		}
		if(flag == 0)
			break;
	}
}

void sort_by_genre(struct node_one **tempnode1, struct node_two **tempnode2, int s){   /* This function sorts the nodes according to their genres. */
	struct node_one **h1;   /* Create two type node */
	struct node_two **h2;
	int i, j , flag;
	for(i=0; i<=s; i++){
		h1 = tempnode1;
		h2 = tempnode2;
		flag = 0;
		for(j=0; j<(s-1-i); j++){
			struct node_one *p1 = *h1;
			struct node_one *p2 = p1->next;
			struct node_two *d1 = *h2;
			struct node_two *d2 = d1->next;
			if(strcmp(d1->genre, d2->genre) > 0){     /* If genre greater than the other then swap their. */
				*h1 = swap1(p1, p2);
				*h2 = swap2(d1, d2);
				flag = 1;
			}
			h1 = &(*h1)->next;
			h2 = &(*h2)->next;
		}
		if(flag == 0)
			break;
	}
}

void part_1(struct node_one *Movie_Budget, struct node_two *Movie_Name, int s){
/* This part gives an menu to user and then user select one of them then sorts the values according to select of user then prints all of them .*/
	struct node_one *tempnode1 = NULL;
	struct node_two *tempnode2 = NULL;
	int op, num, val, i, v1, v2, x, flag=0;
	double val1, val2;
	while(1){
		tempnode1 = Movie_Budget;   /* Equaled to noble list. */
		tempnode2 = Movie_Name;
		printf("\n1. Budget\n2. Genre\n3. Name\n4. Score\n5. Year\n\n");   /* Prints the menu */
		printf("Please Select an Operation: ");
		scanf("%d", &op);
		printf("\n\n1. Single Selection\n2. Multiple Selection\n\nPlease select an operation: ");
		scanf("%d", &num);
		if(op == 1){   /* If the user select 1 then sorts by the budget. */
			sort_by_budget(&tempnode1, &tempnode2, s);
			if(num == 1){  /* If the user select first option then prints one node. */
				printf("\nEnter value: ");
				scanf("%d", &val);
				for(i=0; i<(val-1); i++){
					tempnode1 = tempnode1->next;
					tempnode2 = tempnode2->next;
				}
				if(tempnode1->budget == 0)
					printf("\n%d.Movie\n\nunknown\t%s\t%s\t%.1lf\t%d\n", val, tempnode2->genre, tempnode1->name, tempnode2->score, tempnode1->year);
				else
					printf("\n%d.Movie\n\n%d\t%s\t%s\t%.1lf\t%d\n", val, tempnode1->budget, tempnode2->genre, tempnode1->name, tempnode2->score, tempnode1->year);	
			}
			else if(num == 2){    /* If the user select second option then wants the starts and end values then prints the nodes. */
				printf("\nEnter start budget value: ");
				scanf("%d", &v1);
				printf("\nEnter end budget value: ");
				scanf("%d", &v2);
				while(1){
					if(tempnode1 == NULL) break;
					if((tempnode1->budget > v1) && (tempnode1->budget < v2)){
						if(tempnode1->budget == 0)
							printf("\nunknown\t\t%-15s\t%-55s\t%9.1lf\t%d", tempnode2->genre, tempnode1->name, tempnode2->score, tempnode1->year);
						else{
							printf("\n%-10d\t%-15s\t%-55s\t%9.1lf\t%d", tempnode1->budget, tempnode2->genre, tempnode1->name, tempnode2->score, 
									tempnode1->year);
						}
					}
					tempnode1 = tempnode1->next;
					tempnode2 = tempnode2->next;
				}
			}
			break;
		}
		else if(op == 2){     /* If the user select 2 then sorts by the genre. */
			sort_by_genre(&tempnode1, &tempnode2, s);
			if(num == 1){   /* If the user select first option then prints one node. */
				printf("\nEnter value: ");
				scanf("%d", &val);
				for(i=0; i<(val-1); i++){
					tempnode1 = tempnode1->next;
					tempnode2 = tempnode2->next;
				}
				if(tempnode1->budget == 0)
					printf("\n%d.Movie\n\nunknown\t%s\t%s\t%.1lf\t%d\n", val, tempnode2->genre, tempnode1->name, tempnode2->score, tempnode1->year);
				else
					printf("\n%d.Movie\n\n%d\t%s\t%s\t%.1lf\t%d\n", val, tempnode1->budget, tempnode2->genre, tempnode1->name, tempnode2->score, tempnode1->year);	
			}
			else if(num == 2){    /* If the user select second option then wants the starts and end values then prints the nodes. */
				printf("\nEnter start value: ");
				scanf("%d", &v1);
				printf("\nEnter end value: ");
				scanf("%d", &v2);
				for(x=0; x<v1; x++){
					tempnode1 = tempnode1->next;
					tempnode2 = tempnode2->next;
				}
				i = v2-v1-1;
				for(x=0; x<i; x++){
					if(tempnode1->budget == 0)
							printf("\nunknown\t\t%-15s\t%-55s\t%9.1lf\t%d", tempnode2->genre, tempnode1->name, tempnode2->score, tempnode1->year);
					else{
						printf("\n%-10d\t%-15s\t%-55s\t%9.1lf\t%d", tempnode1->budget, tempnode2->genre, tempnode1->name, tempnode2->score, 
								tempnode1->year);
					}
					tempnode1 = tempnode1->next;
					tempnode2 = tempnode2->next;
				}
			}
			break;
		}
		else if(op == 3){
			sort_by_name(&tempnode1, &tempnode2, s);
			if(num == 1){   /* If the user select first option then prints one node. */
				printf("\nEnter value: ");
				scanf("%d", &val);
				for(i=0; i<(val-1); i++){
					tempnode1 = tempnode1->next;
					tempnode2 = tempnode2->next;
				}
				if(tempnode1->budget == 0)
					printf("\n%d.Movie\n\nunknown\t%s\t%s\t%.1lf\t%d\n", val, tempnode2->genre, tempnode1->name, tempnode2->score, tempnode1->year);
				else
					printf("\n%d.Movie\n\n%d\t%s\t%s\t%.1lf\t%d\n", val, tempnode1->budget, tempnode2->genre, tempnode1->name, tempnode2->score, tempnode1->year);	
			}
			else if(num == 2){    /* If the user select second option then wants the starts and end values then prints the nodes. */
				printf("\nEnter start value: ");
				scanf("%d", &v1);
				printf("\nEnter end value: ");
				scanf("%d", &v2);
				for(x=0; x<v1; x++){
					tempnode1 = tempnode1->next;
					tempnode2 = tempnode2->next;
				}
				i = v2-v1-1;
				for(x=0; x<i; x++){
					if(tempnode1->budget == 0)
						printf("\nunknown\t\t%-15s\t%-55s\t%9.1lf\t%d", tempnode2->genre, tempnode1->name, tempnode2->score, tempnode1->year);
					else{
						printf("\n%-10d\t%-15s\t%-55s\t%9.1lf\t%d", tempnode1->budget, tempnode2->genre, tempnode1->name, tempnode2->score, 
								tempnode1->year);
					}
					tempnode1 = tempnode1->next;
					tempnode2 = tempnode2->next;
				}
			}
			break;
		}
		else if(op == 4){
			sort_by_score(&tempnode1, &tempnode2, s);
			if(num == 1){    /* If the user select first option then prints one node. */
				printf("\nEnter value: ");
				scanf("%d", &val);
				for(i=0; i<(val-1); i++){
					tempnode1 = tempnode1->next;
					tempnode2 = tempnode2->next;
				}
				if(tempnode1->budget == 0)
					printf("\n%d.Movie\n\nunknown\t%s\t%s\t%.1lf\t%d\n", val, tempnode2->genre, tempnode1->name, tempnode2->score, tempnode1->year);
				else
					printf("\n%d.Movie\n\n%d\t%s\t%s\t%.1lf\t%d\n", val, tempnode1->budget, tempnode2->genre, tempnode1->name, tempnode2->score, tempnode1->year);	
			}
			else if(num == 2){      /* If the user select second option then wants the starts and end values then prints the nodes. */
				printf("\nEnter start score value: ");
				scanf("%lf", &val1);
				printf("\nEnter end score value: ");
				scanf("%lf", &val2);
				while(1){
					if(tempnode1 == NULL) break;
					if((tempnode2->score > val1) && (tempnode2->score < val2)){
						if(tempnode1->budget == 0)
							printf("\nunknown\t\t%-15s\t%-55s\t%9.1lf\t%d", tempnode2->genre, tempnode1->name, tempnode2->score, tempnode1->year);
						else{
							printf("\n%-10d\t%-15s\t%-55s\t%9.1lf\t%d", tempnode1->budget, tempnode2->genre, tempnode1->name, tempnode2->score, 
									tempnode1->year);	
						}
					}
					tempnode1 = tempnode1->next;
					tempnode2 = tempnode2->next;
				}
			}
			break;
		}
		else if(op == 5){
			sort_by_year(&tempnode1, &tempnode2, s);
			if(num == 1){    /* If the user select first option then prints one node. */
				printf("\nEnter value: ");
				scanf("%d", &val);
				for(i=0; i<val; i++){
					tempnode1 = tempnode1->next;
					tempnode2 = tempnode2->next;
				}
				if(tempnode1->budget == 0)
					printf("\n%d.Movie\n\nunknown\t%s\t%s\t%.1lf\t%d\n", val, tempnode2->genre, tempnode1->name, tempnode2->score, tempnode1->year);
				else
					printf("\n%d.Movie\n\n%d\t%s\t%s\t%.1lf\t%d\n", val, tempnode1->budget, tempnode2->genre, tempnode1->name, tempnode2->score, tempnode1->year);	
			}
			else if(num == 2){    /* If the user select second option then wants the starts and end values then prints the nodes. */
				printf("\nEnter start year value: ");
				scanf("%d", &v1);
				printf("\nEnter end year value: ");
				scanf("%d", &v2);
				while(1){
					if(tempnode1 == NULL) break;
					if((tempnode1->year > v1) && (tempnode1->year < v2)){
						if(tempnode1->budget == 0)
							printf("\nunknown\t\t%-15s\t%-55s\t%9.1lf\t%d", tempnode2->genre, tempnode1->name, tempnode2->score, tempnode1->year);
						else{
							printf("\n%-10d\t%-15s\t%-55s\t%9.1lf\t%d", tempnode1->budget, tempnode2->genre, tempnode1->name, tempnode2->score, 
									tempnode1->year);	
						}
					}
					tempnode1 = tempnode1->next;
					tempnode2 = tempnode2->next;
				}
			}
			break;
			/* If the user enters wrong value, then the menu appears again and the user enters another value. */
		}
	}
}

void print_genres(char ** type, int *a){   /* This function prints the genres. */
	int x;
	for(x=0; x<(*a); x++)
		printf("\n%s", type[x]);
	printf("\n\n");
}

void part_3(struct node_one *Movie_Budget){   /* This function wants the exact year from the user and prints the nodes accordig to year. */
	int temp_year, op, flag=0;
	while(1){
		printf("\nEnter a year: ");  /* Wants to year from the user. */
		scanf("%d", &temp_year);
		printf("\nUntil (0) or Since (1) %d: ", temp_year);   /* Wants to option from the user. */
		scanf("%d", &op);
		switch(op){
		case 0:   /* Prints the nodes until the year. */
			while(Movie_Budget != NULL){
				if(Movie_Budget->year < temp_year){
					printf("\n%s", Movie_Budget->name);
					flag=1;
				}
				Movie_Budget = Movie_Budget->next;
			}
			if(flag != 1) printf("\nERROR!! NO VALUE FOR THE CONDITIONS YOU REQUESTED. TRY AGAIN.\n");
			break;
		case 1:      /* Prints the nodes since the year. */
			while(Movie_Budget != NULL){
				if(Movie_Budget->year > temp_year){
					printf("\n%s", Movie_Budget->name);
					flag=1;
				}
				Movie_Budget = Movie_Budget->next;
			}
			if(flag != 1) printf("\nERROR!! NO VALUE FOR THE CONDITIONS YOU REQUESTED. TRY AGAIN.\n");
			break;
		default:    /* If the user enters wrong value then the gives an error message. */
			printf("\nERROR!! YOU ENTERED WRONG NUMBER PLEASE TRY AGAIN.\n");
		}
		if(flag == 1) break;
	}
	printf("\n\n");
}

void part_4(struct node_two *Movie_Name){   /* This function wants the exact score from the user and prints the nodes accordig to score. */
	int op, flag=0;
	double temp_score;
	while(1){
		printf("\nEnter a score: ");  /* Wants to score from the user. */
		scanf("%lf", &temp_score);
		printf("\nUntil (0) or Since (1) %.1lf: ", temp_score);   /* Wants to option from the user. */
		scanf("%d", &op);
		switch(op){
		case 0:   /* Prints the nodes until the score. */
			while(Movie_Name != NULL){
				if(Movie_Name->score < temp_score){
					printf("\n%s", Movie_Name->name);
					flag=1;
				}
				Movie_Name = Movie_Name->next;
			}
			if(flag != 1) printf("\nERROR!! NO VALUE FOR THE CONDITIONS YOU REQUESTED. TRY AGAIN.\n");
			break;
		case 1:       /* Prints the nodes since the score. */
			while(Movie_Name != NULL){
				if(Movie_Name->score > temp_score){
					printf("\n%s", Movie_Name->name);
					flag=1;
				}
				Movie_Name = Movie_Name->next;
			}
			if(flag != 1) printf("\nERROR!! NO VALUE FOR THE CONDITIONS YOU REQUESTED. TRY AGAIN.\n");
			break;
		default:    /* If the user enters wrong value then the gives an error message. */
			printf("\nERROR!! YOU ENTERED WRONG NUMBER PLEASE TRY AGAIN.\n");
		}
		if(flag == 1) break;
	}
	printf("\n\n");
}

void part_5(struct node_one *Movie_Budget, struct node_two *Movie_Name){   /* This function wants the exact name from the user and prints the nodes accordig to name. */
	int x=100, flag=0;
	char *temp_name = (char*)malloc(sizeof(char) * x);
	while(1){
		printf("\nPlease enter the name of the movie: ");  /* Wants to name from the user. */
		scanf(" %[^\n]%*c", temp_name);
		while(Movie_Budget != NULL){
			if(strcmp(temp_name, Movie_Budget->name) == 0){
				if(Movie_Budget->budget == 0)
					printf("\nBudget: unknown\nGenre: %s\nName: %s\nScore: %.1lf\nYear: %d\n", Movie_Name->genre, Movie_Name->name , Movie_Name->score, Movie_Budget->year);
				else
					printf("\nBudget: %d\nGenre: %s\nName: %s\nScore: %.1lf\nYear: %d\n", Movie_Budget->budget, Movie_Name->genre, Movie_Name->name , Movie_Name->score, 							Movie_Budget->year);
				flag=1;
				break;
			}
			Movie_Budget = Movie_Budget->next;  /* It goes to next node. */
			Movie_Name = Movie_Name->next;  /* It goes to next node. */
		}
		if(flag == 1) break;
		else printf("\nERROR!! YOU ENTERED WRONG NAME. PLEASE TRY AGAIN.\n");
	}
	printf("\n\n");
	free(temp_name);
}

void part_6(struct node_two *Movie_Name){  /*This function find the average score of the movies and then prints it. */
	double avr, sum=0;
	int i=0;
	while(Movie_Name != NULL){
		sum = sum + Movie_Name->score;  /* It goes to end of the list and sum all of the values. */
		Movie_Name = Movie_Name->next;
		i++;  /*count*/
	}
	avr = sum/(double)i;    /* And finds average IMBD */
	printf("\nAverage: %lf\n\n", avr);
}

void find_genres(struct node_two *Movie_Name, char ** type, int * arr, int *a){   /* This function find genres in the list and add the 2D array. */
	int i=0, flag=0, x;
	struct node_two *temp2 = NULL;   /* Create a pointer. */
	temp2 = Movie_Name;
	while(temp2 != NULL){  /* It goes to end of the list. */
		flag=0;
		if(i == 0){   /* If it is first node the this condition works. */
			strcpy(type[i], temp2->genre);   /* Add the array. */
			arr[i]++;   /* Increase the array size. */
			i++;
			(*a)++;
		}
		else{
			for(x=0; x<i; x++){
				if(strcmp(type[x], temp2->genre) == 0){   /* If the genre already add the array the just the size increases. */
					arr[x]++;   /* Increase the array size. */
					flag=1;
					break;
				}
			}
			if(flag != 1){  /* If the genre did not add the array then add the 2D array and the array size increases. */
				strcpy(type[i], temp2->genre);   /* Add the array. */
				arr[i]++;   /* Increase the array size. */
				i++;
				(*a)++;
			}
		}
		temp2 = temp2->next;  /* It goes next node. */
	}
}

void part_7(int * arr, char ** type, int *a){   /* This function prints genres and their quantities. */
	int x;
	for(x=0; x<(*a); x++)
		printf("\n%-10s\t%15d", type[x], arr[x]);
	printf("\n");
}

int main(){
	FILE *fp;  /* Create file pointer. */
	struct node_one* Movie_Budget=NULL;   /* Create first type link list pointer. */
	struct node_two* Movie_Name=NULL;    /* Create second type link list pointer. */
	int t=100, op, row=50, a=0, i, s=0;
	int len=300, tempi=150, c1;
	double n;
	char *line = (char*)malloc(sizeof(char) * len);   /* Here I created the neccessery variables. */
	char *temp = (char*)malloc(sizeof(char) * tempi);
	char *temp3 = (char*)malloc(sizeof(char) * tempi);
	char *tempfname = (char*)malloc(sizeof(char) * t);
	int *arr = (int*)malloc(tempi * sizeof(int));
	char **type = malloc(row * sizeof(char *));  /* Create 2D array and mallocall elements one by one. */
	for(i=0; i<row; i++)
		type[i] = malloc(row * sizeof(char));
	printf("\nPLEASE WAIT A BIT FOR THE MENU TO APPEAR.\n");
	printf("\nEnter your file name: ");   /* Takes filename. */
	scanf("%s", tempfname);
	char *filename = malloc(sizeof(char) * (strlen(tempfname)+1));   /*And arrange the exact file name. */
	strcpy(filename, tempfname);
	if((fp = fopen(filename, "r")) == NULL){   /* If the file is not opened gives an error message. */
		printf("\nERROR THE FILE IS NOT OPENED!!!\n");
		exit(1);
	}
	fgets(line, len, fp);   /* Takes first line */
	while(fgets(line, len, fp) != NULL){   /* Takes the values line by line until end of the file. */
		struct node_one *temp1 = (struct node_one*)malloc(sizeof(struct node_one));   /* Malloc to fist type pointer. */
		struct node_two *temp2 = (struct node_two*)malloc(sizeof(struct node_two));   /* Malloc to second type pointer. */
		temp = strtok(line, ",");
		n = strtod(temp, &temp3);
		temp1->budget = (int)n;   /* Typecast double to integer. */
		temp = strtok(NULL, ",");
		temp2->genre = malloc(sizeof(char) * (strlen(temp)+1));   /* Arrange to size of the genre. */
		strcpy(temp2->genre, temp);
		temp = strtok(NULL, ",");
		temp1->name = malloc(sizeof(char) * (strlen(temp)+1));   /* Arrange to size of the name. */
		temp2->name = malloc(sizeof(char) * (strlen(temp)+1));   /* Arrange to size of the name. */
		strcpy(temp1->name, temp);
		strcpy(temp2->name, temp);
		temp = strtok(NULL, ",");
		temp2->score = strtod(temp, &temp3);
		temp = strtok(NULL, ",");
		n = strtod(temp, &temp3);
		temp1->year = (int)n;
		temp1->next = NULL;
		temp2->next = NULL;
		c1 = control(Movie_Budget, Movie_Name, temp1, temp2);   /* It controls if the name exists before and takes the signal. */
		if(c1 != 1) {
			insert(&Movie_Budget, &Movie_Name, temp1, temp2);  /* If not exists then goes to insert function. */
			s++;   /* And count increases. */
		}
		else sort(&Movie_Budget, &Movie_Name, s);  /* If exists then goes to sort function. */
	}
	find_genres(Movie_Name, type, arr, &a);  /* Goes to find genre function. */
	while(1){    /* Prints the menu. */
		printf("\n1. List of the Sorted Data\n2. List of the Genres\n3. List of the Movie Through the Years\n");
		printf("4. List of the Movie Through the Scores\n5. All Information of a Single Movie\n6. Average of the IMBD Scores\n");
		printf("7. Frequence of the Genres\n8. Exit\n\nPlease select an operation: ");
		scanf("%d", &op);
		if(op == 1) part_1(Movie_Budget, Movie_Name, s);
		else if(op == 2) print_genres(type, &a);
		else if(op == 3) part_3(Movie_Budget);
		else if(op == 4) part_4(Movie_Name);
		else if(op == 5) part_5(Movie_Budget, Movie_Name);
		else if(op == 6) part_6(Movie_Name);
		else if(op == 7) part_7(arr, type, &a);
		else if(op == 8) break; 
		else printf("\nTRY AGAIN\n");
	}
	fclose(fp);	/*and free the all the vlues. */
	free(tempfname);
	free(line);
	free_list_1(Movie_Budget);
	free_list_2(Movie_Name);
}
