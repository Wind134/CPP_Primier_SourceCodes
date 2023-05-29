/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
*/ 

#include <iostream>
using std::cout; using std::endl;

#include <type_traits>
using std::remove_reference;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "Blob.h"


// 使用尾置类型推断返回类型
template <typename It>
auto reffcn(It beg, It end) -> decltype(*beg)
{
    return *beg;  // 返回range中某个元素的拷贝
}

// 使用remove_reference中的type
// 去掉引用
template <typename It>
auto valfcn(It beg, It end) -> 
	typename remove_reference<decltype(*beg)>::type
{
    return *beg;
}

int main()
{
	vector<int> vi = {1,2,3,4,5};
	Blob<string> ca = { "hi", "bye" };

	auto &i = reffcn(vi.begin(), vi.end()); // reffcn应该返回int&
	auto &s = reffcn(ca.begin(), ca.end()); // reffc应该返回string&


	vi = {1,2,3,4};
	for (auto i : vi) cout << i << " "; cout << endl;
	auto &ref = reffcn(vi.begin(), vi.end());  // ref是int&
	ref = 5; // changes the value of *beg to which ref refers
	for (auto i : vi) cout << i << " "; cout << endl;

	auto val = valfcn(vi.begin(), vi.end()); // val is int
	cout << val << endl;  // will print 5
	
	return 0;
}

