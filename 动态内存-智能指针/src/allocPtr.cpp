/* 展示了普通指针下new与delete的配合使用 */ 
#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::istream; using std::ostream; 
using std::cin; using std::cout; using std::endl;

#include "Foo.h"

// factory returns a pointer to a dynamically allocated object 
Foo* factory(T arg)
{
	// process arg as appropriate
	return new Foo(arg); // 返回一个指向新的Foo对象的指针
}

Foo* use_factory(T arg)
{
	Foo *p = factory(arg);
	print(cout, *p);
	cout << endl;
	// use p
	return p;  // 函数调用负责清除内存
} 

int main()
{
	T arg;
	while (cin >> arg) {
		auto p = use_factory(arg);
		delete p; // 删除分配的空间
	}
	
	return 0;
}
