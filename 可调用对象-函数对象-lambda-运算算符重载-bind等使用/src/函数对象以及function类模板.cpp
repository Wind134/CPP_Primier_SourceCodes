/* 介绍了函数对象以及function类模板 */
#include <iostream>
using std::cout; using std::endl; using std::ostream;

#include <map>
using std::map;

#include <string>
using std::string;

#include <functional>
using std::bind; 	// bind函数

// std::function是C++标准库中的一个类模板，它用于包装可调用对象(函数、函数指针、成员函数、Lambda 表达式等)
// 并提供一种统一的方式来存储、复制、传递和调用这些可调用对象。
using std::function;	
using namespace std::placeholders;

// ordinary function
int add(int i, int j) { return i + j; }	// 普通函数

// lambda, 它生成一个未命名的函数对象类
auto mod = [](int i, int j) { return i % j; };

// 这是一个函数对象类
// In the first printing we named this struct div, but that name conflicts with
// the name of a C library function.  Compilers are permitted to put
// C library names in the global namespace.  Future printings will
// change the name of this calss to divide.
struct divide {
    int operator()(int denominator, int divisor) {
        return denominator / divisor;
    }
};

int main()
{
	// 下面理解为一个function类型即可
	function<int(int, int)> f1 = add;      // f1是一个函数指针，其中函数有两个参数，返回类型为int
	function<int(int, int)> f2 = divide(); // f2是一个可调用对象类型
	function<int(int, int)> f3 = [](int i, int j) // f3是一个lambda
	                             { return i * j; };
	cout << f1(4,2) << endl; // prints 6
	cout << f2(4,2) << endl; // prints 2
	cout << f3(4,2) << endl; // prints 8

	// table of callable objects corresponding to each binary operator
	// all the callables must take two ints and return an int
	// an element can be a function pointer, function object, or lambda
	// 建立运算符与函数计算方式的映射
	map<string, function<int(int, int)>> binops = {
		{"+", add},                  // 加
		{"-", std::minus<int>()},    // 减，用了库函数，表明两个参数都是int
		{"/",  divide()},            // 除，用了函数对象
		{"*", [](int i, int j) { return i * j; }}, // 用lambda
		{"%", mod} };                // 取余

	cout << binops["+"](10, 5) << endl; // calls add(10, 5)
	cout << binops["-"](10, 5) << endl; // uses the call operator of the minus<int> object
	cout << binops["/"](10, 5) << endl; // uses the call operator of the divide object
	cout << binops["*"](10, 5) << endl; // calls the lambda function object
	cout << binops["%"](10, 5) << endl; // calls the lambda function object

	return 0;
}
