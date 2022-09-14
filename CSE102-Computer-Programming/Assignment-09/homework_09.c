#include <stdio.h>
#include <string.h>

typedef struct{  /* I created structure here. */
	char name[20];
	int age;
	int label;
} customer;


void print_current_sequence(customer * a, int counter){  /* This function prints current sequence. */
	int i;
	if(counter == 0)
		printf("\nCurrent Sequence: ");  /* If sequence is null just prints the 'current sequence'. */
	else{
		printf("\nCurrent Sequence: ");  /* If not, prints the current sequence. */
		for(i=0; i<counter; i++)
			printf("%d ", a[i].label);
	}
}


void sort_current_sequence(customer * a, int counter, int x){   /* This function sorts the current sequence according to priorities. after the overflows. */
	customer temp;  /* I create temp structure. */
	int i, j;
	if(x > 1){  /* The number x starts from the new row is created, and how many numbers are. */ 
		for(i=0; i<(x-1); i++){   /* This function almost the same as upper function except parameters. */
			for(j=(counter-x); j < (counter-1); j++){
				if(a[j].label > a[j+1].label){  /* If a[j] greater than a[j+1] then the datas in a[j+1] */
					strcpy(temp.name, a[j].name);  /* Datas in a[j] are copy to the temp structure. */
					temp.age = a[j].age;
					temp.label = a[j].label;
					strcpy(a[j].name, a[j+1].name);  /* Datas in a[j+1] are copy to a[j] */
					a[j].age = a[j+1].age;
					a[j].label = a[j+1].label;
					strcpy(a[j+1].name, temp.name);  /* Datas in the temp structure are copy to a[j+1] */
					a[j+1].age = temp.age;
					a[j+1].label = temp.label;
				}
			}
		}
	}
}
 
/* NOTE: I do my code like this: When there is an overflow on any label, it creates a new order to the continuation of the old row and continues the order accordingly. Like this:
**  0-1-1-1-2 => 0-1-1-1-2-1 => 0-1-1-1-2-1-2 => 0-1-1-1-2-0-1-2 => 0-1-1-1-2-0-1-1-2 => 0-1-1-1-2-0-1-1-1-2 => 0-1-1-1-2-0-1-1-1-2-1 => 0-1-1-1-2-0-1-1-1-2-1-3 and it goes like this.
**  The PDF do not say anything about this subject, so I wrote my code in this way. */
int main(){
	customer cust[50];	/* I created a structure array of size 50 because than 50 people. */
	int ext=0, counter=0, i, j;
	int q0=0, q1=0, q2=0, q3=0, q4=0, q=0;
	printf("\n************Banking System************\n");
	while(1){	/* I created infinite loop because the user enters the value again and again. */
		print_current_sequence(cust, counter);	/* I printed the current sequence. */
		printf("\n1-Add customer\n2-Process customer\n(If do you want to leave please enter -1)\n");
		scanf("%d", &ext);
		if(ext == -1) break;	/* If the user enters -1 the infinite loops terminates. */
		else if(ext == 1){	/* If the user wants to add customer the following operations occur. */
			if(counter>=50)
				printf("\nYOU ARE EXCEED THE LIMIT. PLEASE PROCESS THE CUSTOMER.\n");
			else{
				printf("\nPlease enter the name of the customer: ");	/* Takes the name. */
				scanf("%s", cust[counter].name);
				printf("\nPlease enter the age of the customer: ");	/* Takes the age. */
				scanf("%d", &cust[counter].age);
				printf("\nPlease enter the label of the customer: ");    /* Takes the label. */
				scanf("%d", &cust[counter].label);
				counter++;	/* And then counter is increased. */
				q++;
				if(cust[counter-1].label == 0) q0++;   /* If label is equal to 0 the counter q0 is increasing. */
				else if(cust[counter-1].label == 1) q1++;   /* If label is equal to 1 the counter q1 is increasing. */
				else if(cust[counter-1].label == 2) q2++;   /* If label is equal to 2 the counter q2 is increasing. */
				else if(cust[counter-1].label == 3) q3++;   /* If label is equal to 3 the counter q3 is increasing. */
				else if(cust[counter-1].label == 4) q4++;   /* If label is equal to 4 the counter q4 is increasing. */
				if((q0 <= 5) && (q1 <= 3) && (q2 <= 3) && (q3 <= 2) && (q4 <= 2))
						sort_current_sequence(cust, counter, q);
				else{   /* If overflow occurs once. */
					q=1, q0=0, q1=0, q2=0, q3=0, q4=0;
					if(cust[counter-1].label == 0) q0++;   /* If label is equal to 0 the counter q0 is increasing. */
					else if(cust[counter-1].label == 1) q1++;   /* If label is equal to 1 the counter q1 is increasing. */
					else if(cust[counter-1].label == 2) q2++;   /* If label is equal to 2 the counter q2 is increasing. */
					else if(cust[counter-1].label == 3) q3++;   /* If label is equal to 3 the counter q3 is increasing. */
					else if(cust[counter-1].label == 4) q4++;   /* If label is equal to 4 the counter q4 is increasing. */
					sort_current_sequence(cust, counter, q);	
				}
			}
		}
		else if(ext == 2){	/* If the user wants to process customer the following operations occur. */
			if(counter == 0)
				printf("\nThere is not any customer in bank system sequence.\n");	/* If sequence is null prints messaje. */
			else{
				printf("\nProceed customer is %s \n", cust[0].name);	/* If not, the customer proceses. */
				for(i=0; i < (counter-1); i++){
					strcpy(cust[i].name, cust[i+1].name);  /* And the elements in the array are transferred to a front. */
					cust[i].age = cust[i+1].age;
					cust[i].label = cust[i+1].label;
				}
				counter--;	/* The size of the array is reduced by one. */
			}
		}
		else
			printf("\nYou entered wrong number please try again!!\n");	/* If enters integer different from the 1 and 2 prints an error message. */
	}
}
