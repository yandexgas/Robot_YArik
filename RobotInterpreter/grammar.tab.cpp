
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
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "grammar.y"

	#include "Nodes.h"
	using namespace language;
	std::shared_ptr<Statement_list>* root;
	int yylex(void);
	void yyerror (const char*);


/* Line 189 of yacc.c  */
#line 82 "grammar.tab.c"

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
     CHAR = 261,
     CONSTSTRING = 262,
     TSELOYE = 263,
     DROBNOYE = 264,
     LOGICHESKOYE = 265,
     YACHEYKA = 266,
     MASSIV = 267,
     PTR = 268,
     SIMVOL = 269,
     name = 270,
     FOR = 271,
     WHILE = 272,
     IF = 273,
     IFX = 274,
     ELSE = 275,
     BEGIN_ = 276,
     END = 277,
     RAZMER = 278,
     PROVERKA = 279,
     OR = 280,
     AND = 281,
     IDI = 282,
     POVERNI = 283,
     VZLETI = 284,
     OSTANOV = 285,
     SMOTRI = 286,
     GDEYA = 287,
     ARROW = 288,
     PERED = 289,
     ZAD = 290,
     PRAVO = 291,
     LEVO = 292,
     FUNC = 293,
     VCLUCHIT = 294,
     FILEPATH = 295,
     UMINUS = 296,
     ADR = 297,
     FIELD_OPER = 298,
     STAR = 299
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
language::Commands commands;
std::vector<int>* dimensions;
language::Square* square;
std::list<std::shared_ptr<language::Node>>* operands_;
std::list<language::fparam>* params_;
std::list<std::pair<language::Commands, std::optional<language::Sides>>>* cmd;
std::shared_ptr<language::Command_list>* cmd_lst;
language::fparam* fparam_;
char ch_;



