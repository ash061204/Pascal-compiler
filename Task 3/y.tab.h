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
    SC = 261,                      /* SC  */
    TYPE = 262,                    /* TYPE  */
    EQ = 263,                      /* EQ  */
    OF = 264,                      /* OF  */
    COMMENT = 265,                 /* COMMENT  */
    COLON = 266,                   /* COLON  */
    BEG = 267,                     /* BEG  */
    READ = 268,                    /* READ  */
    OB = 269,                      /* OB  */
    CB = 270,                      /* CB  */
    WRITE = 271,                   /* WRITE  */
    STRING = 272,                  /* STRING  */
    COMMA = 273,                   /* COMMA  */
    FOR = 274,                     /* FOR  */
    ASSIGN = 275,                  /* ASSIGN  */
    DO = 276,                      /* DO  */
    INT_LITERAL = 277,             /* INT_LITERAL  */
    REAL_LITERAL = 278,            /* REAL_LITERAL  */
    CHAR_LITERAL = 279,            /* CHAR_LITERAL  */
    VAR = 280,                     /* VAR  */
    NOTEQ = 281,                   /* NOTEQ  */
    LT = 282,                      /* LT  */
    GT = 283,                      /* GT  */
    GTEQ = 284,                    /* GTEQ  */
    LTEQ = 285,                    /* LTEQ  */
    PLUS = 286,                    /* PLUS  */
    MINUS = 287,                   /* MINUS  */
    MUL = 288,                     /* MUL  */
    DIV = 289,                     /* DIV  */
    MOD = 290,                     /* MOD  */
    AND = 291,                     /* AND  */
    OR = 292,                      /* OR  */
    NOT = 293,                     /* NOT  */
    IF = 294,                      /* IF  */
    THEN = 295,                    /* THEN  */
    ELSE = 296,                    /* ELSE  */
    END = 297,                     /* END  */
    DOT = 298,                     /* DOT  */
    INT = 299,                     /* INT  */
    REAL = 300,                    /* REAL  */
    CHAR = 301,                    /* CHAR  */
    BOOLEAN = 302,                 /* BOOLEAN  */
    TO = 303,                      /* TO  */
    WHILE = 304,                   /* WHILE  */
    ARRAY = 305,                   /* ARRAY  */
    OPENBRAC = 306,                /* OPENBRAC  */
    CLOSEBRAC = 307,               /* CLOSEBRAC  */
    OPENPARA = 308,                /* OPENPARA  */
    CLOSEPARA = 309,               /* CLOSEPARA  */
    ID = 310,                      /* ID  */
    ARR = 311                      /* ARR  */
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
#define SC 261
#define TYPE 262
#define EQ 263
#define OF 264
#define COMMENT 265
#define COLON 266
#define BEG 267
#define READ 268
#define OB 269
#define CB 270
#define WRITE 271
#define STRING 272
#define COMMA 273
#define FOR 274
#define ASSIGN 275
#define DO 276
#define INT_LITERAL 277
#define REAL_LITERAL 278
#define CHAR_LITERAL 279
#define VAR 280
#define NOTEQ 281
#define LT 282
#define GT 283
#define GTEQ 284
#define LTEQ 285
#define PLUS 286
#define MINUS 287
#define MUL 288
#define DIV 289
#define MOD 290
#define AND 291
#define OR 292
#define NOT 293
#define IF 294
#define THEN 295
#define ELSE 296
#define END 297
#define DOT 298
#define INT 299
#define REAL 300
#define CHAR 301
#define BOOLEAN 302
#define TO 303
#define WHILE 304
#define ARRAY 305
#define OPENBRAC 306
#define CLOSEBRAC 307
#define OPENPARA 308
#define CLOSEPARA 309
#define ID 310
#define ARR 311

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 302 "VAPS5421.y"

    struct{
        char type[10];
       
        union{
            int ival;
            float fval;
            char cval;
        }v;
    }t;
#line 313 "VAPS5421.y"

    char *strval;

#line 194 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
