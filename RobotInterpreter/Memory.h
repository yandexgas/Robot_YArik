#pragma once
#include <list>
#include <unordered_map>
#include"Types.h"
namespace language {
	class Function;
	class MemoryCell {
	private:
		MemoryCell():data_(nullptr) {}
	protected:
		std::shared_ptr<Type> data_;
		bool isFloating(Types t1, Types t2 = Types::INT) {
			return t1 == Types::FLOAT || t2 == Types::FLOAT;
		}
		bool lvalue;
		friend class Function;
	public:
		MemoryCell(std::shared_ptr<Type> tp, bool lval=false): data_(tp), lvalue(lval){}
		MemoryCell(MemoryCell& mem) {
			//data_ = mem.data_->makeClone();
			data_ = mem.data_;
			lvalue = mem.lvalue;
		}
		MemoryCell(MemoryCell&& mem)noexcept {
			//data_ = mem.data_->makeClone();
			data_ = std::move(mem.data_);
			lvalue = mem.lvalue;
		}
		std::shared_ptr<Type> getData() {
			return data_;
		}
		 virtual bool isInMemory() {
			return lvalue;
		}
		MemoryCell operator+(MemoryCell val) {
			MemoryCell result;
			if (isFloating(data_->getType(), val.data_->getType())) {
				float to_type = 0;
				to_type = sum(data_, val.data_, to_type);
				result.data_= std::make_shared<Math_type<float>>(to_type, Types::FLOAT);
				return result;
			}
			else {
				int to_type = 0;
				to_type = sum(data_, val.data_, to_type);
				result.data_ = std::make_shared< Math_type<int>>(to_type, Types::INT);
				return result;
			}
		}
		MemoryCell operator-(MemoryCell val) {
			MemoryCell result;
			if (isFloating(data_->getType(), val.data_->getType())) {
				float to_type = 0;
				to_type = sub(data_, val.data_, to_type);
				result.data_ = std::make_shared<Math_type<float>>(to_type, Types::FLOAT);
				 return result;
			}
			else {
				int to_type = 0;
				to_type = sub(data_, val.data_, to_type);
				result.data_ = std::make_shared< Math_type<int>>(to_type, Types::INT);
				 return result;
			}
		}
		MemoryCell operator*(MemoryCell val) {
			MemoryCell result;
			if (isFloating(data_->getType(), val.data_->getType())) {
				float to_type = 0;
				to_type = mul(data_, val.data_, to_type);
				result.data_ = std::make_shared<Math_type<float>>(to_type, Types::FLOAT);
				 return result;
			}
			else {
				int to_type = 0;
				to_type = mul(data_, val.data_, to_type);
				result.data_ = std::make_shared< Math_type<int>>(to_type, Types::INT);
				return result;
			}
		}
		MemoryCell operator/(MemoryCell val) {
			MemoryCell result;
			if (isFloating(data_->getType(), val.data_->getType())) {
				float to_type = 0;
				to_type = div(data_, val.data_, to_type);
				result.data_ = std::make_shared<Math_type<float>>(to_type, Types::FLOAT);
				return result;
			}
			else {
				int to_type = 0;
				to_type = div(data_, val.data_, to_type);
				result.data_ = std::make_shared< Math_type<int>>(to_type, Types::INT);
				return result;
			}
		}
		MemoryCell operator-() {
			MemoryCell result;
			if (isFloating(data_->getType())) {
				float to_type = 0;
				to_type = uminus(data_, to_type);
				result.data_ = std::make_shared<Math_type<float>>(to_type, Types::FLOAT);
				 return result;
			}
			else {
				int to_type = 0;
				to_type = uminus(data_, to_type);
				result.data_ = std::make_shared< Math_type<int>>(to_type, Types::INT);
				 return result;
			}
		}
		MemoryCell operator~() {
			MemoryCell result;
				 result.data_ = std::make_shared< Math_type<bool>>(invers(data_), Types::BOOL);
				 return result;
		}
		MemoryCell operator||(MemoryCell val) {
			MemoryCell result;
			 result.data_ = std::make_shared< Math_type<bool>>(Or(data_,val.data_), Types::BOOL);
			 return result;
		}
		MemoryCell operator&&(MemoryCell val) {
			MemoryCell result;
			result.data_ = std::make_shared< Math_type<bool>>(And(data_, val.data_), Types::BOOL);
			return result;
		}
		MemoryCell operator>(MemoryCell val) {
			MemoryCell result;
			if (isFloating(data_->getType(), val.data_->getType())) {
				float to_type = 0;
				bool rs= more(data_, val.data_, to_type);
				result.data_ = std::make_shared< Math_type<bool>>(rs, Types::BOOL);
				return result;
			}
			else {
				int to_type = 0;
				bool rs = more(data_, val.data_, to_type);
				result.data_ = std::make_shared< Math_type<bool>>(rs, Types::BOOL);
				return result;
			}
		}
		MemoryCell operator<(MemoryCell val) {
			MemoryCell result;
			if (isFloating(data_->getType(), val.data_->getType())) {
				float to_type = 0;
				bool rs = less(data_, val.data_, to_type);
				result.data_ = std::make_shared< Math_type<bool>>(rs, Types::BOOL);
				return result;
			}
			else {
				int to_type = 0;
				bool rs = less(data_, val.data_, to_type);
				result.data_ = std::make_shared< Math_type<bool>>(rs, Types::BOOL);
				return result;
			}
		}
		friend MemoryCell operator<=(YFields field,MemoryCell source){
			if (source.data_->getType() != Types::SQUARE)
				throw Type_error("That object is not yacheyka.");
			MemoryCell result;
			auto tmp = source.data_->getHideType() == Types::LINK ?
				std::dynamic_pointer_cast<Square>(**std::dynamic_pointer_cast<Link>(source.data_)) :
				std::dynamic_pointer_cast<Square>(source.data_);
			MemoryCell res;
			res.lvalue = true;
			switch (field)
			{
			case language::YFields::X:
				res.data_= tmp->getX();
				break;
			case language::YFields::Y:
				res.data_ = tmp->getY();
				break;
			case language::YFields::BUSY:
				res.data_ = tmp->getBusy();
				break;
			}
			return res;
		}
		MemoryCell operator[](std::vector<int> path) {
			if(data_->getType()!=Types::ARRAY)
				throw Type_error("That object is not massiv.");
			auto tmp = data_->getHideType() == Types::LINK ?
				std::dynamic_pointer_cast<Array>(**std::dynamic_pointer_cast<Link>(data_)) :
				std::dynamic_pointer_cast<Array>(data_);
			MemoryCell res((*tmp)[path], true);
			return res;
		}
		MemoryCell operator*() {
			if(data_->getType()!=Types::POINTER)
				throw Type_error("That object is not ukazatel.");
			auto tmp = data_->getHideType() == Types::LINK ?
				std::dynamic_pointer_cast<Pointer>(**std::dynamic_pointer_cast<Link>(data_)) :
				std::dynamic_pointer_cast<Pointer>(data_);
			MemoryCell res(**tmp, true);
			return res;
		}
		static MemoryCell checkTypes(Types t1, Types t2) {
			MemoryCell res;
			res.data_=std::make_shared< Math_type<bool>>(t1 == t2, Types::BOOL);
			return res;
		}
		static MemoryCell checkTypes(MemoryCell t1, Types t2) {
			MemoryCell res;
			res.data_ = std::make_shared< Math_type<bool>>(t1.data_->getType() == t2, Types::BOOL);
			return res;
		}
		static MemoryCell checkTypes(Types t1, MemoryCell t2) {
			MemoryCell res;
			res.data_ = std::make_shared< Math_type<bool>>(t1== t2.data_->getType(), Types::BOOL);
			return res;
		}
		static MemoryCell checkTypes (MemoryCell t1, MemoryCell t2) {
			MemoryCell res;
			res.data_ = std::make_shared< Math_type<bool>>(t1.data_->getType() == t2.data_->getType(), Types::BOOL);
			return res;
		}
		MemoryCell arrayDimension() {
			if(data_->getType()!=Types::ARRAY)
				throw Type_error("That object is not massiv.");
			auto tmp = data_->getHideType() == Types::LINK ?
				std::dynamic_pointer_cast<Array>(**std::dynamic_pointer_cast<Link>(data_)) :
				std::dynamic_pointer_cast<Array>(data_);
			MemoryCell res;
			res.data_ = std::make_shared< Math_type<int>>(tmp->getDimensionality(), Types::INT);
			return res;
		}
		virtual void operator=(std::shared_ptr<MemoryCell> mem) {
			if(!lvalue)
				throw Initial_error("rvalue expression can't change the value");
			else *data_ = (*mem).getData();
		}
		~MemoryCell(){}
	};

