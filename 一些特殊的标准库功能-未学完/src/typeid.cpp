/*
 * typeid函数用于获取一个表达式的类型信息，返回一个type_info类型的对象，该对象包含有关表达式类型的信息。
 
 * 主要用途包括：
 * 运行时类型识别（RTTI）：可以在运行时确定一个对象的实际类型，而不仅仅是它的静态类型。
 * 通过typeid可以比较两个类型是否相同，或者确定一个对象是否是某个特定类型的实例。

 * 类型转换判断：可以使用typeid来判断一个对象是否可以转换为另一个类型。

 * 异常处理：在异常处理中，typeid可以用于确定抛出的异常类型，从而根据异常类型采取相应的处理措施。
*/ 

#include "Sales_data.h"

#include <iostream>
using std::cout; using std::endl;

#include <typeinfo>

#include <string>
using std::string;

struct Base {
    virtual ~Base() { }
};

struct Derived : Base { };

int main()
{
	int arr[10];
	Derived d;
	Base *p = &d;
	
	cout << typeid(42).name() << ", "	// 输出的name千奇百怪的
	     << typeid(arr).name() << ", "
	     << typeid(Sales_data).name() << ", "
	     << typeid(std::string).name() << ", "
	     << typeid(p).name() << ", "
	     << typeid(*p).name() << endl;
	
	return 0;
}
