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
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h" // again, how did you forget to include it TWICE... TWICE!

int yylex(void);
void yyerror(const char *s);
struct ast_node *parser_result = NULL;


#line 83 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_CHARACTER_LITERAL = 4,          /* CHARACTER_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 5,             /* STRING_LITERAL  */
  YYSYMBOL_NUMBER = 6,                     /* NUMBER  */
  YYSYMBOL_FLOAT_LITERAL = 7,              /* FLOAT_LITERAL  */
  YYSYMBOL_INTEGER = 8,                    /* INTEGER  */
  YYSYMBOL_FLOAT = 9,                      /* FLOAT  */
  YYSYMBOL_BOOLEAN = 10,                   /* BOOLEAN  */
  YYSYMBOL_CHAR = 11,                      /* CHAR  */
  YYSYMBOL_STRING = 12,                    /* STRING  */
  YYSYMBOL_ARRAY = 13,                     /* ARRAY  */
  YYSYMBOL_VOID = 14,                      /* VOID  */
  YYSYMBOL_IF = 15,                        /* IF  */
  YYSYMBOL_ELSE = 16,                      /* ELSE  */
  YYSYMBOL_WHILE = 17,                     /* WHILE  */
  YYSYMBOL_RETURN = 18,                    /* RETURN  */
  YYSYMBOL_PRINT = 19,                     /* PRINT  */
  YYSYMBOL_FUNCTION = 20,                  /* FUNCTION  */
  YYSYMBOL_TRUE = 21,                      /* TRUE  */
  YYSYMBOL_FALSE = 22,                     /* FALSE  */
  YYSYMBOL_PLUS = 23,                      /* PLUS  */
  YYSYMBOL_MINUS = 24,                     /* MINUS  */
  YYSYMBOL_MUL = 25,                       /* MUL  */
  YYSYMBOL_DIV = 26,                       /* DIV  */
  YYSYMBOL_MOD = 27,                       /* MOD  */
  YYSYMBOL_EXPO = 28,                      /* EXPO  */
  YYSYMBOL_ASSIGN = 29,                    /* ASSIGN  */
  YYSYMBOL_EQ = 30,                        /* EQ  */
  YYSYMBOL_NEQ = 31,                       /* NEQ  */
  YYSYMBOL_LT = 32,                        /* LT  */
  YYSYMBOL_LE = 33,                        /* LE  */
  YYSYMBOL_GT = 34,                        /* GT  */
  YYSYMBOL_GE = 35,                        /* GE  */
  YYSYMBOL_AND = 36,                       /* AND  */
  YYSYMBOL_OR = 37,                        /* OR  */
  YYSYMBOL_NOT = 38,                       /* NOT  */
  YYSYMBOL_COLON = 39,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 40,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 41,                     /* COMMA  */
  YYSYMBOL_LPAREN = 42,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 43,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 44,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 45,                    /* RBRACE  */
  YYSYMBOL_LBRACK = 46,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 47,                    /* RBRACK  */
  YYSYMBOL_LOWER_THAN_ELSE = 48,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_program = 50,                   /* program  */
  YYSYMBOL_decl_list = 51,                 /* decl_list  */
  YYSYMBOL_decl = 52,                      /* decl  */
  YYSYMBOL_var_decl = 53,                  /* var_decl  */
  YYSYMBOL_type = 54,                      /* type  */
  YYSYMBOL_func_decl = 55,                 /* func_decl  */
  YYSYMBOL_param_list = 56,                /* param_list  */
  YYSYMBOL_param_list_nonempty = 57,       /* param_list_nonempty  */
  YYSYMBOL_param = 58,                     /* param  */
  YYSYMBOL_block = 59,                     /* block  */
  YYSYMBOL_stmt_list = 60,                 /* stmt_list  */
  YYSYMBOL_stmt = 61,                      /* stmt  */
  YYSYMBOL_expr_stmt = 62,                 /* expr_stmt  */
  YYSYMBOL_if_stmt = 63,                   /* if_stmt  */
  YYSYMBOL_while_stmt = 64,                /* while_stmt  */
  YYSYMBOL_return_stmt = 65,               /* return_stmt  */
  YYSYMBOL_print_stmt = 66,                /* print_stmt  */
  YYSYMBOL_expr_list = 67,                 /* expr_list  */
  YYSYMBOL_expr = 68,                      /* expr  */
  YYSYMBOL_arg_list = 69,                  /* arg_list  */
  YYSYMBOL_arg_list_nonempty = 70          /* arg_list_nonempty  */
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   349

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  129

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   303


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    50,    50,    54,    63,    67,    68,    73,    77,    84,
      85,    86,    87,    88,    89,    90,    95,   100,   107,   108,
     112,   113,   122,   129,   133,   142,   146,   147,   148,   149,
     150,   151,   152,   156,   160,   163,   171,   177,   178,   182,
     186,   187,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   214,
     216,   220,   224,   226,   228,   230,   232,   234,   239,   240,
     244,   245
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "CHARACTER_LITERAL", "STRING_LITERAL", "NUMBER", "FLOAT_LITERAL",
  "INTEGER", "FLOAT", "BOOLEAN", "CHAR", "STRING", "ARRAY", "VOID", "IF",
  "ELSE", "WHILE", "RETURN", "PRINT", "FUNCTION", "TRUE", "FALSE", "PLUS",
  "MINUS", "MUL", "DIV", "MOD", "EXPO", "ASSIGN", "EQ", "NEQ", "LT", "LE",
  "GT", "GE", "AND", "OR", "NOT", "COLON", "SEMICOLON", "COMMA", "LPAREN",
  "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "LOWER_THAN_ELSE",
  "$accept", "program", "decl_list", "decl", "var_decl", "type",
  "func_decl", "param_list", "param_list_nonempty", "param", "block",
  "stmt_list", "stmt", "expr_stmt", "if_stmt", "while_stmt", "return_stmt",
  "print_stmt", "expr_list", "expr", "arg_list", "arg_list_nonempty", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-78)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -78,     3,     7,   -78,   -22,   -78,   -78,   -78,   126,   -78,
     -78,   -78,   -78,   -78,   -31,   -78,   335,   -27,    17,     9,
     110,   -78,     2,    50,   -28,   -78,   -78,   -78,   -78,   -78,
     -78,   110,   110,   211,   335,    22,    19,    24,   -78,   110,
     110,   110,   -78,   148,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   -78,   -78,
     335,   -24,    50,   265,   265,    20,    25,   130,   -78,   -19,
     -19,    39,    39,    39,    39,   307,   307,    46,    46,    46,
      46,   294,   280,   -78,    32,   -78,   -78,   -78,   110,   -78,
     -78,   -78,   265,    37,    18,    38,    41,   105,   110,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   229,   335,
     110,   110,   -78,   247,    -2,   265,   -78,   169,   190,   -78,
     -78,   110,    81,    81,   265,    73,   -78,    81,   -78
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,     0,     3,     5,     6,     0,     9,
      10,    11,    12,    13,     0,    14,     0,     0,     0,     0,
       0,     7,     0,    18,    58,    63,    64,    62,    65,    66,
      67,     0,     0,     0,     0,     0,     0,    19,    20,     0,
      68,     0,    56,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,    15,
       0,     0,     0,    59,    70,     0,    69,     0,    57,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    22,     0,    17,    21,    61,     0,    60,
      25,    16,    71,     0,    58,     0,     0,     0,     0,    23,
      26,    32,    24,    27,    28,    29,    30,    31,     0,     0,
       0,     0,    38,     0,     0,    40,    33,     0,     0,    37,
      39,     0,     0,     0,    41,    34,    36,     0,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -78,   -78,   -78,   -78,    90,   -12,   -78,   -78,   -78,    31,
      10,   -78,   -77,   -78,   -78,   -78,   -78,   -78,   -78,   -20,
     -78,   -78
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     5,   100,    17,     7,    36,    37,    38,
     101,    93,   102,   103,   104,   105,   106,   107,   114,   108,
      65,    66
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      33,    39,    20,     3,    19,    84,    46,    47,    48,    49,
       4,    42,    43,    21,    40,    18,    85,     8,    41,    63,
      64,    67,    59,    22,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,   120,   121,
      94,    25,    26,    27,    28,   125,   126,    39,    83,    34,
     128,    23,    95,    35,    96,    97,    98,   109,    29,    30,
      40,    60,    61,    87,    41,    62,    88,    49,    92,    44,
      45,    46,    47,    48,    49,    31,    90,   113,   115,    32,
     110,    90,    99,   111,    94,    25,    26,    27,    28,   127,
     117,   118,     6,    86,    91,     0,    95,     0,    96,    97,
      98,   124,    29,    30,     0,     0,     0,     0,    24,    25,
      26,    27,    28,    24,    25,    26,    27,    28,     0,    31,
       0,     0,     0,    32,     0,    90,    29,    30,     0,     0,
       0,    29,    30,     0,     9,    10,    11,    12,    13,    14,
      15,     0,     0,    31,     0,   112,    16,    32,    31,     0,
       0,     0,    32,    44,    45,    46,    47,    48,    49,     0,
      50,    51,    52,    53,    54,    55,    56,    57,     0,     0,
       0,    44,    45,    46,    47,    48,    49,    89,    50,    51,
      52,    53,    54,    55,    56,    57,     0,     0,     0,     0,
       0,    68,    44,    45,    46,    47,    48,    49,     0,    50,
      51,    52,    53,    54,    55,    56,    57,     0,     0,     0,
       0,     0,   122,    44,    45,    46,    47,    48,    49,     0,
      50,    51,    52,    53,    54,    55,    56,    57,     0,     0,
       0,     0,     0,   123,    44,    45,    46,    47,    48,    49,
       0,    50,    51,    52,    53,    54,    55,    56,    57,     0,
       0,    58,    44,    45,    46,    47,    48,    49,     0,    50,
      51,    52,    53,    54,    55,    56,    57,     0,     0,   116,
      44,    45,    46,    47,    48,    49,     0,    50,    51,    52,
      53,    54,    55,    56,    57,     0,     0,   119,    44,    45,
      46,    47,    48,    49,     0,    50,    51,    52,    53,    54,
      55,    56,    57,    44,    45,    46,    47,    48,    49,     0,
      50,    51,    52,    53,    54,    55,    56,    44,    45,    46,
      47,    48,    49,     0,    50,    51,    52,    53,    54,    55,
      44,    45,    46,    47,    48,    49,     0,     0,     0,    52,
      53,    54,    55,     9,    10,    11,    12,    13,    14,    15
};

