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

    void printTable();
   
    extern FILE *yyin;
     int iflabel = 0;
     int whilelabel=0;
     int forlabel=0;
    int tempVariable = 0;

    char* genTempVariable(int id){
        char* temp = (char*)malloc(10*sizeof(char));
        temp[0] = 't';
        snprintf(temp, 10, "t%d", id);
        return temp;
    }

    int gencode(char* lhs, char* op, char* rhs){
        printf("t%d = %s %s %s \n", tempVariable, lhs, op, rhs);
        return tempVariable;
    }

    void assignment(char* lhs, char* rhs){
        printf("%s = %s \n", lhs, rhs);
    }
void conditional_jump(char* cond, int label,int check){
    if(check==1)
    printf("If %s goto I%d\n", cond, label);
    else if(check==2)
    printf("If not %s goto W%d\n", cond, label);
    else if(check==3)
    printf("If %s goto F%d\n", cond, label);
}
void for_jump(char* cond, int label,int check,char* expr){
    if(check==1)
    printf("If %s > %s goto F%d\n", cond,expr, label);
    else if(check==2)
    printf("If %s < %s goto F%d\n", cond,expr, label);
}

void unconditional_jump(int label,int check){
    if(check==1)
    printf("goto I%d\n", label);
    else if(check==2)
     printf("goto W%d\n", label);
     else if(check==3)
     printf("goto F%d\n", label);
}

void label_statement(int label,int check){
    
    if(check==1)
    printf("I%d:\n", label);
    else if(check==2)
    printf("W%d:\n", label);
    else if(check==3)
    printf("F%d:\n", label);
}


#line 137 "y.tab.c"

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

