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
    DOWNTO = 258,                  /* DOWNTO  */
    UMINUS = 259,                  /* UMINUS  */
    PROGRAM = 260,                 /* PROGRAM  */
    ID = 261,                      /* ID  */
    SC = 262,                      /* SC  */
    TYPE = 263,                    /* TYPE  */
    EQ = 264,                      /* EQ  */
    ARR = 265,                     /* ARR  */
    OF = 266,                      /* OF  */
    COMMENT = 267,                 /* COMMENT  */
    COLON = 268,                   /* COLON  */
    BEG = 269,                     /* BEG  */
    READ = 270,                    /* READ  */
    OB = 271,                      /* OB  */
    CB = 272,                      /* CB  */
    WRITE = 273,                   /* WRITE  */
    STRING = 274,                  /* STRING  */
    COMMA = 275,                   /* COMMA  */
    FOR = 276,                     /* FOR  */
    ASSIGN = 277,                  /* ASSIGN  */
    DO = 278,                      /* DO  */
    INT_LITERAL = 279,             /* INT_LITERAL  */
    REAL_LITERAL = 280,            /* REAL_LITERAL  */
    BOOLEAN_LITERAL = 281,         /* BOOLEAN_LITERAL  */
    CHAR_LITERAL = 282,            /* CHAR_LITERAL  */
    VAR = 283,                     /* VAR  */
    NOTEQ = 284,                   /* NOTEQ  */
    LT = 285,                      /* LT  */
    GT = 286,                      /* GT  */
    GTEQ = 287,                    /* GTEQ  */
    LTEQ = 288,                    /* LTEQ  */
    PLUS = 289,                    /* PLUS  */
    MINUS = 290,                   /* MINUS  */
    MUL = 291,                     /* MUL  */
    DIV = 292,                     /* DIV  */
    MOD = 293,                     /* MOD  */
    AND = 294,                     /* AND  */
    OR = 295,                      /* OR  */
    NOT = 296,                     /* NOT  */
    IF = 297,                      /* IF  */
    THEN = 298,                    /* THEN  */
    ELSE = 299,                    /* ELSE  */
    END = 300,                     /* END  */
    DOT = 301,                     /* DOT  */
    INT = 302,                     /* INT  */
    REAL = 303,                    /* REAL  */
    CHAR = 304,                    /* CHAR  */
    BOOLEAN = 305,                 /* BOOLEAN  */
    TO = 306,                      /* TO  */
    WHILE = 307,                   /* WHILE  */
    ARRAY = 308,                   /* ARRAY  */
    OPENBRAC = 309,                /* OPENBRAC  */
    CLOSEBRAC = 310,               /* CLOSEBRAC  */
    OPENPARA = 311,                /* OPENPARA  */
    CLOSEPARA = 312                /* CLOSEPARA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define DOWNTO 258
#define UMINUS 259
#define PROGRAM 260
#define ID 261
#define SC 262
#define TYPE 263
#define EQ 264
#define ARR 265
#define OF 266
#define COMMENT 267
#define COLON 268
#define BEG 269
#define READ 270
#define OB 271
#define CB 272
#define WRITE 273
#define STRING 274
#define COMMA 275
#define FOR 276
#define ASSIGN 277
#define DO 278
#define INT_LITERAL 279
#define REAL_LITERAL 280
#define BOOLEAN_LITERAL 281
#define CHAR_LITERAL 282
#define VAR 283
#define NOTEQ 284
#define LT 285
#define GT 286
#define GTEQ 287
#define LTEQ 288
#define PLUS 289
#define MINUS 290
#define MUL 291
#define DIV 292
#define MOD 293
#define AND 294
#define OR 295
#define NOT 296
#define IF 297
#define THEN 298
#define ELSE 299
#define END 300
#define DOT 301
#define INT 302
#define REAL 303
#define CHAR 304
#define BOOLEAN 305
#define TO 306
#define WHILE 307
#define ARRAY 308
#define OPENBRAC 309
#define CLOSEBRAC 310
#define OPENPARA 311
#define CLOSEPARA 312

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 66 "VAPS5421.y"

    char* lexeme;

#line 185 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
