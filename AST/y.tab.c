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

    #include<stdio.h>
    #include<stdlib.h>
    #include<math.h>
    #include<limits.h>
    #include<string.h>
    #include<ctype.h>
    #include "graph.c"
    extern FILE *yyin;
    int yylex();
    int ex (nodeType *p, int flag);
	/* function prototype to create a node for an operation */ 
	nodeType *opr(int oper, int nops, ...);
	/* function prototype to create a node for an identifier */
	nodeType *id(char *identifier);
	/* function prototype to create a node for a constat */
	nodeType *con(char *value);


#line 91 "y.tab.c"

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

#line 268 "y.tab.c"

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
  YYSYMBOL_PROG = 4,                       /* PROG  */
  YYSYMBOL_NUL = 5,                        /* NUL  */
  YYSYMBOL_DOWNTO = 6,                     /* DOWNTO  */
  YYSYMBOL_UMINUS = 7,                     /* UMINUS  */
  YYSYMBOL_PROGRAM = 8,                    /* PROGRAM  */
  YYSYMBOL_SC = 9,                         /* SC  */
  YYSYMBOL_TYPE = 10,                      /* TYPE  */
  YYSYMBOL_EQ = 11,                        /* EQ  */
  YYSYMBOL_OF = 12,                        /* OF  */
  YYSYMBOL_COMMENT = 13,                   /* COMMENT  */
  YYSYMBOL_COLON = 14,                     /* COLON  */
  YYSYMBOL_BEG = 15,                       /* BEG  */
  YYSYMBOL_READ = 16,                      /* READ  */
  YYSYMBOL_OB = 17,                        /* OB  */
  YYSYMBOL_CB = 18,                        /* CB  */
  YYSYMBOL_WRITE = 19,                     /* WRITE  */
  YYSYMBOL_COMMA = 20,                     /* COMMA  */
  YYSYMBOL_FOR = 21,                       /* FOR  */
  YYSYMBOL_ASSIGN = 22,                    /* ASSIGN  */
  YYSYMBOL_DO = 23,                        /* DO  */
  YYSYMBOL_VAR = 24,                       /* VAR  */
  YYSYMBOL_NOTEQ = 25,                     /* NOTEQ  */
  YYSYMBOL_LT = 26,                        /* LT  */
  YYSYMBOL_GT = 27,                        /* GT  */
  YYSYMBOL_GTEQ = 28,                      /* GTEQ  */
  YYSYMBOL_LTEQ = 29,                      /* LTEQ  */
  YYSYMBOL_PLUS = 30,                      /* PLUS  */
  YYSYMBOL_MINUS = 31,                     /* MINUS  */
  YYSYMBOL_MUL = 32,                       /* MUL  */
  YYSYMBOL_DIV = 33,                       /* DIV  */
  YYSYMBOL_MOD = 34,                       /* MOD  */
  YYSYMBOL_AND = 35,                       /* AND  */
  YYSYMBOL_OR = 36,                        /* OR  */
  YYSYMBOL_NOT = 37,                       /* NOT  */
  YYSYMBOL_IF = 38,                        /* IF  */
  YYSYMBOL_THEN = 39,                      /* THEN  */
  YYSYMBOL_ELSE = 40,                      /* ELSE  */
  YYSYMBOL_END = 41,                       /* END  */
  YYSYMBOL_DOT = 42,                       /* DOT  */
  YYSYMBOL_INT = 43,                       /* INT  */
  YYSYMBOL_REAL = 44,                      /* REAL  */
  YYSYMBOL_CHAR = 45,                      /* CHAR  */
  YYSYMBOL_BOOLEAN = 46,                   /* BOOLEAN  */
  YYSYMBOL_TO = 47,                        /* TO  */
  YYSYMBOL_WHILE = 48,                     /* WHILE  */
  YYSYMBOL_ARRAY = 49,                     /* ARRAY  */
  YYSYMBOL_OPENBRAC = 50,                  /* OPENBRAC  */
  YYSYMBOL_CLOSEBRAC = 51,                 /* CLOSEBRAC  */
  YYSYMBOL_OPENPARA = 52,                  /* OPENPARA  */
  YYSYMBOL_CLOSEPARA = 53,                 /* CLOSEPARA  */
  YYSYMBOL_ARR = 54,                       /* ARR  */
  YYSYMBOL_ID = 55,                        /* ID  */
  YYSYMBOL_INT_LITERAL = 56,               /* INT_LITERAL  */
  YYSYMBOL_STRING = 57,                    /* STRING  */
  YYSYMBOL_CHAR_LITERAL = 58,              /* CHAR_LITERAL  */
  YYSYMBOL_REAL_LITERAL = 59,              /* REAL_LITERAL  */
  YYSYMBOL_BOOLEAN_LITERAL = 60,           /* BOOLEAN_LITERAL  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_start = 62,                     /* start  */
  YYSYMBOL_program = 63,                   /* program  */
  YYSYMBOL_program_name = 64,              /* program_name  */
  YYSYMBOL_var_dec_sec = 65,               /* var_dec_sec  */
  YYSYMBOL_var_dec_list = 66,              /* var_dec_list  */
  YYSYMBOL_var_dec = 67,                   /* var_dec  */
  YYSYMBOL_id_list = 68,                   /* id_list  */
  YYSYMBOL_type = 69,                      /* type  */
  YYSYMBOL_main_prog_block = 70,           /* main_prog_block  */
  YYSYMBOL_stmt_block = 71,                /* stmt_block  */
  YYSYMBOL_stmt = 72,                      /* stmt  */
  YYSYMBOL_assign_stmt = 73,               /* assign_stmt  */
  YYSYMBOL_expr = 74,                      /* expr  */
  YYSYMBOL_term = 75,                      /* term  */
  YYSYMBOL_factor = 76,                    /* factor  */
  YYSYMBOL_value = 77,                     /* value  */
  YYSYMBOL_conditional_stmt = 78,          /* conditional_stmt  */
  YYSYMBOL_bool_expr = 79,                 /* bool_expr  */
  YYSYMBOL_e = 80,                         /* e  */
  YYSYMBOL_v = 81,                         /* v  */
  YYSYMBOL_loop_stmt = 82,                 /* loop_stmt  */
  YYSYMBOL_read_stmt = 83,                 /* read_stmt  */
  YYSYMBOL_read_list = 84,                 /* read_list  */
  YYSYMBOL_read_id = 85,                   /* read_id  */
  YYSYMBOL_write_stmt = 86,                /* write_stmt  */
  YYSYMBOL_write_param = 87                /* write_param  */
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
#define YYLAST   259

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  203

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   314


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
      56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    41,    41,    44,    47,    50,    53,    54,    57,    60,
      61,    62,    65,    66,    67,    68,    69,    72,    74,    75,
      77,    78,    79,    80,    81,    84,    85,    87,    88,    89,
      91,    92,    93,    94,    98,    99,   100,   101,   102,   105,
     106,   107,   108,   109,   111,   112,   113,   114,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   139,   140,   141,   142,
     143,   148,   149,   150,   151,   152,   153,   156,   158,   159,
     161,   162,   164,   167,   168,   169,   170
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
  "\"end of file\"", "error", "\"invalid token\"", "'-'", "PROG", "NUL",
  "DOWNTO", "UMINUS", "PROGRAM", "SC", "TYPE", "EQ", "OF", "COMMENT",
  "COLON", "BEG", "READ", "OB", "CB", "WRITE", "COMMA", "FOR", "ASSIGN",
  "DO", "VAR", "NOTEQ", "LT", "GT", "GTEQ", "LTEQ", "PLUS", "MINUS", "MUL",
  "DIV", "MOD", "AND", "OR", "NOT", "IF", "THEN", "ELSE", "END", "DOT",
  "INT", "REAL", "CHAR", "BOOLEAN", "TO", "WHILE", "ARRAY", "OPENBRAC",
  "CLOSEBRAC", "OPENPARA", "CLOSEPARA", "ARR", "ID", "INT_LITERAL",
  "STRING", "CHAR_LITERAL", "REAL_LITERAL", "BOOLEAN_LITERAL", "$accept",
  "start", "program", "program_name", "var_dec_sec", "var_dec_list",
  "var_dec", "id_list", "type", "main_prog_block", "stmt_block", "stmt",
  "assign_stmt", "expr", "term", "factor", "value", "conditional_stmt",
  "bool_expr", "e", "v", "loop_stmt", "read_stmt", "read_list", "read_id",
  "write_stmt", "write_param", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-54)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-70)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,   -53,    11,   -54,   -54,     5,   -54,     1,   -38,    16,
     -54,   -54,    27,   -54,    -7,   130,   -54,   -38,   176,    24,
      29,    31,    66,    10,    10,    38,    49,    41,   130,    88,
      94,   108,   110,   118,   -54,   -54,   -54,   -54,   -54,    35,
     -54,   -54,    81,   158,   128,   132,    74,    18,    10,    65,
     144,   -54,   -54,   -54,   -54,   -54,   171,    76,   -54,   -54,
     188,   193,    22,    71,    18,    18,   119,   -54,   -54,   -54,
     -54,   -54,   -54,   148,   -54,   -54,   157,   166,   -54,   167,
     -54,   177,    18,    18,   -12,    -6,   163,    63,   102,    18,
     -54,   -54,   -54,   -54,   -54,    85,    18,    18,    18,    18,
      18,    18,    18,    18,    18,    18,    10,    10,   149,    10,
      10,   151,   194,   211,   117,   117,   -54,   189,   -54,    81,
     158,   -54,     9,    12,   -54,   -54,   -54,   -54,    -9,    18,
     117,   -54,   117,   117,   117,   117,   117,    76,    76,   -54,
     -54,   -54,   -54,   -54,   195,   198,   130,   -54,   -54,   195,
     198,   130,   130,   130,   192,   -54,   -54,    18,    18,    18,
      18,   117,   196,   197,   199,   200,   148,   140,   142,   146,
     180,   202,   203,   -54,   -54,   184,   221,   224,   229,   230,
     231,   232,   236,   130,   130,   130,   130,   130,   130,   176,
     208,   209,   210,   212,   213,   214,   -54,   -54,   -54,   -54,
     -54,   -54,   -54
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     1,     0,     0,     0,
      11,     9,     0,     6,     0,     0,     3,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,     0,
       0,     0,     0,     0,     7,    12,    13,    14,    15,     0,
       8,    10,     0,     0,     0,     0,     0,     0,     0,    37,
      34,    39,    43,    42,    40,    41,     0,    29,    33,    35,
       0,     0,     0,     0,     0,     0,     0,    19,    23,    24,
      22,    20,    21,     0,    81,    80,     0,    78,    86,    83,
      84,     0,     0,     0,    37,    34,     0,     0,     0,     0,
      37,    34,    38,    55,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    25,    26,    17,     0,    77,     0,
       0,    82,     0,     0,    70,    68,    36,    54,     0,     0,
      48,    65,    49,    50,    51,    53,    52,    27,    28,    30,
      31,    32,    56,    63,    57,    60,     0,    62,    59,    61,
      58,     0,     0,     0,     0,    79,    85,     0,     0,     0,
       0,    66,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    44,    46,    71,    72,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,    76,    75,    74,
      73,    45,    47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -54,   -54,   -54,   -54,   -54,   -54,   235,   -54,    67,   -54,
     -28,   -54,   -54,   -45,    51,   -42,   -40,   -54,   -20,   -54,
     -14,   -54,   -54,   138,   -54,   -54,   139
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     5,     9,    12,    13,    14,    40,    16,
      27,    28,    29,    56,    57,    58,    59,    30,    60,   131,
      61,    31,    32,    76,    77,    33,    81
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      67,    86,     4,    80,    62,    92,   124,    18,     1,   126,
      63,     6,   125,    19,     7,   157,    10,    11,   159,   114,
     115,   101,   102,   -69,   -69,     8,    87,    46,    93,   -67,
     -67,    15,    88,   117,    94,    89,    17,   122,   123,   101,
     102,    47,   101,   102,   128,   112,    42,    48,    43,    47,
     130,   132,   133,   134,   135,   136,   158,   106,   107,   160,
      64,   139,   140,   141,    49,    50,    51,    52,    53,    54,
      55,    65,    90,    91,    51,    52,    53,    54,    55,    41,
      80,   127,    66,   -69,   161,    73,   142,   144,   -69,   147,
     149,    46,   143,   145,   113,   148,   150,    68,   106,   107,
     -69,   -69,    89,    69,   -69,    47,   109,   110,   103,   104,
     105,    48,   167,   168,   169,   170,    47,    70,   162,    71,
      44,    45,   129,   163,   164,   165,   175,    72,    84,    85,
      51,    52,    53,    54,    55,    74,    75,   109,   110,    90,
      91,    51,    52,    53,    54,    55,    20,   101,   102,    21,
      82,    22,   137,   138,    83,   190,   191,   192,   193,   194,
     195,   116,   -67,   176,   146,   177,   151,   -67,    23,   178,
     101,   102,   101,   102,    95,   118,   101,   102,    24,   -67,
     -67,   126,    95,   -67,    25,    26,   119,   120,    96,    97,
      98,    99,   100,   101,   102,   121,    96,    97,    98,    99,
     100,   101,   102,   179,    51,    52,    53,    54,    55,   152,
     101,   102,    78,    79,    51,    52,    53,    54,    55,    35,
      36,    37,    38,   106,   107,    39,   153,   108,   109,   110,
     106,   154,   111,   109,   166,   182,   183,   171,   172,   184,
     173,   174,   180,   181,   185,   186,   187,   188,   189,   197,
     198,   199,    34,   200,   201,   202,   196,   155,     0,   156
};

