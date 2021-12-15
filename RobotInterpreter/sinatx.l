%option noyywrap


%{
#include"grammar.tab.h"
#include <stdlib.h>
void yyerror(const char*);
%}

%%
[0-9]+\.[0-9]+ {yylval.fval=atof(yytext);
		return FLOATNUM;}
[0-9]+ {yylval.ival=atoi(yytext);
	return INTNUM; }
(istino)/[^a-zA-Z0-9_] {yylval.bval = true;
				return ISTINO;}
(lozhno)/[^a-zA-Z0-9_] {yylval.bval = false;
				return ISTINO;}
(tseloye)/[^a-zA-Z0-9_] {yylval.types_= language::Types::INT;
				return TSELOYE;}
(drobnoye)/[^a-zA-Z0-9_] {yylval.types_= language::Types::FLOAT;
				return DROBNOYE;}
(logicheskoye)/[^a-zA-Z0-9_] {yylval.types_= language::Types::BOOL;
				return LOGICHESKOYE;}
(simvol)/[^a-zA-Z0-9_] {yylval.types_= language::Types::BYTE;
				return SIMVOL;}
(yacheyka)/[^a-zA-Z0-9_] {yylval.types_= language::Types::SQUARE;
				return YACHEYKA;}
(massiv)/[^a-zA-Z0-9_] {yylval.types_= language::Types::ARRAY;
				return MASSIV;}
(ukazatel)/[^a-zA-Z0-9_] {return PTR;}
(esli)/[^a-zA-Z0-9_] {return IF;}
(inache)/[^a-zA-Z0-9_] {return ELSE;}
(poka)/[^a-zA-Z0-9_] {return WHILE;}
(tsikl)/[^a-zA-Z0-9_] {return FOR;}
(nachalo)/[^a-zA-Z0-9_] {return BEGIN_;}
(konets)/([^a-zA-Z0-9_]|<EOF>) {return END;}
(konets)$ {return END;}
(razmer)/[^a-zA-Z0-9_] {return RAZMER;}
(proverka)/[^a-zA-Z0-9_] {return PROVERKA;}
(\|\|) {return OR;}
(\&\&) {return AND;}
(idi)/[^a-zA-Z0-9_] {yylval.commands=language::Commands::GO;
			return IDI;}
(poverni)/[^a-zA-Z0-9_] {yylval.commands=language::Commands::ROTATE;
			return POVERNI;}
(vzletyi)/[^a-zA-Z0-9_] {yylval.commands=language::Commands::FLY;
			return VZLETI;}
(ostanov)/[^a-zA-Z0-9_] {yylval.commands=language::Commands::STOP;
			return OSTANOV;}
(gdeya\?) {return GDEYA;}
(smotri)/[^a-zA-Z0-9_] {yylval.commands=language::Commands::LOOK;
			return SMOTRI;}
(->) {return ARROW;}
((v|na)?pered)/[^a-zA-Z0-9_] {yylval.sides=language::Sides::FRONT;
				return  PERED;}
((v|na)?zad)/[^a-zA-Z0-9_] {yylval.sides=language::Sides::BACK;
				return  ZAD;}
((v|na)?pravo)/[^a-zA-Z0-9_] {yylval.sides=language::Sides::RIGHT;
				return  PRAVO;}
((v|na)?levo)/[^a-zA-Z0-9_] {yylval.sides=language::Sides::LEFT;
				return  LEVO;}
(funktsiya)/[^a-zA-Z0-9_] {return FUNC;}
(\#vkluchit)/[^a-zA-Z0-9_] {return VCLUCHIT;}
(adr)/[^a-zA-Z0-9_] {return ADR;}
(=>) {return FIELD_OPER;}
[<=>+/\-*~\[\],\(\);\{\}:] {return *yytext;}
'[^']' {yylval.ch_=*(yytext+1);
	return CHAR;}
'\\n' {yylval.ch_='\n';
	return CHAR;}
'\\t' {yylval.ch_='\t';
	return CHAR;}
'\\0' {yylval.ch_='\0';
	return CHAR;}
\"[^\"]*\" {yylval.string = new std::string(yytext+1);
	return CONSTSTRING;}
[a-zA-Z_][a-zA-Z_0-9]* {yylval.string=new std::string(yytext);
			return name;}

[ \t\n] {};

.	yyerror(yytext);

%%
