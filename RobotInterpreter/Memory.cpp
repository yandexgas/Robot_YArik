#include "Memory.h"
namespace language {

	MemoryCell MemoryCell::operator+(const MemoryCell& val) {

		return std::move( operation(val, []<Ariphmetical T, Ariphmetical U, Ariphmetical_result Z> (T t, U u, Z z)->Z  { 
			return sum(t, u, z); 
		}
		));
	}

	MemoryCell MemoryCell::operator-(const MemoryCell& val) {

		return std::move(operation(val, []<Ariphmetical T, Ariphmetical U, Ariphmetical_result Z> (T t, U u, Z z)->Z {
			return sub(t, u, z);
		}
		));
	}

	MemoryCell MemoryCell::operator*(const MemoryCell& val) {
		return std::move(operation(val, []<Ariphmetical T, Ariphmetical U, Ariphmetical_result Z> (T t, U u, Z z)->Z {
			return mul(t, u, z);
		}
		));
	}

	MemoryCell MemoryCell::operator/(const MemoryCell& val) {
		return std::move(operation(val, []<Ariphmetical T, Ariphmetical U, Ariphmetical_result Z> (T t, U u, Z z)->Z {
			return div(t, u, z);
		}
		));
	}

	MemoryCell MemoryCell::operator-() {
		MemoryCell result;
		if (isFloating(data_->getType())) {
			float to_type = 0;
			to_type = uminus(data_, to_type);
			result.data_ = std::make_shared<Math_type<float>>(to_type, Types::FLOAT);
		}
		else {
			int to_type = 0;
			to_type = uminus(data_, to_type);
			result.data_ = std::make_shared< Math_type<int>>(to_type, Types::INT);	
		}
		return result;
	}

	MemoryCell MemoryCell::operator~() {
		MemoryCell result;
		result.data_ = std::make_shared< Math_type<bool>>(invers(data_), Types::BOOL);
		return result;
	}

	MemoryCell MemoryCell::operator||(const MemoryCell& val) {
		MemoryCell result;
		result.data_ = std::make_shared< Math_type<bool>>(Or(data_, val.data_), Types::BOOL);
		return result;
	}

	MemoryCell MemoryCell::operator&&(const MemoryCell& val) {
		MemoryCell result;
		result.data_ = std::make_shared< Math_type<bool>>(And(data_, val.data_), Types::BOOL);
		return result;
	}

	MemoryCell MemoryCell::operator>(const MemoryCell& val) {
		return std::move(operation(val, []<Ariphmetical T, Ariphmetical U, Ariphmetical_result Z> (T t, U u, Z z)->Z
		{
			return more(t, u, z);
		}));
	}

	MemoryCell MemoryCell::operator<(const MemoryCell& val) {
		return std::move(operation(val, []<Ariphmetical T, Ariphmetical U, Ariphmetical_result Z> (T t, U u, Z z)->Z
		{
			return less(t, u, z);
		}));
	}

	MemoryCell MemoryCell::operator[](std::vector<int>& path) {
		if (data_->getType() != Types::ARRAY)
			throw Script_error("That object is not massiv.");
		auto tmp = data_->getHideType() == Types::LINK ?
			std::dynamic_pointer_cast<Array>(**std::dynamic_pointer_cast<Link>(data_)) :
			std::dynamic_pointer_cast<Array>(data_);
		return MemoryCell { (*tmp)[path], true };
	}

	MemoryCell MemoryCell::operator*() {
		if (data_->getType() != Types::POINTER)
			throw Script_error("That object is not ukazatel.");
		auto tmp = data_->getHideType() == Types::LINK ?
			std::dynamic_pointer_cast<Pointer>(**std::dynamic_pointer_cast<Link>(data_)) :
			std::dynamic_pointer_cast<Pointer>(data_);
		return MemoryCell{ **tmp, true };
	}

	MemoryCell MemoryCell::arrayDimension() {
		if (data_->getType() != Types::ARRAY)
			throw Script_error("That object is not massiv.");
		auto tmp = data_->getHideType() == Types::LINK ?
			std::dynamic_pointer_cast<Array>(**std::dynamic_pointer_cast<Link>(data_)) :
			std::dynamic_pointer_cast<Array>(data_);
		MemoryCell res;
		res.data_ = std::make_shared< Math_type<int>>(tmp->getDimensionality(), Types::INT);
		return res;
	}

	Variable::Variable(std::string name, Types type, bool ptr) :NamedObject(name, true), MemoryCell(nullptr,true) {
		switch (type)
		{
		case Types::ARRAY:
			data_ = std::make_shared<Array>();
			break;
		case Types::INT:
			data_ = std::make_shared< Math_type<int>>(Types::INT);
			break;
		case Types::FLOAT:
			data_ = std::make_shared< Math_type<float>>(Types::FLOAT);
			break;
		case Types::BOOL:
			data_ = std::make_shared< Math_type<bool>>(Types::BOOL);
			break;
		case Types::SQUARE:
			data_ = std::make_shared<Square>();
			break;
		case Types::BYTE:
			data_ = std::make_shared<Math_type<char>>(Types::BYTE);
		}
		if (ptr)
			data_ = std::make_shared<Pointer>(data_);
	}

