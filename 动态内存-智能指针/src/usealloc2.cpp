/* 进一步介绍了uninitialized_copy的用法
uninitialized_copy主要的作用是往未构造的原始内存中拷贝元素
*/
#include <cstddef>
using std::size_t;

#include <string>
using std::string; 

#include <vector>
using std::vector; 

#include <memory>
using std::uninitialized_copy;
using std::allocator; using std::uninitialized_fill_n;

#include <iostream>
using std::cout; using std::endl;

int main()
{
	vector<int> vi{1,2,3,4,5,6,7,8,9};

	allocator<int> alloc;

	auto p = alloc.allocate(vi.size() * 2);	// 分配一个两倍大小的空间

	auto q = uninitialized_copy(vi.begin(), vi.end(), p); 	// 前一半分配vi的内容

	// 剩余的元素分配42
	uninitialized_fill_n(q, vi.size(), 42);

	for (size_t i = 0; i != vi.size(); ++i)
		cout << *(p + i) << " ";
	cout << endl;

	for (size_t i = 0; i != vi.size(); ++i)
		cout << *(q + i) << " ";
	cout << endl;

	alloc.deallocate(p, vi.size());	// 归还内存
}
