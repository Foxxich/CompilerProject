/* A Bison parser, made by GNU Bison 3.7.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "Parser.ypp"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <iostream>
	#include <string>
	#include <fstream>

	#include "Data.hpp" 
	#include "Logic.hpp" 
	#include "Loops.hpp" 

	void yyerror(char *s);
	extern FILE *yyin;
	extern int yylineno;
	int yylex();
	int parse_errors = 0;

#line 90 "Parser.tab.cpp"

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

#include "Parser.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VAR = 3,                        /* VAR  */
  YYSYMBOL__BEGIN = 4,                     /* _BEGIN  */
  YYSYMBOL_END = 5,                        /* END  */
  YYSYMBOL_UNTIL = 6,                      /* UNTIL  */
  YYSYMBOL_FOR = 7,                        /* FOR  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_REPEAT = 10,                    /* REPEAT  */
  YYSYMBOL_DO = 11,                        /* DO  */
  YYSYMBOL_THEN = 12,                      /* THEN  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_ENDIF = 14,                     /* ENDIF  */
  YYSYMBOL_FROM = 15,                      /* FROM  */
  YYSYMBOL_TO = 16,                        /* TO  */
  YYSYMBOL_DOWNTO = 17,                    /* DOWNTO  */
  YYSYMBOL_ENDFOR = 18,                    /* ENDFOR  */
  YYSYMBOL_ENDWHILE = 19,                  /* ENDWHILE  */
  YYSYMBOL_READ = 20,                      /* READ  */
  YYSYMBOL_WRITE = 21,                     /* WRITE  */
  YYSYMBOL_PLUS = 22,                      /* PLUS  */
  YYSYMBOL_MINUS = 23,                     /* MINUS  */
  YYSYMBOL_TIMES = 24,                     /* TIMES  */
  YYSYMBOL_DIV = 25,                       /* DIV  */
  YYSYMBOL_MOD = 26,                       /* MOD  */
  YYSYMBOL_LE = 27,                        /* LE  */
  YYSYMBOL_GE = 28,                        /* GE  */
  YYSYMBOL_LEQ = 29,                       /* LEQ  */
  YYSYMBOL_GEQ = 30,                       /* GEQ  */
  YYSYMBOL_EQ = 31,                        /* EQ  */
  YYSYMBOL_NEQ = 32,                       /* NEQ  */
  YYSYMBOL_ASSIGN = 33,                    /* ASSIGN  */
  YYSYMBOL_ERROR = 34,                     /* ERROR  */
  YYSYMBOL_pidentifier = 35,               /* pidentifier  */
  YYSYMBOL_num = 36,                       /* num  */
  YYSYMBOL_37_ = 37,                       /* ','  */
  YYSYMBOL_38_ = 38,                       /* '['  */
  YYSYMBOL_39_ = 39,                       /* ':'  */
  YYSYMBOL_40_ = 40,                       /* ']'  */
  YYSYMBOL_41_ = 41,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_program = 43,                   /* program  */
  YYSYMBOL_44_1 = 44,                      /* $@1  */
  YYSYMBOL_45_2 = 45,                      /* $@2  */
  YYSYMBOL_declarations = 46,              /* declarations  */
  YYSYMBOL_commands = 47,                  /* commands  */
  YYSYMBOL_command = 48,                   /* command  */
  YYSYMBOL_49_3 = 49,                      /* $@3  */
  YYSYMBOL_50_4 = 50,                      /* $@4  */
  YYSYMBOL_51_5 = 51,                      /* $@5  */
  YYSYMBOL_52_6 = 52,                      /* $@6  */
  YYSYMBOL_expression = 53,                /* expression  */
  YYSYMBOL_condition = 54,                 /* condition  */
  YYSYMBOL_value = 55,                     /* value  */
  YYSYMBOL_identifier = 56                 /* identifier  */
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
typedef yytype_int8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   209

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  41
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  106

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
       2,     2,     2,     2,    37,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    39,    41,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    40,     2,     2,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int8 yyrline[] =
{
       0,    64,    64,    64,    66,    66,    70,    71,    72,    73,
      76,    77,    80,    81,    82,    82,    84,    85,    85,    87,
      87,    89,    89,    91,    92,    95,    96,    97,    98,    99,
     100,   103,   104,   105,   106,   107,   108,   111,   112,   114,
     115,   116
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
  "\"end of file\"", "error", "\"invalid token\"", "VAR", "_BEGIN", "END",
  "UNTIL", "FOR", "IF", "WHILE", "REPEAT", "DO", "THEN", "ELSE", "ENDIF",
  "FROM", "TO", "DOWNTO", "ENDFOR", "ENDWHILE", "READ", "WRITE", "PLUS",
  "MINUS", "TIMES", "DIV", "MOD", "LE", "GE", "LEQ", "GEQ", "EQ", "NEQ",
  "ASSIGN", "ERROR", "pidentifier", "num", "','", "'['", "':'", "']'",
  "';'", "$accept", "program", "$@1", "$@2", "declarations", "commands",
  "command", "$@3", "$@4", "$@5", "$@6", "expression", "condition",
  "value", "identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,    44,    91,    58,
      93,    59
};
#endif

