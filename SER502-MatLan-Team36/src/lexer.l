%{
    #include "parser.tab.h"
    #include "utils.h"
    #include <iostream>
    #include <string>
    #include <vector>
    using namespace std;

    extern void yyerror(const char* s);
%}

%option noyywrap

DIGIT      [0-9]
NUMBER     {DIGIT}+(\.{DIGIT}+)?([Ee][+-]?{DIGIT}+)?
LETTER     [a-zA-Z]
IDENTIFIER {LETTER}({LETTER}|{DIGIT})*
WHITESPACE [ \t\n]+
COMMENT    "//".*

%%

{WHITESPACE}  { /* skip whitespace */ }
{COMMENT}     { /* skip comments */ }

"true"       { yylval.boolVal = true; return TRUE; }
"false"      { yylval.boolVal = false; return FALSE; }

"if"         { return IF; }
"then"       { return THEN; }
"else"       { return ELSE; }
"for"        { return FOR; }
"while"      { return WHILE; }
"print"      { return PRINT; }
"matrix"     { return MATRIX_KEYWORD; }
"or"         { return OR; }
"and"         { return AND; }
"not"        { return NOT; }

"+"          { return PLUS; }
"-"          { return MINUS; }
"*"          { return TIMES; }
"/"          { return DIVIDE; }
".*"         { return ELEMENT_TIMES; }
"="          { return ASSIGN; }
"=="         { return EQ; }
"!="         { return NEQ; }
"<"          { return LT; }
">"          { return GT; }
"<="         { return LTE; }
">="         { return GTE; }
"\?"         { return TERNARY_IF; }
":"          { return TERNARY_ELSE; }

"("          { return LPAREN; }
")"          { return RPAREN; }
"{"          { return LBRACE; }
"}"          { return RBRACE; }
"["          { return LBRACKET; }
"]"          { return RBRACKET; }
";"          { return SEMICOLON; }
","          { return COMMA; }

{NUMBER}     { yylval.numVal = stringToDouble(yytext); return NUMBER; }
{IDENTIFIER} { yylval.strVal = new std::string(yytext); return IDENTIFIER; }
\"[^"]*\"    {
                yylval.strVal = new std::string(yytext + 1, yyleng - 2); // Remove quotes
                return STRING;
             }

<<EOF>>      { return YYEOF; }

.            { yyerror(string("Unexpected character: ").append(yytext).c_str()); }

%%