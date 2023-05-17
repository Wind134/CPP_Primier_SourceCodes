/* find以及反转迭代器的应用 */
#include <string>
using std::string;

#include <algorithm>
using std::find;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
	string line;
	getline(cin, line);

	// find the first element in a comma-separated list
	auto comma = find(line.cbegin(), line.cend(), ',');	// 找到逗号所在位置，返回指向该元素的迭代器
	cout << string(line.cbegin(), comma) << endl;		// [cbegin(), comma - 1)
	
	// find the last element in a comma-separated list
	auto rcomma = find(line.crbegin(), line.crend(), ',');
	
	// 输出顺序反了
	cout << string(line.crbegin(), rcomma) << endl;
	
	// ok: 通过base转化为了正常迭代器
	cout << string(rcomma.base(), line.cend()) << endl;	// base返回正向迭代器形式

	return 0;
}
