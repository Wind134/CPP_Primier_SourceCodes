/*
 * Quote定义的是一个书本类
 * 基于Quote定义了派生类Disc_quote
 * 基于Disc_quote又定义了一些具体的折扣策略类 
 */ 

#ifndef QUOTE_H
#define QUOTE_H

#include "Version_test.h"

#include <memory>
#include <iostream>
#include <string>
#include <cstddef>

// 基类中存有的是不打折的价格
// 派生类将会定义各种各样的折扣策略
class Quote {
friend std::istream& operator>>(std::istream&, Quote&);     // 重载输入输出运算符
friend std::ostream& operator<<(std::ostream&, const Quote&);
public:
	Quote() = default;  
    Quote(const std::string &book, double sales_price):
                     bookNo(book), price(sales_price) { }

    // virtual析构，以便派生类执行正确的析构函数
	// 如果一个指向基类的指针指向派生类，那么基类的析构则会被设定为deleted的
    virtual ~Quote() = default; // 针对析构函数的动态绑定

    std::string isbn() const { return bookNo; }

    // 返回同一序号的条目的总价
    // 派生类将会覆盖这个net_price函数，会有自己的定义
    virtual double net_price(std::size_t n) const 
               { return n * price; }

	// 虚函数，返回其动态分配的副本

    // 下面这部分的宏变量是基于Version_test.h中对版本的检测而做出的判断
#ifdef REFMEMS  // 说明编译环境是C++ 11标准之上的
    // 以下两个函数是针对左值引用和右值引用的重载
    virtual Quote* clone() const & {return new Quote(*this);}       // 左值引用限定，该成员函数只能被左值对象调用
    virtual Quote* clone() && {return new Quote(std::move(*this));} // 右值引用限定，该成员函数只能被右值对象调用
#else
	// without reference qualification on member functions
	// we can't overloaded on rvalue reference and const lvalue reference
	// so for now we just implement a single version that copies itself
    virtual Quote* clone() const {return new Quote(*this);}
#endif
private:
    std::string bookNo; // 条目的ISBN号
protected:
    double price = 0.0; // 正常价格
};

// 基于Quote派生出的抽象基类Disc_quote保存折扣以及购买的数量
// 派生类将会通过这些数据实现具体的定价策略
class Disc_quote : public Quote {
public:
    // other members as before
    Disc_quote() = default;
    Disc_quote(const std::string& book, double price,
              std::size_t qty, double disc):
                 Quote(book, price),
                 quantity(qty), discount(disc) { }      // 部分调用基类中的构造函数

    double net_price(std::size_t) const = 0;            // 具体计算方式设定为纯虚函数,没加关键字virtual是因为该类也是一个继承而来的类

    std::pair<size_t, double> discount_policy() const
        { return {quantity, discount}; }
protected:
    std::size_t quantity = 0; // 要应用折扣的购买数量
    double discount = 0.0;    // 分数形式
};

// 当一个特定ISBN号的书籍同时卖了几本以上时，折扣生效

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;  
    Bulk_quote(const std::string& book, double p, 
	           std::size_t qty, double disc) :
               Disc_quote(book, p, qty, disc) { }

    // override明确表示该函数是对一个虚函数的重载，要求参数等信息保持一致
    double net_price(std::size_t) const override;

#ifdef REFMEMS
    Bulk_quote* clone() const & {return new Bulk_quote(*this);}
    Bulk_quote* clone() && {return new Bulk_quote(std::move(*this));}
#else
    Bulk_quote* clone() const {return new Bulk_quote(*this);}
#endif
};

// 只针对某本书特定数量的折扣, 其他的按原价执行
class Lim_quote : public Disc_quote {
public:
    Lim_quote(const std::string& book = "", 
             double sales_price = 0.0,
             std::size_t qty = 0, double disc_rate = 0.0):
                 Disc_quote(book, sales_price, qty, disc_rate) { }

    // 同上
    double net_price(std::size_t) const;

#ifdef REFMEMS  // 这部分在Version_h头文件有详尽的说明，如果版本等于或高于C++11，则会定义REFEMES宏
    Lim_quote* clone() const & { return new Lim_quote(*this); }
    Lim_quote* clone() && { return new Lim_quote(std::move(*this)); }
#else
    Lim_quote* clone() const { return new Lim_quote(*this); }
#endif
};

double print_total(std::ostream &, const Quote&, std::size_t);

#endif

