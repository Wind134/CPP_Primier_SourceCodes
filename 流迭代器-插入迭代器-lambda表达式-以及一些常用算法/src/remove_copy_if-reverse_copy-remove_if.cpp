/* 介绍了remove_copy_if-reverse_copy-remove_if */
#include <algorithm>
using std::find; using std::find_if; using std::for_each;
using std::remove_copy_if; using std::reverse_copy;	// 顾名思义：如果...就移除copy以及反转复制
using std::reverse; 

#include <iterator>
using std::back_inserter;

#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::endl;

int main()
{
	vector<int> v1 = {0,1,2,3,4,5,6,7,8,9};
	vector<int> v2;
	vector<int> v3 = v1;

	find(v1.begin(), v1.end(), 42);  // find first element equal to 42 
	find_if(v1.begin(), v1.end(),    // find first odd element
	        [](int i) { return i % 2; });

	// puts elements in v1 into reverse order
	reverse(v1.begin(), v1.end());  // 翻转
	v1 = v3;  // restore original data

	// copies elements from v1 into v2 in reverse order; v1 is unchanged
	reverse_copy(v1.begin(), v1.end(), back_inserter(v2));	// 通过插入迭代器将v1元素插入到v2

	for (auto i : v1) 
		cout << i << " ";   // prints 0 1 2 . . . 8 9
	cout << endl;
	for (auto i : v2) 
		cout << i << " ";   // prints 9 8 7 . . . 1 0
	cout << endl;

	// removes the odd elements from v1
	auto it = remove_if(v1.begin(), v1.end(), 
	                    [](int i) { return i % 2; });	// 如果...就移除
	// prints 0 2 4 6 8
	for_each(v1.begin(), it, [](int i) { cout << i << " "; });
	cout << endl;

	v1 = v3;    // restore original data
	v2.clear(); // make v2 empty again

	// copies only the even elements from v1 into v2; v1 is unchanged
	remove_copy_if(v1.begin(), v1.end(), back_inserter(v2),
	               [](int i) { return i % 2; });	// 为奇数就不复制
	for (auto i : v2) 
		cout << i << " ";  // prints 0 2 4 6 8
	cout << endl;
	for (auto i : v1)      // prints 0 1 2 . . . 8 9
		cout << i << " ";
	cout << endl;

	return 0;
}
