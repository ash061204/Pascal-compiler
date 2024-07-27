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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    PROG = 258,                    /* PROG  */
    NUL = 259,                     /* NUL  */
    DOWNTO = 260,                  /* DOWNTO  */
    UMINUS = 261,                  /* UMINUS  */
    PROGRAM = 262,                 /* PROGRAM  */
    SC = 263,                      /* SC  */
    TYPE = 264,                    /* TYPE  */
    EQ = 265,                      /* EQ  */
    OF = 266,                      /* OF  */
    COMMENT = 267,                 /* COMMENT  */
    COLON = 268,                   /* COLON  */
    BEG = 269,                     /* BEG  */
    READ = 270,                    /* READ  */
    OB = 271,                      /* OB  */
    CB = 272,                      /* CB  */
    WRITE = 273,                   /* WRITE  */
    COMMA = 274,                   /* COMMA  */
    FOR = 275,                     /* FOR  */
    ASSIGN = 276,                  /* ASSIGN  */
    DO = 277,                      /* DO  */
    VAR = 278,                     /* VAR  */
    NOTEQ = 279,                   /* NOTEQ  */
    LT = 280,                      /* LT  */
    GT = 281,                      /* GT  */
    GTEQ = 282,                    /* GTEQ  */
    LTEQ = 283,                    /* LTEQ  */
    PLUS = 284,                    /* PLUS  */
    MINUS = 285,                   /* MINUS  */
    MUL = 286,                     /* MUL  */
    DIV = 287,                     /* DIV  */
    MOD = 288,                     /* MOD  */
    AND = 289,                     /* AND  */
    OR = 290,                      /* OR  */
    NOT = 291,                     /* NOT  */
    IF = 292,                      /* IF  */
    THEN = 293,                    /* THEN  */
    ELSE = 294,                    /* ELSE  */
    END = 295,                     /* END  */
    DOT = 296,                     /* DOT  */
    INT = 297,                     /* INT  */
    REAL = 298,                    /* REAL  */
    CHAR = 299,                    /* CHAR  */
    BOOLEAN = 300,                 /* BOOLEAN  */
    TO = 301,                      /* TO  */
    WHILE = 302,                   /* WHILE  */
    ARRAY = 303,                   /* ARRAY  */
    OPENBRAC = 304,                /* OPENBRAC  */
    CLOSEBRAC = 305,               /* CLOSEBRAC  */
    OPENPARA = 306,                /* OPENPARA  */
    CLOSEPARA = 307,               /* CLOSEPARA  */
    ARR = 308,                     /* ARR  */
    ID = 309,                      /* ID  */
    INT_LITERAL = 310,             /* INT_LITERAL  */
    STRING = 311,                  /* STRING  */
    CHAR_LITERAL = 312,            /* CHAR_LITERAL  */
    REAL_LITERAL = 313,            /* REAL_LITERAL  */
    BOOLEAN_LITERAL = 314          /* BOOLEAN_LITERAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define PROG 258
#define NUL 259
#define DOWNTO 260
#define UMINUS 261
#define PROGRAM 262
#define SC 263
#define TYPE 264
#define EQ 265
#define OF 266
#define COMMENT 267
#define COLON 268
#define BEG 269
#define READ 270
#define OB 271
#define CB 272
#define WRITE 273
#define COMMA 274
#define FOR 275
#define ASSIGN 276
#define DO 277
#define VAR 278
#define NOTEQ 279
#define LT 280
#define GT 281
#define GTEQ 282
#define LTEQ 283
#define PLUS 284
#define MINUS 285
#define MUL 286
#define DIV 287
#define MOD 288
#define AND 289
#define OR 290
#define NOT 291
#define IF 292
#define THEN 293
#define ELSE 294
#define END 295
#define DOT 296
#define INT 297
#define REAL 298
#define CHAR 299
#define BOOLEAN 300
#define TO 301
#define WHILE 302
#define ARRAY 303
#define OPENBRAC 304
#define CLOSEBRAC 305
#define OPENPARA 306
#define CLOSEPARA 307
#define ARR 308
#define ID 309
#define INT_LITERAL 310
#define STRING 311
#define CHAR_LITERAL 312
#define REAL_LITERAL 313
#define BOOLEAN_LITERAL 314

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "VAPS5421.y"

    int ival;
    nodeType *nPtr;
    char string[100];

#line 191 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
