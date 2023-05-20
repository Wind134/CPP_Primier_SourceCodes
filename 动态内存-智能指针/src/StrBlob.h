/* 结合shared_ptr定义了一个StrBlob类，实现对string的管理 */

#ifndef STRBLOB_H
#define STRBLOB_H
#include <vector>
#include <string>
#include <initializer_list> // 包含初始化列表的处理
#include <memory>
#include <stdexcept>    // 异常处理

// 为了定义在StrBlob中的友元声明需要先进行需要前向声明
class StrBlobPtr;

class StrBlob {
	friend class StrBlobPtr;    // 默认为private权限
public:
    typedef std::vector<std::string>::size_type size_type;  // 定义数值类型

	// 构造函数提供了两种构造方式，data是一个指针类型，具体来说是一个指向string数组的智能指针
    // 非默认构造传入一个初始化列表类型的参数
    StrBlob() : data(std::make_shared<std::vector<std::string>>()) { }
    StrBlob(std::initializer_list<std::string> il);

	// 大小操作：返回string个数以及判断是否为空
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    // add and remove elements
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();    // 稍后定义

    // 返回的是具体元素的引用，神奇
    // std::string& front();
    // std::string& back();

	// interface to StrBlobPtr
	StrBlobPtr begin();  // 需要对StrBlobPtr先进行定义才能定义接下来的函数
    StrBlobPtr end();
private:
    std::shared_ptr<std::vector<std::string>> data;     // data
    // throws msg if data[i] isn't valid
    void check(size_type i, const std::string &msg) const;  // 当data[i]无效时抛出报错语句
};

// 对上述未构造的构造函数进行定义
inline
StrBlob::StrBlob(std::initializer_list<std::string> il):    // data指向那个初始化列表
              data(std::make_shared<std::vector<std::string>>(il)) { }

// StrBlobPtr在尝试访问一个不存在的元素时，抛出一个异常 
class StrBlobPtr {
	friend bool eq(const StrBlobPtr&, const StrBlobPtr&);   // 判
public:
    StrBlobPtr(): curr(0) { }
    // 因为要对StrBlob进行改变，因此采用引用方式
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }   // 默认位置是初始位置，但可自行指定

    std::string& deref() const; // 返回具体的元素
    StrBlobPtr& incr();       // prefix version
    StrBlobPtr& decr();       // prefix version
private:
    // check如果成功则返回一个指向vector的智能指针
    std::shared_ptr<std::vector<std::string>> 
        check(std::size_t, const std::string&) const;

    // 存储一个weak_ptr, 意味着底层的向量可能被销毁(因为该类就是为了核查是否异常？)
    std::weak_ptr<std::vector<std::string>> wptr;  
    std::size_t curr;      // 数组中目前的位置
};

inline
std::string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");   // 有异常这一步的执行会直接终止
    return (*p)[curr];  // (*p) is the vector to which this object points
}

inline
std::shared_ptr<std::vector<std::string>> 
StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
    // 如果expired为true，则lock返回一个空shared_ptr
    // 而expired的返回值取决于w的引用计数是否为0，为0则返回true
    auto ret = wptr.lock();   // is the vector still around?
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");

    if (i >= ret->size())
        /* 
        * 下面这个异常会被抛出的位置所在的函数中断执行，并开始在调用栈中寻找异常处理代码(异常处理程序)。
        * 如果找到匹配的异常处理程序，程序将进入该处理程序执行相应的逻辑，否则程序会终止并终止执行。 
        */ 
        throw std::out_of_range(msg);
    return ret; // 一切正常则返回智能指针
}

// prefix: 返回一个自增对象的引用
inline
StrBlobPtr& StrBlobPtr::incr()
{
    // if curr already points past the end of the container, can't increment it
    check(curr, "increment past end of StrBlobPtr");
    ++curr;       // 自增
    return *this;   // 返回对象
}

inline
StrBlobPtr& StrBlobPtr::decr()
{
    // 如果curr为0, 自减则无意义
    --curr;       // move the current state back one element}
    check(-1, "decrement past begin of StrBlobPtr");
    return *this;
}

// StrBlob的第一个和最后一个成员
inline
StrBlobPtr
StrBlob::begin() 
{
	return StrBlobPtr(*this);
}

inline
StrBlobPtr
StrBlob::end() 
{
	auto ret = StrBlobPtr(*this, data->size());
    return ret; 
}

// 判断等于
inline
bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	// if the underlying vector is the same 
	if (l == r) 
		// 如果他们都是空的或者他们指向了相同的元素 
		// 那么这两个StrBlob相等
		return (!r || lhs.curr == rhs.curr);
	else
		return false; // if they point to difference vectors, they're not equal
}

// 判断不等于，非等于就是不等于
inline
bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !eq(lhs, rhs); 
}
#endif
