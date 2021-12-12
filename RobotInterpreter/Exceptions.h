#pragma once
#include <exception>
#include <iostream>
#include<string>
	class SintaxTree_Exception : public std::exception
	{
	private:
		char incorrect_char;
	public:
		SintaxTree_Exception(char ch) :exception("unexpected symbol or incorrect operation usage: "), incorrect_char(ch) {};
		SintaxTree_Exception(std::string ch) :exception(ch.c_str()), incorrect_char('\0') {};
		friend std::ostream& operator <<(std::ostream& out, SintaxTree_Exception& st) {
			out << st.what() << st.incorrect_char << std::endl;
			return out;
		}
	};

	class Initial_error : public std::exception
	{
	private:
	public:
		Initial_error(std::string ch) :exception(ch.c_str()) {};
		friend std::ostream& operator <<(std::ostream& out, Initial_error& st) {
			out << st.what()  << std::endl;
			return out;
		}
	};
	class Convert_error : public std::exception
	{
	private:

	public:
		Convert_error(std::string ch) :exception(ch.c_str()) {};
		friend std::ostream& operator <<(std::ostream& out, Convert_error& st) {
			out << st.what() << std::endl;
			return out;
		}
	};

	class Type_error : public std::exception
	{
	private:
		std::string type1, type2;
		int line;
		const char* msg = "There are no operation with such tipes:";
	public:
		Type_error(std::string ch) :exception(ch.c_str()) {};
		Type_error(int line, std::string t1="incompletable", std::string t2="") : exception((msg+t1+ ' '+ t2+ "\nLine: "+ std::to_string(line)).c_str()), line(line), type1(t1), type2(t2) {}

		friend std::ostream& operator <<(std::ostream& out, Type_error& st) {
			out << st.what()<< std::endl;
			return out;
		}
	};

	class Array_size_error :public std::exception {
	private:
		size_t dimension;
		int incorrect_size;
		const std::string msg = "Size of dimension must bi positive.";

	public:
		Array_size_error(size_t dim, int size) :exception((msg).c_str()) {};
		
		friend std::ostream& operator <<(std::ostream& out, Array_size_error& st) {
			out << st.what() << "\nDimension number: "<< std::to_string(st.dimension) <<"\nCurrent size: "<< std::to_string(st.incorrect_size) << std::endl;
			return out;
		}
	};
	class Redefinition_error :public std::exception {
	private:
		size_t dimension;
		int incorrect_size;
		const std::string msg = "Size of dimension must bi positive.";

	public:
		Redefinition_error(size_t dim, int size) :exception((msg).c_str()) {};
		Redefinition_error(std::string ch) :exception(ch.c_str()) {};
		friend std::ostream& operator <<(std::ostream& out, Redefinition_error& st) {
			out << st.what() << std::endl;
			return out;
		}
		
	};
	class Call_error :public std::exception {
	private:
		size_t dimension;
		int incorrect_size;
		const std::string msg = "Size of dimension must bi positive.";

	public:
		Call_error(size_t dim, int size) :exception((msg).c_str()) {};
		Call_error(std::string ch) :exception(ch.c_str()) {};
		friend std::ostream& operator <<(std::ostream& out, Call_error& st) {
			out << st.what()  << std::endl;
			return out;
		}
	};
