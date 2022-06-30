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

#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    LE = 259,                      /* LE  */
    GE = 260,                      /* GE  */
    EQ = 261,                      /* EQ  */
    NE = 262,                      /* NE  */
    ADD = 263,                     /* ADD  */
    SUB = 264,                     /* SUB  */
    MUL = 265,                     /* MUL  */
    DIV = 266,                     /* DIV  */
    BOOL = 267,                    /* BOOL  */
    BREAK = 268,                   /* BREAK  */
    CHAR = 269,                    /* CHAR  */
    CASE = 270,                    /* CASE  */
    CLASS = 271,                   /* CLASS  */
    CONTINUE = 272,                /* CONTINUE  */
    DECLARE = 273,                 /* DECLARE  */
    DO = 274,                      /* DO  */
    ELSE = 275,                    /* ELSE  */
    EXIT = 276,                    /* EXIT  */
    FALSE = 277,                   /* FALSE  */
    FLOAT = 278,                   /* FLOAT  */
    FOR = 279,                     /* FOR  */
    FUN = 280,                     /* FUN  */
    IF = 281,                      /* IF  */
    IN = 282,                      /* IN  */
    INT = 283,                     /* INT  */
    LOOP = 284,                    /* LOOP  */
    PRINT = 285,                   /* PRINT  */
    PRINTLN = 286,                 /* PRINTLN  */
    RANGE = 287,                   /* RANGE  */
    RETURN = 288,                  /* RETURN  */
    STRING = 289,                  /* STRING  */
    VAL = 290,                     /* VAL  */
    VAR = 291,                     /* VAR  */
    WHILE = 292,                   /* WHILE  */
    BOOL_LITERAL = 293,            /* BOOL_LITERAL  */
    REAL_LITERAL = 294,            /* REAL_LITERAL  */
    STRING_LITERAL = 295,          /* STRING_LITERAL  */
    INT_LITERAL = 296,             /* INT_LITERAL  */
    UNARY_MINUS = 297              /* UNARY_MINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ID 258
#define LE 259
#define GE 260
#define EQ 261
#define NE 262
#define ADD 263
#define SUB 264
#define MUL 265
#define DIV 266
#define BOOL 267
#define BREAK 268
#define CHAR 269
#define CASE 270
#define CLASS 271
#define CONTINUE 272
#define DECLARE 273
#define DO 274
#define ELSE 275
#define EXIT 276
#define FALSE 277
#define FLOAT 278
#define FOR 279
#define FUN 280
#define IF 281
#define IN 282
#define INT 283
#define LOOP 284
#define PRINT 285
#define PRINTLN 286
#define RANGE 287
#define RETURN 288
#define STRING 289
#define VAL 290
#define VAR 291
#define WHILE 292
#define BOOL_LITERAL 293
#define REAL_LITERAL 294
#define STRING_LITERAL 295
#define INT_LITERAL 296
#define UNARY_MINUS 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 46 "parser.y"

    int integer_value;
    string *string_value;
    bool boolean_value;
    double double_value;
    identifierData* data;
    int data_type;

#line 160 "y.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */
