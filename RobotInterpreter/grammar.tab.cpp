
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
#line 185 "grammar.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 197 "grammar.tab.cpp"

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1062

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNRULES -- Number of states.  */
#define YYNSTATES  184

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
       0,     0,     3,     6,     9,    10,    12,    15,    18,    23,
      31,    41,    49,    55,    61,    69,    71,    75,    78,    80,
      84,    88,    90,    92,    94,    96,    98,   106,   115,   122,
     125,   129,   131,   135,   137,   141,   152,   159,   164,   169,
     172,   176,   178,   181,   183,   185,   187,   189,   191,   193,
     196,   200,   204,   208,   212,   215,   218,   222,   226,   230,
     234,   237,   239,   241,   245,   249,   254,   256,   259,   262,
     266,   270,   274,   278,   280,   282,   284,   286,   288,   290,
     292,   294,   296,   298,   301,   305,   307
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      63,     0,    -1,    63,    64,    -1,    63,     1,    -1,    -1,
      54,    -1,    74,    54,    -1,    71,    54,    -1,    74,    55,
      74,    54,    -1,    16,    56,    71,    57,    74,    58,    64,
      -1,    16,    56,    74,    55,    74,    57,    74,    58,    64,
      -1,    16,    56,    74,    57,    74,    58,    64,    -1,    17,
      56,    74,    58,    64,    -1,    18,    56,    74,    58,    64,
      -1,    18,    56,    74,    58,    64,    20,    64,    -1,    68,
      -1,    21,    73,    22,    -1,    21,    22,    -1,    66,    -1,
      65,    33,    66,    -1,    67,    33,    77,    -1,    30,    -1,
      27,    -1,    31,    -1,    29,    -1,    28,    -1,    76,    38,
      15,    69,    21,    73,    22,    -1,    13,    76,    38,    15,
      69,    21,    73,    22,    -1,    38,    15,    69,    21,    73,
      22,    -1,    56,    58,    -1,    56,    70,    58,    -1,    72,
      -1,    70,    59,    72,    -1,    72,    -1,    72,    55,    74,
      -1,    11,    15,    55,    60,    74,    59,    74,    59,    74,
      61,    -1,    12,    15,    55,    60,    79,    61,    -1,    12,
      15,    55,    74,    -1,    11,    15,    55,    74,    -1,    76,
      15,    -1,    13,    76,    15,    -1,    64,    -1,    73,    64,
      -1,     3,    -1,     4,    -1,     5,    -1,     6,    -1,     7,
      -1,    15,    -1,    15,    78,    -1,    74,    43,    74,    -1,
      74,    44,    74,    -1,    74,    45,    74,    -1,    74,    46,
      74,    -1,    44,    74,    -1,    47,    74,    -1,    74,    25,
      74,    -1,    74,    26,    74,    -1,    56,    74,    58,    -1,
      74,    50,    15,    -1,    23,    74,    -1,    75,    -1,    65,
      -1,    74,    42,    74,    -1,    74,    41,    74,    -1,    74,
      52,    79,    53,    -1,    32,    -1,    45,    74,    -1,    49,
      74,    -1,    24,    15,    15,    -1,    24,    74,    76,    -1,
      24,    76,    74,    -1,    24,    76,    76,    -1,     8,    -1,
       9,    -1,    10,    -1,    11,    -1,    12,    -1,    14,    -1,
      37,    -1,    36,    -1,    34,    -1,    35,    -1,    56,    58,
      -1,    56,    79,    58,    -1,    74,    -1,    79,    59,    74,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    78,    78,    81,    82,    89,    91,    92,    93,    97,
     101,   108,   112,   116,   120,   123,   124,   129,   134,   137,
     146,   148,   153,   154,   155,   156,   159,   163,   167,   173,
     174,   178,   182,   188,   192,   196,   201,   206,   210,   217,
     222,   230,   233,   239,   242,   245,   247,   249,   253,   257,
     261,   265,   269,   273,   277,   281,   285,   289,   293,   295,
     299,   303,   305,   309,   313,   317,   321,   323,   327,   333,
     340,   345,   350,   358,   359,   360,   361,   362,   363,   368,
     369,   370,   371,   376,   377,   381,   384
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
       0,    62,    63,    63,    63,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    65,    65,
      66,    66,    67,    67,    67,    67,    68,    68,    68,    69,
      69,    70,    70,    71,    71,    71,    71,    71,    71,    72,
      72,    73,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    75,
      75,    75,    75,    76,    76,    76,    76,    76,    76,    77,
      77,    77,    77,    78,    78,    79,    79
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     2,     2,     4,     7,
       9,     7,     5,     5,     7,     1,     3,     2,     1,     3,
       3,     1,     1,     1,     1,     1,     7,     8,     6,     2,
       3,     1,     3,     1,     3,    10,     6,     4,     4,     2,
       3,     1,     2,     1,     1,     1,     1,     1,     1,     2,
       3,     3,     3,     3,     2,     2,     3,     3,     3,     3,
       2,     1,     1,     3,     3,     4,     1,     2,     2,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     1,     3,    43,    44,    45,    46,    47,    73,
      74,    75,    76,    77,     0,    78,    48,     0,     0,     0,
       0,     0,     0,    22,    25,    24,    21,    23,    66,     0,
       0,     0,     0,     0,     5,     0,     2,    62,    18,     0,
      15,     0,    33,     0,    61,     0,     0,     0,    76,    77,
       0,     0,    49,     0,     0,     0,    17,    41,     0,    60,
      48,     0,     0,     0,    54,    67,    55,    68,     0,     0,
       0,     7,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     6,     0,    39,     0,     0,     0,    40,
       0,    83,    85,     0,     0,     0,     0,     0,     0,     0,
      16,    42,    69,    70,    71,    72,     0,     0,    58,    19,
      81,    82,    80,    79,    20,    34,    56,    57,    64,    63,
      50,    51,    52,    53,    59,     0,     0,     0,     0,    38,
       0,    37,     0,    84,     0,     0,     0,     0,     0,     0,
       0,    29,     0,    31,     0,    65,     8,     0,     0,     0,
       0,    86,     0,     0,     0,    12,    13,    30,     0,     0,
       0,     0,    36,     0,     0,     0,     0,     0,    32,    28,
       0,     0,     0,     9,     0,    11,    14,    26,     0,    27,
       0,     0,    10,    35
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    57,    37,    38,    39,    40,   107,   142,    41,
      42,    58,    43,    44,    45,   114,    52,    93
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -131
static const yytype_int16 yypact[] =
{
    -131,   262,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
    -131,  -131,    -2,     5,   145,  -131,   -25,   -21,   -18,    -7,
     354,   817,   732,  -131,  -131,  -131,  -131,  -131,  -131,    27,
     817,   817,   817,   817,  -131,   817,  -131,    22,  -131,    34,
    -131,    15,    -8,   974,  -131,    -9,    25,    30,  -131,  -131,
      -6,   298,  -131,   678,   817,   817,  -131,  -131,   408,   -16,
     -12,    67,   786,    38,   -16,    50,   -16,   -16,   728,   175,
     146,  -131,   817,   817,   817,   817,   817,   817,   817,   817,
     817,    88,   817,  -131,   817,  -131,    89,   169,   204,  -131,
      91,  -131,  1010,   -13,   145,    58,   930,   103,   813,   842,
    -131,  -131,  -131,  -131,  1010,  -131,    14,   108,  -131,  -131,
    -131,  -131,  -131,  -131,  -131,  1010,    45,   200,    55,    55,
      82,    82,   -16,   -16,  -131,   -48,   996,    38,   817,  1010,
     817,  1010,    38,  -131,   817,   106,   817,   817,   817,   624,
     624,  -131,    24,  -131,   624,  -131,  -131,   109,   294,    -5,
     110,  1010,   864,   952,   886,  -131,   113,  -131,   177,   462,
     624,   817,  -131,   624,   624,   817,   624,   624,  -131,  -131,
     516,   674,   570,  -131,   908,  -131,  -131,  -131,   817,  -131,
     624,   100,  -131,  -131
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -131,  -131,    -1,  -131,    66,  -131,  -131,  -117,  -131,    83,
    -105,  -130,   -14,  -131,   -10,  -131,  -131,   -80
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      36,   143,   125,   102,    50,   145,    85,    59,    61,    89,
     147,   134,    62,    46,   159,   150,    64,    65,    66,    67,
      47,    68,     9,    10,    11,    48,    49,    94,    15,    86,
     170,    51,    90,   172,    81,    53,    82,    92,    54,    96,
      98,    99,    63,    97,    51,   133,   134,    72,   104,    55,
     149,   103,   105,   168,   134,    69,   162,   101,   115,   116,
     117,   118,   119,   120,   121,   122,   123,    70,    92,    71,
     126,    74,   141,   129,   131,     9,    10,    11,    48,    49,
      87,    15,   157,   158,   135,    88,    75,    76,    77,    78,
      79,    80,    73,    74,   106,    81,    97,    82,    77,    78,
      79,    80,    82,   124,   127,    81,   132,    82,    75,    76,
      77,    78,    79,    80,   148,   136,    92,    81,    85,    82,
     151,    89,   152,   153,   154,    73,    74,    79,    80,   144,
     160,   163,    81,   167,    82,   109,    95,     0,   155,   156,
       0,    75,    76,    77,    78,    79,    80,   171,    97,     0,
      81,   174,    82,     9,    10,    11,    48,    49,   101,    15,
       0,   183,     0,   173,   181,   175,   176,     0,     0,   101,
       0,   101,     4,     5,     6,     7,     8,     0,     0,   182,
     110,   111,   112,   113,    16,     9,    10,    11,    48,    49,
      94,    15,    21,    22,     0,     0,    23,    24,    25,    26,
      27,    28,    23,    24,    25,    26,    27,     4,     5,     6,
       7,     8,     0,    30,    31,     0,    32,     0,    33,    16,
       0,     0,     0,     0,     0,    35,     0,    21,    22,   128,
       0,    23,    24,    25,    26,    27,    28,     0,     0,     0,
       0,    75,    76,    77,    78,    79,    80,     0,    30,    31,
      81,    32,    82,    33,     0,     0,     0,     0,     0,     0,
      35,     0,     2,     3,   130,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,     0,     0,    20,     0,    21,    22,     0,     0,    23,
      24,    25,    26,    27,    28,     0,     0,     0,     0,     0,
      29,     4,     5,     6,     7,     8,    30,    31,     0,    32,
       0,    33,     0,    16,     0,     0,    34,     0,    35,    73,
      74,    21,    22,     0,     0,    23,    24,    25,    26,    27,
      28,     0,     0,     0,     0,    75,    76,    77,    78,    79,
      80,     0,    30,    31,    81,    32,    82,    33,     0,     0,
       0,     0,     0,   161,    35,     0,    91,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,     0,     0,    20,    56,    21,    22,     0,
       0,    23,    24,    25,    26,    27,    28,     0,     0,     0,
       0,     0,    29,     0,     0,     0,     0,     0,    30,    31,
       0,    32,     0,    33,     0,     0,     0,     0,    34,     0,
      35,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,     0,     0,    20,
     100,    21,    22,     0,     0,    23,    24,    25,    26,    27,
      28,     0,     0,     0,     0,     0,    29,     0,     0,     0,
       0,     0,    30,    31,     0,    32,     0,    33,     0,     0,
       0,     0,    34,     0,    35,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,     0,     0,    20,   169,    21,    22,     0,     0,    23,
      24,    25,    26,    27,    28,     0,     0,     0,     0,     0,
      29,     0,     0,     0,     0,     0,    30,    31,     0,    32,
       0,    33,     0,     0,     0,     0,    34,     0,    35,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,     0,     0,    20,   177,    21,
      22,     0,     0,    23,    24,    25,    26,    27,    28,     0,
       0,     0,     0,     0,    29,     0,     0,     0,     0,     0,
      30,    31,     0,    32,     0,    33,     0,     0,     0,     0,
      34,     0,    35,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
       0,    20,   179,    21,    22,     0,     0,    23,    24,    25,
      26,    27,    28,     0,     0,     0,     0,     0,    29,     0,
       0,     0,     0,     0,    30,    31,     0,    32,     0,    33,
       0,     0,     0,     0,    34,     0,    35,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,     0,     0,    20,     0,    21,    22,     0,
       0,    23,    24,    25,    26,    27,    28,     0,     0,     0,
       0,     0,    29,     0,     0,     0,     0,     0,    30,    31,
       0,    32,     0,    33,     0,     0,     0,     0,    34,     0,
      35,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    94,    15,    16,     0,     0,     0,     0,     0,    73,
      74,    21,    22,     0,     0,    23,    24,    25,    26,    27,
      28,     0,     0,     0,     0,    75,    76,    77,    78,    79,
      80,     0,    30,    31,    81,    32,    82,    33,     0,     0,
       0,     0,     0,   178,    35,     4,     5,     6,     7,     8,
       9,    10,    11,    48,    49,     0,    15,    60,     0,     0,
       0,     0,     0,    73,    74,    21,    22,     0,     0,    23,
      24,    25,    26,    27,    28,     0,     0,     0,     0,    75,
      76,    77,    78,    79,    80,     0,    30,    31,    81,    32,
      82,    33,     0,     0,     0,     0,   108,     0,    35,     4,
       5,     6,     7,     8,     9,    10,    11,    48,    49,     0,
      15,    16,     0,     0,     0,     0,     0,     0,     0,    21,
      22,     0,     0,    23,    24,    25,    26,    27,    28,     0,
       4,     5,     6,     7,     8,     0,     0,     0,     0,     0,
      30,    31,    16,    32,     0,    33,     0,     0,    73,    74,
      21,    22,    35,     0,    23,    24,    25,    26,    27,    28,
       0,     0,     0,     0,    75,    76,    77,    78,    79,    80,
       0,    30,    31,    81,    32,    82,    33,    73,    74,     0,
       0,   139,     0,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    75,    76,    77,    78,    79,    80,    73,
      74,     0,    81,     0,    82,     0,     0,     0,     0,     0,
     140,     0,     0,     0,     0,    75,    76,    77,    78,    79,
      80,    73,    74,     0,    81,     0,    82,     0,     0,     0,
       0,     0,   164,     0,     0,     0,     0,    75,    76,    77,
      78,    79,    80,    73,    74,     0,    81,     0,    82,     0,
       0,     0,     0,     0,   166,     0,     0,     0,     0,    75,
      76,    77,    78,    79,    80,    73,    74,     0,    81,     0,
      82,     0,     0,     0,     0,     0,   180,     0,     0,     0,
       0,    75,    76,    77,    78,    79,    80,    73,    74,     0,
      81,     0,    82,     0,     0,   137,     0,   138,     0,     0,
       0,     0,     0,    75,    76,    77,    78,    79,    80,    73,
      74,     0,    81,     0,    82,     0,     0,     0,     0,   165,
       0,     0,     0,     0,     0,    75,    76,    77,    78,    79,
      80,    73,    74,     0,    81,     0,    82,     0,    83,    84,
       0,     0,     0,     0,     0,    73,    74,    75,    76,    77,
      78,    79,    80,     0,     0,     0,    81,     0,    82,     0,
     146,    75,    76,    77,    78,    79,    80,     0,     0,     0,
      81,     0,    82
};

