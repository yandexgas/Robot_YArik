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
		if ((Z)*t == 0)
			throw Script_error("division by zero");
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
			throw Script_error("This type can't be converted to tseloye.");
		}
		explicit virtual operator float() {
			throw Script_error("This type can't be converted to drobnoye.");
		}
		explicit virtual operator bool() {
			throw Script_error("This type can't be converted to logicheskoye.");
		}
		explicit virtual operator char() {
			throw Script_error("This type can't be converted to logicheskoye.");
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
		std::shared_ptr<Type> makeClone() const noexcept override {
			return std::make_shared<Math_type<T>>(value_, type);
		}
		void operator=(std::shared_ptr<Type> a) override {
			value_ = (T)*a;
		}
		operator int() override {
			return value_;
		}
		explicit operator float() override {
			return value_;
		}
		explicit operator bool()override {
			return value_;
		}
		const Types getType() const noexcept override {
			return type;
		}
		explicit operator char() override {
			return value_;
		}
		~Math_type() override {}
	};
	class Link : public Type {
	private:
		std::shared_ptr<Type> pointer_;
		bool inited = false;
		const Types getHideType() const noexcept override {
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
			else throw Script_error("Non initiallized memory access.");
		}
		std::shared_ptr<Type> makeClone() const noexcept override {
			return std::make_shared<Link>((*pointer_).makeClone());
		}
		void operator=(std::shared_ptr<Type> a) override;
		const Types getType() const noexcept override {
				return pointer_->getType();
		}

		explicit operator int() override {
			if (inited)
				return (int)*pointer_;
			else throw Script_error("Non initiallized memory access.");
		}
		explicit operator float() override {
			if (inited)
				return (float)*pointer_;
			else throw Script_error("Non initiallized memory access.");
		}
		explicit operator bool() override {
			if (inited)
				return (bool)*pointer_;
			else throw Script_error("Non initiallized memory access.");
		}
		explicit  operator char() override {
			if (inited)
				return (char)*pointer_;
			else throw Script_error("Non initiallized memory access.");
		}

		~Link() override {}
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
		const Types getType() const noexcept override { return Types::POINTER; }
		void operator=(std::shared_ptr<Type> ptr) override;
		std::shared_ptr<Type> makeClone() const noexcept override {

			return std::make_shared<Pointer>(ptr_);
		}
		operator bool() override {
			if (*ptr_)
				return true;
			else return false;
		}
		std::shared_ptr<Type> operator*() {
			return *ptr_;
		}
		~Pointer() override {}
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
		Square& operator=(Square val);
		const Types getType() const noexcept override {
			return type;
		}
		std::shared_ptr<Type> makeClone() const noexcept override {
			return std::make_shared<Square>(*X_, *Y_, *busy_);
		}
		void operator=(std::shared_ptr<Type> a) override;
		operator Square() {
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
		~Square() override {}
	};


	class Array : public Type
	{
	private:
		const Types type = Types::ARRAY;
		std::vector<std::shared_ptr<Link>> data_;
		std::vector<int> dimensions_;
	public:
		explicit Array(std::vector<int>& dimensions);
		Array(){}// Вроде даже не нужен будет
		Array(std::vector<int> dimensions, std::vector<std::shared_ptr<Link>> data);
		Array(Array& arr);
		Array(Array&& arr) noexcept ;
		Array& operator=(Array& arr);
		Array& operator=(Array&& arr) noexcept;
		std::vector<std::shared_ptr<Link>>& getDataLink() {
			return data_;
		}
		const Types getType() const noexcept override {
			return type;
		}
		 std::shared_ptr<Type> makeClone() const noexcept override {
			return std::make_shared<Array>(this->dimensions_,this->data_);
		}
		 void operator=(std::shared_ptr<Type> a) override;
		size_t getDimensionality()const noexcept {
			return dimensions_.size();
		}
		std::shared_ptr<Link> operator[](std::vector<int>& path);
		~Array() override {}
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