/* C++语句，处理异常与错误 */
#include <stdexcept>	// 提供了一些用于处理运行时异常的错误类
using std::runtime_error;

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include "Sales_item.h"

int main() 
{
	Sales_item item1, item2;
	
	while (cin >> item1 >> item2) {
	    try {
	        // execute code that will add the two Sales_items
	        // if the addition fails, the code throws a runtime_error exception
	        // first check that the data are for the same item 
	        if (item1.isbn() != item2.isbn())	// 两个输入的isbn号必须一致，否则报异常
	            throw runtime_error("Data must refer to same ISBN");
	
	        // if we're still here, the ISBNs are the same
	        cout << item1 + item2 << endl;
	    } catch (runtime_error err) {	// 捕捉错误，处理错误代码
	        // 当捕捉到错误时，提示用户重新输入
			// prompt for another pair
	        cout << err.what() 
	             << "\nTry Again?  Enter y or n" << endl;
	        char c;
	        cin >> c;
	        if (!cin || c == 'n')	// 如果输入出错或者选择了n
	            break;      // 则终止while循环
	    }  
	}
	
	return 0;   // indicate success
}
