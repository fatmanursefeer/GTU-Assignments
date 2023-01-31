#ifndef __GPP_INTERPRETER_H__
#define __GPP_INTERPRETER_H__

typedef struct floatVal{
    struct floatVal* following;
    float arg; 
}listFloat;

typedef struct ids{
    struct ids* following;
    char id[20];
    float arg;
}listIdentifier;

void covertFloatToStr(float number);
void writeList(float* list);
int occurs(char* idVal);
float takeIdentifier(char* idVal);
float takeFloatVal(char* real);
listIdentifier* buildListId(float fNumber, char* idVal);
void setVal(char* id, float newVal);
int boolList2(int boolean, float* list1, float* list3);
int boolList(int boolean, float* list);
void defOfFunc(float* list);
float* actualList(float val);
float* actualList2(float* list,float val);

#endif