static const yytype_int8 yycheck[] =
{
      20,    29,    29,     0,    16,    29,    25,    26,    27,    28,
       3,    31,    32,    40,    42,    46,    40,    39,    46,    39,
      40,    41,    34,     6,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    40,    41,
       3,     4,     5,     6,     7,   122,   123,    29,    60,    47,
     127,    42,    15,     3,    17,    18,    19,    39,    21,    22,
      42,    39,    43,    43,    46,    41,    41,    28,    88,    23,
      24,    25,    26,    27,    28,    38,    44,    97,    98,    42,
      42,    44,    45,    42,     3,     4,     5,     6,     7,    16,
     110,   111,     2,    62,    84,    -1,    15,    -1,    17,    18,
      19,   121,    21,    22,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     3,     4,     5,     6,     7,    -1,    38,
      -1,    -1,    -1,    42,    -1,    44,    21,    22,    -1,    -1,
      -1,    21,    22,    -1,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    38,    -1,    40,    20,    42,    38,    -1,
      -1,    -1,    42,    23,    24,    25,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    47,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    43,    23,    24,    25,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    43,    23,    24,    25,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    43,    23,    24,    25,    26,    27,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    40,    23,    24,    25,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    40,
      23,    24,    25,    26,    27,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    40,    23,    24,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    23,    24,    25,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    23,    24,    25,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      23,    24,    25,    26,    27,    28,    -1,    -1,    -1,    32,
      33,    34,    35,     8,     9,    10,    11,    12,    13,    14
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    50,    51,     0,     3,    52,    53,    55,    39,     8,
       9,    10,    11,    12,    13,    14,    20,    54,    46,    54,
      29,    40,     6,    42,     3,     4,     5,     6,     7,    21,
      22,    38,    42,    68,    47,     3,    56,    57,    58,    29,
      42,    46,    68,    68,    23,    24,    25,    26,    27,    28,
      30,    31,    32,    33,    34,    35,    36,    37,    40,    54,
      39,    43,    41,    68,    68,    69,    70,    68,    43,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    54,    29,    40,    58,    43,    41,    47,
      44,    59,    68,    60,     3,    15,    17,    18,    19,    45,
      53,    59,    61,    62,    63,    64,    65,    66,    68,    39,
      42,    42,    40,    68,    67,    68,    40,    68,    68,    40,
      40,    41,    43,    43,    68,    61,    61,    16,    61
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    53,    53,    54,
      54,    54,    54,    54,    54,    54,    55,    55,    56,    56,
      57,    57,    58,    59,    60,    60,    61,    61,    61,    61,
      61,    61,    61,    62,    63,    63,    64,    65,    65,    66,
      67,    67,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    69,    69,
      70,    70
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     4,     6,     1,
       1,     1,     1,     1,     1,     5,     9,     8,     0,     1,
       1,     3,     3,     3,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     2,     5,     7,     5,     3,     2,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     1,     3,
       4,     4,     1,     1,     1,     1,     1,     1,     0,     1,
       1,     3
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* program: decl_list  */
#line 50 "parser.y"
              { parser_result = (yyvsp[0].node); }
#line 1539 "parser.tab.c"
    break;

  case 3: /* decl_list: decl_list decl  */
#line 54 "parser.y"
                   {
        if ((yyvsp[-1].node) == NULL) { (yyval.node) = (yyvsp[0].node); }
        else {
            struct ast_node *temp = (yyvsp[-1].node);
            while (temp->next) temp = temp->next;
            temp->next = (yyvsp[0].node);
            (yyval.node) = (yyvsp[-1].node);
        }
    }
#line 1553 "parser.tab.c"
    break;

  case 4: /* decl_list: %empty  */
#line 63 "parser.y"
                  { (yyval.node) = NULL; }
#line 1559 "parser.tab.c"
    break;

  case 7: /* var_decl: IDENTIFIER COLON type SEMICOLON  */
#line 73 "parser.y"
                                    {
        (yyval.node) = make_node(AST_VARIABLE_DECL, (yyvsp[-1].node), NULL);
        (yyval.node)->name = (yyvsp[-3].id);
        }
#line 1568 "parser.tab.c"
    break;

  case 8: /* var_decl: IDENTIFIER COLON type ASSIGN expr SEMICOLON  */
#line 77 "parser.y"
                                                  {
        (yyval.node) = make_node(AST_VARIABLE_DECL, (yyvsp[-3].node), (yyvsp[-1].node));
        (yyval.node)->name = (yyvsp[-5].id);
    }
#line 1577 "parser.tab.c"
    break;

  case 9: /* type: INTEGER  */
#line 84 "parser.y"
            { (yyval.node) = make_node(AST_TYPE, NULL, NULL); (yyval.node)->int_value = INTEGER; }
#line 1583 "parser.tab.c"
    break;

  case 10: /* type: FLOAT  */
#line 85 "parser.y"
            { (yyval.node) = make_node(AST_TYPE, NULL, NULL); (yyval.node)->int_value = FLOAT; }
#line 1589 "parser.tab.c"
    break;

  case 11: /* type: BOOLEAN  */
#line 86 "parser.y"
              { (yyval.node) = make_node(AST_TYPE, NULL, NULL); (yyval.node)->int_value = BOOLEAN; }
#line 1595 "parser.tab.c"
    break;

  case 12: /* type: CHAR  */
#line 87 "parser.y"
           { (yyval.node) = make_node(AST_TYPE, NULL, NULL); (yyval.node)->int_value = CHAR; }
#line 1601 "parser.tab.c"
    break;

  case 13: /* type: STRING  */
#line 88 "parser.y"
             { (yyval.node) = make_node(AST_TYPE, NULL, NULL); (yyval.node)->int_value = STRING; }
#line 1607 "parser.tab.c"
    break;

  case 14: /* type: VOID  */
#line 89 "parser.y"
           { (yyval.node) = make_node(AST_TYPE, NULL, NULL); (yyval.node)->int_value = VOID; }
#line 1613 "parser.tab.c"
    break;

  case 15: /* type: ARRAY LBRACK NUMBER RBRACK type  */
#line 90 "parser.y"
                                      { (yyval.node) = make_node(AST_TYPE, NULL, NULL); (yyval.node)->int_value = INTEGER; }
#line 1619 "parser.tab.c"
    break;

  case 16: /* func_decl: IDENTIFIER COLON FUNCTION type LPAREN param_list RPAREN ASSIGN block  */
#line 95 "parser.y"
                                                                         {
        (yyval.node) = make_node(AST_FUNCTION_DECL, (yyvsp[-5].node), (yyvsp[-3].node)); // left = return type, right = params
        (yyval.node)->middle = (yyvsp[0].node);                           // middle = function body
        (yyval.node)->name = (yyvsp[-8].id);                             // name = name... yeah, shocking I know
                    }
#line 1629 "parser.tab.c"
    break;

  case 17: /* func_decl: IDENTIFIER COLON FUNCTION type LPAREN param_list RPAREN SEMICOLON  */
#line 100 "parser.y"
                                                                        {
        (yyval.node) = make_node(AST_FUNCTION_DECL, (yyvsp[-4].node), (yyvsp[-2].node)); // prototype (no body [sad] )
        (yyval.node)->name = (yyvsp[-7].id);
    }
#line 1638 "parser.tab.c"
    break;

  case 18: /* param_list: %empty  */
#line 107 "parser.y"
                { (yyval.node) = NULL; }
#line 1644 "parser.tab.c"
    break;

  case 20: /* param_list_nonempty: param  */
#line 112 "parser.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 1650 "parser.tab.c"
    break;

  case 21: /* param_list_nonempty: param_list_nonempty COMMA param  */
#line 113 "parser.y"
                                      {
        struct ast_node *temp = (yyvsp[-2].node);
        while(temp->next) temp = temp->next;
        temp->next = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
    }
#line 1661 "parser.tab.c"
    break;

  case 22: /* param: IDENTIFIER COLON type  */
#line 122 "parser.y"
                          {
        (yyval.node) = make_node(AST_PARAM, (yyvsp[0].node), NULL); // param(my money)
        (yyval.node)->name = (yyvsp[-2].id);
              }
#line 1670 "parser.tab.c"
    break;

  case 23: /* block: LBRACE stmt_list RBRACE  */
#line 129 "parser.y"
                            { (yyval.node) = make_node(AST_BLOCK, (yyvsp[-1].node), NULL); }
#line 1676 "parser.tab.c"
    break;

  case 24: /* stmt_list: stmt_list stmt  */
#line 133 "parser.y"
                   {
          if ((yyvsp[-1].node) == NULL) { (yyval.node) = (yyvsp[0].node); }
          else {
              struct ast_node *temp = (yyvsp[-1].node);
              while (temp->next) temp = temp->next;
              temp->next = (yyvsp[0].node);
              (yyval.node) = (yyvsp[-1].node);
          }
      }
#line 1690 "parser.tab.c"
    break;

  case 25: /* stmt_list: %empty  */
#line 142 "parser.y"
                  { (yyval.node) = NULL; }
#line 1696 "parser.tab.c"
    break;

  case 33: /* expr_stmt: expr SEMICOLON  */
#line 156 "parser.y"
                   { (yyval.node) = make_node(AST_EXPR_STMT, (yyvsp[-1].node), NULL); }
#line 1702 "parser.tab.c"
    break;

  case 34: /* if_stmt: IF LPAREN expr RPAREN stmt  */
#line 160 "parser.y"
                                                      {
        (yyval.node) = make_node(AST_IF_STMT, (yyvsp[-2].node), (yyvsp[0].node)); 
                }
#line 1710 "parser.tab.c"
    break;

  case 35: /* if_stmt: IF LPAREN expr RPAREN stmt ELSE stmt  */
#line 163 "parser.y"
                                           {
        (yyval.node) = make_node(AST_IF_STMT, (yyvsp[-4].node), NULL);
        (yyval.node)->middle = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node); 
                }
