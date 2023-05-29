/*
 * Vec类的头文件
*/ 

#ifndef VEC_H
#define VEC_H

#include <algorithm>
#include <memory>
#include <utility>
#include <initializer_list>

// vector-like类的内存分配策略的简化实现
template <typename T>
class Vec {
public:
    Vec() = default;
	Vec(const Vec&);                 // 拷贝构造
	Vec(Vec&&) noexcept;             // 移动构造
	Vec &operator=(const Vec&);      // 拷贝赋值
	Vec &operator=(Vec&&) noexcept;  // 移动赋值
	~Vec() noexcept;                 // 析构

	// 初始化列表赋值
	Vec &operator=(std::initializer_list<T>);   

	// 增加元素
    void push_back(const T&);	// 左值
    void push_back(T&&);		// 右值
	template <class... Args> void emplace_back(Args&&...);
	
	// 大小和容量
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }

	// 元素访问的const以及非const版本
    T& operator[](size_t n) { return elements[n]; }
    const T& operator[](size_t n) const { return elements[n]; }

	// 迭代器接口
	T *begin() const { return elements; }
	T *end() const { return first_free; }
private:
    static std::allocator<T> alloc; // 是一个声明，说明其static性
	// 被增添元素进Vec的函数使用
	void chk_n_alloc() { if (first_free == cap) reallocate(); }

    // 被拷贝构造, 赋值运算符, 以及析构函数使用的组件
	std::pair<T*, T*> 
	  alloc_n_copy(const T*, const T*);
	void free();
    void reallocate(); 		// 获取更多的空间，同时复制现存的元素
    T* elements = nullptr;  // 指向第一个元素的指针
    T* first_free = nullptr;// pointer to first free element in the array
    T* cap = nullptr;       // 指向数组结束位置后的下一个位置的指针
};


// 接下来是所有静态数据成员的定义
template <typename T> std::allocator<T> Vec<T>::alloc;  	// 定义了一个std::allocator<T>类型的变量Vec<T>::alloc，是定义

template <typename T>
inline
Vec<T>::~Vec() noexcept { free(); }	// noexcept代表没有异常，我先声明这个不会有异常，也就是说我们不需要进行异常处理


template <typename T>	// 该函数实现的功能就是分配一连串空间，返回指向分配空间的首址以及分配的最后一个元素后面的指针
inline
std::pair<T*, T*> 
Vec<T>::alloc_n_copy(const T *b, const T *e) 
{
	auto data = alloc.allocate(e - b);
	return {data, uninitialized_copy(b, e, data)};	// 第一个为指向分配的那一串空间的指针，第二个指向最后一个复制元素之后的迭代器
}

// 右值引用不需要像下面的左值引用一样去执行alloc_n_copy
// 只需要去接管右值的有关指针即可
template <typename T>
inline	// 针对右值引用参数的构造函数定义
Vec<T>::Vec(Vec &&s) noexcept : 
	// take over resources from s
	elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	// 将s置为空，以便安全的执行析构，下面的执行顺序是从右往左
	s.elements = s.first_free = s.cap = nullptr;
}


template <typename T>	// 拷贝构造
inline
Vec<T>::Vec(const Vec &s)
{
	// 所有的元素保存在newdata
	auto newdata = alloc_n_copy(s.begin(), s.end()); 
	elements = newdata.first; 
	first_free = cap = newdata.second;
}

template <typename T>	// 自行释放空间
inline
void Vec<T>::free()
{
    // 释放空间
	for (auto p = first_free; p != elements; /* empty */)
		alloc.destroy(--p);  // destroy elements in reverse order
    
    // 元素清空之后，归还内存
	if (elements)
		alloc.deallocate(elements, cap - elements);
}
	
template <typename T>	// 拷贝赋值运算符，针对初始化列表
inline
Vec<T>& Vec<T>::operator=(std::initializer_list<T> il)
{
	// 同上
	auto data = alloc_n_copy(il.begin(), il.end());

	free();   // 释放左边的所有

	elements = data.first; // 执行替换
	first_free = cap = data.second;

	return *this;
}

template <typename T>
inline
Vec<T> &Vec<T>::operator=(Vec &&rhs) noexcept
{
	// 检测是否是自分配，如果不是自分配，需要先释放左边
	// 所有元素以及所占用的空间
	if (this != &rhs)
		free();

	elements = rhs.elements;  // 接管
	first_free = rhs.first_free;
	cap = rhs.cap;

	// 同样置空，以便后续执行析构
	rhs.elements = rhs.first_free = rhs.cap = nullptr;

	return *this;
}

template <typename T>
inline
Vec<T> &Vec<T>::operator=(const Vec &rhs)
{
	// 拷贝赋值
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

template <typename T>	// 该函数执行空间的重新分配，这部分实现了旧元素的移动以及空间的再分配
inline
void Vec<T>::reallocate()
{
    // size()为0则分配2个空间，否则分配两倍空间
    auto newcapacity = size() ? 2 * size() : 2;

	// 分配新的空间
	auto first = alloc.allocate(newcapacity);
	auto dest = first;
	auto elem = elements;

	// move the elements
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();  // 对于之前的元素我们执行移动操作而不是拷贝

    // 更新指针信息
    elements = first;
    first_free = dest;
    cap = elements + newcapacity;
}

template <typename T>	// 左值版本
inline
void Vec<T>::push_back(const T& s)
{
    chk_n_alloc(); // 满了就继续分配新的空间
    // 给未构造的空间构造一个s，同时first_free前移
    alloc.construct(first_free++, s);  
}

template <typename T>	// 右值版本
inline
void Vec<T>::push_back(T&& s) 
{
    chk_n_alloc(); // reallocates the Vec if necessary
	alloc.construct(first_free++, std::move(s));
}

template <typename T>	// 可变模板参数版本
template <class... Args>
inline
void Vec<T>::emplace_back(Args&&... args)
{
    // 同样要检查空间
    chk_n_alloc(); // reallocates the Vec if necessary
	alloc.construct(first_free++, std::forward<Args>(args)...);	// construct函数本身就接受可变参数模板，这个是他自带的功能
}

#endif
