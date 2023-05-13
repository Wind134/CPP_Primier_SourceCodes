/* 该函数针对Account头文件中的rate函数进行了实现
并且定义了账户类型和初始利率；
*/
#include <string>
using std::string;

#include "Account.h"

// define static data and function members
const string Account::accountType("Savings Account");   // 定义账户类型
double Account::interestRate = initRate();      // 定义初始利率

void Account::rate(double newRate)  // 更新利率的函数，只需要在声明的时候使用static关键字
{
    interestRate = newRate; 
}
