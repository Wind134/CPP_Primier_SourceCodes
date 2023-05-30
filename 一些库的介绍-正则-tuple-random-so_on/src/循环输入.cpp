/*
 * 循环输入
*/ 

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
	char ch;
	while (cin >> ch)
		cout << ch;
	cout << endl;

	return 0;
}
