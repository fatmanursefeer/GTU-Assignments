%{
	#include "y.tab.h"
	void yyerror(char *);
%}


%%

"and" { return KW_AND; }
"or" { return KW_OR; }
"not" { return KW_NOT; }
"equal" { return KW_EQUAL; } 
"gt" { return KW_GT; }
"set" { return KW_SET; }
"defvar" { return KW_DEFVAR; }
"deffun" { return KW_DEFFUN; }
"while" { return KW_WHILE; }
"if" { return KW_IF; }
"true" { return KW_TRUE; }
"false" { return KW_FALSE; }
"exit" { return KW_EXIT; } 
"list" { return KW_LIST; }

"+" { return OP_PLUS; }
"-" { return OP_MINUS; }
"/" { return OP_DIV; }
"*" { return OP_MULT; }
"(" { return OP_OP; }
")" { return OP_CP; }
"," { return OP_COMMA; }

";".* return COMMENT;
[%.&|\\$#£€₺!?\{\}\[\]~=] {yyerror("SYNTAX_ERROR Expression not recognized");}
[_a-zA-Z][_a-zA-Z0-9]* {strcpy(yylval.id, yytext); return IDENTIFIER;}
[0-9]+[f][1-9][0-9]* {strcpy(yylval.real, yytext); return VALUEF;}
[0] {yyerror("SYNTAX_ERROR Expression not recognized");}
[0][0-9]* {yyerror("SYNTAX_ERROR! IT IS INVALID VALUE (leading 0)");}
[0-9]* {yyerror("SYNTAX_ERROR Expression not recognized");}
[0-9]+[_a-zA-Z][_a-zA-Z]* {yyerror("SYNTAX_ERROR! IT IS INVALID IDENTIFIER(leading digit)");}
"\n\n" {yyerror("Have a nice day!");}
[ \t\n] ;

  
%%

int yywrap() { return 1; }

