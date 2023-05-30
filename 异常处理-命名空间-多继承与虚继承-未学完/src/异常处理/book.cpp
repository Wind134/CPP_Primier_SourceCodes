/*
 * 使用继承自logic_error的类
*/ 

#include "Sales_data.h"
#include "bookexcept.h"

#include <iostream>
using std::cin; using std::cerr; using std::endl;

int main()
{
    // 使用处理书店程序的错误类
    Sales_data item1, item2, sum;
    while (cin >> item1 >> item2) {  // read two transactions
        try {
            sum = item1 + item2;     // calculate their sum
            // use sum
        } catch (const isbn_mismatch &e) {
          cerr << e.what() << ": left isbn(" << e.left
               << ") right isbn(" << e.right << ")" << endl;
        }
    }
     return 0;
}
