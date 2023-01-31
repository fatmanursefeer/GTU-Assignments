flags = -g
exec = gpp_lexer

$(exec).out: lex.yy.c y.tab.c
	gcc $(flags) lex.yy.c y.tab.c gpp_interpreter.c -o output.out -lm

y.tab.c: gpp_interpreter.y
	yacc -d gpp_interpreter.y

lex.yy.c: $(exec).l
	flex $(exec).l

clean: 
	rm -rf lex.yy.c y.tab.c y.tab.h $(exec).out $(exec).dSYM
