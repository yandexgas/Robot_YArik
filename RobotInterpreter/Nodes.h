#pragma once
#include <iostream>
#include <list>
#include <variant>
#include <vector>
#include<string>
#include "robot.h"
namespace language {

	class Node {
	protected:
		std::shared_ptr<MemoryFrame> memTable_;
		std::int16_t lino_;
	public:
		Node(std::int16_t lino) : lino_(lino) {}
		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame>)=0;
		constexpr virtual int priority() const noexcept {
			return 0;
		}
		virtual ~Node() {}
	};

	class Leaf : public Node
	{
	private:
	public:
		Leaf(std::int16_t lino) : Node(lino) {}
		~Leaf() override {};
	};

	template <Ariphmetical_result T>
	class Literal:public Leaf {
	private:
		std::shared_ptr<MemoryCell> value_;
	public:
		Literal(T val,Types t, std::int16_t lino) : Leaf(lino) {
			value_ = std::make_shared<MemoryCell>(std::make_shared<Math_type<T>>(val, t));
		}
		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame>) override { return std::make_shared<MemoryCell>(value_->getData()->makeClone()); }
		~Literal() override {};
	};

	class ConstString : public Leaf {
	private:
		std::shared_ptr<MemoryCell> value_;
	public:
		ConstString(std::string str, std::int16_t lino);
		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame>) override { return value_; }
		~ConstString() override {}
	};

	class Where_operator : public Leaf {
		public:
			Where_operator(std::int16_t lino): Leaf(lino){}
			std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame>) override { return robot::Robot::WhereAmI(); }
	};

	class Var :public Leaf {
	private:
		std::string name;
	public:
		Var(std::string name,std::int16_t lino): Leaf(lino), name(name)  {}
		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame>mem) override;
		~Var() override {};
	};

	class Binary_expression : public Node {
	protected:
		std::shared_ptr<Node> children_[2];
	public:
		Binary_expression(std::int16_t lino, std::shared_ptr<Node> c1, std::shared_ptr<Node> c2);
		~Binary_expression() override{}
	};

	class Addittion_expression : public Binary_expression {
	protected:

	public:
		Addittion_expression(std::int16_t lino, std::shared_ptr<Node> c1, std::shared_ptr<Node> c2) : Binary_expression(lino,c1,c2) {}

		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override;
		~Addittion_expression()override{}
	};

	class Substract_expression : public Binary_expression {
	protected:
	public:
		Substract_expression(std::int16_t lino, std::shared_ptr<Node> c1, std::shared_ptr<Node> c2) : Binary_expression(lino, c1, c2) {}
		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override;
		~Substract_expression() override{}
	};

	class Multiply_expression : public Binary_expression {
	protected:

	public:
		Multiply_expression(std::int16_t lino, std::shared_ptr<Node> c1, std::shared_ptr<Node> c2) : Binary_expression(lino, c1, c2) {}
		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override;
		~Multiply_expression() override{ }
	};

	class Divide_expression : public Binary_expression {
	protected:

	public:
		Divide_expression(std::int16_t lino, std::shared_ptr<Node> c1, std::shared_ptr<Node> c2) : Binary_expression(lino, c1, c2) {}
		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override;
		~Divide_expression() override{}
	};

	class Disjunction_expression : public Binary_expression {
	public:
		Disjunction_expression(std::int16_t lino, std::shared_ptr<Node> c1, std::shared_ptr<Node> c2) : Binary_expression(lino, c1, c2) {}
		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override;
		~Disjunction_expression() override {}
	};

	class Conjunction_expression : public Binary_expression {
	public:
		Conjunction_expression(std::int16_t lino, std::shared_ptr<Node> c1, std::shared_ptr<Node> c2) : Binary_expression(lino, c1, c2) {}
		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override;
		~Conjunction_expression() override {}
	};

	class More_expression : public Binary_expression {
	public:
		More_expression(std::int16_t lino, std::shared_ptr<Node> c1, std::shared_ptr<Node> c2) : Binary_expression(lino, c1, c2) {}
		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override;
		~More_expression() override {}
	};

	class Less_expression : public Binary_expression {
	public:
		Less_expression(std::int16_t lino, std::shared_ptr<Node> c1, std::shared_ptr<Node> c2) : Binary_expression(lino, c1, c2) {}
		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override;
		~Less_expression() override {}
	};

	class FieldAccess_expression : public Node {
	protected:
		YFields field_;
		std::shared_ptr<Node> child_;
	public:
		FieldAccess_expression(std::int16_t lino, std::string field, std::shared_ptr<Node>c);
		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override; 
		~FieldAccess_expression() override {}
	};

	class Unary_expression:public Node {
	protected:
		std::shared_ptr<Node> child_;
	public:
		Unary_expression(std::int16_t lino, std::shared_ptr<Node> child_);
		~Unary_expression() override {};
	};

	class UnaryMinus_expression: public Unary_expression {
	public:
		UnaryMinus_expression(std::int16_t lino, std::shared_ptr<Node> child_): Unary_expression(lino,child_) {}
		
		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override;
		~UnaryMinus_expression() override{}
	};


	class LogicInversion_expression : public Unary_expression {
	private:
	public:
		LogicInversion_expression(std::int16_t lino, std::shared_ptr<Node> child_) : Unary_expression(lino, child_) {}
		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override;
		~LogicInversion_expression() override{}
	};
	
	class TypeCheck_expression : public Node {
		Types t1_;
		Types t2_;
		std::shared_ptr<Node> c1_;
		std::shared_ptr<Node> c2_;
	public:
		TypeCheck_expression(std::int16_t lino, std::shared_ptr<Node> c1_,std::shared_ptr<Node> c2_ ):Node(lino), c1_(c1_), c2_(c2_){
			if (!c1_ || !c2_)
				throw Script_error("Operand of typecheck missed.");
		}
		TypeCheck_expression(std::int16_t lino, std::shared_ptr<Node> c1_, Types type) :Node(lino), c1_(c1_), t1_(type), c2_(nullptr) {
			if(!c1_)
				throw Script_error("Operand of typecheck missed.");
		}
		TypeCheck_expression(std::int16_t lino, Types  t1, Types t2) :Node(lino), t1_(t1), t2_(t2), c1_(nullptr),c2_(nullptr) {}
	
		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override;
		~TypeCheck_expression()override {}
	};

	class ArrayIndaxation_expression : public Node {
	private:
		std::shared_ptr<Node> children_;
		std::list<std::shared_ptr<Node>> path_;
	public:
		ArrayIndaxation_expression(std::int16_t lino, std::shared_ptr<Node> arrptr, std::list<std::shared_ptr<Node>> index): Node(lino),children_(arrptr), path_(index) {
		if(!children_)
			throw Script_error("array pointer missed.");
		}
		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override;
		~ArrayIndaxation_expression() override{}
	};

	class DimensionOperator :public Unary_expression {
	public:
		DimensionOperator(std::int16_t lino, std::shared_ptr<Node> arrptr) : Unary_expression(lino, arrptr) {}
		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override;
	};

	class StarOperator :public Unary_expression {
	public:
		StarOperator(std::int16_t lino, std::shared_ptr<Node> arrptr) : Unary_expression(lino, arrptr) {}
		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override;
	};

	class VarDeclaration_expression :public Node {
	private:
		std::shared_ptr<Node> init_expression_;
		std::string name_;
		std::shared_ptr<Variable> var;
	public:
		VarDeclaration_expression(std::int16_t lino, std::string name, Types tp, bool isPtr,std::shared_ptr<Node> init = nullptr): Node(lino),init_expression_(init), name_(name) {
			var = std::make_shared<Variable>(name, tp, isPtr);
		}
		VarDeclaration_expression(std::int16_t lino, std::string name, Types tp, bool isPtr, std::shared_ptr<MemoryCell> init) : Node(lino),name_(name) {
			var = std::make_shared<Variable>(name, tp, isPtr);
			*var = init;
		}
		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override;
		const std::string& getName() {return name_;}
		~VarDeclaration_expression() override {}
	};

	class SquareDecl:public Node {
	private:
		std::shared_ptr<Node> init_expression_[3];
		std::string name_;
	public:
		SquareDecl(std::int16_t lino, std::string name, std::shared_ptr<Node> exp1, std::shared_ptr<Node> exp2, std::shared_ptr<Node> exp3);
		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override;
		const std::string& getName() {return name_;}
		~SquareDecl() override {}
	};

	class ArrDecl :public Node {
	private:
		std::list<std::shared_ptr<language::Node>> operLst_;
		std::string name_;
	public:
		ArrDecl(std::int16_t lino, std::string name, std::list<std::shared_ptr<language::Node>>* operLst) : Node(lino),operLst_(*operLst), name_(name) {
			delete operLst;
		}
		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override;
		const std::string& getName() {return name_;}
		~ArrDecl() override {
		}
	};

	class FunDeclaration_expression :public Node {
	private:
		std::shared_ptr<Node> body_;
		std::string name_;
		bool execute_trigger_ = false;
		std::shared_ptr<Function> fptr_;
		std::list<fparam> params_;
		std::optional<Types> tp_;
		bool isPtr;
	public:
		FunDeclaration_expression(std::int16_t lino, std::string name, std::list<fparam> params, std::shared_ptr<Node> child, std::optional<Types> tp = {}, bool isPtr = false);
		std::optional<std::shared_ptr<MemoryCell>> funcCal(std::list < std::shared_ptr<MemoryCell>>& args);
		constexpr int priority() const noexcept override {return 1;}
		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override;
		~FunDeclaration_expression() override{}
	};

	class Function_call :public Leaf {
	private:
		std::list<std::shared_ptr<language::Node>> params_;
		std::string name_;
	public:
		Function_call(std::int16_t lino, std::string name, std::list<std::shared_ptr<language::Node>>* params) : Leaf(lino), params_(*params), name_(name) {
			delete params;
		}
		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override;
		~Function_call() override {};
	};

	class Assigment_node :public Binary_expression {
	public:
		Assigment_node(std::int16_t lino, std::shared_ptr<Node> c1, std::shared_ptr<Node> c2) : Binary_expression(lino, c1,c2) {}
		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override;
	};
	
	class For_loop :public Node {
	private:
		std::shared_ptr<Node> fst_conditon_;
		std::shared_ptr<Node> last_conditon_;
		std::shared_ptr<Node> loop_body_;
	public:
		For_loop(std::int16_t lino, std::shared_ptr<Node> fst_conditon,
			std::shared_ptr<Node> last_conditon,
			std::shared_ptr<Node> loop_body, bool declaration = false);
		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override;
		~For_loop() override {};
	};
	
	class While_loop : public Node {
	private:
		std::shared_ptr<Node> conditon_;
		std::shared_ptr<Node> body_;
	public:
		While_loop(std::int16_t lino, std::shared_ptr<Node> conditon,
		std::shared_ptr<Node> body_ ): Node(lino), conditon_(conditon), body_(body_){
			if (!conditon_) 
				throw Script_error("incorrect tsikl declaration");
		}
		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override;
		~While_loop() override{}
	};

	class Condition_expression : public Node {
	private:
		std::shared_ptr<Node> conditon_;
		std::shared_ptr<Node> body_;
		std::shared_ptr<Node> else_body_;
	public:
		Condition_expression(std::int16_t lino, std::shared_ptr<Node> conditon,
			std::shared_ptr<Node> body_, std::shared_ptr<Node> else_=nullptr) : Node(lino), conditon_(conditon), body_(body_), else_body_(else_) 
		{
			if(!body_|| !conditon_)
				throw Script_error("incorrect IF declaration");
		}
		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override;
		~Condition_expression() override {}
	};

	class Pointer_get_expr :public Node {
	private:
		std::shared_ptr<Node> ptr_;
	public:
		Pointer_get_expr(std::int16_t lino, std::shared_ptr<Node> ptr): Node(lino), ptr_(ptr){
			if(!ptr)
				throw Script_error("right operand of GET POINTER missed");
		}
		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override;
		~Pointer_get_expr() override {}
	};

	class Command_list : public Node {
	private:
		std::list<std::pair<Commands, std::optional<Sides>>> command_que_;
	public:
		Command_list(std::int16_t lino, std::list<std::pair<Commands, std::optional<Sides>>>& lst): Node(lino),command_que_(lst){}
		void addCommand(Commands cmd, std::optional<Sides> sd = {});

		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override;
		~Command_list() override {}
	};

	class Statement_list :public Node {
	private:
		std::list<std::shared_ptr<Node>> santenceLst_;
	public:
		Statement_list(std::int16_t lino, std::shared_ptr<Node> santance) :Node(lino) {
			if(santance)
				santenceLst_.push_back(santance);
		}
		Statement_list(std::int16_t lino) :Node(lino) {}
		void addStatement(std::shared_ptr<Node> santance);
		std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override;
		void initMemory(std::shared_ptr<MemoryFrame> global = nullptr) {
			memTable_ = std::make_shared<MemoryFrame>(global);
		}
		void pass() {
			pass(memTable_);
		}
		~Statement_list() override{}
	};
}
