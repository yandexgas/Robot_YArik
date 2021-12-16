#include<iostream>
#include<vector>
#include <algorithm>
#include<optional>
#include "Exceptions.h"

namespace language {
	enum class Types
	{
		INT,
		FLOAT,
		BOOL,
		ARRAY,
		SQUARE,
		LINK,
		POINTER,
		BYTE
	};
	enum class YFields
	{
		X,
		Y,
		BUSY
	};
	template <typename T>
	concept like_Bool = requires(T v, int i) {
		{*v}  -> std::convertible_to<bool>;
	};
	template <typename T>
	concept like_Int = requires(T v, int i) {
		{*v}  -> std::convertible_to<int>;
	};
	template <typename T>
	concept like_float = requires(T v, int i) {
		{*v}  -> std::convertible_to<float>;
	};
	
	template <typename T>
	concept Ariphmetical = requires {
		like_Bool<T>
			|| like_Int<T>
			|| like_float<T>;
	};
	template <typename T>
	concept Ariphmetical_result = requires {
		std::same_as<bool, T>
			|| std::same_as<float, T>
			|| std::same_as<char,T>
			|| std::same_as<int, T>;
	};

	template < Ariphmetical T, Ariphmetical U, Ariphmetical_result Z>
	Z sum(T u, U t, Z) {
		return (Z)(*t) + (Z)(*u);
	}
	template < Ariphmetical T, Ariphmetical U, Ariphmetical_result Z>
	Z sub(T u, U t, Z) {
		return (Z)(*u) - (Z)(*t);
	}
	template < Ariphmetical T, Ariphmetical U, Ariphmetical_result Z>
	Z mul(T u, U t, Z) {
		return (Z)(*t) * (Z)(*u);
	}
	template < Ariphmetical T, Ariphmetical U, Ariphmetical_result Z>
	Z div(T u, U t, Z) {
		return (Z)(*u) / (Z)(*t);
	}
	template < Ariphmetical T, Ariphmetical_result Z>
	Z uminus(T u, Z) {
		return -(Z)(*u);
	}
	template < Ariphmetical T>
	bool invers(T u) {
		return !(bool)*u;
	}
	template < Ariphmetical T, Ariphmetical U>
	bool Or(T u, U t) {
		return (bool)(*t) || (bool)(*u);
	}
	template < Ariphmetical T, Ariphmetical U>
	bool And(T u, U t) {
		return (bool)(*t) && (bool)(*u);
	}
	template < Ariphmetical T, Ariphmetical U, Ariphmetical_result Z>
	bool more(T u, U t, Z) {
		return (Z)(*u) > (Z)(*t);
	}
	template < Ariphmetical T, Ariphmetical U, Ariphmetical_result Z>
	bool less(T u, U t, Z) {
		return (Z)(*u) < (Z)(*t);
	}
	class Type {
	public:
		virtual const Types getType() const noexcept = 0;
		virtual const Types getHideType() const noexcept { return getType(); }
		virtual void operator=(std::shared_ptr<Type>) = 0;
		virtual std::shared_ptr<Type> makeClone() const noexcept = 0;
		explicit virtual operator int() {
			throw Type_error("This type can't be converted to tseloye.");
		}
		explicit virtual operator float() {
			throw Type_error("This type can't be converted to drobnoye.");
		}
		explicit virtual operator bool() {
			throw Type_error("This type can't be converted to logicheskoye.");
		}
		explicit virtual operator char() {
			throw Type_error("This type can't be converted to logicheskoye.");
		}
		virtual ~Type(){}
	};

