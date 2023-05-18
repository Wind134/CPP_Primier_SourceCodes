
#include <string>
using std::string;

#include <list>
using std::list;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;

#include <iterator>
using std::istream_iterator; using std::ostream_iterator;

#include <utility>
using std::pair; using std::make_pair;

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include "Sales_data.h"

pair<string, string> anon;       // 保留着两个字符串-姓和名
pair<string, size_t> word_count; // 字符串出现的次数
pair<string, vector<int>> line;  // holds string and vector<int>

// list initialize the members in a pair
pair<string, string> author{"James", "Joyce"};

// ways to initialize a pair
typedef pair<string, string> Author;	// 
Author proust("Marcel", "Proust");  // construct a pair
Author joyce{"James", "Joyce"};     // list initialize a pair
Author austen = make_pair("Jane", "Austen"); // 使用make_pair函数

void preliminaries(vector<string> &v)	// 初步统计，将词汇存入一个vector，且以词汇长度从小->大排序
{
	// process v
	istream_iterator<string> input(cin), eof;
	copy(input, eof, back_inserter(v));
	sort(v.begin(), v.end(), 
	     [](const string &a, const string &b) 
	     { return a.size() < b.size(); });
}

// 三种方式返回一个pair
// 1. 以列表初始化形式返回值
pair<string, int>
process(vector<string> &v)
{
	if (!v.empty())
		return {v.back(), v.back().size()}; // list initialize
	else
		return pair<string, int>(); // explicitly constructed return value
}

// 2. 使用make_pair函数生成返回值
pair<string, int>
process2(vector<string> &v)
{
	// process v
	if (!v.empty())
		return make_pair(v.back(), v.back().size());
	else
		return pair<string, int>();
}

// 3. 显式构造返回值
pair<string, int>
process3(vector<string> &v)
{
	// process v
	if (!v.empty())
		return pair<string, int>(v.back(), v.back().size());
	else
		return pair<string, int>();
}

int main()
{
	vector<string> v;
	string s;
	while (cin >> s)
		v.push_back(s);

	preliminaries(v);  // sort v into size order

	// all three output statements should be the same 
	auto biggest = process(v);
	cout << biggest.first << " " << biggest.second << endl;
	biggest = process2(v);
	cout << biggest.first << " " << biggest.second << endl;
	biggest = process3(v);
	cout << biggest.first << " " << biggest.second << endl;
}