/* Line 214 of yacc.c  */
#line 185 "grammar.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 210 "grammar.tab.c"

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
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1214

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNRULES -- Number of states.  */
#define YYNSTATES  199

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      56,    58,    45,    43,    59,    44,     2,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    57,    54,
      41,    55,    42,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    52,     2,    53,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    60,     2,    61,    47,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    48,    49,    50,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     7,    11,    15,    19,    23,    27,
      31,    35,    39,    41,    44,    47,    52,    60,    70,    78,
      84,    90,    98,   100,   104,   107,   109,   113,   117,   119,
     121,   123,   125,   127,   135,   144,   151,   154,   158,   160,
     164,   166,   170,   181,   188,   193,   198,   201,   205,   207,
     210,   212,   214,   216,   218,   220,   222,   225,   229,   233,
     237,   241,   244,   247,   251,   255,   259,   263,   266,   268,
     270,   274,   278,   283,   285,   288,   291,   295,   299,   303,
     307,   309,   311,   313,   315,   317,   319,   321,   323,   325,
     327,   330,   334,   336
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      63,     0,    -1,    63,    64,    -1,    -1,    63,    16,     1,
      -1,    63,    17,     1,    -1,    63,    18,     1,    -1,    63,
      21,     1,    -1,    63,    65,     1,    -1,    63,    67,     1,
      -1,    63,    38,     1,    -1,    63,    24,     1,    -1,    54,
      -1,    74,    54,    -1,    71,    54,    -1,    74,    55,    74,
      54,    -1,    16,    56,    71,    57,    74,    58,    64,    -1,
      16,    56,    74,    55,    74,    57,    74,    58,    64,    -1,
      16,    56,    74,    57,    74,    58,    64,    -1,    17,    56,
      74,    58,    64,    -1,    18,    56,    74,    58,    64,    -1,
      18,    56,    74,    58,    64,    20,    64,    -1,    68,    -1,
      21,    73,    22,    -1,    21,    22,    -1,    66,    -1,    65,
      33,    66,    -1,    67,    33,    77,    -1,    30,    -1,    27,
      -1,    31,    -1,    29,    -1,    28,    -1,    76,    38,    15,
      69,    21,    73,    22,    -1,    13,    76,    38,    15,    69,
      21,    73,    22,    -1,    38,    15,    69,    21,    73,    22,
      -1,    56,    58,    -1,    56,    70,    58,    -1,    72,    -1,
      70,    59,    72,    -1,    72,    -1,    72,    55,    74,    -1,
      11,    15,    55,    60,    74,    59,    74,    59,    74,    61,
      -1,    12,    15,    55,    60,    79,    61,    -1,    12,    15,
      55,    74,    -1,    11,    15,    55,    74,    -1,    76,    15,
      -1,    13,    76,    15,    -1,    64,    -1,    73,    64,    -1,
       3,    -1,     4,    -1,     5,    -1,     6,    -1,     7,    -1,
      15,    -1,    15,    78,    -1,    74,    43,    74,    -1,    74,
      44,    74,    -1,    74,    45,    74,    -1,    74,    46,    74,
      -1,    44,    74,    -1,    47,    74,    -1,    74,    25,    74,
      -1,    74,    26,    74,    -1,    56,    74,    58,    -1,    74,
      50,    15,    -1,    23,    74,    -1,    75,    -1,    65,    -1,
      74,    42,    74,    -1,    74,    41,    74,    -1,    74,    52,
      79,    53,    -1,    32,    -1,    45,    74,    -1,    49,    74,
      -1,    24,    15,    15,    -1,    24,    74,    76,    -1,    24,
      76,    74,    -1,    24,    76,    76,    -1,     8,    -1,     9,
      -1,    10,    -1,    11,    -1,    12,    -1,    14,    -1,    37,
      -1,    36,    -1,    34,    -1,    35,    -1,    56,    58,    -1,
      56,    79,    58,    -1,    74,    -1,    79,    59,    74,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    78,    78,    81,    84,    87,    90,    93,    96,    99,
     102,   105,   113,   115,   116,   117,   121,   125,   132,   137,
     141,   145,   149,   150,   155,   162,   165,   174,   176,   182,
     183,   184,   185,   188,   192,   196,   202,   203,   207,   211,
     217,   221,   225,   230,   235,   239,   246,   251,   259,   262,
     268,   271,   274,   276,   278,   282,   286,   290,   294,   298,
     302,   306,   310,   314,   318,   322,   324,   328,   332,   334,
     338,   342,   346,   350,   354,   358,   364,   371,   376,   381,
     390,   391,   392,   393,   394,   395,   400,   401,   402,   403,
     408,   409,   413,   416
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTNUM", "FLOATNUM", "ISTINO", "CHAR",
  "CONSTSTRING", "TSELOYE", "DROBNOYE", "LOGICHESKOYE", "YACHEYKA",
  "MASSIV", "PTR", "SIMVOL", "name", "FOR", "WHILE", "IF", "IFX", "ELSE",
  "BEGIN_", "END", "RAZMER", "PROVERKA", "OR", "AND", "IDI", "POVERNI",
  "VZLETI", "OSTANOV", "SMOTRI", "GDEYA", "ARROW", "PERED", "ZAD", "PRAVO",
  "LEVO", "FUNC", "VCLUCHIT", "FILEPATH", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'~'", "UMINUS", "ADR", "FIELD_OPER", "STAR", "'['", "']'",
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
     295,    60,    62,    43,    45,    42,    47,   126,   296,   297,
     298,   299,    91,    93,    59,    61,    40,    58,    41,    44,
     123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    65,    65,    66,    66,    67,
      67,    67,    67,    68,    68,    68,    69,    69,    70,    70,
      71,    71,    71,    71,    71,    71,    72,    72,    73,    73,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    75,    75,    75,    75,
      76,    76,    76,    76,    76,    76,    77,    77,    77,    77,
      78,    78,    79,    79
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     2,     2,     4,     7,     9,     7,     5,
       5,     7,     1,     3,     2,     1,     3,     3,     1,     1,
       1,     1,     1,     7,     8,     6,     2,     3,     1,     3,
       1,     3,    10,     6,     4,     4,     2,     3,     1,     2,
       1,     1,     1,     1,     1,     1,     2,     3,     3,     3,
       3,     2,     2,     3,     3,     3,     3,     2,     1,     1,
       3,     3,     4,     1,     2,     2,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,    50,    51,    52,    53,    54,    80,    81,
      82,    83,    84,     0,    85,    55,     0,     0,     0,     0,
       0,     0,    29,    32,    31,    28,    30,    73,     0,     0,
       0,     0,     0,    12,     0,     2,     0,    25,     0,    22,
       0,    40,     0,    68,     0,     0,     0,    83,    84,     0,
       0,    56,     4,     0,     5,     0,     6,     0,     7,     0,
       0,     0,     0,    24,     0,     0,    48,    69,     0,     0,
      67,    11,    55,     0,     0,    10,     0,    61,    74,    62,
      75,     0,     8,     0,     9,     0,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,     0,
      46,     0,     0,     0,    47,     0,    90,    92,     0,     0,
       0,     0,     0,     0,     0,    23,    49,    76,    77,    78,
      79,     0,     0,    65,    26,    88,    89,    87,    86,    27,
      41,    63,    64,    71,    70,    57,    58,    59,    60,    66,
       0,     0,     0,     0,    45,     0,    44,     0,    91,     0,
       0,     0,     0,     0,     0,     0,    36,     0,    38,     0,
      72,    15,     0,     0,     0,     0,    93,     0,     0,     0,
      19,    20,    37,     0,     0,     0,     0,    43,     0,     0,
       0,     0,     0,    39,    35,     0,     0,     0,    16,     0,
      18,    21,    33,     0,    34,     0,     0,    17,    42
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    66,    67,    37,    68,    39,   122,   157,    40,
      41,    69,    42,    43,    44,   129,    51,   108
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -136
static const yytype_int16 yypact[] =
{
    -136,   277,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,    16,    23,   227,  -136,    -3,     3,     4,     7,   331,
     935,   385,  -136,  -136,  -136,  -136,  -136,  -136,    27,   935,
     935,   935,   935,  -136,   935,  -136,    95,  -136,    14,  -136,
     -10,     2,  1126,  -136,    10,    33,    40,  -136,  -136,    11,
     416,  -136,  -136,   796,  -136,   935,  -136,   935,  -136,    -2,
      43,    45,   472,  -136,   850,    50,  -136,    75,    77,   526,
      28,  -136,    -5,   960,   904,  -136,    56,    28,    67,    28,
      28,   846,  -136,    87,  -136,   183,  -136,   935,   935,   935,
     935,   935,   935,   935,   935,   935,   111,   935,  -136,   935,
    -136,   114,   184,   219,  -136,   115,  -136,  1162,    24,   227,
      85,  1082,   117,   972,   994,  -136,  -136,  -136,  -136,  1162,
    -136,     9,   123,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    1162,   122,    48,   152,   152,   -16,   -16,    28,    28,  -136,
     -26,  1148,    56,   935,  1162,   935,  1162,    56,  -136,   935,
     128,   935,   935,   935,   742,   742,  -136,    65,  -136,   742,
    -136,  -136,   125,   412,     5,   130,  1162,  1016,  1104,  1038,
    -136,   132,  -136,   244,   580,   742,   935,  -136,   742,   742,
     935,   742,   742,  -136,  -136,   634,   792,   688,  -136,  1060,
    -136,  -136,  -136,   935,  -136,   742,    61,  -136,  -136
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,    -1,   154,    73,   156,  -136,   -97,  -136,   106,
    -115,  -135,   -18,  -136,   -12,  -136,  -136,   -90
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -70
static const yytype_int16 yytable[] =
{
      35,    49,    70,    73,    52,    54,   158,   140,    56,    74,
     117,    77,    78,    79,    80,    84,    81,     8,     9,    10,
      47,    48,   109,    14,   174,   100,   104,   160,    75,    94,
      95,    45,   107,   149,    96,   111,    97,   113,    46,   114,
     185,   112,    76,   187,    86,   162,    73,    85,   101,   105,
     165,    50,    74,    50,    53,   164,   119,    87,   183,    53,
      55,   118,   120,    57,   149,    76,   177,   156,   116,   130,
     131,   132,   133,   134,   135,   136,   137,   138,    96,   107,
      97,   141,   148,   149,   144,   146,    88,    89,   102,    90,
      91,    92,    93,    94,    95,   103,    82,   150,    96,    55,
      97,    57,    90,    91,    92,    93,    94,    95,    83,   112,
      85,    96,   121,    97,    22,    23,    24,    25,    26,    97,
     -69,   -69,   198,   172,   173,   163,   139,   107,    83,   142,
     147,   166,   100,   167,   168,   169,   -69,   -69,   -69,   -69,
     -69,   -69,   151,   104,   159,   -69,   175,   -69,    89,   -69,
     -69,   178,   182,   170,   171,    36,   124,    38,   186,   110,
       0,   112,   189,    90,    91,    92,    93,    94,    95,     0,
       0,     0,    96,   116,    97,   196,     0,     0,   188,     0,
     190,   191,     0,     0,   116,     0,   116,     3,     4,     5,
       6,     7,     0,     0,   197,    92,    93,    94,    95,    15,
       0,     0,    96,     0,    97,     0,     0,    20,    64,     0,
       0,    22,    23,    24,    25,    26,    27,   125,   126,   127,
     128,     0,     3,     4,     5,     6,     7,     0,    29,    30,
       0,    31,     0,    32,    15,     8,     9,    10,    47,    48,
      34,    14,    20,    64,   143,     0,    22,    23,    24,    25,
      26,    27,     8,     9,    10,    47,    48,   109,    14,     0,
       0,     0,     0,    29,    30,     0,    31,     0,    32,     0,
       0,     0,     0,     0,     0,    34,     0,     2,     0,   145,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,     0,     0,    19,     0,
      20,    21,     0,     0,    22,    23,    24,    25,    26,    27,
       0,     0,     0,     0,     0,    28,     0,     0,     0,     0,
       0,    29,    30,     0,    31,     0,    32,     0,     0,     0,
       0,    33,    58,    34,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    59,    60,    61,
       0,     0,    62,    63,    20,    64,     0,     0,    22,    23,
      24,    25,    26,    27,     0,     0,     0,     0,     0,    65,
       0,     0,     0,     0,     0,    29,    30,     0,    31,     0,
      32,     0,     0,     0,     0,    33,    71,    34,     3,     4,
       5,     6,     7,     8,     9,    10,    47,    48,     0,    14,
      72,     0,     0,     0,     0,     0,     0,     0,    20,    64,
       0,     0,    22,    23,    24,    25,    26,    27,     0,     3,
       4,     5,     6,     7,     0,     0,     0,     0,     0,    29,
      30,    15,    31,     0,    32,     0,     0,    88,    89,    20,
      64,    34,     0,    22,    23,    24,    25,    26,    27,     0,
       0,     0,     0,    90,    91,    92,    93,    94,    95,     0,
      29,    30,    96,    31,    97,    32,     0,     0,     0,     0,
       0,   176,    34,     0,   106,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    59,    60,
      61,     0,     0,    62,    63,    20,    64,     0,     0,    22,
      23,    24,    25,    26,    27,     0,     0,     0,     0,     0,
      65,     0,     0,     0,     0,     0,    29,    30,     0,    31,
       0,    32,     0,     0,     0,     0,    33,     0,    34,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    59,    60,    61,     0,     0,    62,   115,    20,
      64,     0,     0,    22,    23,    24,    25,    26,    27,     0,
       0,     0,     0,     0,    65,     0,     0,     0,     0,     0,
      29,    30,     0,    31,     0,    32,     0,     0,     0,     0,
      33,     0,    34,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    59,    60,    61,     0,
       0,    62,   184,    20,    64,     0,     0,    22,    23,    24,
      25,    26,    27,     0,     0,     0,     0,     0,    65,     0,
       0,     0,     0,     0,    29,    30,     0,    31,     0,    32,
       0,     0,     0,     0,    33,     0,    34,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      59,    60,    61,     0,     0,    62,   192,    20,    64,     0,
       0,    22,    23,    24,    25,    26,    27,     0,     0,     0,
       0,     0,    65,     0,     0,     0,     0,     0,    29,    30,
       0,    31,     0,    32,     0,     0,     0,     0,    33,     0,
      34,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    59,    60,    61,     0,     0,    62,
     194,    20,    64,     0,     0,    22,    23,    24,    25,    26,
      27,     0,     0,     0,     0,     0,    65,     0,     0,     0,
       0,     0,    29,    30,     0,    31,     0,    32,     0,     0,
       0,     0,    33,     0,    34,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    59,    60,
      61,     0,     0,    62,     0,    20,    64,     0,     0,    22,
      23,    24,    25,    26,    27,     0,     0,     0,     0,     0,
      65,     0,     0,     0,     0,     0,    29,    30,     0,    31,
       0,    32,     0,     0,     0,     0,    33,     0,    34,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,   109,
      14,    15,     0,     0,     0,     0,     0,    88,    89,    20,
      64,     0,     0,    22,    23,    24,    25,    26,    27,     0,
       0,     0,     0,    90,    91,    92,    93,    94,    95,     0,
      29,    30,    96,    31,    97,    32,     0,     0,     0,     0,
       0,   193,    34,     3,     4,     5,     6,     7,     8,     9,
      10,    47,    48,     0,    14,    72,     0,     0,     0,     0,
       0,    88,    89,    20,    64,     0,     0,    22,    23,    24,
      25,    26,    27,     0,     0,     0,     0,    90,    91,    92,
      93,    94,    95,     0,    29,    30,    96,    31,    97,    32,
       0,     0,     0,     0,   123,     0,    34,     3,     4,     5,
       6,     7,     8,     9,    10,    47,    48,     0,    14,    15,
       0,     0,     0,     0,     0,     0,     0,    20,    64,     0,
       0,    22,    23,    24,    25,    26,    27,     0,     3,     4,
       5,     6,     7,     0,     0,     0,     0,     0,    29,    30,
      15,    31,     0,    32,     0,     0,     0,     0,    20,    64,
      34,     0,    22,    23,    24,    25,    26,    27,     8,     9,
      10,    47,    48,     0,    14,     0,     0,     0,     0,    29,
      30,     0,    31,     0,    32,    88,    89,     0,     0,     0,
       0,    34,     0,     0,     0,     0,     0,    88,    89,     0,
       0,    90,    91,    92,    93,    94,    95,     0,     0,     0,
      96,     0,    97,    90,    91,    92,    93,    94,    95,    88,
      89,     0,    96,     0,    97,     0,     0,     0,     0,     0,
     154,     0,     0,     0,     0,    90,    91,    92,    93,    94,
      95,    88,    89,     0,    96,     0,    97,     0,     0,     0,
       0,     0,   155,     0,     0,     0,     0,    90,    91,    92,
      93,    94,    95,    88,    89,     0,    96,     0,    97,     0,
       0,     0,     0,     0,   179,     0,     0,     0,     0,    90,
      91,    92,    93,    94,    95,    88,    89,     0,    96,     0,
      97,     0,     0,     0,     0,     0,   181,     0,     0,     0,
       0,    90,    91,    92,    93,    94,    95,    88,    89,     0,
      96,     0,    97,     0,     0,     0,     0,     0,   195,     0,
       0,     0,     0,    90,    91,    92,    93,    94,    95,    88,
      89,     0,    96,     0,    97,     0,     0,   152,     0,   153,
       0,     0,     0,     0,     0,    90,    91,    92,    93,    94,
      95,    88,    89,     0,    96,     0,    97,     0,     0,     0,
       0,   180,     0,     0,     0,     0,     0,    90,    91,    92,
      93,    94,    95,    88,    89,     0,    96,     0,    97,     0,
      98,    99,     0,     0,     0,     0,     0,    88,    89,    90,
      91,    92,    93,    94,    95,     0,     0,     0,    96,     0,
      97,     0,   161,    90,    91,    92,    93,    94,    95,     0,
       0,     0,    96,     0,    97
};

static const yytype_int16 yycheck[] =
{
       1,    13,    20,    21,     1,     1,   121,    97,     1,    21,
      15,    29,    30,    31,    32,     1,    34,     8,     9,    10,
      11,    12,    13,    14,   159,    15,    15,    53,     1,    45,
      46,    15,    50,    59,    50,    53,    52,    55,    15,    57,
     175,    53,    15,   178,    54,   142,    64,    33,    38,    38,
     147,    56,    64,    56,    56,   145,    74,    55,   173,    56,
      56,    73,    74,    56,    59,    15,    61,    58,    69,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    50,    97,
      52,    99,    58,    59,   102,   103,    25,    26,    55,    41,
      42,    43,    44,    45,    46,    55,     1,   109,    50,    56,
      52,    56,    41,    42,    43,    44,    45,    46,    33,   121,
      33,    50,    56,    52,    27,    28,    29,    30,    31,    52,
      25,    26,    61,    58,    59,   143,    15,   145,    33,    15,
      15,   149,    15,   151,   152,   153,    41,    42,    43,    44,
      45,    46,    57,    15,    21,    50,    21,    52,    26,    54,
      55,    21,    20,   154,   155,     1,    83,     1,   176,    53,
      -1,   173,   180,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    50,   174,    52,   193,    -1,    -1,   179,    -1,
     181,   182,    -1,    -1,   185,    -1,   187,     3,     4,     5,
       6,     7,    -1,    -1,   195,    43,    44,    45,    46,    15,
      -1,    -1,    50,    -1,    52,    -1,    -1,    23,    24,    -1,
      -1,    27,    28,    29,    30,    31,    32,    34,    35,    36,
      37,    -1,     3,     4,     5,     6,     7,    -1,    44,    45,
      -1,    47,    -1,    49,    15,     8,     9,    10,    11,    12,
      56,    14,    23,    24,    60,    -1,    27,    28,    29,    30,
      31,    32,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    44,    45,    -1,    47,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,     0,    -1,    60,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    -1,    21,    -1,
      23,    24,    -1,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    44,    45,    -1,    47,    -1,    49,    -1,    -1,    -1,
      -1,    54,     1,    56,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      -1,    -1,    21,    22,    23,    24,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,    -1,
      49,    -1,    -1,    -1,    -1,    54,     1,    56,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      -1,    -1,    27,    28,    29,    30,    31,    32,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    44,
      45,    15,    47,    -1,    49,    -1,    -1,    25,    26,    23,
      24,    56,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    41,    42,    43,    44,    45,    46,    -1,
      44,    45,    50,    47,    52,    49,    -1,    -1,    -1,    -1,
      -1,    59,    56,    -1,    58,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    -1,    21,    22,    23,    24,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,
      -1,    49,    -1,    -1,    -1,    -1,    54,    -1,    56,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    -1,    21,    22,    23,
      24,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      44,    45,    -1,    47,    -1,    49,    -1,    -1,    -1,    -1,
      54,    -1,    56,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      -1,    21,    22,    23,    24,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    44,    45,    -1,    47,    -1,    49,
      -1,    -1,    -1,    -1,    54,    -1,    56,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    -1,    21,    22,    23,    24,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    44,    45,
      -1,    47,    -1,    49,    -1,    -1,    -1,    -1,    54,    -1,
      56,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    -1,    -1,    21,
      22,    23,    24,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    44,    45,    -1,    47,    -1,    49,    -1,    -1,
      -1,    -1,    54,    -1,    56,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    -1,    21,    -1,    23,    24,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    47,
      -1,    49,    -1,    -1,    -1,    -1,    54,    -1,    56,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    25,    26,    23,
      24,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    41,    42,    43,    44,    45,    46,    -1,
      44,    45,    50,    47,    52,    49,    -1,    -1,    -1,    -1,
      -1,    59,    56,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    14,    15,    -1,    -1,    -1,    -1,
      -1,    25,    26,    23,    24,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    41,    42,    43,
      44,    45,    46,    -1,    44,    45,    50,    47,    52,    49,
      -1,    -1,    -1,    -1,    58,    -1,    56,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    44,    45,
      15,    47,    -1,    49,    -1,    -1,    -1,    -1,    23,    24,
      56,    -1,    27,    28,    29,    30,    31,    32,     8,     9,
      10,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,    44,
      45,    -1,    47,    -1,    49,    25,    26,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,
      -1,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      50,    -1,    52,    41,    42,    43,    44,    45,    46,    25,
      26,    -1,    50,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,    25,    26,    -1,    50,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    41,    42,    43,
      44,    45,    46,    25,    26,    -1,    50,    -1,    52,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    41,
      42,    43,    44,    45,    46,    25,    26,    -1,    50,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    46,    25,    26,    -1,
      50,    -1,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    -1,    -1,    41,    42,    43,    44,    45,    46,    25,
      26,    -1,    50,    -1,    52,    -1,    -1,    55,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,    25,    26,    -1,    50,    -1,    52,    -1,    -1,    -1,
      -1,    57,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,
      44,    45,    46,    25,    26,    -1,    50,    -1,    52,    -1,
      54,    55,    -1,    -1,    -1,    -1,    -1,    25,    26,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    50,    -1,
      52,    -1,    54,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    50,    -1,    52
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    63,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    21,
      23,    24,    27,    28,    29,    30,    31,    32,    38,    44,
      45,    47,    49,    54,    56,    64,    65,    66,    67,    68,
      71,    72,    74,    75,    76,    15,    15,    11,    12,    76,
      56,    78,     1,    56,     1,    56,     1,    56,     1,    16,
      17,    18,    21,    22,    24,    38,    64,    65,    67,    73,
      74,     1,    15,    74,    76,     1,    15,    74,    74,    74,
      74,    74,     1,    33,     1,    33,    54,    55,    25,    26,
      41,    42,    43,    44,    45,    46,    50,    52,    54,    55,
      15,    38,    55,    55,    15,    38,    58,    74,    79,    13,
      71,    74,    76,    74,    74,    22,    64,    15,    76,    74,
      76,    56,    69,    58,    66,    34,    35,    36,    37,    77,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    15,
      79,    74,    15,    60,    74,    60,    74,    15,    58,    59,
      76,    57,    55,    57,    58,    58,    58,    70,    72,    21,
      53,    54,    69,    74,    79,    69,    74,    74,    74,    74,
      64,    64,    58,    59,    73,    21,    59,    61,    21,    58,
      57,    58,    20,    72,    22,    73,    74,    73,    64,    74,
      64,    64,    22,    59,    22,    58,    74,    64,    61
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

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

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

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
       `yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
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
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 78 "grammar.y"
    {(**(yyvsp[(1) - (2)].Prog_)).addStatement(*(yyvsp[(2) - (2)].Node_));
			(yyval.Prog_)=(yyvsp[(1) - (2)].Prog_); delete (yyvsp[(2) - (2)].Node_);
			root =(yyval.Prog_);;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 81 "grammar.y"
    {(yyval.Prog_)=new std::shared_ptr<language::Statement_list>();
		(*(yyval.Prog_))=std::make_shared<Statement_list>(1);
		root =(yyval.Prog_);;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 84 "grammar.y"
    {std::cout<<"Incorrect TSIKL declaration. Loop body expected. Line: "<<(yylsp[(3) - (3)]).first_line<<std::endl;
			yyerrok;
			(yyval.Prog_)=(yyvsp[(1) - (3)].Prog_);;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 87 "grammar.y"
    {std::cout<<"Incorrect POKA loop declaration. Loop body expected. Line: "<<(yylsp[(3) - (3)]).first_line<<std::endl;
			yyerrok;
			(yyval.Prog_)=(yyvsp[(1) - (3)].Prog_);;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 90 "grammar.y"
    {std::cout<<"Incorrect conditional operator declaration. Line:  "<<(yylsp[(3) - (3)]).first_line<<std::endl;
			yyerrok;
			(yyval.Prog_)=(yyvsp[(1) - (3)].Prog_);;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 93 "grammar.y"
    {std::cout<<"Missed end of block. KONETS expected in pair with NACHALO in line: "<<(yylsp[(3) - (3)]).first_line<<std::endl;
			yyerrok;
			(yyval.Prog_)=(yyvsp[(1) - (3)].Prog_);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 96 "grammar.y"
    {std::cout<<"Incorrect declaretion of list of robot directives in line:  "<<(yylsp[(3) - (3)]).first_line<<std::endl;
			yyerrok;
			(yyval.Prog_)=(yyvsp[(1) - (3)].Prog_);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 99 "grammar.y"
    {std::cout<<"Incorrect robot command declaration. ->SIDE expected in line:  "<<(yylsp[(3) - (3)]).first_line<<std::endl;
			yyerrok;
			(yyval.Prog_)=(yyvsp[(1) - (3)].Prog_);;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 102 "grammar.y"
    {std::cout<<"Incorrect function declaration in line:  "<<(yylsp[(3) - (3)]).first_line<<std::endl;
			yyerrok;
			(yyval.Prog_)=(yyvsp[(1) - (3)].Prog_);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 105 "grammar.y"
    {std::cout<<"Incorrect usage of type check operator in line:  "<<(yylsp[(3) - (3)]).first_line<<std::endl;
			yyerrok;
			(yyval.Prog_)=(yyvsp[(1) - (3)].Prog_);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 113 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
	*(yyval.Node_)=nullptr;;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 115 "grammar.y"
    {(yyval.Node_)=(yyvsp[(1) - (2)].Node_);;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 116 "grammar.y"
    {(yyval.Node_)=(yyvsp[(1) - (2)].Node_);;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 117 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
					*(yyval.Node_)=std::make_shared<Assigment_node>(1,*(yyvsp[(1) - (4)].Node_),*(yyvsp[(3) - (4)].Node_));
					delete (yyvsp[(1) - (4)].Node_); delete (yyvsp[(3) - (4)].Node_);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 121 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
					*(yyval.Node_)=std::make_shared<For_loop>(1,*(yyvsp[(3) - (7)].Node_),*(yyvsp[(5) - (7)].Node_),*(yyvsp[(7) - (7)].Node_),true);
					delete (yyvsp[(3) - (7)].Node_); delete (yyvsp[(5) - (7)].Node_); delete (yyvsp[(7) - (7)].Node_);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 125 "grammar.y"
    {
					(yyval.Node_)=new std::shared_ptr<Node>();
					auto tmp =std::make_shared<Assigment_node>(1,*(yyvsp[(3) - (9)].Node_),*(yyvsp[(5) - (9)].Node_));
					*(yyval.Node_)=std::make_shared<For_loop>(1,tmp,*(yyvsp[(7) - (9)].Node_),*(yyvsp[(9) - (9)].Node_));
					delete (yyvsp[(3) - (9)].Node_); delete (yyvsp[(5) - (9)].Node_); delete (yyvsp[(7) - (9)].Node_);delete (yyvsp[(9) - (9)].Node_);
							;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 132 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
					*(yyval.Node_)=std::make_shared<For_loop>(1,*(yyvsp[(3) - (7)].Node_),*(yyvsp[(5) - (7)].Node_),*(yyvsp[(7) - (7)].Node_));
					delete (yyvsp[(3) - (7)].Node_); delete (yyvsp[(5) - (7)].Node_); delete (yyvsp[(7) - (7)].Node_);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 137 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
					*(yyval.Node_)=std::make_shared<While_loop>(1,*(yyvsp[(3) - (5)].Node_),*(yyvsp[(5) - (5)].Node_));
					delete (yyvsp[(3) - (5)].Node_); delete (yyvsp[(5) - (5)].Node_);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 141 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
					*(yyval.Node_)=std::make_shared<Condition_expression>(1,*(yyvsp[(3) - (5)].Node_),*(yyvsp[(5) - (5)].Node_));
					delete (yyvsp[(3) - (5)].Node_); delete (yyvsp[(5) - (5)].Node_);;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 145 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
					*(yyval.Node_)=std::make_shared<Condition_expression>(1,*(yyvsp[(3) - (7)].Node_),*(yyvsp[(5) - (7)].Node_),*(yyvsp[(7) - (7)].Node_));
					delete (yyvsp[(3) - (7)].Node_); delete (yyvsp[(5) - (7)].Node_); delete (yyvsp[(7) - (7)].Node_);;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 149 "grammar.y"
    {(yyval.Node_)=(yyvsp[(1) - (1)].Node_);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 150 "grammar.y"
    {
		(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=*(yyvsp[(2) - (3)].Prog_);
		delete (yyvsp[(2) - (3)].Prog_);
		;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 155 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
				*(yyval.Node_)=nullptr;;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 162 "grammar.y"
    {(yyval.cmd_lst)=new std::shared_ptr<Command_list>();
			*(yyval.cmd_lst)= std::make_shared<Command_list>(1,*(yyvsp[(1) - (1)].cmd));
			delete (yyvsp[(1) - (1)].cmd);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 165 "grammar.y"
    {
				auto cmd = (*((yyvsp[(3) - (3)].cmd))).front();
				(*(yyvsp[(1) - (3)].cmd_lst))->addCommand(cmd.first, cmd.second);
				(yyval.cmd_lst)=(yyvsp[(1) - (3)].cmd_lst);
				delete (yyvsp[(3) - (3)].cmd);
					;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 174 "grammar.y"
    {(yyval.cmd) = new std::list<std::pair<language::Commands, std::optional<Sides>>>();
			(*(yyval.cmd)).push_back(std::make_pair((yyvsp[(1) - (3)].commands),(yyvsp[(3) - (3)].sides)));;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 176 "grammar.y"
    {(yyval.cmd) = new std::list<std::pair<language::Commands, std::optional<Sides>>>();
			(*(yyval.cmd)).push_back(std::make_pair((yyvsp[(1) - (1)].commands),std::nullopt));;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 182 "grammar.y"
    {(yyval.commands)=(yyvsp[(1) - (1)].commands);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 183 "grammar.y"
    {(yyval.commands)=(yyvsp[(1) - (1)].commands);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 184 "grammar.y"
    {(yyval.commands)=(yyvsp[(1) - (1)].commands);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 185 "grammar.y"
    {(yyval.commands)=(yyvsp[(1) - (1)].commands);;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 188 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
					*(yyval.Node_)=std::make_shared<FunDeclaration_expression>(1,*(yyvsp[(3) - (7)].string),*(yyvsp[(4) - (7)].params_),*(yyvsp[(6) - (7)].Prog_),(yyvsp[(1) - (7)].types_));
					delete (yyvsp[(3) - (7)].string); delete (yyvsp[(4) - (7)].params_); delete (yyvsp[(6) - (7)].Prog_);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 192 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
					*(yyval.Node_)=std::make_shared<FunDeclaration_expression>(1,*(yyvsp[(4) - (8)].string),*(yyvsp[(5) - (8)].params_),*(yyvsp[(7) - (8)].Prog_),(yyvsp[(2) - (8)].types_),true);
					delete (yyvsp[(4) - (8)].string); delete (yyvsp[(5) - (8)].params_); delete (yyvsp[(7) - (8)].Prog_);;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 196 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
					*(yyval.Node_)=std::make_shared<FunDeclaration_expression>(1,*(yyvsp[(2) - (6)].string),*(yyvsp[(3) - (6)].params_),*(yyvsp[(5) - (6)].Prog_));
					delete (yyvsp[(2) - (6)].string); delete (yyvsp[(3) - (6)].params_); delete (yyvsp[(5) - (6)].Prog_);;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 202 "grammar.y"
    {(yyval.params_)=new std::list<language::fparam>();;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 203 "grammar.y"
    {(yyval.params_)=(yyvsp[(2) - (3)].params_);;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 207 "grammar.y"
    {(yyval.params_)=new std::list<language::fparam>();
		(yyval.params_)->push_back(*(yyvsp[(1) - (1)].fparam_));
		delete (yyvsp[(1) - (1)].fparam_);;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 211 "grammar.y"
    {(yyvsp[(1) - (3)].params_)->push_back(*(yyvsp[(3) - (3)].fparam_));
			delete (yyvsp[(3) - (3)].fparam_);;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 217 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<VarDeclaration_expression>(1,(yyvsp[(1) - (1)].fparam_)->name,(yyvsp[(1) - (1)].fparam_)->type, (yyvsp[(1) - (1)].fparam_)->isPtr);
		delete (yyvsp[(1) - (1)].fparam_);;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 221 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<VarDeclaration_expression>(1,(yyvsp[(1) - (3)].fparam_)->name,(yyvsp[(1) - (3)].fparam_)->type, (yyvsp[(1) - (3)].fparam_)->isPtr, *(yyvsp[(3) - (3)].Node_));
		delete (yyvsp[(1) - (3)].fparam_); delete (yyvsp[(3) - (3)].Node_);;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 225 "grammar.y"
    {
		(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<SquareDecl>(1,*(yyvsp[(2) - (10)].string),*(yyvsp[(5) - (10)].Node_),*(yyvsp[(7) - (10)].Node_),*(yyvsp[(9) - (10)].Node_));
		delete (yyvsp[(2) - (10)].string); delete (yyvsp[(5) - (10)].Node_); delete (yyvsp[(7) - (10)].Node_); delete (yyvsp[(9) - (10)].Node_);
								;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 230 "grammar.y"
    {
		(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<ArrDecl>(1,*(yyvsp[(2) - (6)].string),(yyvsp[(5) - (6)].operands_));
		delete (yyvsp[(2) - (6)].string);}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 235 "grammar.y"
    {
		(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<VarDeclaration_expression>(1,*(yyvsp[(2) - (4)].string),language::Types::ARRAY, false, *(yyvsp[(4) - (4)].Node_));
		delete (yyvsp[(2) - (4)].string);delete (yyvsp[(4) - (4)].Node_);;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 239 "grammar.y"
    {
		(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<VarDeclaration_expression>(1,*(yyvsp[(2) - (4)].string),language::Types::SQUARE, false, *(yyvsp[(4) - (4)].Node_));
		delete (yyvsp[(2) - (4)].string); delete (yyvsp[(4) - (4)].Node_);;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 246 "grammar.y"
    {(yyval.fparam_)=new fparam();
			(yyval.fparam_)->type=(yyvsp[(1) - (2)].types_);
			(yyval.fparam_)->name=*(yyvsp[(2) - (2)].string);
			(yyval.fparam_)->isPtr=false;
			delete (yyvsp[(2) - (2)].string);;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 251 "grammar.y"
    {(yyval.fparam_)=new fparam();
			(yyval.fparam_)->type=(yyvsp[(2) - (3)].types_);
			(yyval.fparam_)->name=*(yyvsp[(3) - (3)].string);
			(yyval.fparam_)->isPtr=true;
			delete (yyvsp[(3) - (3)].string);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 259 "grammar.y"
    {(yyval.Prog_)=new std::shared_ptr<language::Statement_list>();
		*(yyval.Prog_)=std::make_shared<language::Statement_list>(1,*(yyvsp[(1) - (1)].Node_));
		delete (yyvsp[(1) - (1)].Node_);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 262 "grammar.y"
    {(*(yyvsp[(1) - (2)].Prog_))->addStatement(*(yyvsp[(2) - (2)].Node_));
			(yyval.Prog_)=(yyvsp[(1) - (2)].Prog_);
			delete (yyvsp[(2) - (2)].Node_);;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 268 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Literal<int>>((yyvsp[(1) - (1)].ival),language::Types::INT,1);;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 271 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Literal<float>>((yyvsp[(1) - (1)].fval),language::Types::FLOAT,1);;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 274 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Literal<bool>>((yyvsp[(1) - (1)].bval),language::Types::BOOL,1);;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 276 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Literal<char>>((yyvsp[(1) - (1)].ch_),language::Types::BYTE,1);;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 278 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<constString>(*(yyvsp[(1) - (1)].string),1);
		delete (yyvsp[(1) - (1)].string);;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 282 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Var>(*(yyvsp[(1) - (1)].string),1);
		delete (yyvsp[(1) - (1)].string);;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 286 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Function_call>(1, *(yyvsp[(1) - (2)].string),(yyvsp[(2) - (2)].operands_));
		delete (yyvsp[(1) - (2)].string);;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 290 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Addittion_expression>(1, *(yyvsp[(1) - (3)].Node_),*(yyvsp[(3) - (3)].Node_));
		delete (yyvsp[(1) - (3)].Node_); delete(yyvsp[(3) - (3)].Node_);;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 294 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Substract_expression>(1, *(yyvsp[(1) - (3)].Node_),*(yyvsp[(3) - (3)].Node_));
		delete (yyvsp[(1) - (3)].Node_); delete(yyvsp[(3) - (3)].Node_);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 298 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Multiply_expression>(1, *(yyvsp[(1) - (3)].Node_),*(yyvsp[(3) - (3)].Node_));
		delete (yyvsp[(1) - (3)].Node_); delete(yyvsp[(3) - (3)].Node_);;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 302 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Divide_expression>(1, *(yyvsp[(1) - (3)].Node_),*(yyvsp[(3) - (3)].Node_));
		delete (yyvsp[(1) - (3)].Node_); delete(yyvsp[(3) - (3)].Node_);;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 306 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<UnaryMinus_expression>(1, *(yyvsp[(2) - (2)].Node_));
		delete (yyvsp[(2) - (2)].Node_);;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 310 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<LogicInversion_expression>(1, *(yyvsp[(2) - (2)].Node_));
		delete (yyvsp[(2) - (2)].Node_);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 314 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Disjunction_expression>(1, *(yyvsp[(1) - (3)].Node_),*(yyvsp[(3) - (3)].Node_));
		delete (yyvsp[(1) - (3)].Node_); delete(yyvsp[(3) - (3)].Node_);;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 318 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Conjunction_expression>(1, *(yyvsp[(1) - (3)].Node_),*(yyvsp[(3) - (3)].Node_));
		delete (yyvsp[(1) - (3)].Node_); delete(yyvsp[(3) - (3)].Node_);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 322 "grammar.y"
    {(yyval.Node_)=(yyvsp[(2) - (3)].Node_);;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 324 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<FieldAccess_expression>(1, *(yyvsp[(3) - (3)].string),*(yyvsp[(1) - (3)].Node_));
		delete (yyvsp[(1) - (3)].Node_); delete(yyvsp[(3) - (3)].string);;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 328 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<DimensionOperator>(1, *(yyvsp[(2) - (2)].Node_));
		delete (yyvsp[(2) - (2)].Node_);;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 332 "grammar.y"
    {(yyval.Node_)=(yyvsp[(1) - (1)].Node_);;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 334 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
			*(yyval.Node_)=*(yyvsp[(1) - (1)].cmd_lst);
			delete (yyvsp[(1) - (1)].cmd_lst);;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 338 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<More_expression>(1, *(yyvsp[(1) - (3)].Node_),*(yyvsp[(3) - (3)].Node_));
		delete (yyvsp[(1) - (3)].Node_); delete(yyvsp[(3) - (3)].Node_);;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 342 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Less_expression>(1, *(yyvsp[(1) - (3)].Node_),*(yyvsp[(3) - (3)].Node_));
		delete (yyvsp[(1) - (3)].Node_); delete(yyvsp[(3) - (3)].Node_);;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 346 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<ArrayIndaxation_expression>(1, *(yyvsp[(1) - (4)].Node_),*(yyvsp[(3) - (4)].operands_));
		delete (yyvsp[(1) - (4)].Node_); delete(yyvsp[(3) - (4)].operands_);;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 350 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Where_operator>(1);
		;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 354 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<StarOperator>(1, *(yyvsp[(2) - (2)].Node_));
		delete (yyvsp[(2) - (2)].Node_);;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 358 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Pointer_get_expr>(1, *(yyvsp[(2) - (2)].Node_));
		delete (yyvsp[(2) - (2)].Node_);;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 364 "grammar.y"
    {
		auto ex1 = std::make_shared<Var>(*(yyvsp[(2) - (3)].string),1);
		auto ex2 = std::make_shared<Var>(*(yyvsp[(3) - (3)].string),1);
		delete (yyvsp[(2) - (3)].string); delete (yyvsp[(3) - (3)].string);
		(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<TypeCheck_expression>(1,ex1,ex2);
		;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 371 "grammar.y"
    {
		(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<TypeCheck_expression>(1,*(yyvsp[(2) - (3)].Node_),(yyvsp[(3) - (3)].types_));
		delete (yyvsp[(2) - (3)].Node_);
		;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 376 "grammar.y"
    {
		(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<TypeCheck_expression>(1,*(yyvsp[(3) - (3)].Node_),(yyvsp[(2) - (3)].types_));
		delete (yyvsp[(3) - (3)].Node_);
		;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 381 "grammar.y"
    {
		(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<TypeCheck_expression>(1,(yyvsp[(2) - (3)].types_),(yyvsp[(3) - (3)].types_));
		;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 390 "grammar.y"
    {(yyval.types_)=(yyvsp[(1) - (1)].types_);;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 391 "grammar.y"
    {(yyval.types_)=(yyvsp[(1) - (1)].types_);;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 392 "grammar.y"
    {(yyval.types_)=(yyvsp[(1) - (1)].types_);;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 393 "grammar.y"
    {(yyval.types_)=(yyvsp[(1) - (1)].types_);;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 394 "grammar.y"
    {(yyval.types_)=(yyvsp[(1) - (1)].types_);;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 395 "grammar.y"
    {(yyval.types_)=(yyvsp[(1) - (1)].types_);;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 400 "grammar.y"
    {(yyval.sides)=(yyvsp[(1) - (1)].sides);;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 401 "grammar.y"
    {(yyval.sides)=(yyvsp[(1) - (1)].sides);;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 402 "grammar.y"
    {(yyval.sides)=(yyvsp[(1) - (1)].sides);;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 403 "grammar.y"
    {(yyval.sides)=(yyvsp[(1) - (1)].sides);;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 408 "grammar.y"
    {(yyval.operands_) = new std::list<std::shared_ptr<language::Node>>();;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 409 "grammar.y"
    {(yyval.operands_)=(yyvsp[(2) - (3)].operands_);;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 413 "grammar.y"
    {(yyval.operands_) = new std::list<std::shared_ptr<language::Node>>();
	(*(yyval.operands_)).push_back(*(yyvsp[(1) - (1)].Node_));
	delete (yyvsp[(1) - (1)].Node_);;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 416 "grammar.y"
    {
	(yyvsp[(1) - (3)].operands_)->push_back(*(yyvsp[(3) - (3)].Node_));
	(yyval.operands_)=(yyvsp[(1) - (3)].operands_);
	delete (yyvsp[(3) - (3)].Node_);;}
    break;



/* Line 1455 of yacc.c  */
#line 2613 "grammar.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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

  yyerror_range[0] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[0] = yylsp[1-yylen];
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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
#line 422 "grammar.y"

 
void yyerror(const char* c){
std::string str;
str=c;
std::cout<<str<<std::endl;
}

namespace robot {
    bool Robot::AllowScriptExecution = true;
    bool Robot::isOnFly = false;
    Square Robot::position{};
    int Robot::rotation = 0;

    Square Labitinth::exit_{};
    std::vector<std::vector<bool>>Labitinth::walls{};
}

#include "lex.yy.cpp"
void main(){
 
 //yydebug = 300;

            fopen_s(&yyin, "pipa.txt", "r");
            yyparse();
            if (yynerrs <= 0) {
                robot::initArea();
            (*root)->initMemory(initStLib());
            try {
                system("color 02");
                std::cout << "==========Program log=========" << std::endl;
                (*root)->pass();
                std::cout << "==========Success end of program.=========" << std::endl;
            }
            catch (Script_error e){
                system("color 04");
                std::cout << e;
                yynerrs += 1;
            }
            delete root;
            fclose(yyin);
        }
           if(yynerrs>0) system("color 04");
         std::cout << "Errors detected: " << yynerrs << std::endl;
}
