/*
 * 相比之前的类主要新增了一个hash的处理
*/ 

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

// 与14章节相比没什么改动，但是增加了一个友元声明用于后面的hash处理
class Sales_data {
friend class std::hash<Sales_data>;	// 针对该类的Hash处理
friend std::ostream &operator<<
                         (std::ostream&, const Sales_data&);
friend std::istream &operator>>(std::istream&, Sales_data&);
friend bool operator==(const Sales_data &, const Sales_data &);

friend std::ostream &print(std::ostream&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);
public:
	Sales_data() = default;
	Sales_data(const std::string &s): bookNo(s) { }
	Sales_data(const std::string &s, unsigned n, double p):
	           bookNo(s), units_sold(n), revenue(p*n) { }
	Sales_data(std::istream &);
	std::string isbn() const { return bookNo; }
	Sales_data& operator+=(const Sales_data&);
private:
	double avg_price() const;  
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

namespace std {			// 位于标准的命名空间内
template <>             // 我们为Sales_data的模板参数定义一个特例版本的hash
struct hash<Sales_data> 
{
    // 用来hash一个无序容器的类必须要定义这些类型
    typedef size_t result_type;			// 给size_t取一个新的别名为result_type，将已知的类型取一个别名，而不能反着来
    typedef Sales_data argument_type; 	// 同上，默认情况下，该类需要定义==运算符

    size_t operator()(const Sales_data& s) const;	// 用于计算哈希的函数的声明

    // 我们的类使用合成的拷贝控制以及默认构造函数
    // 其他成员如之前定义即可
};
}  // 关闭了std命名空间; 注意: 关闭大括号后并没有';'

// Sales_data的非成员操作符
inline
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{ return lhs.isbn() < rhs.isbn(); }

inline
bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn() && 
	       lhs.units_sold == rhs.units_sold && 
	       lhs.revenue == rhs.revenue;
}
inline
bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
	return !(lhs == rhs);
}

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);
std::ostream &operator<<(std::ostream&, const Sales_data&);
std::istream &operator>>(std::istream&, Sales_data&);
#endif
