/* 
 * 这是Query.h的头文件
 * 涉及到了纯虚函数
*/

#ifndef QUERY_H
#define QUERY_H
#include "TextQuery.h"
#include <string>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

// 抽象基类(定义了纯虚函数)作为具体查询类型的基类，其中所有成员都是私有的。
class Query_base {
    friend class Query; // 友元类Query，做接口，可以访问Query_base的所有数据  
protected:
    using line_no = TextQuery::line_no; // 在eval函数中会被使用
    virtual ~Query_base() = default;    // 析构函数，设定为虚函数，以便在资源释放时正确调用派生类自身的析构函数版本
private:
    // 下面这行的定义是一个纯虚函数的定义
    // 纯虚函数的目的是为了定义一些通用的接口，基类不需要具体的实现
    // 具体的实现由派生类来完成，而由于定义了纯虚函数，该基类不能被实例化
    virtual QueryResult eval(const TextQuery&) const = 0; 
    // rep是一个查询的string类型表示，同样定义为了纯虚函数
	virtual std::string rep() const = 0;
};

// 下面是管理Query_base继承层级的接口类
class Query {
    // 这些操作符需要有访问Query类中的shared_ptr构造器的权限
    friend Query operator~(const Query &);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    // 可以从定义中看到，执行的是WordQuery的构造函数
    Query(const std::string&);  // 该构造函数通过string类型的参数建立一个新的WordQuery

    // 接口函数: 调用相应的Query_base操作
    // 这里实现了对Query_base类中相关操作的执行
    QueryResult eval(const TextQuery &t) const 
                            { return q->eval(t); }
	std::string rep() const { return q->rep(); }
private:
    // 一个私有构造函数，参数为指向Query_base对象的指针类型
    // 该参数指向的Query_base对象就是q指向的对象；
    Query(std::shared_ptr<Query_base> query): q(query) { }
    
    // 私有成员，一个指向Query_base对象的指针(该指针既然指向基类，那么会指向派生类吗，答案是会的)
    // 该指针怎么调用派生类呢(目前存疑)
    std::shared_ptr<Query_base> q;
};

inline 
std::ostream &
operator<<(std::ostream &os, const Query &query) // 重载"<<"运算符
{
	// Query::rep通过其Query_base指针对rep()进行虚函数调用
    // 调用的又是谁的rep呢
	return os << query.rep(); 
}

// 继承Query_base的一个WordQuery类
class WordQuery: public Query_base {
    friend class Query; 
    WordQuery(const std::string &s): query_word(s) { }

    // WordQuery 定义了所有继承的纯虚函数
    QueryResult eval(const TextQuery &t) const
                     { return t.query(query_word); }
	std::string rep() const { return query_word; }  // 返回要查找的单词
    std::string query_word;   // 要查找的单词 
};

// Query使用WordQuery构造函数，从这里可以看到q指向的是一个WordQuery对象
// 因为WordQuery是衍生出来的派生类，因此指向基类的指针可以很轻易的转化为指向派生类的指针
// 但是q不能访问派生类中特有的方法
inline
Query::Query(const std::string &s): q(new WordQuery(s)) { }


// 继承Query_base的一个NotQuery类，即~对应的"非"
class NotQuery: public Query_base {
    friend Query operator~(const Query &);  // 定义友元
    NotQuery(const Query &q): query(q) { }  // 构造函数

    // concrete class: NotQuery实现了所有继承的纯虚函数
	std::string rep() const {return "~(" + query.rep() + ")";}
    QueryResult eval(const TextQuery&) const;   // 实现不在结果中的行数的返回
    
    // 下面这行是成员变量
    Query query;   
};

class BinaryQuery: public Query_base {
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s): 
          lhs(l), rhs(r), opSym(s) { }

    // 抽象类: BinaryQuery不定义eval，具体的实现由派生类来完成 
	std::string rep() const { return "(" + lhs.rep() + " " 
	                                     + opSym + " " 
		                                 + rhs.rep() + ")"; }

    Query lhs, rhs;    // 左右操作数
    std::string opSym; // 操作符名字
};
    
class AndQuery: public BinaryQuery {
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &left, const Query &right):        // 用继承的基类的构造函数来实现
                        BinaryQuery(left, right, "&") { }

    // 实现类: AndQuery继承了(基类的)rep同时定义了剩下的纯虚函数
    QueryResult eval(const TextQuery&) const;
};

class OrQuery: public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left, const Query &right): 
                BinaryQuery(left, right, "|") { }

    QueryResult eval(const TextQuery&) const;
};

// 下面三部分分别涉及到运算符的重载，运用了语法糖，以下面的为例，实际应用是
// Query(obj1) & Query(obj2) 
inline Query operator&(const Query &lhs, const Query &rhs)  // 相应的操作符继承相应的派生类
{
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

inline Query operator|(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

inline Query operator~(const Query &operand)
{
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}

std::ifstream& open_file(std::ifstream&, const std::string&);
TextQuery get_file(int, char**);
bool get_word(std::string&);
bool get_words(std::string&, std::string&);
std::ostream &print(std::ostream&, const QueryResult&);

#endif