static const yytype_int16 yycheck[] =
{
      28,    46,    55,    43,    24,    47,    18,    14,     8,    18,
      24,     0,    18,    20,     9,     6,    54,    55,     6,    64,
      65,    30,    31,    35,    36,    24,    46,    17,    48,    35,
      36,    15,    46,    73,    48,    17,     9,    82,    83,    30,
      31,    31,    30,    31,    89,    23,    17,    37,    17,    31,
      95,    96,    97,    98,    99,   100,    47,    35,    36,    47,
      22,   103,   104,   105,    54,    55,    56,    57,    58,    59,
      60,    22,    54,    55,    56,    57,    58,    59,    60,    55,
     120,    18,    41,    18,   129,    50,   106,   107,    23,   109,
     110,    17,   106,   107,    23,   109,   110,     9,    35,    36,
      35,    36,    17,     9,    39,    31,    35,    36,    32,    33,
      34,    37,   157,   158,   159,   160,    31,     9,   146,     9,
      54,    55,    37,   151,   152,   153,   166,     9,    54,    55,
      56,    57,    58,    59,    60,    54,    55,    35,    36,    54,
      55,    56,    57,    58,    59,    60,    16,    30,    31,    19,
      22,    21,   101,   102,    22,   183,   184,   185,   186,   187,
     188,    42,    18,    23,    15,    23,    15,    23,    38,    23,
      30,    31,    30,    31,    11,    18,    30,    31,    48,    35,
      36,    18,    11,    39,    54,    55,    20,    20,    25,    26,
      27,    28,    29,    30,    31,    18,    25,    26,    27,    28,
      29,    30,    31,    23,    56,    57,    58,    59,    60,    15,
      30,    31,    54,    55,    56,    57,    58,    59,    60,    43,
      44,    45,    46,    35,    36,    49,    15,    39,    35,    36,
      35,    42,    39,    35,    42,    51,    15,    41,    41,    15,
      41,    41,    40,    40,    15,    15,    15,    15,    12,    41,
      41,    41,    17,    41,    41,    41,   189,   119,    -1,   120
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    62,    63,    55,    64,     0,     9,    24,    65,
      54,    55,    66,    67,    68,    15,    70,     9,    14,    20,
      16,    19,    21,    38,    48,    54,    55,    71,    72,    73,
      78,    82,    83,    86,    67,    43,    44,    45,    46,    49,
      69,    55,    17,    17,    54,    55,    17,    31,    37,    54,
      55,    56,    57,    58,    59,    60,    74,    75,    76,    77,
      79,    81,    79,    81,    22,    22,    41,    71,     9,     9,
       9,     9,     9,    50,    54,    55,    84,    85,    54,    55,
      77,    87,    22,    22,    54,    55,    74,    79,    81,    17,
      54,    55,    76,    79,    81,    11,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    39,    35,
      36,    39,    23,    23,    74,    74,    42,    77,    18,    20,
      20,    18,    74,    74,    18,    18,    18,    18,    74,    37,
      74,    80,    74,    74,    74,    74,    74,    75,    75,    76,
      76,    76,    79,    81,    79,    81,    15,    79,    81,    79,
      81,    15,    15,    15,    42,    84,    87,     6,    47,     6,
      47,    74,    71,    71,    71,    71,    42,    74,    74,    74,
      74,    41,    41,    41,    41,    77,    23,    23,    23,    23,
      40,    40,    51,    15,    15,    15,    15,    15,    15,    12,
      71,    71,    71,    71,    71,    71,    69,    41,    41,    41,
      41,    41,    41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    63,    64,    65,    66,    66,    67,    68,
      68,    68,    69,    69,    69,    69,    69,    70,    71,    71,
      72,    72,    72,    72,    72,    73,    73,    74,    74,    74,
      75,    75,    75,    75,    76,    76,    76,    76,    76,    77,
      77,    77,    77,    77,    78,    78,    78,    78,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    80,    81,    81,    81,
      81,    82,    82,    82,    82,    82,    82,    83,    84,    84,
      85,    85,    86,    87,    87,    87,    87
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     5,     1,     3,     1,     3,     3,     1,
       3,     1,     1,     1,     1,     1,     9,     4,     1,     2,
       2,     2,     2,     2,     2,     3,     3,     3,     3,     1,
       3,     3,     3,     1,     1,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     6,    10,     6,    10,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     2,     1,     3,     1,
       3,     6,     6,    10,    10,    10,    10,     4,     1,     3,
       1,     1,     4,     1,     1,     3,     1
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
#line 41 "VAPS5421.y"
                {ex((yyvsp[0].nPtr), 0);}
#line 1475 "y.tab.c"
    break;

  case 3: /* program: PROGRAM program_name SC var_dec_sec main_prog_block  */
#line 44 "VAPS5421.y"
                                                              {(yyval.nPtr) = opr(PROG, 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr));}
