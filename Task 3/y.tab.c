/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "VAPS5421.y"

    #include<math.h>
    #include<string.h>
    #include<stdio.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include <stdbool.h>
    #include "symbol_table.h"
    #include "shared_var.h"
    int yo=0;
    int checking=0;
    struct symbolTable table[1000];
    char final_dec_var[1000][50];
    char declared_var[1000][50];
    char declared_type[1000][50];
    int counter=0;
    int count=0;
    int i_value[1000];
    char varLater[1000][50];
    int float_value[1000]={0.0};
   char char_value[1000];
    
    int int_value[1000]={0};
    int initialised[1000] ={0};
    void checkMulDec();
    void printTable();
    void assignType();
    void checkBeforeDec();
     void findId(char* name);
     char* findType(char* variableName);
      float fans = 0.0;
      int ians = 0;
    int x=0;
    void printTable() {
 printf("Symbol Table:\n");
 printf("%d\n",i);
         printf("%-15s %-40s %s\n", "Line Number", "Lexeme", "Token");
         for (int j = 0; j <i; j++) {
                printf("%-15d %-40s %s\n", table[j].line_number, table[j].lexeme, table[j].token);
    }
}
void checkMulDec()
{
   //printf("checking mul dec\n");
  for(int ff=0;ff<1000;ff++)
     char_value[ff]='@';
 for(int j=0;j<i;j++ )
 {
    if(strcasecmp(table[j].lexeme,"BEGIN")==0 ||strcmp(table[j].lexeme,"begin")==0 || strcmp(table[j].lexeme,"Begin")==0  )
        {yo=j;break;}
    if(strcmp(table[j].token,"IDENTIFIER")==0)
    {
        strcpy(declared_var[count],table[j].lexeme);
        i_value[count]=j;
        count++;
    }
 }
 for (int l = 0; l < count; ++l) {
        for (int m = l + 1; m < count; ++m) {
            if (strcasecmp(declared_var[l], declared_var[m]) == 0) {
                printf("Multiple declarations of a varible named %s\n", declared_var[l]);
                checking=1;
                break; 
            }
        }
    }

}
void assignType()
{
        //printf("assigning types to the var\n");
        for(int j=1;j<count;j++)
        {
            int yup=0;
            for(int l=i_value[j];l<i;l++)
            {
                int start,final;
                 if(strcasecmp(table[l].lexeme,"array")==0)
                 {
                    yup=1;
                    //strcpy(final_dec_var[counter], declared_var[j]);
                    //char_value[counter]='$';
                       //counter++;

                    start=atoi(table[l+2].lexeme);
                    final=atoi(table[l+5].lexeme);
                    for(int k=start;k<=final;k++)
                    {
                     char concatenated_string[100];
                    sprintf(concatenated_string, "%s[%d]", declared_var[j], k);
                    strcpy(final_dec_var[counter], concatenated_string);
                       counter++;
                    }

                 }  
                if(strcmp(table[l].lexeme,";")==0)
                {
                    if(yup==1)
                    {
                            for(int k=counter-final;k<counter;k++)
                            {
                                strcpy(declared_type[k],table[l-1].lexeme);
                                
                            }
                            break;
                    }
                    else{
                    strcpy(final_dec_var[counter],declared_var[j]);
                    strcpy(declared_type[counter],table[l-1].lexeme);
                    counter++;
                    break;
                    }
                }
            }
        }

   // for(int k=0;k<counter;k++)
   // {
     //   printf(final_dec_var[k]);printf(" ");printf(declared_type[k]);printf(" %d ",int_value[k]);printf("%c ",char_value[k]);printf("%f \n",float_value[k]);
   // }
        
}
int isIdPresent(char* name)
{
    int xx=0;
     for (int k = 0; k < counter; k++) {
        if (strcasecmp(final_dec_var[k], name) == 0)
        xx=1;
     }
     if(xx==1)
        return 1;
    else
        return 0;
}
void findId(char* name)
{
    //printf(name);
    int xx=0;
     for (int k = 0; k < counter; k++) {
        if (strcasecmp(final_dec_var[k], name) == 0)
        xx=1;
     }
     if(xx==0)
     {
         printf("Undeclared variable %s\n",name);
    checking=1;
     }
}
void checkBeforeDec()
{
    int c=0;
        for(int j=yo;j<i;j++)
        {
            if(strcasecmp(table[j].token,"IDENTIFIER")==0)
            {
                strcpy(varLater[c],table[j].lexeme);
                c++;
            }
        }
    for(int j=0;j<c;j++)
   {
    bool hehe=false;
           for(int l=0;l<counter;l++)
           {
                if(strcasecmp(varLater[j],final_dec_var[l])==0)
                {
                    hehe=true;
                    break;
                }
           }
           if(hehe==false)
           {
            printf("Undeclared variable %s",varLater[j]);
            checking=1;
            printf("\n");
           }
   }
}
float getrealVal(char *name)
{
     for(int k=0;k<counter;k++)
    {
       // printf(final_dec_var[k]);printf(" ");printf(declared_type[k]);printf("\n");
       if(strcasecmp(final_dec_var[k],name)==0)
       {
            return float_value[k];
       }
     }
     return 0.0;
}
int getintVal(char *name)
{
     for(int k=0;k<counter;k++)
    {
       // printf(final_dec_var[k]);printf(" ");printf(declared_type[k]);printf("\n");
       if(strcasecmp(final_dec_var[k],name)==0)
       {
            return int_value[k];
       }
     }
     return 0;
}
void initialize(char* name)
{
     for(int k=0;k<counter;k++)
     {
        if(strcasecmp(final_dec_var[k],name)==0)
            initialised[k]=1;
     }
}
int checkIn(char* name)
{
    for(int k=0;k<counter;k++)
     {
        if(strcasecmp(final_dec_var[k],name)==0)
           return initialised[k];
     }
}
void insertintValue(char* name, int ival)
{
     for(int k=0;k<counter;k++)
    {
       // printf(final_dec_var[k]);printf(" ");printf(declared_type[k]);printf("\n");
       if(strcasecmp(final_dec_var[k],name)==0)
       {
        
            int_value[k]=ival;
        

       }
     }
}
void insertcharValue(char* name, char cval)
{
     for(int k=0;k<counter;k++)
    {
       // printf(final_dec_var[k]);printf(" ");printf(declared_type[k]);printf("\n");
       if(strcasecmp(final_dec_var[k],name)==0)
       {
        
            char_value[k]=cval;
        

       }
     }
}
void insertrealValue(char* name, float fval)
{
     for(int k=0;k<counter;k++)
    {
       // printf(final_dec_var[k]);printf(" ");printf(declared_type[k]);printf("\n");
       if(strcasecmp(final_dec_var[k],name)==0)
       {
        
            float_value[k]=fval;
        

       }
     }
}
char getcharVal(char *name)
{
     for(int k=0;k<counter;k++)
    {
       // printf(final_dec_var[k]);printf(" ");printf(declared_type[k]);printf("\n");
       if(strcasecmp(final_dec_var[k],name)==0)
       {
            return char_value[k];
       }
     }
     return '\0';
}
char* findType(char* name) {
  
    int k;
    for (k = 0; k < counter; k++) {
        if (strcasecmp(final_dec_var[k], name) == 0) {
    

            // Check if the lowercase_type contains specific keywords and return the corresponding type
            if (strcasecmp(declared_type[k], "integer") == 0) {
                return "int";
            } else if (strcasecmp(declared_type[k], "real") == 0 ) {
                return "real";
            } else if (strcasecmp(declared_type[k], "Char") == 0 ) {
                return "char";
            } else if (strcasecmp(declared_type[k], "boolean") == 0 ) {
                return "bool";
            } else {
                // If no specific type is matched, return the original declared type
                return declared_type[k];
            }
        }
    }
    printf("Undeclared variable %s\n",name);
    checking=1;
    return NULL;
}
    extern FILE *yyin;


