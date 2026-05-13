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
#include "symboltable.h" // didn't forget it this time tho
#include "codegen.h"
#include "assembler.h"
#include "registers.h"

extern struct IR_Instr *ir_head;
extern FILE *yyin;
int yylex(void);
void yyerror(const char *s);
struct ast_node *program_root = NULL;
int errors = 0;
static char current_func_name[256] = "";


#line 91 "parser.tab.c"

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
  YYSYMBOL_56_1 = 56,                      /* $@1  */
  YYSYMBOL_57_2 = 57,                      /* $@2  */
  YYSYMBOL_func_suffix = 58,               /* func_suffix  */
  YYSYMBOL_param_list = 59,                /* param_list  */
  YYSYMBOL_param_list_nonempty = 60,       /* param_list_nonempty  */
  YYSYMBOL_param = 61,                     /* param  */
  YYSYMBOL_block = 62,                     /* block  */
  YYSYMBOL_63_3 = 63,                      /* $@3  */
  YYSYMBOL_func_body = 64,                 /* func_body  */
  YYSYMBOL_stmt_list = 65,                 /* stmt_list  */
  YYSYMBOL_stmt = 66,                      /* stmt  */
  YYSYMBOL_expr_stmt = 67,                 /* expr_stmt  */
  YYSYMBOL_if_stmt = 68,                   /* if_stmt  */
  YYSYMBOL_while_stmt = 69,                /* while_stmt  */
  YYSYMBOL_return_stmt = 70,               /* return_stmt  */
  YYSYMBOL_print_stmt = 71,                /* print_stmt  */
  YYSYMBOL_expr_list = 72,                 /* expr_list  */
  YYSYMBOL_expr = 73,                      /* expr  */
  YYSYMBOL_arg_list = 74,                  /* arg_list  */
  YYSYMBOL_array_init = 75,                /* array_init  */
  YYSYMBOL_arg_list_nonempty = 76          /* arg_list_nonempty  */
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
#define YYLAST   384

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

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
static const yytype_int16 yyrline[] =
{
       0,    58,    58,    62,    71,    75,    76,    81,    91,   101,
     114,   115,   116,   117,   118,   119,   120,   125,   131,   125,
     141,   145,   152,   153,   157,   158,   167,   179,   179,   185,
     189,   198,   202,   203,   204,   205,   206,   207,   208,   212,
     216,   219,   227,   233,   234,   238,   242,   243,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   275,   281,   288,   293,   298,
     300,   302,   304,   306,   308,   313,   314,   318,   322,   323
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
  "func_decl", "$@1", "$@2", "func_suffix", "param_list",
  "param_list_nonempty", "param", "block", "$@3", "func_body", "stmt_list",
  "stmt", "expr_stmt", "if_stmt", "while_stmt", "return_stmt",
  "print_stmt", "expr_list", "expr", "arg_list", "array_init",
  "arg_list_nonempty", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-71)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -71,     4,    20,   -71,   -17,   -71,   -71,   -71,   168,   -71,
     -71,   -71,   -71,   -71,   -22,   -71,    98,    10,    39,   -71,
     110,   -71,    -1,    11,    19,   -71,   -71,   -71,   -71,   -71,
     -71,   165,   165,   165,   266,    23,    98,   -71,   165,   165,
     165,   -71,   203,    27,   320,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   -71,
     -71,   -71,    66,   320,   320,    30,    33,   185,   -71,   165,
     -71,   108,   108,    48,    48,    48,    48,   -18,   -18,   172,
     172,   172,   172,   349,   335,    41,    45,    51,   -71,   -71,
     165,    60,   320,    98,    22,    66,   320,   165,   -71,    49,
     -71,   -71,   -71,   320,   -71,   -71,    37,    18,    52,    54,
     152,   165,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   284,    98,   165,   165,   -71,   302,   -38,   -71,
     -71,   224,   245,   -71,   -71,    80,   123,   123,   -71,    84,
     -71,   123,   -71
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,     0,     3,     5,     6,     0,    10,
      11,    12,    13,    14,     0,    15,     0,     0,     0,    17,
       0,     7,     0,     0,    64,    70,    71,    69,    72,    73,
      74,     0,     0,     0,     0,     0,     0,    18,     0,    75,
       0,    62,     0,     0,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       9,    16,    22,    65,    78,     0,    76,     0,    63,     0,
      77,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,     0,     0,    23,    24,    68,
       0,    67,    47,     0,     0,     0,    79,     0,    26,     0,
      21,    19,    25,    66,    31,    20,     0,    64,     0,     0,
       0,     0,    27,    29,    32,    38,    30,    33,    34,    35,
      36,    37,     0,     0,     0,     0,    44,     0,     0,    31,
      39,     0,     0,    43,    45,     0,     0,     0,    28,    40,
      42,     0,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -71,   -71,   -71,   -71,   101,   -15,   -71,   -71,   -71,   -71,
     -71,   -71,    24,   -71,   -71,   -71,    -9,   -70,   -71,   -71,
     -71,   -71,   -71,    12,   -20,   -71,   -71,   -71
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     5,   114,    17,     7,    23,    62,   101,
      86,    87,    88,   115,   129,   105,   106,   116,   117,   118,
     119,   120,   121,    43,   122,    65,    35,    66
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      34,    19,   134,    69,     3,    45,    46,    47,    48,    49,
      50,    41,    42,    44,    53,    54,    55,    56,    63,    64,
      67,    61,     8,     4,    18,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    20,
     107,    25,    26,    27,    28,    22,    36,    38,    38,    92,
      21,    99,   108,    37,   109,   110,   111,   123,    29,    30,
      39,    39,   100,    60,    40,    40,   139,   140,    69,    85,
      96,   142,    70,    89,    90,    31,    50,   103,    98,    32,
      93,   112,   113,   107,    25,    26,    27,    28,    94,    97,
     127,    44,    95,   104,   124,   108,   125,   109,   110,   111,
     141,    29,    30,     6,   131,   132,     9,    10,    11,    12,
      13,    14,    15,    24,    25,    26,    27,    28,    31,   102,
     135,     0,    32,   128,   112,   138,   107,    25,    26,    27,
      28,    29,    30,    47,    48,    49,    50,     0,   108,     0,
     109,   110,   111,     0,    29,    30,     0,     0,    31,     0,
       0,     0,    32,     0,    33,    24,    25,    26,    27,    28,
       0,    31,     0,     0,     0,    32,     0,   112,    24,    25,
      26,    27,    28,    29,    30,     0,     9,    10,    11,    12,
      13,    14,    15,     0,     0,     0,    29,    30,    16,     0,
      31,     0,   126,     0,    32,    45,    46,    47,    48,    49,
      50,     0,     0,    31,     0,     0,     0,    32,    45,    46,
      47,    48,    49,    50,     0,    51,    52,    53,    54,    55,
      56,    57,    58,     0,     0,     0,    45,    46,    47,    48,
      49,    50,    91,    51,    52,    53,    54,    55,    56,    57,
      58,     0,     0,     0,     0,     0,    68,    45,    46,    47,
      48,    49,    50,     0,    51,    52,    53,    54,    55,    56,
      57,    58,     0,     0,     0,     0,     0,   136,    45,    46,
      47,    48,    49,    50,     0,    51,    52,    53,    54,    55,
      56,    57,    58,     0,     0,     0,     0,     0,   137,    45,
      46,    47,    48,    49,    50,     0,    51,    52,    53,    54,
      55,    56,    57,    58,     0,     0,    59,    45,    46,    47,
      48,    49,    50,     0,    51,    52,    53,    54,    55,    56,
      57,    58,     0,     0,   130,    45,    46,    47,    48,    49,
      50,     0,    51,    52,    53,    54,    55,    56,    57,    58,
       0,     0,   133,    45,    46,    47,    48,    49,    50,     0,
      51,    52,    53,    54,    55,    56,    57,    58,    45,    46,
      47,    48,    49,    50,     0,    51,    52,    53,    54,    55,
      56,    57,    45,    46,    47,    48,    49,    50,     0,    51,
      52,    53,    54,    55,    56
};

