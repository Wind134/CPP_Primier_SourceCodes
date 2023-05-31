/* erase函数的使用 */
#include <algorithm>	// 包含了很多常用的算法
using std::find; 

#include <string>
using std::string; 

#include <list>			// 是一个双向链表实现序列容器
using std::list;

#include <vector>
using std::vector;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
	list<string> slist;
	string s;
	while (cin >> s)
		slist.push_back(s);  // 将输入的内容s加入到slist中

	/* 第十章将会解释find函数
	 * find会在第一和第二个迭代器参数表示的序列中查找第三个参数所提供的值
	 * 如果存在该值将返回指向第一个该值的迭代器，如果不存在则返回end迭代器
	*/
	auto iter = find(slist.begin(), slist.end(), "Quasimodo");
	if (iter != slist.end())	// 如果找到了，erase掉
	     slist.erase(iter);
	
	auto orig = slist; // 在清楚slist之后保存一个副本
	slist.clear();
	cout << "after clear, size is: " << slist.size() << endl;
	
	slist = orig; // restore the data
	slist.erase(slist.begin(), slist.end()); // 同clear等价
	cout << "after erase begin to end, size is: " << slist.size() << endl;
	
	slist = orig; // 恢复数据
	auto elem1 = slist.begin(), elem2 = slist.end();
	// 删除迭代器之间的所有元素
	// 返回一个迭代器，该迭代器指向上一个移除的元素的后面那个元素
	elem1 = slist.erase(elem1, elem2); // 调用之后一定有elem1 == elem2
	cout << "after erase elem1 to elem2 size is: " << slist.size() << endl;
	
	if (elem1 != elem2)
		cout << "somethings wrong" << endl;
	else
		cout << "okay, they're equal " << endl;
	
}
