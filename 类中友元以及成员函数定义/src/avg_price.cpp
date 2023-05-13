/* 这里保证的是连续两次输入的变量是否是一直 */
#include <iostream>
using std::cerr; using std::cin; using std::cout; using std::endl;

#include "Sales_data.h"

int main()
{
	Sales_data total;         // 存储交易和的变量
	if (read(cin, total))  {  // 这里也证明了用流类型的用意，读取第一次输入的变量
		Sales_data trans;     // 存储下一笔交易的变量
		while(read(cin, trans)) {      // 读取交易
			if (total.isbn() == trans.isbn())   // 如果两者ISBN一致
				total.combine(trans);  // 更新和
			else {						// 如果不一样
				print(cout, total) << endl;  // 这里就说明了不能用void了，因为endl需要一个流对象输出
				total = trans;               // 读取下一笔交易
			}
		}
		print(cout, total) << endl;          // print the last transaction
	}
	else 
	{                                 // there was no input
		cerr << "No data?!" << endl;         // notify the user
	}

	return 0;
}