static const yytype_int16 yycheck[] =
{
      20,    16,    40,    41,     0,    23,    24,    25,    26,    27,
      28,    31,    32,    33,    32,    33,    34,    35,    38,    39,
      40,    36,    39,     3,    46,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    29,
       3,     4,     5,     6,     7,     6,    47,    29,    29,    69,
      40,    29,    15,    42,    17,    18,    19,    39,    21,    22,
      42,    42,    40,    40,    46,    46,   136,   137,    41,     3,
      90,   141,    45,    43,    41,    38,    28,    97,    93,    42,
      39,    44,    45,     3,     4,     5,     6,     7,    43,    29,
     110,   111,    41,    44,    42,    15,    42,    17,    18,    19,
      16,    21,    22,     2,   124,   125,     8,     9,    10,    11,
      12,    13,    14,     3,     4,     5,     6,     7,    38,    95,
     129,    -1,    42,   111,    44,    45,     3,     4,     5,     6,
       7,    21,    22,    25,    26,    27,    28,    -1,    15,    -1,
      17,    18,    19,    -1,    21,    22,    -1,    -1,    38,    -1,
      -1,    -1,    42,    -1,    44,     3,     4,     5,     6,     7,
      -1,    38,    -1,    -1,    -1,    42,    -1,    44,     3,     4,
       5,     6,     7,    21,    22,    -1,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    -1,    21,    22,    20,    -1,
      38,    -1,    40,    -1,    42,    23,    24,    25,    26,    27,
      28,    -1,    -1,    38,    -1,    -1,    -1,    42,    23,    24,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    23,    24,    25,    26,
      27,    28,    47,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    43,    23,    24,    25,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    43,    23,    24,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    43,    23,
      24,    25,    26,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    40,    23,    24,    25,
      26,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    40,    23,    24,    25,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    40,    23,    24,    25,    26,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    23,    24,
      25,    26,    27,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    23,    24,    25,    26,    27,    28,    -1,    30,
      31,    32,    33,    34,    35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    50,    51,     0,     3,    52,    53,    55,    39,     8,
       9,    10,    11,    12,    13,    14,    20,    54,    46,    54,
      29,    40,     6,    56,     3,     4,     5,     6,     7,    21,
      22,    38,    42,    44,    73,    75,    47,    42,    29,    42,
      46,    73,    73,    72,    73,    23,    24,    25,    26,    27,
      28,    30,    31,    32,    33,    34,    35,    36,    37,    40,
      40,    54,    57,    73,    73,    74,    76,    73,    43,    41,
      45,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,     3,    59,    60,    61,    43,
      41,    47,    73,    39,    43,    41,    73,    29,    54,    29,
      40,    58,    61,    73,    44,    64,    65,     3,    15,    17,
      18,    19,    44,    45,    53,    62,    66,    67,    68,    69,
      70,    71,    73,    39,    42,    42,    40,    73,    72,    63,
      40,    73,    73,    40,    40,    65,    43,    43,    45,    66,
      66,    16,    66
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    53,    53,    53,
      54,    54,    54,    54,    54,    54,    54,    56,    57,    55,
      58,    58,    59,    59,    60,    60,    61,    63,    62,    64,
      65,    65,    66,    66,    66,    66,    66,    66,    66,    67,
      68,    68,    69,    70,    70,    71,    72,    72,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    74,    74,    75,    76,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     4,     6,     6,
       1,     1,     1,     1,     1,     1,     5,     0,     0,    10,
       2,     1,     0,     1,     1,     3,     3,     0,     4,     3,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     2,
       5,     7,     5,     3,     2,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     1,     3,     6,     4,     4,     1,
       1,     1,     1,     1,     1,     0,     1,     3,     1,     3
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
#line 58 "parser.y"
              { program_root = (yyvsp[0].node); }
#line 1569 "parser.tab.c"
    break;

  case 3: /* decl_list: decl_list decl  */
#line 62 "parser.y"
                   {
        if ((yyvsp[-1].node) == NULL) { (yyval.node) = (yyvsp[0].node); }
        else {
            struct ast_node *temp = (yyvsp[-1].node);
            while (temp->next) temp = temp->next;
            temp->next = (yyvsp[0].node);
            (yyval.node) = (yyvsp[-1].node);
        }
    }
#line 1583 "parser.tab.c"
    break;

  case 4: /* decl_list: %empty  */
#line 71 "parser.y"
                  { (yyval.node) = NULL; }
#line 1589 "parser.tab.c"
    break;

  case 7: /* var_decl: IDENTIFIER COLON type SEMICOLON  */
#line 81 "parser.y"
                                    {
        char *parent = current_func_name[0] ? current_func_name : NULL;
        int base_type = ((yyvsp[-1].node)->int_value == ARRAY && (yyvsp[-1].node)->left) ? (yyvsp[-1].node)->left->int_value : 0;
        int array_size = ((yyvsp[-1].node)->int_value == ARRAY) ? (yyvsp[-1].node)->num_value : 0;
        if (!insertSymbol((yyvsp[-3].id), (yyvsp[-1].node)->int_value, 0, parent, base_type, array_size)) {
            yyerror("Redeclaration of variable in same scope");
        }
        (yyval.node) = make_node(AST_VARIABLE_DECL, (yyvsp[-1].node), NULL);
        (yyval.node)->name = (yyvsp[-3].id);
        }
#line 1604 "parser.tab.c"
    break;

  case 8: /* var_decl: IDENTIFIER COLON type ASSIGN expr SEMICOLON  */
#line 91 "parser.y"
                                                  {
        char *parent = current_func_name[0] ? current_func_name : NULL;
        int base_type = ((yyvsp[-3].node)->int_value == ARRAY && (yyvsp[-3].node)->left) ? (yyvsp[-3].node)->left->int_value : 0;
        int array_size = ((yyvsp[-3].node)->int_value == ARRAY) ? (yyvsp[-3].node)->num_value : 0;
        if (!insertSymbol((yyvsp[-5].id), (yyvsp[-3].node)->int_value, 0, parent, base_type, array_size)) {
            yyerror("Redeclaration of variable in same scope");
        }
        (yyval.node) = make_node(AST_VARIABLE_DECL, (yyvsp[-3].node), (yyvsp[-1].node));
        (yyval.node)->name = (yyvsp[-5].id);
    }
#line 1619 "parser.tab.c"
    break;

  case 9: /* var_decl: IDENTIFIER COLON type ASSIGN array_init SEMICOLON  */
#line 101 "parser.y"
                                                        {
        char *parent = current_func_name[0] ? current_func_name : NULL;
        int base_type = ((yyvsp[-3].node)->int_value == ARRAY && (yyvsp[-3].node)->left) ? (yyvsp[-3].node)->left->int_value : 0;
        int array_size = ((yyvsp[-3].node)->int_value == ARRAY) ? (yyvsp[-3].node)->num_value : 0;
        if (!insertSymbol((yyvsp[-5].id), (yyvsp[-3].node)->int_value, 0, parent, base_type, array_size)) {
            yyerror("Redeclaration of variable in same scope");
        }
        (yyval.node) = make_node(AST_VARIABLE_DECL, (yyvsp[-3].node), (yyvsp[-1].node));
        (yyval.node)->name = (yyvsp[-5].id);
    }
#line 1634 "parser.tab.c"
    break;

  case 10: /* type: INTEGER  */
#line 114 "parser.y"
            { (yyval.node) = make_node(AST_TYPE, NULL, NULL); (yyval.node)->int_value = INTEGER; }
#line 1640 "parser.tab.c"
    break;

  case 11: /* type: FLOAT  */
#line 115 "parser.y"
            { (yyval.node) = make_node(AST_TYPE, NULL, NULL); (yyval.node)->int_value = FLOAT; }
#line 1646 "parser.tab.c"
    break;

  case 12: /* type: BOOLEAN  */
#line 116 "parser.y"
              { (yyval.node) = make_node(AST_TYPE, NULL, NULL); (yyval.node)->int_value = BOOLEAN; }
#line 1652 "parser.tab.c"
    break;

  case 13: /* type: CHAR  */
#line 117 "parser.y"
           { (yyval.node) = make_node(AST_TYPE, NULL, NULL); (yyval.node)->int_value = CHAR; }
#line 1658 "parser.tab.c"
    break;

  case 14: /* type: STRING  */
#line 118 "parser.y"
             { (yyval.node) = make_node(AST_TYPE, NULL, NULL); (yyval.node)->int_value = STRING; }
#line 1664 "parser.tab.c"
    break;

  case 15: /* type: VOID  */
#line 119 "parser.y"
           { (yyval.node) = make_node(AST_TYPE, NULL, NULL); (yyval.node)->int_value = VOID; }
#line 1670 "parser.tab.c"
    break;

  case 16: /* type: ARRAY LBRACK NUMBER RBRACK type  */
#line 120 "parser.y"
                                      { (yyval.node) = make_node(AST_TYPE, (yyvsp[0].node), NULL); (yyval.node)->int_value = ARRAY; (yyval.node)->num_value = (yyvsp[-2].num); }
#line 1676 "parser.tab.c"
    break;

  case 17: /* $@1: %empty  */
#line 125 "parser.y"
                                  { 
        if (!insertSymbol((yyvsp[-3].id), (yyvsp[0].node)->int_value, 1, NULL, 0, 0)) {
            yyerror("Function already exists");
        }
        strncpy(current_func_name, (yyvsp[-3].id), sizeof(current_func_name) - 1);
        current_func_name[sizeof(current_func_name) - 1] = '\0';
    }
#line 1688 "parser.tab.c"
    break;

  case 18: /* $@2: %empty  */
#line 131 "parser.y"
             { enterScope(); }
#line 1694 "parser.tab.c"
    break;

  case 19: /* func_decl: IDENTIFIER COLON FUNCTION type $@1 LPAREN $@2 param_list RPAREN func_suffix  */
#line 131 "parser.y"
                                                             {
        (yyval.node) = (yyvsp[0].node); // func_suffix returns the node
        (yyval.node)->left = (yyvsp[-6].node);
        (yyval.node)->right = (yyvsp[-2].node);
        (yyval.node)->name = (yyvsp[-9].id);
        exitScope();
    }
#line 1706 "parser.tab.c"
    break;

  case 20: /* func_suffix: ASSIGN func_body  */
#line 141 "parser.y"
                     {
        (yyval.node) = make_node(AST_FUNCTION_DECL, NULL, NULL);
        (yyval.node)->middle = (yyvsp[0].node);
    }
#line 1715 "parser.tab.c"
    break;

  case 21: /* func_suffix: SEMICOLON  */
#line 145 "parser.y"
                {
        (yyval.node) = make_node(AST_FUNCTION_DECL, NULL, NULL);
        // Prototype, so middle stays NULL
    }
#line 1724 "parser.tab.c"
    break;

  case 22: /* param_list: %empty  */
#line 152 "parser.y"
                { (yyval.node) = NULL; }
#line 1730 "parser.tab.c"
    break;

  case 24: /* param_list_nonempty: param  */
#line 157 "parser.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 1736 "parser.tab.c"
    break;

  case 25: /* param_list_nonempty: param_list_nonempty COMMA param  */
#line 158 "parser.y"
                                      {
        struct ast_node *temp = (yyvsp[-2].node);
        while(temp->next) temp = temp->next;
        temp->next = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
    }
#line 1747 "parser.tab.c"
    break;

  case 26: /* param: IDENTIFIER COLON type  */
#line 167 "parser.y"
                          {
        int base_type = ((yyvsp[0].node)->int_value == ARRAY && (yyvsp[0].node)->left) ? (yyvsp[0].node)->left->int_value : 0;
        int array_size = ((yyvsp[0].node)->int_value == ARRAY) ? (yyvsp[0].node)->num_value : 0;
        if (!insertSymbol((yyvsp[-2].id), (yyvsp[0].node)->int_value, 0, current_func_name, base_type, array_size)) {
            yyerror("Parameter name already used in this scope");
        }
        (yyval.node) = make_node(AST_PARAM, (yyvsp[0].node), NULL); // param(my money)
        (yyval.node)->name = (yyvsp[-2].id);
              }
#line 1761 "parser.tab.c"
    break;

  case 27: /* $@3: %empty  */
#line 179 "parser.y"
           { enterScope(); }
#line 1767 "parser.tab.c"
    break;

  case 28: /* block: LBRACE $@3 stmt_list RBRACE  */
#line 179 "parser.y"
                                              { 
        exitScope();
        (yyval.node) = make_node(AST_BLOCK, (yyvsp[-1].node), NULL); }
#line 1775 "parser.tab.c"
    break;

  case 29: /* func_body: LBRACE stmt_list RBRACE  */
#line 185 "parser.y"
                            { (yyval.node) = make_node(AST_BLOCK, (yyvsp[-1].node), NULL); }
#line 1781 "parser.tab.c"
    break;

  case 30: /* stmt_list: stmt_list stmt  */
#line 189 "parser.y"
                   {
          if ((yyvsp[-1].node) == NULL) { (yyval.node) = (yyvsp[0].node); }
          else {
              struct ast_node *temp = (yyvsp[-1].node);
              while (temp->next) temp = temp->next;
              temp->next = (yyvsp[0].node);
              (yyval.node) = (yyvsp[-1].node);
          }
      }
#line 1795 "parser.tab.c"
    break;

  case 31: /* stmt_list: %empty  */
#line 198 "parser.y"
                  { (yyval.node) = NULL; }
#line 1801 "parser.tab.c"
    break;

  case 39: /* expr_stmt: expr SEMICOLON  */
#line 212 "parser.y"
                   { (yyval.node) = make_node(AST_EXPR_STMT, (yyvsp[-1].node), NULL); }
#line 1807 "parser.tab.c"
    break;

  case 40: /* if_stmt: IF LPAREN expr RPAREN stmt  */
#line 216 "parser.y"
                                                      {
        (yyval.node) = make_node(AST_IF_STMT, (yyvsp[-2].node), (yyvsp[0].node)); 
                }
#line 1815 "parser.tab.c"
    break;

  case 41: /* if_stmt: IF LPAREN expr RPAREN stmt ELSE stmt  */
#line 219 "parser.y"
                                           {
        (yyval.node) = make_node(AST_IF_STMT, (yyvsp[-4].node), NULL);
        (yyval.node)->middle = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node); 
                }
