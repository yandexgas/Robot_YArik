#include "Nodes.h"
namespace language {


	ConstString::ConstString (std::string str, std::int16_t lino): Leaf(lino) {
		std::vector<int> dim;
		dim.push_back(str.length());
		auto res = std::make_shared<Array>(dim);
		for (int i = 0; i < str.length(); i++)
		*(res->getDataLink()[i]) = std::make_shared<Math_type<char>>(str[i], Types::BYTE);
		*(res->getDataLink()[str.length() - 1]) = std::make_shared<Math_type<char>>(0, Types::BYTE);
		value_ = std::make_shared<MemoryCell>(res);
	}

	 std::optional<std::shared_ptr<MemoryCell>> Var::pass(std::shared_ptr<MemoryFrame>mem)  {
		try {
			return  (*mem)[name];
		}
		catch (Script_error e) {
			throw Script_error(e, lino_);
		}
	}

	 Binary_expression::Binary_expression(std::int16_t lino, std::shared_ptr<Node> c1, std::shared_ptr<Node> c2) : Node(lino) {
		 if (c1 && c2) {
			 children_[0] = c1;
			 children_[1] = c2;
		 }
		 else
			 throw Script_error("One of operands of binary operator has been missed", lino_);
	 }
	 std::optional<std::shared_ptr<MemoryCell>> Addittion_expression::pass(std::shared_ptr<MemoryFrame> mem)  {
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

	 std::optional<std::shared_ptr<MemoryCell>> Substract_expression::pass(std::shared_ptr<MemoryFrame> mem) {
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

	 std::optional<std::shared_ptr<MemoryCell>> Multiply_expression::pass(std::shared_ptr<MemoryFrame> mem)  {
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

	 std::optional<std::shared_ptr<MemoryCell>> Divide_expression::pass(std::shared_ptr<MemoryFrame> mem){
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

	 std::optional<std::shared_ptr<MemoryCell>> Disjunction_expression::pass(std::shared_ptr<MemoryFrame> mem) {
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

	 std::optional<std::shared_ptr<MemoryCell>> Conjunction_expression::pass(std::shared_ptr<MemoryFrame> mem)  {
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
	 std::optional<std::shared_ptr<MemoryCell>> More_expression::pass(std::shared_ptr<MemoryFrame> mem){
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

	std::optional<std::shared_ptr<MemoryCell>> Less_expression::pass(std::shared_ptr<MemoryFrame> mem)  {
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

	FieldAccess_expression::FieldAccess_expression(std::int16_t lino, std::string field, std::shared_ptr<Node>c) :Node(lino), child_(c) {
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

	std::optional<std::shared_ptr<MemoryCell>> FieldAccess_expression::pass(std::shared_ptr<MemoryFrame> mem){
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

	Unary_expression::Unary_expression(std::int16_t lino, std::shared_ptr<Node> child_) : Node(lino), child_(child_) {
		try {
			if (!child_)
				throw Script_error("Operand missed");
		}
		catch (Script_error e) {
			throw Script_error(e, lino_);
		}
	}

	std::optional<std::shared_ptr<MemoryCell>> UnaryMinus_expression::pass(std::shared_ptr<MemoryFrame> mem)  {
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

	std::optional<std::shared_ptr<MemoryCell>> LogicInversion_expression::pass(std::shared_ptr<MemoryFrame> mem) {
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

	std::optional<std::shared_ptr<MemoryCell>> TypeCheck_expression::pass(std::shared_ptr<MemoryFrame> mem){
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

	std::optional<std::shared_ptr<MemoryCell>> ArrayIndaxation_expression::pass(std::shared_ptr<MemoryFrame> mem)  {
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

	std::optional<std::shared_ptr<MemoryCell>> DimensionOperator::pass(std::shared_ptr<MemoryFrame> mem){
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

	std::optional<std::shared_ptr<MemoryCell>> StarOperator::pass(std::shared_ptr<MemoryFrame> mem) {
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

	std::optional<std::shared_ptr<MemoryCell>> VarDeclaration_expression::pass(std::shared_ptr<MemoryFrame> mem) {
		try {
			mem->insert(var);
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

	SquareDecl::SquareDecl(std::int16_t lino, std::string name, std::shared_ptr<Node> exp1, std::shared_ptr<Node> exp2, std::shared_ptr<Node> exp3) : Node(lino), name_(name) {
		init_expression_[0] = exp1;
		init_expression_[1] = exp2;
		init_expression_[2] = exp3;
	}

	std::optional<std::shared_ptr<MemoryCell>> SquareDecl::pass(std::shared_ptr<MemoryFrame> mem) {
		try {
			std::optional < std::shared_ptr<MemoryCell>> tmp[3];
			for (int i = 0; i < 3; i++)
				tmp[i] = init_expression_[i]->pass(mem);
			if (tmp[0] && tmp[1] && tmp[2]) {
				auto yach = std::make_shared<Square>((int)*(tmp[0].value()->getData()), (int)*(tmp[1].value()->getData()), (bool)*(tmp[2].value()->getData()));
				auto var = std::make_shared<Variable>(name_, yach);
				mem->insert(var);
			}
			else
				throw Script_error("Yacheyka initialization value expected.");
			return std::nullopt;
		}
		catch (Script_error e) {
			throw Script_error(e, lino_);
		}
	}

	std::optional<std::shared_ptr<MemoryCell>> ArrDecl::pass(std::shared_ptr<MemoryFrame> mem) {
		try {
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
			mem->insert(var);
			return std::nullopt;
		}
		catch (Script_error e) {
			throw Script_error(e, lino_);
		}
	}

	FunDeclaration_expression::FunDeclaration_expression(std::int16_t lino, std::string name, std::list<fparam> params, std::shared_ptr<Node> child, std::optional<Types> tp, bool isPtr) 
		: Node(lino), name_(name), body_(child), params_(params), tp_(tp), isPtr(isPtr) 
	{
		fptr_ = std::make_shared<Function>(params, tp, isPtr);
		fptr_->setPtr(this);
	}

	std::optional<std::shared_ptr<MemoryCell>> FunDeclaration_expression::funcCal(std::list < std::shared_ptr<MemoryCell>>& args) {
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
				std::optional<std::shared_ptr<MemoryCell>> res;
				if (tp_) 
					res = std::make_shared<MemoryCell>(result->getData());
				else
					res = std::nullopt;
				stackFrame->clear();
				return res;
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

	std::optional<std::shared_ptr<MemoryCell>> FunDeclaration_expression::pass(std::shared_ptr<MemoryFrame> mem) {
		try {
			mem->insert(name_, fptr_);
			memTable_ = mem;
			return std::nullopt;
		}
		catch (Script_error e) {
			throw Script_error(e, lino_);
		}
	}

	std::optional<std::shared_ptr<MemoryCell>> Function_call::pass(std::shared_ptr<MemoryFrame> mem){
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
			std::pair <std::string, std::list<std::shared_ptr<MemoryCell>>> fun (name_,tmp);
			auto fptr = (*mem)[fun];
			auto target_func = fptr->getPtr();
			if (target_func)
				return dynamic_cast<FunDeclaration_expression*>(target_func)->funcCal(fun.second);
			else
				return (*std::dynamic_pointer_cast<LibFunction>(fptr))(fun.second);
		}
		catch (Script_error e) {
			throw Script_error(e, lino_);
		}
	}

	std::optional<std::shared_ptr<MemoryCell>> Assigment_node::pass(std::shared_ptr<MemoryFrame> mem) {
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

	For_loop::For_loop(std::int16_t lino, std::shared_ptr<Node> fst_conditon,
		std::shared_ptr<Node> last_conditon,
		std::shared_ptr<Node> loop_body, bool declaration ) : Node(lino), fst_conditon_(fst_conditon), last_conditon_(last_conditon),
		loop_body_(loop_body)
	{
		if (!fst_conditon || !last_conditon)
			throw Script_error("incorrect tsikl declaration");
	}

	std::optional<std::shared_ptr<MemoryCell>> For_loop::pass(std::shared_ptr<MemoryFrame> mem){
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
				for ( ; (bool)*((*i < jj).getData()) ; *i = std::move(*i + one)) {
					if (loop_body_ && robot::Robot::AllowScriptExecution) {
						auto mem2 = std::make_shared<MemoryFrame>(memTable_);
						loop_body_->pass(mem2);
						mem2->clear();
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

	std::optional<std::shared_ptr<MemoryCell>> While_loop::pass(std::shared_ptr<MemoryFrame> mem){
		try {
			memTable_ = std::make_shared<MemoryFrame>(mem);
			try {
				while ((bool)*(conditon_->pass(memTable_)).value()->getData() 
						&& robot::Robot::AllowScriptExecution )
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

	std::optional<std::shared_ptr<MemoryCell>> Condition_expression::pass(std::shared_ptr<MemoryFrame> mem) {
		try {
			auto fst = conditon_->pass(mem);
			memTable_ = std::make_shared<MemoryFrame>(mem);
			if (fst) {
				if ((bool)*(fst.value()->getData()))
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

	std::optional<std::shared_ptr<MemoryCell>> Pointer_get_expr::pass(std::shared_ptr<MemoryFrame> mem) {
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

	void Command_list::addCommand(Commands cmd, std::optional<Sides> sd) {
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

	std::optional<std::shared_ptr<MemoryCell>> Command_list::pass(std::shared_ptr<MemoryFrame> mem) {
		try {
			return robot::Robot::doCommands(command_que_);
		}
		catch (Script_error e) {
			throw Script_error(e, lino_);
		}
	}

	void Statement_list::addStatement(std::shared_ptr<Node> santance) {
		if (santance && !santance->priority())
			santenceLst_.push_back(santance);
		else if (santance && santance->priority())
			santenceLst_.push_front(santance);
	}

	std::optional<std::shared_ptr<MemoryCell>> Statement_list::pass(std::shared_ptr<MemoryFrame> mem){
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
 }