	class NamedObject {
	protected:
		std::string name_;
		const bool isVar;
	public:
		NamedObject(std::string name_,bool isVar):name_(name_), isVar(isVar){}
		bool isVariable() const noexcept {
			return isVar;
		}
		const std::string& getName()const noexcept {
			return name_;
		}
		~NamedObject(){}
	};
	class Variable :public MemoryCell, public NamedObject {	
	public:
		Variable(std::string name, MemoryCell& mem): MemoryCell(mem), NamedObject(name,true){}
		Variable(std::string name, std::shared_ptr<Type> tp) : MemoryCell(tp,true), NamedObject(name,true){}
		Variable(std::string name, Types type, bool ptr=false) :NamedObject(name,true), MemoryCell(nullptr) {
			switch (type)
			{
			case Types::ARRAY:
				data_ = std::make_shared<Array>();
				break;
			case Types::INT:
				data_ =std::make_shared< Math_type<int>>(Types::INT);
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
			default:
				break;
			}
			if (ptr)
				data_ = std::make_shared<Pointer>(data_);
		}
		virtual void operator=(std::shared_ptr<MemoryCell> mem) override {
			*data_ = (*mem).getData();
		}
		virtual bool isInMemory() override {
			return true;
		}
	};

	struct fparam
	{
		Types type;
		bool isPtr;
		std::string name;
		const bool operator==(const fparam& p)const {
			if (isPtr == p.isPtr) {
				return type == p.type;
			}
			else return false;
		}

	};
	class Node;
	class Function {
	protected:
		const std::list<fparam> params_;
		const std::optional<Types> type_;
		const bool ptrType_;
		Node* fptr_;
	public:
		Function(std::list<fparam> param, std::optional<Types> type = {}, bool ptrType = false) :params_(param), type_(type), ptrType_(ptrType),fptr_(nullptr) {}
		bool operator==(Function& f) {
			if (params_.size() != f.params_.size())
				return false;
			for (auto i = params_.begin(), j = f.params_.begin(); i != params_.end(); i++, j++) {
				if ((*i) !=(*j))
					return false;
			}
			return true;
		}

