/* 初步展示了运算符重载的使用 */
#include <iostream>
using std::cin; using std::cout; using std::endl;

#include "Sales_data.h"
#include "Sales_item.h"

int main() 
{
    Sales_item item1, item2;
    cin >> item1 >> item2;   // 读取一组交易
    // 打印两组交易的和
    cout << item1 + item2 << endl; 

	Sales_data data1, data2;
    read(read(cin, data1), data2);   // 第二种方式读取一种交易
    print(cout, add(data1, data2));  // 打印和
 	cout << std::endl; 

	cin >> data1 >> data2; // 直接使用输入运算符去读取交易
    // 直接输出两者的和
    cout << data1 + data2 << endl;  // 这里Sales_data应该对"<<"进行了重载

    return 0;
}
