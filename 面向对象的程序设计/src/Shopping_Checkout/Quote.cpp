/*
 * Quote类的具体实现
 * 各种方法的具体实现
*/ 

#include "Quote.h"

#include <algorithm>
using std::min;

#include <cstddef>
using std::size_t;

#include <iostream>
using std::ostream; using std::endl; 
using std::cout;

// 计算并打印给定份数的价格
double print_total(ostream &os, 
                   const Quote &item, size_t n)
{
	// 根据绑定到item参数的对象的类型，调用Quote::net_price或Bulk_quote::net_price
	// 主要原理是对基类的引用，也可以成为对派生类的引用，由于基类中的net_price方法定义为了虚函数
    // 因此如果该引用绑定到派生类，实质上会调用派生类中的net_price方法
	double ret = item.net_price(n); 
    os << "ISBN: " << item.isbn() // calls Quote::isbn
       << " # sold: " << n << " total due: " << ret << endl;
 	return ret;
}

// 购买了特定数量则采用折扣价 
double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= quantity)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

// 打折的部分折扣价
// 不打折的部分则正常价
double Lim_quote::net_price(size_t cnt) const
{
    size_t discounted = min(cnt, quantity);     // 折扣数量
    size_t undiscounted = cnt - discounted;     // 未折扣的数量
    return discounted * (1 - discount) * price 
           + undiscounted * price;
}

