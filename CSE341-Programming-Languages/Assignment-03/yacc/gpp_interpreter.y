%{ 
#include <stdio.h>    
#include <stdlib.h>    
#include <string.h>    
#include <ctype.h>
#include <math.h>
#include "gpp_interpreter.h"
int yylex(void);
void yyerror (const char* s);
%}

%union {
	float number;
	char id[100]; 
	char real[100];
	float *array;
}

%start START

%token KW_AND KW_OR KW_NOT KW_EQUAL KW_GT KW_SET KW_DEFVAR KW_DEFFUN KW_WHILE KW_IF KW_TRUE KW_FALSE KW_EXIT KW_LIST COMMENT;
%token OP_PLUS OP_MINUS OP_DIV OP_MULT OP_OP OP_CP OP_COMMA;

%token <real> VALUEF
%token <id> IDENTIFIER
%type <number> EXP
%type <number> EXPB
%type <number> FUNCTION
%type <array> NUMBERS
%type <array> EXPLIST

%%

START: EXP { covertFloatToStr($1); }
| START EXP { covertFloatToStr($2); }
| EXPB { if($1 == 1){printf("true\n");} else{printf("false\n");} }
| START EXPB { if($2 == 1){printf("true\n");} else{printf("false\n");} }
| EXPLIST { writeList($1); }
| START EXPLIST { writeList($2); }
| FUNCTION { covertFloatToStr($1); }
| START FUNCTION { covertFloatToStr($2); }
| COMMENT { printf("Syntax OK. This is comment\n"); }
| START COMMENT { printf("Syntax OK. This is comment\n"); }
| OP_OP KW_EXIT OP_CP { exit(1); }
| START OP_OP KW_EXIT OP_CP { exit(1); }
;
EXP: OP_OP OP_PLUS EXP EXP OP_CP { $$ = $3 + $4; }
| OP_OP OP_MINUS EXP EXP OP_CP { $$ = $3 - $4; }
| OP_OP OP_MULT EXP EXP OP_CP { $$ = $3 * $4; }
| OP_OP OP_DIV EXP EXP OP_CP { $$ = $3 / $4; }
| IDENTIFIER { $$ = takeIdentifier($1); }
| VALUEF { $$ = takeFloatVal($1); }
| OP_OP KW_SET IDENTIFIER EXP OP_CP { $$ = $4; setVal($3, $4); }
| OP_OP KW_IF EXPB EXPLIST EXPLIST OP_CP { $$ = boolList2($3, $4, $5); }
| OP_OP KW_WHILE EXPB EXPLIST OP_CP { $$ = boolList($3, $4); }
| OP_OP KW_DEFVAR IDENTIFIER EXP OP_CP { $$ = $4; setVal($3, $4); }
;
EXPB: OP_OP KW_EQUAL EXP EXP OP_CP { $$ = ($3 == $4); }
| OP_OP KW_GT EXP EXP OP_CP { $$ = ($3 > $4); }
| KW_TRUE { $$ = 1; }
| KW_FALSE { $$ = 0; }
| OP_OP KW_AND EXPB EXPB OP_CP { $$ = $3 && $4; }
| OP_OP KW_OR EXPB EXPB OP_CP { $$ = $3 || $4; }
| OP_OP KW_NOT EXPB OP_CP { $$ = !$3; }
;
EXPLIST: OP_OP KW_LIST OP_CP { $$ = NULL; }
| OP_OP KW_LIST NUMBERS OP_CP { $$ = $3; }
;
FUNCTION: OP_OP KW_DEFFUN IDENTIFIER EXPLIST OP_CP { defOfFunc($4); }
| OP_OP KW_DEFFUN IDENTIFIER OP_OP IDENTIFIER OP_CP EXPLIST OP_CP { defOfFunc($7); }
| OP_OP KW_DEFFUN IDENTIFIER OP_OP IDENTIFIER IDENTIFIER OP_CP EXPLIST OP_CP { defOfFunc($8); }
| OP_OP KW_DEFFUN IDENTIFIER OP_OP IDENTIFIER IDENTIFIER IDENTIFIER OP_CP EXPLIST OP_CP { defOfFunc($9); }
| OP_OP KW_DEFFUN IDENTIFIER OP_OP IDENTIFIER IDENTIFIER IDENTIFIER IDENTIFIER OP_CP EXPLIST OP_CP { defOfFunc($10); }
;
NUMBERS: EXP { $$ = actualList($1); }
| NUMBERS EXP { $$ = actualList2($1, $2); }
;

%%

int main(int argc, char** argv){
    yyparse();
}

void yyerror(const char *s){
    printf ("%s\n", s);
    exit(0);
}