	template<Ariphmetical_result T>
	class Math_type:public Type {
	private:
		const Types type;
		T value_;
	public:
		Math_type(Types tp) : value_(0), type(tp) {  };
		Math_type(T value, Types tp) : value_(value), type(tp) {}
		Math_type(Math_type<T>& v) : value_(v.value_), type(v.type) {}
		Math_type& operator=(T val) {
			value_ = val;
			return *this;
		}
		Math_type& operator= (Math_type<T>& v) {
			value_ = v.value_;
			return *this;
		}
		virtual std::shared_ptr<Type> makeClone() const noexcept override {
			return std::make_shared<Math_type<T>>(value_, type);
		}
		virtual void operator=(std::shared_ptr<Type> a) {
			value_ = (T)*a;
		}
		virtual operator int()override {
			return value_;
		}
		explicit virtual operator float() override {
			return value_;
		}
		explicit virtual operator bool()override {
			return value_;
		}
		virtual const Types getType() const noexcept override {
			return type;
		}
		explicit virtual operator char() {
			return value_;
		}
		virtual ~Math_type() override {}
	};
	class Link : public Type {
	private:
		std::shared_ptr<Type> pointer_;
		bool inited = false;
		virtual const Types getHideType() const noexcept override {
			return Types::LINK;
		}
	public:
		Link(std::shared_ptr<Type> ptr = nullptr, bool init=true) :pointer_(ptr),inited(init) {};
		operator std::shared_ptr<Type>() {
			return pointer_;
		}
		Link(Link& lnk) {
			pointer_ = lnk.pointer_->makeClone();
			inited = lnk.inited;
		};
		//тут фигня, чуть позже изменю
		Link(Link&& lnk)noexcept {
			pointer_ = lnk.pointer_->makeClone();
			inited = lnk.inited;
		};
		Link& operator=(Link& lnk) {
			if (&lnk != this) {
				pointer_ = lnk.pointer_->makeClone();
				inited = lnk.inited;
			}
			return *this;
		}
		std::shared_ptr<Type> operator*() {
			if(inited)
				return pointer_;
			else throw Type_error("Non initiallized memory access.");
		}
		virtual std::shared_ptr<Type> makeClone() const noexcept override {
			return std::make_shared<Link>((*pointer_).makeClone());
		}
		virtual void operator=(std::shared_ptr<Type> a) override {
			if (a->getHideType() != Types::LINK)
				pointer_ = (*a).makeClone();
			else
				pointer_ = (**std::dynamic_pointer_cast<Link>(a))->makeClone();
			inited = true;
		}
		virtual const Types getType() const noexcept {
				return pointer_->getType();
		}

		explicit virtual operator int() override {
			if (inited)
				return (int)*pointer_;
			else throw Type_error("Non initiallized memory access.");
		}
		explicit virtual operator float() {
			if (inited)
				return (float)*pointer_;
			else throw Type_error("Non initiallized memory access.");
		}
		explicit virtual operator bool() {
			if (inited)
				return (bool)*pointer_;
			else throw Type_error("Non initiallized memory access.");
		}
		explicit virtual operator char() {
			if (inited)
				return (char)*pointer_;
			else throw Type_error("Non initiallized memory access.");
		}

		virtual ~Link() override {}
	};

	class Pointer :public Type {
	private:
		std::shared_ptr<std::shared_ptr<Type>> ptr_;
	public:
		Pointer(std::shared_ptr<Type> ptr) {
			ptr_ = std::make_shared<std::shared_ptr<Type>>(ptr);
		}
		Pointer() :ptr_(nullptr) {}
		Pointer(Pointer& ptr) {
			ptr_ = ptr.ptr_;
		}
		Pointer(Pointer&& ptr) noexcept {
			ptr_ = std::move(ptr.ptr_);
		}
		Pointer(std::shared_ptr<std::shared_ptr<Type>> ptr) {
			ptr_ = ptr;
		}
		virtual const Types getType() const noexcept override { return Types::POINTER; }
		virtual void operator=(std::shared_ptr<Type> ptr) {
			if (ptr->getType() == Types::POINTER) {
				auto tmp = std::dynamic_pointer_cast<Pointer>(ptr)->ptr_;
				if (ptr_ &&  (**tmp).getType() != (**ptr_).getType())
					throw Type_error("Different pointer tipes");
				ptr_ = tmp;
			}
			else
				throw Type_error("Type can not be converted to pointer");
		}
		virtual std::shared_ptr<Type> makeClone() const noexcept override {

			return std::make_shared<Pointer>(ptr_);
		}
		virtual operator bool() {
			if (*ptr_)
				return true;
			else return false;
		}
		std::shared_ptr<Type> operator*() {
			return *ptr_;
		}
		virtual ~Pointer() {}
	};

