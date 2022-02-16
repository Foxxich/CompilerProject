all: lex.yy.c Parser.tab.hpp Parser.tab.cpp main

lex.yy.c:
	lex Lexer.l 
Simple.tab.hpp Simple.tab.cpp:
	bison -d Parser.ypp
main:
	g++ -o compiler Parser.tab.cpp Parser.tab.hpp lex.yy.c -std=c++17 --pedantic -Wall -Wextra