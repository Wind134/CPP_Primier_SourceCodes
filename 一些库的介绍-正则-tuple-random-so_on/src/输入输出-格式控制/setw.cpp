/*
 * 输出格式控制
*/ 

#include <iostream>
using std::cout; using std::endl; 
using std::left; using std::right; using std::internal;

#include <iomanip>
using std::setw; using std::setfill;

int main()
{
	int i = -16;
	double d = 3.14159;
	
	// pad the first column to use a minimum of 12 positions in the output
	cout << "i: " << setw(12) << i << "next col" << '\n'
	     << "d: " << setw(12) << d << "next col" << '\n';
	
	// 向左调整字符
	cout << left 
	     << "i: " << setw(12) << i << "next col" << '\n'
	     << "d: " << setw(12) << d << "next col" << '\n'
	     << right;           // restore normal justification
	
	// 向右调整字符
	cout << right
	     << "i: " << setw(12) << i << "next col" << '\n'
	     << "d: " << setw(12) << d << "next col" << '\n';
	
	// 填充字符会被插入到数字和其他字符之间
	cout << internal
	     << "i: " << setw(12) << i << "next col" << '\n'
	     << "d: " << setw(12) << d << "next col" << '\n';
	
	// pad the first column, using # as the pad character
	cout << setfill('#')
	     << "i: " << setw(12) << i << "next col" << '\n'
	     << "d: " << setw(12) << d << "next col" << '\n'
	     << setfill(' ');   // restore the normal pad character

	return 0;
}
