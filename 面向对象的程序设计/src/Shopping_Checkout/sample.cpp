/*
 * Quote类的一个应用
*/ 

#include <iostream>
#include <cstddef>
using std::size_t;

using std::cout; 
using std::endl;
#include "Quote.h"

int main()
{
	Quote basic("0-201-54848-8", 45);	// ISBN，价格
	Bulk_quote bulk("0-201-82470-1", 45, 3, .15);	// 同一本书的数量，15折

	// basic是Quote类型; bulk是Bulk_quote类型
	print_total(cout, basic, 20); // 调用Quote版本的net_price 
	print_total(cout, bulk, 20);  // 调用Bulk_quote版本的net_price 
	Quote base("0-201-82470-1", 50);	// 一个新的对象
	Bulk_quote derived("0-201-82470-1", 50, 5, .19);	// 一个新对象的定义
	cout << derived.net_price(20); // 调用Bulk_quote::net_price
	cout << endl;

	base = derived;        // 复制derived的Quote部分到base
	cout << base.net_price(20);    // 此时调用Quote::net_price
	cout << endl;

	Quote &item = derived; // 某个类型的动态和静态类型不同
	cout << item.net_price(20);    // calls Bulk_quote::net_price(动态类型，运行时才绑定)

	item.isbn();           // isbn并非虚函数, 只能调用基类中的版本，即调用Bulk::isbn(静态类型)
	cout << endl;

	return 0;
}


