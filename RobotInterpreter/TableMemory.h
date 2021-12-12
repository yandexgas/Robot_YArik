#pragma once
#include"DataTypes.h"
#include <unordered_map>
namespace SintaxTree {
	class MemoryTable {
	private:
		std::unordered_map <std::string, std::shared_ptr<NamedObject>> localMemory_;
		std::shared_ptr<MemoryTable> higerMemory_;
	public:
		void clear() {
			localMemory_.clear();
		}
		std::shared_ptr<NamedObject> operator[](std::string name) {
			if (localMemory_.contains(name))
				return localMemory_[name];
			else if (higerMemory_)
				return (*higerMemory_)[name];
			else return nullptr;
		}
	};
}