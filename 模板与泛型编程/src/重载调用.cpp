/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.

*/ 

#include <cstring>
using std::strcmp;

#include <iostream>
using std::cout; using std::endl;

// 第一个版本，可以比较两个任意的类型
template <typename T> int compare(const T&, const T&);

// 第二个版本：可以比较字面值常量
template<size_t N, size_t M>
int compare(const char (&)[N], const char (&)[M]);

// 特例化第一个版本
template <>
int compare(const char* const &, const char* const &);

// 通用函数模板的定义
template <typename T> int compare(const T& v1, const T& v2)
{
    cout << "base template" << endl;
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

// 第二个通用函数模板的定义
template<size_t N, size_t M>
int compare(const char (&p1)[N], const char (&p2)[M])
{
    cout << "array template" << endl;
	return strcmp(p1, p2);
}


// 特例化版本，比较两个C风格字符串的大小
template <>
int compare(const char* const &p1, const char* const &p2)
{
cout << "specialized template" << endl;
    return strcmp(p1, p2);
}

int main()
{
	const char *p1 = "hi", *p2 = "mom";
	compare(p1, p2);      // 调用第一个模板特例，因为更匹配参数，而不是调用T模板的那个
	compare("hi", "mom"); // calls the template with two nontype parameters
}
