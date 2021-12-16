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
		virtual ~Node() {}
		constexpr virtual int priority() const noexcept {
			return 0;
		}
	};

	class Leaf : public Node
	{
	private:
	public:
		Leaf(std::int16_t lino) : Node(lino) {}
		virtual  ~Leaf() override {};
	};

	template <Ariphmetical_result T>
	class Literal:public Leaf {
	private:
		std::shared_ptr<MemoryCell> value_;
	public:
		Literal(T val,Types t, std::int16_t lino) : Leaf(lino) {
			value_ = std::make_shared<MemoryCell>(std::make_shared<Math_type<T>>(val, t));
		}
		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame>) override { return std::make_shared<MemoryCell>(value_->getData()->makeClone()); }
		virtual  ~Literal() override {};
	};

	class constString : public Leaf {
	private:
		std::shared_ptr<MemoryCell> value_;
	public:
		constString(std::string str, std::int16_t lino) : Leaf(lino) {
			std::vector<int> dim;
			dim.push_back(str.length());
			auto res = std::make_shared<Array>(dim);
			for (int i = 0; i < str.length(); i++)
				*(res->getDataLink()[i]) = std::make_shared<Math_type<char>>(str[i], Types::BYTE);
			*(res->getDataLink()[str.length()-1]) = std::make_shared<Math_type<char>>(0, Types::BYTE);
			value_ = std::make_shared<MemoryCell>(res);
		}
		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame>) override { return value_; }
	};

	class Where_operator : public Leaf {
		public:
			Where_operator(std::int16_t lino): Leaf(lino){}
			virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame>) override { return robot::Robot::WhereAmI(); }
	};

	class Var :public Leaf {
	private:
		std::string name;
	public:
		Var(std::string name,std::int16_t lino): Leaf(lino), name(name)  {}
		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame>mem) override {
			try {
				return  (*mem)[name];
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}
		}
		virtual  ~Var() override {};
	};
	class Binary_expression : public Node {
	protected:
		std::shared_ptr<Node> children_[2];
	public:
		Binary_expression(std::int16_t lino, std::shared_ptr<Node> c1, std::shared_ptr<Node> c2) : Node(lino) {
			if (c1 && c2) {
				children_[0] = c1;
				children_[1] = c2;
			}
			else
				throw Script_error("One of operands of binary operator has been missed", lino_);
		}
		virtual ~Binary_expression() override{}
	};

	class Addittion_expression : public Binary_expression {
	protected:

	public:
		Addittion_expression(std::int16_t lino, std::shared_ptr<Node> c1, std::shared_ptr<Node> c2) : Binary_expression(lino,c1,c2) {}

		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override {
			try {
				auto r1 = children_[0]->pass(mem);
				auto r2 = children_[1]->pass(mem);
				if (r1 && r2)
					return std::make_shared<MemoryCell>(*(r1.value()) + *(r2.value()));
				else
					throw Script_error("One of operands of + has been missed");
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}
		}
		virtual ~Addittion_expression()override{}
	};
	class Substract_expression : public Binary_expression {
	protected:
	public:
		Substract_expression(std::int16_t lino, std::shared_ptr<Node> c1, std::shared_ptr<Node> c2) : Binary_expression(lino, c1, c2) {}
		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override {
			try {
				auto r1 = children_[0]->pass(mem);
				auto r2 = children_[1]->pass(mem);
				if (r1 && r2)
					return std::make_shared<MemoryCell>(*(r1.value()) - *(r2.value()));
				else
					throw Script_error("One of operands of - has been missed");
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}
		}
		virtual ~Substract_expression() override{}
	};

	class Multiply_expression : public Binary_expression {
	protected:

	public:
		Multiply_expression(std::int16_t lino, std::shared_ptr<Node> c1, std::shared_ptr<Node> c2) : Binary_expression(lino, c1, c2) {}
		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override {
			try {
				auto r1 = children_[0]->pass(mem);
				auto r2 = children_[1]->pass(mem);
				if (r1 && r2)
					return std::make_shared<MemoryCell>(*(r1.value()) * *(r2.value()));
				else
					throw Script_error("One of operands of * has been missed");
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}

		}
		virtual ~Multiply_expression() override{ }
	};
	class Divide_expression : public Binary_expression {
	protected:

	public:
		Divide_expression(std::int16_t lino, std::shared_ptr<Node> c1, std::shared_ptr<Node> c2) : Binary_expression(lino, c1, c2) {}
		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override {
			try {
				auto r1 = children_[0]->pass(mem);
				auto r2 = children_[1]->pass(mem);
				if (r1 && r2)
					return std::make_shared<MemoryCell>(*(r1.value()) / *(r2.value()));
				else
					throw Script_error("One of operands of / has been missed");
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}
		}
		virtual ~Divide_expression() override{}
	};
	class Disjunction_expression : public Binary_expression {
	public:
		Disjunction_expression(std::int16_t lino, std::shared_ptr<Node> c1, std::shared_ptr<Node> c2) : Binary_expression(lino, c1, c2) {}
		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override {
			try {
				auto r1 = children_[0]->pass(mem);

				if (r1 && !(bool)*(r1.value()->getData())) {
					auto r2 = children_[1]->pass(mem);
					if (r2)
						return std::make_shared<MemoryCell>(*(r2.value()));
					else
						throw Script_error("One of operands of || has been missed");
				}

				else if (r1)	return std::make_shared<MemoryCell>(*(r1.value()));

				else	throw Script_error("One of operands of || has been missed");
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}
		}
		virtual ~Disjunction_expression() override {}
	};

	class Conjunction_expression : public Binary_expression {
	public:
		Conjunction_expression(std::int16_t lino, std::shared_ptr<Node> c1, std::shared_ptr<Node> c2) : Binary_expression(lino, c1, c2) {}
		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override {
			try {
				auto r1 = children_[0]->pass(mem);
				if (r1 && (bool)*(r1.value()->getData())) {
					auto r2 = children_[1]->pass(mem);
					if (r2)
						return std::make_shared<MemoryCell>(*(r2.value()));
					else
						throw Script_error("One of operands of && has been missed");
				}
				else if (r1)	return std::make_shared<MemoryCell>(*(r1.value()));

				else	throw Script_error("One of operands of && has been missed");
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}
		}
		virtual ~Conjunction_expression() override {}
	};

	class More_expression : public Binary_expression {
	public:
		More_expression(std::int16_t lino, std::shared_ptr<Node> c1, std::shared_ptr<Node> c2) : Binary_expression(lino, c1, c2) {}
		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override {
			try {
				auto r1 = children_[0]->pass(mem);
				auto r2 = children_[1]->pass(mem);
				if (r1 && r2)
					return std::make_shared<MemoryCell>(*(r1.value()) > *(r2.value()));
				else
					throw Script_error("One of operands of > has been missed");
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}
		}
		virtual ~More_expression() override {}
	};

	class Less_expression : public Binary_expression {
	public:
		Less_expression(std::int16_t lino, std::shared_ptr<Node> c1, std::shared_ptr<Node> c2) : Binary_expression(lino, c1, c2) {}
		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override {
			try {
				auto r1 = children_[0]->pass(mem);
				auto r2 = children_[1]->pass(mem);
				if (r1 && r2)
					return std::make_shared<MemoryCell>(*(r1.value()) < *(r2.value()));
				else
					throw Script_error("One of operands of <has been missed");
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}
		}
		virtual ~Less_expression() override {}
	};

	class FieldAccess_expression : public Node {
	protected:
		YFields field_;
		std::shared_ptr<Node> child_;
	public:
		FieldAccess_expression(std::int16_t lino, std::string field, std::shared_ptr<Node>c):Node(lino),child_(c)  {
			try {
				if (field == "x")
					field_ = YFields::X;
				else if (field == "y")
					field_ = YFields::Y;
				else {
					if (field == "busy")
						field_ = YFields::BUSY;
					else throw Script_error("There is no such field in yacheyka.");
				}
				if (!c)
					throw Script_error("left operand of => missed.");
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}
		}

		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override {
			try {
				auto r = child_->pass(mem);
				if (r)
					return std::make_shared<MemoryCell>(field_ <= *(r.value()));
				else
					throw Script_error("One of operands of =>has been missed");
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}
		}
		virtual ~FieldAccess_expression() override {}
	};

	class Unary_expression:public Node {
	protected:
		std::shared_ptr<Node> child_;
	public:
		Unary_expression(std::int16_t lino, std::shared_ptr<Node> child_) : Node(lino), child_(child_) {
			try {
				if (!child_)
					throw Script_error("Operand missed");
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}
		}
	};

	class UnaryMinus_expression: public Unary_expression {
	public:
		UnaryMinus_expression(std::int16_t lino, std::shared_ptr<Node> child_): Unary_expression(lino,child_) {}
		
		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override {
			try {
				auto r = child_->pass(mem);
				if (r)
					return std::make_shared<MemoryCell>(-*(r.value()));
				else
					throw Script_error("One of operands of unary - has been missed");
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}
		}
		virtual ~UnaryMinus_expression() override{}
	};


	class LogicInversion_expression : public Unary_expression {
	private:
	public:
		LogicInversion_expression(std::int16_t lino, std::shared_ptr<Node> child_) : Unary_expression(lino, child_) {}
		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override {
			try {
				auto r = child_->pass(mem);
				if (r)
					return std::make_shared<MemoryCell>(~*(r.value()));
				else
					throw Script_error("One of operands of ~ has been missed");
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}
		}
		virtual ~LogicInversion_expression() override{}
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
	
		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override {
			try {
				if (c1_ && c2_) {
					auto r1 = c1_->pass(mem);
					auto r2 = c2_->pass(mem);
					if (r1 && r2) {
						return std::make_shared<MemoryCell>(MemoryCell::checkTypes(*r1.value(), *r2.value()));
					}
				}
				else if (c1_) {
					auto r = c1_->pass(mem);
					if (r)
						return std::make_shared<MemoryCell>(MemoryCell::checkTypes(*r.value(), t1_));
				}
				else {
					return std::make_shared<MemoryCell>(MemoryCell::checkTypes(t2_, t1_));
				}
				throw Script_error("Incorrect operands for typeCheck");
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}
		}
		virtual ~TypeCheck_expression()override {}
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
		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override {
			try {
				auto r1 = children_->pass(mem);
				std::vector<int> r2;
				for (auto a : path_) {
					auto tmp = a->pass(mem);
					if (tmp)
						r2.push_back((int)*(tmp.value()->getData()));
					else throw Script_error("Incorrect array path.");
				}
				if (!r1)
					throw Script_error("Incorrect array.");
				return std::make_shared<MemoryCell>((*r1.value())[r2]);
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}
		}
		virtual ~ArrayIndaxation_expression() override{}
	};

	class DimensionOperator :public Unary_expression {
	public:
		DimensionOperator(std::int16_t lino, std::shared_ptr<Node> arrptr) : Unary_expression(lino, arrptr) {}
		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override {
			try {
				auto r1 = child_->pass(mem);
				if (r1) {
					return std::make_shared<MemoryCell>((*r1.value()).arrayDimension());
				}
				throw Script_error("Incorrect array.");
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}
		}
	};

	class StarOperator :public Unary_expression {
	public:
		StarOperator(std::int16_t lino, std::shared_ptr<Node> arrptr) : Unary_expression(lino, arrptr) {}
		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override {
			try {
				auto r1 = child_->pass(mem);
				if (r1) {
					return std::make_shared<MemoryCell>(*(*r1.value()));
				}
				throw Script_error("Pointer type expected");
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}
		}
	};

	class VarDeclaration_expression :public Node {
	private:
		std::shared_ptr<Node> init_expression_;
		std::string name_;
		std::shared_ptr<Variable> var;
	public:
		VarDeclaration_expression(std::int16_t lino, std::string name, Types tp, bool isPtr,std::shared_ptr<Node> init = nullptr): Node(lino),init_expression_(init) {
			var = std::make_shared<Variable>(name, tp, isPtr);
			name_ = name;
		}
		VarDeclaration_expression(std::int16_t lino, std::string name, Types tp, bool isPtr, std::shared_ptr<MemoryCell> init) : Node(lino) {
			var = std::make_shared<Variable>(name, tp, isPtr);
			*var = init;
			name_ = name;
		}
		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override {
			try {
				memTable_ = mem;
				memTable_->insert(var);
				if (init_expression_) {
					auto r1 = init_expression_->pass(mem);
					if (r1) {
						*var = r1.value();
					}
					else
						throw Script_error("value expected.");
				}
				return var;
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}
		}
		const std::string& getName() {
			return name_;
		}
		virtual ~VarDeclaration_expression() override {}
	};

	class SquareDecl:public Node {
	private:
		std::shared_ptr<Node> init_expression_[3];
		std::string name_;
		std::shared_ptr<Variable> var;
	public:
		SquareDecl(std::int16_t lino, std::string name, std::shared_ptr<Node> exp1, std::shared_ptr<Node> exp2, std::shared_ptr<Node> exp3) : Node(lino) {
			init_expression_[0] = exp1;
			init_expression_[1] = exp2;
			init_expression_[2] = exp3;
			var = std::make_shared<Variable>(name, Types::SQUARE, false);
			name_ = name;
		}
		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override {
			try {
				memTable_ = mem;
				memTable_->insert(var);
				std::optional < std::shared_ptr<MemoryCell>> tmp[3];
				for (int i = 0; i < 3; i++)
					tmp[i] = init_expression_[i]->pass(mem);
				if (tmp[0] && tmp[1] && tmp[2]) {
					auto yach = std::make_shared<Square>((int)*(tmp[0].value()->getData()), (int)*(tmp[1].value()->getData()), (bool)*(tmp[2].value()->getData()));
					*var = std::make_shared<MemoryCell>(yach);
				}
				else
					throw Script_error("Yacheyka initialization value expected.");
				return std::nullopt;
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}
		}
		const std::string& getName() {
			return name_;
		}
		virtual ~SquareDecl() override {}
	};

	class ArrDecl :public Node {
	private:
		std::list<std::shared_ptr<language::Node>> operLst_;
		std::string name_;
	public:
		ArrDecl(std::int16_t lino, std::string name, std::list<std::shared_ptr<language::Node>>* operLst) : Node(lino),operLst_(*operLst), name_(name) {
			delete operLst;
		}
		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override {
			try {
				memTable_ = mem;
				std::vector<int> tmp;
				for (auto a : operLst_) {
					auto r = a->pass(mem);
					if (r)
						tmp.push_back((int)*(r.value()->getData()));
					else
						throw Script_error("Array initialization expected.");
				}
				auto arr = std::make_shared<Array>(tmp);
				auto var = std::make_shared<Variable>(name_, arr);
				memTable_->insert(var);
				return std::nullopt;
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}
		}
		const std::string& getName() {
			return name_;
		}
		virtual ~ArrDecl() override {
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
		FunDeclaration_expression(std::int16_t lino, std::string name, std::list<fparam> params, std::shared_ptr<Node> child, std::optional<Types> tp = {}, bool isPtr = false) : Node(lino), 
			name_(name), body_(child), params_(params), tp_(tp), isPtr(isPtr) {
			fptr_ = std::make_shared<Function>(params, tp, isPtr);
			fptr_->setPtr(this);		
		}
		std::optional<std::shared_ptr<MemoryCell>> funcCal(std::list < std::shared_ptr<MemoryCell>>& args) {
			try {
				std::shared_ptr<MemoryFrame> stackFrame = std::make_shared<MemoryFrame>(memTable_);
				auto argsIter = args.begin();
				for (auto a : params_) {
					auto varAlloc = std::make_shared<Variable>(a.name, a.type, a.isPtr);
					*varAlloc = (*argsIter++);
					stackFrame->insert(varAlloc);
				}
				std::shared_ptr<Variable> result;
				if (tp_) {
					result = std::make_shared<Variable>("rezultat", tp_.value(), isPtr);
					stackFrame->insert(result);
				}
				if (body_) {
					body_->pass(stackFrame);
					if (tp_)
						return result;
					else
						return std::nullopt;
				}
				else if (tp_)
					throw Script_error("Result value missed.");
				else
					return std::nullopt;
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}
		}
		constexpr virtual int priority() const noexcept override {
			return 1;
		}
		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override {
			try {
				mem->insert(name_, fptr_);
				memTable_ = mem;
				return std::nullopt;
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}
		}
		virtual ~FunDeclaration_expression() override{}
	};

	class Function_call :public Leaf {
	private:
		std::list<std::shared_ptr<language::Node>> params_;
		std::string name_;
	public:
		Function_call(std::int16_t lino, std::string name, std::list<std::shared_ptr<language::Node>>* params) : Leaf(lino), params_(*params), name_(name) {
			delete params;
		}
		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override {
			try {
				std::list<std::shared_ptr<MemoryCell>> tmp;
				for (auto a : params_) {
					if (a) {
						auto tmp2 = a->pass(mem);
						if (tmp2)
							tmp.push_back(tmp2.value());
						else throw Script_error("Incorrect expression. Can't be a parametr");
					}
					else throw Script_error("Incorrect expression. Can't be a parametr");
				}
				fcall fun;
				fun.name = name_;
				fun.arg = tmp;
				auto fptr = (*mem)[fun];
				auto target_func = fptr->getPtr();
				if (target_func)
					return dynamic_cast<FunDeclaration_expression*>(target_func.value())->funcCal(fun.arg);
				else
					return (*std::dynamic_pointer_cast<LibFunction>(fptr))(fun.arg);
			}
			catch(Script_error e ){
				throw Script_error(e, lino_);
			}
		}
		virtual  ~Function_call() override {};
	};

	class Assigment_node :public Binary_expression {
	public:
		Assigment_node(std::int16_t lino, std::shared_ptr<Node> c1, std::shared_ptr<Node> c2) : Binary_expression(lino, c1,c2) {}
		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override {
			try {
				auto r1 = children_[0]->pass(mem);
				auto r2 = children_[1]->pass(mem);
				if (r1 && r2)
					*(r1.value()) = r2.value();
				else throw Script_error("Incorrect operands in assigment expression");
				return r1.value();
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}

		}
		virtual  ~Assigment_node() override {};
	};
	
	class For_loop :public Node {
	private:
		std::shared_ptr<Node> fst_conditon_;
		std::shared_ptr<Node> last_conditon_;
		std::shared_ptr<Node> loop_body_;
	public:
		For_loop(std::int16_t lino, std::shared_ptr<Node> fst_conditon,
			std::shared_ptr<Node> last_conditon,
			std::shared_ptr<Node> loop_body, bool declaration=false) : Node(lino), fst_conditon_(fst_conditon), last_conditon_(last_conditon),
			loop_body_(loop_body){
			if (!fst_conditon || !last_conditon)
				throw Script_error("incorrect tsikl declaration");
		}
		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override {
			try {
				memTable_ = std::make_shared<MemoryFrame>(mem);
				auto fst = fst_conditon_->pass(memTable_);
				int ff = 0;
				auto last = last_conditon_->pass(memTable_);
				if (fst && last) {
					auto one = *std::make_shared<MemoryCell>(std::make_shared<Math_type<int>>(1, Types::INT));
					auto i = fst.value();
					auto j = last.value();
					auto jj = *j + one;
					i->applyValueChange();
					for (; (bool)*(((*i) < jj).getData()); (*i) = std::make_shared<MemoryCell>((*i) + one)) {
						if (loop_body_ && robot::Robot::AllowScriptExecution) {
							auto mem2 = std::make_shared<MemoryFrame>(memTable_);
							loop_body_->pass(mem2);
						}
					}
				}
				memTable_->clear();
				return std::nullopt;
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}
		}
		virtual  ~For_loop() override {};
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
		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override {
			try {
				memTable_ = std::make_shared<MemoryFrame>(mem);
				try {
					while ((bool)(*(*(conditon_->pass(memTable_)).value()).getData()) && robot::Robot::AllowScriptExecution)
					{
						if (body_) {
							body_->pass(memTable_);
							memTable_->clear();
						}
					}
					return std::nullopt;
				}
				catch (std::bad_optional_access e) {
					throw Script_error("Loop's invariant must be logicheskoye or convertable to logicheskoye");
				}
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}
		}
		virtual ~While_loop() override{}
	};

	class Condition_expression : public Node {
	private:
		std::shared_ptr<Node> conditon_;
		std::shared_ptr<Node> body_;
		std::shared_ptr<Node> else_body_;
	public:
		Condition_expression(std::int16_t lino, std::shared_ptr<Node> conditon,
			std::shared_ptr<Node> body_, std::shared_ptr<Node> else_=nullptr) : Node(lino), conditon_(conditon), body_(body_), else_body_(else_) {
			if(!body_|| !conditon_)
				throw Script_error("incorrect IF declaration");
		}
		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override {
			try {
				auto fst = conditon_->pass(mem);
				memTable_ = std::make_shared<MemoryFrame>(mem);
				if (fst) {
					if ((bool)(*(fst.value()->getData())))
						body_->pass(memTable_);
					else if (else_body_)
						else_body_->pass(memTable_);
					memTable_->clear();
					return std::nullopt;
				}
				throw Script_error("Missed condition.");
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}
		}
		virtual ~Condition_expression() override {}
	};

	class Pointer_get_expr :public Node {
	private:
		std::shared_ptr<Node> ptr_;
	public:
		Pointer_get_expr(std::int16_t lino, std::shared_ptr<Node> ptr): Node(lino), ptr_(ptr){
			if(!ptr)
				throw Script_error("right operand of GET POINTER missed");
		}
		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override {
			try {
				auto fst = ptr_->pass(mem);
				if (fst) {
					if (fst.value()->getData()->getType() != Types::POINTER
						&& fst.value()->isInMemory()
						&& fst.value()->getData()->getHideType() != Types::LINK) {

						std::shared_ptr<Pointer> tmp = std::make_shared<Pointer>(fst.value()->getData());
						return std::make_shared<MemoryCell>(tmp);
					}
					else if (fst.value()->isInMemory())
						throw Script_error("The expression must have the type of an independent object. (not a pointer and not an array element)");
					else
						throw Script_error("Trying to get pointer to constant expression.");
				}
				throw Script_error("Missed operand. Expression exprected;");
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}
		}
		virtual ~Pointer_get_expr() override {}
	};

	class Command_list : public Node {
	private:
		std::list<std::pair<Commands, std::optional<Sides>>> command_que_;
	public:
		Command_list(std::int16_t lino, std::list<std::pair<Commands, std::optional<Sides>>>& lst): Node(lino),command_que_(lst){}
		void addCommand(Commands cmd, std::optional<Sides> sd = {}) {
			try {
				if (cmd == Commands::ROTATE &&
					(sd == Sides::FRONT || sd == Sides::BACK))
					throw Script_error("Rotate front and rotate back - undefined.");
				command_que_.push_back(std::make_pair(cmd, sd));
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}
		}

		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override {
			try {
				return robot::Robot::doCommands(command_que_);
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}
		}
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
		void addStatement(std::shared_ptr<Node> santance) {
			if (santance&&!santance->priority())
				santenceLst_.push_back(santance);
			else if(santance && santance->priority())
				santenceLst_.push_front(santance);
		}
		virtual std::optional<std::shared_ptr<MemoryCell>> pass(std::shared_ptr<MemoryFrame> mem) override {
			try {
				for (auto a : santenceLst_) {
					if (robot::Robot::AllowScriptExecution)
						a->pass(mem);
					else break;
				}
				return std::nullopt;
			}
			catch (Script_error e) {
				throw Script_error(e, lino_);
			}
		}
		void initMemory(std::shared_ptr<MemoryFrame> global = nullptr) {
			memTable_ = std::make_shared<MemoryFrame>(global);
		}
		void pass() {
			pass(memTable_);
		}
		virtual ~Statement_list() override{}
	};
}
