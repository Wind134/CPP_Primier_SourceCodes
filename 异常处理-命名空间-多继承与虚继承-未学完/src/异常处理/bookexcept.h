/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
*/ 

#ifndef BOOKEXCEPT_H
#define BOOKEXCEPT_H
#include <stdexcept>
#include <string>

// 书店应用程序的假设性异常类，继承自std::runtime_error类
class out_of_stock: public std::runtime_error {
public:
    explicit out_of_stock(const std::string &s):
                       std::runtime_error(s) { }    // 定义explicit的构造函数
};

class isbn_mismatch: public std::logic_error {
public:
    explicit isbn_mismatch(const std::string &s): 
                          std::logic_error(s) { }
    isbn_mismatch(const std::string &s,
        const std::string &lhs, const std::string &rhs):
        std::logic_error(s), left(lhs), right(rhs) { }
    const std::string left, right;
};

#endif