	class Square : public Type
	{
	private:
		static const Types type = Types::SQUARE;
		std::shared_ptr< Math_type<int>> X_;
		std::shared_ptr< Math_type<int >> Y_;
		std::shared_ptr< Math_type<bool>> busy_;
	public:
		Square() : X_(std::make_shared<Math_type<int>>(Types::INT)),
			Y_(std::make_shared<Math_type<int>>(Types::INT)), 
			busy_(std::make_shared<Math_type<bool>>(Types::BOOL)) {};

		Square(std::int32_t x, std::int32_t y, bool busy) : X_(std::make_shared<Math_type<int>>(x, Types::INT)),
			Y_(std::make_shared<Math_type<int>>(y, Types::INT)),
			busy_(std::make_shared<Math_type<bool>>(busy, Types::BOOL)) {}

		Square(Square& v) : X_(std::make_shared<Math_type<int>>(*v.X_, Types::INT)),
			Y_(std::make_shared<Math_type<int>>(*v.Y_, Types::INT)), 
			busy_(std::make_shared<Math_type<bool>>(*v.busy_, Types::BOOL)) {}
		Square& operator=(Square val) {
			*X_ = *(val.X_);
			*Y_ = *(val.Y_);
			*busy_ = *(val.busy_);
			return *this;
		}
		virtual const Types getType() const noexcept override {
			return type;
		}
		virtual std::shared_ptr<Type> makeClone() const noexcept override {
			return std::make_shared<Square>(*X_, *Y_, *busy_);
		}
		virtual void operator=(std::shared_ptr<Type> a) {
			auto tmp= std::dynamic_pointer_cast<Square>(a);
			if (tmp)
				*this = *tmp;
			else throw Type_error("This object can't be converted to square.");
		}
		virtual operator Square() {
			return*this;
		}
		std::shared_ptr<Type> getY()const noexcept {
			return Y_;
		}
		Square& setY(std::int32_t val) {
			*Y_ = val;
			return *this;
		}
		std::shared_ptr<Type> getX()const noexcept {
			return X_;
		}
		Square& setX(std::int32_t val) {
			*X_ = val;
			return *this;
		}
		std::shared_ptr<Type> getBusy()const noexcept {
			return busy_;
		}
		Square& setBusy(bool val) {
			*busy_ = val;
			return *this;
		}
		virtual ~Square() override {}
	};


