#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{
    int data;
    float number;
    char* name;
    struct node *next;
};


void insert_end(struct node **head, int val, float num, char* name_)
{
    //create a new node
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->number = num;
    newNode->name = name_;
    newNode->next = NULL;

    //if head is NULL, it is an empty list
    if(*head == NULL)
         *head = newNode;
    //Otherwise, find the last node and add the newNode
    else
    {
        struct node *lastNode = *head;

        //last node's next address will be NULL.
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        //add the newNode at the end of the linked list
        lastNode->next = newNode;
    }

}

void printList_withLoop(struct node *head)
{
	//iterate the entire linked list and print the data with loop
	while(head != NULL){
		printf("%d->%lf->%s,\n", head->data, head->number, head->name);
		head = head->next;
	}
}

void printList_withRecursive(struct node *list) {
	//iterate the entire linked list and print the data with recursive
	if(list != NULL){
		printf("%d->%lf->%s, ", list->data, list->number, list->name);
		printList_withRecursive(list->next);
	}
}


void sortedInsert(struct node** head_ref, struct node* new_node)
{
	// Sort according to string into the node struct.
	// It's name is "name".
	// You will sort ascending order.
	struct node *temp1, *temp2, *temp3;
	if((*head_ref) == NULL || strcmp((*head_ref)->name, new_node->name)>0){
		temp1 = malloc(sizeof(struct node));
		temp1->data = new_node->data;
		temp1->number = new_node->number;
		temp1->name = new_node->name;
		temp1->next = *head_ref;
		*head_ref = temp1;
	}
	else{
		temp2 = *head_ref;
		temp3 = temp2->next;
		while(temp2 != NULL && temp3 != NULL && !((strcmp(temp2->name, new_node->name)<0) && (strcmp(temp3->name, new_node->name)>0))){
			temp2 = temp3;
			temp3 = temp2->next;
		}
		temp1 = malloc(sizeof(struct node));
		temp2->next = temp1;
		temp1->data = new_node->data;
		temp1->number = new_node->number;
		temp1->name = temp1->name;
		temp1->next = temp3;
	}
}
 
 
/* A utility function to create a new node */
struct node* newNode(int new_data, float num, char* name_)
{
	/* allocate node */
	struct node *temp = malloc(sizeof(struct node));
	/* put in the data  */
	temp->data = new_data;
	temp->number = num;
	temp->name = name_;
	temp->next = NULL;
	return temp;
}


bool search(struct node* head, int x)
{
	// Search according to "data" which defined in node struct.
	// You will control x number comparision with "data" which struct element.
	if(head == NULL) return false;
	if(head->data == x) return true;
	return search(head->next, x);
	
}

int main()
{
     struct node *head = NULL;

     insert_end(&head,10,5.5,"hello1");
     insert_end(&head,20,5.5,"hello2");
     insert_end(&head,30,5.5,"hello3");

     printf("Print List with Loop: \n");
     printList_withLoop(head);
     
     struct node* new_node = newNode(1,5.5, "a");
    // sortedInsert(&head, new_node);

     
     new_node = newNode(3,5.5, "c");
    // sortedInsert(&head, new_node);

     
     new_node = newNode(2,5.5, "d");
   //  sortedInsert(&head, new_node);
     
     new_node = newNode(2,5.5, "b");
    // sortedInsert(&head, new_node);
     
     printf("Print List with Recursive: \n");
     printf("[");
     printList_withRecursive(head);
     printf("]");
	 
	 printf("\nIs 20 belong this linked list?: " );
     printf(search(head, 20) ? "YES \n" : "NO \n");
     
     printf("\nIs 18 belong this linked list?: " );
     printf(search(head, 18) ? "YES \n" : "NO \n");


     return 0;
}
