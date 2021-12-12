
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

#include "Nodes.h"

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
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



/* Line 1676 of yacc.c  */
#line 114 "grammar.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


