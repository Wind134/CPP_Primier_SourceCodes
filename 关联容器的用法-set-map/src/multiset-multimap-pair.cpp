/* multiset-multimap-pair等使用方式 */
#include <set>
using std::multiset;

#include <map>
using std::map;

#include <string>
using std::string;

#include <utility>
using std::pair;

#include <iostream>
using std::cout; using std::endl;

#include "Sales_data.h"      
#include "make_plural.h"

// SDComp指向一个比较两个Sales_data对象大小的函数
typedef bool(*SDComp)(const Sales_data&, const Sales_data&);	// typedef用法

// bookstore可以保存多个带有相同ISBN号的交易
multiset<Sales_data, decltype(compareIsbn)*> 
	bookstore(compareIsbn);

// 使用lambda方式定义的一种替代性方式
multiset<Sales_data, SDComp> 	// 这个函数指针本质上也是指向下面那个的返回类型
	bookstore2([](const Sales_data &l, const Sales_data &r)
                 { return l.isbn() < r.isbn(); });

int main() 
{
	map <string, size_t> word_count; // empty map
	
	// insert a value-initialized element with key Anna; 
	// assign 1 to the value of that element
	word_count["Anna"] = 1;  

	// 输出1，索引即是"Anna"
	cout << word_count["Anna"] << endl;  
	
	++word_count["Anna"];        // 自增
	cout << word_count["Anna"] << endl; // 打印2
	
	// 多种方式添加一个word->word_count
	string word; 
	word_count.insert({word, 1});	// 直接添加
	word_count.insert(make_pair(word, 1));	// 通过make_pair函数添加
	word_count.insert(pair<string, size_t>(word, 1));	// 通过pair构造函数添加
	word_count.insert(map<string, size_t>::value_type(word, 1));	// 本质上同上行一样，map的值类型：pair
	
	typedef map<string,size_t>::value_type valType;		// typedef重定义 
	word_count.insert(valType(word, 1));				// 构造函数方式

	
	
	// key为map类型的迭代器，value为bool类型
	pair<map<string, size_t>::iterator, bool> insert_ret;

	// 如果Anna不在word_count中, 插入这个词，并且对应的值为1
	// insert插入成功，返回的迭代器指向插入的元素
	// insert插入不成功，返回的迭代器指向已存在的元素
	insert_ret = word_count.insert({"Anna", 1});
	
	// 如果在word_count中存在，默认的second是0，这时候
	if (insert_ret.second == false)    	// Anna was already in the map
	    insert_ret.first->second++;    	// 自增当前map下的size_t类型元素的值
	cout << "Output: "<< word_count["Anna"] << endl;	// 输出3

	// get an iterator to an element in word_count
	auto map_it = word_count.begin();
	
	// *map_it is a reference to a pair<const string, size_t> object
	cout << map_it->first;         // word为空，不会打印出任何东西
	cout << " " << map_it->second; // prints the value of the element
	++map_it->second;     // ok: we can change the value through an iterator
	return 0;
}