		Function& setPtr(Node* ptr) {
			fptr_ = ptr;
			return *this;
		}

		virtual std::optional<Node*> getPtr() {
			return fptr_;
		}
		bool operator==(std::list<std::shared_ptr<MemoryCell>>& f) {
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
		bool convertableTo(std::list<std::shared_ptr<MemoryCell>>& f) {
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
			return true;
			}
		}


	};

	class FunctionList:public NamedObject {
	private:
		std::list<std::shared_ptr<Function>> funcFamily_;
	public:
		FunctionList(std::string name, std::shared_ptr<Function> f) : NamedObject(name,false) {
			funcFamily_.push_back(f);
		}
		void insert(std::shared_ptr<Function> f) {
			for (auto a : funcFamily_) {
				if ((*a) == (*f))
					throw Redefinition_error("Functions, diffirent only by result type can't be overloaded.");
			}
			funcFamily_.push_back(f);
		}
		std::shared_ptr<Function> get(std::list<std::shared_ptr<MemoryCell>>&lst) {
			for (auto a : funcFamily_) {
				if ((*a) == lst)
					return a;
			}
			return nullptr;
		}
		std::shared_ptr<Function> getConvertable(std::list < std::shared_ptr< MemoryCell> > & lst) {
			for (auto a : funcFamily_) {
				if ((*a).convertableTo(lst))
					return a;
			}
			return nullptr;
		}
	};
	struct fcall
	{
		std::string name;
		std::list<std::shared_ptr<MemoryCell>> arg;
	};
	class MemoryFrame {
	private:
		std::shared_ptr<MemoryFrame> higerFrame_;
		std::unordered_map<std::string, std::shared_ptr<NamedObject>> localMemory_;
	public:
		MemoryFrame(std::shared_ptr<MemoryFrame> ptr = {}) : higerFrame_(ptr) {};
		MemoryFrame(MemoryFrame& mf):higerFrame_(mf.higerFrame_), localMemory_(mf.localMemory_) {}

