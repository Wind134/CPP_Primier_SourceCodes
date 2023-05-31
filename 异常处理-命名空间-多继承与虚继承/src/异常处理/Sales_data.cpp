/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
*/ 
#include <string>
using std::istream; using std::ostream;

#include "Sales_data.h"
#include "bookexcept.h"

// 这个版本的运算符重载增加了判断isbn()是否一致的操作
Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
    if (isbn() != rhs.isbn())	// 继承了logic_error类
        throw isbn_mismatch("wrong isbns", isbn(), rhs.isbn());
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}


Sales_data 
operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum += rhs;	// 使用+=
	return sum;
}


// 与之前保持一致
namespace std {
size_t
hash<Sales_data>::operator()(const Sales_data& s) const
{
    return hash<string>()(s.bookNo) ^
           hash<unsigned>()(s.units_sold) ^
           hash<double>()(s.revenue);
}
}  // 注意，没有分号


// 保持一致
Sales_data::Sales_data(istream &is) 
{
	is >> *this;
}

double Sales_data::avg_price() const
{
	if (units_sold)
		return revenue/units_sold;
	else
		return 0;
}

istream &operator>>(istream &is, Sales_data &item)
{
	double price;  // no need to initialize; we'll read into price before we use it
	is >> item.bookNo >> item.units_sold >> price;
	if (is)        // check that the inputs succeeded
    	item.revenue = item.units_sold * price;
	else
    	item = Sales_data(); // input failed: give the object the default state
	return is;
}

ostream &operator<<(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " 
	   << item.revenue << " " << item.avg_price();
	return os;
}

// operators replace these original named functions
istream &read(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}
ostream &print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " 
	   << item.revenue << " " << item.avg_price();
	return os;
}
	
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;  // copy data members from lhs into sum
	sum += rhs;            // add rhs into sum
	return sum;
}

