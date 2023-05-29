/*
 * 这是一个自定义类Blob的头文件
 * 
*/ 

#ifndef BLOB_H
#define BLOB_H

#include <iterator>
#include <string>
#include <vector>
#include <initializer_list>
#include <cstddef>
#include <stdexcept>
#include <utility>
#include <memory>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <stdexcept>



// 友元需要，因此前向声明
template <typename> class BlobPtr;	// 类模板，功能是指向Blob  
template <typename> class Blob;		// Blob本身是一个模板类
template <typename T>	// 函数模板
    bool operator==(const Blob<T>&, const Blob<T>&);	

// 下面是类模板的具体定义
template <typename T> class Blob {
	friend class BlobPtr<T>;	// BlobPtr，顾名思义，也就是指向Blob的指针
	friend bool operator==<T>
	       (const Blob<T>&, const Blob<T>&);
public:
	typedef T value_type;	// 数据类型
	typedef typename std::vector<T>::size_type size_type;	// 大小的类型

	// 构造函数
	Blob(); 
	Blob(std::initializer_list<T> il);	// 考虑参数是初始化列表的情形
	
	// 迭代器类型的参数
	// b、e分别指代容器中元素的起、始位置
	// 不论是该迭代器具体指向的是哪个类型，在后续的
	// 具体定义中都交给vector来处理
	template <typename It> Blob(It b, It e);

	Blob(T*, std::size_t);	// 给定初始地址，然后限定大小(像是数组情形)

	// 返回首指针和末尾指针
	BlobPtr<T> begin() { return BlobPtr<T>(*this); }	// 为何是BlobPtr类型，因为是指针类型
	BlobPtr<T> end() 
	    { auto ret = BlobPtr<T>(*this, data->size()); 
	      return ret; }

	// Blob中的元素数量，判空逻辑
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	// 增加和移除元素
	void push_back(const T &t) {data->push_back(t);}	// 左值
	void push_back(T &&t) { data->push_back(std::move(t)); }	// 右值，需要通过move函数单独处理一波
	void pop_back();

	// 元素权限
	T& front();			// 返回的是元素的引用
	T& back();
	T& at(size_type);	// 返回指定位置的元素
	// 针对常量版本的对象返回常量版本的值
	const T& back() const;	
	const T& front() const;
	const T& at(size_type) const;
	T& operator[](size_type i);	// 定义了运算符[] 
	const T& operator[](size_type i) const;	// 常量版本

	void swap(Blob &b) { data.swap(b.data); }	// 交换Blob对象，本质上就是交换Blob对象中的数据
private:
	std::shared_ptr<std::vector<T>> data; 		// 指向vector的智能指针

	// 如果data[i]无效，就抛出msg
	void check(size_type i, const std::string &msg) const;
};


// 构造函数的详细定义
template <typename T>	// 这里要求带上typename
Blob<T>::Blob(T *p, std::size_t n): 
              data(std::make_shared<std::vector<T>>(p, p + n)) { }

template <typename T>
Blob<T>::Blob():
	          data(std::make_shared<std::vector<T>>()) { }

template <typename T>     // 类的类型参数T
template <typename It>    // 构造函数的类型参数，因此两部分都要写全
    Blob<T>::Blob(It b, It e):
              data(std::make_shared<std::vector<T>>(b, e)) { }	// 其实从std::vector<T>>(b, e)可以看到，要求得是迭代器类型

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il): 
              data(std::make_shared<std::vector<T>>(il)) { }

// 这是Blob类中的check成员
template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

// 元素访问成员
template <typename T>	// 同样加上了模板名T
T& Blob<T>::front()
{
	// 若是向量为空，则会抛出下列语句
	check(0, "front on empty Blob");
	return data->front();
}