#line 373 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 553 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_3_ = 3,                         /* '-'  */
  YYSYMBOL_DOWNTO = 4,                     /* DOWNTO  */
  YYSYMBOL_UMINUS = 5,                     /* UMINUS  */
  YYSYMBOL_PROGRAM = 6,                    /* PROGRAM  */
  YYSYMBOL_SC = 7,                         /* SC  */
  YYSYMBOL_TYPE = 8,                       /* TYPE  */
  YYSYMBOL_EQ = 9,                         /* EQ  */
  YYSYMBOL_OF = 10,                        /* OF  */
  YYSYMBOL_COMMENT = 11,                   /* COMMENT  */
  YYSYMBOL_COLON = 12,                     /* COLON  */
  YYSYMBOL_BEG = 13,                       /* BEG  */
  YYSYMBOL_READ = 14,                      /* READ  */
  YYSYMBOL_OB = 15,                        /* OB  */
  YYSYMBOL_CB = 16,                        /* CB  */
  YYSYMBOL_WRITE = 17,                     /* WRITE  */
  YYSYMBOL_STRING = 18,                    /* STRING  */
  YYSYMBOL_COMMA = 19,                     /* COMMA  */
  YYSYMBOL_FOR = 20,                       /* FOR  */
  YYSYMBOL_ASSIGN = 21,                    /* ASSIGN  */
  YYSYMBOL_DO = 22,                        /* DO  */
  YYSYMBOL_INT_LITERAL = 23,               /* INT_LITERAL  */
  YYSYMBOL_REAL_LITERAL = 24,              /* REAL_LITERAL  */
  YYSYMBOL_CHAR_LITERAL = 25,              /* CHAR_LITERAL  */
  YYSYMBOL_VAR = 26,                       /* VAR  */
  YYSYMBOL_NOTEQ = 27,                     /* NOTEQ  */
  YYSYMBOL_LT = 28,                        /* LT  */
  YYSYMBOL_GT = 29,                        /* GT  */
  YYSYMBOL_GTEQ = 30,                      /* GTEQ  */
  YYSYMBOL_LTEQ = 31,                      /* LTEQ  */
  YYSYMBOL_PLUS = 32,                      /* PLUS  */
  YYSYMBOL_MINUS = 33,                     /* MINUS  */
  YYSYMBOL_MUL = 34,                       /* MUL  */
  YYSYMBOL_DIV = 35,                       /* DIV  */
  YYSYMBOL_MOD = 36,                       /* MOD  */
  YYSYMBOL_AND = 37,                       /* AND  */
  YYSYMBOL_OR = 38,                        /* OR  */
  YYSYMBOL_NOT = 39,                       /* NOT  */
  YYSYMBOL_IF = 40,                        /* IF  */
  YYSYMBOL_THEN = 41,                      /* THEN  */
  YYSYMBOL_ELSE = 42,                      /* ELSE  */
  YYSYMBOL_END = 43,                       /* END  */
  YYSYMBOL_DOT = 44,                       /* DOT  */
  YYSYMBOL_INT = 45,                       /* INT  */
  YYSYMBOL_REAL = 46,                      /* REAL  */
  YYSYMBOL_CHAR = 47,                      /* CHAR  */
  YYSYMBOL_BOOLEAN = 48,                   /* BOOLEAN  */
  YYSYMBOL_TO = 49,                        /* TO  */
  YYSYMBOL_WHILE = 50,                     /* WHILE  */
  YYSYMBOL_ARRAY = 51,                     /* ARRAY  */
  YYSYMBOL_OPENBRAC = 52,                  /* OPENBRAC  */
  YYSYMBOL_CLOSEBRAC = 53,                 /* CLOSEBRAC  */
  YYSYMBOL_OPENPARA = 54,                  /* OPENPARA  */
  YYSYMBOL_CLOSEPARA = 55,                 /* CLOSEPARA  */
  YYSYMBOL_ID = 56,                        /* ID  */
  YYSYMBOL_ARR = 57,                       /* ARR  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_start = 59,                     /* start  */
  YYSYMBOL_program = 60,                   /* program  */
  YYSYMBOL_program_name = 61,              /* program_name  */
  YYSYMBOL_var_dec_sec = 62,               /* var_dec_sec  */
  YYSYMBOL_var_dec_list = 63,              /* var_dec_list  */
  YYSYMBOL_var_dec = 64,                   /* var_dec  */
  YYSYMBOL_id_list = 65,                   /* id_list  */
  YYSYMBOL_type = 66,                      /* type  */
  YYSYMBOL_main_prog_block = 67,           /* main_prog_block  */
  YYSYMBOL_68_1 = 68,                      /* $@1  */
  YYSYMBOL_stmt_block = 69,                /* stmt_block  */
  YYSYMBOL_stmt = 70,                      /* stmt  */
  YYSYMBOL_assign_stmt = 71,               /* assign_stmt  */
  YYSYMBOL_72_2 = 72,                      /* @2  */
  YYSYMBOL_73_3 = 73,                      /* @3  */
  YYSYMBOL_expr = 74,                      /* expr  */
  YYSYMBOL_term = 75,                      /* term  */
  YYSYMBOL_factor = 76,                    /* factor  */
  YYSYMBOL_value = 77,                     /* value  */
  YYSYMBOL_conditional_stmt = 78,          /* conditional_stmt  */
  YYSYMBOL_bool_expr = 79,                 /* bool_expr  */
  YYSYMBOL_v = 80,                         /* v  */
  YYSYMBOL_rel_op = 81,                    /* rel_op  */
  YYSYMBOL_loop_stmt = 82,                 /* loop_stmt  */
  YYSYMBOL_read_stmt = 83,                 /* read_stmt  */
  YYSYMBOL_read_list = 84,                 /* read_list  */
  YYSYMBOL_read_id = 85,                   /* read_id  */
  YYSYMBOL_arr = 86,                       /* arr  */
  YYSYMBOL_write_stmt = 87,                /* write_stmt  */
  YYSYMBOL_write_param = 88,               /* write_param  */
  YYSYMBOL_list = 89                       /* list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   301

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  198

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   311


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     3,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   329,   329,   332,   335,   338,   341,   342,   345,   348,
     349,   350,   353,   354,   355,   356,   357,   360,   360,   362,
     363,   365,   366,   367,   368,   369,   372,   372,   424,   424,
     479,   526,   566,   585,   627,   700,   722,   747,   791,   809,
     853,   876,   900,   901,   902,   903,   906,   907,   908,   909,
     911,   912,   913,   914,   915,   916,   918,   920,   921,   922,
     923,   924,   925,   927,   967,  1007,  1049,  1095,  1096,  1097,
    1098,  1099,  1100,  1103,  1104,  1105,  1106,  1109,  1111,  1111,
    1112,  1116,  1121,  1121,  1122,  1125,  1126,  1128,  1129,  1130,
    1131
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "'-'", "DOWNTO",
  "UMINUS", "PROGRAM", "SC", "TYPE", "EQ", "OF", "COMMENT", "COLON", "BEG",
  "READ", "OB", "CB", "WRITE", "STRING", "COMMA", "FOR", "ASSIGN", "DO",
  "INT_LITERAL", "REAL_LITERAL", "CHAR_LITERAL", "VAR", "NOTEQ", "LT",
  "GT", "GTEQ", "LTEQ", "PLUS", "MINUS", "MUL", "DIV", "MOD", "AND", "OR",
  "NOT", "IF", "THEN", "ELSE", "END", "DOT", "INT", "REAL", "CHAR",
  "BOOLEAN", "TO", "WHILE", "ARRAY", "OPENBRAC", "CLOSEBRAC", "OPENPARA",
  "CLOSEPARA", "ID", "ARR", "$accept", "start", "program", "program_name",
  "var_dec_sec", "var_dec_list", "var_dec", "id_list", "type",
  "main_prog_block", "$@1", "stmt_block", "stmt", "assign_stmt", "@2",
  "@3", "expr", "term", "factor", "value", "conditional_stmt", "bool_expr",
  "v", "rel_op", "loop_stmt", "read_stmt", "read_list", "read_id", "arr",
  "write_stmt", "write_param", "list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-125)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-66)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,   -39,    51,  -125,  -125,    70,  -125,    83,   127,    82,
      75,  -125,  -125,   114,  -125,    -5,  -125,  -125,  -125,   179,
     127,   218,    79,     2,  -125,  -125,  -125,  -125,   100,  -125,
    -125,  -125,  -125,  -125,    98,  -125,  -125,   140,   159,    25,
     196,   196,  -125,  -125,   164,  -125,  -125,  -125,  -125,  -125,
    -125,   144,   179,    42,   -13,     0,   215,   226,   196,    69,
     185,   131,   174,  -125,  -125,   -26,   219,    46,    50,   177,
     184,    72,   179,   172,  -125,  -125,   201,   181,  -125,   205,
     208,   212,  -125,   226,   226,    -6,    -3,   246,    23,    27,
     226,  -125,  -125,  -125,  -125,  -125,   195,  -125,  -125,  -125,
    -125,  -125,   226,   226,   226,   226,   226,   226,   196,   196,
     223,   196,   196,   232,   233,   234,   226,   226,   214,  -125,
     217,   224,  -125,    42,   186,   186,  -125,    15,   134,  -125,
    -125,  -125,  -125,     8,   226,   174,   174,    85,  -125,  -125,
    -125,  -125,  -125,   230,   243,     2,  -125,  -125,   230,   243,
       2,     2,     2,    85,    85,  -125,  -125,   179,  -125,  -125,
    -125,   248,   268,    85,   277,   278,   279,   280,   235,     2,
       2,    76,    80,    91,   125,   281,   282,   283,   250,   251,
    -125,  -125,   218,   129,   137,   284,   285,  -125,  -125,  -125,
       2,     2,   287,   288,   156,   175,  -125,  -125
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     1,     0,     0,     0,
       0,     9,    82,     0,     6,     0,    11,    17,     3,     0,
       5,     0,     0,     0,    45,    42,    43,    44,     0,     7,
      12,    13,    14,    15,     0,     8,    10,     0,     0,     0,
       0,     0,    28,    26,     0,    19,    24,    25,    23,    21,
      22,     0,     0,     0,     0,     0,     0,     0,     0,    37,
      39,     0,    32,    36,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    80,    81,     0,    78,    86,    87,
      90,     0,    85,     0,     0,    37,    39,     0,     0,     0,
       0,    37,    39,    41,    52,    61,    67,    68,    69,    70,
      72,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    20,
       0,     0,    77,     0,     0,     0,    84,     0,     0,    64,
      66,    40,    51,     0,     0,    30,    31,    50,    33,    34,
      35,    53,    60,    54,    57,     0,    59,    56,    58,    55,
       0,     0,     0,    29,    27,    18,    83,     0,    79,    88,
      89,     0,     0,    62,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    46,    48,
      73,    74,     0,     0,     0,     0,     0,    16,    76,    75,
       0,     0,     0,     0,     0,     0,    47,    49
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -125,  -125,  -125,  -125,  -125,  -125,   276,  -125,   117,  -125,
    -125,  -124,   -70,   261,  -125,  -125,   -54,    88,   -51,   -19,
    -125,   -38,   -33,  -125,  -125,  -125,   178,  -125,    49,  -125,
    -125,    28
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     5,     9,    13,    14,    15,    35,    18,
      23,    44,    45,    46,    70,    69,    61,    62,    63,    64,
      47,    65,    66,   104,    48,    49,    76,    77,    80,    50,
      81,    82
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,   119,    87,    67,    83,    78,    93,    21,    68,     1,
     129,   108,   109,   130,    22,   110,    37,     4,    88,    38,
      94,   164,    39,    89,   131,    95,   165,   166,   167,   127,
     128,   -63,   -63,    73,   -65,   -65,   133,   161,    10,   132,
     102,   103,    40,    79,    12,   176,   177,   102,   103,    84,
     137,     6,    41,   120,   138,   139,   140,    16,    42,    43,
     108,   109,   153,   154,   111,   112,   192,   193,   114,    16,
     141,   143,   115,   146,   148,   142,   144,     7,   147,   149,
     163,    42,    43,   108,   109,   -63,    37,   111,   112,    38,
      37,   -63,    39,    38,    37,    17,    39,    38,    74,    75,
      39,   119,   119,   119,   119,    37,   -63,   -63,    38,     8,
     -63,    39,    40,   119,   119,   118,    40,   102,   103,   178,
      40,    20,    41,   179,   119,   119,    41,    19,    42,    43,
      41,    40,    42,    43,   180,    36,    42,    43,   168,    37,
      96,    41,    38,    37,    51,    39,    38,    42,    43,    39,
      52,    37,   159,   160,    38,    53,   162,    39,    97,    98,
      99,   100,   101,   102,   103,    40,   102,   103,   181,    40,
      37,    71,   188,    38,    54,    41,    39,    40,    10,    41,
     189,    42,    43,    11,    12,    42,    43,    41,    72,    37,
     135,   136,    38,    42,    43,    39,    40,    24,   116,   196,
     123,   -65,    25,    26,    27,   117,    41,   -65,   105,   106,
     107,    56,    42,    43,    24,    40,   121,   122,   197,    25,
      26,    27,   -65,   -65,   124,    41,   -65,   125,   126,    57,
      56,    42,    43,    24,   134,    58,   145,    10,    25,    26,
      27,    90,    79,    12,    24,   150,   151,   152,    57,    25,
      26,    27,    59,    60,    58,    96,   111,   112,   155,    57,
     113,   169,   131,    30,    31,    32,    33,   108,   157,    34,
     156,    85,    86,    97,    98,    99,   100,   101,   102,   103,
     111,   170,    91,    92,   171,   172,   173,   174,   175,   183,
     184,   182,   185,   186,   194,   195,    29,   190,   191,   187,
      55,   158
};

static const yytype_uint8 yycheck[] =
{
      19,    71,    56,    41,     4,    18,    57,    12,    41,     6,
      16,    37,    38,    16,    19,    41,    14,    56,    56,    17,
      58,   145,    20,    56,    16,    58,   150,   151,   152,    83,
      84,    37,    38,    52,    37,    38,    90,    22,    51,    16,
      32,    33,    40,    56,    57,   169,   170,    32,    33,    49,
     104,     0,    50,    72,   105,   106,   107,     8,    56,    57,
      37,    38,   116,   117,    37,    38,   190,   191,    22,    20,
     108,   109,    22,   111,   112,   108,   109,     7,   111,   112,
     134,    56,    57,    37,    38,    16,    14,    37,    38,    17,
      14,    22,    20,    17,    14,    13,    20,    17,    56,    57,
      20,   171,   172,   173,   174,    14,    37,    38,    17,    26,
      41,    20,    40,   183,   184,    43,    40,    32,    33,    43,
      40,     7,    50,    43,   194,   195,    50,    52,    56,    57,
      50,    40,    56,    57,    43,    56,    56,    57,   157,    14,
       9,    50,    17,    14,    44,    20,    17,    56,    57,    20,
      52,    14,   124,   125,    17,    15,    22,    20,    27,    28,
      29,    30,    31,    32,    33,    40,    32,    33,    43,    40,
      14,     7,    43,    17,    15,    50,    20,    40,    51,    50,
      43,    56,    57,    56,    57,    56,    57,    50,    44,    14,
     102,   103,    17,    56,    57,    20,    40,    18,    21,    43,
      19,    16,    23,    24,    25,    21,    50,    22,    34,    35,
      36,    15,    56,    57,    18,    40,    44,    16,    43,    23,
      24,    25,    37,    38,    19,    50,    41,    19,    16,    33,
      15,    56,    57,    18,    39,    39,    13,    51,    23,    24,
      25,    15,    56,    57,    18,    13,    13,    13,    33,    23,
      24,    25,    56,    57,    39,     9,    37,    38,    44,    33,
      41,    13,    16,    45,    46,    47,    48,    37,    44,    51,
      53,    56,    57,    27,    28,    29,    30,    31,    32,    33,
      37,    13,    56,    57,     7,     7,     7,     7,    53,     7,
       7,    10,    42,    42,     7,     7,    20,    13,    13,   182,
      39,   123
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    59,    60,    56,    61,     0,     7,    26,    62,
      51,    56,    57,    63,    64,    65,    86,    13,    67,    52,
       7,    12,    19,    68,    18,    23,    24,    25,    77,    64,
      45,    46,    47,    48,    51,    66,    56,    14,    17,    20,
      40,    50,    56,    57,    69,    70,    71,    78,    82,    83,
      87,    44,    52,    15,    15,    71,    15,    33,    39,    56,
      57,    74,    75,    76,    77,    79,    80,    79,    80,    73,
      72,     7,    44,    77,    56,    57,    84,    85,    18,    56,
      86,    88,    89,     4,    49,    56,    57,    74,    79,    80,
      15,    56,    57,    76,    79,    80,     9,    27,    28,    29,
      30,    31,    32,    33,    81,    34,    35,    36,    37,    38,
      41,    37,    38,    41,    22,    22,    21,    21,    43,    70,
      77,    44,    16,    19,    19,    19,    16,    74,    74,    16,
      16,    16,    16,    74,    39,    75,    75,    74,    76,    76,
      76,    79,    80,    79,    80,    13,    79,    80,    79,    80,
      13,    13,    13,    74,    74,    44,    53,    44,    84,    89,
      89,    22,    22,    74,    69,    69,    69,    69,    77,    13,
      13,     7,     7,     7,     7,    53,    69,    69,    43,    43,
      43,    43,    10,     7,     7,    42,    42,    66,    43,    43,
      13,    13,    69,    69,     7,     7,    43,    43
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    60,    61,    62,    63,    63,    64,    65,
      65,    65,    66,    66,    66,    66,    66,    68,    67,    69,
      69,    70,    70,    70,    70,    70,    72,    71,    73,    71,
      74,    74,    74,    75,    75,    75,    75,    76,    76,    76,
      76,    76,    77,    77,    77,    77,    78,    78,    78,    78,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    80,    80,    80,    80,    81,    81,    81,
      81,    81,    81,    82,    82,    82,    82,    83,    84,    84,
      85,    85,    86,    86,    87,    88,    88,    89,    89,    89,
      89
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     5,     1,     3,     1,     3,     3,     1,
       3,     1,     1,     1,     1,     1,     9,     0,     6,     1,
       3,     1,     1,     1,     1,     1,     0,     4,     0,     4,
       3,     3,     1,     3,     3,     3,     1,     1,     1,     1,
       3,     2,     1,     1,     1,     1,     7,    12,     7,    12,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     4,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     7,     7,     9,     9,     4,     1,     3,
       1,     1,     1,     7,     4,     1,     1,     1,     3,     3,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 17: /* $@1: %empty  */
