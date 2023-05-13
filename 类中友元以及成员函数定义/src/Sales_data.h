/* 这是Sales_data.h的头文件 */

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

class Sales_data {
friend Sales_data add(const Sales_data&, const Sales_data&);	// 友元
friend std::ostream &print(std::ostream&, const Sales_data&);	// 输出
friend std::istream &read(std::istream&, Sales_data&);			// 输入
public:
	// constructors
	Sales_data() = default;	// 默认构造
	Sales_data(const std::string &s): bookNo(s) { }	// 带俩参数的构造函数
	Sales_data(const std::string &s, unsigned n, double p):	// 带三参数的构造函数
	           bookNo(s), units_sold(n), revenue(p*n) { }
	Sales_data(std::istream &);	// 流类型参数的构造函数

	// operations on Sales_data objects
	std::string isbn() const { return bookNo; }	// const代表括号内的内容不可变化
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};


// 最好要友元声明之外再专门对函数进行一次声明
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

// 后续章节要用到的内联函数
inline 
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}
#endif
