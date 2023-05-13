/* 描述了vector的用法，以及描述了using的用法 */

#include <cstddef>	// 该头文件为C++标准库中的头文件，提供了一些定义了的符号常量和类型
using std::size_t;

#include <vector>
using std::vector;

#include <iostream>
using std::cin; using std::cout; using std::endl;


int main ()
{
	vector<unsigned> grades;
	// count the number of grades by clusters of ten: 
	// 0--9, 10--19, . . . 90--99, 100
	unsigned scores[11] = {};  // 大小为11的数组，隐式初始化
	unsigned grade;
	while (cin >> grade) {
		if (grade <= 100)
			// increment the counter for the current cluster
			++scores[grade/10]; 
		grades.push_back(grade);
	}
	cout << "grades.size = " << grades.size() << endl;

	for (auto g : grades)  // for every element in grades
		cout << g << " " ;
	cout << endl;

	for (auto i : scores)       // for each counter in scores
		cout << i << " ";       // print the value of that counter
	cout << endl;
}
