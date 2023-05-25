/* 声明了一个Basket类 */
#ifndef BASKET_H
#define BASKET_H

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <cstddef>
#include <stdexcept>
#include <memory>
#include "Quote.h"

// 保留已经购买的物件
class Basket {
public:
	// Basket使用默认的构造函数以及默认的拷贝控制成员
	void add_item(const std::shared_ptr<Quote> &sale)  
        { items.insert(sale); }

	void add_item(const Quote& sale) // 重载版本
      { items.insert(std::shared_ptr<Quote>(sale.clone())); }

	void add_item(Quote&& sale)      // 重载版本，去除了右值引用
      { items.insert(
	      std::shared_ptr<Quote>(std::move(sale).clone())); }

    // 打印每本书的价格以及
	// 篮子里所有书的总价
    double total_receipt(std::ostream&) const;

	// 打印内容，debug之用
	void display (std::ostream&) const;
private:
	// compare函数，isbn较小的在前
	static bool compare(const std::shared_ptr<Quote> &lhs,
	                    const std::shared_ptr<Quote> &rhs)
		{ return lhs->isbn() < rhs->isbn(); }

	// multiset来保存多个quotes, 通过compare来排序(有序集合)
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> 
	              items{compare}; 	// items是一个集合，其成员是一个指向Quote类型的智能指针
};

#endif