#line 308 "y.tab.c"

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
  YYSYMBOL_ID = 7,                         /* ID  */
  YYSYMBOL_SC = 8,                         /* SC  */
  YYSYMBOL_TYPE = 9,                       /* TYPE  */
  YYSYMBOL_EQ = 10,                        /* EQ  */
  YYSYMBOL_ARR = 11,                       /* ARR  */
  YYSYMBOL_OF = 12,                        /* OF  */
  YYSYMBOL_COMMENT = 13,                   /* COMMENT  */
  YYSYMBOL_COLON = 14,                     /* COLON  */
  YYSYMBOL_BEG = 15,                       /* BEG  */
  YYSYMBOL_READ = 16,                      /* READ  */
  YYSYMBOL_OB = 17,                        /* OB  */
  YYSYMBOL_CB = 18,                        /* CB  */
  YYSYMBOL_WRITE = 19,                     /* WRITE  */
  YYSYMBOL_STRING = 20,                    /* STRING  */
  YYSYMBOL_COMMA = 21,                     /* COMMA  */
  YYSYMBOL_FOR = 22,                       /* FOR  */
  YYSYMBOL_ASSIGN = 23,                    /* ASSIGN  */
  YYSYMBOL_DO = 24,                        /* DO  */
  YYSYMBOL_INT_LITERAL = 25,               /* INT_LITERAL  */
  YYSYMBOL_REAL_LITERAL = 26,              /* REAL_LITERAL  */
  YYSYMBOL_BOOLEAN_LITERAL = 27,           /* BOOLEAN_LITERAL  */
  YYSYMBOL_CHAR_LITERAL = 28,              /* CHAR_LITERAL  */
  YYSYMBOL_VAR = 29,                       /* VAR  */
  YYSYMBOL_NOTEQ = 30,                     /* NOTEQ  */
  YYSYMBOL_LT = 31,                        /* LT  */
  YYSYMBOL_GT = 32,                        /* GT  */
  YYSYMBOL_GTEQ = 33,                      /* GTEQ  */
  YYSYMBOL_LTEQ = 34,                      /* LTEQ  */
  YYSYMBOL_PLUS = 35,                      /* PLUS  */
  YYSYMBOL_MINUS = 36,                     /* MINUS  */
  YYSYMBOL_MUL = 37,                       /* MUL  */
  YYSYMBOL_DIV = 38,                       /* DIV  */
  YYSYMBOL_MOD = 39,                       /* MOD  */
  YYSYMBOL_AND = 40,                       /* AND  */
  YYSYMBOL_OR = 41,                        /* OR  */
  YYSYMBOL_NOT = 42,                       /* NOT  */
  YYSYMBOL_IF = 43,                        /* IF  */
  YYSYMBOL_THEN = 44,                      /* THEN  */
  YYSYMBOL_ELSE = 45,                      /* ELSE  */
  YYSYMBOL_END = 46,                       /* END  */
  YYSYMBOL_DOT = 47,                       /* DOT  */
  YYSYMBOL_INT = 48,                       /* INT  */
  YYSYMBOL_REAL = 49,                      /* REAL  */
  YYSYMBOL_CHAR = 50,                      /* CHAR  */
  YYSYMBOL_BOOLEAN = 51,                   /* BOOLEAN  */
  YYSYMBOL_TO = 52,                        /* TO  */
  YYSYMBOL_WHILE = 53,                     /* WHILE  */
  YYSYMBOL_ARRAY = 54,                     /* ARRAY  */
  YYSYMBOL_OPENBRAC = 55,                  /* OPENBRAC  */
  YYSYMBOL_CLOSEBRAC = 56,                 /* CLOSEBRAC  */
  YYSYMBOL_OPENPARA = 57,                  /* OPENPARA  */
  YYSYMBOL_CLOSEPARA = 58,                 /* CLOSEPARA  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_start = 60,                     /* start  */
  YYSYMBOL_program = 61,                   /* program  */
  YYSYMBOL_program_name = 62,              /* program_name  */
  YYSYMBOL_var_dec_sec = 63,               /* var_dec_sec  */
  YYSYMBOL_var_dec_list = 64,              /* var_dec_list  */
  YYSYMBOL_var_dec = 65,                   /* var_dec  */
  YYSYMBOL_id_list = 66,                   /* id_list  */
  YYSYMBOL_type = 67,                      /* type  */
  YYSYMBOL_main_prog_block = 68,           /* main_prog_block  */
  YYSYMBOL_stmt_block = 69,                /* stmt_block  */
  YYSYMBOL_stmt = 70,                      /* stmt  */
  YYSYMBOL_assign_stmt = 71,               /* assign_stmt  */
  YYSYMBOL_expr = 72,                      /* expr  */
  YYSYMBOL_term = 73,                      /* term  */
  YYSYMBOL_factor = 74,                    /* factor  */
  YYSYMBOL_value = 75,                     /* value  */
  YYSYMBOL_conditional_stmt = 76,          /* conditional_stmt  */
  YYSYMBOL_77_1 = 77,                      /* $@1  */
  YYSYMBOL_78_2 = 78,                      /* $@2  */
  YYSYMBOL_v = 79,                         /* v  */
  YYSYMBOL_maybe_else_block = 80,          /* maybe_else_block  */
  YYSYMBOL_81_3 = 81,                      /* $@3  */
  YYSYMBOL_bool_expr = 82,                 /* bool_expr  */
  YYSYMBOL_e = 83,                         /* e  */
  YYSYMBOL_rel_op = 84,                    /* rel_op  */
  YYSYMBOL_loop_stmt = 85,                 /* loop_stmt  */
  YYSYMBOL_86_4 = 86,                      /* $@4  */
  YYSYMBOL_87_5 = 87,                      /* $@5  */
  YYSYMBOL_88_6 = 88,                      /* $@6  */
  YYSYMBOL_89_7 = 89,                      /* $@7  */
  YYSYMBOL_read_stmt = 90,                 /* read_stmt  */
  YYSYMBOL_read_list = 91,                 /* read_list  */
  YYSYMBOL_read_id = 92,                   /* read_id  */
  YYSYMBOL_arr = 93,                       /* arr  */
  YYSYMBOL_write_stmt = 94,                /* write_stmt  */
  YYSYMBOL_write_param = 95                /* write_param  */
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
#define YYLAST   300

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  199

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   312


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
      56,    57,    58
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    82,    82,    85,    88,    91,    94,    95,    98,   101,
     102,   103,   106,   107,   108,   109,   110,   113,   115,   116,
     117,   119,   120,   121,   122,   123,   126,   127,   129,   135,
     141,   143,   149,   155,   161,   165,   166,   167,   168,   169,
     177,   178,   179,   180,   181,   183,   183,   188,   188,   194,
     195,   196,   197,   199,   200,   200,   206,   210,   214,   218,
     222,   223,   227,   231,   235,   239,   243,   247,   251,   256,
     262,   263,   264,   265,   266,   267,   270,   270,   277,   277,
     284,   284,   293,   293,   305,   307,   307,   308,   308,   309,
     309,   310,   313,   314,   315,   316
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
  "UMINUS", "PROGRAM", "ID", "SC", "TYPE", "EQ", "ARR", "OF", "COMMENT",
  "COLON", "BEG", "READ", "OB", "CB", "WRITE", "STRING", "COMMA", "FOR",
  "ASSIGN", "DO", "INT_LITERAL", "REAL_LITERAL", "BOOLEAN_LITERAL",
  "CHAR_LITERAL", "VAR", "NOTEQ", "LT", "GT", "GTEQ", "LTEQ", "PLUS",
  "MINUS", "MUL", "DIV", "MOD", "AND", "OR", "NOT", "IF", "THEN", "ELSE",
  "END", "DOT", "INT", "REAL", "CHAR", "BOOLEAN", "TO", "WHILE", "ARRAY",
  "OPENBRAC", "CLOSEBRAC", "OPENPARA", "CLOSEPARA", "$accept", "start",
  "program", "program_name", "var_dec_sec", "var_dec_list", "var_dec",
  "id_list", "type", "main_prog_block", "stmt_block", "stmt",
  "assign_stmt", "expr", "term", "factor", "value", "conditional_stmt",
  "$@1", "$@2", "v", "maybe_else_block", "$@3", "bool_expr", "e", "rel_op",
  "loop_stmt", "$@4", "$@5", "$@6", "$@7", "read_stmt", "read_list",
  "read_id", "arr", "write_stmt", "write_param", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-143)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-55)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,     8,    24,  -143,  -143,    18,  -143,    32,     1,    52,
      -7,    20,    98,  -143,    21,  -143,   187,  -143,   257,    -9,
       1,   246,   105,   101,   103,   115,   133,    -2,   211,   211,
     159,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,   257,
    -143,  -143,  -143,  -143,  -143,   257,    34,   177,  -143,  -143,
     132,  -143,  -143,  -143,  -143,  -143,   127,  -143,  -143,   257,
     257,   166,     3,     2,    48,   119,   234,   211,   256,   107,
     140,    95,   116,    25,   136,  -143,   257,   257,  -143,   257,
     257,   257,   143,    -9,    79,    79,  -143,  -143,   179,   149,
     183,  -143,  -143,   189,   257,   257,    19,    22,    69,   152,
      33,  -143,  -143,   163,  -143,  -143,  -143,  -143,  -143,   257,
     211,   211,  -143,   211,   211,  -143,  -143,  -143,   161,  -143,
    -143,   177,   177,  -143,  -143,  -143,    -9,   164,  -143,   166,
       3,  -143,    41,    86,  -143,  -143,  -143,   257,  -143,    79,
    -143,  -143,   172,   181,   187,  -143,  -143,   172,   181,   187,
     202,   204,  -143,   168,   178,  -143,  -143,  -143,  -143,    79,
      76,    76,   187,   187,  -143,    -9,   212,   214,   187,   187,
    -143,  -143,   224,   226,   186,   187,   187,   227,   109,   122,
     231,   236,   238,   123,  -143,  -143,   246,   142,   167,   203,
    -143,  -143,  -143,   205,   237,   187,   241,   180,  -143
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     1,     0,     0,     0,
       9,     0,     0,     6,     0,    11,    20,     3,     0,     0,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,    24,    25,    23,    21,    22,    35,    38,     0,
      44,    40,    41,    42,    43,     0,     0,    30,    34,    36,
       0,     7,    12,    13,    14,    15,     0,     8,    10,     0,
       0,     0,     0,     0,    35,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    39,     0,     0,    89,     0,
       0,     0,     0,     0,    27,    26,    87,    88,     0,    85,
      92,    95,    93,     0,     0,     0,    35,    38,     0,     0,
       0,    67,    57,    70,    71,    72,    73,    75,    74,     0,
       0,     0,    47,     0,     0,    45,    78,    76,     0,    19,
      37,    28,    29,    31,    32,    33,     0,     0,    84,     0,
       0,    91,     0,     0,    50,    52,    60,     0,    68,    56,
      62,    65,    61,    64,    20,    66,    58,    63,    59,    20,
       0,     0,    17,     0,     0,    86,    94,    82,    80,    69,
       0,     0,    20,    20,    90,     0,     0,     0,     0,    20,
      48,    46,     0,     0,     0,    20,    20,     0,     0,     0,
       0,     0,     0,     0,    79,    77,     0,     0,     0,    53,
      16,    83,    81,     0,     0,    20,     0,     0,    55
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -143,  -143,  -143,  -143,  -143,  -143,   235,  -143,    70,  -143,
    -142,   -70,   230,   -14,   124,   -23,   -19,  -143,  -143,  -143,
     -28,    97,  -143,   -17,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,   134,  -143,  -143,  -143,   135
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     5,     9,    12,    13,    14,    57,    17,
      30,    31,    32,    68,    47,    48,    49,    33,   149,   144,
      69,   170,   193,    70,   138,   109,    34,   151,   150,   167,
     166,    35,    88,    89,    15,    36,    93
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    71,   160,   119,    46,    23,    94,   161,    10,    24,
      90,    40,    72,     1,    91,     4,    41,    42,    43,    44,
     172,   173,    75,    40,     6,    74,     7,   177,    41,    42,
      43,    44,    23,   181,   182,    21,    24,   134,    99,   101,
     135,    25,    22,    92,    26,    84,    85,    27,    18,   100,
     102,   136,    98,   196,    95,    11,   123,   124,   125,   -49,
     -49,     8,   -51,   -51,   127,   157,   -49,    16,    28,    76,
      77,   118,   -49,   113,   114,    19,    76,    77,    29,   103,
     132,   133,   140,   142,   168,   145,   147,   120,   -49,   -49,
      78,   169,   -49,   141,   143,   139,   146,   148,   119,   104,
     105,   106,   107,   108,    76,    77,    20,   153,   119,   119,
     158,    92,    58,   119,    76,    77,    23,   119,   119,   116,
      24,    76,    77,   159,    59,    25,    60,   119,    26,    23,
      23,    27,    61,    24,    24,   110,   111,   -51,    25,    25,
     117,    26,    26,   -51,    27,    27,   174,   110,   111,    23,
      62,   112,    28,    24,   120,   184,   113,   114,    25,   -51,
     -51,    26,    29,   -51,    27,    28,    28,    73,   185,   189,
     129,    76,    77,    86,    23,    29,    29,    87,    24,    82,
     113,   114,    83,    25,   115,    28,    26,    23,   191,    27,
     126,    24,   110,   111,    23,    29,    25,   128,    24,    26,
     121,   122,    27,    25,   130,   137,    26,   131,   152,    27,
      28,   154,   110,   192,    79,    80,    81,   162,    64,   163,
      29,   113,    65,    28,   164,   165,   198,   175,    66,   176,
      28,    40,   178,    29,   179,   183,    41,    42,    43,    44,
      29,    96,   180,   186,   187,    97,   188,    45,   -54,   197,
     194,    66,   195,    67,    40,    51,   190,    63,   171,    41,
      42,    43,    44,   155,    37,   156,   103,     0,    38,     0,
      45,     0,     0,     0,    39,     0,    67,    40,     0,     0,
       0,     0,    41,    42,    43,    44,   104,   105,   106,   107,
     108,    76,    77,    45,    52,    53,    54,    55,     0,     0,
      56
};

