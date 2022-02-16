%option noyywrap
%option yylineno

%{
#include <string.h>
#include <stdlib.h> 
#include <string>
#include "Parser.tab.hpp"

const std::string error_alert = "\x1b[31merror\x1b[0m: ";
%}

IDENTIFIER              [_a-z]
DIGIT                   -?[0-9]
PUNCT                   [\[\]\:\;\,] 

%x COMMENT

%%
"VAR"               { return VAR; }
"BEGIN"                    { return _BEGIN; }
"END"                   { return END; }

"READ"                  { return READ; }
"WRITE"                 { return WRITE; }

"IF"                    { return IF; }
"THEN"                  { return THEN; }
"ELSE"                  { return ELSE; }
"ENDIF"                 { return ENDIF; }

"WHILE"                 { return WHILE; }
"DO"                    { return DO; }
"ENDWHILE"              { return ENDWHILE; }

"REPEAT"                { return REPEAT; }
"UNTIL"                 { return UNTIL; }

"FOR"                   { return FOR; }
"FROM"                  { return FROM; }
"TO"                    { return TO; }
"DOWNTO"                { return DOWNTO; }
"ENDFOR"                { return ENDFOR; }

"ASSIGN"                    { return ASSIGN; }

"EQ"                     { return EQ; }
"NEQ"                     { return NEQ; }
"GE"                     { return GE; }
"LE"                     { return LE; }
"GEQ"                     { return GEQ; }
"LEQ"                     { return LEQ; }

"PLUS"                     { return PLUS; }
"DIV"                     { return DIV; }
"MINUS"                     { return MINUS; }
"TIMES"                     { return TIMES; }
"MOD"                     { return MOD; }
{IDENTIFIER}+           { 
                            yylval.pidentifier = new std::string(yytext);
                            return pidentifier;
                        }
{DIGIT}+                { yylval.num = std::stoll(yytext); return num; }
{PUNCT}                 { return yytext[0]; }
\(.*\)                  { /*ignore comments TODO: changed*/ }
"("                     { BEGIN(COMMENT); }
<COMMENT>{
    [^\)]               ;
    ")"                 BEGIN(INITIAL);
}

[ \t\r\n]+                { /*ignore whitespaces*/ }
.                       { return ERROR; }
%%