#line 1720 "parser.tab.c"
    break;

  case 36: /* while_stmt: WHILE LPAREN expr RPAREN stmt  */
#line 171 "parser.y"
                                  {
        (yyval.node) = make_node(AST_WHILE_STMT, (yyvsp[-2].node), (yyvsp[0].node));
                }
#line 1728 "parser.tab.c"
    break;

  case 37: /* return_stmt: RETURN expr SEMICOLON  */
#line 177 "parser.y"
                          { (yyval.node) = make_node(AST_RETURN_STMT, (yyvsp[-1].node), NULL); }
#line 1734 "parser.tab.c"
    break;

  case 38: /* return_stmt: RETURN SEMICOLON  */
#line 178 "parser.y"
                       { (yyval.node) = make_node(AST_RETURN_STMT, NULL, NULL); }
#line 1740 "parser.tab.c"
    break;

  case 39: /* print_stmt: PRINT expr_list SEMICOLON  */
#line 182 "parser.y"
                              { (yyval.node) = make_node(AST_PRINT_STMT, (yyvsp[-1].node), NULL); }
#line 1746 "parser.tab.c"
    break;

  case 40: /* expr_list: expr  */
#line 186 "parser.y"
         { (yyval.node) = (yyvsp[0].node); }
#line 1752 "parser.tab.c"
    break;

  case 41: /* expr_list: expr_list COMMA expr  */