#define YYPACT_NINF (-29)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,   -24,   -29,    25,   -11,    -3,   174,   -29,    -7,   -29,
      -2,     9,   -28,   -28,   -29,    11,   -28,    12,    10,   -29,
      14,    17,   174,    15,    34,   -29,    45,    40,   -29,    48,
     174,    19,    21,   -22,   -29,   -29,   -28,    27,    31,    28,
     -28,   174,   -28,   -28,   -28,   -28,   -28,   -28,   174,   101,
     -29,   -29,    36,    37,    24,   175,    38,   -29,    35,     6,
     105,   -29,   -29,   -29,   -29,   -29,   -29,   134,   -28,   -29,
     -29,   -29,   -28,   -28,   -28,   -28,   -28,   -29,    46,   -28,
     -28,   -29,   -29,   -29,    42,   -29,   -29,   -29,   -29,   -29,
      41,    73,    74,   174,   -29,   -29,   -29,   -29,   138,   174,
     174,   -29,   154,   158,   -29,   -29
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     4,     0,     8,     0,     0,     1,     0,     2,
       0,     0,     0,     0,    17,     0,     0,    39,     0,    11,
       0,     0,     0,     6,     0,    37,     0,     0,    38,     0,
       0,     0,     0,     0,     5,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,    24,     0,     0,     0,    25,     0,     3,     0,     0,
       0,    33,    34,    35,    36,    31,    32,     0,     0,    40,
      41,    12,     0,     0,     0,     0,     0,     9,     0,     0,
       0,    14,    13,    16,     0,    26,    27,    28,    29,    30,
       0,     0,     0,     0,    18,     7,    19,    21,     0,     0,
       0,    15,     0,     0,    20,    22
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -29,   -29,   -29,   -29,   -29,   -20,   -12,   -29,   -29,   -29,
     -29,   -29,   -10,    59,    -6
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,    22,     6,     5,    18,    19,    93,    30,    99,
     100,    54,    26,    27,    28
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      20,     9,    38,    29,     1,     2,    35,    17,    25,    31,
      49,     4,    20,    52,    53,    34,    20,    11,    12,    13,
      14,    60,    79,    80,    20,     7,    35,     8,    67,    21,
      15,    16,    20,    23,    10,    20,    57,    35,    11,    12,
      13,    14,    20,    20,    24,    17,    17,    36,    35,    40,
      33,    15,    16,    39,    20,    35,    37,    41,    84,    48,
      50,    20,    51,    56,    58,    71,    17,    42,    43,    44,
      45,    46,    47,    98,    78,    32,    69,    70,    77,   102,
     103,    95,    90,    94,    96,    97,    35,    20,     0,     0,
      35,    35,    20,    20,    20,    55,    20,    20,     0,    59,
       0,    61,    62,    63,    64,    65,    66,    68,    11,    12,
      13,    14,    11,    12,    13,    14,     0,     0,    81,    82,
       0,    15,    16,     0,     0,    15,    16,     0,     0,     0,
       0,    85,    86,    87,    88,    89,    17,     0,    91,    92,
      17,    11,    12,    13,    14,    11,    12,    13,    14,     0,
       0,     0,   101,    83,    15,    16,     0,     0,    15,    16,
       0,    11,    12,    13,    14,    11,    12,    13,    14,    17,
       0,     0,   104,    17,    15,    16,   105,     0,    15,    16,
       0,    11,    12,    13,    14,     0,     0,     0,     0,    17,
       0,     0,     0,    17,    15,    16,     0,    72,    73,    74,
      75,    76,     0,     0,     0,     0,     0,     0,     0,    17
};