#line 360 "VAPS5421.y"
                      {checkMulDec();assignType();}
#line 1774 "y.tab.c"
    break;

  case 26: /* @2: %empty  */
#line 372 "VAPS5421.y"
                   {if(isIdPresent((yyvsp[0].strval))==1){findId((yyvsp[0].strval));strcpy((yyval.t.type), findType((yyvsp[0].strval)));} }
#line 1780 "y.tab.c"
    break;

  case 27: /* assign_stmt: ARR @2 ASSIGN expr  */
#line 372 "VAPS5421.y"
                                                                                                       { if(isIdPresent((yyvsp[-3].strval))==1) {if (strcmp(findType((yyvsp[-3].strval)),(yyvsp[0].t.type))!=0 && !(strcmp(findType((yyvsp[-3].strval)),"bool")==0 && strcmp((yyvsp[0].t.type),"int")==0 && !(strcmp(findType((yyvsp[-3].strval)),"real")==0 && strcmp((yyvsp[0].t.type),"int")==0)) ) { printf("Type mismatch: Assigning %s to %s for variable %s not possible\n",(yyvsp[0].t.type),findType((yyvsp[-3].strval)),(yyvsp[-3].strval));  checking=1;}
                else
                {
                    char name[50];
                    strcpy(name, (yyvsp[-3].strval));
                    //printf("\n");
                    //printf(name);
                    //printf("\n");
                    strcpy((yyvsp[-3].t.type),findType((yyvsp[-3].strval)));
                    //printf($<t.type>1);printf("\n");printf("hoho\n");
                   if (strcmp((yyvsp[-3].t.type),"real")==0) 
                   {
                    if (strcmp((yyvsp[0].t.type),"int")==0)
                    {
                        (yyvsp[-3].t.v.fval) = 1.0*(yyvsp[0].t.v.ival);
                    initialize(name);
                    insertrealValue(name,(yyvsp[-3].t.v.fval));
                    }
                    else{
                    (yyvsp[-3].t.v.fval) = (yyvsp[0].t.v.fval);
                    initialize(name);
                    insertrealValue(name,(yyvsp[-3].t.v.fval));}
                   }
                    else if (strcmp((yyvsp[-3].t.type),"int")==0)
                    {
                        //printf("entered int\n");
                    (yyvsp[-3].t.v.ival) = (yyvsp[0].t.v.ival);
                   //printf("\n");
                    //printf(name);
                    //printf("\n");
                    initialize(name);
                    insertintValue(name,(yyvsp[-3].t.v.ival));
                   // printf("%d \n",$<t.v.ival>1);
                    }
                    else if (strcmp((yyvsp[-3].t.type),"char")==0)
                    {
                     (yyvsp[-3].t.v.cval) = (yyvsp[0].t.v.cval);
                     initialize(name);
                     insertcharValue(name,(yyvsp[-3].t.v.cval));
                    }
                    else if (strcmp((yyvsp[-3].t.type),"bool")==0)
                    {
                     //printf("entered int\n");
                    (yyvsp[-3].t.v.ival) = (yyvsp[0].t.v.ival);
                    initialize(name);
                    insertintValue(name,(yyvsp[-3].t.v.ival));
                   // printf("%d \n",$<t.v.ival>1);
                     
                    }
                }
}
            }
