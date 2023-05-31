/* 函数指针的应用
通过对这部分源码的学习，加强了对函数指针的理解 */
#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

// declarations (not strictly speaking necessary in this file)
string::size_type sumLength(const string&, const string&);
string::size_type largerLength(const string&, const string&);

// definition of these functions
string::size_type sumLength(const string &s1, const string &s2)
{
	return s1.size() + s2.size();
}

string::size_type largerLength(const string &s1, const string &s2)
{
	return (s1.size() > s2.size()) ? s1.size() : s2.size();
}

// depending on the value of its string parameter,
// getFcn returns a pointer to sumLength or to largerLength

// 三种方式声明getFcn 
// 1. use decltype
// 记得添加"*"符号
decltype(sumLength) *getFcn(const string &);	// getFcn函数返回size_type类型的指针

// 尾置返回类型返回响应的函数
auto getFcn(const string&) -> string::size_type(*)(const string&, const string&);

// 直接定义函数指针
string::size_type (*getFcn(const string&))(const string&, const string&);

// 定义getFcn
decltype(sumLength)* 	// sumLength函数返回类型的指针类型
getFcn(const string &fetch)	// 该函数返回的是上述类型
{
	if (fetch == "sum")
		return sumLength;
	return largerLength;	// 返回一个指针，该指针的类型是string::size_type*(这下就理解了)
}							// 因为函数名本身就是一个指针

int main()
{
	// "sum" is the argument to getFcn
	// ("hello", "world!") are arguments to the function getFcn returns
	cout << getFcn("sum")("hello", "world!") << endl;    // prints 11
	cout << getFcn("larger")("hello", "world!") << endl; // prints 6

	return 0;
}
