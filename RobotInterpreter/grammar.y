%{
	#include "Nodes.h"
	using namespace language;
	std::shared_ptr<Statement_list>* root;
	int yylex(void);
	void yyerror (const char*);
%}

%union{

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
}

%token <ival> INTNUM <fval> FLOATNUM <bval> ISTINO <ch_> CHAR <string> CONSTSTRING
%token <types_> TSELOYE <types_> DROBNOYE <types_> LOGICHESKOYE <types_> YACHEYKA <types_> MASSIV PTR <types_> SIMVOL
%token <string> name
%token FOR WHILE IF
%nonassoc IFX
%nonassoc ELSE
%token BEGIN_ END
%token RAZMER
%token PROVERKA
%left OR
%left AND
%token <commands>IDI <commands>POVERNI <commands>VZLETI <commands>OSTANOV <commands>SMOTRI
%token GDEYA
%left ARROW
%token <sides> PERED  <sides> ZAD  <sides> PRAVO  <sides> LEVO
%token FUNC
%token VCLUCHIT
%token <string> FILEPATH
%left '<' '>'
%left '+' '-'
%left '*' '/'
%right UMINUS '~' RAZMER
%right  ADR
%left FIELD_OPER
%right STAR
%nonassoc '[' ']'

%type <commands> command_word
%type <fparam_> arg
%type <Node_> expr
%type <Node_> check
%type <sides> side
%type <Node_> stmt
%type <Node_> decl
%type <Node_> fdecl
%type <operands_> operands
%type <operands_> oper_list
%type <params_>args
%type <params_>arglst
%type <cmd> robot_command
%type <cmd_lst> robot_oper
%type <Prog_> stmt_lst
%type <types_> type
%type <Prog_> program

%%

program:
	 program stmt {(**$1).addStatement(*$2);
			$$=$1; delete $2;
			root =$$;}
	| program error {/*Здесь будет про ошибку*/}
	| {$$=new std::shared_ptr<language::Statement_list>();
		(*$$)=std::make_shared<Statement_list>(1);
		root =$$;}
	;


stmt:
	';' {$$=new std::shared_ptr<Node>();
	*$$=nullptr;}
	| expr ';'  {$$=$1;}
	| decl ';'  {$$=$1;}
	| expr '=' expr ';' %prec IF {$$=new std::shared_ptr<Node>();
					*$$=std::make_shared<Assigment_node>(1,*$1,*$3);
					delete $1; delete $3;}

	| FOR '(' decl ':' expr ')' stmt {$$=new std::shared_ptr<Node>();
					*$$=std::make_shared<For_loop>(1,*$3,*$5,*$7,true);
					delete $3; delete $5; delete $7;}

	| FOR '(' expr '=' expr ':' expr ')' stmt {
					$$=new std::shared_ptr<Node>();
					auto tmp =std::make_shared<Assigment_node>(1,*$3,*$5);
					*$$=std::make_shared<For_loop>(1,tmp,*$7,*$9);
					delete $3; delete $5; delete $7;delete $9;
							}

	| FOR '(' expr ':' expr ')' stmt {$$=new std::shared_ptr<Node>();
					*$$=std::make_shared<For_loop>(1,*$3,*$5,*$7);
					delete $3; delete $5; delete $7;}

	| WHILE '(' expr ')' stmt {$$=new std::shared_ptr<Node>();
					*$$=std::make_shared<While_loop>(1,*$3,*$5);
					delete $3; delete $5;} 

	| IF '(' expr ')' stmt %prec IFX {$$=new std::shared_ptr<Node>();
					*$$=std::make_shared<Condition_expression>(1,*$3,*$5);
					delete $3; delete $5;} 

	| IF '(' expr ')' stmt ELSE stmt {$$=new std::shared_ptr<Node>();
					*$$=std::make_shared<Condition_expression>(1,*$3,*$5,*$7);
					delete $3; delete $5; delete $7;}
	| fdecl {$$=$1;}
	| BEGIN_ stmt_lst END {
		$$=new std::shared_ptr<Node>();
		*$$=*$2;
		delete $2;
		}
	| BEGIN_ END {$$=new std::shared_ptr<Node>();
	*$$=nullptr;}
	;

