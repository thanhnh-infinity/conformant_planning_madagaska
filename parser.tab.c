/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 4 "parser.y"


#include "stdio.h"
#include "main.h"
#include "asyntax.h"


void rparen(char *);

int COST;


/* Line 371 of yacc.c  */
#line 81 "parser.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     rwMINIMIZE = 258,
     rwMETRIC = 259,
     rwINCREASE = 260,
     rwEITHER = 261,
     rwCONSTANTS = 262,
     rwLENGTH = 263,
     rwEXISTS = 264,
     EQUA = 265,
     rwPROBLEM = 266,
     rwFORALL = 267,
     rwIMPLY = 268,
     rwNOT = 269,
     rwWHEN = 270,
     rwONEOF = 271,
     rwOR = 272,
     rwAND = 273,
     rwTYPING = 274,
     rwDOMAIN = 275,
     rwGOAL = 276,
     rwINIT = 277,
     rwOBJECTS = 278,
     rwTYPES = 279,
     rwREQUIREMENTS = 280,
     rwPREDICATES = 281,
     rwPRECOND = 282,
     rwEFFECT = 283,
     rwPARAMS = 284,
     rwACTION = 285,
     rwDEFINE = 286,
     DASH = 287,
     LPAREN = 288,
     RPAREN = 289,
     INT = 290,
     VAR = 291,
     ID = 292,
     rwFUNCTIONS = 293
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 17 "parser.y"

  int i;
  intlist *intlistp;
  atomlist *atomlistp;
  atom *atomp;
  Sfma *Sfmap;
  Sfmalist *Sfmalistp;
  Seff *Seffp;
  Sefflist *Sefflistp;
  typedvarlist *typedvarlistp;