#line 1825 "parser.tab.c"
    break;

  case 42: /* while_stmt: WHILE LPAREN expr RPAREN stmt  */
#line 227 "parser.y"
                                  {
        (yyval.node) = make_node(AST_WHILE_STMT, (yyvsp[-2].node), (yyvsp[0].node));
                }
#line 1833 "parser.tab.c"
    break;

  case 43: /* return_stmt: RETURN expr SEMICOLON  */
#line 233 "parser.y"
                          { (yyval.node) = make_node(AST_RETURN_STMT, (yyvsp[-1].node), NULL); }
#line 1839 "parser.tab.c"
    break;

  case 44: /* return_stmt: RETURN SEMICOLON  */
#line 234 "parser.y"
                       { (yyval.node) = make_node(AST_RETURN_STMT, NULL, NULL); }
#line 1845 "parser.tab.c"
    break;

  case 45: /* print_stmt: PRINT expr_list SEMICOLON  */
#line 238 "parser.y"
                              { (yyval.node) = make_node(AST_PRINT_STMT, (yyvsp[-1].node), NULL); }
#line 1851 "parser.tab.c"
    break;

  case 46: /* expr_list: expr  */
#line 242 "parser.y"
         { (yyval.node) = (yyvsp[0].node); }
#line 1857 "parser.tab.c"
    break;

  case 47: /* expr_list: expr_list COMMA expr  */