robot_oper:
	robot_command {$$=new std::shared_ptr<Command_list>();
			*$$= std::make_shared<Command_list>(1,*$1);
			delete $1;}
	| robot_oper ARROW robot_command {
				auto cmd = (*($2)).front;
				(*$1)->addCommand(cmd.first, cmd.second);
				$$=$1;
				delete $3;
					}
	;

robot_command:
	command_word ARROW side {$$ = new std::list<std::pair<language::Commands, std::optional<Sides>>>();
			(*$$).push_back(std::make_pair($1,$3));}
	| OSTANOV {$$ = new std::list<std::pair<language::Commands, std::optional<Sides>>>();
			(*$$).push_back(std::make_pair($1,std::nullopt));}
	;

command_word:
	IDI {$$=$1;}
	| SMOTRI{$$=$1;} 
	| VZLETI {$$=$1;} 
	| POVERNI {$$=$1;}
	;
fdecl:
	type FUNC name arglst BEGIN_ stmt_lst END {$$=new std::shared_ptr<Node>();
					*$$=std::make_shared<FunDeclaration_expression>(1,*$3,*$4,*$6,$1);
					delete $3; delete $4; delete $6;}

	| PTR type FUNC name arglst BEGIN_ stmt_lst END {$$=new std::shared_ptr<Node>();
					*$$=std::make_shared<FunDeclaration_expression>(1,*$4,*$5,*$7,$2,true);
					delete $4; delete $5; delete $7;}

	| FUNC name arglst BEGIN_ stmt_lst END {$$=new std::shared_ptr<Node>();
					*$$=std::make_shared<FunDeclaration_expression>(1,*$2,*$3,*$5);
					delete $2; delete $3; delete $5;}
	;

arglst:
	'(' ')' {$$=new std::list<language::fparam>();}
	| '(' args ')' {$$=$2;}
	;

args:
	arg {$$=new std::list<language::fparam>();
		$$->push_back(*$1);
		delete $1;} 

	| args ',' arg {$1->push_back(*$3);
			delete $3;}
	;


decl:
	arg {$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<VarDeclaration_expression>(1,$1->name,$1->type, $1->isPtr);
		delete $1;}

	| arg '=' expr  {$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<VarDeclaration_expression>(1,$1->name,$1->type, $1->isPtr, *$3);
		delete $1; delete $3;}

	| YACHEYKA name '=' '{' expr ',' expr ',' expr '}' %prec YACHEYKA {
		$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<SquareDecl>(1,*$2,*$5,*$7,*$9);
		delete $2; delete $5; delete $7; delete $9;
								}
	| MASSIV name '=' '{' oper_list '}' %prec MASSIV {
		$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<ArrDecl>(1,*$2,$5);
		delete $2}

	| MASSIV name '=' expr {
		$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<VarDeclaration_expression>(1,*$2,language::Types::ARRAY, false, *$4);
		delete $2;delete $4;}
	| YACHEYKA name '=' expr {
		$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<VarDeclaration_expression>(1,*$2,language::Types::SQUARE, false, *$4);
		delete $2; delete $4;}
	;

arg:
	type name {$$=new fparam();
			$$->type=$1;
			$$->name=*$2;
			$$->isPtr=false;
			delete $2;}
	| PTR type name {$$=new fparam();
			$$->type=$2;
			$$->name=*$3;
			$$->isPtr=true;
			delete $3;}
	;

stmt_lst:
	stmt {$$=new std::shared_ptr<language::Statement_list>();
		*$$=std::make_shared<language::Statement_list>(1,*$1);
		delete $1;} 
	| stmt_lst stmt {*$1.addStatement($2);
			$$=$1;
			delete $2;}
	;