#line 1837 "y.tab.c"
    break;

  case 28: /* @3: %empty  */
#line 424 "VAPS5421.y"
                  {if(isIdPresent((yyvsp[0].strval))==1){findId((yyvsp[0].strval));strcpy((yyval.t.type), findType((yyvsp[0].strval)));} }
#line 1843 "y.tab.c"
    break;

  case 29: /* assign_stmt: ID @3 ASSIGN expr  */
#line 424 "VAPS5421.y"
                                                                                                      { if(isIdPresent((yyvsp[-3].strval))==1) {if (strcmp(findType((yyvsp[-3].strval)),(yyvsp[0].t.type))!=0 && !(strcmp(findType((yyvsp[-3].strval)),"bool")==0 && strcmp((yyvsp[0].t.type),"int")==0) && !(strcmp(findType((yyvsp[-3].strval)),"real")==0 && strcmp((yyvsp[0].t.type),"int")==0) ) { printf("Type mismatch: Assigning %s to %s for variable %s not possible\n",(yyvsp[0].t.type),findType((yyvsp[-3].strval)),(yyvsp[-3].strval));  checking=1;}
                else
                {
                    char name[50];
                    strcpy(name, (yyvsp[-3].strval));
                    //printf("\n");
                    //printf(name);
                    //printf("\n");
                    strcpy((yyvsp[-3].t.type),findType((yyvsp[-3].strval)));
                    //printf($<t.type>1);printf("\n");printf("hoho\n");
                   if (strcmp((yyvsp[-3].t.type),"real")==0) 
                   {
                    if (strcmp((yyvsp[0].t.type),"int")==0)
                    {
                        (yyvsp[-3].t.v.fval) = 1.0*(yyvsp[0].t.v.ival);
                    initialize(name);
                    insertrealValue(name,(yyvsp[-3].t.v.fval));
                    }
                    else
                    {
                    (yyvsp[-3].t.v.fval) = (yyvsp[0].t.v.fval);
                    initialize(name);
                    insertrealValue(name,(yyvsp[-3].t.v.fval));}
                   }
                    else if (strcmp((yyvsp[-3].t.type),"int")==0)
                    {
                        //printf("entered int\n");
                    (yyvsp[-3].t.v.ival) = (yyvsp[0].t.v.ival);
                   //printf("\n");
                    //printf(name);
                    //printf("\n");
                    initialize(name);
                    insertintValue(name,(yyvsp[-3].t.v.ival));
                   // printf("%d \n",$<t.v.ival>1);
                    }
                    else if (strcmp((yyvsp[-3].t.type),"char")==0)
                    {
                     (yyvsp[-3].t.v.cval) = (yyvsp[0].t.v.cval);
                     initialize(name);
                     insertcharValue(name,(yyvsp[-3].t.v.cval));
                    }
                    else if (strcmp((yyvsp[-3].t.type),"bool")==0)
                    {
                     //printf("entered int\n");
                    (yyvsp[-3].t.v.ival) = (yyvsp[0].t.v.ival);
                    initialize(name);
                    insertintValue(name,(yyvsp[-3].t.v.ival));
                   // printf("%d \n",$<t.v.ival>1);
                     
                    }
                }
}
            }
#line 1901 "y.tab.c"
    break;

  case 30: /* expr: expr PLUS term  */
