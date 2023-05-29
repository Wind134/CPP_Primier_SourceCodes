/*
 * debug_rep的头文件
*/ 

#ifndef DEBUG_REP_H
#define DEBUG_REP_H
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

/* 该文件使用两个预处理器变量来控制我们是使用非模板函数，还是针对字符串数据
 * 使用特例化版本，并控制是否定义处理字符指针的debug_rep版本

 * 特例化函数模板和普通函数都用于处理特定类型的数据，但在语法上有所不同，并且在使用时需要注意函数的声明和定义位置。
 * 特例化函数模板通常在模板定义之后进行声明，以避免编译器在调用时找不到匹配的函数。
 * 而普通函数则可以直接定义在需要使用的位置。
 * 
 * 
 * OVERCHAR只在SPECIALIZED没定义的情况下生效；在这种情况下，
 * 如果OVERCHAR被定义了, 我们定义一个接受string的非模板函数
 * 如果OVERCHAR没被定义，我们也去定义一个接受char*和const char*的非模板函数
*/
#ifndef SPECIALIZED
std::string debug_rep(const std::string &s);	// 接受string的非模板函数
#ifndef OVERCHAR
std::string debug_rep(char *p);
std::string debug_rep(const char *cp);
#endif
#endif
// 重载的, 非特例化的函数模板
template <typename T> std::string debug_rep(const T &t);	// 针对const引用
template <typename T> std::string debug_rep(T *p);			// 针对指针
template <typename T> std::string debug_rep(T b, T e);		// 针对迭代器
template <typename T> std::string debug_rep(const std::vector<T> &v);	// 针对vector

/* 
 * SPECIALIZED如果被定义, 我们就针对string, char*, and const char*定义特例化版本
 * 同时不要再定义接受这些类型的非模板函数。
 */
#ifdef SPECIALIZED
// 特例化版本处理strings以及字符指针
// 特化版本的声明应该在所有重载模板的声明之后
// 这是定义了SPECIALIZED下的方案
template <> std::string debug_rep(const std::string&); 
template <> std::string debug_rep(const char*);
template <> std::string debug_rep(char*);
#endif

// 打印我们没有做任何特殊处理的任意类型
template <typename T> std::string debug_rep(const T &t)
{
#ifdef DEBUG	// 下面这行是debug语句
	std::cout << "const T&" << "\t";
#endif
	std::ostringstream ret; 
	ret << t; // 使用T重载过的输出运算符来打印t
	return ret.str();  // 返回输出字符流中的字符串
}

// 注意: 这一函数在char*下不会正常工作，因为
template <typename T> std::string debug_rep(T *p)
{
	std::cout << "Call debug_rep(T* )" << std::endl;
#ifdef DEBUG
	std::cout << "T*" << "\t";
#endif
	std::ostringstream ret;
	ret << "pointer: " << p;         // 打印指针值
	if (p)
		ret << " " << debug_rep(*p); // 打印指针指向的值
	else
		ret << " null pointer";      // 或者说明p是空指针
	return ret.str();	// 都通过这个返回string字符串
}
#ifndef SPECIALIZED
// 打印双引号内的字符串
std::string debug_rep(const std::string &s)
#else
template <> std::string debug_rep(const std::string &s)
#endif
{
#ifdef DEBUG
	std::cout << "const string &" << "\t";
#endif
	return '"' + s + '"';
}


#ifndef OVERCHAR
// 将字符指针转换为字符串，并调用debug_rep的字符串版本
std::string debug_rep(char *p) 
{
	return debug_rep(std::string(p));
}
std::string debug_rep(const char *p) 
{
	std::cout << "Call debug_rep(const char*)" << std::endl;
	return debug_rep(std::string(p));
}
#endif
#ifdef SPECIALIZED
template<> std::string debug_rep(char *p)
	{ return debug_rep(std::string(p)); }
template <> std::string debug_rep(const char *cp)
	{ return debug_rep(std::string(cp)); }
#endif

template <typename T> std::string debug_rep(T b, T e)
{
	std::ostringstream ret;
	for (T it = b; it != e; ++it) {
		if (it != b)
			ret << ",";            // 除了第一个元素，每个元素之前都打上一个逗号
		ret << debug_rep(*it);     // 打印元素
	}
	return ret.str();
}

template <typename T> std::string debug_rep(const std::vector<T> &v)	// 如果T是int会返回什么
{
	std::ostringstream ret;
	ret << "vector: [";
	ret << debug_rep(v.begin(), v.end());
	ret << "]";
	return ret.str();
}
#endif
