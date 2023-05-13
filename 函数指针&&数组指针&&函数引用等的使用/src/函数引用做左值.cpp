/* 函数引用以及数组名做指针 */
#include <iostream>
using std::cout; using std::endl;

// 形参是一个指向int的指针和一个int变量
int &get(int *arry, int index) { return arry[index]; }

int main() {
    int ia[10];  // array of ten uninitialized ints

    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;  // call get to assign values to the elements

	for (auto i : ia)    // print the elements
		cout << i << " ";
	cout << endl;

	return 0;
}