template <typename T>
T& Blob<T>::back() 
{
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T> void Blob<T>::pop_back() 
{
	check(0, "pop_back on empty Blob"); 
	data->pop_back(); 
}

template <typename T>
const T& Blob<T>::front() const 
{
	check(0, "front on empty Blob");
	return data->front();
}

template <typename T>
const T& Blob<T>::back() const 
{
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
T& Blob<T>::at(size_type i) 
{
	// if i is too big, check will throw, preventing access to a nonexistent element
	check(i, "subscript out of range");
	return (*data)[i];  // (*data) is the vector to which this object points
}

template <typename T>
const T&
Blob<T>::at(size_type i) const
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
	// 如果i过大, check 将会抛出下列语句，阻止对不在范围内的元素的读取
	// "[]"符号本身就是at函数的运算符形式
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
const T& 
Blob<T>::operator[](size_type i) const
{
	check(i, "subscript out of range");
	return (*data)[i];
}

// 重载"<<"运算符
template <typename T>
std::ostream&
operator<<(std::ostream &os, const Blob<T> a)
{
	os << "< ";
	for (size_t i = 0; i < a.size(); ++i) 
		os << a[i] << " ";
	os << " >";
	return os;
}

// 重载"=="运算符
template <typename T>
bool
operator==(const Blob<T> lhs, const Blob<T> rhs)
{
	if (rhs.size() != lhs.size())
		return false;
	for (size_t i = 0; i < lhs.size(); ++i) {
		if (lhs[i] != rhs[i])
			return false;
	}
	return true;
}

// BlobPtr的等于逻辑判断，先声明
template <typename T>
bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);

// std::bidirectional_iterator_tag是C++标准库中的一个迭代器标签类型，用于表示
// 迭代器的特性。它指示BlobPtr迭代器是双向迭代器，即可以向前和向后遍历元素的迭代器。
// 这个标签类型通常用于泛型算法中，以确定迭代器支持的操作和行为。
// 在使用迭代器时，可以使用这个标签来进行类型萃取或编译时判断，以选择适当的算法或优化措施。
template <typename T> class BlobPtr : public std::iterator<std::bidirectional_iterator_tag, T> {
	friend bool 
	operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
public:
    BlobPtr(): curr(0) { }	// 默认构造，将当前位置的下标设置为0
    BlobPtr(Blob<T> &a, size_t sz = 0): 	// 接收两个参数的构造
	        wptr(a.data), curr(sz) { }

	T &operator[](std::size_t i)
	{ auto p = check(i, "subscript out of range");	// 这个check是BlobPtr中所定义的check
	  return (*p)[i];  // (*p)是对象指向的vector
	}

	const T &operator[](std::size_t i) const
	{ auto p = check(i, "subscript out of range"); 
	  return (*p)[i];
	}
    
    T& operator*() const	// 取指针运算符'*'的定义
	{ 
		auto p = check(curr, "dereference past end"); 
	  	return (*p)[curr];	// 返回的是引用类型
	}

	// 现在知道这个符号的由来了，就是针对指针定义一种新的写法'->'
    T* operator->() const
	{ 
		// 委托给解引用运算符
	 	return & this->operator*(); 	// "&"符号是取地址运算符
	}

    // 自增自减
    BlobPtr& operator++();       // 前置运算符
    BlobPtr& operator--();

    BlobPtr operator++(int);     // 后置运算符
    BlobPtr operator--(int);
    
private:
	// 检查合法性的函数
	std::shared_ptr<std::vector<T>> 
		check(std::size_t, const std::string&) const;

	// 存储了一个weak_ptr,意味着底层的vector可能已经被销毁
    std::weak_ptr<std::vector<T>> wptr;  
    std::size_t curr;      // 数组位置
};

// 等于运算符
// lock函数会判断weak_ptr指向的vector是否还存在，如果存在则获取指针地址值，在这个等于的逻辑判断中还需要加上此时的位置
template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return lhs.wptr.lock().get() == rhs.wptr.lock().get() && 
	       lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return !(lhs == rhs);
}

// 检查成员
template <typename T>
std::shared_ptr<std::vector<T>> 
BlobPtr<T>::check(std::size_t i, const std::string &msg) const
{
	auto ret = wptr.lock();   // vector是否还存在，存在返回一个shared_ptr
	if (!ret)
		throw std::runtime_error("unbound BlobPtr");
	if (i >= ret->size()) 
		throw std::out_of_range(msg);
	return ret; // otherwise, return a shared_ptr to the vector
}

// 成员运算符
// 后置自增: 自增/自减对象但是返回更改之前的值
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    // 不必检查; 对前缀自增的调用将会做check
    BlobPtr ret = *this;   // 保存当前值
    ++*this;     // 增加，同时做check
    return ret;  // 返回之前保存的值
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
    // 同上
    BlobPtr ret = *this;
	--*this;     
    return ret;
}

// 前缀自增: 返回一个引用
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
	// 最后一个不能再自增了
	check(curr, "increment past end of BlobPtr");
    ++curr;       // advance the current state
    return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
	// 第一个不能再自减了
    --curr;
    check(-1, "decrement past begin of BlobPtr");	// -1会变成short型，这一点需要注意
    return *this;
}

#endif