static const yytype_int16 yycheck[] =
{
       1,   106,    82,    15,    14,    53,    15,    21,    22,    15,
     127,    59,    22,    15,   144,   132,    30,    31,    32,    33,
      15,    35,     8,     9,    10,    11,    12,    13,    14,    38,
     160,    56,    38,   163,    50,    56,    52,    51,    56,    53,
      54,    55,    15,    53,    56,    58,    59,    55,    62,    56,
     130,    61,    62,   158,    59,    33,    61,    58,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    33,    82,    54,
      84,    26,    58,    87,    88,     8,     9,    10,    11,    12,
      55,    14,    58,    59,    94,    55,    41,    42,    43,    44,
      45,    46,    25,    26,    56,    50,   106,    52,    43,    44,
      45,    46,    52,    15,    15,    50,    15,    52,    41,    42,
      43,    44,    45,    46,   128,    57,   130,    50,    15,    52,
     134,    15,   136,   137,   138,    25,    26,    45,    46,    21,
      21,    21,    50,    20,    52,    69,    53,    -1,   139,   140,
      -1,    41,    42,    43,    44,    45,    46,   161,   158,    -1,
      50,   165,    52,     8,     9,    10,    11,    12,   159,    14,
      -1,    61,    -1,   164,   178,   166,   167,    -1,    -1,   170,
      -1,   172,     3,     4,     5,     6,     7,    -1,    -1,   180,
      34,    35,    36,    37,    15,     8,     9,    10,    11,    12,
      13,    14,    23,    24,    -1,    -1,    27,    28,    29,    30,
      31,    32,    27,    28,    29,    30,    31,     3,     4,     5,
       6,     7,    -1,    44,    45,    -1,    47,    -1,    49,    15,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    23,    24,    60,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    46,    -1,    44,    45,
      50,    47,    52,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,     0,     1,    60,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    -1,    21,    -1,    23,    24,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      38,     3,     4,     5,     6,     7,    44,    45,    -1,    47,
      -1,    49,    -1,    15,    -1,    -1,    54,    -1,    56,    25,
      26,    23,    24,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,    -1,    44,    45,    50,    47,    52,    49,    -1,    -1,
      -1,    -1,    -1,    59,    56,    -1,    58,     3,     4,     5,
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
      16,    17,    18,    -1,    -1,    21,    -1,    23,    24,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    44,    45,
      -1,    47,    -1,    49,    -1,    -1,    -1,    -1,    54,    -1,
      56,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    25,
      26,    23,    24,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,    -1,    44,    45,    50,    47,    52,    49,    -1,    -1,
      -1,    -1,    -1,    59,    56,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    14,    15,    -1,    -1,
      -1,    -1,    -1,    25,    26,    23,    24,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    41,
      42,    43,    44,    45,    46,    -1,    44,    45,    50,    47,
      52,    49,    -1,    -1,    -1,    -1,    58,    -1,    56,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      24,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      44,    45,    15,    47,    -1,    49,    -1,    -1,    25,    26,
      23,    24,    56,    -1,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,    46,
      -1,    44,    45,    50,    47,    52,    49,    25,    26,    -1,
      -1,    58,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    43,    44,    45,    46,    25,
      26,    -1,    50,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,    25,    26,    -1,    50,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    41,    42,    43,
      44,    45,    46,    25,    26,    -1,    50,    -1,    52,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    41,
      42,    43,    44,    45,    46,    25,    26,    -1,    50,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    46,    25,    26,    -1,
      50,    -1,    52,    -1,    -1,    55,    -1,    57,    -1,    -1,
      -1,    -1,    -1,    41,    42,    43,    44,    45,    46,    25,
      26,    -1,    50,    -1,    52,    -1,    -1,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,    25,    26,    -1,    50,    -1,    52,    -1,    54,    55,
      -1,    -1,    -1,    -1,    -1,    25,    26,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    50,    -1,    52,    -1,
      54,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      50,    -1,    52
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    63,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      21,    23,    24,    27,    28,    29,    30,    31,    32,    38,
      44,    45,    47,    49,    54,    56,    64,    65,    66,    67,
      68,    71,    72,    74,    75,    76,    15,    15,    11,    12,
      76,    56,    78,    56,    56,    56,    22,    64,    73,    74,
      15,    74,    76,    15,    74,    74,    74,    74,    74,    33,
      33,    54,    55,    25,    26,    41,    42,    43,    44,    45,
      46,    50,    52,    54,    55,    15,    38,    55,    55,    15,
      38,    58,    74,    79,    13,    71,    74,    76,    74,    74,
      22,    64,    15,    76,    74,    76,    56,    69,    58,    66,
      34,    35,    36,    37,    77,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    15,    79,    74,    15,    60,    74,
      60,    74,    15,    58,    59,    76,    57,    55,    57,    58,
      58,    58,    70,    72,    21,    53,    54,    69,    74,    79,
      69,    74,    74,    74,    74,    64,    64,    58,    59,    73,
      21,    59,    61,    21,    58,    57,    58,    20,    72,    22,
      73,    74,    73,    64,    74,    64,    64,    22,    59,    22,
      58,    74,    64,    61
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
#line 78 "grammar.y"
    {(**(yyvsp[(1) - (2)].Prog_)).addStatement(*(yyvsp[(2) - (2)].Node_));
			(yyval.Prog_)=(yyvsp[(1) - (2)].Prog_); delete (yyvsp[(2) - (2)].Node_);
			root =(yyval.Prog_);;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 81 "grammar.y"
    {/*Здесь будет про ошибку*/;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 82 "grammar.y"
    {(yyval.Prog_)=new std::shared_ptr<language::Statement_list>();
		(*(yyval.Prog_))=std::make_shared<Statement_list>(1);
		root =(yyval.Prog_);;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 89 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
	*(yyval.Node_)=nullptr;;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 91 "grammar.y"
    {(yyval.Node_)=(yyvsp[(1) - (2)].Node_);;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 92 "grammar.y"
    {(yyval.Node_)=(yyvsp[(1) - (2)].Node_);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 93 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
					*(yyval.Node_)=std::make_shared<Assigment_node>(1,*(yyvsp[(1) - (4)].Node_),*(yyvsp[(3) - (4)].Node_));
					delete (yyvsp[(1) - (4)].Node_); delete (yyvsp[(3) - (4)].Node_);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 97 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
					*(yyval.Node_)=std::make_shared<For_loop>(1,*(yyvsp[(3) - (7)].Node_),*(yyvsp[(5) - (7)].Node_),*(yyvsp[(7) - (7)].Node_),true);
					delete (yyvsp[(3) - (7)].Node_); delete (yyvsp[(5) - (7)].Node_); delete (yyvsp[(7) - (7)].Node_);;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 101 "grammar.y"
    {
					(yyval.Node_)=new std::shared_ptr<Node>();
					auto tmp =std::make_shared<Assigment_node>(1,*(yyvsp[(3) - (9)].Node_),*(yyvsp[(5) - (9)].Node_));
					*(yyval.Node_)=std::make_shared<For_loop>(1,tmp,*(yyvsp[(7) - (9)].Node_),*(yyvsp[(9) - (9)].Node_));
					delete (yyvsp[(3) - (9)].Node_); delete (yyvsp[(5) - (9)].Node_); delete (yyvsp[(7) - (9)].Node_);delete (yyvsp[(9) - (9)].Node_);
							;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 108 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
					*(yyval.Node_)=std::make_shared<For_loop>(1,*(yyvsp[(3) - (7)].Node_),*(yyvsp[(5) - (7)].Node_),*(yyvsp[(7) - (7)].Node_));
					delete (yyvsp[(3) - (7)].Node_); delete (yyvsp[(5) - (7)].Node_); delete (yyvsp[(7) - (7)].Node_);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 112 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
					*(yyval.Node_)=std::make_shared<While_loop>(1,*(yyvsp[(3) - (5)].Node_),*(yyvsp[(5) - (5)].Node_));
					delete (yyvsp[(3) - (5)].Node_); delete (yyvsp[(5) - (5)].Node_);;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 116 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
					*(yyval.Node_)=std::make_shared<Condition_expression>(1,*(yyvsp[(3) - (5)].Node_),*(yyvsp[(5) - (5)].Node_));
					delete (yyvsp[(3) - (5)].Node_); delete (yyvsp[(5) - (5)].Node_);;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 120 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
					*(yyval.Node_)=std::make_shared<Condition_expression>(1,*(yyvsp[(3) - (7)].Node_),*(yyvsp[(5) - (7)].Node_),*(yyvsp[(7) - (7)].Node_));
					delete (yyvsp[(3) - (7)].Node_); delete (yyvsp[(5) - (7)].Node_); delete (yyvsp[(7) - (7)].Node_);;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 123 "grammar.y"
    {(yyval.Node_)=(yyvsp[(1) - (1)].Node_);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 124 "grammar.y"
    {
		(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=*(yyvsp[(2) - (3)].Prog_);
		delete (yyvsp[(2) - (3)].Prog_);
		;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 129 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
	*(yyval.Node_)=nullptr;;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 134 "grammar.y"
    {(yyval.cmd_lst)=new std::shared_ptr<Command_list>();
			*(yyval.cmd_lst)= std::make_shared<Command_list>(1,*(yyvsp[(1) - (1)].cmd));
			delete (yyvsp[(1) - (1)].cmd);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 137 "grammar.y"
    {
				auto cmd = (*((yyvsp[(3) - (3)].cmd))).front();
				(*(yyvsp[(1) - (3)].cmd_lst))->addCommand(cmd.first, cmd.second);
				(yyval.cmd_lst)=(yyvsp[(1) - (3)].cmd_lst);
				delete (yyvsp[(3) - (3)].cmd);
					;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 146 "grammar.y"
    {(yyval.cmd) = new std::list<std::pair<language::Commands, std::optional<Sides>>>();
			(*(yyval.cmd)).push_back(std::make_pair((yyvsp[(1) - (3)].commands),(yyvsp[(3) - (3)].sides)));;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 148 "grammar.y"
    {(yyval.cmd) = new std::list<std::pair<language::Commands, std::optional<Sides>>>();
			(*(yyval.cmd)).push_back(std::make_pair((yyvsp[(1) - (1)].commands),std::nullopt));;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 153 "grammar.y"
    {(yyval.commands)=(yyvsp[(1) - (1)].commands);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 154 "grammar.y"
    {(yyval.commands)=(yyvsp[(1) - (1)].commands);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 155 "grammar.y"
    {(yyval.commands)=(yyvsp[(1) - (1)].commands);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 156 "grammar.y"
    {(yyval.commands)=(yyvsp[(1) - (1)].commands);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 159 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
					*(yyval.Node_)=std::make_shared<FunDeclaration_expression>(1,*(yyvsp[(3) - (7)].string),*(yyvsp[(4) - (7)].params_),*(yyvsp[(6) - (7)].Prog_),(yyvsp[(1) - (7)].types_));
					delete (yyvsp[(3) - (7)].string); delete (yyvsp[(4) - (7)].params_); delete (yyvsp[(6) - (7)].Prog_);;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 163 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
					*(yyval.Node_)=std::make_shared<FunDeclaration_expression>(1,*(yyvsp[(4) - (8)].string),*(yyvsp[(5) - (8)].params_),*(yyvsp[(7) - (8)].Prog_),(yyvsp[(2) - (8)].types_),true);
					delete (yyvsp[(4) - (8)].string); delete (yyvsp[(5) - (8)].params_); delete (yyvsp[(7) - (8)].Prog_);;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 167 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
					*(yyval.Node_)=std::make_shared<FunDeclaration_expression>(1,*(yyvsp[(2) - (6)].string),*(yyvsp[(3) - (6)].params_),*(yyvsp[(5) - (6)].Prog_));
					delete (yyvsp[(2) - (6)].string); delete (yyvsp[(3) - (6)].params_); delete (yyvsp[(5) - (6)].Prog_);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 173 "grammar.y"
    {(yyval.params_)=new std::list<language::fparam>();;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 174 "grammar.y"
    {(yyval.params_)=(yyvsp[(2) - (3)].params_);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 178 "grammar.y"
    {(yyval.params_)=new std::list<language::fparam>();
		(yyval.params_)->push_back(*(yyvsp[(1) - (1)].fparam_));
		delete (yyvsp[(1) - (1)].fparam_);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 182 "grammar.y"
    {(yyvsp[(1) - (3)].params_)->push_back(*(yyvsp[(3) - (3)].fparam_));
			delete (yyvsp[(3) - (3)].fparam_);;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 188 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<VarDeclaration_expression>(1,(yyvsp[(1) - (1)].fparam_)->name,(yyvsp[(1) - (1)].fparam_)->type, (yyvsp[(1) - (1)].fparam_)->isPtr);
		delete (yyvsp[(1) - (1)].fparam_);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 192 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<VarDeclaration_expression>(1,(yyvsp[(1) - (3)].fparam_)->name,(yyvsp[(1) - (3)].fparam_)->type, (yyvsp[(1) - (3)].fparam_)->isPtr, *(yyvsp[(3) - (3)].Node_));
		delete (yyvsp[(1) - (3)].fparam_); delete (yyvsp[(3) - (3)].Node_);;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 196 "grammar.y"
    {
		(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<SquareDecl>(1,*(yyvsp[(2) - (10)].string),*(yyvsp[(5) - (10)].Node_),*(yyvsp[(7) - (10)].Node_),*(yyvsp[(9) - (10)].Node_));
		delete (yyvsp[(2) - (10)].string); delete (yyvsp[(5) - (10)].Node_); delete (yyvsp[(7) - (10)].Node_); delete (yyvsp[(9) - (10)].Node_);
								;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 201 "grammar.y"
    {
		(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<ArrDecl>(1,*(yyvsp[(2) - (6)].string),(yyvsp[(5) - (6)].operands_));
		delete (yyvsp[(2) - (6)].string);}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 206 "grammar.y"
    {
		(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<VarDeclaration_expression>(1,*(yyvsp[(2) - (4)].string),language::Types::ARRAY, false, *(yyvsp[(4) - (4)].Node_));
		delete (yyvsp[(2) - (4)].string);delete (yyvsp[(4) - (4)].Node_);;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 210 "grammar.y"
    {
		(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<VarDeclaration_expression>(1,*(yyvsp[(2) - (4)].string),language::Types::SQUARE, false, *(yyvsp[(4) - (4)].Node_));
		delete (yyvsp[(2) - (4)].string); delete (yyvsp[(4) - (4)].Node_);;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 217 "grammar.y"
    {(yyval.fparam_)=new fparam();
			(yyval.fparam_)->type=(yyvsp[(1) - (2)].types_);
			(yyval.fparam_)->name=*(yyvsp[(2) - (2)].string);
			(yyval.fparam_)->isPtr=false;
			delete (yyvsp[(2) - (2)].string);;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 222 "grammar.y"
    {(yyval.fparam_)=new fparam();
			(yyval.fparam_)->type=(yyvsp[(2) - (3)].types_);
			(yyval.fparam_)->name=*(yyvsp[(3) - (3)].string);
			(yyval.fparam_)->isPtr=true;
			delete (yyvsp[(3) - (3)].string);;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 230 "grammar.y"
    {(yyval.Prog_)=new std::shared_ptr<language::Statement_list>();
		*(yyval.Prog_)=std::make_shared<language::Statement_list>(1,*(yyvsp[(1) - (1)].Node_));
		delete (yyvsp[(1) - (1)].Node_);;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 233 "grammar.y"
    {(*(yyvsp[(1) - (2)].Prog_))->addStatement(*(yyvsp[(2) - (2)].Node_));
			(yyval.Prog_)=(yyvsp[(1) - (2)].Prog_);
			delete (yyvsp[(2) - (2)].Node_);;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 239 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Literal<int>>((yyvsp[(1) - (1)].ival),language::Types::INT,1);;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 242 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Literal<float>>((yyvsp[(1) - (1)].fval),language::Types::FLOAT,1);;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 245 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Literal<bool>>((yyvsp[(1) - (1)].bval),language::Types::BOOL,1);;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 247 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Literal<char>>((yyvsp[(1) - (1)].ch_),language::Types::BYTE,1);;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 249 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<constString>(*(yyvsp[(1) - (1)].string),1);
		delete (yyvsp[(1) - (1)].string);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 253 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Var>(*(yyvsp[(1) - (1)].string),1);
		delete (yyvsp[(1) - (1)].string);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 257 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Function_call>(1, *(yyvsp[(1) - (2)].string),(yyvsp[(2) - (2)].operands_));
		delete (yyvsp[(1) - (2)].string);;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 261 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Addittion_expression>(1, *(yyvsp[(1) - (3)].Node_),*(yyvsp[(3) - (3)].Node_));
		delete (yyvsp[(1) - (3)].Node_); delete(yyvsp[(3) - (3)].Node_);;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 265 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Substract_expression>(1, *(yyvsp[(1) - (3)].Node_),*(yyvsp[(3) - (3)].Node_));
		delete (yyvsp[(1) - (3)].Node_); delete(yyvsp[(3) - (3)].Node_);;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 269 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Multiply_expression>(1, *(yyvsp[(1) - (3)].Node_),*(yyvsp[(3) - (3)].Node_));
		delete (yyvsp[(1) - (3)].Node_); delete(yyvsp[(3) - (3)].Node_);;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 273 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Divide_expression>(1, *(yyvsp[(1) - (3)].Node_),*(yyvsp[(3) - (3)].Node_));
		delete (yyvsp[(1) - (3)].Node_); delete(yyvsp[(3) - (3)].Node_);;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 277 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<UnaryMinus_expression>(1, *(yyvsp[(2) - (2)].Node_));
		delete (yyvsp[(2) - (2)].Node_);;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 281 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<LogicInversion_expression>(1, *(yyvsp[(2) - (2)].Node_));
		delete (yyvsp[(2) - (2)].Node_);;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 285 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Disjunction_expression>(1, *(yyvsp[(1) - (3)].Node_),*(yyvsp[(3) - (3)].Node_));
		delete (yyvsp[(1) - (3)].Node_); delete(yyvsp[(3) - (3)].Node_);;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 289 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Conjunction_expression>(1, *(yyvsp[(1) - (3)].Node_),*(yyvsp[(3) - (3)].Node_));
		delete (yyvsp[(1) - (3)].Node_); delete(yyvsp[(3) - (3)].Node_);;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 293 "grammar.y"
    {(yyval.Node_)=(yyvsp[(2) - (3)].Node_);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 295 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<FieldAccess_expression>(1, *(yyvsp[(3) - (3)].string),*(yyvsp[(1) - (3)].Node_));
		delete (yyvsp[(1) - (3)].Node_); delete(yyvsp[(3) - (3)].string);;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 299 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<DimensionOperator>(1, *(yyvsp[(2) - (2)].Node_));
		delete (yyvsp[(2) - (2)].Node_);;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 303 "grammar.y"
    {(yyval.Node_)=(yyvsp[(1) - (1)].Node_);;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 305 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
			*(yyval.Node_)=*(yyvsp[(1) - (1)].cmd_lst);
			delete (yyvsp[(1) - (1)].cmd_lst);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 309 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<More_expression>(1, *(yyvsp[(1) - (3)].Node_),*(yyvsp[(3) - (3)].Node_));
		delete (yyvsp[(1) - (3)].Node_); delete(yyvsp[(3) - (3)].Node_);;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 313 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Less_expression>(1, *(yyvsp[(1) - (3)].Node_),*(yyvsp[(3) - (3)].Node_));
		delete (yyvsp[(1) - (3)].Node_); delete(yyvsp[(3) - (3)].Node_);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 317 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<ArrayIndaxation_expression>(1, *(yyvsp[(1) - (4)].Node_),*(yyvsp[(3) - (4)].operands_));
		delete (yyvsp[(1) - (4)].Node_); delete(yyvsp[(3) - (4)].operands_);;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 321 "grammar.y"
  {(yyval.Node_) = new std::shared_ptr<Node>();
  *(yyval.Node_) = std::make_shared<Where_operator>(1);; }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 323 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<StarOperator>(1, *(yyvsp[(2) - (2)].Node_));
		delete (yyvsp[(2) - (2)].Node_);;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 327 "grammar.y"
    {(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<Pointer_get_expr>(1, *(yyvsp[(2) - (2)].Node_));
		delete (yyvsp[(2) - (2)].Node_);;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 333 "grammar.y"
    {
		auto ex1 = std::make_shared<Var>(*(yyvsp[(2) - (3)].string),1);
		auto ex2 = std::make_shared<Var>(*(yyvsp[(3) - (3)].string),1);
		delete (yyvsp[(2) - (3)].string); delete (yyvsp[(3) - (3)].string);
		(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<TypeCheck_expression>(1,ex1,ex2);
		;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 340 "grammar.y"
    {
		(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<TypeCheck_expression>(1,*(yyvsp[(2) - (3)].Node_),(yyvsp[(3) - (3)].types_));
		delete (yyvsp[(2) - (3)].Node_);
		;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 345 "grammar.y"
    {
		(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<TypeCheck_expression>(1,*(yyvsp[(3) - (3)].Node_),(yyvsp[(2) - (3)].types_));
		delete (yyvsp[(3) - (3)].Node_);
		;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 350 "grammar.y"
    {
		(yyval.Node_)=new std::shared_ptr<Node>();
		*(yyval.Node_)=std::make_shared<TypeCheck_expression>(1,(yyvsp[(2) - (3)].types_),(yyvsp[(3) - (3)].types_));
		;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 358 "grammar.y"
    {(yyval.types_)=(yyvsp[(1) - (1)].types_);;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 359 "grammar.y"
    {(yyval.types_)=(yyvsp[(1) - (1)].types_);;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 360 "grammar.y"
    {(yyval.types_)=(yyvsp[(1) - (1)].types_);;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 361 "grammar.y"
    {(yyval.types_)=(yyvsp[(1) - (1)].types_);;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 362 "grammar.y"
    {(yyval.types_)=(yyvsp[(1) - (1)].types_);;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 363 "grammar.y"
    {(yyval.types_)=(yyvsp[(1) - (1)].types_);;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 368 "grammar.y"
    {(yyval.sides)=(yyvsp[(1) - (1)].sides);;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 369 "grammar.y"
    {(yyval.sides)=(yyvsp[(1) - (1)].sides);;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 370 "grammar.y"
    {(yyval.sides)=(yyvsp[(1) - (1)].sides);;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 371 "grammar.y"
    {(yyval.sides)=(yyvsp[(1) - (1)].sides);;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 376 "grammar.y"
    {(yyval.operands_) = new std::list<std::shared_ptr<language::Node>>();;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 377 "grammar.y"
    {(yyval.operands_)=(yyvsp[(2) - (3)].operands_);;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 381 "grammar.y"
    {(yyval.operands_) = new std::list<std::shared_ptr<language::Node>>();
	(*(yyval.operands_)).push_back(*(yyvsp[(1) - (1)].Node_));
	delete (yyvsp[(1) - (1)].Node_);;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 384 "grammar.y"
    {
	(yyvsp[(1) - (3)].operands_)->push_back(*(yyvsp[(3) - (3)].Node_));
	(yyval.operands_)=(yyvsp[(1) - (3)].operands_);
	delete (yyvsp[(3) - (3)].Node_);;}
    break;



/* Line 1455 of yacc.c  */
#line 2457 "grammar.tab.cpp"
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
#line 390 "grammar.y"

 
void yyerror(const char* c){
std::string str;
str=c;
std::cout<<str<<std::endl;
}
#include "lex.yy.cpp"

namespace robot {
    bool Robot::AllowScriptExecution = true;
    bool Robot::isOnFly = false;
    Square Robot::position{};
    int Robot::rotation = 0;

    Square Labitinth::exit_{};
    std::vector<std::vector<bool>>Labitinth::walls{};
}
void main(){
    robot::initArea();
 //yydebug = 300;
 for(int i=0;i<1500000; i++){
 fopen_s(&yyin, "pipa.txt", "r");
    yyparse();
    (*root)->initMemory(initStLib());
    (*root)->pass();
	delete root;
	 fclose(yyin);
	}
}