#line 479 "VAPS5421.y"
                      {
            //printf("expr + term\n");
            //printf($<t.type>1);
            //printf($<t.type>3);
            if (((strcmp((yyvsp[-2].t.type) , "real")==0 && strcmp((yyvsp[0].t.type) , "char")==0 )) || ((strcmp((yyvsp[-2].t.type) , "char")==0 && strcmp((yyvsp[0].t.type) , "real")==0 ))) {
                printf("Error:Char and real addition not possible\n");
                checking=1;
            }
            if ((strcmp((yyvsp[-2].t.type) , "char")==0 && strcmp((yyvsp[0].t.type) , "char")==0 ))
            {
                printf("Error:Char and char addition not possible\n");
                checking=1;
            }
            if (((strcmp((yyvsp[-2].t.type) , "int")==0 && strcmp((yyvsp[0].t.type) , "char")==0 )) || ((strcmp((yyvsp[-2].t.type) , "char")==0 && strcmp((yyvsp[0].t.type) , "int")==0 )))
            {
                 printf("Error:Char and int addition not possible\n");
                checking=1;
            }
            if ((strcmp((yyvsp[-2].t.type) , "real")==0 && strcmp((yyvsp[0].t.type) , "real")==0 )) {
                (yyval.t.v.fval) = (yyvsp[-2].t.v.fval) + (yyvsp[0].t.v.fval) ;
                fans = (yyval.t.v.fval) ; 
                strcpy((yyval.t.type), "real");
                //printf("Result of expression is %s and value is : %f\n",$<t.type>$, fans);
            }
            if ((strcmp((yyvsp[-2].t.type) , "real")==0 && strcmp((yyvsp[0].t.type) , "int")==0 )) {
                (yyval.t.v.fval) = (yyvsp[-2].t.v.fval) + (yyvsp[0].t.v.ival) ;

                fans = (yyval.t.v.fval) ;
                strcpy((yyval.t.type), "real");
                //printf("Result of expression is %s and value is : %f\n",$<t.type>$, fans);
            }
            if ((strcmp((yyvsp[-2].t.type) , "int")==0 && strcmp((yyvsp[0].t.type) , "real")==0 )) {
                (yyval.t.v.fval) = (yyvsp[-2].t.v.ival) + (yyvsp[0].t.v.fval) ;

                fans = (yyval.t.v.fval) ;
                strcpy((yyval.t.type), "real");
                //printf("Result of expression is %s and value is : %f\n",$<t.type>$, fans);
            }
            if ((strcmp((yyvsp[-2].t.type) , "int")==0 && strcmp((yyvsp[0].t.type) , "int")==0 )) {
                (yyval.t.v.ival) = (yyvsp[-2].t.v.ival) + (yyvsp[0].t.v.ival) ;
                ians = (yyval.t.v.ival);
                //printf("hello");
                strcpy((yyval.t.type), "int");
               // printf($<t.type>$);
                //printf("Result of expression is %s and value is : %d\n",$<t.type>$, ians);
            }
        }
#line 1953 "y.tab.c"
    break;

  case 31: /* expr: expr MINUS term  */
#line 526 "VAPS5421.y"
                       {
    if (((strcmp((yyvsp[-2].t.type) , "real")==0 && strcmp((yyvsp[0].t.type) , "char")==0 )) || ((strcmp((yyvsp[-2].t.type) , "char")==0 && strcmp((yyvsp[0].t.type) , "real")==0 ))) {
                printf("Error:Char and real subtraction not possible\n");
                checking=1;
            }
            if ((strcmp((yyvsp[-2].t.type) , "char")==0 && strcmp((yyvsp[0].t.type) , "char")==0 ))
            {
                printf("Error:Char and char subtraction not possible\n");
                checking=1;
            }
            if (((strcmp((yyvsp[-2].t.type) , "int")==0 && strcmp((yyvsp[0].t.type) , "char")==0 )) || ((strcmp((yyvsp[-2].t.type) , "char")==0 && strcmp((yyvsp[0].t.type) , "int")==0 )))
            {
                 printf("Error:Char and int subtraction not possible\n");
                checking=1;
            }
    if ((strcmp((yyvsp[-2].t.type) , "real")==0 && strcmp((yyvsp[0].t.type) , "real")==0 )) {
        (yyval.t.v.fval) = (yyvsp[-2].t.v.fval) - (yyvsp[0].t.v.fval) ;
        fans = (yyval.t.v.fval) ; 
        strcpy((yyval.t.type), "real");
        //printf("Result of expression is %s and value is : %f\n",$<t.type>$, fans);
    }
    if ((strcmp((yyvsp[-2].t.type) , "real")==0 && strcmp((yyvsp[0].t.type) , "int")==0 )) {
        (yyval.t.v.fval) = (yyvsp[-2].t.v.fval) - (yyvsp[0].t.v.ival) ;
        fans = (yyval.t.v.fval) ;
        strcpy((yyval.t.type), "real");
        //printf("Result of expression is %s and value is : %f\n",$<t.type>$, fans);
    }
    if ((strcmp((yyvsp[-2].t.type) , "int")==0 && strcmp((yyvsp[0].t.type) , "real")==0 )) {
        (yyval.t.v.fval) = (yyvsp[-2].t.v.ival) - (yyvsp[0].t.v.fval) ;
        fans = (yyval.t.v.fval) ;
        strcpy((yyval.t.type), "real");
        //printf("Result of expression is %s and value is : %f\n",$<t.type>$, fans);
    }
    if ((strcmp((yyvsp[-2].t.type) , "int")==0 && strcmp((yyvsp[0].t.type) , "int")==0 )) {
        (yyval.t.v.ival) = (yyvsp[-2].t.v.ival) - (yyvsp[0].t.v.ival) ;
        ians = (yyval.t.v.ival);
        strcpy((yyval.t.type), "int");
       // printf("Result of expression is %s and value is : %d\n",$<t.type>$, ians);
    }
}
#line 1998 "y.tab.c"
    break;

  case 32: /* expr: term  */
#line 566 "VAPS5421.y"
            { strcpy((yyval.t.type), (yyvsp[0].t.type));
           // printf("expr->term\n");
            //printf($<t.type>$);printf("\n");
            if (strcmp((yyvsp[0].t.type),"int")==0)
                 {
                    (yyval.t.v.ival) = (yyvsp[0].t.v.ival); 
                   // printf("hello%d\n", $<t.v.ival>$);
                   // printf("value printf");
                }
                 else if (strcmp((yyvsp[0].t.type),"real")==0) 
                {
                    (yyval.t.v.fval) = (yyvsp[0].t.v.fval); 
                } 
                else if (strcmp((yyvsp[0].t.type),"char")==0)
                 {
                    (yyval.t.v.cval) = (yyvsp[0].t.v.cval); 
                 } 
     }
#line 2021 "y.tab.c"
    break;

  case 33: /* term: term MUL factor  */
#line 585 "VAPS5421.y"
                       {
    // Subtraction
    // Similar code for subtraction
    if (((strcmp((yyvsp[-2].t.type) , "real")==0 && strcmp((yyvsp[0].t.type) , "char")==0 )) || ((strcmp((yyvsp[-2].t.type) , "char")==0 && strcmp((yyvsp[0].t.type) , "real")==0 ))) {
                printf("Error:Char and real multiplication not possible\n");
                checking=1;
            }
            if ((strcmp((yyvsp[-2].t.type) , "char")==0 && strcmp((yyvsp[0].t.type) , "char")==0 ))
            {
                printf("Error:Char and char multiplication not possible\n");
                checking=1;
            }
            if (((strcmp((yyvsp[-2].t.type) , "int")==0 && strcmp((yyvsp[0].t.type) , "char")==0 )) || ((strcmp((yyvsp[-2].t.type) , "char")==0 && strcmp((yyvsp[0].t.type) , "int")==0 )))
            {
                 printf("Error:Char and int multiplication not possible\n");
                checking=1;
            }
    if ((strcmp((yyvsp[-2].t.type) , "real")==0 && strcmp((yyvsp[0].t.type) , "real")==0 )) {
        (yyval.t.v.fval) = (yyvsp[-2].t.v.fval) * (yyvsp[0].t.v.fval) ;
        fans = (yyval.t.v.fval) ; 
        strcpy((yyval.t.type), "real");
       // printf("Result of expression is %s and value is : %f\n",$<t.type>$, fans);
    }
    if ((strcmp((yyvsp[-2].t.type) , "real")==0 && strcmp((yyvsp[0].t.type) , "int")==0 )) {
        (yyval.t.v.fval) = (yyvsp[-2].t.v.fval) * (yyvsp[0].t.v.ival) ;
        fans = (yyval.t.v.fval) ;
        strcpy((yyval.t.type), "real");
        //printf("Result of expression is %s and value is : %f\n",$<t.type>$, fans);
    }
    if ((strcmp((yyvsp[-2].t.type) , "int")==0 && strcmp((yyvsp[0].t.type) , "real")==0 )) {
        (yyval.t.v.fval) = (yyvsp[-2].t.v.ival) * (yyvsp[0].t.v.fval) ;
        fans = (yyval.t.v.fval) ;
        strcpy((yyval.t.type), "real");
        //printf("Result of expression is %s and value is : %f\n",$<t.type>$, fans);
    }
    if ((strcmp((yyvsp[-2].t.type) , "int")==0 && strcmp((yyvsp[0].t.type) , "int")==0 )) {
        (yyval.t.v.ival) = (yyvsp[-2].t.v.ival) * (yyvsp[0].t.v.ival) ;
        ians = (yyval.t.v.ival);
        strcpy((yyval.t.type), "int");
    //printf("Result of expression is %s and value is : %d\n",$<t.type>$, ians);
    }
}
#line 2068 "y.tab.c"
    break;

  case 34: /* term: term DIV factor  */
