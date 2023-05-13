/* 展示了对Screen类的使用 */
#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include "Screen.h"

int main()
{
	Screen myScreen(5, 3);	// 初始大小，高为5，宽为3
	// move the cursor to a given position, and set that character 
	myScreen.move(4, 0).set('#');	// 第五行的第一个设为'#'

	Screen nextScreen(5, 5, 'X');	// 初始大小，高为5，宽为5
	nextScreen.move(4,0).set('#').display(cout);	// 第五行第一个设置为'#'，并展示
	cout << "\n";
	nextScreen.display(cout);	// 同样展示
	cout << endl;

	const Screen blank(5, 3);	// 新的空Screen，高为5，宽为3，const类型变量
	myScreen.set('#').display(cout);  // 调用非const版本的display
	cout << endl;
	blank.display(cout);              // 调用const版本
	cout << endl;

	myScreen.clear('Z').display(cout); cout << endl;	// clear为'Z'
	myScreen.move(4,0);	// 移动到(4, 0)
	myScreen.set('#');	// 该位置字符设置为'#'
	myScreen.display(cout); cout << endl;
	myScreen.clear('Z').display(cout); cout << endl;

	// 如果不是返回的Screen的引用，则无法按照我们的预期去展示
	Screen temp = myScreen.move(4,0); // the return value would be copied
	temp.set('#'); // the contents inside myScreen would be unchanged
	myScreen.display(cout);
	cout << endl;
	temp.display(cout);
	cout << endl;
}
