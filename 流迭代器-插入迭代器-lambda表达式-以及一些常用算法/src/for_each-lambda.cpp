/* 介绍了for_each以及lambda表达式 */
#include <vector>
using std::vector;

#include <iterator>		// 迭代器
using std::inserter;

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <algorithm>	// 算法库
using std::for_each; using std::transform;	// transform是对指定范围内的元素进行转换操作的函数

int main() {
	vector<int> vi;
	int i;
	while (cin >> i)
		vi.push_back(i);
	// 结合lambda与for_each来打印出vi中的每个元素
	for_each(vi.begin(), vi.end(), [](int i) { cout << i << " "; });
	cout << endl;

	vector<int> orig = vi; // 保存初始vi的初始数据

	// 用绝对值代替负值
	transform(vi.begin(), vi.end(), vi.begin(),
	          [](int i) { return i < 0 ? -i : i; });
	// print the elements now in vi
	for_each(vi.begin(), vi.end(), [](int i) { cout << i << " "; });
	cout << endl;

	vi = orig;  // start afresh
	// 指定返回类型的lambda方式，因为这里有两个return，编译器无法推断他的具体形式
	transform(vi.begin(), vi.end(), vi.begin(),
	          [](int i) -> int 
	          { if (i < 0) return -i; else return i; });
	// print the elements now in vi
	for_each(vi.begin(), vi.end(), [](int i) { cout << i << " "; });
	cout << endl;

    return 0;
}
