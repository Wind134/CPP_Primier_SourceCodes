/* 多维数组的处理 */
#include <iterator>
using std::begin; using std::end;

#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;

#include <cstddef>
using std::size_t;

int main()
{
	int ia1[3][4];
	
	int arr[10][20][30] = {0};	// 初始化
	
	ia1[2][3] = arr[0][0][0];	// 矩阵三行四列的那个值等于三维数组第一个矩阵中的第一行的第一列
	
	// 绑定矩阵的第二行的那个数组
	int (&row)[4] = ia1[1];
	
	// 定义一个三行四列的矩阵
	int ia2[3][4] = { 
	    {0, 1, 2, 3},   // initializers for the row indexed by 0
	    {4, 5, 6, 7},   // initializers for the row indexed by 1
	    {8, 9, 10, 11}  // initializers for the row indexed by 2
	};
	
	// 考虑数组连续存储的特性，这是上述定义的一个等价定义
	int ia3[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
	
	// 只定义了矩阵每一行的第一个值
	int ia4[3][4] = {{ 0 }, { 4 }, { 8 }};
	
	
	// 只定义了第一个数组，其余的被值初始化
	int ix[3][4] = {0, 3, 6, 9};
	
	// 打印测试
	cout << ix[0][3] << ' ' << ix[1][0] << ' ' << ix[2][0] << endl;
	
	constexpr size_t rowCnt = 3, colCnt = 4;
	int ia[rowCnt][colCnt];   // 12 uninitialized elements 
	
    // for each row
    for (size_t i = 0; i != rowCnt; ++i) {
        // for each column within the row
        for (size_t j = 0; j != colCnt; ++j) {
            // assign the element's positional index as its value
            ia[i][j] = i * colCnt + j;   
		}
	}

	// four ways to print the contents of ia
	// 1. 使用范围for语句输出
	for (const auto &row : ia) // for every element in the outer array
		for (auto col : row)   // for every element in the inner array
			cout << col << endl; // print the element's value
    cout << ia[0][0] << ' ' << ia[2][3] << endl; // prints 0 11


	// 2. 使用指针以及for循环输出
	//    p q都是指针 
	for (auto p = ia; p != ia + rowCnt; ++p) {
		// q points to the first element of an array of four ints; 
		// that is, q points to an int
	    for (auto q = *p; q != *p + colCnt; ++q)
	         cout << *q << ' ';
		cout << endl;
	}
	
	// 3. 使用迭代器
	for (auto p = begin(ia); p != end(ia); ++p) {
		// q points to the first element in an inner array
		for (auto q = begin(*p); q != end(*p); ++q)
			cout << *q << ' ';  // prints the int value to which q points
		cout << endl;
	}
	
	// 4. 使用using语句
	using int_array = int[4]; // int_array为一个存储4个整型变量的数组

	// 下面的p为一个指向存储四个整型的数组的指针，*p即为该数组<=>该数组名，因此q也得是一个指针
	for (int_array *p = ia; p != ia + 3; ++p) {
	    for (int *q = *p; q != *p + 4; ++q)
	         cout << *q << ' ';
		cout << endl;
	}

	// alternative way to assign positional index to elements 
	// in a two-dimensional array
	int alt_ia[rowCnt][colCnt]; // 12 uninitialized elements 
	size_t cnt = 0;
	for (auto &row : alt_ia)    // for every element in the outer array
		for (auto &col : row) { // for every element in the inner array
			col = cnt;          // give this element the next value
			++cnt;              // increment cnt
		}
	// now print the value of the array
	for (const auto &row : alt_ia) // for every element in the outer array
		for (auto col : row)     // for every element in the inner array
			cout << col << endl;

	return 0;
}
