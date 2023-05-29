/*
 * 展示了可变参数模板的用法

*/ 

#include <initializer_list>
using std::initializer_list;

#include <iostream>
using std::ostream; using std::cout; using std::endl;

#include <algorithm>
using std::min;

#include <string>
using std::string;

#include "Sales_data.h"

// 结束递归，打印最后一个元素
// 需要在下一个函数之前声明，切记
template<typename T> 
ostream &print(ostream &os, const T &t)
{
	return os << t; //
}


template <typename T, typename... Args> 	// 模板参数包
ostream &print(ostream &os, const T &t, const Args&... rest)	// 函数参数包
{
	os << t << ", ";           // 打印第一个参数
	return print(os, rest...); // 递归调用，打印其余参数
}

template <typename T> bool bigger(const T &t, initializer_list<T> il)
{
	if (il.size() == 0)
		return false;
	auto b = il.begin();
	while (b != il.end())
		if (t < *b)
			return true;
		else
			++b;
	return false;
}

// 注意: list中的元素必须是相同的类型
template <typename T> T min_elem(initializer_list<T> il)	// 注意，返回类型是T
{
	if (il.size() == 0)
		throw "empty";
	auto b = il.begin();      // 我们知道列表中至少有一个元素
	T ret(*b++);              // 给第一个元素赋值
	while (b != il.end())     // 不断更新，直到最后一个
		ret = min(ret, *b++);
	return ret;               // 返回我们找到的值
}


// 定义了可变参数模板的递归退出条件
template<typename T> T min_elem(const T &v)
{
	return v;
}

template <typename T, typename... Back>
T min_elem(T val, Back... back)
{
	// 递归调用
	T val2 = min_elem(back...); 

	// 要最小值
	return val < val2 ? val : val2;   
}

int main()
{
	// 调用可变参数版本
	cout << min_elem(1.0,2,3,4.5,0.0,5,6,7,8,9) << endl;

	// 调用初始化列表版本
	cout << min_elem({1,2,3,4,0,5,6,7,8,9}) << endl;

	int i = 5;
	cout << bigger(i, {1,2,3,4,0,5,6,7,8,9}) << endl;

	string s = "how now brown cow";
	print(cout, i, s, 42, '\n');  // two parameters in the pack
	print(cout, i, s, '\n');      // one parameter in the pack
	print(cout, i);         // no parameters in the pack
	cout << endl;

	return 0;
}

