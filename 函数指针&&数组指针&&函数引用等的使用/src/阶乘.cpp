// declarations of our factorial functions
// definitions are in LocalMath.cc
#include "LocalMath.h"

#include <iostream>
using std::cout; using std::endl;



int main()
{
	cout << factorial(5) << endl;	// 计算阶乘的内置函数
	cout << fact(5) << endl;		//
	cout << factorial(0) << endl;
	cout << fact(0) << endl;

	return 0;
}