#line 627 "VAPS5421.y"
                       {
    // Subtraction
    if (((strcmp((yyvsp[-2].t.type) , "real")==0 && strcmp((yyvsp[0].t.type) , "char")==0 )) || ((strcmp((yyvsp[-2].t.type) , "char")==0 && strcmp((yyvsp[0].t.type) , "real")==0 ))) {
                printf("Error:Char and real division not possible\n");
                checking=1;
            }
            if ((strcmp((yyvsp[-2].t.type) , "char")==0 && strcmp((yyvsp[0].t.type) , "char")==0 ))
            {
                printf("Error:Char and char division not possible\n");
                checking=1;
            }
            if (((strcmp((yyvsp[-2].t.type) , "int")==0 && strcmp((yyvsp[0].t.type) , "char")==0 )) || ((strcmp((yyvsp[-2].t.type) , "char")==0 && strcmp((yyvsp[0].t.type) , "int")==0 )))
            {
                 printf("Error:Char and int division not possible\n");
                checking=1;
            }
    if ((strcmp((yyvsp[-2].t.type) , "real")==0 && strcmp((yyvsp[0].t.type) , "real")==0 )) {
        if( (yyvsp[0].t.v.fval)==0.0)
        {
           printf("Divide by zero error\n");
           checking=1; 
        }
        else
        {
        (yyval.t.v.fval) = (yyvsp[-2].t.v.fval) / (yyvsp[0].t.v.fval) ;
        fans = (yyval.t.v.fval) ; 
        strcpy((yyval.t.type), "real");
        //printf("Result of expression is %s and value is : %f\n",$<t.type>$, fans);
        }
    }
    if ((strcmp((yyvsp[-2].t.type) , "real")==0 && strcmp((yyvsp[0].t.type) , "int")==0 )) {
        if( (yyvsp[0].t.v.ival)==0)
        {
           printf("Divide by zero error\n");
           checking=1; 
        }
        else
        {
        (yyval.t.v.fval) = (yyvsp[-2].t.v.fval) / (yyvsp[0].t.v.ival) ;
        fans = (yyval.t.v.fval) ;
        strcpy((yyval.t.type), "real");
        //printf("Result of expression is %s and value is : %f\n",$<t.type>$, fans);
        }
    }
    if ((strcmp((yyvsp[-2].t.type) , "int")==0 && strcmp((yyvsp[0].t.type) , "real")==0 )) {
        if( (yyvsp[0].t.v.fval)==0.0)
        {
           printf("Divide by zero error\n");
           checking=1; 
        }
        else
        {
        (yyval.t.v.fval) = (yyvsp[-2].t.v.ival) / (yyvsp[0].t.v.fval) ;
        fans = (yyval.t.v.fval) ;
        strcpy((yyval.t.type), "real");
        //printf("Result of expression is %s and value is : %f\n",$<t.type>$, fans);
        }
    }
    if ((strcmp((yyvsp[-2].t.type) , "int")==0 && strcmp((yyvsp[0].t.type) , "int")==0 )) {
        if( (yyvsp[0].t.v.ival)==0)
        {
           printf("Divide by zero error\n");
           checking=1; 
        }
        else
        {
        (yyval.t.v.ival) = (yyvsp[-2].t.v.ival) / (yyvsp[0].t.v.ival) ;
        ians = (yyval.t.v.ival);
        strcpy((yyval.t.type), "int");
       // printf("Result of expression is %s and value is : %d\n",$<t.type>$, ians);
        }
    }
}
#line 2146 "y.tab.c"
    break;

  case 35: /* term: term MOD factor  */
#line 700 "VAPS5421.y"
                       {
    // Modulus
    if (strcmp((yyvsp[-2].t.type) , "real")==0 || strcmp((yyvsp[0].t.type) , "real")==0 ) {
        printf("Error:Modulus operator cannot be applied to real numbers\n"); checking=1;
    }
    else if ((yyvsp[0].t.v.ival) == 0) {
        printf("Error:Division by zero\n");
          checking=1;
    }
   else if ((strcmp((yyvsp[-2].t.type) , "int")==0 && strcmp((yyvsp[0].t.type) , "int")==0 )) {
        (yyval.t.v.ival) = (yyvsp[-2].t.v.ival) / (yyvsp[0].t.v.ival) ;
        ians = (yyval.t.v.ival);
        strcpy((yyval.t.type), "int");
       // printf("Result of expression is %s and value is : %d\n",$<t.type>$, ians);
    }
    else
    {
        printf("Error:Type should be int for Modulus operation\n");
      checking=1;
    }
    
}
#line 2173 "y.tab.c"
    break;

  case 36: /* term: factor  */
#line 722 "VAPS5421.y"
              { strcpy((yyval.t.type), (yyvsp[0].t.type));
            //printf("term->factor\n");
            //printf($<t.type>$);printf("\n");
            if (strcmp((yyvsp[0].t.type),"int")==0)
                 {
                    (yyval.t.v.ival) = (yyvsp[0].t.v.ival); 
                   // printf("hello%d\n", $<t.v.ival>$);
                    //printf("value printf");
                }
                 else if (strcmp((yyvsp[0].t.type),"real")==0) 
                {
                    (yyval.t.v.fval) = (yyvsp[0].t.v.fval); 
                } 
                else if (strcmp((yyvsp[0].t.type),"char")==0)
                 {
                    (yyval.t.v.cval) = (yyvsp[0].t.v.cval); 
                 } 
                 else if (strcmp((yyvsp[0].t.type),"bool")==0)
                 {
                    (yyval.t.v.ival) = (yyvsp[0].t.v.ival); 
                 } 
     }
#line 2200 "y.tab.c"
    break;

  case 37: /* factor: ID  */
#line 747 "VAPS5421.y"
              { if(isIdPresent((yyvsp[0].strval))==1){strcpy((yyval.t.type), findType((yyvsp[0].strval)));
                
               // printf($1);printf("\n");printf($<t.type>$);printf("\n");printf("factor\n");
                if(strcmp((yyval.t.type),"real")==0)
                {
                   (yyval.t.v.fval)=getrealVal((yyvsp[0].strval));
                   int val=checkIn((yyvsp[0].strval));
                    if((yyval.t.v.fval)==0.0 && val==0)
                    {
                    printf("Variable ");printf((yyvsp[0].strval));printf(" is used before initializing\n");checking=1;
                    }
                }
             else if(strcmp((yyval.t.type),"int")==0)
                {
                    //printf("yo\n");
                    (yyval.t.v.ival)=getintVal((yyvsp[0].strval));
                     int val=checkIn((yyvsp[0].strval));
                     //printf("yo\n");
                     if((yyval.t.v.ival)==0 && val==0)
                    {
                        printf("Variable ");printf((yyvsp[0].strval));printf(" is used before initializing\n");checking=1;
                    }
                }
                else if(strcmp((yyval.t.type),"char")==0)
                {
                     (yyval.t.v.cval)=getcharVal((yyvsp[0].strval));
                      int val=checkIn((yyvsp[0].strval));
                     if((yyval.t.v.cval)=='@' && val==0)
                    {
                         printf("Variable ");printf((yyvsp[0].strval));printf(" is used before initializing\n");checking=1;
                    }
                }
                else if(strcmp((yyval.t.type),"bool")==0)
                {
                     (yyval.t.v.ival)=getintVal((yyvsp[0].strval));
                     int val=checkIn((yyvsp[0].strval));
                     //printf("yo\n");
                     if((yyval.t.v.ival)==0 && val==0)
                    {
                        printf("Variable ");printf((yyvsp[0].strval));printf(" is used before initializing\n");checking=1;
                    }
                }
}
 }
#line 2249 "y.tab.c"
    break;

  case 38: /* factor: value  */
#line 791 "VAPS5421.y"
               {
        strcpy((yyval.t.type),(yyvsp[0].t.type)); 
        // printf($<t.type>$);printf("factor\n");
                 if (strcmp((yyvsp[0].t.type),"int")==0)
                 {
                    (yyval.t.v.ival) = (yyvsp[0].t.v.ival); 
                   // printf("hello%d\n", $<t.v.ival>$);
                   // printf("value printf");
                }
                 else if (strcmp((yyvsp[0].t.type),"real")==0) 
                {
                    (yyval.t.v.fval) = (yyvsp[0].t.v.fval); 
                } 
                else if (strcmp((yyvsp[0].t.type),"char")==0)
                 {
                    (yyval.t.v.cval) = (yyvsp[0].t.v.cval); 
                 } 
            }
#line 2272 "y.tab.c"
    break;

  case 39: /* factor: ARR  */
