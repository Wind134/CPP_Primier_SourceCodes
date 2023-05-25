/* 对Basket头文件的具体实现 */

#include "Quote.h"
#include "Basket.h"

#include <cstddef>
using std::size_t;

#include <set>
using std::multiset; 

#include <string>
using std::string; 

#include <iostream>
using std::ostream; using std::endl; 
using std::cout;

// 获取购物篮中商品的信息的debugging方法
void Basket::display(ostream &os) const
{
    os << "Basket size: " << items.size() << endl;  // 书本总数

    // 打印篮子里同一书本ISBN号的数目以及价格
    // upper_bound返回集合中下一个不同ISBN号的书本的迭代器位置
    for (auto next_item = items.cbegin();
              next_item != items.cend();
              next_item = items.upper_bound(*next_item))    // 由于是基于isbn的排列，因此upper_bound也会基于这个判断
    {
        // 只要存在于集合，说明某个ISBN的书本至少会有一本
        os << (*next_item)->isbn() << " occurs " 
           << items.count(*next_item) << " times" 
           << " for a price of " 
           << (*next_item)->net_price(items.count(*next_item))  // 价格打印的是总价
           << endl;
    }
}

// 打印总价
double Basket::total_receipt(ostream &os) const
{
    double sum = 0.0; 

    for (auto iter = items.cbegin(); 
              iter != items.cend();
              iter = items.upper_bound(*iter)) 
    {
        sum += print_total(os, **iter, items.count(*iter));  
    } 
	os << "Total Sale: " << sum << endl; // print the final overall total
    return sum;
}

