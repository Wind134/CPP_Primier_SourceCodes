/* 
 * 
 */

#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr; using std::make_shared;

#include "Quote.h"

int main ()
{
	Quote base("0-201-82470-1", 50);  
	Bulk_quote bulk("0-201-54848-8", 50, 10, .25); 

	// 没问题: 但可能不是我们想要的---
	//     因为basket中的对象没有派生成员
	vector<Quote> basket;
	basket.push_back(Quote("0-201-82470-1", 50));

	// 没问题, 但只会复制对象的Quote部分进basket
	basket.push_back(Bulk_quote("0-201-54848-8", 50, 10, .25));  
	
	// 调用Quote定义的版本
	cout << basket.back().net_price(15) << endl;  
	
	// 更好的方式，存储指针而不是变量，这样便可以执行动态绑定
	vector<shared_ptr<Quote>> basket2;
	
	basket2.push_back(make_shared<Quote>("0-201-82470-1", 50));  
	basket2.push_back(
		make_shared<Bulk_quote>("0-201-54848-8", 50, 10, .25));  
	
	// 派生类调用派生类中定义的版本
	cout << basket2.back()->net_price(15) << endl; 

	return 0;
}