#line 187 "parser.y"
                           {
        struct ast_node *temp = (yyvsp[-2].node);
        while(temp->next) temp = temp->next;
        temp->next = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
    }
#line 1763 "parser.tab.c"
    break;

  case 42: /* expr: expr PLUS expr  */
#line 196 "parser.y"
                   { (yyval.node) = make_node(AST_BINARY_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->op = PLUS; }
#line 1769 "parser.tab.c"
    break;

  case 43: /* expr: expr MINUS expr  */
#line 197 "parser.y"
                      { (yyval.node) = make_node(AST_BINARY_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->op = MINUS; }
#line 1775 "parser.tab.c"
    break;

  case 44: /* expr: expr MUL expr  */
#line 198 "parser.y"
                    { (yyval.node) = make_node(AST_BINARY_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->op = MUL; }
#line 1781 "parser.tab.c"
    break;

  case 45: /* expr: expr DIV expr  */
#line 199 "parser.y"
                    { (yyval.node) = make_node(AST_BINARY_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->op = DIV; }
#line 1787 "parser.tab.c"
    break;

  case 46: /* expr: expr MOD expr  */
#line 200 "parser.y"
                    { (yyval.node) = make_node(AST_BINARY_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->op = MOD; }
#line 1793 "parser.tab.c"
    break;

  case 47: /* expr: expr EXPO expr  */
#line 201 "parser.y"
                     { (yyval.node) = make_node(AST_BINARY_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->op = EXPO; }
#line 1799 "parser.tab.c"
    break;

  case 48: /* expr: expr EQ expr  */
#line 202 "parser.y"
                   { (yyval.node) = make_node(AST_BINARY_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->op = EQ; }
#line 1805 "parser.tab.c"
    break;

  case 49: /* expr: expr NEQ expr  */
#line 203 "parser.y"
                    { (yyval.node) = make_node(AST_BINARY_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->op = NEQ; }
#line 1811 "parser.tab.c"
    break;

  case 50: /* expr: expr LT expr  */
#line 204 "parser.y"
                   { (yyval.node) = make_node(AST_BINARY_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->op = LT; }
#line 1817 "parser.tab.c"
    break;

  case 51: /* expr: expr LE expr  */
#line 205 "parser.y"
                   { (yyval.node) = make_node(AST_BINARY_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->op = LE; }
#line 1823 "parser.tab.c"
    break;

  case 52: /* expr: expr GT expr  */
#line 206 "parser.y"
                   { (yyval.node) = make_node(AST_BINARY_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->op = GT; }
#line 1829 "parser.tab.c"
    break;

  case 53: /* expr: expr GE expr  */
#line 207 "parser.y"
                   { (yyval.node) = make_node(AST_BINARY_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->op = GE; }
#line 1835 "parser.tab.c"
    break;

  case 54: /* expr: expr AND expr  */
#line 208 "parser.y"
                    { (yyval.node) = make_node(AST_BINARY_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->op = AND; }
#line 1841 "parser.tab.c"
    break;

  case 55: /* expr: expr OR expr  */
#line 209 "parser.y"
                   { (yyval.node) = make_node(AST_BINARY_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->op = OR; }
#line 1847 "parser.tab.c"
    break;

  case 56: /* expr: NOT expr  */
#line 210 "parser.y"
               { (yyval.node) = make_node(AST_UNARY_EXPR, (yyvsp[0].node), NULL); (yyval.node)->op = NOT; }
#line 1853 "parser.tab.c"
    break;

  case 57: /* expr: LPAREN expr RPAREN  */
#line 211 "parser.y"
                         {(yyval.node) = (yyvsp[-1].node); }
#line 1859 "parser.tab.c"
    break;

  case 58: /* expr: IDENTIFIER  */
#line 212 "parser.y"
                 { (yyval.node) = make_node(AST_IDENTIFIER, NULL, NULL);
                   (yyval.node)-> name = (yyvsp[0].id); }
#line 1866 "parser.tab.c"
    break;

  case 59: /* expr: IDENTIFIER ASSIGN expr  */
#line 214 "parser.y"
                             { (yyval.node) = make_node(AST_ASSIGN_EXPR, NULL, (yyvsp[0].node));
                   (yyval.node)-> name = (yyvsp[-2].id); }
#line 1873 "parser.tab.c"
    break;

  case 60: /* expr: IDENTIFIER LBRACK expr RBRACK  */
#line 216 "parser.y"
                                    {
        (yyval.node) = make_node(AST_ARRAY_LITERAL, NULL, (yyvsp[-1].node)); //treat array access like a binary op: [Identifier, Index], brilliant
        (yyval.node)->name = (yyvsp[-3].id);
       }
#line 1882 "parser.tab.c"
    break;

  case 61: /* expr: IDENTIFIER LPAREN arg_list RPAREN  */
#line 220 "parser.y"
                                        {
        (yyval.node) = make_node(AST_CALL_EXPR, (yyvsp[-1].node), NULL);
        (yyval.node)->name = (yyvsp[-3].id);
         }
#line 1891 "parser.tab.c"
    break;

  case 62: /* expr: NUMBER  */
#line 224 "parser.y"
             { (yyval.node) = make_node(AST_INTEGER_LITERAL, NULL, NULL);
                   (yyval.node)-> int_value = (yyvsp[0].num); }
#line 1898 "parser.tab.c"
    break;

  case 63: /* expr: CHARACTER_LITERAL  */
#line 226 "parser.y"
                        { (yyval.node) = make_node(AST_CHAR_LITERAL, NULL, NULL);
                   (yyval.node)-> name = (yyvsp[0].id); }
#line 1905 "parser.tab.c"
    break;

  case 64: /* expr: STRING_LITERAL  */
#line 228 "parser.y"
                     { (yyval.node) = make_node(AST_STRING_LITERAL, NULL, NULL);
                   (yyval.node)-> string_value = (yyvsp[0].id); }
#line 1912 "parser.tab.c"
    break;

  case 65: /* expr: FLOAT_LITERAL  */
#line 230 "parser.y"
                    { (yyval.node) = make_node(AST_FLOAT_LITERAL, NULL, NULL);
                   (yyval.node)-> float_value = (yyvsp[0].fnum); }
#line 1919 "parser.tab.c"
    break;

  case 66: /* expr: TRUE  */
#line 232 "parser.y"
           { (yyval.node) = make_node(AST_BOOLEAN_LITERAL, NULL, NULL);
                   (yyval.node)-> int_value = 1; }
#line 1926 "parser.tab.c"
    break;

  case 67: /* expr: FALSE  */
#line 234 "parser.y"
            { (yyval.node) = make_node(AST_BOOLEAN_LITERAL, NULL, NULL);
                   (yyval.node)-> int_value = 0; }
#line 1933 "parser.tab.c"
    break;

  case 68: /* arg_list: %empty  */
#line 239 "parser.y"
                { (yyval.node) = NULL; }
#line 1939 "parser.tab.c"
    break;

  case 69: /* arg_list: arg_list_nonempty  */
#line 240 "parser.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 1945 "parser.tab.c"
    break;

  case 70: /* arg_list_nonempty: expr  */
#line 244 "parser.y"
         { (yyval.node) = (yyvsp[0].node); }
#line 1951 "parser.tab.c"
    break;

  case 71: /* arg_list_nonempty: arg_list_nonempty COMMA expr  */
#line 245 "parser.y"
                                   {
        struct ast_node *temp = (yyvsp[-2].node);
        while(temp->next) temp = temp->next;
        temp->next = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
    }
#line 1962 "parser.tab.c"
    break;


#line 1966 "parser.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 253 "parser.y"


void yyerror(const char *s) {
    extern int yylineno; 
    fprintf(stderr, "Parse error in line %d: %s\n", yylineno, s);
}

int main(void) {
    if(yyparse() == 0) {
        printf("Parse successful! Tree Structure:\n");
        print_ast(parser_result, 0);
    }
    return 0;
}
