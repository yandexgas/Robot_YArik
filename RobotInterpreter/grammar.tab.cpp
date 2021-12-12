
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "grammar.y"

	#include "Nodes.h"
	using namespace language;
	std::shared_ptr<Statement_list>* root;
	int yylex(void);
	void yyerror (const char*);


/* Line 189 of yacc.c  */
#line 82 "grammar.tab.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTNUM = 258,
     FLOATNUM = 259,
     ISTINO = 260,
     TSELOYE = 261,
     DROBNOYE = 262,
     LOGICHESKOYE = 263,
     YACHEYKA = 264,
     MASSIV = 265,
     PTR = 266,
     name = 267,
     FOR = 268,
     WHILE = 269,
     IF = 270,
     IFX = 271,
     ELSE = 272,
     BEGIN_ = 273,
     END = 274,
     RAZMER = 275,
     PROVERKA = 276,
     OR = 277,
     AND = 278,
     IDI = 279,
     POVERNI = 280,
     VZLETI = 281,
     OSTANOV = 282,
     GDEYA = 283,
     SMOTRI = 284,
     ARROW = 285,
     PERED = 286,
     ZAD = 287,
     PRAVO = 288,
     LEVO = 289,
     FUNC = 290,
     VCLUCHIT = 291,
     FILEPATH = 292,
     PECHAT = 293,
     CHITAT = 294,
     UMINUS = 295,
     ADR = 296,
     STAR = 297,
     FIELD_OPER = 298
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 9 "grammar.y"


std::shared_ptr<language::Node>* Node_;
std::shared_ptr<language::Statement_list>* Prog_;
float fval;
int ival;
bool bval;
language::Types types_;
std::string* string;
language::Sides sides;
std::vector<int>* dimensions;
language::Square* square;
std::list<std::shared_ptr<language::Node>>* operands_;
std::list<language::fparam>* params_;
language::fparam* fparam_;



