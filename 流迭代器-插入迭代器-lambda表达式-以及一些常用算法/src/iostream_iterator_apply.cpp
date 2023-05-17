/* 进一步介绍iostream_iterator */
#include <iterator>	// 以下使用输入流迭代器和输出流迭代器
using std::istream_iterator; using std::ostream_iterator;

#include <iostream>
using std::cin; using std::cout;

#include "Sales_item.h"

int main() 
{
	// iterators that can read and write Sales_items
	istream_iterator<Sales_item> item_iter(cin), eof;	// 输入元素的类型是Sales_item
	ostream_iterator<Sales_item> out_iter(cout, "\n");	// 每个元素输出到输出流cout中，并且添加'\n'

	// 存储第一笔交易
	Sales_item sum = *item_iter++; 

	while (item_iter != eof) {	// 只要输入不到头(没输入完)
		// if the current transaction (which is in item_iter) 
		// has the same ISBN
	    if (item_iter->isbn() == sum.isbn())
	        sum += *item_iter++; // add it to sum 
		                         // and read the next transaction
	    else {
	        out_iter = sum;      // write the current sum
	        sum = *item_iter++;  // read the next transaction
	    }
	}
	out_iter = sum;  // remember to print the last set of records

	return 0;
}
