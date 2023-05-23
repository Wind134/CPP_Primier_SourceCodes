/* 通过可调用对象实现符合要求的数量计算 */
#include "make_plural.h"

#include <iostream>
using std::cin; using std::cerr; using std::cout; using std::endl;
using std::ostream;

#include <algorithm>
using std::for_each; using std::find_if; using std::stable_sort;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <cstddef>
using std::size_t;

// comparison function to be used to sort by word length
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

// determine whether a length of a given word is 6 or more
bool GT(const string &s, string::size_type m) 	// 判断字符长度是否>=6
{
    return s.size() >= m;
}

class SizeComp {	// 比较大小的类，一个函数对象，或者说函数对象类
public:
	SizeComp() = delete;  // 不存在默认构造
	SizeComp &operator=(const SizeComp&) = delete; // 不存在赋值运算符
	~SizeComp() = default;	// 默认析构

	// 为每一个捕获的变量，构造带一个参数的构造函数 
	SizeComp(size_t n): sz(n) { }  

	// 调用运算符，主函数体类似lambda
	// parameters, and body as the lambda
	bool operator()(const string &s) const { return s.size() >= sz; }
private:
	size_t sz;  // 要比较的值，通过一个参数去构造
};

class PrintString {	// 打印字符串的类
public:
	PrintString() = delete;   // no default constructor
	PrintString(ostream &o) : os(o) { }
	void operator()(const string &s) const { os << s << " "; }
private:
	ostream &os;
};

class ShorterString {
public:
	bool operator()(const string &s1, const string &s2) const
	{ return s1.size() < s2.size(); }
};

void elimDups(vector<string> &words)
{
    // sort words alphabetically so we can find the duplicates
    sort(words.begin(), words.end());

	// 打印出排序后的内容
	for_each(words.begin(), words.end(), PrintString(cerr));	// 第三个参数是一个可调用对象
	cerr << endl;

    // unique reorders the input so that each word appears once in the
    // front part of the range 
	// returns an iterator one past the unique range;
    auto end_unique = unique(words.begin(), words.end());

    // erase uses a vector operation to remove the nonunique elements
    words.erase(end_unique, words.end());

	// 打印去除重复之后的vector
	for_each(words.begin(), words.end(), PrintString(cerr));
	cerr << endl;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);  // 去除重复的单词

    // sort words by size using object of type ShorterString
	// 稳定排序维持相同大小的字符串的相对位置不变
    stable_sort(words.begin(), words.end(), ShorterString());

	// use object of type SizeComp to find
	// 找到第一个元素的size()大于等于sz的位置
    auto wc = find_if(words.begin(), words.end(), SizeComp(sz));

	// compute the number of elements with size >= sz 
	auto count = words.end() - wc;

	// print results
    cout << count << " " << make_plural(count, "word", "s")
         << " " << sz << " characters or longer" << endl;

	// use object of type PrintString
	// to print the contents of words, each one followed by a space
	for_each(wc, words.end(), PrintString(cout));	// 打印每一个大于等于的元素
	cout << endl;
}

int main()
{
    vector<string> words;

    // copy contents of each book into a single vector
    string next_word;
    while (cin >> next_word) {
        // insert next book's contents at end of words
        words.push_back(next_word);
    }

	biggies(words, 6);	// 根据输入的内容，输出仅有一个符合要求

	return 0;
}

