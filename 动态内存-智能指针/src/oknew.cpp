/* 展示了一下new的使用 */ 

#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

#include <cstddef>
using std::size_t;

#include <new>
using std::nothrow;

size_t get_size() { return 42; }

int main() 
{
	int *p1 = new int; 				// 如果分配失败，new抛出一个std::bad_alloc，无法进行分配
	int *p2 = new (nothrow) int; 	// 不管是否失败，new都进行分配，如果失败则分配空指针
	
	int i0;                  // 一个未初始化的变量i0

	int *p0 = new int;       // p0指向一个动态分配的整型对象 
	                         // 该变量未命名，未初始化
	delete p0;  // 释放p0指向的那篇空间

	// 命名了的初始化变量
	int i(1024);             // value of i is 1024
	string s(10, '9');       // value of s is "9999999999"
	vector<int> v = {0,1,2,3,4,5,6,7,8,9};

	// 未命名，但初始化了的动态对象
	int *pi = new int(1024); // 指向一个值为1024的整型动态变量
	string *ps = new string(10, '9');   // *ps的值为字符串"9999999999"
	// vector with ten elements with values from 0 to 9
	vector<int> *pv = new vector<int>{0,1,2,3,4,5,6,7,8,9};
	
	cout << "*pi: " << *pi
	     << "\ti: " << i << endl
	     << "*ps: " << *ps
	     << "\ts: " << s << endl;
	
	for (auto b = pv->begin(); b != pv->end(); ++b)
		cout << *b << " ";
	cout << endl;

	// 当我们使用完内存后必须删除指针
	delete pi;  // frees the memory to which pi points
	delete ps;  // frees the string to which ps points
	            // the string destructor frees the space used by its data
	delete pv;  // frees the memory for the vector
	            // which also destroys the elements in that vector
	
	// 调用get_size来决定分配多少int
	// get_size是一个常量表达式，即能在编译时就知道get_size的值
	int *pia = new int[get_size()]; // pia points to the first of these ints
	delete [] pia; // 要删除一片连续的数组空间时，'[]'必须使用
	typedef int arrT[42];  // typedef重命名一个大小为42的整型数组
	int *p = new arrT;     // p指向该数组
	delete [] p;           // brackets are necessary because we allocated an array 

	return 0;
}
