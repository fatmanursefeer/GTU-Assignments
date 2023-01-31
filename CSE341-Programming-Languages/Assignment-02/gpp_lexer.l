%{
	#include <stdio.h>
	#include <string.h>
	int open_counter = 0;
%}



COMMENT ";;".*
VALUEI "0"|[1-9][0-9]*
VALUEF [1-9]+[f][1-9]+
IDENTIFIER [a-zA-Z][a-zA-Z0-9_]*
ERROR [0-9][a-zA-Z0-9]*
VALUESTR ["](.*?)["]
EXIT "\n\n"


%%

"and" { printf("and: KW_AND\n"); }
"or" { printf("or: KW_OR\n"); }
"not" { printf("not: KW_NOT\n"); }
"equal" { printf("equal: KW_EQUAL\n"); } 
"less" { printf("less: KW_LESS\n"); }
"nil" { printf("nil: KW_NIL\n"); }
"list" { printf("list: KW_LIST\n"); }
"append" { printf("append: KW_APPEND\n"); }
"concat" { printf("concat: KW_CONCAT\n"); }
"set" { printf("set: KW_SET\n"); }
"deffun" { printf("deffun: KW_DEFFUN\n"); }
"for" { printf("for: KW_FOR\n"); }
"if" { printf("if: KW_IF\n"); }
"exit" { printf("exit: KW_EXIT\n"); return 0; }
"load" { printf("load: KW_LOAD\n"); }
"disp" { printf("disp: KW_DISP\n"); }
"true" { printf("true: KW_TRUE\n"); }
"false" { printf("false: KW_FALSE\n"); }

"+" { printf("+ : OP_PLUS\n"); }
"-" { printf("- : OP_MINUS\n"); }
"/" { printf("/ : OP_DIV\n"); }
"*" { printf("* : OP_MULT\n"); }
"(" { printf("( : OP_OP\n"); }
")" { printf(") : OP_CP\n"); } 
"**" { printf("** : OP_DBLMULT\n"); }
"," { printf(", : OP_COMMA\n"); }
" \" " { 
		printf("\" : OP_"); 
	      	if (open_counter == 0) { 
	      		printf("OC\n"); open_counter = 1; 
	      	}
		else { 
			printf("CC\n"); open_counter = 0; 
		}
    }
    
{COMMENT} { printf ("%s: COMMENT\n", yytext); }
{VALUEI} { printf("%s: VALUEI\n", yytext); }
{VALUEF} { printf("%s: VALUEF\n", yytext); }
{IDENTIFIER} { printf("%s: IDENTIFIER\n", yytext); }
{ERROR}  { 
		printf ("LEXICAL ERROR %s cannot be tokenized \n",yytext); 
		return 0;
	 }
{EXIT} {
        	return 0;
       }
{VALUESTR} { 
		int counter;
		int size = strlen(yytext);
		printf("\" : OP_OC\n"); 
		for(counter = 1; counter < size-1; counter++)
			printf("%c", yytext[counter]);
		printf(": VALUESTR\n\" : OP_CC\n"); 
	}

"\n"|"\t"|" " { }		// ignore newlines, tabs and spaces

. { 
    printf ("LEXICAL ERROR %s cannot be tokenized \n",yytext); 
    return 0;
  }
  
  
%%

int yywrap() {}

int main(int argc , char** argv)
{
	FILE *fptr;
	if (argc < 2){  
		printf("Press two enters to exit\n");
    	} 
    	else 
    	{
        	fptr = fopen(argv[1], "r");
        	yyin = fptr;;
    	}
	yylex();
    	return 0;
}

