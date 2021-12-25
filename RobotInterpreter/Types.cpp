#include "Types.h"

namespace language {
	void Link::operator=(std::shared_ptr<Type> a) {
		if (a->getHideType() != Types::LINK)
			pointer_ = (*a).makeClone();
		else
			pointer_ = (**std::dynamic_pointer_cast<Link>(a))->makeClone();
		inited = true;
	}
	void Pointer::operator=(std::shared_ptr<Type> ptr) {
		if (ptr->getType() == Types::POINTER) {
			auto tmp = std::dynamic_pointer_cast<Pointer>(ptr)->ptr_;
			if (ptr_ && (**tmp).getType() != (**ptr_).getType())
				throw Script_error("Different pointer tipes");
			ptr_ = tmp;
		}
		else
			throw Script_error("Type can not be converted to pointer");
	}

	Square& Square::operator=(Square val) {
		*X_ = *(val.X_);
		*Y_ = *(val.Y_);
		*busy_ = *(val.busy_);
		return *this;
	}

	void Square::operator=(std::shared_ptr<Type> a){
		auto tmp = std::dynamic_pointer_cast<Square>(a);
		if (tmp)
			*this = *tmp;
		else throw Script_error("This object can't be converted to square.");
	}

	Array::Array(std::vector<int>& dimensions) : dimensions_(dimensions) {
		int mult = 1;
		for (auto i : dimensions_)
			mult *= i;
		if (mult < 0)
			throw std::length_error("Too much elements in massiv");// Вообще тут еще сразу проверка и на нулевые элементы
		for (int i = 0; i < mult; i++) {
			data_.push_back(std::make_shared<Link>(std::make_shared<Math_type<char>>(Types::BYTE), false));
		}
	}

	Array::Array(std::vector<int> dimensions, std::vector<std::shared_ptr<Link>> data) : dimensions_(dimensions) {
		for (auto a : data)
			data_.push_back(std::dynamic_pointer_cast<Link>(a->makeClone()));
	}

	Array::Array(Array& arr) :dimensions_(arr.dimensions_) {
		for (auto a : arr.data_)
			data_.push_back(std::dynamic_pointer_cast<Link>(a->makeClone()));
	}
	Array::Array(Array&& arr) noexcept {
		data_ = std::move(arr.data_);
		dimensions_ = std::move(arr.dimensions_);
	}

	Array& Array::operator=(Array& arr) {
		if (&arr != this) {
			dimensions_ = arr.dimensions_;
			data_.clear();
			for (auto a : arr.data_)
				data_.push_back(std::dynamic_pointer_cast<Link>(a->makeClone()));
		}
		return *this;
	}
	Array& Array::operator=(Array&& arr) noexcept {
		if (&arr != this) {
			data_ = std::move(arr.data_);
			dimensions_ = std::move(arr.dimensions_);
		}
		return *this;
	}

	void Array::operator=(std::shared_ptr<Type> a) {
		auto tmp = std::dynamic_pointer_cast<Array>(a);
		if (tmp)
			*this = *tmp;
		else
			throw Script_error("Object can't be converted to array.");
	}

	std::shared_ptr<Link> Array::operator[](std::vector<int>& path) {

		if (path.size() != dimensions_.size())
			throw std::out_of_range("Incorrect indexation.");
		int sz = path.size() - 1;
		size_t index = path[sz] >= dimensions_[sz] ? throw Script_error("Out of massive range.") : path[sz--];

		for (int multi = 1; sz >= 0; sz--) {
			if (path[sz] >= dimensions_[sz])
				throw Script_error("Out of massive range.");
			multi *= dimensions_[sz];
			index += path[sz] * multi;
		}
		return data_[index];
	}
}