/* Line 214 of yacc.c  */
#line 180 "grammar.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 192 "grammar.tab.cpp"

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
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1111

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNRULES -- Number of states.  */
#define YYNSTATES  200

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      53,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      56,    58,    44,    42,    59,    43,     2,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    57,    54,
      40,    55,    41,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    60,     2,    61,    46,     2,     2,     2,
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
      35,    36,    37,    38,    39,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    12,    16,    17,    19,    22,
      25,    30,    38,    48,    56,    62,    68,    76,    82,    84,
      88,    91,    93,    97,   101,   103,   105,   107,   109,   111,
     119,   128,   135,   138,   142,   144,   148,   150,   154,   165,
     172,   177,   182,   185,   189,   191,   194,   196,   198,   200,
     202,   205,   209,   213,   217,   221,   224,   227,   231,   235,
     239,   243,   246,   248,   250,   254,   258,   263,   268,   270,
     273,   276,   280,   284,   289,   293,   298,   302,   308,   310,
     312,   314,   316,   318,   320,   322,   324,   326,   329,   333,
     335
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      63,     0,    -1,    53,    -1,    63,    64,    -1,    63,    64,
      53,    -1,    63,     1,    53,    -1,    -1,    54,    -1,    74,
      54,    -1,    71,    54,    -1,    74,    55,    74,    54,    -1,
      13,    56,    71,    57,    74,    58,    64,    -1,    13,    56,
      74,    55,    74,    57,    74,    58,    64,    -1,    13,    56,
      74,    57,    74,    58,    64,    -1,    14,    56,    74,    58,
      64,    -1,    15,    56,    74,    58,    64,    -1,    15,    56,
      74,    58,    64,    17,    64,    -1,    38,    56,    74,    58,
      54,    -1,    68,    -1,    18,    73,    19,    -1,    18,    19,
      -1,    66,    -1,    65,    30,    66,    -1,    67,    30,    77,
      -1,    27,    -1,    24,    -1,    29,    -1,    26,    -1,    25,
      -1,    76,    35,    12,    69,    18,    73,    19,    -1,    11,
      76,    35,    12,    69,    18,    73,    19,    -1,    35,    12,
      69,    18,    73,    19,    -1,    56,    58,    -1,    56,    70,
      58,    -1,    72,    -1,    70,    59,    72,    -1,    72,    -1,
      72,    55,    74,    -1,     9,    12,    55,    60,    74,    59,
      74,    59,    74,    61,    -1,    10,    12,    55,    60,    79,
      61,    -1,    10,    12,    55,    74,    -1,     9,    12,    55,
      74,    -1,    76,    12,    -1,    11,    76,    12,    -1,    64,
      -1,    73,    64,    -1,     3,    -1,     4,    -1,     5,    -1,
      12,    -1,    12,    78,    -1,    74,    42,    74,    -1,    74,
      43,    74,    -1,    74,    44,    74,    -1,    74,    45,    74,
      -1,    43,    74,    -1,    46,    74,    -1,    74,    22,    74,
      -1,    74,    23,    74,    -1,    56,    74,    58,    -1,    74,
      50,    12,    -1,    20,    74,    -1,    75,    -1,    65,    -1,
      74,    41,    74,    -1,    74,    40,    74,    -1,    74,    51,
      79,    52,    -1,    39,    56,    74,    58,    -1,    28,    -1,
      44,    74,    -1,    48,    74,    -1,    21,    12,    12,    -1,
      21,    74,    76,    -1,    21,    74,    11,    76,    -1,    21,
      76,    74,    -1,    21,    11,    76,    74,    -1,    21,    76,
      76,    -1,    21,    11,    76,    11,    76,    -1,     6,    -1,
       7,    -1,     8,    -1,     9,    -1,    10,    -1,    34,    -1,
      33,    -1,    31,    -1,    32,    -1,    56,    58,    -1,    56,
      79,    58,    -1,    74,    -1,    79,    59,    74,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    71,    71,    72,    75,    78,    79,    86,    88,    89,
      90,    94,    98,   105,   109,   113,   117,   120,   121,   122,
     127,   132,   133,   137,   138,   142,   143,   144,   145,   148,
     152,   156,   162,   163,   167,   171,   177,   181,   185,   190,
     195,   199,   206,   210,   217,   220,   226,   229,   232,   235,
     239,   243,   247,   251,   255,   259,   263,   267,   271,   275,
     277,   281,   285,   287,   289,   293,   297,   301,   303,   305,
     309,   315,   322,   327,   328,   333,   334,   338,   343,   344,
     345,   346,   347,   352,   353,   354,   355,   360,   361,   365,
     368
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTNUM", "FLOATNUM", "ISTINO",
  "TSELOYE", "DROBNOYE", "LOGICHESKOYE", "YACHEYKA", "MASSIV", "PTR",
  "name", "FOR", "WHILE", "IF", "IFX", "ELSE", "BEGIN_", "END", "RAZMER",
  "PROVERKA", "OR", "AND", "IDI", "POVERNI", "VZLETI", "OSTANOV", "GDEYA",
  "SMOTRI", "ARROW", "PERED", "ZAD", "PRAVO", "LEVO", "FUNC", "VCLUCHIT",
  "FILEPATH", "PECHAT", "CHITAT", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "'~'", "UMINUS", "ADR", "STAR", "FIELD_OPER", "'['", "']'", "'\\n'",
  "';'", "'='", "'('", "':'", "')'", "','", "'{'", "'}'", "$accept",
  "program", "stmt", "robot_oper", "robot_command", "command_word",
  "fdecl", "arglst", "args", "decl", "arg", "stmt_lst", "expr", "check",
  "type", "side", "operands", "oper_list", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      60,    62,    43,    45,    42,    47,   126,   295,   296,   297,
     298,    91,    93,    10,    59,    61,    40,    58,    41,    44,
     123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    63,    63,    63,    63,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    65,    65,    66,    66,    67,    67,    67,    67,    68,
      68,    68,    69,    69,    70,    70,    71,    71,    71,    71,
      71,    71,    72,    72,    73,    73,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    75,    75,    75,    75,    75,    75,    75,    76,    76,
      76,    76,    76,    77,    77,    77,    77,    78,    78,    79,
      79
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     3,     3,     0,     1,     2,     2,
       4,     7,     9,     7,     5,     5,     7,     5,     1,     3,
       2,     1,     3,     3,     1,     1,     1,     1,     1,     7,
       8,     6,     2,     3,     1,     3,     1,     3,    10,     6,
       4,     4,     2,     3,     1,     2,     1,     1,     1,     1,
       2,     3,     3,     3,     3,     2,     2,     3,     3,     3,
       3,     2,     1,     1,     3,     3,     4,     4,     1,     2,
       2,     3,     3,     4,     3,     4,     3,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     1,
       3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     2,     0,     1,     0,    46,    47,    48,    78,    79,
      80,    81,    82,     0,    49,     0,     0,     0,     0,     0,
       0,    25,    28,    27,    24,    68,    26,     0,     0,     0,
       0,     0,     0,     0,     7,     0,     3,    63,    21,     0,
      18,     0,    36,     0,    62,     0,     5,     0,     0,    81,
      82,     0,     0,    50,     0,     0,     0,    20,    44,     0,
      61,     0,    49,     0,     0,     0,     0,     0,    55,    69,
      56,    70,     0,     4,     0,     0,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,     0,
      42,     0,     0,     0,    43,     0,    87,    89,     0,     0,
       0,     0,     0,     0,     0,    19,    45,     0,    71,     0,
      72,    74,    76,     0,     0,     0,     0,    59,    22,    85,
      86,    84,    83,    23,    37,    57,    58,    65,    64,    51,
      52,    53,    54,    60,     0,     0,     0,     0,    41,     0,
      40,     0,    88,     0,     0,     0,     0,     0,     0,     0,
       0,    75,    73,    32,     0,    34,     0,     0,    67,    66,
      10,     0,     0,     0,     0,    90,     0,     0,     0,    14,
      15,    77,    33,     0,     0,    17,     0,     0,    39,     0,
       0,     0,     0,     0,    35,    31,     0,     0,     0,    11,
       0,    13,    16,    29,     0,    30,     0,     0,    12,    38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    58,    37,    38,    39,    40,   114,   154,    41,
      42,    59,    43,    44,    45,   123,    53,    98
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -152
static const yytype_int16 yypact[] =
{
     -23,  -152,   242,  -152,    -6,  -152,  -152,  -152,  -152,  -152,
    -152,    23,    38,    34,     0,    28,    29,    32,   335,   846,
     659,  -152,  -152,  -152,  -152,  -152,  -152,    41,    43,    55,
     846,   846,   846,   846,  -152,   846,    50,    82,  -152,    86,
    -152,    63,    65,  1044,  -152,    -3,  -152,    68,    69,  -152,
    -152,     4,   279,  -152,   713,   846,   846,  -152,  -152,   389,
     -24,    34,    -5,   873,   767,    62,   846,   846,   -24,   -24,
     -24,   -24,   704,  -152,   166,   111,  -152,   846,   846,   846,
     846,   846,   846,   846,   846,   846,   114,   846,  -152,   846,
    -152,   120,   110,   184,  -152,   121,  -152,  1060,    14,    34,
      83,   995,   136,   885,   897,  -152,  -152,   813,  -152,    34,
    -152,  1060,  -152,    12,   132,   909,   934,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,  1060,   803,    36,    51,    51,    47,
      47,   -24,   -24,  -152,   -49,   758,    62,   846,  1060,   846,
    1060,    62,  -152,   846,   139,   846,   846,   846,   605,   605,
      34,  1060,  -152,  -152,    24,  -152,   605,    98,  -152,  -152,
    -152,   137,   270,   -28,   142,  1060,   946,  1020,   958,  -152,
     140,  -152,  -152,    99,   443,  -152,   605,   846,  -152,   605,
     605,   846,   605,   605,  -152,  -152,   497,   650,   551,  -152,
     983,  -152,  -152,  -152,   846,  -152,   605,   175,  -152,  -152
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -152,  -152,    -2,  -152,    87,  -152,  -152,  -112,  -152,   108,
    -105,  -151,   -18,  -152,    -9,  -152,  -152,   -81
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      36,    60,    63,   159,    51,   174,   134,   108,   155,    90,
     143,    64,    68,    69,    70,    71,    94,    72,     8,     9,
      10,    49,    50,    99,   161,   186,    86,    87,   188,   164,
       1,   143,    91,   178,    97,    47,   101,   103,   104,    95,
       8,     9,    10,    49,    50,   102,   111,    46,   115,   116,
      48,    52,   107,    65,   110,   112,    52,   106,   163,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   184,    97,
     153,   135,   142,   143,   138,   140,    80,    81,    82,    83,
      84,    85,   172,   173,    54,    55,    86,    87,    56,   151,
     144,    84,    85,    82,    83,    84,    85,    86,    87,    66,
     152,    86,    87,    73,   102,     8,     9,    10,    49,    50,
      99,    67,    74,     5,     6,     7,    75,    76,   113,   162,
      77,    97,    14,    92,    93,   165,   133,   166,   167,   168,
      19,    20,   136,   141,    21,    22,    23,    24,    25,    26,
     145,   171,   119,   120,   121,   122,   169,   170,    90,    29,
     156,    94,   175,    30,    31,   176,    32,   183,    33,   187,
     179,   118,   100,   190,   102,     0,    35,     0,     0,     0,
     137,     0,   106,     0,     0,     0,   197,     0,   189,     0,
     191,   192,     0,     0,   106,     0,   106,     5,     6,     7,
      21,    22,    23,    24,   198,    26,    14,    78,    79,     0,
       0,     0,     0,     0,    19,    20,     0,     0,    21,    22,
      23,    24,    25,    26,     0,    80,    81,    82,    83,    84,
      85,     0,     0,    29,     0,    86,    87,    30,    31,     0,
      32,     0,    33,     0,     0,     0,   199,     0,     0,     0,
      35,     0,     3,     4,   139,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,     0,     0,
      18,     0,    19,    20,     0,     0,    21,    22,    23,    24,
      25,    26,     0,     0,     0,     0,     0,    27,     0,     0,
      28,    29,     5,     6,     7,    30,    31,     0,    32,     0,
      33,    14,    78,    79,     0,     0,    34,     0,    35,    19,
      20,     0,     0,    21,    22,    23,    24,    25,    26,     0,
      80,    81,    82,    83,    84,    85,     0,     0,    29,     0,
      86,    87,    30,    31,     0,    32,     0,    33,     0,   177,
       0,     0,     0,     0,     0,    35,     0,    96,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,     0,     0,    18,    57,    19,    20,     0,     0,    21,
      22,    23,    24,    25,    26,     0,     0,     0,     0,     0,
      27,     0,     0,    28,    29,     0,     0,     0,    30,    31,
       0,    32,     0,    33,     0,     0,     0,     0,     0,    34,
       0,    35,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,     0,     0,    18,   105,    19,
      20,     0,     0,    21,    22,    23,    24,    25,    26,     0,
       0,     0,     0,     0,    27,     0,     0,    28,    29,     0,
       0,     0,    30,    31,     0,    32,     0,    33,     0,     0,
       0,     0,     0,    34,     0,    35,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,     0,
       0,    18,   185,    19,    20,     0,     0,    21,    22,    23,
      24,    25,    26,     0,     0,     0,     0,     0,    27,     0,
       0,    28,    29,     0,     0,     0,    30,    31,     0,    32,
       0,    33,     0,     0,     0,     0,     0,    34,     0,    35,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,     0,     0,    18,   193,    19,    20,     0,
       0,    21,    22,    23,    24,    25,    26,     0,     0,     0,
       0,     0,    27,     0,     0,    28,    29,     0,     0,     0,
      30,    31,     0,    32,     0,    33,     0,     0,     0,     0,
       0,    34,     0,    35,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,     0,     0,    18,
     195,    19,    20,     0,     0,    21,    22,    23,    24,    25,
      26,     0,     0,     0,     0,     0,    27,     0,     0,    28,
      29,     0,     0,     0,    30,    31,     0,    32,     0,    33,
       0,     0,     0,     0,     0,    34,     0,    35,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,     0,     0,    18,     0,    19,    20,     0,     0,    21,
      22,    23,    24,    25,    26,     0,     0,     0,     0,     0,
      27,     0,     0,    28,    29,     0,     0,     0,    30,    31,
       0,    32,     0,    33,     0,     0,     0,     0,     0,    34,
       0,    35,     5,     6,     7,     8,     9,    10,    49,    50,
      61,    62,    78,    79,     0,     0,     0,     0,     0,    19,
      20,     0,     0,    21,    22,    23,    24,    25,    26,     0,
      80,    81,    82,    83,    84,    85,     0,     0,    29,     0,
      86,    87,    30,    31,     0,    32,     0,    33,     0,   194,
       0,     0,     0,     0,     0,    35,     5,     6,     7,     8,
       9,    10,    11,    12,    99,    14,    78,    79,     0,     0,
       0,     0,     0,    19,    20,     0,     0,    21,    22,    23,
      24,    25,    26,     0,    80,    81,    82,    83,    84,    85,
       0,     0,    29,     0,    86,    87,    30,    31,     0,    32,
       0,    33,   117,     0,     0,     0,     0,     0,     0,    35,
       5,     6,     7,     8,     9,    10,    49,    50,     0,    14,
      78,    79,     0,     0,     0,     0,     0,    19,    20,     0,
       0,    21,    22,    23,    24,    25,    26,     0,    80,    81,
      82,    83,    84,    85,     0,     0,    29,     0,    86,    87,
      30,    31,   160,    32,     0,    33,     5,     6,     7,     0,
       0,     0,     0,    35,   150,    14,    79,     0,     0,     0,
       0,     0,     0,    19,    20,     0,     0,    21,    22,    23,
      24,    25,    26,    80,    81,    82,    83,    84,    85,     5,
       6,     7,    29,    86,    87,     0,    30,    31,    14,    32,
       0,    33,     0,     0,     0,     0,    19,    20,     0,    35,
      21,    22,    23,    24,    25,    26,     0,     0,     0,     8,
       9,    10,    49,    50,   109,    29,     0,     0,     0,    30,
      31,     0,    32,     0,    33,    78,    79,     0,     0,     0,
       0,     0,    35,     0,     0,     0,     0,    78,    79,     0,
       0,     0,     0,    80,    81,    82,    83,    84,    85,    78,
      79,     0,     0,    86,    87,    80,    81,    82,    83,    84,
      85,    78,    79,     0,     0,    86,    87,    80,    81,    82,
      83,    84,    85,   148,     0,     0,     0,    86,    87,    80,
      81,    82,    83,    84,    85,   149,    78,    79,     0,    86,
      87,     0,     0,     0,     0,     0,     0,   157,    78,    79,
       0,     0,     0,     0,    80,    81,    82,    83,    84,    85,
      78,    79,     0,     0,    86,    87,    80,    81,    82,    83,
      84,    85,   158,     0,     0,     0,    86,    87,    80,    81,
      82,    83,    84,    85,   180,    78,    79,     0,    86,    87,
       0,     0,     0,     0,     0,     0,   182,    78,    79,     0,
       0,     0,     0,    80,    81,    82,    83,    84,    85,     0,
       0,     0,     0,    86,    87,    80,    81,    82,    83,    84,
      85,   196,    78,    79,     0,    86,    87,     0,     0,     0,
     146,     0,   147,     0,     0,     0,     0,     0,     0,     0,
      80,    81,    82,    83,    84,    85,    78,    79,     0,     0,
      86,    87,     0,     0,     0,     0,     0,   181,     0,     0,
       0,     0,    78,    79,    80,    81,    82,    83,    84,    85,
       0,     0,     0,     0,    86,    87,     0,     0,    88,    89,
      80,    81,    82,    83,    84,    85,     0,     0,     0,     0,
      86,    87
};

