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
		POINTER
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
	concept is_float = requires(T v, int i) {
		{v}  -> std::same_as<float>;
	};
	template <typename T>
	concept is_Int = requires(T v, int i) {
		{v}  -> std::same_as<int>;
	};
	template <typename T>
	concept is_Bool = requires(T v, int i) {
		{v}  -> std::same_as<bool>;
	};
	template <typename T>
	concept Ariphmetical_result = requires {
		is_Bool<T>
			|| is_Int<T>
			|| is_float<T>;
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

		virtual ~Type(){}
	};

	class Int : public Type
	{
	private:
		static const Types type = Types::INT;
		std::int32_t value_;
	public:
		Int() :value_(0) {};
		Int(std::int32_t value): value_(value){}
		Int(Int& v) : value_(v.value_) {}
		Int& operator=(std::int32_t val) {
			value_ = val;
			return *this;
		}
		virtual std::shared_ptr<Type> makeClone() const noexcept override  {
			return std::make_shared<Int>(value_);
		}
		virtual void operator=(std::shared_ptr<Type> a) {
			value_ = (int)*a;
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
		virtual ~Int() override{}
	};

	class Float : public Type
	{
	private:
		static const Types type = Types::FLOAT;
		float value_;
	public:
		Float() :value_(0) {};
		Float (float value) : value_(value) {}
		Float(Float& v) : value_(v.value_) {}
		Float& operator=(float val) {
			value_ = val;
			return *this;
		}
		virtual const Types getType() const noexcept override {
			return type;
		}
		virtual std::shared_ptr<Type> makeClone() const noexcept override  {
			return std::make_shared<Float>(value_);
		}
		virtual void operator=(std::shared_ptr<Type> a) {
			value_ = (float)*a;
		}
		virtual operator float() override {
			return value_;
		}
		explicit virtual operator int()override {
			return value_;
		}
		explicit virtual operator bool()override {
			return value_;
		}
		virtual ~Float() override {}
	};

	class Bool : public Type
	{
	private:
		static const Types type = Types::BOOL;
		bool value_;
	public:
		Bool () : value_(0) {};
		Bool(bool value) : value_(value) {}
		Bool(Bool& v) : value_(v.value_) {}
		Bool& operator=(bool val) {
			value_ = val;
			return *this;
		}
		virtual const Types getType() const noexcept override {
			return type;
		}
		virtual std::shared_ptr<Type> makeClone() const noexcept override {
			return std::static_pointer_cast<Type>(std::make_shared<Bool>(value_));
		}
		virtual void operator=(std::shared_ptr<Type> a) {
			value_ = (bool)*a;
		}
		explicit virtual operator float() override {
			return value_;
		}
		explicit virtual operator int()override {
			return value_;
		}
		virtual operator bool()override {
			return value_;
		}
		virtual ~Bool() override {}
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
			return pointer_;
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
				if (ptr_ && (**tmp).getType() != (**ptr_).getType())
					throw Type_error("Different pointer tipes");
				ptr_ = tmp;
			}
			else
				**ptr_ = ptr;
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
		virtual ~Pointer() {
			//			if(ptr_)
					//	delete ptr_;
		}
	};

	class Square : public Type
	{
	private:
		static const Types type = Types::SQUARE;
		std::shared_ptr<Int> X_;
		std::shared_ptr<Int> Y_;
		std::shared_ptr<Bool> busy_;
	public:
		Square() : X_(std::make_shared<Int>(0)), Y_((std::make_shared<Int>(0))), busy_((std::make_shared<Bool>(false))) {};
		Square(std::int32_t x, std::int32_t y, bool busy) : X_((std::make_shared<Int>(x))), Y_((std::make_shared<Int>(y))), busy_((std::make_shared<Bool>(busy))) {}
		Square(Square& v) : X_((std::make_shared<Int>(*v.X_))), Y_((std::make_shared<Int>(*v.Y_))), busy_((std::make_shared<Bool>(*v.busy_))) {}
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
			*this = (*std::dynamic_pointer_cast<Square>(a));
		}
		virtual operator Square() {
			return*this;
		}
		std::shared_ptr<Type> getY()const noexcept {
			return Y_;
		}
		Square& setY(std::int32_t val) {
			*Y_ = val;
		}
		std::shared_ptr<Type> getX()const noexcept {
			return X_;
		}
		Square& setX(std::int32_t val) {
			*X_ = val;
		}
		std::shared_ptr<Type> getBusy()const noexcept {
			return busy_;
		}
		Square& setBusy(bool val) {
			*busy_ = val;
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
				data_.push_back(std::make_shared<Link> (std::static_pointer_cast<Type>(std::make_shared<Bool>()),false));
			}
		}
		Array(){}
		Array(std::vector<int> dimensions, std::vector<std::shared_ptr<Link>> data) : dimensions_(dimensions) {
			for (auto a : data) 
				data_.push_back(std::dynamic_pointer_cast<Link>(a->makeClone()));
		}
		Array(Array& arr) :dimensions_(arr.dimensions_){
			for (size_t i = 0; i < arr.data_.size(); i++) {
				data_.push_back(std::make_shared<Link>(*arr.data_[i]));
			}
		}
		Array(Array&& arr) noexcept {
			data_ = std::move(arr.data_);
			dimensions_ = std::move(arr.dimensions_);
		}
		Array& operator=(Array& arr) {
			if (&arr != this) {
				dimensions_ = arr.dimensions_;
				for (size_t i = 0; i < arr.data_.size(); i++) {
					data_.push_back(std::make_shared<Link>(*arr.data_[i]));
				}
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
		virtual const Types getType() const noexcept override {
			return type;
		}
		virtual std::shared_ptr<Type> makeClone() const noexcept override {
			return std::make_shared<Array>(this->dimensions_,this->data_);
		}
		virtual void operator=(std::shared_ptr<Type> a) {
			*this = *std::dynamic_pointer_cast<Array>(a);
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