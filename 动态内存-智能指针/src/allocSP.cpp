/* 分配智能指针 */

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <memory>	// 需要包含的头文件
using std::make_shared; using std::shared_ptr;

#include <iostream>
using std::istream; using std::ostream; 
using std::cin; using std::cout; using std::endl;

#include "Foo.h"

// factory returns a shared_ptr to a dynamically allocated object 
shared_ptr<Foo> factory(T arg)	// 创建一个返回指向Foo对象的指针
{
	// process arg as appropriate
	// shared_ptr will take care of deleting this memory
	return make_shared<Foo>(arg); 	// 由make_shared函数制造智能指针
}

shared_ptr<Foo> use_factory(T arg)
{
	shared_ptr<Foo> p = factory(arg);	// 定义一个指向Foo对象的智能指针p，该指针的值等于factory的返回值
	print(cout, *p);					// 执行打印功能
	cout << endl;
	// use p
	// shared_ptr当返回p的时候引用计数会增加1，因为返回的是一个指向相同对象的新智能指针
	// unique_ptr则执行移动操作，这是两者区别
	return p;  
} 

int main()
{
	T arg;
	while (cin >> arg)
		use_factory(arg);	// 尽管用，智能指针会自动处理空间的释放
}