	class Array : public Type
	{
	private:
		const Types type = Types::ARRAY;
		std::vector<std::shared_ptr<Link>> data_;
		std::vector<int> dimensions_;
	public:
		explicit Array(std::vector<int>& dimensions) : dimensions_(dimensions) {
			int mult=1;
			for (auto i : dimensions_)
				mult *= i;
			if (mult < 0)
				throw std::length_error("Too much elements in massiv");// Вообще тут еще сразу проверка и на нулевые элементы
			for (int i = 0; i < mult; i++) {
				data_.push_back(std::make_shared<Link>(std::make_shared<Math_type<char>>(Types::BYTE),false));
			}
		}
		Array(){}
		Array(std::vector<int> dimensions, std::vector<std::shared_ptr<Link>> data) : dimensions_(dimensions) {
			for (auto a : data) 
				data_.push_back(std::dynamic_pointer_cast<Link>(a->makeClone()));
		}
		Array(Array& arr) :dimensions_(arr.dimensions_){
			for (auto a : arr.data_)
				data_.push_back(std::dynamic_pointer_cast<Link>(a->makeClone()));
		}
		Array(Array&& arr) noexcept {
			data_ = std::move(arr.data_);
			dimensions_ = std::move(arr.dimensions_);
		}
		Array& operator=(Array& arr) {
			if ( &arr != this) {
				dimensions_ = arr.dimensions_;
				data_.clear();
				for (auto a : arr.data_)
					data_.push_back(std::dynamic_pointer_cast<Link>(a->makeClone()));
			}
			return *this;
		}
		Array& operator=(Array&& arr) noexcept {
			if (&arr != this) {
				data_ = std::move(arr.data_);
				dimensions_ = std::move(arr.dimensions_);
			}
			return *this;
		}
		std::vector<std::shared_ptr<Link>>& getDataLink() {
			return data_;
		}
		virtual const Types getType() const noexcept override {
			return type;
		}
		virtual std::shared_ptr<Type> makeClone() const noexcept override {
			return std::make_shared<Array>(this->dimensions_,this->data_);
		}
		virtual void operator=(std::shared_ptr<Type> a) {
			auto tmp = std::dynamic_pointer_cast<Array>(a);
			if (tmp)
				*this = *tmp;
			else
				throw Type_error("Object can't be converted to array.");
		}
		size_t getDimensionality()const noexcept {
			return dimensions_.size();
		}
		std::shared_ptr<Link> operator[](std::vector<int>& path) {

			if (path.size() != dimensions_.size())
				throw std::out_of_range("Incorrect indexation.");
			int sz = path.size() - 1;
			size_t index = path[sz] >= dimensions_[sz] ? throw std::out_of_range("Out of massive range.") : path[sz--];

			for (int multi = 1; sz >= 0; sz--) {
				if (path[sz] >= dimensions_[sz])
					throw std::out_of_range("Out of massive range.");
				multi *= dimensions_[sz];
				index += path[sz] * multi;
			}
			return data_[index];
		}
		virtual ~Array() override {}
	};

	
	//Боже, простите меня за эту функцию, когда нибудь я сделаю вместо неё константную хэш таблицу для проверки совместимости типов, но это будет в другом коммите.
	constexpr bool convertableTypes(Types t1, Types t2) {
		switch (t1)
		{
		case language::Types::INT: {
			switch (t2)
			{
			case language::Types::INT:
				return true;
				break;
			case language::Types::FLOAT:
				return true;
				break;
			case language::Types::BOOL:
				return true;
				break;
			case language::Types::BYTE:
				return true;
				break;
			default:
				return false;
				break;
			}
		}
			break;
		case language::Types::FLOAT:
		{
			switch (t2)
			{
			case language::Types::INT:
				return true;
				break;
			case language::Types::FLOAT:
				return true;
				break;
			case language::Types::BOOL:
				return true;
				break;
			case language::Types::BYTE:
				return true;
				break;
			default:
				return false;
				break;
			}
		}
			break;
		case language::Types::BOOL: {
			switch (t2)
			{
			case language::Types::INT:
				return true;
				break;
			case language::Types::FLOAT:
				return true;
				break;
			case language::Types::BOOL:
				return true;
				break;
			case language::Types::BYTE:
				return true;
				break;
			default:
				return false;
				break;
			}
		}
			break;
		case language::Types::BYTE: {
			switch (t2)
			{
			case language::Types::INT:
				return true;
				break;
			case language::Types::FLOAT:
				return true;
				break;
			case language::Types::BOOL:
				return true;
				break;
			case language::Types::BYTE:
				return true;
				break;
			default:
				return false;
				break;
			}
		}
			break;
		case language::Types::ARRAY:
			return t2 == t1;
			break;
		case language::Types::SQUARE:
			return t2 == t1;
			break;
		}
	}
}