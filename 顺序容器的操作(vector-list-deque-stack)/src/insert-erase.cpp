/* 
* insert返回的是插入的第一个元素前面的那个元素
* erase返回的是删除的最后一个元素后面的那个元素 
*/
#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::endl;

void printVec(const vector<int> &vi)
{
	// print the vector's elements
	auto iter = vi.begin();
	while (iter != vi.end())
		cout << *iter++ << endl;
}

int main()
{
	// silly loop to remove even-valued elements 
	// and insert a duplicate of odd-valued elements
	vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
	printVec(vi);

	// 调用begin而非cbegin是因为我们将要改变vi
	auto iter = vi.begin(); 
	while (iter != vi.end()) {
		if (*iter % 2) {    // 当元素为奇数时
			iter = vi.insert(iter, *iter);  // 重复该数，insert返回的是插入的数前面的一个数
			iter += 2; // advance past this element and the new one 
		} else 
			iter = vi.erase(iter);          // 移除偶数
			// 不需要自增迭代器
			// iter返回的就是下一个数
	}
	printVec(vi);

	return 0;
}
	
