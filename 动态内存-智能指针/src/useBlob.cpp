/* 使用我们之前定义的StrBlob */
#include <iostream>
using std::cout; using std::endl;

#include "StrBlob.h"

int main()
{
	StrBlob b1;	// 这是一个指针类
	// 下面用大括号专门锁定了作用域 
	{
	    StrBlob b2 = { "a", "an", "the" };
	    b1 = b2;  	// 默认拷贝构造吧
	    b2.push_back("about");
		cout << b2.size() << endl;
	}
	cout << b1.size() << endl;	// 由于是一个指针类，因此b1也会同步变化

	for (auto it = b1.begin(); neq(it, b1.end()); it.incr())
		cout << it.deref() << endl;

	return 0;
}
