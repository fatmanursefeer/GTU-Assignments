#include <stdio.h>    
#include <stdlib.h>    
#include <string.h>    
#include <ctype.h>
#include <math.h>
#include "gpp_interpreter.h"

listIdentifier* ids = NULL;

// this function converts the number float to string like 2/1 => 2f1
void covertFloatToStr(float number) {
	char arr[100];
	char nArr1[100], nArr2[100], nArr3[100] = "";
	int i, j, length, len1=0, len2=0, ten1=1, ten2=1, num1=0, temp, t, flag=0;
	sprintf(arr, "%g", number);
	length = strlen(arr);
	for(i=0; i<length; i++) {
		if(arr[i] == '-')
			flag = 1;
	}
	if(flag == 0)
		len1 = length - 2;
	else
		len1 = length - 3;
	for(i=0; i<length; i++) {
		if(arr[i] == '-')
			continue;
		if(arr[i] == '.')
			len2 = 0;
		len2++;
	}
	len2--;
	for(i=0; i<len1; i++)
		ten1 = ten1 * 10;
	for(i=0; i<len2; i++)
		ten2 = ten2 * 10;
	for(i=0; i<length; i++){
		if(arr[i] == '-')
			continue;
		if(arr[i] == '.')
			continue;
		t = arr[i] - '0';
		temp = t * ten1;
		num1 = num1 + temp;
		ten1 = ten1 / 10;
	}
	if(flag == 1)
		strcat(nArr3, "-");
	sprintf(nArr1, "%d", num1);
	strcat(nArr3, nArr1);
	strcat(nArr3, "f");
	sprintf(nArr2, "%d", ten2);
	strcat(nArr3, nArr2);
	printf("Syntax OK.\nResult: %s\n", nArr3);
}

// this function prints the list
void writeList(float *list) {
    int temp = 1;
    if(list != NULL){
        printf("(");
        while(temp < list[0]){
            printf("%lf ",list[temp]);
            temp++;
        }
        printf("%lf)",list[temp]);
        printf("\n");
    } else {
        printf("()\n");
    }
}

// this function checks the id is in the already in the list or not
int occurs(char* idVal) {
    int temp = 0;
    listIdentifier* current = ids;
    while(current != NULL) {
        if(strcmp(current->id, idVal) == 0) {
            return temp;
        }
        temp++;
        current = current->following;
    }
    return -1;
}

// this function takes an id value
float takeIdentifier(char* idVal) {
    int temp = occurs(idVal);
    listIdentifier* newIdList = ids;
    if(temp == -1) {
        printf("ERROR!! IDENTIFIER NOT FOUND\n");
        exit(-1);
    }   
    for(int i = 0; i < temp; i++) {
        newIdList = newIdList->following;
    }
    return newIdList->arg;
}

//this function takes the string value and converts it float 
float takeFloatVal(char* real) {
	int i, length, j, k;
	float f1, f2, number;
	char temp [100];
	length = strlen(real);
	for(i=0; i<length; i++) {
		if(real[i] == 'f') {
			for(j=0; j<i; j++)
				temp[j] = real[j];
			break;
		}
	}
	f1 = atof(temp);
	j=0;
	for(k=i+1; k<length; k++){
		temp[j] = real[k];
		j++;
	}
	f2 = atof(temp);
	number = f1/f2;
	return number;
}

// this function retuns a listIdentifier value
listIdentifier* buildListId(float fNumber, char* idVal) {
    listIdentifier* newList = (listIdentifier*)malloc(sizeof(listIdentifier));
    strcpy(newList->id, idVal);
    newList->arg = fNumber;
    newList->following = NULL;
    return newList;
}

//this function sets the new id value and its float value
void setVal(char* id, float newVal) {
    int temp = occurs(id);
    listIdentifier* newIdList = ids;
    if(newIdList == NULL) {
        ids = buildListId(newVal, id);
    }
    else {
        if(temp != -1) {
            for(int i = 0; i < temp; i++) {
                newIdList = newIdList->following;
            }
            newIdList->arg = newVal;
        }
        else {
            while(newIdList->following != NULL) {
                newIdList = newIdList->following;
            }
            newIdList->following = (listIdentifier*)malloc(sizeof(listIdentifier));
            newIdList->following->following = NULL;
            strcpy(newIdList->following->id, id);
            newIdList->following->arg = newVal;
        }
    }
}

// this function takes to float list and prints them
int boolList2(int boolean, float *list1, float *list2){
    if(boolean != 1)
        writeList(list2);
    else
        writeList(list1);
    return 0;
}

// this function takes one float list and prints it
int boolList(int boolean, float *list){
    if(list[0] == 2){
        if(boolean != 1)
            return list[2];
        else
            return list[1];
    }
    else if(list[0] == 1){
        if(boolean != 1)
            return 0;
        else
            return list[1];
    }
    else
        return 0;
}

// this function takes float list and prints it 
void defOfFunc(float* list){
    writeList(list);
}

// this fuction create a list
float* actualList(float val){
    float *number = (float *) malloc(2*sizeof(float));
    number[0] = 1;
    number[1] = val;
    return number;
}

// this function takes a list and create another list
float* actualList2(float* list,float val){
    float *number = (float *) malloc((2+list[0])*sizeof(float));
    number[0] = list[0] + 1;
    int i = 1;
    while(i < number[0]){
        number[i] = list[i];
        i++;
    }
    number[i] = val;
    return number;
}


