/* 介绍了multimap特有的一些用法 */
#include <map>
using std::multimap;

#include <string>
using std::string;

#include <utility>
using std::pair;

#include <iostream>
using std::cout; using std::endl;

int main()
{
    // map from author to title; there can be multiple titles per author
    multimap<string, string> authors;
    // 插入每个作者的作品信息
    authors.insert({"Alain de Botton", "On Love"});
    authors.insert({"Alain de Botton", "Status Anxiety"});
    authors.insert({"Alain de Botton", "Art of Travel"});
    authors.insert({"Alain de Botton", 
		                      "Architecture of Happiness"});

    string search_item("Alain de Botton");      // 寻找作者
    auto entries = authors.count(search_item);  // 元素数量
    auto iter = authors.find(search_item);      // 找到第一个对应作者的条目

    // loop through the number of entries there are for this author
    while(entries) {
		cout << iter->second << endl; // 打印每个标题
		++iter;     // 自增
		--entries;  // keep track of how many we've printed
	}

    // lower_bound函数用于在有序容器中查找第一个大于或等于给定值的元素，并返回一个指向该元素的迭代器
    // upper_bound函数用于在有序容器中查找第一个大于给定值的元素，并返回一个指向该元素的迭代器
    // map中的key默认是从小到大排列
    for (auto beg = authors.lower_bound(search_item),
              end = authors.upper_bound(search_item);
		 beg != end; ++beg)
        cout << beg->second << endl; // print each title

    // equal_range函数返回一个相同key的迭代器范围，mutilmap特有的函数
    // pos holds iterators that denote the range of elements for this key
    for (auto pos = authors.equal_range(search_item);
         pos.first != pos.second; ++pos.first)
        cout << pos.first->second << endl; // print each title

	return 0;
}

