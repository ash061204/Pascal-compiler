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
    int x=0;
    extern FILE *yyin;


#line 84 "y.tab.c"

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
typedef int YYSTYPE;
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
  YYSYMBOL_factor = 73,                    /* factor  */
  YYSYMBOL_value = 74,                     /* value  */
  YYSYMBOL_conditional_stmt = 75,          /* conditional_stmt  */
  YYSYMBOL_bool_expr = 76,                 /* bool_expr  */
  YYSYMBOL_rel_op = 77,                    /* rel_op  */
  YYSYMBOL_loop_stmt = 78,                 /* loop_stmt  */
  YYSYMBOL_read_stmt = 79,                 /* read_stmt  */
  YYSYMBOL_read_list = 80,                 /* read_list  */
  YYSYMBOL_read_id = 81,                   /* read_id  */
  YYSYMBOL_arr = 82,                       /* arr  */
  YYSYMBOL_write_stmt = 83,                /* write_stmt  */
  YYSYMBOL_write_param = 84                /* write_param  */
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
#define YYLAST   386

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

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
static const yytype_uint8 yyrline[] =
{
       0,    25,    25,    28,    31,    34,    37,    38,    41,    44,
      45,    46,    49,    50,    51,    52,    53,    56,    58,    59,
      60,    62,    63,    64,    65,    66,    69,    70,    72,    73,
      74,    75,    76,    77,    78,    81,    82,    83,    84,    85,
      88,    89,    90,    91,    92,    95,    96,    98,    99,   100,
     101,   102,   103,   104,   105,   107,   108,   109,   110,   111,
     112,   115,   116,   117,   118,   119,   120,   123,   125,   125,
     126,   126,   127,   127,   128,   131,   132,   133,   134
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
  "assign_stmt", "expr", "factor", "value", "conditional_stmt",
  "bool_expr", "rel_op", "loop_stmt", "read_stmt", "read_list", "read_id",
  "arr", "write_stmt", "write_param", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-126)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      20,     7,    28,  -126,  -126,    22,  -126,    29,     3,    17,
     -22,    10,    30,  -126,    -5,  -126,   274,  -126,    14,   358,
       3,    25,    56,     4,    52,    54,     6,   117,   117,    78,
    -126,  -126,  -126,  -126,  -126,    64,  -126,    14,   -22,    14,
    -126,  -126,  -126,  -126,  -126,    65,   192,  -126,  -126,  -126,
      42,  -126,  -126,  -126,  -126,  -126,    45,  -126,  -126,    14,
       8,   298,    -1,   117,   117,  -126,   333,    26,    -4,   142,
      14,     9,   176,  -126,    65,    65,    65,    65,    65,  -126,
      55,   358,   310,   -22,    88,    86,  -126,   -20,  -126,  -126,
      90,    14,    14,   303,    43,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,    14,   117,   117,    94,   150,    67,  -126,   310,
    -126,  -126,  -126,  -126,  -126,  -126,   358,    68,  -126,     8,
     298,  -126,   320,   338,    14,   117,   117,   310,  -126,    81,
     274,   274,  -126,  -126,    62,    79,  -126,  -126,   167,   183,
     262,   107,   -11,   119,   120,  -126,   358,   274,  -126,   274,
    -126,  -126,  -126,  -126,   200,   216,    76,   125,   127,    91,
    -126,   126,   233,   249,   135,    25,  -126,  -126,   274,  -126,
     132,   266,  -126
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     1,     0,     0,     0,
       9,     0,     0,     6,     0,    11,    20,     3,     0,     0,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,    24,    25,    23,    21,     0,    22,     0,    35,     0,
      44,    40,    41,    42,    43,     0,     0,    33,    36,    38,
       0,     7,    12,    13,    14,    15,     0,     8,    10,     0,
       0,     0,     0,     0,     0,    54,     0,     0,     0,     0,
       0,    34,     0,    39,     0,     0,     0,     0,     0,    72,
       0,     0,    27,    70,     0,    68,    71,    75,    76,    78,
       0,     0,     0,     0,     0,    49,    55,    56,    57,    58,
      60,    59,     0,     0,     0,     0,     0,     0,    19,    26,
      37,    28,    29,    30,    31,    32,     0,     0,    67,     0,
       0,    74,     0,     0,     0,     0,     0,    47,    50,    51,
      20,    20,    61,    17,     0,     0,    69,    77,     0,     0,
      47,    50,    51,     0,     0,    73,     0,    20,    65,    20,
      63,    48,    53,    52,     0,     0,     0,     0,     0,    45,
      62,     0,     0,     0,     0,     0,    66,    64,    20,    16,
       0,     0,    46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,  -126,  -126,  -126,  -126,  -126,   131,  -126,   -13,  -126,
    -125,   -58,   130,   -14,   103,   -17,  -126,    -9,    69,  -126,
    -126,    48,  -126,    -8,  -126,    50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     5,     9,    12,    13,    14,    57,    17,
      29,    30,    31,    66,    47,    48,    32,    67,   102,    33,
      34,    84,    85,    49,    36,    90
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      15,   120,    50,    91,    46,   143,   144,   153,    35,    21,
      10,   108,    15,    23,     4,    83,    22,    37,    35,    68,
     106,    38,   157,    71,   158,    72,     1,    59,     6,   103,
       7,    39,    16,    18,    40,    18,   103,   104,    20,    41,
      42,    43,    44,   170,    88,    82,    76,    77,   132,    93,
      45,    92,    86,    89,    94,    95,   109,    11,     8,    18,
      11,    35,    11,    58,   117,    19,   103,   104,    11,    60,
     105,    61,    38,    52,    53,    54,    55,   122,   123,    56,
     148,   150,    39,   125,   126,    40,    69,    70,   127,    80,
      41,    42,    43,    44,   128,   129,   108,   108,    35,   134,
      81,    45,   116,    88,   108,   108,   118,   119,   121,   130,
     140,    86,    89,   108,   133,   135,   141,   142,   145,    11,
      37,   103,    35,    35,    38,   152,   146,   154,   155,   156,
      35,    35,   161,   162,    63,   163,   164,    40,   165,    35,
     171,    35,    41,    42,    43,    44,    35,    35,    73,    23,
     168,    51,   169,    45,    35,    35,    62,    23,    24,    64,
      35,    25,   124,    35,    26,   131,    24,   136,    65,    25,
     137,    11,    26,     0,    23,     0,     0,   111,   112,   113,
     114,   115,   147,    24,     0,    27,    25,     0,   107,    26,
      23,     0,     0,    27,   110,    28,    11,     0,   149,    24,
       0,     0,    25,    28,    11,    26,     0,    23,     0,     0,
      27,    74,    75,    76,    77,    78,    24,     0,     0,    25,
      28,    11,    26,    23,     0,     0,    27,    74,    75,    76,
      77,    78,    24,     0,     0,    25,    28,    11,    26,     0,
      23,     0,     0,    27,     0,     0,   159,     0,    79,    24,
       0,     0,    25,    28,    11,    26,    23,     0,     0,    27,
       0,     0,   160,     0,     0,    24,     0,     0,    25,    28,
      11,    26,     0,    23,     0,     0,    27,     0,     0,   166,
     151,    23,    24,     0,     0,    25,    28,    11,    26,     0,
      24,     0,    27,    25,     0,   167,    26,    74,    75,    76,
      77,    78,    28,    11,     0,    87,     0,     0,     0,    27,
       0,     0,   172,    96,     0,     0,     0,    27,    40,    28,
      11,   110,     0,    41,    42,    43,    44,    28,    11,     0,
       0,     0,     0,    97,    98,    99,   100,   101,    74,    75,
      76,    77,    78,    96,   138,    74,    75,    76,    77,    78,
       0,     0,    11,     0,     0,    74,    75,    76,    77,    78,
       0,     0,   139,    97,    98,    99,   100,   101,    74,    75,
      76,    77,    78,    74,    75,    76,    77,    78,    40,     0,
       0,     0,     0,    41,    42,    43,    44
};

