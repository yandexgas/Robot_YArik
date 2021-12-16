%option noyywrap
%option yylineno

%{
#include"grammar.tab.h"
#include <stdlib.h>
void yyerror(const char*);
%}

%%
[0-9]+\.[0-9]+ { yylloc.last_line=yylloc.first_line=yylineno;
		yylval.fval=atof(yytext);
		return FLOATNUM;}
[0-9]+ {yylval.ival=atoi(yytext);
	return INTNUM; }
(istino)/[^a-zA-Z0-9_] {yylloc.last_line=yylloc.first_line=yylineno;
			yylval.bval = true;
				return ISTINO;}
(lozhno)/[^a-zA-Z0-9_] {yylloc.last_line=yylloc.first_line=yylineno;
			yylval.bval = false;
				return ISTINO;}
(tseloye)/[^a-zA-Z0-9_] {yylloc.last_line=yylloc.first_line=yylineno;
			yylval.types_= language::Types::INT;
				return TSELOYE;}
(drobnoye)/[^a-zA-Z0-9_] {yylloc.last_line=yylloc.first_line=yylineno;
			yylval.types_= language::Types::FLOAT;
				return DROBNOYE;}
(logicheskoye)/[^a-zA-Z0-9_] {yylloc.last_line=yylloc.first_line=yylineno;
			yylval.types_= language::Types::BOOL;
				return LOGICHESKOYE;}
(simvol)/[^a-zA-Z0-9_] {yylloc.last_line=yylloc.first_line=yylineno;
			yylval.types_= language::Types::BYTE;
				return SIMVOL;}
(yacheyka)/[^a-zA-Z0-9_] {yylloc.last_line=yylloc.first_line=yylineno;
			yylval.types_= language::Types::SQUARE;
				return YACHEYKA;}
(massiv)/[^a-zA-Z0-9_] {yylloc.last_line=yylloc.first_line=yylineno;
			yylval.types_= language::Types::ARRAY;
				return MASSIV;}
(ukazatel)/[^a-zA-Z0-9_] {yylloc.last_line=yylloc.first_line=yylineno;
			return PTR;}
(esli)/[^a-zA-Z0-9_] {yylloc.last_line=yylloc.first_line=yylineno;
			return IF;}
(inache)/[^a-zA-Z0-9_] {yylloc.last_line=yylloc.first_line=yylineno;
			return ELSE;}
(poka)/[^a-zA-Z0-9_] {yylloc.last_line=yylloc.first_line=yylineno;
			return WHILE;}
(tsikl)/[^a-zA-Z0-9_] {yylloc.last_line=yylloc.first_line=yylineno;
			return FOR;}
(nachalo)/[^a-zA-Z0-9_] {yylloc.last_line=yylloc.first_line=yylineno;
			return BEGIN_;}
(konets)/([^a-zA-Z0-9_]|<EOF>) {yylloc.last_line=yylloc.first_line=yylineno;
			return END;}
(konets)$ {yylloc.last_line=yylloc.first_line=yylineno;
			return END;}
(razmer)/[^a-zA-Z0-9_] {yylloc.last_line=yylloc.first_line=yylineno;
			return RAZMER;}
(proverka)/[^a-zA-Z0-9_] {yylloc.last_line=yylloc.first_line=yylineno;
			return PROVERKA;}
(\|\|) {yylloc.last_line=yylloc.first_line=yylineno;
			return OR;}
(\&\&) {yylloc.last_line=yylloc.first_line=yylineno;
			return AND;}
(idi)/[^a-zA-Z0-9_] {yylloc.last_line=yylloc.first_line=yylineno;
			yylval.commands=language::Commands::GO;
			return IDI;}
(poverni)/[^a-zA-Z0-9_] {yylloc.last_line=yylloc.first_line=yylineno;
			yylval.commands=language::Commands::ROTATE;
			return POVERNI;}
(vzleti)/[^a-zA-Z0-9_] {yylloc.last_line=yylloc.first_line=yylineno;
			yylval.commands=language::Commands::FLY;
			return VZLETI;}
(ostanov)/[^a-zA-Z0-9_] {yylloc.last_line=yylloc.first_line=yylineno;
			yylval.commands=language::Commands::STOP;
			return OSTANOV;}
(gdeya\?) {yylloc.last_line=yylloc.first_line=yylineno;
			return GDEYA;}
(smotri)/[^a-zA-Z0-9_] {yylloc.last_line=yylloc.first_line=yylineno;
			yylval.commands=language::Commands::LOOK;
			return SMOTRI;}
(->) {yylloc.last_line=yylloc.first_line=yylineno;
			return ARROW;}
((v|na)?pered)/[^a-zA-Z0-9_] {yylloc.last_line=yylloc.first_line=yylineno;
			yylval.sides=language::Sides::FRONT;
				return  PERED;}
((v|na)?zad)/[^a-zA-Z0-9_] {yylloc.last_line=yylloc.first_line=yylineno;
			yylval.sides=language::Sides::BACK;
				return  ZAD;}
((v|na)?pravo)/[^a-zA-Z0-9_] {yylloc.last_line=yylloc.first_line=yylineno;
			yylval.sides=language::Sides::RIGHT;
				return  PRAVO;}
((v|na)?levo)/[^a-zA-Z0-9_] {yylloc.last_line=yylloc.first_line=yylineno;
			yylval.sides=language::Sides::LEFT;
				return  LEVO;}
(funktsiya)/[^a-zA-Z0-9_] {yylloc.last_line=yylloc.first_line=yylineno;
			return FUNC;}
(\#vkluchit)/[^a-zA-Z0-9_] {yylloc.last_line=yylloc.first_line=yylineno;
			return VCLUCHIT;}
(adr)/[^a-zA-Z0-9_] {yylloc.last_line=yylloc.first_line=yylineno;
			return ADR;}
(=>) {yylloc.last_line=yylloc.first_line=yylineno;
			return FIELD_OPER;}
[<=>+/\-*~\[\],\(\);\{\}:] {yylloc.last_line=yylloc.first_line=yylineno;
			return *yytext;}
'[^']' {yylloc.last_line=yylloc.first_line=yylineno;
			yylval.ch_=*(yytext+1);
	return CHAR;}
'\\n' {yylloc.last_line=yylloc.first_line=yylineno;
			yylval.ch_='\n';
	return CHAR;}
'\\t' {yylloc.last_line=yylloc.first_line=yylineno;
			yylval.ch_='\t';
	return CHAR;}
'\\0' {yylloc.last_line=yylloc.first_line=yylineno;
			yylval.ch_='\0';
	return CHAR;}
\"[^\"]*\" {yylloc.last_line=yylloc.first_line=yylineno;
			yylval.string = new std::string(yytext+1);
	return CONSTSTRING;}
[a-zA-Z_][a-zA-Z_0-9]* {yylloc.last_line=yylloc.first_line=yylineno;
			yylval.string=new std::string(yytext);
			return name;}

[ \t\n] {};

.	{yylloc.last_line=yylloc.first_line=yylineno;
			return *yytext;}

%%