expr:
	INTNUM {$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<Literal<int>>($1,language::Types::INT,1);}

	| FLOATNUM {$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<Literal<float>>($1,language::Types::FLOAT,1);}

	| ISTINO {$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<Literal<bool>>($1,language::Types::BOOL,1);}
	| CHAR	{$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<Literal<char>>($1,language::Types::BYTE,1);}
	| CONSTSTRING {$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<constString>(*$1,1);
		delete $1;}

	| name {$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<Var>(*$1,1);
		delete $1;}

	| name operands {$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<Function_call>(1, *$1,$2);
		delete $1;}

	| expr '+' expr {$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<Addittion_expression>(1, *$1,*$3);
		delete $1; delete$3;}

	| expr '-' expr {$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<Substract_expression>(1, *$1,*$3);
		delete $1; delete$3;}

	| expr '*' expr {$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<Multiply_expression>(1, *$1,*$3);
		delete $1; delete$3;}

	| expr '/' expr {$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<Divide_expression>(1, *$1,*$3);
		delete $1; delete$3;}

	| '-' expr %prec UMINUS {$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<UnaryMinus_expression>(1, *$2);
		delete $2;}

	| '~' expr  {$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<LogicInversion_expression>(1, *$2);
		delete $2;}

	| expr OR expr {$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<Disjunction_expression>(1, *$1,*$3);
		delete $1; delete$3;}

	| expr AND expr  {$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<Conjunction_expression>(1, *$1,*$3);
		delete $1; delete$3;}

	| '(' expr ')' {$$=$2;}

	| expr FIELD_OPER name %prec FIELD_OPER {$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<FieldAccess_expression>(1, *$3,*$1);
		delete $1; delete$3;}

	| RAZMER expr {$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<DimensionOperator>(1, *$2);
		delete $2;}

	| check {$$=$1;}

	| robot_oper {$$=new std::shared_ptr<Node>();
			*$$=*$1;
			delete $1;}

	| expr '>' expr {$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<More_expression>(1, *$1,*$3);
		delete $1; delete$3;}

	| expr '<' expr {$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<Less_expression>(1, *$1,*$3);
		delete $1; delete$3;}

	| expr '['oper_list ']' {$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<ArrayIndaxation_expression>(1, *$1,*$3);
		delete $1; delete$3;}

	| GDEYA {$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<Where_operator>(1);
		}

	| '*' expr %prec STAR {$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<StarOperator>(1, *$2);
		delete $2;}

	| ADR expr {$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<Pointer_get_expr>(1, *$2);
		delete $2;}
	;

check:
	PROVERKA name name {
		auto ex1 = std::make_shared<Var>(*$2,1);
		auto ex2 = std::make_shared<Var>(*$3,1);
		delete $2; delete $3;
		$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<TypeCheck_expression>(1,ex1,ex2);
		}
	| PROVERKA expr type {
		$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<TypeCheck_expression>(1,*$2,$3);
		delete $2;
		}
	| PROVERKA type expr  {
		$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<TypeCheck_expression>(1,*$3,$2);
		delete $3;
		}
	| PROVERKA type type {
		$$=new std::shared_ptr<Node>();
		*$$=std::make_shared<TypeCheck_expression>(1,$2,$3);
		}
	;


type:
	TSELOYE {$$=$1;}
	| DROBNOYE {$$=$1;}
	| LOGICHESKOYE {$$=$1;} 
	| YACHEYKA {$$=$1;}
	| MASSIV {$$=$1;}
	| SIMVOL {$$=$1;}
	;


side:
	LEVO {$$=$1;}
	| PRAVO {$$=$1;}
	| PERED {$$=$1;}
	| ZAD {$$=$1;}
	;


operands:
	'(' ')' {$$ = new std::list<std::shared_ptr<language::Node>>();}
	| '(' oper_list ')' {$$=$2;}
	;

oper_list:
	expr {$$ = new std::list<std::shared_ptr<language::Node>>();
	*$$.push_back(*$1);
	delete $1;} 
	| oper_list ',' expr {
	$1->push_back(*$3);
	$$=$1;
	delete $3;}
	;

%%
 
void yyerror(const char* c){
std::string str;
str=c;
std::cout<<str<<std::endl;
}

void main(){
 
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