#line 243 "parser.y"
                           {
        struct ast_node *temp = (yyvsp[-2].node);
        while(temp->next) temp = temp->next;
        temp->next = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
    }
#line 1868 "parser.tab.c"
    break;

  case 48: /* expr: expr PLUS expr  */
#line 252 "parser.y"
                   { (yyval.node) = make_node(AST_BINARY_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->op = PLUS; }
#line 1874 "parser.tab.c"
    break;

  case 49: /* expr: expr MINUS expr  */
#line 253 "parser.y"
                      { (yyval.node) = make_node(AST_BINARY_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->op = MINUS; }
#line 1880 "parser.tab.c"
    break;

  case 50: /* expr: expr MUL expr  */
#line 254 "parser.y"
                    { (yyval.node) = make_node(AST_BINARY_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->op = MUL; }
#line 1886 "parser.tab.c"
    break;

  case 51: /* expr: expr DIV expr  */
#line 255 "parser.y"
                    { (yyval.node) = make_node(AST_BINARY_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->op = DIV; }
#line 1892 "parser.tab.c"
    break;

  case 52: /* expr: expr MOD expr  */
#line 256 "parser.y"
                    { (yyval.node) = make_node(AST_BINARY_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->op = MOD; }
#line 1898 "parser.tab.c"
    break;

  case 53: /* expr: expr EXPO expr  */
#line 257 "parser.y"
                     { (yyval.node) = make_node(AST_BINARY_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->op = EXPO; }
#line 1904 "parser.tab.c"
    break;

  case 54: /* expr: expr EQ expr  */
#line 258 "parser.y"
                   { (yyval.node) = make_node(AST_BINARY_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->op = EQ; }
#line 1910 "parser.tab.c"
    break;

  case 55: /* expr: expr NEQ expr  */
#line 259 "parser.y"
                    { (yyval.node) = make_node(AST_BINARY_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->op = NEQ; }
#line 1916 "parser.tab.c"
    break;

  case 56: /* expr: expr LT expr  */
#line 260 "parser.y"
                   { (yyval.node) = make_node(AST_BINARY_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->op = LT; }
#line 1922 "parser.tab.c"
    break;

  case 57: /* expr: expr LE expr  */
#line 261 "parser.y"
                   { (yyval.node) = make_node(AST_BINARY_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->op = LE; }
#line 1928 "parser.tab.c"
    break;

  case 58: /* expr: expr GT expr  */
#line 262 "parser.y"
                   { (yyval.node) = make_node(AST_BINARY_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->op = GT; }
#line 1934 "parser.tab.c"
    break;

  case 59: /* expr: expr GE expr  */
#line 263 "parser.y"
                   { (yyval.node) = make_node(AST_BINARY_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->op = GE; }
#line 1940 "parser.tab.c"
    break;

  case 60: /* expr: expr AND expr  */
#line 264 "parser.y"
                    { (yyval.node) = make_node(AST_BINARY_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->op = AND; }
#line 1946 "parser.tab.c"
    break;

  case 61: /* expr: expr OR expr  */
#line 265 "parser.y"
                   { (yyval.node) = make_node(AST_BINARY_EXPR, (yyvsp[-2].node), (yyvsp[0].node)); (yyval.node)->op = OR; }
#line 1952 "parser.tab.c"
    break;

  case 62: /* expr: NOT expr  */
#line 266 "parser.y"
               { (yyval.node) = make_node(AST_UNARY_EXPR, (yyvsp[0].node), NULL); (yyval.node)->op = NOT; }
#line 1958 "parser.tab.c"
    break;

  case 63: /* expr: LPAREN expr RPAREN  */
#line 267 "parser.y"
                         {(yyval.node) = (yyvsp[-1].node); }
#line 1964 "parser.tab.c"
    break;

  case 64: /* expr: IDENTIFIER  */
#line 268 "parser.y"
                 { 
        symbol *s = lookUpSymbol((yyvsp[0].id));
        if (!s) {
            yyerror("Variable not declared!");
        }
        (yyval.node) = make_node(AST_IDENTIFIER, NULL, NULL);
                   (yyval.node)-> name = (yyvsp[0].id); }
#line 1976 "parser.tab.c"
    break;

  case 65: /* expr: IDENTIFIER ASSIGN expr  */
#line 275 "parser.y"
                             { 
        if (!lookUpSymbol((yyvsp[-2].id))) {
            yyerror("Cannot assign to undeclared variable");
        }
        (yyval.node) = make_node(AST_ASSIGN_EXPR, NULL, (yyvsp[0].node));
                   (yyval.node)-> name = (yyvsp[-2].id); }
#line 1987 "parser.tab.c"
    break;

  case 66: /* expr: IDENTIFIER LBRACK expr RBRACK ASSIGN expr  */
#line 281 "parser.y"
                                                {
        if (!lookUpSymbol((yyvsp[-5].id))) {
            yyerror("Cannot assign to undeclared array variable");
        }
        (yyval.node) = make_node(AST_ASSIGN_EXPR, (yyvsp[-3].node), (yyvsp[0].node));
        (yyval.node)->name = (yyvsp[-5].id);
    }
#line 1999 "parser.tab.c"
    break;

  case 67: /* expr: IDENTIFIER LBRACK expr RBRACK  */
#line 288 "parser.y"
                                    {
        if (!lookUpSymbol((yyvsp[-3].id))) yyerror("Undeclared array identifier");
        (yyval.node) = make_node(AST_ARRAY_LITERAL, NULL, (yyvsp[-1].node)); //treat array access like a binary op: [Identifier, Index], brilliant
        (yyval.node)->name = (yyvsp[-3].id);
       }
#line 2009 "parser.tab.c"
    break;

  case 68: /* expr: IDENTIFIER LPAREN arg_list RPAREN  */
#line 293 "parser.y"
                                        {
        if (!lookUpSymbol((yyvsp[-3].id))) yyerror("Call to undeclared function");
        (yyval.node) = make_node(AST_CALL_EXPR, (yyvsp[-1].node), NULL);
        (yyval.node)->name = (yyvsp[-3].id);
         }
#line 2019 "parser.tab.c"
    break;

  case 69: /* expr: NUMBER  */
#line 298 "parser.y"
             { (yyval.node) = make_node(AST_INTEGER_LITERAL, NULL, NULL);
                   (yyval.node)-> int_value = (yyvsp[0].num); }
#line 2026 "parser.tab.c"
    break;

  case 70: /* expr: CHARACTER_LITERAL  */
#line 300 "parser.y"
                        { (yyval.node) = make_node(AST_CHAR_LITERAL, NULL, NULL);
                   (yyval.node)-> name = (yyvsp[0].id); }
#line 2033 "parser.tab.c"
    break;

  case 71: /* expr: STRING_LITERAL  */
#line 302 "parser.y"
                     { (yyval.node) = make_node(AST_STRING_LITERAL, NULL, NULL);
                   (yyval.node)-> string_value = (yyvsp[0].id); }
#line 2040 "parser.tab.c"
    break;

  case 72: /* expr: FLOAT_LITERAL  */
#line 304 "parser.y"
                    { (yyval.node) = make_node(AST_FLOAT_LITERAL, NULL, NULL);
                   (yyval.node)-> float_value = (yyvsp[0].fnum); }
#line 2047 "parser.tab.c"
    break;

  case 73: /* expr: TRUE  */
#line 306 "parser.y"
           { (yyval.node) = make_node(AST_BOOLEAN_LITERAL, NULL, NULL);
                   (yyval.node)-> int_value = 1; }
#line 2054 "parser.tab.c"
    break;

  case 74: /* expr: FALSE  */
#line 308 "parser.y"
            { (yyval.node) = make_node(AST_BOOLEAN_LITERAL, NULL, NULL);
                   (yyval.node)-> int_value = 0; }
#line 2061 "parser.tab.c"
    break;

  case 75: /* arg_list: %empty  */
#line 313 "parser.y"
                { (yyval.node) = NULL; }
#line 2067 "parser.tab.c"
    break;

  case 76: /* arg_list: arg_list_nonempty  */
#line 314 "parser.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2073 "parser.tab.c"
    break;

  case 77: /* array_init: LBRACE expr_list RBRACE  */
#line 318 "parser.y"
                            { (yyval.node) = make_node(AST_ARRAY_INIT, (yyvsp[-1].node), NULL); }
#line 2079 "parser.tab.c"
    break;

  case 78: /* arg_list_nonempty: expr  */
#line 322 "parser.y"
         { (yyval.node) = (yyvsp[0].node); }
#line 2085 "parser.tab.c"
    break;

  case 79: /* arg_list_nonempty: arg_list_nonempty COMMA expr  */
#line 323 "parser.y"
                                   {
        struct ast_node *temp = (yyvsp[-2].node);
        while(temp->next) temp = temp->next;
        temp->next = (yyvsp[0].node);
        (yyval.node) = (yyvsp[-2].node);
    }
#line 2096 "parser.tab.c"
    break;


#line 2100 "parser.tab.c"

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

#line 331 "parser.y"


void yyerror(const char *s) {
    extern int yylineno; 
    errors++;
    fprintf(stderr, "Parse error in line %d: %s\n", yylineno, s);
}

int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror(argv[1]);
            return 1;
        }
    }

    int result = 0;
    if (yyparse() == 0 && errors == 0) {
        init_registers();
        printf("Parse successful! Starting Semantic Analysis:\n");
        semanticAnalysis(program_root);
        printf("Semantics successful\n");
        struct ast_node *current = program_root;
        while(current) {
           struct ast_node *next_backup = current->next;
    
   
    current->next = NULL;

  
    if (current->kind == AST_FUNCTION_DECL || current->kind == AST_VARIABLE_DECL) {
        generateIR(current);
    }

  
    current->next = next_backup;

  
    current = next_backup;
     }
        printf("\nOptimizing Intermediate Representation...\n");
        optimize_ir(ir_head); 
        dump_ir_to_file("output.ir", ir_head);
        generate_dot_file("graph.dot", ir_head);

        printf("Generating Assembly (output.s)...\n");
        generate_asm(ir_head, "output.s");  

        printf("\nCleaning up memory...\n");
        free_ast(program_root);

        free_ir_list(ir_head);
    }

    else{
        printf("Compilation failed with %d errors.\n", errors);
        result = 1;
    }

    if (yyin && yyin != stdin) {
        fclose(yyin);
    }

    return result;
}