/* Line 387 of yacc.c  */
#line 175 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 203 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   205

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  131
/* YYNRULES -- Number of states.  */
#define YYNSTATES  247

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    10,    16,    17,    23,    28,
      33,    38,    41,    44,    45,    47,    49,    52,    53,    54,
      55,    66,    69,    70,    71,    77,    78,    84,    85,    91,
      92,    98,    99,   105,   106,   107,   115,   118,   120,   121,
     127,   130,   133,   135,   137,   138,   141,   143,   146,   148,
     152,   153,   154,   165,   166,   172,   173,   178,   181,   184,
     187,   190,   194,   196,   198,   199,   201,   203,   204,   208,
     212,   216,   220,   221,   225,   229,   233,   237,   238,   243,
     245,   250,   251,   261,   264,   265,   266,   273,   274,   277,
     278,   282,   284,   285,   291,   292,   297,   298,   304,   305,
     312,   313,   319,   320,   327,   328,   334,   336,   337,   344,
     345,   354,   355,   364,   367,   369,   372,   374,   376,   378,
     379,   384,   385,   391,   392,   399,   400,   409,   411,   412,
     418,   419
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      40,     0,    -1,    51,    70,    -1,    37,    41,    -1,    -1,
      33,    10,   102,   102,    34,    -1,    -1,    33,    37,    50,
      44,    34,    -1,    33,    16,    48,    34,    -1,    33,    17,
      48,    34,    -1,    33,    14,    48,    34,    -1,    48,    43,
      -1,    48,    42,    -1,    -1,    36,    -1,    37,    -1,    49,
      50,    -1,    -1,    -1,    -1,    33,    31,    33,    20,    37,
      52,    34,    54,    53,    34,    -1,    54,    55,    -1,    -1,
      -1,    33,    26,    84,    56,    34,    -1,    -1,    33,    25,
      41,    57,    34,    -1,    -1,    33,     7,    81,    58,    34,
      -1,    -1,    33,    38,    86,    59,    34,    -1,    -1,    33,
      24,    81,    60,    34,    -1,    -1,    -1,    33,    30,    61,
      37,    63,    62,    34,    -1,    64,    63,    -1,    64,    -1,
      -1,    29,    33,    66,    65,    34,    -1,    27,    90,    -1,
      28,   103,    -1,    67,    -1,    68,    -1,    -1,    36,    67,
      -1,    36,    -1,    69,    68,    -1,    69,    -1,    67,    32,
      37,    -1,    -1,    -1,    33,    31,    33,    11,    37,    71,
      34,    73,    72,    34,    -1,    -1,    73,    33,    76,    74,
      34,    -1,    -1,    33,    76,    75,    34,    -1,    20,    37,
      -1,    23,    81,    -1,    22,    77,    -1,    21,    90,    -1,
       4,     3,    48,    -1,    48,    -1,    78,    -1,    -1,    80,
      -1,    79,    -1,    -1,    48,    46,    48,    -1,    48,    46,
      79,    -1,    48,    45,    79,    -1,    48,    47,    79,    -1,
      -1,    48,    45,    48,    -1,    48,    45,    80,    -1,    48,
      46,    80,    -1,    48,    47,    80,    -1,    -1,    41,    32,
      37,    81,    -1,    41,    -1,    36,    32,    37,    82,    -1,
      -1,    36,    32,    33,     6,    37,    41,    83,    34,    82,
      -1,    36,    82,    -1,    -1,    -1,    84,    33,    37,    82,
      85,    34,    -1,    -1,    87,    86,    -1,    -1,    88,    32,
      37,    -1,    88,    -1,    -1,    33,    37,    82,    89,    34,
      -1,    -1,    33,    18,    91,    34,    -1,    -1,    33,    18,
     100,    92,    34,    -1,    -1,    33,    15,    90,    90,    93,
      34,    -1,    -1,    33,    17,   100,    94,    34,    -1,    -1,
      33,    13,    90,    90,    95,    34,    -1,    -1,    33,    14,
      90,    96,    34,    -1,    43,    -1,    -1,    33,    10,    49,
      49,    97,    34,    -1,    -1,    33,    12,    33,    66,    34,
      90,    98,    34,    -1,    -1,    33,     9,    33,    66,    34,
      90,    99,    34,    -1,   100,    90,    -1,    90,    -1,   101,
     103,    -1,   103,    -1,    43,    -1,    35,    -1,    -1,    33,
      18,   104,    34,    -1,    -1,    33,    18,   101,   105,    34,
      -1,    -1,    33,    15,    90,   103,   106,    34,    -1,    -1,
      33,    12,    33,    66,    34,   103,   107,    34,    -1,    43,
      -1,    -1,    33,    14,    43,   108,    34,    -1,    -1,    33,
       5,    43,   102,   109,    34,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    56,    56,    59,    60,    63,    66,    66,    70,    73,
      76,    80,    81,    82,    85,    86,    89,    90,    95,    95,
      95,    98,    99,   102,   102,   103,   103,   104,   104,   105,
     105,   106,   106,   107,   107,   107,   110,   111,   114,   114,
     115,   116,   119,   120,   121,   124,   125,   128,   129,   132,
     136,   136,   136,   139,   139,   140,   140,   143,   144,   145,
     146,   147,   152,   153,   154,   157,   158,   159,   162,   163,
     164,   165,   166,   176,   177,   178,   179,   180,   185,   186,
     189,   190,   190,   191,   192,   195,   195,   196,   199,   200,
     203,   204,   207,   207,   212,   212,   213,   213,   214,   214,
     215,   215,   216,   216,   217,   217,   218,   219,   219,   220,
     220,   221,   221,   224,   225,   228,   229,   232,   233,   236,
     236,   237,   237,   238,   238,   239,   239,   240,   241,   241,
     242,   242
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "rwMINIMIZE", "rwMETRIC", "rwINCREASE",
  "rwEITHER", "rwCONSTANTS", "rwLENGTH", "rwEXISTS", "EQUA", "rwPROBLEM",
  "rwFORALL", "rwIMPLY", "rwNOT", "rwWHEN", "rwONEOF", "rwOR", "rwAND",
  "rwTYPING", "rwDOMAIN", "rwGOAL", "rwINIT", "rwOBJECTS", "rwTYPES",
  "rwREQUIREMENTS", "rwPREDICATES", "rwPRECOND", "rwEFFECT", "rwPARAMS",
  "rwACTION", "rwDEFINE", "DASH", "LPAREN", "RPAREN", "INT", "VAR", "ID",
  "rwFUNCTIONS", "$accept", "begin", "idlist", "costexpr", "atom", "$@1",
  "one_of_combine", "or_combine", "not_combine", "atomlist", "varid",
  "varidlist", "domain", "$@2", "$@3", "domaindefs", "domaindef", "$@4",
  "$@5", "$@6", "$@7", "$@8", "$@9", "$@10", "actdefs", "actdef", "$@11",
  "opvars", "varlist", "opvarlist", "opvar", "problem", "$@12", "$@13",
  "defs", "$@14", "$@15", "def", "initCollect", "complex_structure",
  "or_structure", "one_of_structure", "objectlist", "typedvarlist", "$@16",
  "typedatoms", "$@17", "functiondecls", "functiondecl", "tdecl", "$@18",
  "fma", "$@19", "$@20", "$@21", "$@22", "$@23", "$@24", "$@25", "$@26",
  "$@27", "fmas", "effects", "numexpr", "effect", "$@28", "$@29", "$@30",
  "$@31", "$@32", "$@33", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    44,    43,    45,    46,
      47,    48,    48,    48,    49,    49,    50,    50,    52,    53,
      51,    54,    54,    56,    55,    57,    55,    58,    55,    59,
      55,    60,    55,    61,    62,    55,    63,    63,    65,    64,
      64,    64,    66,    66,    66,    67,    67,    68,    68,    69,
      71,    72,    70,    74,    73,    75,    73,    76,    76,    76,
      76,    76,    77,    77,    77,    78,    78,    78,    79,    79,
      79,    79,    79,    80,    80,    80,    80,    80,    81,    81,
      82,    83,    82,    82,    82,    85,    84,    84,    86,    86,
      87,    87,    89,    88,    91,    90,    92,    90,    93,    90,
      94,    90,    95,    90,    96,    90,    90,    97,    90,    98,
      90,    99,    90,   100,   100,   101,   101,   102,   102,   104,
     103,   105,   103,   106,   103,   107,   103,   103,   108,   103,
     109,   103
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     5,     0,     5,     4,     4,
       4,     2,     2,     0,     1,     1,     2,     0,     0,     0,
      10,     2,     0,     0,     5,     0,     5,     0,     5,     0,
       5,     0,     5,     0,     0,     7,     2,     1,     0,     5,
       2,     2,     1,     1,     0,     2,     1,     2,     1,     3,
       0,     0,    10,     0,     5,     0,     4,     2,     2,     2,
       2,     3,     1,     1,     0,     1,     1,     0,     3,     3,
       3,     3,     0,     3,     3,     3,     3,     0,     4,     1,
       4,     0,     9,     2,     0,     0,     6,     0,     2,     0,
       3,     1,     0,     5,     0,     4,     0,     5,     0,     6,
       0,     5,     0,     6,     0,     5,     1,     0,     6,     0,
       8,     0,     8,     2,     1,     2,     1,     1,     1,     0,
       4,     0,     5,     0,     6,     0,     8,     1,     0,     5,
       0,     6
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     2,     0,     0,
       0,     0,    18,     0,     0,    50,    22,     0,    19,     0,
       0,     0,    21,     0,    51,     4,     4,     4,    87,    33,
      89,    20,     0,     0,     0,    13,     4,    55,     0,     0,
       4,    79,    27,    31,    25,    23,     0,     0,    29,    89,
      91,    13,    57,     0,   106,    60,    62,    59,    63,    66,
      65,    58,     0,    53,    52,     3,     0,     0,     0,     0,
       0,     0,     0,    84,     0,    88,     0,    61,     0,     0,
       0,     0,     0,     0,     0,    94,    17,     0,    12,    11,
      13,    13,    13,    56,     0,     4,    28,    32,    26,    84,
      24,     0,     0,     0,    34,    37,    84,    92,    30,    90,
       0,    44,    14,    15,     0,    44,     0,   104,     0,   114,
     100,     0,    96,    17,     6,     0,    13,    13,    13,    73,
      70,    74,    68,    69,    75,     0,    71,    76,    54,    78,
      85,    40,     0,   127,    41,    44,     0,    36,     0,    83,
       0,    46,     0,    42,    43,    48,   107,     0,   102,     0,
      98,   113,     0,    95,     0,    16,     0,     0,   118,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   119,
      38,    35,     0,    84,    93,    45,     0,     0,     0,    47,
       0,     0,     0,   105,     0,   101,    97,     7,     0,    10,
       8,     9,    86,     0,    44,   128,     0,   121,   116,     0,
       0,     0,    80,   111,    49,   108,   109,   103,    99,     5,
     130,     0,     0,   123,   115,     0,   120,    39,     4,     0,
       0,     0,     0,   129,     0,   122,    81,   112,   110,   131,
     125,   124,     0,     0,    84,   126,    82
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    41,    88,    54,   166,    90,    91,    92,    56,
     123,   124,     3,    14,    21,    18,    22,    71,    69,    67,
      74,    68,    46,   146,   104,   105,   210,   152,   153,   154,
     155,     7,    17,    39,    24,    94,    62,    37,    57,    58,
      59,    60,    42,   107,   242,    45,   174,    48,    49,    50,
     150,   119,   121,   164,   194,   162,   192,   159,   190,   230,
     229,   120,   207,   170,   144,   209,   225,   234,   243,   222,
     231
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -173
static const yytype_int16 yypact[] =
{
      -5,   -23,    30,    -1,     3,  -173,    12,  -173,    36,    13,
      31,    60,  -173,    38,    51,  -173,  -173,    53,    58,    63,
      14,    70,  -173,    41,    86,    84,    84,    84,  -173,  -173,
      90,  -173,   123,    91,    94,  -173,    84,  -173,    41,    95,
      84,    98,  -173,  -173,  -173,    99,    96,    97,  -173,    90,
     103,  -173,  -173,    88,  -173,  -173,   104,  -173,  -173,  -173,
    -173,  -173,   102,  -173,  -173,  -173,   101,   105,   106,   107,
     108,   109,    26,   111,   110,  -173,   112,   120,   122,    71,
     124,    94,    94,    94,    94,    94,    71,    62,  -173,  -173,
    -173,  -173,   126,  -173,   127,    84,  -173,  -173,  -173,   111,
    -173,    94,   125,   129,  -173,    26,   -21,  -173,  -173,  -173,
       0,   128,  -173,  -173,    71,   128,    94,  -173,    94,  -173,
      94,   131,    94,    71,  -173,   -16,  -173,  -173,  -173,   104,
    -173,  -173,   104,  -173,  -173,   104,  -173,  -173,  -173,  -173,
    -173,  -173,    11,  -173,  -173,   128,   132,  -173,   -13,  -173,
     133,   128,   134,   137,  -173,   128,  -173,   136,  -173,   138,
    -173,  -173,   139,  -173,   140,  -173,   141,   119,  -173,  -173,
     -16,    76,    78,    80,   142,   130,   145,   130,    94,   125,
    -173,  -173,   165,   111,  -173,  -173,    94,   143,   137,  -173,
     147,    94,   148,  -173,   149,  -173,  -173,  -173,   150,  -173,
    -173,  -173,  -173,   -16,   128,  -173,   125,   125,  -173,   151,
     152,   153,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,   154,   155,  -173,  -173,   157,  -173,  -173,    84,   158,
     159,   160,   125,  -173,   161,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,   162,   163,   111,  -173,  -173
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -173,  -173,   -27,  -173,   -55,  -173,  -173,  -173,  -173,   -33,
     -73,     8,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,    37,  -173,  -173,  -112,  -124,    24,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,   164,  -173,  -173,
     -25,    -9,   -22,   -94,  -173,  -173,  -173,   156,  -173,  -173,
    -173,   -32,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,   113,  -173,  -161,  -172,  -173,  -173,  -173,  -173,  -173,
    -173
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -73
static const yytype_int16 yytable[] =
{
      44,    89,    55,   157,    43,   140,   114,   208,     4,   198,
     125,   148,   149,    65,    61,   106,   175,   167,    77,   168,
     182,    25,    89,   176,   183,   177,   178,   185,     1,   179,
       5,   188,     6,   180,   223,   224,     8,    86,    26,    27,
      28,   156,   220,     9,    29,    32,    11,   143,    86,   116,
     117,   118,    30,   101,   102,   103,    10,   129,   132,   135,
     240,    33,    34,    35,    36,   130,   133,   136,    12,   141,
     169,    13,   125,   139,    89,    15,   126,    89,   127,   128,
      89,   131,   134,   137,   158,    16,   160,    19,   161,   212,
     161,    20,   221,   171,   172,   173,    23,    78,    79,    86,
      80,    81,    82,    83,    31,    84,    85,   112,   113,   110,
     199,   110,   200,   110,   201,   169,    89,    89,    89,    38,
     203,    40,   205,    47,   143,    86,    51,    53,    52,    64,
      66,   165,    70,    72,    73,    76,    93,    87,    95,    96,
      97,    98,   147,   100,   108,    99,   206,   106,   169,   109,
     246,   143,   143,   110,   213,   111,    86,   115,   142,   216,
     -72,   138,   145,   167,   151,   163,   181,   184,   186,   187,
     191,   211,   193,   195,   196,   197,   202,   143,   204,   189,
     214,   215,   217,   218,   219,   226,   227,     0,   232,   233,
     228,   235,   237,   238,   239,   241,   244,   245,   122,     0,
       0,   236,    63,     0,     0,    75
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-173)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      27,    56,    34,   115,    26,    99,    79,   179,    31,   170,
      10,    32,   106,    40,    36,    36,     5,    33,    51,    35,
      33,     7,    77,    12,    37,    14,    15,   151,    33,    18,
       0,   155,    33,   145,   206,   207,    33,    37,    24,    25,
      26,   114,   203,    31,    30,     4,    33,   102,    37,    81,
      82,    83,    38,    27,    28,    29,    20,    90,    91,    92,
     232,    20,    21,    22,    23,    90,    91,    92,    37,   101,
     125,    11,    10,    95,   129,    37,    14,   132,    16,    17,
     135,    90,    91,    92,   116,    34,   118,    34,   120,   183,
     122,    33,   204,   126,   127,   128,    33,     9,    10,    37,
      12,    13,    14,    15,    34,    17,    18,    36,    37,    33,
      34,    33,    34,    33,    34,   170,   171,   172,   173,    33,
     175,    37,   177,    33,   179,    37,     3,    33,    37,    34,
      32,   123,    33,    37,    37,    32,    34,    33,    37,    34,
      34,    34,   105,    34,    34,    37,   178,    36,   203,    37,
     244,   206,   207,    33,   186,    33,    37,    33,    33,   191,
      34,    34,    33,    33,    36,    34,    34,    34,    34,    32,
      34,     6,    34,    34,    34,    34,    34,   232,    33,   155,
      37,    34,    34,    34,    34,    34,    34,    -1,    34,    34,
      37,    34,    34,    34,    34,    34,    34,    34,    85,    -1,
      -1,   228,    38,    -1,    -1,    49
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    33,    40,    51,    31,     0,    33,    70,    33,    31,
      20,    33,    37,    11,    52,    37,    34,    71,    54,    34,
      33,    53,    55,    33,    73,     7,    24,    25,    26,    30,
      38,    34,     4,    20,    21,    22,    23,    76,    33,    72,
      37,    41,    81,    81,    41,    84,    61,    33,    86,    87,
      88,     3,    37,    33,    43,    90,    48,    77,    78,    79,
      80,    81,    75,    76,    34,    41,    32,    58,    60,    57,
      33,    56,    37,    37,    59,    86,    32,    48,     9,    10,
      12,    13,    14,    15,    17,    18,    37,    33,    42,    43,
      45,    46,    47,    34,    74,    37,    34,    34,    34,    37,
      34,    27,    28,    29,    63,    64,    36,    82,    34,    37,
      33,    33,    36,    37,    49,    33,    90,    90,    90,    90,
     100,    91,   100,    49,    50,    10,    14,    16,    17,    48,
      79,    80,    48,    79,    80,    48,    79,    80,    34,    81,
      82,    90,    33,    43,   103,    33,    62,    63,    32,    82,
      89,    36,    66,    67,    68,    69,    49,    66,    90,    96,
      90,    90,    94,    34,    92,    50,    44,    33,    35,    43,
     102,    48,    48,    48,    85,     5,    12,    14,    15,    18,
      66,    34,    33,    37,    34,    67,    34,    32,    67,    68,
      97,    34,    95,    34,    93,    34,    34,    34,   102,    34,
      34,    34,    34,    43,    33,    43,    90,   101,   103,   104,
      65,     6,    82,    90,    37,    34,    90,    34,    34,    34,
     102,    66,   108,   103,   103,   105,    34,    34,    37,    99,
      98,   109,    34,    34,   106,    34,    41,    34,    34,    34,
     103,    34,    83,   107,    34,    34,    82
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
/* Line 1787 of yacc.c  */
#line 59 "parser.y"
    { (yyval.intlistp) = intcons((yyvsp[(1) - (2)].i),(yyvsp[(2) - (2)].intlistp)); }
    break;

  case 4:
/* Line 1787 of yacc.c  */
#line 60 "parser.y"
    { (yyval.intlistp) = EMPTYLIST; }
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 63 "parser.y"
    { }
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 66 "parser.y"
    { rparen("term"); }
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 66 "parser.y"
    { (yyval.atomp) = newatom((yyvsp[(2) - (5)].i),(yyvsp[(3) - (5)].intlistp)); }
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 70 "parser.y"
    {save_one_of((yyvsp[(3) - (4)].atomlistp));}
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 73 "parser.y"
    {save_or((yyvsp[(3) - (4)].atomlistp));}
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 76 "parser.y"
    {save_not((yyvsp[(3) - (4)].atomlistp));}
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 80 "parser.y"
    { (yyval.atomlistp) = atomcons((yyvsp[(2) - (2)].atomp),(yyvsp[(1) - (2)].atomlistp)); }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 81 "parser.y"
    { (yyval.atomlistp) = (yyvsp[(1) - (2)].atomlistp); }
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 82 "parser.y"
    { (yyval.atomlistp) = EMPTYLIST; }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 85 "parser.y"
    { (yyval.i) = (yyvsp[(1) - (1)].i); }
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 86 "parser.y"
    { (yyval.i) = (yyvsp[(1) - (1)].i); }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 89 "parser.y"
    { (yyval.intlistp) = intcons((yyvsp[(1) - (2)].i),(yyvsp[(2) - (2)].intlistp)); }
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 90 "parser.y"
    { (yyval.intlistp) = EMPTYLIST; }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 95 "parser.y"
    { rparen("domain"); }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 95 "parser.y"
    { rparen("domain body"); }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 95 "parser.y"
    { storedomain((yyvsp[(5) - (10)].i)); }
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 99 "parser.y"
    { }
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 102 "parser.y"
    { rparen(":predicates"); }
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 102 "parser.y"
    { storepredicates(); }
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 103 "parser.y"
    { rparen(":requirements"); }
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 103 "parser.y"
    { checkrequirements((yyvsp[(3) - (5)].intlistp)); }
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 104 "parser.y"
    { rparen(":constants"); }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 104 "parser.y"
    { storeconstants((yyvsp[(3) - (5)].typedvarlistp)); }
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 105 "parser.y"
    { rparen(":functions"); }
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 105 "parser.y"
    { }
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 106 "parser.y"
    { rparen(":types"); }
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 106 "parser.y"
    { storetypes((yyvsp[(3) - (5)].typedvarlistp)); }
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 107 "parser.y"
    { COST = 0; }
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 107 "parser.y"
    { rparen(":action"); }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 107 "parser.y"
    { addactioncost(COST); addnewaction((yyvsp[(4) - (7)].i)); }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 114 "parser.y"
    { rparen(":action definitions"); }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 114 "parser.y"
    { addactionparameters((yyvsp[(3) - (5)].typedvarlistp)); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 115 "parser.y"
    { addactionprecond((yyvsp[(2) - (2)].Sfmap)); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 116 "parser.y"
    { addactioneffect((yyvsp[(2) - (2)].Seffp)); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 119 "parser.y"
    { (yyval.typedvarlistp) = withtype(UNIVTYPE,(yyvsp[(1) - (1)].intlistp)); }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 120 "parser.y"
    { (yyval.typedvarlistp) = (yyvsp[(1) - (1)].typedvarlistp); }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 121 "parser.y"
    { (yyval.typedvarlistp) = EMPTYLIST; }
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 124 "parser.y"
    { (yyval.intlistp) = intcons((yyvsp[(1) - (2)].i),(yyvsp[(2) - (2)].intlistp)); }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 125 "parser.y"
    { (yyval.intlistp) = intcons((yyvsp[(1) - (1)].i), EMPTYLIST); }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 128 "parser.y"
    { (yyval.typedvarlistp) = TVappend((yyvsp[(1) - (2)].typedvarlistp),(yyvsp[(2) - (2)].typedvarlistp)); }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 129 "parser.y"
    { (yyval.typedvarlistp) = (yyvsp[(1) - (1)].typedvarlistp); }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 132 "parser.y"
    { (yyval.typedvarlistp) = withtype((yyvsp[(3) - (3)].i),(yyvsp[(1) - (3)].intlistp)); }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 136 "parser.y"
    { rparen(":problem"); }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 136 "parser.y"
    { rparen("problem definition"); }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 136 "parser.y"
    { addproblem((yyvsp[(5) - (10)].i)); }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 139 "parser.y"
    { rparen("problem definitions"); }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 139 "parser.y"
    { }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 140 "parser.y"
    { rparen("problem definitions"); }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 140 "parser.y"
    { }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 143 "parser.y"
    { checkdomain((yyvsp[(2) - (2)].i)); }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 144 "parser.y"
    { storeobjects((yyvsp[(2) - (2)].typedvarlistp)); }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 145 "parser.y"
    { storeinit((yyvsp[(2) - (2)].atomlistp));getInitState((yyvsp[(2) - (2)].atomlistp));}
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 146 "parser.y"
    { storegoal((yyvsp[(2) - (2)].Sfmap)); }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 147 "parser.y"
    { }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 152 "parser.y"
    {(yyval.atomlistp) = (yyvsp[(1) - (1)].atomlistp);}
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 153 "parser.y"
    {(yyval.atomlistp) = (yyvsp[(1) - (1)].atomlistp);}
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 157 "parser.y"
    {(yyval.atomlistp) = (yyvsp[(1) - (1)].atomlistp);}
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 158 "parser.y"
    {(yyval.atomlistp) = (yyvsp[(1) - (1)].atomlistp);}
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 162 "parser.y"
    {(yyval.atomlistp) = atomlist_combine((yyvsp[(3) - (3)].atomlistp),(yyvsp[(1) - (3)].atomlistp));}
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 163 "parser.y"
    {(yyval.atomlistp) = atomlist_combine((yyvsp[(3) - (3)].atomlistp),(yyvsp[(1) - (3)].atomlistp));}
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 164 "parser.y"
    {(yyval.atomlistp) = atomlist_combine((yyvsp[(3) - (3)].atomlistp),(yyvsp[(1) - (3)].atomlistp));}
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 165 "parser.y"
    {(yyval.atomlistp) = atomlist_combine((yyvsp[(3) - (3)].atomlistp),(yyvsp[(1) - (3)].atomlistp));}
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 176 "parser.y"
    {(yyval.atomlistp) = atomlist_combine((yyvsp[(3) - (3)].atomlistp),(yyvsp[(1) - (3)].atomlistp));}
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 177 "parser.y"
    {(yyval.atomlistp) = atomlist_combine((yyvsp[(3) - (3)].atomlistp),(yyvsp[(1) - (3)].atomlistp));}
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 178 "parser.y"
    {(yyval.atomlistp) = atomlist_combine((yyvsp[(3) - (3)].atomlistp),(yyvsp[(1) - (3)].atomlistp));}
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 179 "parser.y"
    {(yyval.atomlistp) = atomlist_combine((yyvsp[(3) - (3)].atomlistp),(yyvsp[(1) - (3)].atomlistp));}
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 185 "parser.y"
    { (yyval.typedvarlistp) = TVappend(withtype((yyvsp[(3) - (4)].i),(yyvsp[(1) - (4)].intlistp)),(yyvsp[(4) - (4)].typedvarlistp)); }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 186 "parser.y"
    { (yyval.typedvarlistp) = withtype(UNIVTYPE,(yyvsp[(1) - (1)].intlistp)); }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 189 "parser.y"
    { }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 190 "parser.y"
    { rparen("typed variable list"); }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 190 "parser.y"
    { }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 191 "parser.y"
    { }
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 192 "parser.y"
    { }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 195 "parser.y"
    { rparen("typed atom list"); }
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 195 "parser.y"
    { }
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 196 "parser.y"
    { }
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 199 "parser.y"
    { }
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 200 "parser.y"
    { }
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 203 "parser.y"
    { }
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 204 "parser.y"
    { }
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 207 "parser.y"
    { rparen("function list"); }
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 212 "parser.y"
    { rparen("empty conjunction"); }
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 212 "parser.y"
    { (yyval.Sfmap) = Strue(); }
    break;

  case 96:
/* Line 1787 of yacc.c  */
#line 213 "parser.y"
    { rparen("conjunction"); }
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 213 "parser.y"
    { (yyval.Sfmap) = Sconjunction((yyvsp[(3) - (5)].Sfmalistp)); }
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 214 "parser.y"
    { rparen("when"); }
    break;

  case 99:
/* Line 1787 of yacc.c  */
#line 214 "parser.y"
    { (yyval.Sfmap) = Sconjunction(Sfmacons(Sneg((yyvsp[(3) - (6)].Sfmap)),Sfmacons((yyvsp[(4) - (6)].Sfmap),EMPTYLIST))); }
    break;

  case 100:
/* Line 1787 of yacc.c  */
#line 215 "parser.y"
    { rparen("disjunction"); }
    break;

  case 101:
/* Line 1787 of yacc.c  */
#line 215 "parser.y"
    { (yyval.Sfmap) = Sdisjunction((yyvsp[(3) - (5)].Sfmalistp)); }
    break;

  case 102:
/* Line 1787 of yacc.c  */
#line 216 "parser.y"
    { rparen("imply"); }
    break;

  case 103:
/* Line 1787 of yacc.c  */
#line 216 "parser.y"
    { (yyval.Sfmap) = Sdisjunction(Sfmacons(Sneg((yyvsp[(3) - (6)].Sfmap)),Sfmacons((yyvsp[(4) - (6)].Sfmap),EMPTYLIST))); }
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 217 "parser.y"
    { rparen("not"); }
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 217 "parser.y"
    { (yyval.Sfmap) = Sneg((yyvsp[(3) - (5)].Sfmap)); }
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 218 "parser.y"
    { (yyval.Sfmap) = Satom((yyvsp[(1) - (1)].atomp)); }
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 219 "parser.y"
    { rparen("equality"); }
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 219 "parser.y"
    { (yyval.Sfmap) = SfmaEQ((yyvsp[(3) - (6)].i),(yyvsp[(4) - (6)].i)); }
    break;

  case 109:
/* Line 1787 of yacc.c  */
#line 220 "parser.y"
    { rparen("forall"); }
    break;

  case 110:
/* Line 1787 of yacc.c  */
#line 220 "parser.y"
    { (yyval.Sfmap) = Sfmaforall((yyvsp[(4) - (8)].typedvarlistp),(yyvsp[(6) - (8)].Sfmap)); }
    break;

  case 111:
/* Line 1787 of yacc.c  */
#line 221 "parser.y"
    { rparen("exists"); }
    break;

  case 112:
/* Line 1787 of yacc.c  */
#line 221 "parser.y"
    { (yyval.Sfmap) = Sfmaforsome((yyvsp[(4) - (8)].typedvarlistp),(yyvsp[(6) - (8)].Sfmap)); }
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 224 "parser.y"
    { (yyval.Sfmalistp) = Sfmacons((yyvsp[(2) - (2)].Sfmap),(yyvsp[(1) - (2)].Sfmalistp)); }
    break;

  case 114:
/* Line 1787 of yacc.c  */
#line 225 "parser.y"
    { (yyval.Sfmalistp) = Sfmacons((yyvsp[(1) - (1)].Sfmap),EMPTYLIST); }
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 228 "parser.y"
    { (yyval.Sefflistp) = Seffcons((yyvsp[(2) - (2)].Seffp),(yyvsp[(1) - (2)].Sefflistp)); }
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 229 "parser.y"
    { (yyval.Sefflistp) = Seffcons((yyvsp[(1) - (1)].Seffp),EMPTYLIST); }
    break;

  case 117:
/* Line 1787 of yacc.c  */
#line 232 "parser.y"
    { (yyval.i) = 0; }
    break;

  case 118:
/* Line 1787 of yacc.c  */
#line 233 "parser.y"
    { (yyval.i) = (yyvsp[(1) - (1)].i); }
    break;

  case 119:
/* Line 1787 of yacc.c  */
#line 236 "parser.y"
    { rparen("empty conjunction"); }
    break;

  case 120:
/* Line 1787 of yacc.c  */
#line 236 "parser.y"
    { (yyval.Seffp) = Seffconjunction(EMPTYLIST); }
    break;

  case 121:
/* Line 1787 of yacc.c  */
#line 237 "parser.y"
    { rparen("compound effect"); }
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 237 "parser.y"
    { (yyval.Seffp) = Seffconjunction((yyvsp[(3) - (5)].Sefflistp)); }
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 238 "parser.y"
    { rparen("when"); }
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 238 "parser.y"
    { (yyval.Seffp) = Seffwhen((yyvsp[(3) - (6)].Sfmap),(yyvsp[(4) - (6)].Seffp)); }
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 239 "parser.y"
    { rparen("forall"); }
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 239 "parser.y"
    { (yyval.Seffp) = Seffforall((yyvsp[(4) - (8)].typedvarlistp),(yyvsp[(6) - (8)].Seffp)); }
    break;

  case 127:
/* Line 1787 of yacc.c  */
#line 240 "parser.y"
    { (yyval.Seffp) = SPeffatom((yyvsp[(1) - (1)].atomp)); }
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 241 "parser.y"
    { rparen("not"); }
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 241 "parser.y"
    { (yyval.Seffp) = SNeffatom((yyvsp[(3) - (5)].atomp)); }
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 242 "parser.y"
    { rparen("increase"); }
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 242 "parser.y"
    { (yyval.Seffp) = Seffconjunction(NULL); COST = (yyvsp[(4) - (6)].i); }
    break;


/* Line 1787 of yacc.c  */
#line 2346 "parser.tab.c"
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2050 of yacc.c  */
#line 245 "parser.y"


void parseerror(char *s) {
  errorstring = s;
}

void rparen(char *s) {
  errorstring = s;
}
