#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Teacher I made the txt files and the parts I wrote in C before I get caught covid-19, so I could not continue, because of my illness, so I just throw away the parts I made. */

struct synonym{
	char word[50];
	char synm1[50];
	char synm2[50];
	struct synonym *next;
};

struct antonym{
	char word[50];
	char antm1[50];
	char antm2[50];
	struct antonym *next;
};

void antm_q(struct antonym *p2){
	char temp[50];
	char temp2[50];
	int l, i, j, op=0,a;
	while(op != 1){
		a = rand()%1000;
		for(i=0; i<a; i++)
			p2 = p2->next;
		printf("\nWhat is the antonym of the %s", p2->word);
		scanf("%s", temp);
		l = strlen(p2->antm1);
		i = strncmp(p2->antm1, temp, l-1);
		l  = strlen(p2->antm2);
		j = strncmp(p2->antm2, temp, l-1);
		if((i == 0) && (j == 0))
			printf("\nYour answer is true");
		else
			printf("\nYour answer is wrong the true is %s or %s", p2->antm1, p2->antm2);
	}
}

void synm_q(struct synonym *p1){
	char temp[50];
	char temp2[50];
	int l, i, j, op=0, a;
	while(op != 1){
		a = rand()%1000;
		for(i=0; i<a; i++)
			p1 = p1->next;
		printf("\nWhat is the antonym of the %s", p1->word);
		scanf("%s", temp);
		l = strlen(p1->synm1);
		i = strncmp(p1->synm1, temp, l-1);
		l  = strlen(p1->synm2);
		j = strncmp(p1->synm2, temp, l-1);
		if((i == 0) && (j == 0))
			printf("\nYour answer is true");
		else
			printf("\nYour answer is wrong the true is %s or %s", p1->synm1, p1->synm2);
	}
}

int main(){
	FILE *fp, *fp2;
	char buff[50];
	struct synonym* p1=NULL;
	struct antonym* p2=NULL;   
	fp = fopen("ac.txt", "r");
	while(fscanf(fp, "%s", buff) != EOF){
		   strcpy(p1->word, buff);
		   fscanf(fp, "%s", buff);
		   strcpy(p1->synm1, buff);
		   fscanf(fp, "%s", buff);
		   strcpy(p1->synm2, buff);
		   p1 = p1->next;
	}	
	fclose(fp);
	fp2 = fopen("ac.txt", "r");
	while(fscanf(fp2, "%s", buff) != EOF){
		   strcpy(p2->word, buff);
		   fscanf(fp2, "%s", buff);
		   strcpy(p2->antm1, buff);
		   fscanf(fp2, "%s", buff);
		   strcpy(p2->antm2, buff);
		   p2 = p2->next;
	}	
	fclose(fp2);
}