#line 809 "VAPS5421.y"
             {if(isIdPresent((yyvsp[0].strval))==1){strcpy((yyval.t.type), findType((yyvsp[0].strval)));
                
               // printf($1);printf("\n");printf($<t.type>$);printf("\n");printf("factor\n");
                if(strcmp((yyval.t.type),"real")==0)
                {
                     int val=checkIn((yyvsp[0].strval));
                   (yyval.t.v.fval)=getrealVal((yyvsp[0].strval));
                    if((yyval.t.v.fval)==0.0 && val==0)
                    {
                     printf("Variable ");printf((yyvsp[0].strval));printf(" is used before initializing\n");checking=1;
                    }
                }
             else if(strcmp((yyval.t.type),"int")==0)
                {
                     int val=checkIn((yyvsp[0].strval));
                    //printf("yo\n");
                    (yyval.t.v.ival)=getintVal((yyvsp[0].strval));
                     //printf("yo\n");
                     if((yyval.t.v.ival)==0 && val==0)
                    {
                       printf("Variable ");printf((yyvsp[0].strval));printf(" is used before initializing\n");checking=1;
                    }
                }
                else if(strcmp((yyval.t.type),"char")==0)
                {
                     int val=checkIn((yyvsp[0].strval));
                     (yyval.t.v.cval)=getcharVal((yyvsp[0].strval));
                     if((yyval.t.v.cval)=='@' && val==0)
                    {
                        printf("Variable ");printf((yyvsp[0].strval));printf(" is used before initializing\n");checking=1;
                    }
                }
                else if(strcmp((yyval.t.type),"bool")==0)
                {
                     (yyval.t.v.ival)=getintVal((yyvsp[0].strval));
                     int val=checkIn((yyvsp[0].strval));
                     //printf("yo\n");
                     if((yyval.t.v.ival)==0 && val==0)
                    {
                        printf("Variable ");printf((yyvsp[0].strval));printf(" is used before initializing\n");checking=1;
                    }
                }
       }
       }
#line 2321 "y.tab.c"
    break;

  case 40: /* factor: OB expr CB  */
#line 853 "VAPS5421.y"
                    { strcpy((yyval.t.type), (yyvsp[-1].t.type));
            //printf("term->factor\n");
            //printf($<t.type>$);printf("\n");
            if (strcmp((yyvsp[-1].t.type),"int")==0)
                 {
                    (yyval.t.v.ival) = (yyvsp[-1].t.v.ival); 
                   // printf("hello%d\n", $<t.v.ival>$);
                    //printf("value printf");
                }
                 else if (strcmp((yyvsp[-1].t.type),"real")==0) 
                {
                    (yyval.t.v.fval) = (yyvsp[-1].t.v.fval); 
                } 
                else if (strcmp((yyvsp[-1].t.type),"char")==0)
                 {
                    (yyval.t.v.cval) = (yyvsp[-1].t.v.cval); 
                 } 
                 else if (strcmp((yyvsp[-1].t.type),"bool")==0)
                 {
                    (yyval.t.v.ival) = (yyvsp[-1].t.v.ival); 
                 }
     }
#line 2348 "y.tab.c"
    break;

  case 41: /* factor: MINUS factor  */
#line 876 "VAPS5421.y"
                                    { strcpy((yyval.t.type), (yyvsp[0].t.type));
            //printf("term->factor\n");
            //printf($<t.type>$);printf("\n");
            if (strcmp((yyvsp[0].t.type),"int")==0)
                 {
                    (yyval.t.v.ival) = (yyvsp[0].t.v.ival); 
                   // printf("hello%d\n", $<t.v.ival>$);
                    //printf("value printf");
                }
                 else if (strcmp((yyvsp[0].t.type),"real")==0) 
                {
                    (yyval.t.v.fval) = (yyvsp[0].t.v.fval); 
                } 
                else if (strcmp((yyvsp[0].t.type),"char")==0)
                 {
                    (yyval.t.v.cval) = (yyvsp[0].t.v.cval); 
                 } 
                 else if (strcmp((yyvsp[0].t.type),"bool")==0)
                 {
                    (yyval.t.v.ival) = (yyvsp[0].t.v.ival); 
                 }
     }
#line 2375 "y.tab.c"
    break;

  case 42: /* value: INT_LITERAL  */
#line 900 "VAPS5421.y"
                    {strcpy((yyval.t.type),"int"); (yyval.t.v.ival)=(yyvsp[0].t.v.ival);}
#line 2381 "y.tab.c"
    break;

  case 43: /* value: REAL_LITERAL  */
#line 901 "VAPS5421.y"
                     {strcpy((yyval.t.type),"real");(yyval.t.v.fval)=(yyvsp[0].t.v.fval);}
#line 2387 "y.tab.c"
    break;

  case 44: /* value: CHAR_LITERAL  */
#line 902 "VAPS5421.y"
                     {strcpy((yyval.t.type),"char");(yyval.t.v.cval)=(yyvsp[0].t.v.cval);}
#line 2393 "y.tab.c"
    break;

  case 48: /* conditional_stmt: IF v THEN BEG stmt_block SC END  */
#line 908 "VAPS5421.y"
                                                   {if (strcmp((yyvsp[-5].t.type),"bool")!=0 ) {printf("Error: Variable type must be boolean in conditional statement\n");checking=1;} }
#line 2399 "y.tab.c"
    break;

  case 49: /* conditional_stmt: IF v THEN BEG stmt_block SC END ELSE BEG stmt_block SC END  */
#line 909 "VAPS5421.y"
                                                                              {if (strcmp((yyvsp[-10].t.type),"bool")!=0 ) {printf("Error: Variable type must be boolean in conditional statement\n");checking=1;} }
#line 2405 "y.tab.c"
    break;

  case 50: /* bool_expr: expr rel_op expr  */
#line 911 "VAPS5421.y"
                             {if (strcmp((yyvsp[-2].t.type),(yyvsp[0].t.type))!=0) {printf("Type %s doesn't match with %s\n",(yyvsp[-2].t.type),(yyvsp[0].t.type));checking=1;}  }
#line 2411 "y.tab.c"
    break;

  case 55: /* bool_expr: v OR v  */
#line 916 "VAPS5421.y"
                  {if (strcmp((yyvsp[-2].t.type),"bool")!=0 ) {printf("Error: Variable must be boolean in conditional statement\n");checking=1;}
          if (strcmp((yyvsp[0].t.type),"bool")!=0) {printf("Error: Variable must be boolean in conditional statement\n");checking=1;}   }
#line 2418 "y.tab.c"
    break;

  case 56: /* bool_expr: v AND v  */
#line 918 "VAPS5421.y"
                   {if (strcmp((yyvsp[-2].t.type),"bool")!=0 ) {printf("Error: Variable must be boolean in conditional statement\n");checking=1;}
          if (strcmp((yyvsp[0].t.type),"bool")!=0) {printf("Error: Variable must be boolean in conditional statement\n");checking=1;}   }
#line 2425 "y.tab.c"
    break;

  case 57: /* bool_expr: bool_expr OR v  */
#line 920 "VAPS5421.y"
                          {if (strcmp((yyvsp[0].t.type),"bool")!=0 ) {printf("Error: Variable must be boolean in conditional statement\n");checking=1;} }
#line 2431 "y.tab.c"
    break;

  case 58: /* bool_expr: v OR bool_expr  */
#line 921 "VAPS5421.y"
                         {if (strcmp((yyvsp[-2].t.type),"bool")!=0 ) {printf("Error: Variable must be boolean in conditional statement\n");checking=1;} }
#line 2437 "y.tab.c"
    break;

  case 59: /* bool_expr: v AND bool_expr  */
#line 922 "VAPS5421.y"
                          {if (strcmp((yyvsp[-2].t.type),"bool")!=0 ) {printf("Error: Variable must be boolean in conditional statement\n");checking=1;} }
#line 2443 "y.tab.c"
    break;

  case 60: /* bool_expr: bool_expr AND v  */
#line 923 "VAPS5421.y"
                          {if (strcmp((yyvsp[0].t.type),"bool")!=0 ) {printf("Error: Variable must be boolean in conditional statement\n");checking=1;} }
#line 2449 "y.tab.c"
    break;

  case 61: /* bool_expr: NOT v  */
#line 924 "VAPS5421.y"
                {if (strcmp((yyvsp[0].t.type),"bool")!=0) {printf("Error: Variable must be boolean\n in conditional statement");checking=1;} }
#line 2455 "y.tab.c"
    break;

  case 62: /* bool_expr: expr EQ NOT expr  */
#line 925 "VAPS5421.y"
                           {if (strcmp((yyvsp[-3].t.type),(yyvsp[0].t.type))!=0) {printf("Error:Type %s doesn't match type %s\n",(yyvsp[-3].t.type),(yyvsp[0].t.type));checking=1;}  }
#line 2461 "y.tab.c"
    break;

  case 63: /* v: ID  */
