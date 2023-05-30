/*
 * 让cin读取空格
*/ 

#include <iostream>
using std::cin; using std::cout;
using std::noskipws; using std::skipws;

int main()
{
	char ch;
	cin >> noskipws;  // 设置cin读取空格
	while (cin >> ch)
		cout << ch;
	cin >> skipws;    // 重置到默认

	return 0;
}