static const yytype_int16 yycheck[] =
{
       8,    21,    19,     4,    18,   130,   131,    18,    16,    14,
       7,    69,    20,     7,     7,     7,    21,     3,    26,    28,
      24,     7,   147,    37,   149,    39,     6,    23,     0,    40,
       8,    17,    15,    55,    20,    55,    40,    41,     8,    25,
      26,    27,    28,   168,    61,    59,    37,    38,   106,    63,
      36,    52,    60,    61,    63,    64,    70,    54,    29,    55,
      54,    69,    54,     7,    81,    55,    40,    41,    54,    17,
      44,    17,     7,    48,    49,    50,    51,    91,    92,    54,
     138,   139,    17,    40,    41,    20,     8,    23,   102,    47,
      25,    26,    27,    28,   103,   104,   154,   155,   106,   116,
      55,    36,    47,   120,   162,   163,    18,    21,    18,    15,
     124,   119,   120,   171,    47,    47,   125,   126,    56,    54,
       3,    40,   130,   131,     7,    18,    47,     8,     8,   146,
     138,   139,    56,     8,    17,     8,    45,    20,    12,   147,
       8,   149,    25,    26,    27,    28,   154,   155,    45,     7,
      15,    20,   165,    36,   162,   163,    26,     7,    16,    42,
     168,    19,    93,   171,    22,    15,    16,   119,    51,    19,
     120,    54,    22,    -1,     7,    -1,    -1,    74,    75,    76,
      77,    78,    15,    16,    -1,    43,    19,    -1,    46,    22,
       7,    -1,    -1,    43,    18,    53,    54,    -1,    15,    16,
      -1,    -1,    19,    53,    54,    22,    -1,     7,    -1,    -1,
      43,    35,    36,    37,    38,    39,    16,    -1,    -1,    19,
      53,    54,    22,     7,    -1,    -1,    43,    35,    36,    37,
      38,    39,    16,    -1,    -1,    19,    53,    54,    22,    -1,
       7,    -1,    -1,    43,    -1,    -1,    46,    -1,    56,    16,
      -1,    -1,    19,    53,    54,    22,     7,    -1,    -1,    43,
      -1,    -1,    46,    -1,    -1,    16,    -1,    -1,    19,    53,
      54,    22,    -1,     7,    -1,    -1,    43,    -1,    -1,    46,
      18,     7,    16,    -1,    -1,    19,    53,    54,    22,    -1,
      16,    -1,    43,    19,    -1,    46,    22,    35,    36,    37,
      38,    39,    53,    54,    -1,     7,    -1,    -1,    -1,    43,
      -1,    -1,    46,    10,    -1,    -1,    -1,    43,    20,    53,
      54,    18,    -1,    25,    26,    27,    28,    53,    54,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    10,    24,    35,    36,    37,    38,    39,
      -1,    -1,    54,    -1,    -1,    35,    36,    37,    38,    39,
      -1,    -1,    24,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    35,    36,    37,    38,    39,    20,    -1,
      -1,    -1,    -1,    25,    26,    27,    28
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    60,    61,     7,    62,     0,     8,    29,    63,
       7,    54,    64,    65,    66,    82,    15,    68,    55,    55,
       8,    14,    21,     7,    16,    19,    22,    43,    53,    69,
      70,    71,    75,    78,    79,    82,    83,     3,     7,    17,
      20,    25,    26,    27,    28,    36,    72,    73,    74,    82,
      74,    65,    48,    49,    50,    51,    54,    67,     7,    23,
      17,    17,    71,    17,    42,    51,    72,    76,    76,     8,
      23,    72,    72,    73,    35,    36,    37,    38,    39,    56,
      47,    55,    72,     7,    80,    81,    82,     7,    74,    82,
      84,     4,    52,    72,    76,    76,    10,    30,    31,    32,
      33,    34,    77,    40,    41,    44,    24,    46,    70,    72,
      18,    73,    73,    73,    73,    73,    47,    74,    18,    21,
      21,    18,    72,    72,    77,    40,    41,    72,    76,    76,
      15,    15,    70,    47,    74,    47,    80,    84,    24,    24,
      72,    76,    76,    69,    69,    56,    47,    15,    70,    15,
      70,    18,    18,    18,     8,     8,    74,    69,    69,    46,
      46,    56,     8,     8,    45,    12,    46,    46,    15,    67,
      69,     8,    46
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    61,    62,    63,    64,    64,    65,    66,
      66,    66,    67,    67,    67,    67,    67,    68,    69,    69,
      69,    70,    70,    70,    70,    70,    71,    71,    72,    72,
      72,    72,    72,    72,    72,    73,    73,    73,    73,    73,
      74,    74,    74,    74,    74,    75,    75,    76,    76,    76,
      76,    76,    76,    76,    76,    77,    77,    77,    77,    77,
      77,    78,    78,    78,    78,    78,    78,    79,    80,    80,
      81,    81,    82,    82,    83,    84,    84,    84,    84
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     5,     1,     3,     1,     3,     3,     1,
       3,     1,     1,     1,     1,     1,     9,     5,     1,     3,
       0,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     1,     2,     1,     1,     3,     1,     2,
       1,     1,     1,     1,     1,     7,    12,     3,     5,     2,
       3,     3,     5,     5,     1,     1,     1,     1,     1,     1,
       1,     4,     7,     6,     9,     6,     9,     4,     1,     3,
       1,     1,     4,     7,     4,     1,     1,     3,     1
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
#line 25 "VAPS5421.y"
                { printf("Valid Input!\n"); }
#line 1464 "y.tab.c"
    break;


#line 1468 "y.tab.c"

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

#line 137 "VAPS5421.y"

void yyerror()
{
    printTable();
    printf("Syntax Error\n");
    exit(0);
}

int main()
{
printf("Enter your input:\n");
      char fName[25];
  scanf("%s",fName);
      FILE *file = fopen(fName, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Initialize Flex
    yyin = file;

    yyparse();
   // printTable();
    return 0;
}





