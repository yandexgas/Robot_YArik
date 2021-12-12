#pragma once
#include <iostream>
#include <list>
#include <variant>
#include <vector>
#include "Exceptions.h"

namespace SintaxTree {
	enum class DataTypes {
		TSELOYE,
		DROBNOYE,
		LOGICHESKOYE,
		MASSIV,
		YACHEYKA,
		VOID
	};

	class NamedObject {
	protected:
		std::string name_;
	public:
		NamedObject(std::string name) : name_(name) {}
		inline const std::string getName() const noexcept { return name_; }
		virtual DataTypes getType() const noexcept = 0;
		virtual bool isVariable() const noexcept = 0;
	};


	class Object :public  NamedObject {

	public:
		virtual bool isVariable() const noexcept override{
			return true;
		}
		operator float() {
			auto u = getType();
			switch (u)
			{
			case SintaxTree::DataTypes::TSELOYE: {
				return *(dynamic_cast<Int*>(this));
				break;
			}
			case SintaxTree::DataTypes::DROBNOYE:
				return *(dynamic_cast<Float*>(this));
				break;
			case SintaxTree::DataTypes::LOGICHESKOYE: {
				return *(dynamic_cast<Bool*>(this));
				break;
			}
			default:
				throw Convert_error("Trying to convert incompatible types ");
				break;
			}

		}

		operator Yacheyka() {
			if (getType() == DataTypes::YACHEYKA)
				return *(dynamic_cast<Yacheyka*>(this));
			else throw Convert_error("Trying to convert incompatible type to Yacheyka ");

		}
		operator Array() {
			if (getType() == DataTypes::MASSIV)
				return *(dynamic_cast<Array*>(this));
			else throw Convert_error("Trying to convert incompatible type to Massiv ");

		}
		Object(std::string name) : NamedObject(name) {}
	};

	class Function:public NamedObject {
	private:
		std::list<DataTypes> args_;
		std::list<std::shared_ptr<Object>> lastCallArgs_;
		std::shared_ptr<NamedObject> lastVal_;
		DataTypes type_;
		//указатель на начало
		//указатель на конец
	public:
		Function(std::string name, std::list<DataTypes> args, DataTypes type = DataTypes::VOID) : NamedObject(name), args_(args), lastCallArgs_(), lastVal_(nullptr), type_(type){};
		virtual DataTypes getType()const noexcept override {
			return type_;
		}
		// ƒќќѕ–≈ƒ≈Ћ»“№ ‘”Ќ ÷»ё
		std::shared_ptr<NamedObject> getVal(std::list<std::shared_ptr<Object>> args) {
			return lastVal_;
		}
		virtual bool isVariable() const noexcept override {
			return false;
		}

	};
	class Int : public Object {
	private:
		int value;
	public:
		Int(std::string name, int val = 0) :Object(name), value(val) {}
		virtual DataTypes getType() const noexcept override { return DataTypes::TSELOYE; }
		operator int() {
			return value;
		}
		Int& operator =(int val) {
			value = val;
			return *this;
		}
	};


	class Float : public Object {
	private:
		float value;
	public:
		Float(std::string name, float b = 0) :Object(name), value(b) {}
		virtual DataTypes getType() const noexcept { return DataTypes::DROBNOYE; };
		operator float() {
			return value;
		}
		Float& operator =(float val) {
			value = val;
			return *this;
		}
	};


	class Bool : public Object {
	private:
		bool value;
	public:
		Bool(std::string name, bool b = 0) :Object(name), value(b) {}
		virtual DataTypes getType() const noexcept { return DataTypes::LOGICHESKOYE; };
		operator bool() {
			return value;
		}
		Bool& operator =(bool val) {
			value = val;
			return *this;
		}
	};


	class Yacheyka : public Object {
	private:
		int X, Y;
		bool busy;
	public:
		Yacheyka(std::string name, int x, int y, bool busy = 0) :Object(name), X(x), Y(y), busy(busy) {}
		virtual DataTypes getType() const noexcept { return DataTypes::YACHEYKA; };
		inline int get_X()const noexcept { return X; }
		inline int get_Y()const noexcept { return Y; }
		inline bool isBusy()const noexcept { return busy; }
	};
	class Array : public Object {
	private:
		std::vector<std::shared_ptr<Object>> massiv;
		std::list<int> dimensions;
		int dimensionality;
		int count;
	public:
		Array(std::string name, std::list<int> dimensions = {}) : Object(name), dimensions(dimensions), count(0) {
			dimensionality = dimensions.size();
			if (dimensionality <= 0)
				throw Initial_error("Zero - dimension array has been declarated. Array must contain 1 or more dimensions");
		}
		operator bool() {
			Int i("a", 1);
			i = 1 + *(massiv[1]);
		}
		std::shared_ptr<Object> operator [](int i) {
			return massiv[i];
		}
		DataTypes getType() const noexcept override {
			return DataTypes::MASSIV;
		}
	};
}