#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{   /* Here I created my struct. */
	char title[50], author[50], subject[100];
	int year;
} Book;


int main(){
	Book *lib, *lib2;  /* There is two pointer because of increasing size of the array. */
	int num, num2, i=0, j, k, flag, years[50], temp;   /* I assigned the my variables.*/
	char books_title[50], books_author[50], books_subject[100];
	lib = (Book *)calloc(100, sizeof(Book));   /* Firstly I use calloc here. */
	lib2 = (Book *)calloc(1000, sizeof(Book));  /* I use calloc here too because of the exceed of the array size. */
	while(1){  /* I created while loop */
		if(i > 100)
			*lib2 = *lib;  /* If there is oversize this is happen. */
		printf("\nMENU\n");
		printf("\t1. Add New Book\n\t2. List Books\n\t3. EXIT\n");
		printf("Choose: ");
		scanf("%d", &num);
		if(num == 1){   /* If the user enter the 1 the computer gives values. */
			printf("\n*****************************\n");
			printf("\nPlease Enter Book Title = ");
			scanf("%s", lib[i].title);
			printf("\nPlease enter book author = ");
			scanf("%s", lib[i].author);
			printf("\nPlease enter book subject = ");
			scanf("%s", lib[i].subject);
			printf("\nPlease enter book year = ");
			scanf("%d", &lib[i].year);
			i++;
		}
		else if(num == 2){  /* If the user enter the 2, submenu is there. */
			while(1){  /* I created infinite while loop. */
				printf("\n*************************\n");
				printf("\nSUBMENU\n");
				printf("\t1. Get by Title\n\t2. Get by Author\n\t3. Get by Subject\n\t4. Sorted List by Year (DESC)\n\t5. List All Books\n\t6. EXIT SUBMENU\nChoose = ");
				scanf("%d", &num2);
				if(num2 == 1){   /* If the user enter 1 the computer recevie book title from the user and comparison that the other books. */
					printf("\nEnter a books title = ");
					scanf("%s", books_title);
					flag=0;
					for(j=0; j<i; j++){
						if((strcmp(lib[j].title, books_title)) == 0){   /* If there exist the books informations will be writing. */
							printf("\nBook Found\n");
							printf("Title => %s\nAuthor => %s\nSubject => %s\nYear => %d\n", lib[j].title, lib[j].author, lib[j].subject, lib[j].year);
							flag=1;
						}
					}
					if(flag != 1)   /* If not the message is writing. */
						printf("\nThe book does not found\n");
				}
				else if(num2 == 2){   /* If the user enter 2 the computer recevie book author from the user and comparison that the other books. */
					flag = 0;
					printf("\nEnter a books Author = ");
					scanf("%s", books_author);
					for(j=0; j<i; j++){
						if((strcmp(lib[j].author, books_author)) == 0){    /* If there exist the books informations will be writing. */
							printf("\nBook Found\n");
							printf("Title => %s\nAuthor => %s\nSubject => %s\nYear => %d\n", lib[j].title, lib[j].author, lib[j].subject, lib[j].year);
							flag=1;
						}
					}
					if(flag != 1)   /* If not the message is writing. */
						printf("\nThe book does not found\n");
				}
				else if(num2 == 3){    /* If the user enter 3 the computer recevie book subject from the user and comparison that the other books. */
					flag = 0;
					printf("\nEnter a books Subject = ");
					scanf("%s", books_subject);
					for(j=0; j<i; j++){
						if((strcmp(lib[j].subject, books_subject)) == 0){     /* If there exist the books informations will be writing. */
							printf("\nBook Found\n");
							printf("Title => %s\nAuthor => %s\nSubject => %s\nYear => %d\n", lib[j].title, lib[j].author, lib[j].subject, lib[j].year);
							flag=1;
						}
					}
					if(flag != 1)     /* If not the message is writing. */
						printf("\nThe book does not found\n");
				}
				else if(num2 == 4){   /* If the user enter 4, computer sorted the books to decreasig line of the years. */
					for(j=0; j<i; j++)
						years[j] = lib[j].year;   /* Here I assigned the years lib.year to new array. */
					for(j=0; j<i; j++){
						for(k=0; k<i; k++){   /* And I sorted to the decreasing year. */
							if(years[j] > years[k]){
								temp = years[j];
								years[j] = years[k];
								years[k] = temp;
							}
						}
					}
					for(j=0, k=0; j<i; j++){   /* And finally I writed to all of them. */
						if(years[k] == lib[j].year){
							printf("\nList of Books\n********************************\n");
							printf("%d. Book\nTitle => %s\nAuthor => %s\nSubject => %s\nYear => %d\n", k+1, lib[j].title, lib[j].author, lib[j].subject, lib[j].year);
							k++;
						}
					}
				}
				else if (num2 == 5){   /* If the user enter 5, computer sorted the books to the enter time. */
					printf("\n*********************************\nLists of Books\n***********************************\n");
					for(j=0; j<i; j++){
						printf("%d. Book;\nTitle => %s\nAuthor => %s\nSubject => %s\nYear => %d\n", j+1, lib[j].title, lib[j].author, lib[j].subject, lib[j].year);
						printf("\n***********************************\n");
					}
				}
				else if(num2 == 6) break;  /* If the user enter 6, the while loop is breaking and the main menu writing. */
				else printf("\nTRY AGAIN\n");  /* If the user enter orter then uppers the error message. */
			}
		}
		else if(num == 3) break;    /* If the user enter 3, the while loop is breaking. */
		else printf("\nTRY AGAIN\n");   /* If the user enter orter then uppers the error message. */
	}
	
}
