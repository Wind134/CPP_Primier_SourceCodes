/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
*/ 

#include <cstddef>
using std::size_t;

#include <string>
using std::string;

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <unordered_set>
using std::unordered_multiset;

#include <functional>

#include "Sales_data.h"

using std::hash;

int main()
{
	// 使用了hash<Sales_data> and Sales_data operator== 
	unordered_multiset<Sales_data> SDset;   
	Sales_data item;
	while (cin >> item) {
		SDset.insert(item);
	}
	cout << SDset.size() << endl;

	return 0;
}
