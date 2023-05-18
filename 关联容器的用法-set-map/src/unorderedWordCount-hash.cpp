
#include <unordered_map>	// 无序map
using std::unordered_map;

#include <unordered_set>
using std::unordered_set; using std::unordered_multiset;

#include <string>
using std::string; 

using std::hash;

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <cstddef>
using std::size_t;

#include "Sales_data.h"

// 无序map版本词汇数目统计程序
int main() 
{
	// count occurrences, but the words won't be in alphabetical order
    unordered_map<string, size_t> word_count;  
    string word;
    while (cin >> word)
		++word_count[word]; // fetch and increment the counter for word

	for (const auto &w : word_count) // for each element in the map
		// print the results
		cout <<  w.first << " occurs " << w.second 
		     << ((w.second > 1) ? " times" : " time") << endl;

	return 0;
}

// 以下函数展示了怎么重写key类型的默认hash和相等运算符
size_t hasher(const Sales_data &sd) 
{
	// hash<string>()来创建一个针对string类型的哈希函数对象
	// 通过调用sd.isbn()来对Sales_data对象的isbn成员进行哈希操作
	return hash<string>()(sd.isbn());
}
bool eqOp(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn();
}

// 使用我们自定义的hasher和eqOp来定义multiset(两个都是函数指针的形式)
using SD_multiset = unordered_multiset<Sales_data, 
                    decltype(hasher)*, decltype(eqOp)*>;

// bookstore can hold multiple Sales_data with the same ISBN
// arguments are the bucket size 
// and pointers to the hash function and equality operator
SD_multiset bookstore(42, hasher, eqOp);	// 函数名做指针传递进去，42代表了桶的数目

// 怎样仅仅重写hash函数
// Foo must have ==
struct Foo { string s; };

// 重载了"=="运算符，无序set/map需要
bool operator==(const Foo& l, const Foo&r) { return l.s == r.s; }

size_t FooHash(const Foo& f) { return hash<string>()(f.s); }	// FooHash的返回值

// use FooHash to generate the hash code; Foo must have an == operator
unordered_set<Foo, decltype(FooHash)*> fooSet(10, FooHash);

