#pragma once

#include"Memory.h"
#include <regex>
namespace language {

	
	class LibFunction : public Function {
	public:
		LibFunction(std::list<fparam> param, std::optional<Types> type = {}, bool ptrType = false) : Function(param, type, ptrType) {}
		virtual std::optional<std::shared_ptr<MemoryCell>> operator()(std::list<std::shared_ptr<MemoryCell>>&) = 0;
		virtual std::optional<Node*> getPtr() {
			return std::nullopt;
		}
	};

	class PrintFunction : public LibFunction {
	public:
		PrintFunction(std::list<fparam> param, std::optional<Types> type = {}, bool ptrType = false): LibFunction(param, type, ptrType) {}
		virtual std::optional<std::shared_ptr<MemoryCell>> operator()(std::list<std::shared_ptr<MemoryCell>>& args) override {
			auto tmp = args.front();
			args.pop_front();
			auto b = tmp->getData()->getHideType() == Types::LINK ?
				**std::dynamic_pointer_cast<Link>(tmp->getData()) :
				tmp->getData();
			switch (tmp->getData()->getType())
			{
			case language::Types::INT:
				std::cout << (int)*(b);
				break;
			case language::Types::FLOAT:
				std::cout << (float)*(b);
				break;
			case language::Types::BOOL:{
				std::string busy = (bool)*(b) ? "istino" : "lozhno";
				std::cout << busy;}
				break;
			case language::Types::SQUARE:
			{
				auto print = std::dynamic_pointer_cast<Square>(b);
				std::string busy = (bool)*(print->getBusy()) ? "istino" : "lozhno";
				std::cout << '{' << (int)*(print->getX()) << ',' << (int)*(print->getY())<<',' << busy << '}';
			}
				break;
			case language::Types::BYTE:
				std::cout << (char)*(b);
				break;
			default:
				throw Script_error("No function with such tipes of parametrs.");
				break;
			}
			return std::nullopt;
		}
		static std::pair<std::string, std::shared_ptr<PrintFunction>> build(Types argType) {
			const std::string fun_name = "pechataem";
			std::list<fparam> param;
			fparam fst_arg;
			fst_arg.isPtr = false;
			fst_arg.name = "";
			fst_arg.type = argType;
			param.push_back(fst_arg);
			auto fptr = std::make_shared<PrintFunction>(param);
			return std::make_pair(fun_name, fptr);
		}
	};

	class ReadFunction : public LibFunction {
	private:
		template<Ariphmetical_result T>
		std::optional<std::shared_ptr<MemoryCell>> read(std::shared_ptr<Pointer> ptr, T readed, Types type) {
			bool res;
			std::cin >> readed;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				res = false;
			}
			else {
				res = true;
				(***ptr) = std::make_shared<Math_type<T>>(readed, type);
			}
			return std::make_shared<MemoryCell>(std::make_shared<Math_type<bool>>(res, Types::BOOL));
		}
		std::regex reg_square;
		std::cmatch result;
	public:
		ReadFunction(std::list<fparam> param, std::optional<Types> type = {}, bool ptrType = false) : LibFunction(param, type, ptrType) {
			std::regex rg("[{] *([0-9]+) *, *([0-9]+) *, *(istino|lozhno) *[}]");
			reg_square = rg;
		}
		virtual std::optional<std::shared_ptr<MemoryCell>> operator()(std::list<std::shared_ptr<MemoryCell>>& args) override {
			auto tmp = args.front();
			args.pop_front();
			auto b = std::dynamic_pointer_cast<Pointer>(tmp->getData());
			switch ((**b)->getType())
			{
			case language::Types::INT:
			{
				int readed=0;
				return read(b, readed, Types::INT);
			}
				break;
			case language::Types::FLOAT:
			{
				float readed=0;
				return read(b, readed, Types::FLOAT);
			}
				break;
			case language::Types::BOOL:
			{
				int readed=0;
				bool res;
				std::cin >> readed;
				if (std::cin.fail()) {
					std::cin.clear();
					std::string litera;
					std::cin >> litera;
					if (litera != "istino" && litera != "lozhno") {
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						res = false;
					}
					else if (litera == "istino")
						readed = true;
					else readed = false;
					(***b) = std::make_shared<Math_type<bool>>(readed, Types::BOOL);
				}
				else {
					res = true;
					(***b) = std::make_shared<Math_type<bool>>(readed, Types::BOOL);
				}
				return std::make_shared<MemoryCell> (std::make_shared<Math_type<bool>>(res, Types::BOOL));
			}
				break;
			case language::Types::SQUARE:
			{
				std::string readed;
				bool res;
				std::getline(std::cin, readed);
				if (std::regex_match(readed.c_str(), result, reg_square)) {
					int x, y;
					bool busy;
					x = std::stoi(result[1]);
					y = std::stoi(result[2]);
					busy = result[3] == "istino" ? true : false;
					res = true;
					(***b) = std::make_shared<Square>(x,y,busy);
				}
				else {
					res = false;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				return std::make_shared<MemoryCell>(std::make_shared<Math_type<bool>>(res, Types::BOOL));
			}
				break;
			case language::Types::BYTE:
			{
				char readed=0;
				return read(b, readed, Types::BYTE);
			}
				break;
			default:
				throw Script_error("No function with such tipes of parametrs.");
				break;
			}
		}
		static std::pair<std::string, std::shared_ptr<ReadFunction>> build(Types argType) {
			const std::string fun_name = "chitaem";
			std::list<fparam> param;
			fparam fst_arg;
			fst_arg.isPtr = true;
			fst_arg.name = "";
			fst_arg.type = argType;
			param.push_back(fst_arg);
			auto fptr=std::make_shared<ReadFunction>(param, Types::BOOL, false);
			return std::make_pair(fun_name, fptr);
		}
	};

	static std::shared_ptr<MemoryFrame> initStLib() {
		auto globalMem = std::make_shared<MemoryFrame>();
		auto read = ReadFunction::build(Types::BYTE);
		globalMem->insert(read.first, read.second);
		read = ReadFunction::build(Types::SQUARE);
		globalMem->insert(read.first, read.second);
		read = ReadFunction::build(Types::INT);
		globalMem->insert(read.first, read.second);
		read = ReadFunction::build(Types::FLOAT);
		globalMem->insert(read.first, read.second);
		read = ReadFunction::build(Types::BOOL);
		globalMem->insert(read.first, read.second);

		auto print = PrintFunction::build(Types::BYTE);
		globalMem->insert(print.first, print.second);
		print = PrintFunction::build(Types::SQUARE);
		globalMem->insert(print.first, print.second);
		print = PrintFunction::build(Types::INT);
		globalMem->insert(print.first, print.second);
		print = PrintFunction::build(Types::FLOAT);
		globalMem->insert(print.first, print.second);
		print = PrintFunction::build(Types::BOOL);
		globalMem->insert(print.first, print.second);

		return globalMem;
	}
}