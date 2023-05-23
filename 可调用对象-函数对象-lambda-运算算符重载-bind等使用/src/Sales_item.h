#ifndef SALESITEM_H // 理解为一个宏即可，定义了就不定义了
// we're here only if SALESITEM_H has not yet been defined 
#define SALESITEM_H

// Definition of Sales_item class and related functions goes here
#include <iostream>
#include <string>

class Sales_item {
// 这些声明书中270页的7.2.1会讲解 
// 同时在14章的557, 558, 561有详细说明
friend std::istream& operator>>(std::istream&, Sales_item&);        // input
friend std::ostream& operator<<(std::ostream&, const Sales_item&);  // output
friend bool operator<(const Sales_item&, const Sales_item&);        // compare 
friend bool 
operator==(const Sales_item&, const Sales_item&);
public:
    // 构造函数在书中262 - 265页的7.1.4章节有讲解 
    // 初始化内置成员需要一个默认构造函数
    Sales_item() = default; // 默认构造
    Sales_item(const std::string &book): bookNo(book) { }
    Sales_item(std::istream &is) { is >> *this; }   // 也是一种构造函数，参数为stream类型
public:
    // operations on Sales_item objects
    // member binary operator: left-hand operand bound to implicit this pointer
    Sales_item& operator+=(const Sales_item&);
    
    // operations on Sales_item objects
    std::string isbn() const { return bookNo; }
    double avg_price() const;
// private members as before
private:
    std::string bookNo;      // 隐式初始化为空字符串
    unsigned units_sold = 0; // 显式初始化
    double revenue = 0.0;
};

// 书中第十章有使用
inline
bool compareIsbn(const Sales_item &lhs, const Sales_item &rhs) 
{ return lhs.isbn() == rhs.isbn(); }

// nonmember binary operator: must declare a parameter for each operand
Sales_item operator+(const Sales_item&, const Sales_item&);

inline bool 
operator==(const Sales_item &lhs, const Sales_item &rhs)
{
    // must be made a friend of Sales_item
    return lhs.units_sold == rhs.units_sold &&
           lhs.revenue == rhs.revenue &&
           lhs.isbn() == rhs.isbn();
}

inline bool 
operator!=(const Sales_item &lhs, const Sales_item &rhs)
{
    return !(lhs == rhs); // != defined in terms of operator==
}

// assumes that both objects refer to the same ISBN
Sales_item& Sales_item::operator+=(const Sales_item& rhs) 
{
    units_sold += rhs.units_sold; 
    revenue += rhs.revenue; 
    return *this;
}   // +=运算符定义在类内

// assumes that both objects refer to the same ISBN
Sales_item 
operator+(const Sales_item& lhs, const Sales_item& rhs) 
{
    Sales_item ret(lhs);  // 拷贝复制
    ret += rhs;           // add in the contents of (|rhs|) 
    return ret;           // return (|ret|) by value
}   // ret是一个全新的对象，我们需要返回这个全新的对象

std::istream& 
operator>>(std::istream& in, Sales_item& s) // 两者都是引用
{
    double price;
    in >> s.bookNo >> s.units_sold >> price;
    // check that the inputs succeeded
    if (in)
        s.revenue = s.units_sold * price;
    else 
        s = Sales_item();  // input failed: reset object to default state
    return in;
}

std::ostream& 
operator<<(std::ostream& out, const Sales_item& s)
{
    out << s.isbn() << " " << s.units_sold << " "
        << s.revenue << " " << s.avg_price();
    return out;
}

double Sales_item::avg_price() const
{
    if (units_sold) 
        return revenue/units_sold; 
    else 
        return 0;
}
#endif