		void insert(std::shared_ptr<Variable> var){
			if (localMemory_.contains(var->getName())) {
				throw Redefinition_error("double definition of variable: " + var->getName());
			}
			localMemory_[var->getName()] = var;
		}

		void insert(std::string name,std::shared_ptr<Function> f) {
			if (localMemory_.contains(name)&& !(localMemory_[name]->isVariable())) {
				auto tmp = std::static_pointer_cast<FunctionList>(localMemory_[name]);
				tmp->insert(f);
			}
			else if(!localMemory_.contains(name)){
				localMemory_[name] = std::make_shared<FunctionList>(name, f);
			}
		}

		std::shared_ptr<Variable> operator[](std::string name) {
			if (localMemory_.contains(name) && localMemory_[name]->isVariable())
				return std::static_pointer_cast<Variable>(localMemory_[name]);
			else if (localMemory_.contains(name)) {
				throw Call_error("Argument list expected.");
			}
			else {
				//if (higerFrame_)
					return (*higerFrame_)[name];
				//else throw Initial_error("Undeclared variable.");
			}
		}
		

		std::shared_ptr<Function> operator[](fcall& f) {
			if (localMemory_.contains(f.name) && !(localMemory_[f.name]->isVariable())){
				auto tmp = std::static_pointer_cast<FunctionList>(localMemory_[f.name]);
				auto res =tmp->get(f.arg);
				if (!res) {
					auto prev = higerFrame_;
					while (prev)
					{
						if (prev->localMemory_.contains(f.name) && !(prev->localMemory_[f.name]->isVariable())) {
							tmp = std::static_pointer_cast<FunctionList>(prev->localMemory_[f.name]);
							res = tmp->get(f.arg);
							if (res)
								return res;
							prev = prev->higerFrame_;
						}
						else if (prev->localMemory_.contains(f.name))
							throw Call_error("Attemp to use variable as function.");
					}
					auto tmp = std::static_pointer_cast<FunctionList>(localMemory_[f.name]);
					res = tmp->getConvertable(f.arg);
					if (!res) {
						prev = higerFrame_;
						while (prev)
						{
							if (prev->localMemory_.contains(f.name)) {
								tmp = std::static_pointer_cast<FunctionList>(prev->localMemory_[f.name]);
								res = tmp->getConvertable(f.arg);
								if (res)
									return res;
							}
						}
					}
					else return res;
				}
				else return res;
				throw Call_error("No function with complitable parametrs.");
			}
			else if (localMemory_.contains(f.name)) {
				throw Call_error("Attemp to use variable as function.");
			}
			else
				return (*higerFrame_)[f];
		}
		void clear() {
			localMemory_.clear();
			higerFrame_ = nullptr;
		}
		

		~MemoryFrame(){}
	};
}