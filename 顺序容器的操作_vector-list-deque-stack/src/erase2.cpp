/* 增加了单向链表的处理策略以及对应的erase_after函数 */
#include <algorithm>
using std::find; 

#include <string>
using std::string; 

#include <list>
using std::list;

#include <forward_list>		// 单向链表
using std::forward_list;

#include <vector>
using std::vector; 

#include <iostream>
using std::cout; using std::endl;

int main() 
{
	// lst has ten elements 0 ... 9 in value
	list<int> lst = {0,1,2,3,4,5,6,7,8,9};	// 将链表初始化

	// print the initial values in lst
	cout << "initial list: ";
	for (auto it : lst)
		cout << it << " ";
	cout << endl;

	// erase the odd elements in lst
	auto it = lst.begin(); 
	while (it != lst.end())
		if (*it % 2)             // 如果元素是奇数，就erase
			it = lst.erase(it);  // erase之后，it指向的是下一个元素，继续判断
		else
			++it;

	// print the current contents of lst
	cout << "after erasing odd elements from lst: ";
	for (auto it : lst)
		cout << it << " ";
	cout << endl;
	
	// 重复一样的动作，但这次是在单向链表上处理
	forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9};

	// print the initial values in flst
	cout << "initial list: ";
	for (auto it : flst)
		cout << it << " ";
	cout << endl;

	// 同样erase奇数
	// 但是由于是单向链表，其中使用的erase_after较为特殊，因为单向链表需要一个保留前驱的变量(单链表的特点决定的)
	auto prev = flst.before_begin(); 	// 第一个元素之前的位置
	auto curr = flst.begin();     		// 首元素
	while (curr != flst.end()) {  		// 只要有元素就执行循环 
		if (*curr % 2)                     // 如果元素为奇数
	    	curr = flst.erase_after(prev); // erase it and move curr 
		else {
			prev = curr; // 更新prev
			++curr;      // 判断下一个数
		}
	}

	// print the current contents of lst
	cout << "after erasing elements from flst: ";
	for (auto it : flst)
		cout << it << " ";
	cout << endl;

	return 0;
}
