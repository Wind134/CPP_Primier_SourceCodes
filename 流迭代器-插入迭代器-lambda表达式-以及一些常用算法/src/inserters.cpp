/* 介绍了插入迭代器的使用 */
#include <algorithm>
using std::copy;

#include <list>
using std::list;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

#include <iterator>	// 下面使用了插入迭代器，一个是正常插入的迭代器，一个是往前面方向插入的迭代器
using std::inserter; using std::front_inserter;	// 插入迭代器返回值是一个插入迭代器的对象

void print(const string &label, const list<int> &lst)
{
	cout << label << endl;
	for (auto iter : lst)
        cout << iter << " ";
    cout << endl;
}

int main() 
{

    list<int> lst = {1,2,3,4};	// 默认是双向链表
	print("lst", lst);

    // after copy completes, lst2 contains 4 3 2 1
	list<int> lst2, lst3;     // empty lists
    copy(lst.cbegin(), lst.cend(), front_inserter(lst2));	// 前向插入

    // after copy completes, lst3 contains 1 2 3 4
    copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));	// 从lst3的起始位置插入(指定位置)

	print("lst2", lst2);
	print("lst3", lst3);
	
	vector<int> v = {1,2,3,4,5};
	list<int> new_lst = {6,7,8,9};
	auto it = new_lst.begin();
	copy(v.begin(), v.end(), inserter(new_lst, it));
	print("new_lst", new_lst);

	return 0;
}
