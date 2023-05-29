/*
 * 针对头文件Blob.h的使用示例
*/ 

#include <iterator>
using std::begin; using std::end;

#include <list>
using std::list;

#include <vector>
using std::vector; 

#include <iostream>
using std::cout; using std::endl; 

#include <string>
using std::string;

#include <initializer_list>
using std::initializer_list;

#include <cstddef>
using std::size_t;

#include "Blob.h"

int main()
{
    Blob<int> ia;                // 空Blob<int>
	Blob<int> ia2 = {0,1,2,3,4};
	vector<int> v1(10, 0); // 10个元素，初始化为0
    Blob<int> ia3(v1.begin(), v1.end());  // copy elements from v1
    cout << ia << "\n" << ia2 << "\n" << ia3 << endl;

    // 这些定义实例化了两个不同的Blob类型，从这里可以看出的是，对于模板类，编译器无法自动推断类型，需要我们手写出实例化出的具体类型
    Blob<string> names; 
    Blob<double> prices;

	// 实例化出Blob<string>类以及它的
	// 初始化列表initializer_list<const char*>的构造函数
	Blob<string> articles = {"a", "an", "the"}; // three elements

	// 实例化出Blob<int>以及initializer_list<int>构造函数
	Blob<int> squares = {0,1,2,3,4,5,6,7,8,9};

	// 实例化出Blob<int>::size() const
    cout << squares << endl;
	for (size_t i = 0; i != squares.size(); ++i)  
		squares[i] = i*i; // 实例化出Blob<int>::operator[](size_t)
    cout << squares << endl;

	// 实例化出有两个vector<long>::iterator
	// 参数的Blob<int>构造函数
	vector<long> vl = {0,1,2,3,4,5,6,7,8,9};
	Blob<int> a1(vl.begin(), vl.end());   // 拷贝于vector

	// 实例化了Blob<int>类以及含有两个
	// int*参数的Blob<int>构造函数
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	Blob<int> a2(begin(arr), end(arr));   // 拷贝于数组

	list<int> li(10, 0);
	Blob<int> zeros(li.begin(), li.end());  // 拷贝于链表

    cout << a1 << "\n" << zeros << endl;

	a1.swap(zeros);
    cout << a1 << "\n" << zeros << endl;

	list<const char*> w = {"now", "is", "the", "time"};

	// 实例化了Blob<string>类以及有两个(list<const char*>::iterator
	// 参数Blob<string>构造函数 
	Blob<string> a3(w.begin(), w.end());

	return 0;
}
