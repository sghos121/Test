/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 69 "parser.y"

    #include <string>
    #include <vector>
    #include "matrix.h"

#line 55 "parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUMBER = 258,                  /* NUMBER  */
    TRUE = 259,                    /* TRUE  */
    FALSE = 260,                   /* FALSE  */
    IDENTIFIER = 261,              /* IDENTIFIER  */
    STRING = 262,                  /* STRING  */
    IF = 263,                      /* IF  */
    THEN = 264,                    /* THEN  */
    ELSE = 265,                    /* ELSE  */
    FOR = 266,                     /* FOR  */
    WHILE = 267,                   /* WHILE  */
    PRINT = 268,                   /* PRINT  */
    MATRIX_KEYWORD = 269,          /* MATRIX_KEYWORD  */
    OR = 270,                      /* OR  */
    AND = 271,                     /* AND  */
    NOT = 272,                     /* NOT  */
    PLUS = 273,                    /* PLUS  */
    MINUS = 274,                   /* MINUS  */
    TIMES = 275,                   /* TIMES  */
    DIVIDE = 276,                  /* DIVIDE  */
    ELEMENT_TIMES = 277,           /* ELEMENT_TIMES  */
    ASSIGN = 278,                  /* ASSIGN  */
    EQ = 279,                      /* EQ  */
    NEQ = 280,                     /* NEQ  */
    LT = 281,                      /* LT  */
    GT = 282,                      /* GT  */
    LTE = 283,                     /* LTE  */
    GTE = 284,                     /* GTE  */
    TERNARY_IF = 285,              /* TERNARY_IF  */
    TERNARY_ELSE = 286,            /* TERNARY_ELSE  */
    LPAREN = 287,                  /* LPAREN  */
    RPAREN = 288,                  /* RPAREN  */
    LBRACE = 289,                  /* LBRACE  */
    RBRACE = 290,                  /* RBRACE  */
    LBRACKET = 291,                /* LBRACKET  */
    RBRACKET = 292,                /* RBRACKET  */
    SEMICOLON = 293,               /* SEMICOLON  */
    COMMA = 294,                   /* COMMA  */
    LOWEST = 295,                  /* LOWEST  */
    TERNARY_PREC = 296,            /* TERNARY_PREC  */
    UMINUS = 297,                  /* UMINUS  */
    UNOT = 298                     /* UNOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 75 "parser.y"

    double numVal;
    bool boolVal;
    std::string* strVal;
    Matrix* matrixVal;
    struct Value* val;
    std::vector<struct Value*>* valList;

#line 124 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
