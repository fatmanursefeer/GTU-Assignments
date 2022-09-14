#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{  /* Here I created struct */
	char country[20];
	char capital[20];
	int population;
	bool driving_side;
	struct node *next;
};

void enter_new_record(struct node **node_one){  /* This function works to add new node. */
	int b;
	if(*node_one == NULL){  /* If node is null then take the front. */
		struct node* new_node = (struct node*)calloc(1, sizeof(node));  /*Makes a new node dynamically. */
		printf("\nCountry name: ");   /* Takes the informations from the user one by one. */
		scanf("%s", new_node->country);
		printf("\nCapital: ");
		scanf("%s", new_node->capital);
		printf("\nPopulation of %s: ",new_node->country);
		scanf("%s", &new_node->population);
		printf("\nDo people in %s drive on the right side? (Yes:1, No:0): ", new_node->country);
		scanf("%d", &b);
		new_node->driving_side = b;
		new_node->next = *node_one;   /*And it goes to like this. */
		(*node_one) = new_node;
	}
	else{
		struct node *temp;  /* If node not null then this condition works. */
		temp = *node_one;
		struct node* new_node = (struct node*)calloc(1, sizeof(node));  /*Makes a new node dynamically. */
		printf("\nCountry name: ");    /* Takes the informations from the user one by one. */
		scanf("%s", new_node->country);
		printf("\nCapital: ");
		scanf("%s", new_node->capital);
		printf("\nPopulation of %s: ",new_node->country);
		scanf("%d", &new_node->population);
		printf("\nDo people in %s drive on the right side? (Yes:1, No:0): ", new_node->country);
		scanf("%d", &b);
		new_node->driving_side = b;
		new_node->next = NULL;
		while(temp->next != NULL)   /* It goes to end of the linked list and then add the new node. */
			temp = temp->next;
		temp->next = new_node;
	}
}


void write_to_the_file(struct node *node_one){   /* This function works to write the nodes. */
	FILE *fp;
	char filename[20];
	printf("\nFile name: ");
	scanf("%s", filename);
	if((fp = fopen(filename, "w")) == NULL){   /* If file is not opened gives an erroe message. */
		printf("\nERROR THE FILE IS NOT OPENED!!!\n");
		exit(1);
	}
	while(node_one != NULL){   /* If file is opens the informations inside the linked list writes one by one. */
		if(node_one->driving_side == true)
			fprintf(fp, "%s\t%s\t%d\tRight\n", node_one->country, node_one->capital, node_one->population);
		else
			fprintf(fp, "%s\t%s\t%d\tLeft\n", node_one->country, node_one->capital, node_one->population);
		node_one = node_one->next;
	}
	fclose(fp);   /* And file closed. */
}

void read_from_the_file(struct node **temp_node){   /* This function works to read the file. */
	
	FILE *fp;
	char filename[20], temp[20], line[100], temp3[20];
	int n, t=0;
	printf("\nFile name: ");
	scanf("%s", filename);
	if((fp = fopen(filename, "r")) == NULL){    /* If file is not opened gives an erroe message. */
		printf("\nERROR THE FILE IS NOT OPENED!!!\n");
		exit(1);
	}
	while(fgets(line, 100, fp) != NULL){   /* If file opens then the informations in the file takes one by one and adds the nodes. */
		temp = strtok(line, " ");
		struct node *temp_1 = (struct node*)calloc(1, sizeof(struct node));
		strcpy(temp_1->country, temp);
		temp = strtok(NULL, " ");
		strcpy(temp_1->capital, temp);
		temp =  strtok(NULL, " ");
		n = strtod(temp, &temp3);
		temp_1->population = (int)n;
		temp =  strtok(NULL, " ");
		n = strtod(temp, &temp3);
		temp_1->driving_side= (int)n;
		if(t == 0){
			temp_1->next = *temp_node;   /* If node is null this condition works. */
			(*temp_node) = temp_1;
		}
		else{
			temp_1->next = NULL;
			(*temp_node)->next = temp_1;   /* If not this condition works. */
			(*temp_node) = (*temp_node)->next;
		}
		t++;
	}
	fclose(fp);   /* And file closed. */
}

void print_the_linked_list(struct node *temp_node){   /* This function prints the node the takes from the file. */
	while(temp_node != NULL){
		if(temp_node->driving_side == true)   /* All the nodes writes one by one until node will be null .*/
			printf("\nCountry:\t%s\tCapital:\t%s\tPopulation:\t%d\tDriving Side: Right\n", temp_node->country, temp_node->capital, temp_node->population);
		else
			printf("\nCountry:\t%s\tCapital:\t%s\tPopulation:\t%d\tDriving Side: Left\n", temp_node->country, temp_node->capital, temp_node->population);
		temp_node = temp_node->next;
	}
}


int main(){
	int op, size = 1;
	struct node* node_one = NULL;
	struct node* temp_node = NULL;
	while(1){   /* This loop works until the user enters 5. */
		printf("\n------MENU------\n1. Enter new record\n2. Write to the file\n3. Read from the file\n4. Print the linked list\n5. Exit\nYour Choise: ");
		scanf("%d", &op);
		if(op == 1) enter_new_record(&node_one);
		else if(op == 2) write_to_the_file(node_one);
		else if(op == 3) read_from_the_file(&temp_node);
		else if(op = 4) print_the_linked_list(temp_node);
		else if(op == 5) break;
		else printf("\nERROR!! YOU ENTERED WRONG NUMBER. PLEASE TRY AGAIN.\n");
	}
}