static const yytype_int16 yycheck[] =
{
       2,    19,    20,    52,    13,   156,    87,    12,   113,    12,
      59,    20,    30,    31,    32,    33,    12,    35,     6,     7,
       8,     9,    10,    11,   136,   176,    50,    51,   179,   141,
      53,    59,    35,    61,    52,    12,    54,    55,    56,    35,
       6,     7,     8,     9,    10,    54,    64,    53,    66,    67,
      12,    56,    61,    12,    63,    64,    56,    59,   139,    77,
      78,    79,    80,    81,    82,    83,    84,    85,   173,    87,
      58,    89,    58,    59,    92,    93,    40,    41,    42,    43,
      44,    45,    58,    59,    56,    56,    50,    51,    56,   107,
      99,    44,    45,    42,    43,    44,    45,    50,    51,    56,
     109,    50,    51,    53,   113,     6,     7,     8,     9,    10,
      11,    56,    30,     3,     4,     5,    30,    54,    56,   137,
      55,   139,    12,    55,    55,   143,    12,   145,   146,   147,
      20,    21,    12,    12,    24,    25,    26,    27,    28,    29,
      57,   150,    31,    32,    33,    34,   148,   149,    12,    39,
      18,    12,    54,    43,    44,    18,    46,    17,    48,   177,
      18,    74,    54,   181,   173,    -1,    56,    -1,    -1,    -1,
      60,    -1,   174,    -1,    -1,    -1,   194,    -1,   180,    -1,
     182,   183,    -1,    -1,   186,    -1,   188,     3,     4,     5,
      24,    25,    26,    27,   196,    29,    12,    22,    23,    -1,
      -1,    -1,    -1,    -1,    20,    21,    -1,    -1,    24,    25,
      26,    27,    28,    29,    -1,    40,    41,    42,    43,    44,
      45,    -1,    -1,    39,    -1,    50,    51,    43,    44,    -1,
      46,    -1,    48,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      56,    -1,     0,     1,    60,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    -1,
      18,    -1,    20,    21,    -1,    -1,    24,    25,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      38,    39,     3,     4,     5,    43,    44,    -1,    46,    -1,
      48,    12,    22,    23,    -1,    -1,    54,    -1,    56,    20,
      21,    -1,    -1,    24,    25,    26,    27,    28,    29,    -1,
      40,    41,    42,    43,    44,    45,    -1,    -1,    39,    -1,
      50,    51,    43,    44,    -1,    46,    -1,    48,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    58,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    -1,    18,    19,    20,    21,    -1,    -1,    24,
      25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      35,    -1,    -1,    38,    39,    -1,    -1,    -1,    43,    44,
      -1,    46,    -1,    48,    -1,    -1,    -1,    -1,    -1,    54,
      -1,    56,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    18,    19,    20,
      21,    -1,    -1,    24,    25,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    38,    39,    -1,
      -1,    -1,    43,    44,    -1,    46,    -1,    48,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    56,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      -1,    18,    19,    20,    21,    -1,    -1,    24,    25,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      -1,    38,    39,    -1,    -1,    -1,    43,    44,    -1,    46,
      -1,    48,    -1,    -1,    -1,    -1,    -1,    54,    -1,    56,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    -1,    18,    19,    20,    21,    -1,
      -1,    24,    25,    26,    27,    28,    29,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    38,    39,    -1,    -1,    -1,
      43,    44,    -1,    46,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    56,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    18,
      19,    20,    21,    -1,    -1,    24,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    38,
      39,    -1,    -1,    -1,    43,    44,    -1,    46,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    56,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    -1,    18,    -1,    20,    21,    -1,    -1,    24,
      25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      35,    -1,    -1,    38,    39,    -1,    -1,    -1,    43,    44,
      -1,    46,    -1,    48,    -1,    -1,    -1,    -1,    -1,    54,
      -1,    56,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    22,    23,    -1,    -1,    -1,    -1,    -1,    20,
      21,    -1,    -1,    24,    25,    26,    27,    28,    29,    -1,
      40,    41,    42,    43,    44,    45,    -1,    -1,    39,    -1,
      50,    51,    43,    44,    -1,    46,    -1,    48,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    56,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    22,    23,    -1,    -1,
      -1,    -1,    -1,    20,    21,    -1,    -1,    24,    25,    26,
      27,    28,    29,    -1,    40,    41,    42,    43,    44,    45,
      -1,    -1,    39,    -1,    50,    51,    43,    44,    -1,    46,
      -1,    48,    58,    -1,    -1,    -1,    -1,    -1,    -1,    56,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      22,    23,    -1,    -1,    -1,    -1,    -1,    20,    21,    -1,
      -1,    24,    25,    26,    27,    28,    29,    -1,    40,    41,
      42,    43,    44,    45,    -1,    -1,    39,    -1,    50,    51,
      43,    44,    54,    46,    -1,    48,     3,     4,     5,    -1,
      -1,    -1,    -1,    56,    11,    12,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    -1,    -1,    24,    25,    26,
      27,    28,    29,    40,    41,    42,    43,    44,    45,     3,
       4,     5,    39,    50,    51,    -1,    43,    44,    12,    46,
      -1,    48,    -1,    -1,    -1,    -1,    20,    21,    -1,    56,
      24,    25,    26,    27,    28,    29,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    39,    -1,    -1,    -1,    43,
      44,    -1,    46,    -1,    48,    22,    23,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    22,    23,    -1,
      -1,    -1,    -1,    40,    41,    42,    43,    44,    45,    22,
      23,    -1,    -1,    50,    51,    40,    41,    42,    43,    44,
      45,    22,    23,    -1,    -1,    50,    51,    40,    41,    42,
      43,    44,    45,    58,    -1,    -1,    -1,    50,    51,    40,
      41,    42,    43,    44,    45,    58,    22,    23,    -1,    50,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    58,    22,    23,
      -1,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      22,    23,    -1,    -1,    50,    51,    40,    41,    42,    43,
      44,    45,    58,    -1,    -1,    -1,    50,    51,    40,    41,
      42,    43,    44,    45,    58,    22,    23,    -1,    50,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    22,    23,    -1,
      -1,    -1,    -1,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    50,    51,    40,    41,    42,    43,    44,
      45,    58,    22,    23,    -1,    50,    51,    -1,    -1,    -1,
      55,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    45,    22,    23,    -1,    -1,
      50,    51,    -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,
      -1,    -1,    22,    23,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,    55,
      40,    41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,
      50,    51
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    53,    63,     0,     1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    18,    20,
      21,    24,    25,    26,    27,    28,    29,    35,    38,    39,
      43,    44,    46,    48,    54,    56,    64,    65,    66,    67,
      68,    71,    72,    74,    75,    76,    53,    12,    12,     9,
      10,    76,    56,    78,    56,    56,    56,    19,    64,    73,
      74,    11,    12,    74,    76,    12,    56,    56,    74,    74,
      74,    74,    74,    53,    30,    30,    54,    55,    22,    23,
      40,    41,    42,    43,    44,    45,    50,    51,    54,    55,
      12,    35,    55,    55,    12,    35,    58,    74,    79,    11,
      71,    74,    76,    74,    74,    19,    64,    76,    12,    11,
      76,    74,    76,    56,    69,    74,    74,    58,    66,    31,
      32,    33,    34,    77,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    12,    79,    74,    12,    60,    74,    60,
      74,    12,    58,    59,    76,    57,    55,    57,    58,    58,
      11,    74,    76,    58,    70,    72,    18,    58,    58,    52,
      54,    69,    74,    79,    69,    74,    74,    74,    74,    64,
      64,    76,    58,    59,    73,    54,    18,    59,    61,    18,
      58,    57,    58,    17,    72,    19,    73,    74,    73,    64,
      74,    64,    64,    19,    59,    19,    58,    74,    64,    61
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
        case 2:

/* Line 1455 of yacc.c  */
#line 71 "grammar.y"
    {;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 72 "grammar.y"
    {(**(yyvsp[(1) - (2)].Prog_)).addStatement(*(yyvsp[(2) - (2)].Node_));
			(yyval.Prog_)=(yyvsp[(1) - (2)].Prog_); delete (yyvsp[(2) - (2)].Node_);
			root =(yyval.Prog_);;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 75 "grammar.y"
    {(**(yyvsp[(1) - (3)].Prog_)).addStatement(*(yyvsp[(2) - (3)].Node_));
				(yyval.Prog_)=(yyvsp[(1) - (3)].Prog_); delete (yyvsp[(2) - (3)].Node_);
				root =(yyval.Prog_);;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 78 "grammar.y"
    {/*Здесь будет про ошибку*/;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 79 "grammar.y"
    {(yyval.Prog_)=new std::shared_ptr<language::Statement_list>();
		(*(yyval.Prog_))=std::make_shared<Statement_list>(1);
		root =(yyval.Prog_);;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 86 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
	*(yyval.Node_)=nullptr;;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 88 "grammar.y"
    {(yyval.Node_)=(yyvsp[(1) - (2)].Node_);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 89 "grammar.y"
    {(yyval.Node_)=(yyvsp[(1) - (2)].Node_);;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 90 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
					*(yyval.Node_)=std::make_shared<Assigment_node>(1,*(yyvsp[(1) - (4)].Node_),*(yyvsp[(3) - (4)].Node_));
					delete (yyvsp[(1) - (4)].Node_); delete (yyvsp[(3) - (4)].Node_);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 94 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
					*(yyval.Node_)=std::make_shared<For_loop>(1,*(yyvsp[(3) - (7)].Node_),*(yyvsp[(5) - (7)].Node_),*(yyvsp[(7) - (7)].Node_),true);
					delete (yyvsp[(3) - (7)].Node_); delete (yyvsp[(5) - (7)].Node_); delete (yyvsp[(7) - (7)].Node_);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 98 "grammar.y"
    {
					(yyval.Node_)=new std::shared_ptr<Node>();
					auto tmp =std::make_shared<Assigment_node>(1,*(yyvsp[(3) - (9)].Node_),*(yyvsp[(5) - (9)].Node_));
					*(yyval.Node_)=std::make_shared<For_loop>(1,tmp,*(yyvsp[(7) - (9)].Node_),*(yyvsp[(9) - (9)].Node_));
					delete (yyvsp[(3) - (9)].Node_); delete (yyvsp[(5) - (9)].Node_); delete (yyvsp[(7) - (9)].Node_);delete (yyvsp[(9) - (9)].Node_);
							;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 105 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
					*(yyval.Node_)=std::make_shared<For_loop>(1,*(yyvsp[(3) - (7)].Node_),*(yyvsp[(5) - (7)].Node_),*(yyvsp[(7) - (7)].Node_));
					delete (yyvsp[(3) - (7)].Node_); delete (yyvsp[(5) - (7)].Node_); delete (yyvsp[(7) - (7)].Node_);;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 109 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
					*(yyval.Node_)=std::make_shared<While_loop>(1,*(yyvsp[(3) - (5)].Node_),*(yyvsp[(5) - (5)].Node_));
					delete (yyvsp[(3) - (5)].Node_); delete (yyvsp[(5) - (5)].Node_);;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 113 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
					*(yyval.Node_)=std::make_shared<Condition_expression>(1,*(yyvsp[(3) - (5)].Node_),*(yyvsp[(5) - (5)].Node_));
					delete (yyvsp[(3) - (5)].Node_); delete (yyvsp[(5) - (5)].Node_);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 117 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
					*(yyval.Node_)=std::make_shared<Condition_expression>(1,*(yyvsp[(3) - (7)].Node_),*(yyvsp[(5) - (7)].Node_),*(yyvsp[(7) - (7)].Node_));
					delete (yyvsp[(3) - (7)].Node_); delete (yyvsp[(5) - (7)].Node_); delete (yyvsp[(7) - (7)].Node_);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 120 "grammar.y"
    {/*пока не до этого*/;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 121 "grammar.y"
    {(yyval.Node_)=(yyvsp[(1) - (1)].Node_);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 122 "grammar.y"
    {
		(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=*(yyvsp[(2) - (3)].Prog_);
		delete (yyvsp[(2) - (3)].Prog_);
		;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 127 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
	*(yyval.Node_)=nullptr;;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 132 "grammar.y"
    {/*пока не до этого*/;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 133 "grammar.y"
    {/*пока не до этого*/;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 137 "grammar.y"
    {/*пока не до этого*/;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 138 "grammar.y"
    {/*пока не до этого*/;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 142 "grammar.y"
    {/*пока не до этого*/;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 143 "grammar.y"
    {/*пока не до этого*/;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 144 "grammar.y"
    {/*пока не до этого*/;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 145 "grammar.y"
    {/*пока не до этого*/;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 148 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
					*(yyval.Node_)=std::make_shared<FunDeclaration_expression>(1,*(yyvsp[(3) - (7)].string),*(yyvsp[(4) - (7)].params_),*(yyvsp[(6) - (7)].Prog_),(yyvsp[(1) - (7)].types_));
					delete (yyvsp[(3) - (7)].string); delete (yyvsp[(4) - (7)].params_); delete (yyvsp[(6) - (7)].Prog_);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 152 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
					*(yyval.Node_)=std::make_shared<FunDeclaration_expression>(1,*(yyvsp[(4) - (8)].string),*(yyvsp[(5) - (8)].params_),*(yyvsp[(7) - (8)].Prog_),(yyvsp[(2) - (8)].types_),true);
					delete (yyvsp[(4) - (8)].string); delete (yyvsp[(5) - (8)].params_); delete (yyvsp[(7) - (8)].Prog_);}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 156 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
					*(yyval.Node_)=std::make_shared<FunDeclaration_expression>(1,*(yyvsp[(2) - (6)].string),*(yyvsp[(3) - (6)].params_),*(yyvsp[(5) - (6)].Prog_));
					delete (yyvsp[(2) - (6)].string); delete (yyvsp[(3) - (6)].params_); delete (yyvsp[(5) - (6)].Prog_);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 162 "grammar.y"
    {(yyval.params_)=new std::list<language::fparam>();;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 163 "grammar.y"
    {(yyval.params_)=(yyvsp[(2) - (3)].params_);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 167 "grammar.y"
    {(yyval.params_)=new std::list<language::fparam>();
		(yyval.params_)->push_back(*(yyvsp[(1) - (1)].fparam_));
		delete (yyvsp[(1) - (1)].fparam_);;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 171 "grammar.y"
    {(yyvsp[(1) - (3)].params_)->push_back(*(yyvsp[(3) - (3)].fparam_));
			delete (yyvsp[(3) - (3)].fparam_);;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 177 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<VarDeclaration_expression>(1,(yyvsp[(1) - (1)].fparam_)->name,(yyvsp[(1) - (1)].fparam_)->type, (yyvsp[(1) - (1)].fparam_)->isPtr);
        (yyvsp[(1) - (1)].fparam_)->name.clear();
		delete (yyvsp[(1) - (1)].fparam_);;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 181 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<VarDeclaration_expression>(1,(yyvsp[(1) - (3)].fparam_)->name,(yyvsp[(1) - (3)].fparam_)->type, (yyvsp[(1) - (3)].fparam_)->isPtr, *(yyvsp[(3) - (3)].Node_));
		delete (yyvsp[(1) - (3)].fparam_); delete (yyvsp[(3) - (3)].Node_);;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 185 "grammar.y"
    {
		(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<SquareDecl>(1,*(yyvsp[(2) - (10)].string),*(yyvsp[(5) - (10)].Node_),*(yyvsp[(7) - (10)].Node_),*(yyvsp[(9) - (10)].Node_));
		delete (yyvsp[(2) - (10)].string); delete (yyvsp[(5) - (10)].Node_); delete (yyvsp[(7) - (10)].Node_); delete (yyvsp[(9) - (10)].Node_);
								;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 190 "grammar.y"
    {
		(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<ArrDecl>(1,*(yyvsp[(2) - (6)].string),(yyvsp[(5) - (6)].operands_));
		delete (yyvsp[(2) - (6)].string);}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 195 "grammar.y"
    {
		(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<VarDeclaration_expression>(1,*(yyvsp[(2) - (4)].string),language::Types::ARRAY, false);
		delete (yyvsp[(2) - (4)].string);;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 199 "grammar.y"
    {
		(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<VarDeclaration_expression>(1,*(yyvsp[(2) - (4)].string),language::Types::SQUARE, false);
		delete (yyvsp[(2) - (4)].string);}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 206 "grammar.y"
    {(yyval.fparam_)=new fparam();
			(yyval.fparam_)->type=(yyvsp[(1) - (2)].types_);
			(yyval.fparam_)->name=*(yyvsp[(2) - (2)].string);
			(yyval.fparam_)->isPtr=false;
            delete (yyvsp[(2) - (2)].string);; }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 210 "grammar.y"
  {(yyval.fparam_) = new fparam();
  (yyval.fparam_)->type = (yyvsp[(2) - (3)].types_);
  (yyval.fparam_)->name = *(yyvsp[(3) - (3)].string);
  (yyval.fparam_)->isPtr = true;
  delete (yyvsp[(2) - (2)].string);; }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 217 "grammar.y"
    {(yyval.Prog_)=new std::shared_ptr<language::Statement_list>();
		*(yyval.Prog_)=std::make_shared<language::Statement_list>(1,*(yyvsp[(1) - (1)].Node_));
		delete (yyvsp[(1) - (1)].Node_);}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 220 "grammar.y"
    {(*(yyvsp[(1) - (2)].Prog_))->addStatement(*(yyvsp[(2) - (2)].Node_));
			(yyval.Prog_)=(yyvsp[(1) - (2)].Prog_);
			delete (yyvsp[(2) - (2)].Node_);;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 226 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Liter_int>((yyvsp[(1) - (1)].ival),1);;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 229 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Liter_float>((yyvsp[(1) - (1)].fval),1);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 232 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Liter_bool>((yyvsp[(1) - (1)].bval),1);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 235 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Var>(*(yyvsp[(1) - (1)].string),1);
		delete (yyvsp[(1) - (1)].string);;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 239 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Function_call>(1, *(yyvsp[(1) - (2)].string),(yyvsp[(2) - (2)].operands_));
		delete (yyvsp[(1) - (2)].string);;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 243 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Addittion_expression>(1, *(yyvsp[(1) - (3)].Node_),*(yyvsp[(3) - (3)].Node_));
		delete (yyvsp[(1) - (3)].Node_); delete(yyvsp[(3) - (3)].Node_);;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 247 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Substract_expression>(1, *(yyvsp[(1) - (3)].Node_),*(yyvsp[(3) - (3)].Node_));
		delete (yyvsp[(1) - (3)].Node_); delete(yyvsp[(3) - (3)].Node_);;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 251 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Multiply_expression>(1, *(yyvsp[(1) - (3)].Node_),*(yyvsp[(3) - (3)].Node_));
		delete (yyvsp[(1) - (3)].Node_); delete(yyvsp[(3) - (3)].Node_);;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 255 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Divide_expression>(1, *(yyvsp[(1) - (3)].Node_),*(yyvsp[(3) - (3)].Node_));
		delete (yyvsp[(1) - (3)].Node_); delete(yyvsp[(3) - (3)].Node_);;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 259 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<UnaryMinus_expression>(1, *(yyvsp[(2) - (2)].Node_));
		delete (yyvsp[(2) - (2)].Node_);;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 263 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<LogicInversion_expression>(1, *(yyvsp[(2) - (2)].Node_));
		delete (yyvsp[(2) - (2)].Node_);;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 267 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Disjunction_expression>(1, *(yyvsp[(1) - (3)].Node_),*(yyvsp[(3) - (3)].Node_));
		delete (yyvsp[(1) - (3)].Node_); delete(yyvsp[(3) - (3)].Node_);;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 271 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Conjunction_expression>(1, *(yyvsp[(1) - (3)].Node_),*(yyvsp[(3) - (3)].Node_));
		delete (yyvsp[(1) - (3)].Node_); delete(yyvsp[(3) - (3)].Node_);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 275 "grammar.y"
    {(yyval.Node_)=(yyvsp[(2) - (3)].Node_);;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 277 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<FieldAccess_expression>(1, *(yyvsp[(3) - (3)].string),*(yyvsp[(1) - (3)].Node_));
		delete (yyvsp[(1) - (3)].Node_); delete(yyvsp[(3) - (3)].string);;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 281 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<DimensionOperator>(1, *(yyvsp[(2) - (2)].Node_));
		delete (yyvsp[(2) - (2)].Node_);;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 285 "grammar.y"
    {(yyval.Node_)=(yyvsp[(1) - (1)].Node_);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 287 "grammar.y"
    {/*пока не до этого*/;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 289 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<More_expression>(1, *(yyvsp[(1) - (3)].Node_),*(yyvsp[(3) - (3)].Node_));
		delete (yyvsp[(1) - (3)].Node_); delete(yyvsp[(3) - (3)].Node_);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 293 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Less_expression>(1, *(yyvsp[(1) - (3)].Node_),*(yyvsp[(3) - (3)].Node_));
		delete (yyvsp[(1) - (3)].Node_); delete(yyvsp[(3) - (3)].Node_);;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 297 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<ArrayIndaxation_expression>(1, *(yyvsp[(1) - (4)].Node_),*(yyvsp[(3) - (4)].operands_));
		delete (yyvsp[(1) - (4)].Node_); delete(yyvsp[(3) - (4)].operands_);;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 301 "grammar.y"
    {/*пока не до этого*/;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 303 "grammar.y"
    {/*пока не до этого*/;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 305 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<StarOperator>(1, *(yyvsp[(2) - (2)].Node_));
		delete (yyvsp[(2) - (2)].Node_);;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 309 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Pointer_get_expr>(1, *(yyvsp[(2) - (2)].Node_));
		delete (yyvsp[(2) - (2)].Node_);;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 315 "grammar.y"
    {
		auto ex1 = std::make_shared<Var>(*(yyvsp[(2) - (3)].string),1);
		auto ex2 = std::make_shared<Var>(*(yyvsp[(3) - (3)].string),1);
		delete (yyvsp[(2) - (3)].string); delete (yyvsp[(3) - (3)].string);
		(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<TypeCheck_expression>(1,ex1,ex2);
		;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 322 "grammar.y"
    {
		(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<TypeCheck_expression>(1,*(yyvsp[(2) - (3)].Node_),(yyvsp[(3) - (3)].types_));
		delete (yyvsp[(2) - (3)].Node_);
		;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 327 "grammar.y"
    {/*пока не до этого*/;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 328 "grammar.y"
    {
		(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<TypeCheck_expression>(1, *(yyvsp[(3) - (3)].Node_),(yyvsp[(2) - (3)].types_));
		delete (yyvsp[(3) - (3)].Node_);
		;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 333 "grammar.y"
    {/*пока не до этого*/;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 334 "grammar.y"
    {
		(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<TypeCheck_expression>(1,(yyvsp[(2) - (3)].types_),(yyvsp[(3) - (3)].types_));
		;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 338 "grammar.y"
    {/*пока не до этого*/;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 343 "grammar.y"
    {(yyval.types_)=(yyvsp[(1) - (1)].types_);;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 344 "grammar.y"
    {(yyval.types_)=(yyvsp[(1) - (1)].types_);;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 345 "grammar.y"
    {(yyval.types_)=(yyvsp[(1) - (1)].types_);;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 346 "grammar.y"
    {(yyval.types_)=(yyvsp[(1) - (1)].types_);;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 347 "grammar.y"
    {(yyval.types_)=(yyvsp[(1) - (1)].types_);;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 352 "grammar.y"
    {(yyval.sides)=(yyvsp[(1) - (1)].sides);;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 353 "grammar.y"
    {(yyval.sides)=(yyvsp[(1) - (1)].sides);;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 354 "grammar.y"
    {(yyval.sides)=(yyvsp[(1) - (1)].sides);;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 355 "grammar.y"
    {(yyval.sides)=(yyvsp[(1) - (1)].sides);;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 360 "grammar.y"
    {(yyval.operands_) = new std::list<std::shared_ptr<language::Node>>();;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 361 "grammar.y"
    {(yyval.operands_)=(yyvsp[(2) - (3)].operands_);;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 365 "grammar.y"
    {(yyval.operands_) = new std::list<std::shared_ptr<language::Node>>();
	(*(yyval.operands_)).push_back(*(yyvsp[(1) - (1)].Node_));
	delete (yyvsp[(1) - (1)].Node_);;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 368 "grammar.y"
    {
	(yyvsp[(1) - (3)].operands_)->push_back(*(yyvsp[(3) - (3)].Node_));
	(yyval.operands_)=(yyvsp[(1) - (3)].operands_);
	delete (yyvsp[(3) - (3)].Node_);;}
    break;



/* Line 1455 of yacc.c  */
#line 2485 "grammar.tab.cpp"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



/* Line 1675 of yacc.c  */
#line 374 "grammar.y"

 
void yyerror(const char* c){
std::string str;
str=c;
std::cout<<str<<std::endl;
}
#include "lex.yy.cpp"
void main(){
  //  yydebug = 300;
    for (int i = 0; i < 1500000; i++) {
        fopen_s(&yyin, "pipa.txt", "r");
    yyparse();
          (*root)->initMemory();
          (*root)->pass();
        delete root;
        fclose(yyin);
    }
}
