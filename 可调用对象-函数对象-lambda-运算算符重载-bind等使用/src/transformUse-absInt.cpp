/* 主要介绍了transform函数的用法 */
#include <vector>
using std::vector;

#include <iterator>
using std::inserter;	// 插入迭代器

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <algorithm>
using std::transform;	// std::transform用于对指定范围内的元素进行转换操作，并将结果存储到另一个目标范围中。

struct absInt {			// 用于返回一个绝对值
    int operator()(int val) const {
        return val < 0 ? -val : val;
    }
};

int main() {
    int i = -42;
    absInt absObj;           // absObj含有函数对象操作符
    unsigned ui = absObj(i); // 保存至ui
    cout << i << " " << ui << endl;

	// store collection of positive and negative integers in vi
	vector<int> vi;
	while (cin >> i)
		vi.push_back(i);

	// call absInt to store the absolute value of those ints in vu
	vector<unsigned> vu;	// 定义一个新的vector容器，以保存转换后的元素
	transform(vi.begin(), vi.end(), back_inserter(vu), absInt());	// 后插入

	// 使用lambda打印内容
	for_each(vu.begin(), vu.end(), [](unsigned i) { cout << i << " "; });
	cout << endl;

	vector<unsigned> vu2;
	// similar transformation but using a lambda
	transform(vi.begin(), vi.end(), back_inserter(vu2),
	          [](int i) { return i < 0 ? -i : i; });
	if (vu == vu2)
		cout << "as expected" << endl;
	else {
		cout << "something's wrong, vectors differ" << endl;
		for_each(vu.begin(), vu.end(), [](unsigned i) { cout << i << " "; });
	}
	cout << endl;

    return 0;
}
