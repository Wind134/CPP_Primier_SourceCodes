 #ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {     // 这是一个account账户类
public:
	Account() = default;    // 默认构造
	Account(const std::string &s, double amt):  // 自定义构造
		owner(s), amount(amt) { }

    void calculate() { amount += amount * interestRate; }   // interestRate代表的是利率
    double balance() { return amount; }         // 该函数获取余额
public:
    static double rate() { return interestRate; } // 返回利率，每个人的账户都要参考这个利率，因此定义为static的
    static void rate(double);                     // 更新利率的重载函数，每个人也同样要遵循的规则 
private:
    std::string owner;      // 账户持有人
    double amount = 0.0;    // 账户初始余额
    static double interestRate;     // 利率
    static double initRate() { return .0225; }  // 初始利率
    static const std::string accountType;       // 账户类型
    static constexpr int period = 30;// period是一个constant表达式，在编译时就能知道period大小
    double daily_tbl[period];        // daily_tabl是存款日期
};
#endif