	bool Function::operator==(Function& f) {
		if (params_.size() != f.params_.size())
			return false;
		for (auto i = params_.begin(), j = f.params_.begin(); i != params_.end(); i++, j++) {
			if ((*i) != (*j))
				return false;
		}
		return true;
	}

	bool Function::operator==(std::list<std::shared_ptr<MemoryCell>>& f) {
		if (params_.size() != f.size())
			return false;
		auto j = f.begin();
		for (auto i = params_.begin(); i != params_.end(); i++, j++) {
			if ((*i).isPtr == ((*j)->data_->getType() == Types::POINTER)) {
				if ((*i).isPtr) {
					if ((*i).type != (**std::dynamic_pointer_cast<Pointer>((*j)->data_))->getType())
						return false;
				}
				else if ((*i).type != (*j)->data_->getType())
					return false;
			}
			else return false;
		}
		return true;
	}

	bool Function::convertableTo(std::list<std::shared_ptr<MemoryCell>>& f) {
		if (params_.size() != f.size())
			return false;
		auto j = f.begin();
		for (auto i = params_.begin(); i != params_.end(); i++, j++) {
			if ((*i).isPtr == ((*j)->data_->getType() == Types::POINTER)) {
				if ((*i).isPtr) {
					if ((*i).type != (**std::dynamic_pointer_cast<Pointer>((*j)->data_))->getType())
						return false;
				}
				else if (!convertableTypes((*i).type, (*j)->data_->getType()))
					return false;
			}
			else return false;
		}
		return true;
	}

	void FunctionList::insert(std::shared_ptr<Function> f) {
		for (auto a : funcFamily_) {
			if ((*a) == (*f))
				throw Script_error("Functions, diffirent only by result type can't be overloaded.");
		}
		funcFamily_.push_back(f);
	}

	std::shared_ptr<Function> FunctionList::get(std::list<std::shared_ptr<MemoryCell>>& lst) {
		for (auto a : funcFamily_) {
			if ((*a) == lst)
				return a;
		}
		return nullptr;
	}

	std::shared_ptr<Function> FunctionList::getConvertable(std::list < std::shared_ptr< MemoryCell> >& lst) {
		for (auto a : funcFamily_) {
			if ((*a).convertableTo(lst))
				return a;
		}
		return nullptr;
	}

	void MemoryFrame::insert(std::shared_ptr<Variable> var) {
		if (localMemory_.contains(var->getName())) {
			throw Script_error("double definition of variable: " + var->getName());
		}
		localMemory_[var->getName()] = var;
	}

	void MemoryFrame::insert(std::string name, std::shared_ptr<Function> f) {
		if (localMemory_.contains(name) && !(localMemory_[name]->isVariable())) {
			auto tmp = std::static_pointer_cast<FunctionList>(localMemory_[name]);
			tmp->insert(f);
		}
		else if (!localMemory_.contains(name)) {
			localMemory_[name] = std::make_shared<FunctionList>(name, f);
		}
	}

	std::shared_ptr<Variable> MemoryFrame::operator[](std::string name) {
		if (localMemory_.contains(name) && localMemory_[name]->isVariable())
			return std::static_pointer_cast<Variable>(localMemory_[name]);
		else if (localMemory_.contains(name)) {
			throw Script_error("Argument list expected.");
		}
		else {
			if (higerFrame_)
				return (*higerFrame_)[name];
			else throw Script_error("Undeclared variable.");
		}
	}

	std::shared_ptr<Function> MemoryFrame::operator[](std::pair<std::string, std::list<std::shared_ptr<MemoryCell>>>& fcall) {
		if (localMemory_.contains(fcall.first) 
			&& !(localMemory_[fcall.first]->isVariable())) {
			auto tmp = std::static_pointer_cast<FunctionList>(localMemory_[fcall.first]);
			auto res = tmp->get(fcall.second);
			if (!res) {
				auto prev = higerFrame_;
				while (prev)
				{
					if (prev->localMemory_.contains(fcall.first) 
						&& !(prev->localMemory_[fcall.first]->isVariable())) {
						tmp = std::static_pointer_cast<FunctionList>(prev->localMemory_[fcall.first]);
						res = tmp->get(fcall.second);
						if (res)
							return res;
					}
					else if (prev->localMemory_.contains(fcall.first))
						throw Script_error("Attemp to use variable as function.");
					prev = prev->higerFrame_;
				}
				auto tmp = std::static_pointer_cast<FunctionList>(localMemory_[fcall.first]);
				res = tmp->getConvertable(fcall.second);
				if (!res) {
					prev = higerFrame_;
					while (prev)
					{
						if (prev->localMemory_.contains(fcall.first)) {
							tmp = std::static_pointer_cast<FunctionList>(prev->localMemory_[fcall.first]);
							res = tmp->getConvertable(fcall.second);
							if (res)
								return res;
						}
						prev = prev->higerFrame_;
					}
				}
				else return res;
			}
			else return res;
			throw Script_error("No function with complitable parametrs.");
		}
		else if (localMemory_.contains(fcall.first)) {
			throw Script_error("Attemp to use variable as function.");
		}
		else
		{
			if (higerFrame_)
				return (*higerFrame_)[fcall];
			else throw Script_error("No function with complitable parametrs.");
		}
	}
}