static const yytype_int8 yycheck[] =
{
       6,     4,    22,    13,     3,     4,    18,    35,    36,    15,
      30,    35,    18,    35,    36,     5,    22,     7,     8,     9,
      10,    41,    16,    17,    30,     0,    38,    38,    48,    36,
      20,    21,    38,    35,    37,    41,     5,    49,     7,     8,
       9,    10,    48,    49,    35,    35,    35,    33,    60,    15,
      38,    20,    21,    38,    60,    67,    39,    12,    68,    11,
      41,    67,    41,    36,    36,    41,    35,    27,    28,    29,
      30,    31,    32,    93,    39,    16,    40,    40,    40,    99,
     100,    40,    36,    41,    11,    11,    98,    93,    -1,    -1,
     102,   103,    98,    99,   100,    36,   102,   103,    -1,    40,
      -1,    42,    43,    44,    45,    46,    47,     6,     7,     8,
       9,    10,     7,     8,     9,    10,    -1,    -1,    13,    14,
      -1,    20,    21,    -1,    -1,    20,    21,    -1,    -1,    -1,
      -1,    72,    73,    74,    75,    76,    35,    -1,    79,    80,
      35,     7,     8,     9,    10,     7,     8,     9,    10,    -1,
      -1,    -1,    14,    19,    20,    21,    -1,    -1,    20,    21,
      -1,     7,     8,     9,    10,     7,     8,     9,    10,    35,
      -1,    -1,    18,    35,    20,    21,    18,    -1,    20,    21,
      -1,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    35,
      -1,    -1,    -1,    35,    20,    21,    -1,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,    43,    35,    46,    45,     0,    38,     4,
      37,     7,     8,     9,    10,    20,    21,    35,    47,    48,
      56,    36,    44,    35,    35,    36,    54,    55,    56,    54,
      50,    56,    55,    38,     5,    48,    33,    39,    47,    38,
      15,    12,    27,    28,    29,    30,    31,    32,    11,    47,
      41,    41,    35,    36,    53,    55,    36,     5,    36,    55,
      47,    55,    55,    55,    55,    55,    55,    47,     6,    40,
      40,    41,    22,    23,    24,    25,    26,    40,    39,    16,
      17,    13,    14,    19,    54,    55,    55,    55,    55,    55,
      36,    55,    55,    49,    41,    40,    11,    11,    47,    51,
      52,    14,    47,    47,    18,    18
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    44,    43,    45,    43,    46,    46,    46,    46,
      47,    47,    48,    48,    49,    48,    48,    50,    48,    51,
      48,    52,    48,    48,    48,    53,    53,    53,    53,    53,
      53,    54,    54,    54,    54,    54,    54,    55,    55,    56,
      56,    56
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     6,     0,     4,     3,     8,     1,     6,
       2,     1,     4,     5,     0,     8,     5,     0,     6,     0,
      10,     0,    10,     3,     3,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       4,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2: /* $@1: %empty  */
#line 64 "Parser.ypp"
                                                                        {registers();}
#line 1212 "Parser.tab.cpp"
    break;

  case 3: /* program: VAR declarations _BEGIN $@1 commands END  */
#line 65 "Parser.ypp"
                                                                                {finish();}
#line 1218 "Parser.tab.cpp"
    break;

  case 4: /* $@2: %empty  */
#line 66 "Parser.ypp"
                                                                                        {registers();}
#line 1224 "Parser.tab.cpp"
    break;

  case 5: /* program: _BEGIN $@2 commands END  */
#line 67 "Parser.ypp"
                                                                                {finish();}
#line 1230 "Parser.tab.cpp"
    break;

  case 6: /* declarations: declarations ',' pidentifier  */
#line 70 "Parser.ypp"
                                                                                        {put_var(*(yyvsp[0].pidentifier),yylineno);}
#line 1236 "Parser.tab.cpp"
    break;

  case 7: /* declarations: declarations ',' pidentifier '[' num ':' num ']'  */
#line 71 "Parser.ypp"
                                                                        {put_in_array(*(yyvsp[-5].pidentifier),(yyvsp[-3].num),(yyvsp[-1].num),yylineno);}
#line 1242 "Parser.tab.cpp"
    break;

  case 8: /* declarations: pidentifier  */
#line 72 "Parser.ypp"
                                                                                                        {put_var(*(yyvsp[0].pidentifier),yylineno);}
#line 1248 "Parser.tab.cpp"
    break;

  case 9: /* declarations: pidentifier '[' num ':' num ']'  */
#line 73 "Parser.ypp"
                                                                                        {put_in_array(*(yyvsp[-5].pidentifier),(yyvsp[-3].num),(yyvsp[-1].num),yylineno);}
#line 1254 "Parser.tab.cpp"
    break;

  case 12: /* command: identifier ASSIGN expression ';'  */
#line 80 "Parser.ypp"
                                                                                        {assign((yyvsp[-3].var),(yyvsp[-1].var),yylineno);}
#line 1260 "Parser.tab.cpp"
    break;

  case 13: /* command: IF condition THEN commands ENDIF  */
#line 81 "Parser.ypp"
                                                                    {if_block();}
#line 1266 "Parser.tab.cpp"
    break;

  case 14: /* $@3: %empty  */
#line 82 "Parser.ypp"
                                                                                {else_block();}
#line 1272 "Parser.tab.cpp"
    break;

  case 15: /* command: IF condition THEN commands ELSE $@3 commands ENDIF  */
#line 83 "Parser.ypp"
                                                                    {endif_block();}
#line 1278 "Parser.tab.cpp"
    break;

  case 16: /* command: WHILE condition DO commands ENDWHILE  */
#line 84 "Parser.ypp"
                                                                                {while_block();}
#line 1284 "Parser.tab.cpp"
    break;

  case 17: /* $@4: %empty  */
#line 85 "Parser.ypp"
                                                                                                                {repeat_block();}
#line 1290 "Parser.tab.cpp"
    break;

  case 18: /* command: REPEAT $@4 commands UNTIL condition ';'  */
#line 86 "Parser.ypp"
                                                                                        {until_block();}
#line 1296 "Parser.tab.cpp"
    break;

  case 19: /* $@5: %empty  */
#line 87 "Parser.ypp"
                                                          {for_to_block(*(yyvsp[-5].pidentifier),(yyvsp[-3].var),(yyvsp[-1].var),yylineno);}
#line 1302 "Parser.tab.cpp"
    break;

  case 20: /* command: FOR pidentifier FROM value TO value DO $@5 commands ENDFOR  */
#line 88 "Parser.ypp"
                                                                                                        {endfor_to_block();}
#line 1308 "Parser.tab.cpp"
    break;

  case 21: /* $@6: %empty  */
#line 89 "Parser.ypp"
                                                              {for_downto_block(*(yyvsp[-5].pidentifier),(yyvsp[-3].var),(yyvsp[-1].var),yylineno);}
#line 1314 "Parser.tab.cpp"
    break;

  case 22: /* command: FOR pidentifier FROM value DOWNTO value DO $@6 commands ENDFOR  */
#line 90 "Parser.ypp"
                                                                                                        {endfor_downto_block();}
#line 1320 "Parser.tab.cpp"
    break;

  case 23: /* command: READ identifier ';'  */
#line 91 "Parser.ypp"
                                                                                                {read((yyvsp[-1].var),yylineno);}
#line 1326 "Parser.tab.cpp"
    break;

  case 24: /* command: WRITE value ';'  */
#line 92 "Parser.ypp"
                                                                                                        {write((yyvsp[-1].var),yylineno);}
#line 1332 "Parser.tab.cpp"
    break;

  case 26: /* expression: value PLUS value  */
#line 96 "Parser.ypp"
                                                                                                        {func_plus((yyvsp[-2].var), (yyvsp[0].var), yylineno);}
#line 1338 "Parser.tab.cpp"
    break;

  case 27: /* expression: value MINUS value  */
#line 97 "Parser.ypp"
                                                                                                {func_minus((yyvsp[-2].var),(yyvsp[0].var),yylineno);}
#line 1344 "Parser.tab.cpp"
    break;

  case 28: /* expression: value TIMES value  */
#line 98 "Parser.ypp"
                                                                                                {func_times((yyvsp[-2].var),(yyvsp[0].var),yylineno);}
#line 1350 "Parser.tab.cpp"
    break;

  case 29: /* expression: value DIV value  */
#line 99 "Parser.ypp"
                                                                                                        {func_div((yyvsp[-2].var),(yyvsp[0].var),yylineno);}
#line 1356 "Parser.tab.cpp"
    break;

  case 30: /* expression: value MOD value  */
#line 100 "Parser.ypp"
                                                                                                {func_mod((yyvsp[-2].var),(yyvsp[0].var),yylineno);}
#line 1362 "Parser.tab.cpp"
    break;

  case 31: /* condition: value EQ value  */
#line 103 "Parser.ypp"
                                        {condition_eq((yyvsp[-2].var),(yyvsp[0].var),yylineno);}
#line 1368 "Parser.tab.cpp"
    break;

  case 32: /* condition: value NEQ value  */
#line 104 "Parser.ypp"
                                        {condition_neq((yyvsp[-2].var),(yyvsp[0].var),yylineno);}
#line 1374 "Parser.tab.cpp"
    break;

  case 33: /* condition: value LE value  */
#line 105 "Parser.ypp"
                                        {condition_le((yyvsp[-2].var),(yyvsp[0].var),yylineno);}
#line 1380 "Parser.tab.cpp"
    break;

  case 34: /* condition: value GE value  */
#line 106 "Parser.ypp"
                                    {condition_ge((yyvsp[-2].var),(yyvsp[0].var),yylineno);}
#line 1386 "Parser.tab.cpp"
    break;

  case 35: /* condition: value LEQ value  */
#line 107 "Parser.ypp"
                                        {condition_leq((yyvsp[-2].var),(yyvsp[0].var),yylineno);}
#line 1392 "Parser.tab.cpp"
    break;

  case 36: /* condition: value GEQ value  */
#line 108 "Parser.ypp"
                                        {condition_geq((yyvsp[-2].var),(yyvsp[0].var),yylineno);}
#line 1398 "Parser.tab.cpp"
    break;

  case 37: /* value: num  */
#line 111 "Parser.ypp"
                                                                                                                        {(yyval.var)=function_number((yyvsp[0].num),yylineno);}
#line 1404 "Parser.tab.cpp"
    break;

  case 39: /* identifier: pidentifier  */
#line 114 "Parser.ypp"
                                                                                                        {(yyval.var) = function_pidentifier(*(yyvsp[0].pidentifier), yylineno);}
#line 1410 "Parser.tab.cpp"
    break;

  case 40: /* identifier: pidentifier '[' pidentifier ']'  */
#line 115 "Parser.ypp"
                                                                                        {(yyval.var) = function_pidentifier_array(*(yyvsp[-3].pidentifier),*(yyvsp[-1].pidentifier),yylineno);}
#line 1416 "Parser.tab.cpp"
    break;

  case 41: /* identifier: pidentifier '[' num ']'  */
#line 116 "Parser.ypp"
                                                                                        {(yyval.var)=function_pidentifier(*(yyvsp[-3].pidentifier),(yyvsp[-1].num),yylineno);}
#line 1422 "Parser.tab.cpp"
    break;


#line 1426 "Parser.tab.cpp"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
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

#line 118 "Parser.ypp"


void yyerror(char * err_sym)
{
	parse_errors++;
	std::cout << err_sym << " - unrecognized token (line " << yylineno << ")" << std::endl;
    std::cout << "### \x1b[31mErrors occured\x1b[0m ###" << std::endl;
	exit(0);
}

int main(int argc, char *argv[] )
{ 
	if (argc < 3) {
        std::cout << "### \x1b[31mNot enough arguments\x1b[0m ###" << std::endl;
        return 0;
    } 
	else 
	{
		++argv; 
		std::string input_file_0 = argv[0];
		std::string input_file_1 = argv[1];
		std::ofstream outfile;
		yyin = fopen(input_file_0.c_str(), "r");
		outfile.open (input_file_1.c_str());
		if(!yyin) 
		{
			std::cout << "### \x1b[31mCan't open file\x1b[0m ###" << std::endl;
			return 0;
		}
		parse_errors = 0;
		yyparse();
		int sumErrors = parse_errors + tableErrors + codeErrors;
		if(sumErrors == 0)
		{
			for(int i=0;i<cmds.size();i++)
			{
				outfile << cmds[i] << std::endl;
			}
			std::cout << "### \x1b[32mCompilation completed successfully\x1b[0m ###" << std::endl;
		} 
		else 
		{
			std::cout << "### \x1b[31mErrors occured\x1b[0m ###" << std::endl;
		}
		fclose(yyin);
		outfile.close();
		return 0;
	}
}
