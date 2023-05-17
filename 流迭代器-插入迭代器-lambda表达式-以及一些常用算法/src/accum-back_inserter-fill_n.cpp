/* 介绍了accumlate函数以及back_inserter迭代器以及fill_n的用法 */
#include <vector>
using std::vector;

#include <string>
using std::string;

#include <algorithm>
using std::fill; using std::fill_n;	// fill函数为简单的填充，fill_n则连续填充指定数量的元素为给定的值

#include <numeric>	// C++ 标准库中的头文件，它提供了各种数值算法和数值操作的函数和类模板
using std::accumulate;	// 累加函数

#include <iterator>
using std::back_inserter;	// 用于创建一个迭代器，将元素插入容器的末尾。

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
	vector<int> vec(10);              // default initialized to 0
	fill(vec.begin(), vec.end(), 1);  // 每个元素填充1

	// 累加vec当中的每个元素
	int sum = accumulate(vec.cbegin(), vec.cend(), 0);	// 0这个参数代表的是初始值
	cout << sum << endl;
	
	// 一半填充为10
	fill(vec.begin(), vec.begin() + vec.size()/2, 10);
	cout << accumulate(vec.begin(), vec.end(), 0) << endl;

	// reset the same subsequence to 0
	fill_n(vec.begin(), vec.size()/2, 0);	// 从首元素开始，填充一半size的0
	cout << accumulate(vec.begin(), vec.end(), 0) << endl;

	// 从vec的末尾开始，连续插入10个42
	fill_n(back_inserter(vec), 10, 42);
	cout << accumulate(vec.begin(), vec.end(), 0) << endl;
	
	// 将vector中所有string字符串连接在一起，并存储在sum当中 
	vector<string> v;
	string s;
	while (cin >> s)
		v.push_back(s);
	string concat = accumulate(v.cbegin(), v.cend(), string(""));	// 这个加执行的是字符串的"+"
	cout << concat << endl;
	
	return 0;
}

