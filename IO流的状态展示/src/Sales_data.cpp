/* 该源文件针对头文件中声明的许多函数进行了具体定义 */
#include <iostream>
using std::istream; using std::ostream;

#include "Sales_data.h"

Sales_data::Sales_data(std::istream &is)	// 定义流类型参数的构造函数
{
	// read will read a transaction from is into this object
	read(is, *this);	// 把read理解为一个读取操作即可
}

// 返回平均值的函数
double 
Sales_data::avg_price() const {
	if (units_sold)
		return revenue/units_sold;
	else
		return 0;
}

// 等价于+=的效果
Sales_data& 
Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold; // 相加 
	revenue += rhs.revenue;       // ....
	return *this; 	// 返回本对象
}

Sales_data 
add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;  // copy data members from lhs into sum
	sum.combine(rhs);      // add data members from rhs into sum
	return sum;
}

// 定义read函数，参数为输入流以及Sales_data类型对象的引用
istream&
read(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream&	// 我改成void是不是一样可以
print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " 
	   << item.revenue << " " << item.avg_price();
	return os;
}
