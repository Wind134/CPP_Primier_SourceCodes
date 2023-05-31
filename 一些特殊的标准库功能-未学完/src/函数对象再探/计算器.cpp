/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
*/ 

#include <iostream>
using std::cout; using std::endl; 
using std::ostream;

#include <map>
using std::map;

#include <string>
using std::string;

#include <functional>
using std::bind; using std::function;
using namespace std::placeholders;

// this version of the desk calculator adds a class that
// represents both the left and right shift operators.
// This calss illustrates using pointers to member
// in the desk calculator
struct ShiftOps {
	ShiftOps(std::ostream &o) : os(o) { }
	unsigned Lshift(unsigned op1, unsigned op2) 	// unsigned代表一个无符号整数
	{ os << "Lshift: " << op1 << " " << op2 << endl; return op1 << op2; }
	unsigned Rshift(unsigned op1, unsigned op2) 
	{ os << "Rshift: " << op1 << " " << op2; return op1 >> op2; }
private:
	std::ostream &os;
};

// 初始函数，加法
int add(int i, int j) { return i + j; }

// lambda生成一个未命名的函数对象，取余
auto mod = [](int i, int j) { return i % j; };

// 函数对象类，地板除
struct divide {
    int operator()(int denominator, int divisor) {
        return denominator / divisor;
    }
};

int main()
{
	function<int(int, int)> f1 = add;      // f1是一个函数指针
	function<int(int, int)> f2 = divide(); // f2调用可调用对象
	function<int(int, int)> f3 = [](int i, int j) // lambda
	                             { return i * j; };
	cout << f1(4,2) << endl; // prints 6
	cout << f2(4,2) << endl; // prints 2
	cout << f3(4,2) << endl; // prints 8

	// 通过map将符号与函数名相互映射
	map<string, function<int(int, int)>> binops = {
		{"+", add},                  // 函数指针
		{"-", std::minus<int>()},    // 库函数对象
		{"/",  divide()},            // 用户定义的函数对象
		{"*", [](int i, int j) { return i * j; }}, // 未命名的lambda
		{"%", mod} };                // 命名的lambda

	cout << binops["+"](10, 5) << endl; 
	cout << binops["-"](10, 5) << endl; 
	cout << binops["/"](10, 5) << endl; 
	cout << binops["*"](10, 5) << endl; 
	cout << binops["%"](10, 5) << endl;


	// memp 指向左Lshift member，int (ShiftOps*, int, int)是一个函数
	// 参数类型是(ShiftOps*, int, int)，返回类型为int
	// 因为Lshift是ShiftOps内的函数，编译器会自动地将 ShiftOps::Lshift成员函数转换为一个普通的函数
	// 接受一个指向ShiftOps对象的指针作为第一个参数
	function<int (ShiftOps*, int, int)> memp = &ShiftOps::Lshift;  

	ShiftOps shift(cout);      // os绑定了cout
	binops.insert({"<<", bind(memp, &shift, _1, _2)}); 
	cout << binops["<<"](10, 5) << endl; // calls 成员函数
}