#line 927 "VAPS5421.y"
        {if(isIdPresent((yyvsp[0].strval))==1){strcpy((yyval.t.type), findType((yyvsp[0].strval)));
               
                if(strcmp((yyval.t.type),"real")==0)
                {
                   (yyval.t.v.fval)=getrealVal((yyvsp[0].strval));
                   int val=checkIn((yyvsp[0].strval));
                    if((yyval.t.v.fval)==0.0 && val==0)
                    {
                    printf("Variable ");printf((yyvsp[0].strval));printf(" is used before initializing\n");checking=1;
                    }
                }
             else if(strcmp((yyval.t.type),"int")==0)
                {
                    (yyval.t.v.ival)=getintVal((yyvsp[0].strval));
                     int val=checkIn((yyvsp[0].strval));
                     if((yyval.t.v.ival)==0 && val==0)
                    {
                        printf("Variable ");printf((yyvsp[0].strval));printf(" is used before initializing\n");checking=1;
                    }
                }
                else if(strcmp((yyval.t.type),"char")==0)
                {
                     (yyval.t.v.cval)=getcharVal((yyvsp[0].strval));
                      int val=checkIn((yyvsp[0].strval));
                     if((yyval.t.v.cval)=='@' && val==0)
                    {
                         printf("Variable ");printf((yyvsp[0].strval));printf(" is used before initializing\n");checking=1;
                    }
                }
                else if(strcmp((yyval.t.type),"bool")==0)
                {
                     (yyval.t.v.ival)=getintVal((yyvsp[0].strval));
                     int val=checkIn((yyvsp[0].strval));
                     if((yyval.t.v.ival)==0 && val==0)
                    {
                        printf("Variable ");printf((yyvsp[0].strval));printf(" is used before initializing\n");checking=1;
                    }
                }
}
 }
#line 2506 "y.tab.c"
    break;

  case 64: /* v: OB ID CB  */
#line 967 "VAPS5421.y"
                {if(isIdPresent((yyvsp[-1].strval))==1){strcpy((yyval.t.type), findType((yyvsp[-1].strval)));
                
                if(strcmp((yyval.t.type),"real")==0)
                {
                   (yyval.t.v.fval)=getrealVal((yyvsp[-1].strval));
                   int val=checkIn((yyvsp[-1].strval));
                    if((yyval.t.v.fval)==0.0 && val==0)
                    {
                    printf("Variable ");printf((yyvsp[-1].strval));printf(" is used before initializing\n");checking=1;
                    }
                }
             else if(strcmp((yyval.t.type),"int")==0)
                {
                    (yyval.t.v.ival)=getintVal((yyvsp[-1].strval));
                     int val=checkIn((yyvsp[-1].strval));
                     if((yyval.t.v.ival)==0 && val==0)
                    {
                        printf("Variable ");printf((yyvsp[-1].strval));printf(" is used before initializing\n");checking=1;
                    }
                }
                else if(strcmp((yyval.t.type),"char")==0)
                {
                     (yyval.t.v.cval)=getcharVal((yyvsp[-1].strval));
                      int val=checkIn((yyvsp[-1].strval));
                     if((yyval.t.v.cval)=='@' && val==0)
                    {
                         printf("Variable ");printf((yyvsp[-1].strval));printf(" is used before initializing\n");checking=1;
                    }
                }
                else if(strcmp((yyval.t.type),"bool")==0)
                {
                     (yyval.t.v.ival)=getintVal((yyvsp[-1].strval));
                     int val=checkIn((yyvsp[-1].strval));
                     if((yyval.t.v.ival)==0 && val==0)
                    {
                        printf("Variable ");printf((yyvsp[-1].strval));printf(" is used before initializing\n");checking=1;
                    }
                }
 }
    }
#line 2551 "y.tab.c"
    break;

  case 65: /* v: ARR  */
#line 1007 "VAPS5421.y"
           {if(isIdPresent((yyvsp[0].strval))==1){strcpy((yyval.t.type), findType((yyvsp[0].strval)));
                if(strcmp((yyval.t.type),"real")==0)
                {
                   (yyval.t.v.fval)=getrealVal((yyvsp[0].strval));
                   int val=checkIn((yyvsp[0].strval));
                    if((yyval.t.v.fval)==0.0 && val==0)
                    {
                    printf("Variable ");printf((yyvsp[0].strval));printf(" is used before initializing\n");checking=1;
                    }
                }
             else if(strcmp((yyval.t.type),"int")==0)
                {
                    //printf("yo\n");
                    (yyval.t.v.ival)=getintVal((yyvsp[0].strval));
                     int val=checkIn((yyvsp[0].strval));
                     //printf("yo\n");
                     if((yyval.t.v.ival)==0 && val==0)
                    {
                        printf("Variable ");printf((yyvsp[0].strval));printf(" is used before initializing\n");checking=1;
                    }
                }
                else if(strcmp((yyval.t.type),"char")==0)
                {
                     (yyval.t.v.cval)=getcharVal((yyvsp[0].strval));
                      int val=checkIn((yyvsp[0].strval));
                     if((yyval.t.v.cval)=='@' && val==0)
                    {
                         printf("Variable ");printf((yyvsp[0].strval));printf(" is used before initializing\n");checking=1;
                    }
                }
                else if(strcmp((yyval.t.type),"bool")==0)
                {
                     (yyval.t.v.ival)=getintVal((yyvsp[0].strval));
                     int val=checkIn((yyvsp[0].strval));
                     //printf("yo\n");
                     if((yyval.t.v.ival)==0 && val==0)
                    {
                        printf("Variable ");printf((yyvsp[0].strval));printf(" is used before initializing\n");checking=1;
                    }
                }
 }
    }
#line 2598 "y.tab.c"
    break;

  case 66: /* v: OB ARR CB  */
#line 1049 "VAPS5421.y"
                {if(isIdPresent((yyvsp[-1].strval))==1){strcpy((yyval.t.type), findType((yyvsp[-1].strval)));
                
               // printf($1);printf("\n");printf($<t.type>$);printf("\n");printf("factor\n");
                if(strcmp((yyval.t.type),"real")==0)
                {
                   (yyval.t.v.fval)=getrealVal((yyvsp[-1].strval));
                   int val=checkIn((yyvsp[-1].strval));
                    if((yyval.t.v.fval)==0.0 && val==0)
                    {
                    printf("Variable ");printf((yyvsp[-1].strval));printf(" is used before initializing\n");checking=1;
                    }
                }
             else if(strcmp((yyval.t.type),"int")==0)
                {
                    //printf("yo\n");
                    (yyval.t.v.ival)=getintVal((yyvsp[-1].strval));
                     int val=checkIn((yyvsp[-1].strval));
                     //printf("yo\n");
                     if((yyval.t.v.ival)==0 && val==0)
                    {
                        printf("Variable ");printf((yyvsp[-1].strval));printf(" is used before initializing\n");checking=1;
                    }
                }
                else if(strcmp((yyval.t.type),"char")==0)
                {
                     (yyval.t.v.cval)=getcharVal((yyvsp[-1].strval));
                      int val=checkIn((yyvsp[-1].strval));
                     if((yyval.t.v.cval)=='@' && val==0)
                    {
                         printf("Variable ");printf((yyvsp[-1].strval));printf(" is used before initializing\n");checking=1;
                    }
                }
                else if(strcmp((yyval.t.type),"bool")==0)
                {
                     (yyval.t.v.ival)=getintVal((yyvsp[-1].strval));
                     int val=checkIn((yyvsp[-1].strval));
                     //printf("yo\n");
                     if((yyval.t.v.ival)==0 && val==0)
                    {
                        printf("Variable ");printf((yyvsp[-1].strval));printf(" is used before initializing\n");checking=1;
                    }
                }
 }
    }
#line 2647 "y.tab.c"
    break;

  case 74: /* loop_stmt: WHILE v DO BEG stmt_block SC END  */
#line 1104 "VAPS5421.y"
                                               {if (strcmp((yyvsp[-5].t.type),"bool")!=0 ) {printf("Error:Variable must be boolean type\n");checking=1;} }
#line 2653 "y.tab.c"
    break;

  case 80: /* read_id: ID  */
#line 1112 "VAPS5421.y"
             {
                    char name[50];
                    strcpy(name, (yyvsp[0].strval));
                    initialize(name);}
#line 2662 "y.tab.c"
    break;

  case 81: /* read_id: ARR  */
#line 1116 "VAPS5421.y"
      {
                    char name[50];
                    strcpy(name, (yyvsp[0].strval));
                    initialize(name);}
#line 2671 "y.tab.c"
    break;


#line 2675 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1134 "VAPS5421.y"

void yyerror()
{
    printTable();
    printf("Syntax Error\n");
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    yyin = file;
    yyparse();
     checkBeforeDec();
     //printTable();
    if(checking==0)
        printf("Semantically correct!\n");
    fclose(file);
    return 0;
}
