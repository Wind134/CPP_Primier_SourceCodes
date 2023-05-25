/*
 * 对Quote类的简单使用
*/ 

#include <iostream>
using std::cout; using std::ostream;

#include "Quote.h"

int main()
{
	Quote base("0-201-82470-1", 50);
	print_total(cout, base, 10);    // 调用Quote::net_price，不打折
	
	Bulk_quote derived("0-201-82470-1", 50, 5, .19);
	print_total(cout, derived, 10); // 调用Bulk_quote::net_price，打折
	
	Quote *baseP = &derived;
	
	// 调用基类的版本，因为自身已经指定
	// 无视baseP的动态类型
	double undiscounted = baseP->Quote::net_price(42);

	cout << undiscounted << std::endl;
}