#line 1481 "y.tab.c"
    break;

  case 5: /* var_dec_sec: VAR var_dec_list SC  */
#line 50 "VAPS5421.y"
                                  {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1487 "y.tab.c"
    break;

  case 6: /* var_dec_list: var_dec  */
#line 53 "VAPS5421.y"
                       {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1493 "y.tab.c"
    break;

  case 7: /* var_dec_list: var_dec_list SC var_dec  */
#line 54 "VAPS5421.y"
                                       {(yyval.nPtr) = opr(';', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1499 "y.tab.c"
    break;

  case 8: /* var_dec: id_list COLON type  */
#line 57 "VAPS5421.y"
                             {(yyval.nPtr) = (yyvsp[-2].nPtr);}
#line 1505 "y.tab.c"
    break;

  case 9: /* id_list: ID  */
#line 60 "VAPS5421.y"
             {(yyval.nPtr) = id((yyvsp[0].string));}
#line 1511 "y.tab.c"
    break;

  case 10: /* id_list: id_list COMMA ID  */
#line 61 "VAPS5421.y"
                            {(yyval.nPtr) = opr(',', 2, (yyvsp[-2].nPtr), id((yyvsp[0].string)));}
#line 1517 "y.tab.c"
    break;

  case 11: /* id_list: ARR  */
#line 62 "VAPS5421.y"
              {(yyval.nPtr) = id((yyvsp[0].string));}
#line 1523 "y.tab.c"
    break;

  case 17: /* main_prog_block: BEG stmt_block END DOT  */
#line 72 "VAPS5421.y"
                                         {(yyval.nPtr)=(yyvsp[-2].nPtr);}
#line 1529 "y.tab.c"
    break;

  case 18: /* stmt_block: stmt  */
#line 74 "VAPS5421.y"
                  {(yyval.nPtr) = opr(';', 1, (yyvsp[0].nPtr));}
#line 1535 "y.tab.c"
    break;

  case 19: /* stmt_block: stmt stmt_block  */
#line 75 "VAPS5421.y"
                             {(yyval.nPtr) = opr(';', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr));}
#line 1541 "y.tab.c"
    break;

  case 20: /* stmt: read_stmt SC  */
#line 77 "VAPS5421.y"
                     {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1547 "y.tab.c"
    break;

  case 21: /* stmt: write_stmt SC  */
#line 78 "VAPS5421.y"
                      {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1553 "y.tab.c"
    break;

  case 22: /* stmt: loop_stmt SC  */
#line 79 "VAPS5421.y"
                     {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1559 "y.tab.c"
    break;

  case 23: /* stmt: assign_stmt SC  */
#line 80 "VAPS5421.y"
                       {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1565 "y.tab.c"
    break;

  case 24: /* stmt: conditional_stmt SC  */
#line 81 "VAPS5421.y"
                           {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1571 "y.tab.c"
    break;

  case 25: /* assign_stmt: ARR ASSIGN expr  */
#line 84 "VAPS5421.y"
                               {(yyval.nPtr) = opr('=', 2, id((yyvsp[-2].string)), (yyvsp[0].nPtr));}
#line 1577 "y.tab.c"
    break;

  case 26: /* assign_stmt: ID ASSIGN expr  */
#line 85 "VAPS5421.y"
                              {(yyval.nPtr) = opr('=', 2, id((yyvsp[-2].string)), (yyvsp[0].nPtr));}
#line 1583 "y.tab.c"
    break;

  case 27: /* expr: expr PLUS term  */
#line 87 "VAPS5421.y"
                      {(yyval.nPtr) = opr('+', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1589 "y.tab.c"
    break;

  case 28: /* expr: expr MINUS term  */
#line 88 "VAPS5421.y"
                       {(yyval.nPtr) = opr('-', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1595 "y.tab.c"
    break;

  case 29: /* expr: term  */
#line 89 "VAPS5421.y"
            {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1601 "y.tab.c"
    break;

  case 30: /* term: term MUL factor  */
#line 91 "VAPS5421.y"
                        {(yyval.nPtr) = opr('*', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1607 "y.tab.c"
    break;

  case 31: /* term: term DIV factor  */
#line 92 "VAPS5421.y"
                        {(yyval.nPtr) = opr('/', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1613 "y.tab.c"
    break;

  case 32: /* term: term MOD factor  */
#line 93 "VAPS5421.y"
                        {(yyval.nPtr) = opr('%', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1619 "y.tab.c"
    break;

  case 33: /* term: factor  */
#line 94 "VAPS5421.y"
              {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1625 "y.tab.c"
    break;

  case 34: /* factor: ID  */
#line 98 "VAPS5421.y"
             {(yyval.nPtr) = id((yyvsp[0].string));}
#line 1631 "y.tab.c"
    break;

  case 35: /* factor: value  */
#line 99 "VAPS5421.y"
               {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1637 "y.tab.c"
    break;

  case 36: /* factor: OB expr CB  */
#line 100 "VAPS5421.y"
                     {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1643 "y.tab.c"
    break;

  case 37: /* factor: ARR  */
#line 101 "VAPS5421.y"
             {(yyval.nPtr) = id((yyvsp[0].string));}
#line 1649 "y.tab.c"
    break;

  case 38: /* factor: MINUS factor  */
#line 102 "VAPS5421.y"
                                    {(yyval.nPtr)=opr('-',1,(yyvsp[0].nPtr));}
#line 1655 "y.tab.c"
    break;

  case 39: /* value: INT_LITERAL  */
#line 105 "VAPS5421.y"
                    {(yyval.nPtr) = con((yyvsp[0].string));}
#line 1661 "y.tab.c"
    break;

  case 40: /* value: REAL_LITERAL  */
#line 106 "VAPS5421.y"
                     {(yyval.nPtr) = con((yyvsp[0].string));}
#line 1667 "y.tab.c"
    break;

  case 41: /* value: BOOLEAN_LITERAL  */
#line 107 "VAPS5421.y"
                        {(yyval.nPtr) = con((yyvsp[0].string));}
#line 1673 "y.tab.c"
    break;

  case 42: /* value: CHAR_LITERAL  */
#line 108 "VAPS5421.y"
                     {(yyval.nPtr) = con((yyvsp[0].string));}
#line 1679 "y.tab.c"
    break;

  case 43: /* value: STRING  */
#line 109 "VAPS5421.y"
               {(yyval.nPtr) = con((yyvsp[0].string));}
#line 1685 "y.tab.c"
    break;

  case 44: /* conditional_stmt: IF bool_expr THEN BEG stmt_block END  */
#line 111 "VAPS5421.y"
                                                        {(yyval.nPtr) = opr(IF,2, (yyvsp[-4].nPtr), opr(THEN, 1, (yyvsp[-1].nPtr)));}
#line 1691 "y.tab.c"
    break;

  case 45: /* conditional_stmt: IF bool_expr THEN BEG stmt_block END ELSE BEG stmt_block END  */
#line 112 "VAPS5421.y"
                                                                                {(yyval.nPtr) = opr(IF, 3, (yyvsp[-8].nPtr), opr(THEN, 1, (yyvsp[-5].nPtr)), opr(ELSE, 1, (yyvsp[-1].nPtr)));}
#line 1697 "y.tab.c"
    break;

  case 46: /* conditional_stmt: IF v THEN BEG stmt_block END  */
#line 113 "VAPS5421.y"
                                                {(yyval.nPtr) = opr(IF,2, (yyvsp[-4].nPtr), opr(THEN, 1, (yyvsp[-1].nPtr)));}
#line 1703 "y.tab.c"
    break;

  case 47: /* conditional_stmt: IF v THEN BEG stmt_block END ELSE BEG stmt_block END  */
#line 114 "VAPS5421.y"
                                                                        {(yyval.nPtr) = opr(IF, 3, (yyvsp[-8].nPtr), opr(THEN, 1, (yyvsp[-5].nPtr)), opr(ELSE, 1, (yyvsp[-1].nPtr)));}
#line 1709 "y.tab.c"
    break;

  case 48: /* bool_expr: expr EQ expr  */
#line 120 "VAPS5421.y"
                        {(yyval.nPtr) = opr(EQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1715 "y.tab.c"
    break;

  case 49: /* bool_expr: expr NOTEQ expr  */
#line 121 "VAPS5421.y"
                           {(yyval.nPtr) = opr(NOTEQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1721 "y.tab.c"
    break;

  case 50: /* bool_expr: expr LT expr  */
#line 122 "VAPS5421.y"
                        {(yyval.nPtr) = opr(LT, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1727 "y.tab.c"
    break;

  case 51: /* bool_expr: expr GT expr  */
#line 123 "VAPS5421.y"
                       {(yyval.nPtr) = opr(GT, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1733 "y.tab.c"
    break;

  case 52: /* bool_expr: expr LTEQ expr  */
#line 124 "VAPS5421.y"
                          {(yyval.nPtr) = opr(LTEQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1739 "y.tab.c"
    break;

  case 53: /* bool_expr: expr GTEQ expr  */
#line 125 "VAPS5421.y"
                          {(yyval.nPtr) = opr(GTEQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1745 "y.tab.c"
    break;

  case 54: /* bool_expr: OB bool_expr CB  */
#line 126 "VAPS5421.y"
                            {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1751 "y.tab.c"
    break;

  case 55: /* bool_expr: NOT bool_expr  */
#line 127 "VAPS5421.y"
                         {(yyval.nPtr)=opr(NOT,1,(yyvsp[0].nPtr));}
#line 1757 "y.tab.c"
    break;

  case 56: /* bool_expr: bool_expr AND bool_expr  */
#line 128 "VAPS5421.y"
                                   {(yyval.nPtr) = opr(AND, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1763 "y.tab.c"
    break;

  case 57: /* bool_expr: bool_expr OR bool_expr  */
#line 129 "VAPS5421.y"
                                   {(yyval.nPtr) = opr(OR, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1769 "y.tab.c"
    break;

  case 58: /* bool_expr: v OR v  */
#line 130 "VAPS5421.y"
                   {(yyval.nPtr) = opr(OR, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1775 "y.tab.c"
    break;

  case 59: /* bool_expr: v AND v  */
#line 131 "VAPS5421.y"
                   {(yyval.nPtr) = opr(AND, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1781 "y.tab.c"
    break;

  case 60: /* bool_expr: bool_expr OR v  */
#line 132 "VAPS5421.y"
                          {(yyval.nPtr) = opr(OR, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1787 "y.tab.c"
    break;

  case 61: /* bool_expr: v OR bool_expr  */
#line 133 "VAPS5421.y"
                         {(yyval.nPtr) = opr(OR, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1793 "y.tab.c"
    break;

  case 62: /* bool_expr: v AND bool_expr  */
#line 134 "VAPS5421.y"
                          {(yyval.nPtr) = opr(AND, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1799 "y.tab.c"
    break;

  case 63: /* bool_expr: bool_expr AND v  */
#line 135 "VAPS5421.y"
                          {(yyval.nPtr) = opr(AND, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1805 "y.tab.c"
    break;

  case 64: /* bool_expr: NOT v  */
#line 136 "VAPS5421.y"
                {(yyval.nPtr)=opr(NOT,1,(yyvsp[0].nPtr));}
#line 1811 "y.tab.c"
    break;

  case 65: /* bool_expr: expr EQ e  */
#line 137 "VAPS5421.y"
                    {(yyval.nPtr) = opr(EQ, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1817 "y.tab.c"
    break;

  case 66: /* e: NOT expr  */
#line 139 "VAPS5421.y"
             {(yyval.nPtr)=opr(NOT,1,(yyvsp[0].nPtr));}
#line 1823 "y.tab.c"
    break;

  case 67: /* v: ID  */
#line 140 "VAPS5421.y"
       {(yyval.nPtr) = id((yyvsp[0].string));}
#line 1829 "y.tab.c"
    break;

  case 68: /* v: OB ID CB  */
#line 141 "VAPS5421.y"
               {(yyval.nPtr) = id((yyvsp[-1].string));}
#line 1835 "y.tab.c"
    break;

  case 69: /* v: ARR  */
#line 142 "VAPS5421.y"
          {(yyval.nPtr) = id((yyvsp[0].string));}
#line 1841 "y.tab.c"
    break;

  case 70: /* v: OB ARR CB  */
#line 143 "VAPS5421.y"
                {(yyval.nPtr) = id((yyvsp[-1].string));}
#line 1847 "y.tab.c"
    break;

  case 71: /* loop_stmt: WHILE bool_expr DO BEG stmt_block END  */
#line 148 "VAPS5421.y"
                                                   {(yyval.nPtr) = opr(WHILE, 2, (yyvsp[-4].nPtr), opr(DO, 1, (yyvsp[-1].nPtr)));}
#line 1853 "y.tab.c"
    break;

  case 72: /* loop_stmt: WHILE v DO BEG stmt_block END  */
#line 149 "VAPS5421.y"
                                             {(yyval.nPtr) = opr(WHILE, 2, (yyvsp[-4].nPtr), opr(DO, 1, (yyvsp[-1].nPtr)));}
#line 1859 "y.tab.c"
    break;

  case 73: /* loop_stmt: FOR ID ASSIGN expr TO expr DO BEG stmt_block END  */
#line 150 "VAPS5421.y"
                                                             {(yyval.nPtr) = opr(FOR, 3, opr('=', 2, id((yyvsp[-8].string)), (yyvsp[-6].nPtr)), opr(LTEQ, 2,id((yyvsp[-8].string)),(yyvsp[-4].nPtr)), opr(DO, 1, (yyvsp[-1].nPtr)));}
#line 1865 "y.tab.c"
    break;

  case 74: /* loop_stmt: FOR ID ASSIGN expr DOWNTO expr DO BEG stmt_block END  */
#line 151 "VAPS5421.y"
                                                                  {(yyval.nPtr) = opr(FOR, 3, opr('=', 2, id((yyvsp[-8].string)), (yyvsp[-6].nPtr)), opr(GTEQ, 2,id((yyvsp[-8].string)),(yyvsp[-4].nPtr)), opr(DO, 1, (yyvsp[-1].nPtr)));}
#line 1871 "y.tab.c"
    break;

  case 75: /* loop_stmt: FOR ARR ASSIGN expr TO expr DO BEG stmt_block END  */
#line 152 "VAPS5421.y"
                                                              {(yyval.nPtr) = opr(FOR, 3, opr('=', 2, id((yyvsp[-8].string)), (yyvsp[-6].nPtr)), opr(LTEQ, 2,id((yyvsp[-8].string)),(yyvsp[-4].nPtr)), opr(DO, 1, (yyvsp[-1].nPtr)));}
#line 1877 "y.tab.c"
    break;

  case 76: /* loop_stmt: FOR ARR ASSIGN expr DOWNTO expr DO BEG stmt_block END  */
#line 153 "VAPS5421.y"
                                                                   {(yyval.nPtr) = opr(FOR, 3, opr('=', 2, id((yyvsp[-8].string)), (yyvsp[-6].nPtr)), opr(GTEQ, 2,id((yyvsp[-8].string)),(yyvsp[-4].nPtr)), opr(DO, 1, (yyvsp[-1].nPtr)));}
#line 1883 "y.tab.c"
    break;

  case 77: /* read_stmt: READ OB read_list CB  */
#line 156 "VAPS5421.y"
                                 {(yyval.nPtr) = opr(READ, 1, (yyvsp[-1].nPtr));}
#line 1889 "y.tab.c"
    break;

  case 78: /* read_list: read_id  */
#line 158 "VAPS5421.y"
                    {(yyval.nPtr)=(yyvsp[0].nPtr);}
#line 1895 "y.tab.c"
    break;

  case 79: /* read_list: read_id COMMA read_list  */
#line 159 "VAPS5421.y"
                                      {(yyval.nPtr) = opr(',', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1901 "y.tab.c"
    break;

  case 80: /* read_id: ID  */
#line 161 "VAPS5421.y"
             {(yyval.nPtr) = id((yyvsp[0].string));}
#line 1907 "y.tab.c"
    break;

  case 81: /* read_id: ARR  */
#line 162 "VAPS5421.y"
              {(yyval.nPtr) = id((yyvsp[0].string));}
#line 1913 "y.tab.c"
    break;

  case 82: /* write_stmt: WRITE OB write_param CB  */
#line 164 "VAPS5421.y"
                                      {(yyval.nPtr) = opr(WRITE, 1, (yyvsp[-1].nPtr));}
#line 1919 "y.tab.c"
    break;

  case 83: /* write_param: ID  */
#line 167 "VAPS5421.y"
                 {(yyval.nPtr) = id((yyvsp[0].string));}
#line 1925 "y.tab.c"
    break;

  case 84: /* write_param: value  */
#line 168 "VAPS5421.y"
                    {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1931 "y.tab.c"
    break;

  case 85: /* write_param: ID COMMA write_param  */
#line 169 "VAPS5421.y"
                                   {(yyval.nPtr) = opr(',', 2, id((yyvsp[-2].string)), (yyvsp[0].nPtr));}
#line 1937 "y.tab.c"
    break;

  case 86: /* write_param: ARR  */
#line 170 "VAPS5421.y"
                 {(yyval.nPtr) = id((yyvsp[0].string));}
#line 1943 "y.tab.c"
    break;


#line 1947 "y.tab.c"

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

#line 173 "VAPS5421.y"


void yyerror()
{
    //printTable();
    printf("Syntax Error\n");
    exit(0);
}

int main()
{
    yyin = fopen("input.txt","r");
    yyparse();
    //printTable();
    return 0;
}

nodeType *con(char *value)
{
    
	nodeType *p;
	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
		yyerror("out of memory");
	/* copy information */
	p->type = typeCon;
    if(value[0]=='"')
    {
        strcpy(p->con.value, "string");
    }
    else
	   strcpy(p->con.value, value);
    //printf("The copied value %s\n", p->con.value);
	return p;
}
nodeType *id(char *identifier) {
	nodeType *p;
	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
		yyerror("out of memory");
	/* copy information */
	p->type = typeId;
	strcpy(p->id.name,identifier);
//	printf("The copied identifier %s\n", p->id.name);
	return p;
}

nodeType *opr(int oper, int nops, ...)
{
	va_list ap;
	nodeType *p;
	int i;
	/* allocate node, extending op array */
	if ((p = malloc(sizeof(nodeType) +(nops-1) * sizeof(nodeType *))) == NULL)
		yyerror("out of memory");
	/* copy information */
	p->type = typeOpr;
	p->opr.oper = oper;
	p->opr.nops = nops;
	va_start(ap, nops);
	for (i = 0; i < nops; i++)
		p->opr.op[i] = va_arg(ap, nodeType*);
	va_end(ap);
	return p;
}

