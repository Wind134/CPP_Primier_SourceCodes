/* 展示了equal函数的使用策略 */
#include <algorithm>
using std::equal;	// 判断迭代器范围内的元素是否相等，返回bool类型

#include <list>
using std::list;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

int main()
{
	list<const char *> roster1;	// 每个元素都是C风格的字符串
	vector<string> roster2;		// 每个元素是string类型的字符串
	roster2 = {"hello", "so long", "tata"};
	roster1 = {"hello", "so long"};

	auto b = 
	// roster2 should have at least as many elements as roster1
	equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());

	(b) ? cout << "true" : cout << "false";
	cout << endl;

	return 0;
}
