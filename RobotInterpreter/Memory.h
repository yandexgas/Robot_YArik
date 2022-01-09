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
		MemoryCell(MemoryCell& mem) : data_(mem.data_), lvalue(mem.lvalue) {}
		MemoryCell(MemoryCell&& mem) noexcept : data_(mem.data_), lvalue(mem.lvalue) {
			mem.data_ = nullptr;
		}
		void operator=(MemoryCell mem) {
			if (!lvalue)
				throw Script_error("rvalue expression can't change the value");
			else *data_ = mem.getData();
		}
		std::shared_ptr<Type> getData() {
			return data_;
		}
		 virtual bool isInMemory() {
			return lvalue;
		}
		 void applyValueChange() {
			 lvalue = true;
		 }
		 MemoryCell operator+(MemoryCell val);
		 MemoryCell operator-(MemoryCell val);
		 MemoryCell operator*(MemoryCell val);
		 MemoryCell operator/(MemoryCell val);
		 MemoryCell operator-();
		 MemoryCell operator~();
		 MemoryCell operator||(MemoryCell val);
		 MemoryCell operator&&(MemoryCell val);
		 MemoryCell operator>(MemoryCell val);
		 MemoryCell operator<(MemoryCell val);

		friend MemoryCell operator<=(YFields field,MemoryCell source){
			if (source.data_->getType() != Types::SQUARE)
				throw Script_error("That object is not yacheyka.");
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

		MemoryCell operator[](std::vector<int> path);
		MemoryCell operator*();
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
		MemoryCell arrayDimension();
		virtual void operator=(std::shared_ptr<MemoryCell> mem) {
			if(!lvalue)
				throw Script_error("rvalue expression can't change the value");
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
		Variable(std::string name, Types type, bool ptr = false);
		void operator=(std::shared_ptr<MemoryCell> mem) override {
			*data_ = (*mem).getData();
		}
		bool isInMemory() override {
			return true;
		}
	};

	struct fparam
	{
		Types type;
		bool isPtr;
		std::string name;
		const bool operator==(const fparam& p)const 
		{
			if (isPtr == p.isPtr) {
				return type == p.type;
			}
			else return false;
		}

	};
	class Node;
	class Function {
	private:
		Node* fptr_;
	protected:
		const std::list<fparam> params_;
		const std::optional<Types> type_;
		const bool ptrType_;
	public:
		Function(std::list<fparam> param, std::optional<Types> type = {}, bool ptrType = false) :params_(param), type_(type), ptrType_(ptrType),fptr_(nullptr) {}
		bool operator==(Function& f);

		Function& setPtr(Node* ptr) {
			fptr_ = ptr;
			return *this;
		}

		virtual Node* getPtr() {
			return fptr_;
		}
		bool operator==(std::list<std::shared_ptr<MemoryCell>>& f);
		bool convertableTo(std::list<std::shared_ptr<MemoryCell>>& f);
	};

	class FunctionList:public NamedObject {
	private:
		std::list<std::shared_ptr<Function>> funcFamily_;
	public:
		FunctionList(std::string name, std::shared_ptr<Function> f) : NamedObject(name,false) {
			funcFamily_.push_back(f);
		}
		void insert(std::shared_ptr<Function> f);
		std::shared_ptr<Function> get(std::list<std::shared_ptr<MemoryCell>>& lst);
		std::shared_ptr<Function> getConvertable(std::list < std::shared_ptr< MemoryCell> >& lst);
	};

	class MemoryFrame {
	private:
		std::shared_ptr<MemoryFrame> higerFrame_;
		std::unordered_map<std::string, std::shared_ptr<NamedObject>> localMemory_;
	public:
		MemoryFrame(std::shared_ptr<MemoryFrame> ptr = {}) : higerFrame_(ptr) {};
		MemoryFrame(MemoryFrame& mf):higerFrame_(mf.higerFrame_), localMemory_(mf.localMemory_) {}

		void insert(std::shared_ptr<Variable> var);

		void insert(std::string name, std::shared_ptr<Function> f);

		std::shared_ptr<Variable> operator[](std::string name);
		std::shared_ptr<Function> operator[](std::pair<std::string, std::list<std::shared_ptr<MemoryCell>>>& fcall);
		void clear() {
			localMemory_.clear();
		}
		~MemoryFrame(){}
	};
}