static const yytype_int16 yycheck[] =
{
      19,    29,   144,    73,    18,     7,     4,   149,     7,    11,
       7,    20,    29,     6,    11,     7,    25,    26,    27,    28,
     162,   163,    45,    20,     0,    39,     8,   169,    25,    26,
      27,    28,     7,   175,   176,    14,    11,    18,    66,    67,
      18,    16,    21,    62,    19,    59,    60,    22,    55,    66,
      67,    18,    66,   195,    52,    54,    79,    80,    81,    40,
      41,    29,    40,    41,    83,    24,    18,    15,    43,    35,
      36,    46,    24,    40,    41,    55,    35,    36,    53,    10,
      94,    95,   110,   111,     8,   113,   114,    18,    40,    41,
      56,    15,    44,   110,   111,   109,   113,   114,   168,    30,
      31,    32,    33,    34,    35,    36,     8,   126,   178,   179,
      24,   130,     7,   183,    35,    36,     7,   187,   188,    24,
      11,    35,    36,   137,    23,    16,    23,   197,    19,     7,
       7,    22,    17,    11,    11,    40,    41,    18,    16,    16,
      24,    19,    19,    24,    22,    22,   165,    40,    41,     7,
      17,    44,    43,    11,    18,    46,    40,    41,    16,    40,
      41,    19,    53,    44,    22,    43,    43,     8,    46,    46,
      21,    35,    36,     7,     7,    53,    53,    11,    11,    47,
      40,    41,    55,    16,    44,    43,    19,     7,    46,    22,
      47,    11,    40,    41,     7,    53,    16,    18,    11,    19,
      76,    77,    22,    16,    21,    42,    19,    18,    47,    22,
      43,    47,    40,    46,    37,    38,    39,    15,     7,    15,
      53,    40,    11,    43,    56,    47,    46,    15,    17,    15,
      43,    20,     8,    53,     8,     8,    25,    26,    27,    28,
      53,     7,    56,    12,     8,    11,     8,    36,    45,     8,
      45,    17,    15,    42,    20,    20,   186,    27,   161,    25,
      26,    27,    28,   129,     7,   130,    10,    -1,    11,    -1,
      36,    -1,    -1,    -1,    17,    -1,    42,    20,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    30,    31,    32,    33,
      34,    35,    36,    36,    48,    49,    50,    51,    -1,    -1,
      54
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    60,    61,     7,    62,     0,     8,    29,    63,
       7,    54,    64,    65,    66,    93,    15,    68,    55,    55,
       8,    14,    21,     7,    11,    16,    19,    22,    43,    53,
      69,    70,    71,    76,    85,    90,    94,     7,    11,    17,
      20,    25,    26,    27,    28,    36,    72,    73,    74,    75,
      75,    65,    48,    49,    50,    51,    54,    67,     7,    23,
      23,    17,    17,    71,     7,    11,    17,    42,    72,    79,
      82,    79,    82,     8,    72,    74,    35,    36,    56,    37,
      38,    39,    47,    55,    72,    72,     7,    11,    91,    92,
       7,    11,    75,    95,     4,    52,     7,    11,    72,    79,
      82,    79,    82,    10,    30,    31,    32,    33,    34,    84,
      40,    41,    44,    40,    41,    44,    24,    24,    46,    70,
      18,    73,    73,    74,    74,    74,    47,    75,    18,    21,
      21,    18,    72,    72,    18,    18,    18,    42,    83,    72,
      79,    82,    79,    82,    78,    79,    82,    79,    82,    77,
      87,    86,    47,    75,    47,    91,    95,    24,    24,    72,
      69,    69,    15,    15,    56,    47,    89,    88,     8,    15,
      80,    80,    69,    69,    75,    15,    15,    69,     8,     8,
      56,    69,    69,     8,    46,    46,    12,     8,     8,    46,
      67,    46,    46,    81,    45,    15,    69,     8,    46
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    61,    62,    63,    64,    64,    65,    66,
      66,    66,    67,    67,    67,    67,    67,    68,    69,    69,
      69,    70,    70,    70,    70,    70,    71,    71,    72,    72,
      72,    73,    73,    73,    73,    74,    74,    74,    74,    74,
      75,    75,    75,    75,    75,    77,    76,    78,    76,    79,
      79,    79,    79,    80,    81,    80,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    83,
      84,    84,    84,    84,    84,    84,    86,    85,    87,    85,
      88,    85,    89,    85,    90,    91,    91,    92,    92,    93,
      93,    94,    95,    95,    95,    95
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     5,     1,     3,     1,     3,     3,     1,
       3,     1,     1,     1,     1,     1,     9,     5,     1,     3,
       0,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       1,     3,     3,     3,     1,     1,     1,     3,     1,     2,
       1,     1,     1,     1,     1,     0,     6,     0,     6,     1,
       3,     1,     3,     4,     0,    10,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     2,
       1,     1,     1,     1,     1,     1,     0,     8,     0,     8,
       0,    10,     0,    10,     4,     1,     3,     1,     1,     4,
       7,     4,     1,     1,     3,     1
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
  case 2: /* start: program  */
#line 82 "VAPS5421.y"
                {  }
#line 1536 "y.tab.c"
    break;

  case 26: /* assign_stmt: ARR ASSIGN expr  */
#line 126 "VAPS5421.y"
                               {assignment((yyvsp[-2].lexeme), (yyvsp[0].lexeme));}
#line 1542 "y.tab.c"
    break;

  case 27: /* assign_stmt: ID ASSIGN expr  */
#line 127 "VAPS5421.y"
                              {assignment((yyvsp[-2].lexeme), (yyvsp[0].lexeme));}
#line 1548 "y.tab.c"
    break;

  case 28: /* expr: expr PLUS term  */
#line 129 "VAPS5421.y"
                     {
                            int a = gencode((yyvsp[-2].lexeme), "+", (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;
                        }
#line 1559 "y.tab.c"
    break;

  case 29: /* expr: expr MINUS term  */
#line 135 "VAPS5421.y"
                       {
                            int a = gencode((yyvsp[-2].lexeme), "-", (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;
                        }
#line 1570 "y.tab.c"
    break;

  case 30: /* expr: term  */
#line 141 "VAPS5421.y"
            {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1576 "y.tab.c"
    break;

  case 31: /* term: term MUL factor  */
#line 143 "VAPS5421.y"
                       {
                            int a = gencode((yyvsp[-2].lexeme), "*", (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;
                        }
#line 1587 "y.tab.c"
    break;

  case 32: /* term: term DIV factor  */
#line 149 "VAPS5421.y"
                       {
                            int a = gencode((yyvsp[-2].lexeme), "/", (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;
                        }
#line 1598 "y.tab.c"
    break;

  case 33: /* term: term MOD factor  */
#line 155 "VAPS5421.y"
                       {
                            int a = gencode((yyvsp[-2].lexeme), "%", (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;
                        }
#line 1609 "y.tab.c"
    break;

  case 34: /* term: factor  */
#line 161 "VAPS5421.y"
              {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1615 "y.tab.c"
    break;

  case 35: /* factor: ID  */
#line 165 "VAPS5421.y"
             {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1621 "y.tab.c"
    break;

  case 36: /* factor: value  */
#line 166 "VAPS5421.y"
               {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1627 "y.tab.c"
    break;

  case 37: /* factor: OB expr CB  */
#line 167 "VAPS5421.y"
                     {(yyval.lexeme) = (yyvsp[-1].lexeme);}
#line 1633 "y.tab.c"
    break;

  case 38: /* factor: ARR  */
#line 168 "VAPS5421.y"
             {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1639 "y.tab.c"
    break;

  case 39: /* factor: MINUS factor  */
#line 169 "VAPS5421.y"
                                    {
                            int a = gencode("", "-", (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;
                        }
#line 1650 "y.tab.c"
    break;

  case 40: /* value: INT_LITERAL  */
#line 177 "VAPS5421.y"
                    {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1656 "y.tab.c"
    break;

  case 41: /* value: REAL_LITERAL  */
#line 178 "VAPS5421.y"
                     {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1662 "y.tab.c"
    break;

  case 42: /* value: BOOLEAN_LITERAL  */
#line 179 "VAPS5421.y"
                        {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1668 "y.tab.c"
    break;

  case 43: /* value: CHAR_LITERAL  */
#line 180 "VAPS5421.y"
                     {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1674 "y.tab.c"
    break;

  case 45: /* $@1: %empty  */
#line 183 "VAPS5421.y"
                                      {
                        conditional_jump((yyvsp[-1].lexeme), iflabel,1);
                        unconditional_jump(iflabel + 1,1);
                        label_statement(iflabel++,1);
                    }
#line 1684 "y.tab.c"
    break;

  case 47: /* $@2: %empty  */
#line 188 "VAPS5421.y"
                                 {
                        conditional_jump((yyvsp[-1].lexeme), iflabel,1);
                        unconditional_jump(iflabel + 1,1);
                        label_statement(iflabel++,1);
                    }
#line 1694 "y.tab.c"
    break;

  case 49: /* v: ID  */
#line 194 "VAPS5421.y"
       {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1700 "y.tab.c"
    break;

  case 50: /* v: OB ID CB  */
#line 195 "VAPS5421.y"
               {(yyval.lexeme) = (yyvsp[-1].lexeme);}
#line 1706 "y.tab.c"
    break;

  case 51: /* v: ARR  */
#line 196 "VAPS5421.y"
          {(yyval.lexeme) = (yyvsp[0].lexeme);}
#line 1712 "y.tab.c"
    break;

  case 52: /* v: OB ARR CB  */
#line 197 "VAPS5421.y"
                {(yyval.lexeme) = (yyvsp[-1].lexeme);}
#line 1718 "y.tab.c"
    break;

  case 53: /* maybe_else_block: BEG stmt_block SC END  */
#line 199 "VAPS5421.y"
                                         {label_statement(iflabel++,1);}
#line 1724 "y.tab.c"
    break;

  case 54: /* $@3: %empty  */
#line 200 "VAPS5421.y"
                                         {unconditional_jump(iflabel + 1,1);label_statement(iflabel++,1);}
#line 1730 "y.tab.c"
    break;

  case 55: /* maybe_else_block: BEG stmt_block SC END $@3 ELSE BEG stmt_block SC END  */
#line 200 "VAPS5421.y"
                                                                                                                                      {
                        label_statement(iflabel++,1);
                    }
#line 1738 "y.tab.c"
    break;

  case 56: /* bool_expr: expr rel_op expr  */
#line 206 "VAPS5421.y"
                            {int a = gencode((yyvsp[-2].lexeme), (yyvsp[-1].lexeme), (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;}
#line 1747 "y.tab.c"
    break;

  case 57: /* bool_expr: NOT bool_expr  */
#line 210 "VAPS5421.y"
                         {int a = gencode("", (yyvsp[-1].lexeme), (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;}
#line 1756 "y.tab.c"
    break;

  case 58: /* bool_expr: bool_expr AND bool_expr  */
#line 214 "VAPS5421.y"
                                   {int a = gencode((yyvsp[-2].lexeme), (yyvsp[-1].lexeme), (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;}
#line 1765 "y.tab.c"
    break;

  case 59: /* bool_expr: bool_expr OR bool_expr  */
#line 218 "VAPS5421.y"
                                  {int a = gencode((yyvsp[-2].lexeme), (yyvsp[-1].lexeme), (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;}
#line 1774 "y.tab.c"
    break;

  case 60: /* bool_expr: OB bool_expr CB  */
#line 222 "VAPS5421.y"
                            {(yyval.lexeme)=(yyvsp[-1].lexeme);}
#line 1780 "y.tab.c"
    break;

  case 61: /* bool_expr: v OR v  */
#line 223 "VAPS5421.y"
                   {int a = gencode((yyvsp[-2].lexeme), (yyvsp[-1].lexeme), (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;}
#line 1789 "y.tab.c"
    break;

  case 62: /* bool_expr: v AND v  */
#line 227 "VAPS5421.y"
                   {int a = gencode((yyvsp[-2].lexeme), (yyvsp[-1].lexeme), (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;}
#line 1798 "y.tab.c"
    break;

  case 63: /* bool_expr: bool_expr OR v  */
#line 231 "VAPS5421.y"
                          {int a = gencode((yyvsp[-2].lexeme), (yyvsp[-1].lexeme), (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;}
#line 1807 "y.tab.c"
    break;

  case 64: /* bool_expr: v OR bool_expr  */
#line 235 "VAPS5421.y"
                         {int a = gencode((yyvsp[-2].lexeme), (yyvsp[-1].lexeme), (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;}
#line 1816 "y.tab.c"
    break;

  case 65: /* bool_expr: v AND bool_expr  */
#line 239 "VAPS5421.y"
                          {int a = gencode((yyvsp[-2].lexeme), (yyvsp[-1].lexeme), (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;}
#line 1825 "y.tab.c"
    break;

  case 66: /* bool_expr: bool_expr AND v  */
#line 243 "VAPS5421.y"
                          {int a = gencode((yyvsp[-2].lexeme), (yyvsp[-1].lexeme), (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;}
#line 1834 "y.tab.c"
    break;

  case 67: /* bool_expr: NOT v  */
#line 247 "VAPS5421.y"
                {int a = gencode("", (yyvsp[-1].lexeme), (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;}
#line 1843 "y.tab.c"
    break;

  case 68: /* bool_expr: expr EQ e  */
#line 251 "VAPS5421.y"
                    {int a = gencode((yyvsp[-2].lexeme), (yyvsp[-1].lexeme), (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;}
#line 1852 "y.tab.c"
    break;

  case 69: /* e: NOT expr  */
#line 256 "VAPS5421.y"
             {int a = gencode("", (yyvsp[-1].lexeme), (yyvsp[0].lexeme));
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;}
#line 1861 "y.tab.c"
    break;

  case 76: /* $@4: %empty  */
#line 270 "VAPS5421.y"
                                {
                    
                    label_statement(whilelabel++,2);
                    conditional_jump((yyvsp[-1].lexeme), whilelabel,2);
                   
                    
                }
#line 1873 "y.tab.c"
    break;

  case 77: /* loop_stmt: WHILE bool_expr DO $@4 BEG stmt_block SC END  */
#line 276 "VAPS5421.y"
                                         {unconditional_jump(whilelabel-1,2);label_statement(whilelabel++,2);}
#line 1879 "y.tab.c"
    break;

  case 78: /* $@5: %empty  */
#line 277 "VAPS5421.y"
                              {
                    
                    label_statement(whilelabel++,2);
                    conditional_jump((yyvsp[-1].lexeme), whilelabel,2);
                   
                    
                }
#line 1891 "y.tab.c"
    break;

  case 79: /* loop_stmt: WHILE v DO $@5 BEG stmt_block SC END  */
#line 283 "VAPS5421.y"
                                         {unconditional_jump(whilelabel-1,2);label_statement(whilelabel++,2);}
#line 1897 "y.tab.c"
    break;

  case 80: /* $@6: %empty  */
#line 284 "VAPS5421.y"
                                       {
                   label_statement(forlabel++,3);
                    for_jump((yyvsp[-3].lexeme), forlabel,1,(yyvsp[-1].lexeme));
                }
#line 1906 "y.tab.c"
    break;

  case 81: /* loop_stmt: FOR assign_stmt TO expr DO $@6 BEG stmt_block SC END  */
#line 287 "VAPS5421.y"
                                        {int a = gencode((yyvsp[-8].lexeme), "+", "1");
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;assignment((yyvsp[-8].lexeme), (yyval.lexeme));unconditional_jump(forlabel-1,3);label_statement(forlabel++,3);int b = gencode((yyvsp[-8].lexeme), "-", "1");
                            char* tempVar1 = genTempVariable(b);
                            (yyval.lexeme) = tempVar1;tempVariable++;assignment((yyvsp[-8].lexeme), (yyval.lexeme));}
#line 1917 "y.tab.c"
    break;

  case 82: /* $@7: %empty  */
#line 293 "VAPS5421.y"
                                            {
                    label_statement(forlabel++,3);
                     for_jump((yyvsp[-3].lexeme), forlabel,2,(yyvsp[-1].lexeme));
                    
                }
#line 1927 "y.tab.c"
    break;

  case 83: /* loop_stmt: FOR assign_stmt DOWNTO expr DO $@7 BEG stmt_block SC END  */
#line 297 "VAPS5421.y"
                                        {int a = gencode((yyvsp[-8].lexeme), "-", "1");
                            char* tempVar = genTempVariable(a);
                            (yyval.lexeme) = tempVar;
                            tempVariable++;assignment((yyvsp[-8].lexeme), (yyval.lexeme));unconditional_jump(forlabel-1,3);label_statement(forlabel++,3);int b = gencode((yyvsp[-8].lexeme), "+", "1");
                            char* tempVar1 = genTempVariable(b);
                            (yyval.lexeme) = tempVar1;tempVariable++;assignment((yyvsp[-8].lexeme), (yyval.lexeme));}
#line 1938 "y.tab.c"
    break;


#line 1942 "y.tab.c"

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

#line 319 "VAPS5421.y"

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
   // printTable();
   fclose(file);
    return 0;
}





