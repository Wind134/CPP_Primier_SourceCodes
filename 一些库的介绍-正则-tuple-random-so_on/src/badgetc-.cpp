/*
 * 展示了put函数
*/ 

#include <cstdio> // for EOF
#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
	char ch;    // using a char here invites disaster!

	// cin.get的返回值传递给char 
	// 然后与int进行比较
	while ((ch = cin.get()) != EOF)
         	cout.put(ch);		// put函数可以向输出流cout添加单个字符
	cout << endl;

	return 0;
}
