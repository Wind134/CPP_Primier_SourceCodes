/*
 * 结合了tuple，文件流fstream，运算符重载，以及equal_range函数的运用等多方面的知识点
 * 同时额外得到补充的知识点就是，ifstream支持通配符的操作，可以读取多份文件
 * 据C++标准库的规定，ifstream在打开符合通配符条件的多个文件时，会按照操作系统
 * 提供的文件系统顺序逐个打开并读取这些文件，而不是同时读取多份文件。
*/ 

// cassert是C++中的标准头文件，用于支持断言（assertion）功能。
// 它包含了一个宏函数assert，用于在程序中进行断言检查。
// 当断言条件为假时，assert宏将触发错误信息，并终止程序的执行。
#include <cassert>
#include <utility>
using std::pair;

#include <string>
using std::string; 

#include <tuple>	// 处理元组
using std::tuple; using std::get; 
using std::make_tuple;

#include <vector>
using std::vector;

#include <numeric>	// 包含了一些常用的数值计算函数
using std::accumulate; 

#include <algorithm>
using std::equal_range; 

#include <exception>	// 提供了异常处理的基本机制，用于处理程序在运行过程中可能遇到的错误和异常情况。
#include <stdexcept>	// 是exception头文件的子集(完全意义上的子集？)，提供了一些常见的异常类，用于表示不同类型的标准异常情况。
using std::domain_error;

#include <iostream>
using std::ostream; using std::istream;
using std::cout; using std::endl; 

#include <fstream>	// 文件流
using std::ifstream; 

#include "Sales_data.h"

bool lt(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}

// matches是针对每一个商店的tuple
typedef tuple<vector<Sales_data>::size_type,		// 第几个商店
              vector<Sales_data>::const_iterator,	// 访问Sales_data内容的迭代器起始位置
              vector<Sales_data>::const_iterator> matches;	// 访问Sales_data内容的迭代器结束

// 参数中的files保存每个商店的交易 
// 结合上述元组的定义，很容易理解返回的vector的每个条目表示售出给定书籍的具体店铺
vector<matches>
findBook(const vector<vector<Sales_data>> &files, 
         const string &book)
{
	vector<matches> ret;  // 初始化为空
	// 针对每一个店铺执行循环
	for (auto it = files.cbegin(); it != files.cend(); ++it) {
		// equal_range返回一个迭代器对，指明了有相同ISBN号的元素范围
		auto found = equal_range(it->cbegin(), it->cend(),
		                         book, compareIsbn);	// 是不是要假设有序(是的，要确保有序)，由于是二分查找，因此需要compareIsbn
		if (found.first != found.second)  // 如果有
			// 存储商店索引以及该范围的起始迭代器
			ret.push_back(make_tuple(it - files.cbegin(), 
                                  found.first, found.second));
	}
	return ret;
}

vector<Sales_data> build_store(const string &s)
{
	Sales_data item;
	vector<Sales_data> ret;
	ifstream is(s);	// 从s中读取信息
	while (read(is, item))
		ret.push_back(item);
	sort (ret.begin(), ret.end(), lt);  // 商店的每笔交易都必须有序
	return ret;
}

void reportResults(istream &in, ostream &os,
                   const vector<vector<Sales_data>> &files)
{
	string s;	// 书本
	while (in >> s) {
		auto trans = findBook(files, s);
		if (trans.empty()) {
			cout << s << " not found in any stores" << endl;
			continue;  // 继续执行循环
		}
		for (const auto &store : trans)   // 对于每个商店给定ISBN的交易
			// 输出每个商店的索引，以及该ISBN号书本的交易总额(Sales_data已经重载了+运算符)
			os << "store " << get<0>(store) << " sales: "
			   << accumulate(get<1>(store), get<2>(store), 
			                 Sales_data(s))
			   << endl;
	}
}

int main(int argc, char **argv)
{
	assert(argc > 1);

	vector<vector<Sales_data>> files;
	for (int cnt = 1; cnt != argc; ++cnt)
		files.push_back(build_store(argv[cnt]));

	ifstream in("../data/findbook.in");  // ISBNs to search for
	reportResults(in, cout, files);
}
