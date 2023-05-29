/*
 * 函数对象类，但该函数时函数模板
*/ 

#ifndef DEBUGDELETE_H
#define DEBUGDELETE_H

#include <cstddef>
#include <iostream>
#include <string>

// 调用删除一个给定的指针的函数对象类
class DebugDelete {
public:
	DebugDelete(const std::string &s = "unique_ptr",
                std::ostream &strm = std::cerr): os(strm), type(s) { }
	// as with any function template, the type of T is deduced by the compiler
	template <typename T> void operator()(T *p) const 
	  { os << "deleting " << type << std::endl; delete p; }
private:
	std::ostream &os;  // where to print debugging info
	std::string type;  // what type of smart pointer we're deleting
};

#endif
