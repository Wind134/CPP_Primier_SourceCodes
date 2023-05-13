/* 类的构造函数&&列表初始化
涉及到stream对象的使用，以及字符串转换
 */
#include <vector>
using std::vector;

#include <string>
using std::string; 

#include <iostream>
using std::cout; using std::endl;

#include <initializer_list>
using std::initializer_list;

#include <sstream>
using std::ostringstream;

// 第七章会解释关于ErrCode的使用(就是类的使用)
struct ErrCode { 
	ErrCode(int i) : num(i) { }  // 构造函数
	string msg()                 // 成员函数
	{ ostringstream s; s << "ErrCode " << num; return s.str(); }	// str转换为C风格字符串
	int num;  // 数据成员错误码
};

// 使用类和初始化列表作为形参
void error_msg(ErrCode e, initializer_list<string> il)
{
	cout << e.msg() << ": ";
	for (const auto &elem : il)
		cout << elem << " " ;
	cout << endl;
}

// 仅单个初始化列表的形参
void error_msg(initializer_list<string> il)
{
	for (auto beg = il.begin(); beg != il.end(); ++beg)
		cout << *beg << " " ;
	cout << endl;
}

// 解释初始化列表返回值的函数
vector<string> functionX()
{
	string expected = "description", actual = "some other case";
	// . . .
	if (expected.empty())
		return {};  // return an empty vector
	else if (expected == actual)
		return {"functionX", "okay"}; // return list-initialized vector
	else 
		return {"functionX", expected, actual}; 
}
	
int main()
{
	string expected = "description", actual = "some other case";
	initializer_list<int> li = {0,1,2,3};

	// expected, actual are strings 
	if (expected != actual)
		error_msg({"functionX", expected, actual});	// 观察调用的函数的版本
	else
		error_msg({"functionX", "okay"});

	// expected, actual are strings 
	if (expected != actual)
		error_msg(ErrCode(42), {"functionX", expected, actual});	// 错误码42，输出后面初始化列表
	else
		error_msg(ErrCode(0), {"functionX", "okay"});
	
	// can pass an empty list, calls second version of error_msg
	error_msg({}); // 输出空行

	// call function that list initializes its return value
	// results is a vector<string>
	auto results = functionX();
	for (auto i : results) 
		cout << i << " ";
	cout << endl;
}

