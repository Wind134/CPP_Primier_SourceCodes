/* 这是Sales_data的具体实现 */

#include "Sales_data.h"
#include <string>
using std::istream; using std::ostream;

Sales_data::Sales_data(istream &is) 
{
	is >> *this; // read a transaction from is into this object
}

double Sales_data::avg_price() const
{
	if (units_sold)
		return revenue/units_sold;
	else
		return 0;
}

// member binary operator: left-hand operand is bound to the implicit this pointer
// assumes that both objects refer to the same book
Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

// assumes that both objects refer to the same book
Sales_data 
operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;  // copy data members from lhs into sum
	sum += rhs;            // add rhs into sum
	return sum;
}

/* 
* 假设有一个对象Sales_data sales;
cin >> sales;	// 这个就要求输入数据以Sales_data的数据格式进行输入 
*/
istream &operator>>(istream &is, Sales_data &item)	// 这是对运算符">>"的重载
{
	double price;  // no need to initialize; we'll read into price before we use it
	is >> item.bookNo >> item.units_sold >> price;
	if (is)        // 检查输入是否成功
    	item.revenue = item.units_sold * price;
	else
    	item = Sales_data(); // 输入失败则默认为空
	return is;
}

ostream &operator<<(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " 
	   << item.revenue << " " << item.avg_price();
	return os;
}

// read函数返回的是输入流对象
istream &read(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;	// 输入流依次把数据传入bookNo units_sold price
	item.revenue = price * item.units_sold;
	return is;	// 返回输入流
}
// print函数返回的是输出流对象
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

